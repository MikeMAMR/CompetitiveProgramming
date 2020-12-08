#include <stdio.h>
struct pos{
    int i;
    int j;
};
struct nodo{
    pos val;
    nodo* next;
    nodo(){
        next=NULL;
    }
    nodo(pos val){
        next=NULL;
        this->val=val;
    }
};
struct cola{
    nodo* head;
    nodo* tail;
    cola(){
        tail=NULL;
        head=NULL;
    }
    bool isEmpty(){
        return head==NULL;
    }
    pos fronts(){
        return head->val;
    }
    void push(pos val){
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
        head= head->next;
        if(head==NULL){
            tail=NULL;
        }
        delete tmp;
    }
};
int mat[500][500];
int di[5] = {1,0,-1,0};
int dj[5] = {0,1,0,-1};
int main(){
    cola q;
    int n;
    int m;
    scanf("%d%d", &n, &m);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &mat[i][j]);
        }
    }
    int a, b;
    int x, y;
    scanf("%d%d", &a, &b);
    scanf("%d%d", &x, &y);

    pos nv;
    nv.i = a;
    nv.j = b;
    q.push(nv);

    while(!q.isEmpty()){
        pos act = q.fronts();
        q.pop();
        int num = mat[act.i][act.j];
        for(int k=0; k<4; k++){
            int pi = act.i+di[k];
            int pj = act.j+dj[k];
            if(pi>=0 && pi<n && pj>=0 && pj<m){
                if(mat[pi][pj]==0 && mat[pi][pj]!=1){
                    mat[pi][pj]= num+1;
                    pos nueva;
                    nueva.i = pi;
                    nueva.j = pj;
                    q.push(nueva);
                }
            }
        }
    }
    printf("%d", mat[x][y]+1);
    return 0;

}
