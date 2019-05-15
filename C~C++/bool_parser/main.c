#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define CHUNK 100
#define YES 1
#define ERR (-1)
#define OK 0
#define NO 0
#define ERROR "[error]"
#define OPEN_BRACKET_1 '['
#define CLOSE_BRACKET_1 ']'
#define OPEN_BRACKET_2 '('
#define CLOSE_BRACKET_2 ')'


/* Рекурсивно-последовательный парсер логических выражений.
 * Студент - Прийма Антон
 * Run id = 501
*/

//В глобальных переменных храним выражение, текущий токен и индексы.
char *expression;
int exp_index;
char *token;
int tok_index;
size_t len;

int eval_expr_brackets(int *, int *, int *);        //Уровень скобок
int eval_expr_intercept(int *, int *, int *, int *); //Уровень ^
int eval_expr_sum(int *, int *, int *);          //Уровень U;/
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

int myatoi(char *s) {
    int res = 0, minus = *s == '-';
    if (minus) s++;

    while (isdigit(*s)) {
        res = res*10 + (*s++ - '0');
    }

    if (*s!='\0'){
        return ERR;
    }

    return minus ? -res : res;
}

// Сумма множеств.
void unite(int *a, int *b, int *len_first, int *len_second) {
    for (int i = 0; i < *len_second; i++) {
        char contains = 0;
        for (int j = 0; j < *len_first; j++) {
            if (a[j] == b[i]) {
                contains = 1;
                break;
            }
        }
        if (!contains) {
            a[(*len_first)++] = b[i];
        }
        b[i] = 0;
    }
    *len_second = 0;
}

// Разность множеств.
void sub(int *op_first, int *op_second, const int *len_first, int *len_second) {
    for (int i = 0; i < *len_first; i++) {
        char contains = 0;
        for (int j = 0; j < *len_second; j++) {
            if (op_second[j] == op_first[i]) {
                contains = 1;
                break;
            }
        }
        if (contains) {
            op_first[i] = -1;
        }
    }
    for (int i = 0; i < *len_second; i++) {
        op_second[i] = 0;
    }
    *len_second = 0;
}

// Пересечение множеств.
void intersection(int *op_first, const int *op_second, const int *len_first, const int *len_second) {

    for (int i = 0; i < *len_first; i++) {
        char contains = 0;
        for (int j = 0; j < *len_second; j++) {
            if (op_first[i] == op_second[j]) {
                contains = 1;
                break;
            }
        }
        if (!contains) {
            op_first[i] = -1;
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

//Выделить следущий токен
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
    } else if (expression[exp_index] == OPEN_BRACKET_1) {
        while (expression[exp_index++] != CLOSE_BRACKET_1) {
            token[tok_index++] = expression[exp_index - 1];
        }
        token[tok_index++] = expression[exp_index - 1];
        token[tok_index] = '\0';
    }
}

int eval_expr_sum(int *part_result, int *part_result_buffer, int *len_1) {
    if (!part_result || !part_result_buffer || !len_1) {
        return ERR;
    }
    char op;
    int *len_2 = (int *)calloc(1, sizeof(int));
    int *buf = (int *)malloc(CHUNK * sizeof(int));
    if (!len_2 || !buf) {
        free(len_2);
        free(buf);
        return ERR;
    }
    get_token();
    int err = eval_expr_intercept(part_result, part_result_buffer, buf, len_1);
    if (err) {
        free(buf);
        free(len_2);
        return ERR;
    }
    while ((op = token[0]) == 'U' || op == '^' || op == '\\') {
        get_token();
        err = eval_expr_intercept(part_result_buffer, part_result, buf, len_2);
        if (err) {
            free(buf);
            free(len_2);
            return ERR;
        }
        switch (op) {
            case 'U':
                unite(part_result, part_result_buffer, len_1, len_2);
                break;
            case '\\':
                sub(part_result, part_result_buffer, len_1, len_2);
                break;
            default:
                break;
        }
    }
    free(buf);
    free(len_2);
    return 0;
}

int eval_expr_intercept(int *partResult, int *part_result_buffer, int *buf, int *len) {
    if (!partResult || !part_result_buffer || !buf || !len) {
        return ERR;
    }
    int *len_2 = (int *)calloc(1, sizeof(int));
    if (!len_2) {
        return ERR;
    }
    int err = eval_expr_brackets(partResult, part_result_buffer, len);
    if (err) {
        free(len_2);
        return ERR;
    }
    while (token[0] == '^') {
        get_token();
        err = eval_expr_brackets(buf, partResult, len_2);
        if (err) {
            free(len_2);
            return ERR;
        }
        intersection(partResult, buf, len, len_2);
    }

    free(len_2);
    return OK;
}

int eval_expr_brackets(int *part_result, int *part_result_buffer, int *len) {
    if (!part_result || !part_result_buffer || !len) {
        return ERR;
    }
    if (*token == OPEN_BRACKET_2) {
        int err = eval_expr_sum(part_result, part_result_buffer, len);
        if (err) {
            return ERR;
        }
        if (*token != CLOSE_BRACKET_2) {
            return ERR;
        }
        get_token();
        return OK;
    } else {
        int err = string_to_int(token, part_result, len);
        if (err) {
            return ERR;
        }
    }

    return OK;
}

int string_to_int(char *token, int *part_result, int *len) {
    if (!token || !part_result || !len)
        return ERR;
    int err = remove_spaces(token);
    if (err) {
        return ERR;
    }

    int count = 0;
    char *buffer = (char *)malloc(CHUNK);
    if (!buffer) {
        return ERR;
    }
    int *buf = part_result;
    for (int i = 0; i < tok_index; i++) {
        if (token[i] == ',' || token[i] == OPEN_BRACKET_1) {
            if (token[i + 1] == CLOSE_BRACKET_1) {
                break;//Пустое множество.
            }
            buffer[0] = '\0';
            count = 0;
            while (token[++i] != ',' && token[i] != CLOSE_BRACKET_1) {
                buffer[count++] = token[i];
            }
            buffer[count] = '\0';
            i--;
            if (i)
            err=myatoi(buffer);
            if (err==ERR){
                free(buffer);
                return err;
            }
            buf[(*len)++] = err;
        }
    }
    get_token();
    free(buffer);
    return OK;
}

//вход в парсер
int execute(int *part_result, int *part_result_buffer, int *len) {
    int err = eval_expr_sum(part_result, part_result_buffer, len);
    if (err) {
        return ERR;
    }
    return OK;
}

//вывод
int printSet(int *set, int len) {
    if (!set) {
        return ERR;
    }
    printf("%c",OPEN_BRACKET_1);
    for (int i = 0, count = 0; i < len; i++) {
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
    printf("%c",CLOSE_BRACKET_1);
    return OK;
}

//считывание строки
char* read_input()
{
    char* input=0;
    char temp_buf[CHUNK]="";
    size_t inputlen = 0, templen = 0;
    do {
        char *buf=NULL;
        fgets(temp_buf, CHUNK, stdin);

        if (ferror(stdin)) {
           return NULL;
        }
        templen = strlen(temp_buf);
        inputlen += templen;
        buf = (char *)realloc(input, inputlen+1);
        if (!buf){
            free(input);
            return NULL;
        }
        input=buf;
        for (size_t i = inputlen - templen; i < inputlen; i++){
            input[i]=temp_buf[i-inputlen+templen];
        }
        input[inputlen]='\0';
       // strcat(input,temp_buf);
    } while (templen==CHUNK-1 && temp_buf[CHUNK-2]!=EOF);
    int err = remove_spaces(input);
    if (err) {
        return NULL;
    }
    len = strlen(input);
    return input;
}

int init_global_vars() {
    exp_index = 0;
    tok_index = 0;
    char* buf= (char *)malloc(len+1);
    if (!buf) {
        return ERR;
    }
    token=buf;
    token[0] = '\0';
    return OK;
}

int main() {
    int err;
    char* char_err;
    char_err=read_input();
    if (!char_err) {
        printf(ERROR);
        return 0;
    }
    expression=char_err;
    err = init_global_vars();
    if (err) {
        printf(ERROR);
        return 0;
    }
    int *result = (int *)malloc(len * sizeof(int));//Результат не больше исходного выражения.
    int *part_result = (int *)malloc(len * sizeof(int));
    int *len = (int *)calloc(1, sizeof(int));

    if (!len || !result || !part_result) {
        printf(ERROR);
        delete (len, result, part_result);
        return 0;
    }
    err = execute(result, part_result, len);
    if (err) {
        printf(ERROR);
        delete (len, result, part_result);
        return 0;
    }
    err = printSet(result, *len);
    if (err) {
        printf(ERROR);
    }

    delete (len, result, part_result);
    return 0;
}