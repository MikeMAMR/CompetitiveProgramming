#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;
struct pos{
    int i;
    int j;
};
int di[9]={1,0,-1,0,  +1,-1,-1,+1};
int dj[9]={0,1,0,-1, -1,+1,-1,+1};
long long mat[1000][1000];
char mapa[10000][10000];
int main(){
    queue<pos> q;
    int n, m, x=0, y=0;
    scanf("%d%d", &n,&m);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf(" %c", &mapa[i][j]);
            if(mapa[i][j]=='S'){

                x=i;
                y=j;
            }
        }
    }
    int a, b;
    scanf("%d%d", &a,&b);
    a--;
    b=n-b;

    pos nv;
    nv.i=b;
    nv.j=a;

    q.push(nv);

    while(!q.empty()){
        pos act = q.front();
        q.pop();
        int num = mat[act.i][act.j];
        for(int k=0; k<8; k++){
            int pi = act.i+di[k];
            int pj = act.j+dj[k];
            if(pi>=0 && pi<n && pj>=0 && pj<m){
                if(mat[pi][pj]==0 && (mapa[pi][pj]!='D' || mapa[pi][pj]!='#' )){
                       mat[pi][pj]=num+1;
                       pos nueva;
                       nueva.i=pi;
                       nueva.j=pj;
                       q.push(nueva);
                }
            }
        }

    }
    /*for(int i=0; i<n; i++){*
        for(int j=0; j<m; j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }*/
    printf("%d", mat[x][y]+1);
    return 0;
}
