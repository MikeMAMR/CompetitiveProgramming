#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef pair<int, int> pi;
queue<pi> q;
int di[10]={0,0,1,-1};
int dj[10]={1,-1,0,0};
long long mat[2010][2010];
char s[2000][2000];
int qi=0, qj=0;
long long menor=1e15;
int main(){
    int n, m, p;
    scanf("%d%d", &n,&m);
    int x, y, a,b;
    scanf("%d%d",&a,&b);
    scanf("%d%d",&x,&y);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf(" %c", &s[i][j]);
        }
    }
    q.push({a-1,b-1});
    while(!q.empty()){
        pi act = q.front();
        q.pop();
        int inc = mat[act.f][act.s];
        for(int k=0; k<4; k++){
            int i = act.f + di[k];
            int j = act.s + dj[k];
            if(i>=0  && j>=0 && i<n && j<m){
                if((s[i][j]!='#') ){
                    if(mat[i][j]==0){
                        mat[i][j]=inc+1;
                        if(s[i][j]>='1' && s[i][j]<='9'){
                            mat[i][j]+=(s[i][j]-48);
                        }
                        q.push({i,j});
                    }else{
                        int com=0;
                        if(s[i][j]>='1' && s[i][j]<='9'){
                            com=(s[i][j]-48);
                        }

                        if((inc+1+com)<mat[i][j]){
                                q.push({i,j});
                                mat[i][j]=inc+1+com;
                        }
                    }

                }
            }
        }
    }
    /*for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            printf("%4d", mat[i][j]);
        }
        printf("\n");
    }*/
    printf("%lld",mat[x-1][y-1]);
    return 0;
}
