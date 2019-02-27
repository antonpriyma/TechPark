#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

#define NONE 0
#define DELIMETER 1
#define NUMBER 3
#define YES 1
#define NO 0
#define END '\0'

char *expression;
int expIndex;
char *token;
int tokIndex;
size_t len;
int tokType;

int evalExp4(int *, int *, int *);
int evalExp3(int *, int *, int *, int *);
int stringToInt(char *, int *, int *);

int RemoveSpaces(char *source) {
    if (source == NULL) {
        return -1;
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

int isDelim(char c) {
    char delims[] = {'U', '^', '\\', '(', ')'};
    char size = 5;
    for (int i = 0; i < size; i++) {
        if (c == delims[i]) {
            return YES;
        }
    }
    return NO;
}

void getToken() {

    tokType = NONE;
    token[0] = '\0';
    tokIndex = 0;
    if (expIndex == len) {
        tokType = END;
        return;
    }

    if (isDelim(expression[expIndex])) {
        token[tokIndex++] = expression[expIndex];
        token[tokIndex] = '\0';
        expIndex++;
        tokType = DELIMETER;
    } else if (expression[expIndex] == '[') {
        while (expression[expIndex++] != ']') {
            token[tokIndex++] = expression[expIndex - 1];
        }
        token[tokIndex++] = expression[expIndex - 1];
        token[tokIndex] = '\0';
        tokType = NUMBER;
    }
}

int evalExp2(int *partResult1, int *partResult2, int *lenA) {
    char op;
    int *lenB = (int *)calloc(1, sizeof(int));
    int *buf = (int *)malloc(100 * sizeof(int));
    getToken();
    int err = evalExp3(partResult1, partResult2, buf, lenA);
    if (err == -1) {
        free(buf);
        free(lenB);
        return -1;
    }
    while ((op = token[0]) == 'U' || op == '^' || op == '\\') {
        getToken();
        err = evalExp3(partResult2, partResult1, buf, lenB);
        if (err == -1) {
            free(buf);
            free(lenB);
            return -1;
        }
        switch (op) {
            case 'U':
                unite(partResult1, partResult2, lenA, lenB);
                break;
            case '\\':
                sub(partResult1, partResult2, lenA, lenB);
                break;
            default:
                break;
        }
    }
    free(buf);
    free(lenB);
    return 0;
}

int evalExp3(int *partResult1, int *partResult2, int *buf, int *lenA) {
    int *lenB = (int *)calloc(1, sizeof(int));

    evalExp4(partResult1, partResult2, lenA);
    while (token[0] == '^') {
        getToken();
        int err = evalExp4(buf, partResult1, lenB);
        if (err == -1) {
            free(lenB);
            return -1;
        }
        intersection(partResult1, buf, lenA, lenB);
    }
    free(lenB);
    return 0;
}

int evalExp4(int *partResult1, int *partResult2, int *lenA) {

    if (*token == '(') {
        evalExp2(partResult1, partResult2, lenA);
        if (*token != ')') {
            return -1;
        }
        getToken();
        return 0;
    } else {
        stringToInt(token, partResult1, lenA);
    }

    return 0;
}

int stringToInt(char *token, int *partResult1, int *len) {
    RemoveSpaces(token);
    int count = 0;
    char *buf1 = (char *)malloc(100);
    int *buf = partResult1;
    for (int i = 0; i < tokIndex; i++) {
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
    getToken();
    free(buf1);
    return 0;
}

int execute(int *partResult1, int *partResult2, int *lenA) {
    int err = evalExp2(partResult1, partResult2, lenA);
    if (err == -1) {
        return -1;
    }
    return 0;
}

void printSet(int *set, int lenA) {
    printf("[");
    for (int i = 0, count = 0; i < lenA; i++) {
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
}

int main() {
    expIndex = 0;
    tokIndex = 0;
    token = (char *)malloc(100);
    token[0] = '\0';
    expression = (char *)malloc(100);
    gets(expression);
    int err = RemoveSpaces(expression);
    if (err == -1) {
        printf("[error]");
        return 0;
    }
    len = strlen(expression);
    int *partResult1 = (int *)malloc(100 * sizeof(int));
    int *partResult2 = (int *)malloc(100 * sizeof(int));
    int *lenA = (int *)calloc(1, sizeof(int));
    err = execute(partResult1, partResult2, lenA);
    if (err == -1) {
        free(lenA);
        free(partResult1);
        free(partResult2);
        printf("[error]");
        return 0;
    }
    printSet(partResult1, *lenA);

    free(lenA);
    free(partResult1);
    free(partResult2);
    return 0;
}