#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;
struct sub{
    int val;
    int pasos;
};
bool mark[100000];
bool matAd[110][110];
int cont=0;

int main(){
    queue<sub> q;
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
    while(!q.empty()){
        sub act = q.front();
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

