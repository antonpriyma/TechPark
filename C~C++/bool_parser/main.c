#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

#define STRING_SIZE 99
#define YES 1
#define ERR 1
#define OK 0
#define NO 0
#define ERROR "[error]"

#define END_PROGRAMM                                                           \
  delete (len_1, partResult1, partResult2);                                     \
  return 0;
#define CHECK_ERR                                                              \
  if (err) {                                                                   \
    printf(ERROR);                                                             \
    END_PROGRAMM;                                                              \
  }

/* Рекурсивно-последовательный парсер логических выражений.
 * Студент - Прийма Антон
 * Run id = 493
*/

//В глобальных переменных храним выражение, текущий токен и индексы.
char *expression;
int exp_index;
char *token;
int tok_index;
size_t len;

int eval_expr_4(int *, int *, int *);        //Уровень скобок
int eval_expr_3(int *, int *, int *, int *); //Уровень ^
int string_to_int(char *, int *, int *);     //Токен -> массив

void delete (int *val1, int *val2, int *val3) {
    if (val1)
        free(val1);
    if (val2)
        free(val2);
    if (val3)
        free(val3);
}

int remove_spaces(char *source) {
    if (!source) {
        return ERR;
    }
    char *i = source;
    char *j = source;
    while (*j != 0) {
        *i = *j++;

        if (*i != ' ') {
            i++;
        }
    }
    *i = 0;
    return 0;
}

// Сумма множеств.
void unite(int *a, int *b, int *len1, int *len2) {
    for (int i = 0; i < *len2; i++) {
        char contains = 0;
        for (int j = 0; j < *len1; j++) {
            if (a[j] == b[i]) {
                contains = 1;
                break;
            }
        }
        if (!contains) {
            a[(*len1)++] = b[i];
        }
        b[i] = 0;
    }
    *len2 = 0;
}

// Разность множеств.
void sub(int *a, int *b, const int *len1, int *len2) {
    for (int i = 0; i < *len1; i++) {
        char contains = 0;
        for (int j = 0; j < *len2; j++) {
            if (b[j] == a[i]) {
                contains = 1;
                break;
            }
        }
        if (contains) {
            a[i] = -1;
        }
    }
    for (int i = 0; i < *len2; i++) {
        b[i] = 0;
    }
    *len2 = 0;
}

// Пересечение множеств.
void intersection(int *a, const int *b, const int *len1, const int *len2) {

    for (int i = 0; i < *len1; i++) {
        char contains = 0;
        for (int j = 0; j < *len2; j++) {
            if (a[i] == b[j]) {
                contains = 1;
                break;
            }
        }
        if (!contains) {
            a[i] = -1;
        }
    }
}

int is_delim(char c) {
    char delims[] = {'U', '^', '\\', '(', ')'};
    char size = 5;
    for (int i = 0; i < size; i++) {
        if (c == delims[i]) {
            return YES;
        }
    }
    return NO;
}

void get_token() {

    token[0] = '\0';
    tok_index = 0;
    if (exp_index == len) {
        return;
    }

    if (is_delim(expression[exp_index])) {
        token[tok_index++] = expression[exp_index];
        token[tok_index] = '\0';
        exp_index++;
    } else if (expression[exp_index] == '[') {
        while (expression[exp_index++] != ']') {
            token[tok_index++] = expression[exp_index - 1];
        }
        token[tok_index++] = expression[exp_index - 1];
        token[tok_index] = '\0';
    }
}

int eval_expr_2(int *part_result_1, int *part_result_2, int *len_1) {
    if (!part_result_1 || !part_result_2 || !len_1) {
        return ERR;
    }
    char op;
    int *len_2 = (int *)calloc(1, sizeof(int));
    int *buf = (int *)malloc(100 * sizeof(int));
    get_token();
    int err = eval_expr_3(part_result_1, part_result_2, buf, len_1);
    if (err) {
        free(buf);
        free(len_2);
        return ERR;
    }
    while ((op = token[0]) == 'U' || op == '^' || op == '\\') {
        get_token();
        err = eval_expr_3(part_result_2, part_result_1, buf, len_2);
        if (err) {
            free(buf);
            free(len_2);
            return ERR;
        }
        switch (op) {
            case 'U':
                unite(part_result_1, part_result_2, len_1, len_2);
                break;
            case '\\':
                sub(part_result_1, part_result_2, len_1, len_2);
                break;
            default:
                break;
        }
    }
    free(buf);
    free(len_2);
    return 0;
}

int eval_expr_3(int *partResult1, int *partResult2, int *buf, int *len_1) {
    if (!partResult1 || !partResult2 || !buf || !len_1) {
        return ERR;
    }
    int *len_2 = (int *)calloc(1, sizeof(int));
    int err = eval_expr_4(partResult1, partResult2, len_1);
    if (err) {
        free(len_2);
        return ERR;
    }
    while (token[0] == '^') {
        get_token();
        int err = eval_expr_4(buf, partResult1, len_2);
        if (err) {
            free(len_2);
            return ERR;
        }
        intersection(partResult1, buf, len_1, len_2);
    }
    free(len_2);
    return OK;
}

int eval_expr_4(int *part_result_1, int *part_result_2, int *len_1) {
    if (!part_result_1 || !part_result_2 || !len_1) {
        return ERR;
    }
    if (*token == '(') {
        int err = eval_expr_2(part_result_1, part_result_2, len_1);
        if (err) {
            return ERR;
        }
        if (*token != ')') {
            return ERR;
        }
        get_token();
        return OK;
    } else {
        int err = string_to_int(token, part_result_1, len_1);
        if (err) {
            return ERR;
        }
    }

    return OK;
}

int string_to_int(char *token, int *part_result_1, int *len) {
    if (!token || !part_result_1 || !len)
        return ERR;
    int err = remove_spaces(token);
    if (err)
        return ERR;

    int count = 0;
    char *buf1 = (char *)malloc(100);
    int *buf = part_result_1;
    for (int i = 0; i < tok_index; i++) {
        if (token[i] == ',' || token[i] == '[') {
            if (token[i + 1] == ']') {
                break;
            }
            buf1[0] = '\0';
            count = 0;
            while (token[++i] != ',' && token[i] != ']') {
                buf1[count++] = token[i];
            }
            buf1[count] = '\0';
            i--;
            buf[(*len)++] = atoi(buf1);
        }
    }
    get_token();
    free(buf1);
    return OK;
}

//вход в парсер
int execute(int *part_result_1, int *part_result_2, int *len_1) {
    int err = eval_expr_2(part_result_1, part_result_2, len_1);
    if (err) {
        return ERR;
    }
    return OK;
}

//вывод
int printSet(int *set, int len_1) {
    if (!set) {
        return ERR;
    }
    printf("[");
    for (int i = 0, count = 0; i < len_1; i++) {
        if (count == 0) {

            if (set[i] != -1) {
                printf("%d", set[i]);
                count++;
            }
        } else {
            if (set[i] != -1) {
                printf(",%d", set[i]);
            }
        }
    }
    printf("]");
    return OK;
}

//считывание строки
int scan_string() {
    if (!expression) {
        return ERR;
    }
    char c, *buf = NULL;
    int i = 0;
    size_t n1 = STRING_SIZE;
    while ((c = (char)getchar()) != EOF) {
        if (i >= n1 - 1) {
            buf = (char *)realloc(expression, n1 * 2);
            if (!buf) {
                return ERR;
            }
            expression = buf;
            n1 *= 2;
        }
        i++;
        *(expression + i - 1) = c;
        *(expression + i) = '\0';
    }

    int err = remove_spaces(expression);
    if (err) {
        return ERR;
    }
    len = strlen(expression);
    return OK;
}

void init() {
    exp_index = 0;
    tok_index = 0;
    token = (char *)malloc(STRING_SIZE);
    token[0] = '\0';
    expression = (char *)malloc(STRING_SIZE);
}

int main() {
    int err;
    int *partResult1 = (int *)malloc(100 * sizeof(int));
    int *partResult2 = (int *)malloc(100 * sizeof(int));
    int *len_1 = (int *)calloc(1, sizeof(int));
    init();
    err = scan_string(expression);
    CHECK_ERR

    err = execute(partResult1, partResult2, len_1);
    CHECK_ERR
    err = printSet(partResult1, *len_1);
    CHECK_ERR

    END_PROGRAMM
}