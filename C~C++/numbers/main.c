#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if defined(LP64) || defined(_LP64) // S не больше size_t
#define STRING_SIZE 65
#elif defined(LP32) || defined(_LP32)
#define STRING_SIZE 33
#endif
#define ERROR "[error]"
#define ERR 0
#define OK 1
#define MAX_SYSTEM 36
#define MIN_SYSTEM 2
#define NULL_SYMBOL '0'
#define NINE_SYMBOL '9'
#define A_SYMBOL 'A'
#define Z_SYMBOL 'Z'

#define CHECK_OK(OK)                                                           \
  if (!(OK))                                                                   \
    return ERR;

/* Перевод из 1 системы счислений в другую.
 * Студент - Антон Прийма
 * Run id = 696
 * */

// char->int
int dec_to_int(char c) {
    if (c <= NINE_SYMBOL && c >= NULL_SYMBOL) {
        return c - '0';
    }
    if (c >= A_SYMBOL && c <= Z_SYMBOL) {
        return c - 'A' + 10;
    }

    return ERR;
}
//Проверка на корректность ввода
int check_char(char c, int Q) {
    if (!((c <= NINE_SYMBOL && c >= NULL_SYMBOL) ||
          (c >= A_SYMBOL && c <= Z_SYMBOL)) ||
        dec_to_int(c) >= Q) {
        return ERR;
    }
    return OK;
}
// int->char
char int_to_dec(size_t i) {
    if (i <= 9) {
        return (char)(NULL_SYMBOL + i);
    }
    if (i >= 10 && i < 36) {
        return (char)(A_SYMBOL + i - 10);
    }
    return 0;
}

int upcase_string(char *S) {
    if (!S) {
        return ERR;
    }
    size_t len = strlen(S);
    for (int i = 0; i < len; i++) {
        S[i] = (char)toupper(S[i]);
    }
    return OK;
}

int check_char_pointer(const char *const p) {
    if (!p) {
        return ERR;
    }
    return OK;
}


//Перевод из Q в P
char *translate(int Q, int P, const char *const S) {
    //Проверка на валидность
    size_t size = 0, i = 0;
    size_t numb = 0, power = 1, buf = 0;
    char *result = NULL;
    for (const char *c = S; (*c) != '\0'; c++) {
        if (!(check_char(*c, Q))) {
            return ERROR;
        } else {
            size++;
        }
    }

    for (i = size; i > 0; i--) {
        numb += dec_to_int(*(S + i - 1)) * power;
        power *= Q;
    }
    size = 0;
    buf = numb;
    while (buf > 0) {
        buf /= P;
        size++;
    }
    result = (char *)malloc(size + 1);
    result[size] = '\0';
    i = 1;
    while (numb > 0) {
        result[size - i] = int_to_dec(numb % P);
        i++;
        numb /= P;
    }
    return result;
}

//Считываем в буфер, если переполняется, то увиличиваем.
void scan_string(char *S) {
//    char *buf = S;
//    int count = 0;
//    int n2 = 0;
//    while (1) {
//        if (n2 == STRING_SIZE) {
//            buf = (char *)realloc(S, STRING_SIZE);
//            if (buf) {
//                S = buf;
//            } else {
//                free(S);
//            }
//            buf += STRING_SIZE - 1;
//            n2 = 0;
//        }
//        scanf("%98s", buf);
//        n2 += STRING_SIZE;
//        for (int i = 0; i < STRING_SIZE - 1; i++) {
//            if (buf[i] == EOF || buf[i] == '\0' || buf[i] == '\n') {
//                count = 1;
//                break;
//            }
//            buf[i] = (char)toupper(buf[i]);
//        }
//        if (count)
//            break;
//    }
    scanf("%65s", S);
}

int read(const int *Q, const int *P, char *S) {
    if (!check_char_pointer(S) ) {
        printf(ERROR);
        return ERR;
    }
    int ok = scanf("%d%d", (int *)Q, (int *)P);
    CHECK_OK(ok);

    getchar();

    scan_string(S);

    ok = upcase_string(S);
    CHECK_OK(ok);

    if (*Q > MAX_SYSTEM || *P < MIN_SYSTEM) {
        return ERR;
    }
    return OK;
}

int main() {
    const int Q = 0;
    const int P = 0;
    char *S = (char *)malloc(STRING_SIZE);
    if (read(&Q, &P, S) != OK) {
        printf(ERROR);
        free(S);
        return 0;
    }
    char *result = translate(Q, P, S);
    printf("%s", result);
    if (strcmp(result,ERROR)!=0) {
        free(result);
    }
    free(S);

    return 0;
}
