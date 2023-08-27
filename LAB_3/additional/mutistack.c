#include<stdio.h>
#include<stdlib.h>
# define MAX 16

typedef struct{
    int key;
}element;

element mstack[MAX];
int *tops,*bnds;
int i;

void init(int N){
    int SZ = MAX/N;
    tops = (int*)malloc(N*sizeof(int));
    bnds = (int*)malloc(N*sizeof(int));
    tops[0] = -1;
    bnds[0] = -1;
    for(i=1;i<N;i++){
        tops[i] = SZ*i;
        bnds[i] = SZ*i;
    }
    bnds[N]=MAX;
}

void Push(int x,element e){
    if(tops[x]<bnds[x+1]){
        tops[x]++;
        mstack[tops[x]] = e;
    }
    else{
        printf("%d stack is full\n",x);
    }
}

element Pop(int x){
    element ret;
    ret.key =-1;
    if(tops[x]==bnds[x]){
        printf("%d stack is empty\n",x);
    }
    else{
        ret= mstack[tops[x]--];
    }
    return ret;
}

void main(){
    element e;
    init(4);
    e.key=12;
    Push(0,e);
    e.key=13;
    Push(0,e);
    e.key=4;
    Push(0,e);
    e.key=56;
    Push(0,e);
    e.key=56;
    Push(0,e);
    e.key=56;
    Push(0,e);
    printf("%d",Pop(0));
}