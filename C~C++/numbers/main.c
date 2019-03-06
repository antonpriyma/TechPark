#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if defined(LP64) || defined(_LP64)//S не больше size_t
#define STRING_SIZE 65
#elif defined(LP32) || defined(_LP32)
#define STRING_SIZE 33
#endif
#define ERROR "[error]"
#define ERR 0
#define OK 1

#define CHECK_OK\
  if (!ok)                                                                     \
  return ERR

/* Перевод из 1 системы счислений в другую.
 * Студент - Антон Прийма
 * Run id = 494
 * */


//Очистка памяти
void delete (const int *p, const int *q, char *c) {
    free((int *)p);
    free((int *)q);
    free(c);
}
//char->int
int dec_to_int(char c) {
    if (c <= '9' && c >= '0') {
        return c - '0';
    }
    if (c >= 'A' && c <= 'Z') {
        return c - 'A' + 10;
    }

    return ERR;
}
//Проверка на корректность ввода
int check_char(char c, int Q) {
    if (!((c <= '9' && c >= '0') || (c >= 'A' && c <= 'Z')) ||
        dec_to_int(c) >= Q) {
        return ERR;
    }
    return OK;
}
//int->char
char int_to_dec(size_t i) {
    if (i <= 9) {
        return (char)('0' + i);
    }
    if (i >= 10 && i < 36) {
        return (char)('A' + i - 10);
    }
    return 0;
}

int upcase_string(char* S){
    if (!S){
        return ERR;
    }
    size_t len = strlen(S);
    for (int i=0;i<len;i++){
        S[i]= (char) toupper(S[i]);
    }
    return OK;
}

int check_char_pointer(const char *const p) {
    if (!p) {
        return ERR;
    }
    return OK;
}

int check_int_pointer(const int *const p) {
    if (!p) {
        return ERR;
    }
    return OK;
}

//Перевод из Q в P
void translate(const int *Q, const int *P, const char *const S) {
    //Проверка на валидность
    size_t size = 0, i = 0;
    size_t numb = 0, power = 1, buf = 0;
    char *result = NULL;
    if (!check_char_pointer(S) || !check_int_pointer(Q) ||
        !check_int_pointer(P)) {
        printf(ERROR);
        return;
    }

    for (const char *c = S; (*c) != '\0'; c++) {
        if (!(check_char(*c, *Q))) {
            printf(ERROR);
            return;
        } else {
            size++;
        }
    }

    for (i = size; i > 0; i--) {
        numb += dec_to_int(*(S + i - 1)) * power;
        power *= (*Q);
    }
    size = 0;
    buf = numb;
    while (buf > 0) {
        buf /= (*P);
        size++;
    }
    result = (char *)malloc(size + 1);
    result[size] = '\0';
    i = 1;
    while (numb > 0) {
        result[size - i] = int_to_dec(numb % (*P));
        i++;
        numb /= (*P);
    }
    printf("%s", result);
    free(result);
}

//Считываем в буфер, если переполняется, то увиличиваем.
void scan_string(char *S) {
    char *buf = S;
    int count=0;
    int n2 = 0;
    while (1) {
        if (n2 == STRING_SIZE) {
            buf = (char *)realloc(S, STRING_SIZE);
            if (buf){
                S=buf;
            } else{
                free(S);
            }
            buf += STRING_SIZE-1;
            n2 = 0;
        }
        scanf("%98s", buf);
        n2 += STRING_SIZE;
        for (int i = 0; i < STRING_SIZE-1; i++) {
            if (buf[i] == EOF || buf[i] == '\0' || buf[i] == '\n') {
                count = 1;
                break;
            }
            buf[i] = (char)toupper(buf[i]);
        }
        if (count)
            break;
    }
}


int read(const int *Q, const int *P, char *S) {
    if (!check_char_pointer(S) || !check_int_pointer(Q) ||
        !check_int_pointer(P)) {
        printf(ERROR);
        return ERR;
    }
    int ok = scanf("%d%d", (int *)Q, (int *)P);
    CHECK_OK;

    getchar();

    //scan_string(S);
    scanf("%65s",S);
    ok=upcase_string(S);
    CHECK_OK;


    if (*Q > 36 || *P < 2) {
        return ERR;
    }
    return OK;
}

int main() {
    const int *const Q = (int *)calloc(1, sizeof(int));
    const int *const P = (int *)calloc(1, sizeof(int));
    char *S = (char *)malloc(STRING_SIZE);
    if (read(Q, P, S) != OK) {
        printf(ERROR);
        delete (P, Q, S);
        return 0;
    }
    translate(Q, P, S);
    delete (P, Q, S);

    return 0;
}
