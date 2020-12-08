#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    while(scanf("%d%d", &n,&m), (n, m)){
        char s[600][600], s1[600][600], s2[600][600], s3[600][600], s4[600][600];
        int a=0, b=0, c=0, d=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                scanf(" %c", &s[i][j]);
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<m; j++){
                scanf(" %c", &s1[i][j]);
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<m; j++){
                s2[i][j] = s1[m-j-1][i];
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<m; j++){
                s3[i][j] = s2[m-j-1][i];
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<m; j++){
                s4[i][j] = s3[m-j-1][i];
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i+m <= n && j+m <= n){
                    bool flag = true;
                    for(int ii=0; ii<m; ii++){
                        for(int jj=0; jj<m; jj++){
                            if(s1[ii][jj]!=s[i+ii][j+jj]) flag = false;
                        }
                    }
                    if(flag) a++;
                    flag= true;
                    for(int ii=0; ii<m; ii++){
                        for(int jj=0; jj<m; jj++){
                            if(s2[ii][jj]!=s[i+ii][j+jj]) flag = false;
                        }
                    }
                    if(flag) b++;
                    flag= true;
                    for(int ii=0; ii<m; ii++){
                        for(int jj=0; jj<m; jj++){
                            if(s3[ii][jj]!=s[i+ii][j+jj]) flag = false;
                        }
                    }
                    if(flag) c++;
                    flag= true;
                    for(int ii=0; ii<m; ii++){
                        for(int jj=0; jj<m; jj++){
                            if(s4[ii][jj]!=s[i+ii][j+jj]) flag = false;
                        }
                    }
                    if(flag) d++;
                    flag= true;
                }
            }
        }
        cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    }

    return 0;
}
