#include <iostream>



// В супермаркете решили оптимизировать показ рекламы.
// Известно расписание прихода и ухода покупателей (два целых числа).
// Каждому покупателю необходимо показать минимум 2 рекламы.
// Рекламу можно транслировать только в целочисленные моменты времени.
// Покупатель может видеть рекламу от момента прихода до момента ухода из магазина.
// В каждый момент времени может показываться только одна реклама.
// Считается, что реклама показывается мгновенно.
// Если реклама показывается в момент ухода или прихода, то считается, что посетитель успел её посмотреть.
// Требуется определить минимальное число показов рекламы.
typedef struct pair pair;
struct pair{
    int a;
    int b;
    pair(int a,int b){
        this->a=a;
        this->b=b;
    }
};

bool empty(pair pair){
    return (pair.a==0 && pair.b==0);
}

void add(pair* pairs, int a,int b,int i){
            pairs[i]=pair(a,b);
            return;
}


int countPair(int in, int out, pair* pairs, int n){
    int i =0;
    for (i =0;i<n && !empty(pairs[i]);i++){
        int result = 0;
        if (in>=pairs[i].a && out<=pairs[i].b){
            pairs[i].a=in;
            pairs[i].b=out;
            return 0;
        }
        if (in>=pairs[i].a && in<=pairs[i].b){
            result=1;
            if (in!=pairs[i].b){
                result=0;
                pairs[i].a=in;
            }

            return result;
        }
        if (out<=pairs[i].b && out>=pairs[i].a){
            result=1;
            if (out!=pairs[i].a){
                result=0;
                pairs[i].b=out;
            }

            return result;
        }
    }
    add(pairs,in,out,i);
    return 2;
}

int main() {
    int n=0,result=0;
    std::cin>>n;
    pair *pairs = (pair *)malloc(n* sizeof(pair));
    for (int i =0;i<n;i++){
        int in=0,out=0;
        std::cin>>in>>out;
        result+=countPair(in,out,pairs,n);
    }

    for (int i =1;i<n && !empty(pairs[i]);i++){
        if (pairs[i-1].b>pairs[i].a && pairs[i-1].b<=pairs[i].b){
            result=1;
            result-=1;
        }
        if (pairs[i-1].a<pairs[i].b && pairs[i-1].a>=pairs[i].a){
            result-=1;
        }
    }
    std::cout<<result;
    delete[](pairs);
    return 0;
}