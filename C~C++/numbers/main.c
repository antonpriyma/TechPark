#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ERROR "[error]"
#define ERR 0
#define OK 1


void delete(const int* p,const int* q,char* c)
{
    free((int *)p);
    free((int *)q);
    free(c);
}

int decToInt(char c)
{
    if (c<='9' && c>='0')
    {
        return c-'0';
    }
    if (c>='A' && c<='Z')
    {
        return c-'A'+10;
    }

    return ERR;
}

int checkChar(char c,int Q)
{
    if (!((c<='9' && c>='0')  || (c>='A' && c<='Z'))|| decToInt(c)>=Q)
    {
        return ERR;
    }
    return OK;
}

char intToDec(size_t i)
{
    if (i>=0 && i<=9)
    {
        return (char )('0'+i);
    }
    if (i>=10 && i<36)
    {
        return (char)('A'+i-10);
    }
    return 0;
}

void translate(const int* Q,const int* P, const char *const S)
{
    //Проверка на валидность
    size_t size=0,i=0;
    size_t numb=0,power=1,buf=0;
    char* result=NULL;
    if (!S)
    {
        printf(ERROR);
        return;
    }

    for (const char* c = S;(*c)!='\0';c++)
    {
        if (!(checkChar(*c,*Q)))
        {
            printf(ERROR);
            return;
        } else
        {
            size++;
        }
    }

    for (i=size;i>0;i--)
    {
        numb+=decToInt(*(S+i-1))*power;
        power*=(*Q);
    }
   // printf("%d",numb);
    size=0;
    buf = numb;
    while (buf>0)
    {
       buf/=(*P);
       size++;
    }
    result=(char *)malloc(size+1);
    result[size]='\0';
    i=1;
    while (numb>0)
    {
        result[size-i]=intToDec(numb%(*P));
        i++;
        numb/=(*P);
    }
    printf("%s",result);
    free(result);
}

int read(const int *Q,const int *P,char *S)
{
    scanf("%d%d",(int *)Q,(int *)P);
    char c;
    getchar();
    int i=1;
    size_t n1=99;
    while ((c= (char) getchar()) !=EOF)
    {
        if (i>=n1)
        {
            S=(char *)realloc(S,n1*2);
            n1*=2;
        }
        *(S+i-1)=(char)toupper(c);//считывание строки
        *(S+i)='\0';
        i++;
    }
    if (*Q>36 || *P<2)
    {
        printf(ERROR);
        delete(P,Q,S);
        return ERR;
    }
    return OK;
}

int main()
{
    const int *const Q=(int *)calloc(1,sizeof(int));
    const int *const P=(int *)calloc(1,sizeof(int));
    char *S = (char *)malloc(100);
    if (read(Q,P,S)!=OK)
    {
        return 0;
    }
    translate(Q,P,S);
    delete(P,Q,S);

    return 0;

}

