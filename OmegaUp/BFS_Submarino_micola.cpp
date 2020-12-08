#include <stdio.h>
#include <iostream>
struct sub{
    int val;
    int pasos;
};
struct nodo{
    sub val;
    nodo* next;
    nodo(){
        next=NULL;
    }
    nodo(sub val){
        next=NULL;
        this->val=val;
    }
};
struct cola{
    nodo* head;
    nodo* tail;
    cola(){
        head=NULL;
        tail=NULL;
    }
    bool isEmpty(){
        return head==NULL;
    }
    sub front1(){
        return head->val;
    }
    void push(sub val){
        nodo* nd = new nodo(val);
        if(tail!=NULL){
            tail->next=nd;
        }
        tail=nd;
        if(head==NULL){
            head=nd;
        }
    }
    void pop(){
        nodo* tmp=head;
        head=head->next;
        if(head==NULL){
            tail=NULL;
        }
        delete tmp;
    }
};
bool mark[100000];
bool matAd[110][110];
int cont=0;
int main(){
    cola q;
    int n, m, t;
    int a, b;
    scanf("%d%d%d", &n, &m, &t);
    for(int i=0; i<m; i++){
        scanf("%d%d",&a,&b);
        matAd[a][b]=true;
        matAd[b][a]=true;
    }
    sub nv;
    nv.val = n;
    nv.pasos=0;

    q.push(nv);
    mark[n]=true;
    while(!q.isEmpty()){
        sub act = q.front1();
        q.pop();
        int incre = act.pasos;
        if((incre+1)<t){
            for(int i=1; i<=n; i++){
                if(matAd[act.val][i]==true && mark[i]==false){
                    sub nueva;
                    nueva.val=i;
                    nueva.pasos=incre+1;
                    q.push(nueva);
                    mark[i]=true;
                    cont++;
                }
            }
        }
    }
    printf("%d", cont);
    return 0;
}
