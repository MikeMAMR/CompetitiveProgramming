#include <stdio.h>
#include <iostream>
using namespace std;
struct calc{
    int val;
    int paso;
};
struct nodo{
    calc val;
    nodo* next;
    nodo(){
        next=NULL;
    }
    nodo(calc val){
        next=NULL;
        this->val=val;
    }
};
struct cola{
    nodo* tail;
    nodo* head;
    cola(){
        tail=NULL;
        head=NULL;
    }
    bool isEmty(){
        return head==NULL;
    }
    calc fronts(){
        return head->val;
    }
    void push(calc val){
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
        nodo* tmp = head;
        head=head->next;
        if(head==NULL){
            tail=NULL;
        }
        delete tmp;
    }
};
bool repe[100000];
int a, b, c;

int main(){
    cola q;

    scanf("%d%d%d", &a,&b,&c);

    repe[1]=1;
    calc nv;

    nv.val=1;
    nv.paso=0;

    q.push(nv);

    while(!q.isEmty()){

        calc act = q.fronts();
        q.pop();
        //cout<<act.val<<" " <<act.paso<<endl;
        if(act.val==c){
            cout<<act.paso<<endl;
            break;
        }
        int valor = act.paso;
        int por2 = act.val*a;
        int divb = act.val/b;
        if(divb>0 && divb<=9999){
            if(repe[divb]==false){
                calc nueva;
                nueva.val = divb;
                nueva.paso = valor+1;
                q.push(nueva);
                repe[divb]=true;
            }
        }
        if(por2>0 && por2<=9999){
            if(repe[por2]==false){
                calc nueva;
                nueva.val = por2;
                nueva.paso = valor+1;
                q.push(nueva);
                repe[por2]=true;
            }

        }


    }

    return 0;
}
