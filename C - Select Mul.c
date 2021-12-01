/* https://atcoder.jp/contests/abc221/tasks/abc221_c */
#include <stdio.h>
int A_box[10];
int B_box[10];
int rank[10];
int t; //桁数
long long bi_num;
long long MAX;

long long makeA(){
    long long n;
    int i,j;
    for(i=9,j=0,n=0;i>=0;){
        if(A_box[i]==0){
            j=0;
            do{
                i--;
            }while((A_box[i]==0)&&(i>=0));
        }
        if(i>=0){
            n = n*10 + i;
            A_box[i]--;
        }
    }
    return(n);
}

long long makeB(){
    long long n;
    int i;
    for(i=9,n=0;i>=0;){
        if(B_box[i]==0){
            do{
                i--;
            }while((B_box[i]==0)&&(i>=0));
        }
        if(i>=0){
            n = n*10 + i;
            B_box[i]--;
        }
    }
    return(n);
}

void makebox(){
    long long n;
    int i;
    n = bi_num;
    i = 1;
    while(n!=2){
        if(n%10==1){
            A_box[rank[i]]++;
        }else{
            B_box[rank[i]]++;
        }
        n /= 10;
        i++;
    }
}

void makebinaly(int r){
    long long A,B;
    r++;
    bi_num = bi_num*10;
    if(r<=t){
        makebinaly(r);
    }else{
        makebox();
        A = makeA();
        B = makeB();
        if(MAX<A*B){
            MAX = A*B;
        }
    }
    bi_num /= 10;
    bi_num = bi_num*10 + 1;
    if(r<=t){
        makebinaly(r);
    }else{
        makebox();
        A = makeA();
        B = makeB();
        if(MAX<A*B){
            MAX = A*B;
        }
    }
    bi_num /= 10;
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long NC;
    NC=N;
    t=0;
    do{
        t++;
        rank[t] = NC % 10;
        NC /= 10;
    }while(NC>0);
    bi_num = 2;
    MAX=0;
    makebinaly(1);
    printf("%lld",MAX);
    return 0;
}