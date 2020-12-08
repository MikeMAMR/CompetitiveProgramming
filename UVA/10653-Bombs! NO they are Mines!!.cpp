#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;
struct pos{
    int i;
    int j;
};

int di[5]={1,0,-1,0};
int dj[5]={0,1,0,-1};
long long mat[1000][1000];
int main(){
    while(true){

        queue<pos> q;
        int n, m, fila, nf, nc, culm;
        int x, y,a,b;

        scanf("%d%d", &n, &m);
        if(n==0 && m==0){
            break;
        }
        scanf("%d", &fila);
        for(int i=0; i<fila; i++){
            scanf("%d%d", &nf, &nc);
            for(int j=0; j<nc; j++){
                scanf("%d", &culm);
                mat[nf][culm]=1;
            }

        }

        scanf("%d%d", &x, &y);
        scanf("%d%d", &a, &b);

        pos nv;
        nv.i = x;
        nv.j = y;
        q.push(nv);

        while(!q.empty()){
            pos act = q.front();
            q.pop();
            int num = mat[act.i][act.j];
            for(int k=0; k<4;k++){
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

        printf("%lld\n", mat[a][b]);
         for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                mat[i][j]=0;
            }
        }
    }
    return 0;
}
