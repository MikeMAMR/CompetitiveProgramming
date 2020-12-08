#include <bits/stdc++.h>
using namespace std;
char s[150][150];
int di[5] = {1,-1,0,0};
int dj[5] = {0,0,1,-1};
int n, m;
void cambio(){
    char tmp[150][150];
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
           if(s[i][j]=='P'){

                for(int k=0; k<4; k++){
                    int x = i+di[k];
                    int y = j+dj[k];
                    if(x>0 && x<=n && y>0 && y<=m){

                        if(s[x][y]=='R'){
                            //cout<<"p"<<endl;
                            tmp[x][y]='P';
                        }else if (tmp[x][y]=='\0') tmp[x][y] = s[x][y];
                    }
                }

           }else if(s[i][j]=='R'){

                for(int k=0; k<4; k++){
                    int x = i+di[k];
                    int y = j+dj[k];
                    if(x>0 && x<=n && y>0 && y<=m){

                        if(s[x][y]=='S'){
                            tmp[x][y]='R';
                        }else if (tmp[x][y]=='\0') tmp[x][y] = s[x][y];
                    }
                }

           }else if(s[i][j]=='S'){

                for(int k=0; k<4; k++){

                    int x = i+di[k];
                    int y = j+dj[k];
                    if(x>0 && x<=n && y>0 && y<=m){
                        if(s[x][y]=='P'){
                            tmp[x][y]='S';
                        }else if (tmp[x][y]=='\0') tmp[x][y] = s[x][y];
                    }
                }

           }

        }
    }
    for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(tmp[i][j]!='\0')
                    s[i][j]=tmp[i][j];
                tmp[i][j] = '\0';
            }
    }
   /* cout<<endl;
    for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                cout<<s[i][j];
            }
            cout<<endl;
    }*/
}
int main(){
    int cases;
    scanf("%d", &cases);
        while(cases--){
        int k;
        scanf("%d%d%d", &n, &m, &k);
            for(int i=1; i<=n; i++){
                for(int j=1; j<=m; j++){
                    scanf(" %c", &s[i][j]);
                }
            }
        while(k--){
            cambio();
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                cout<<s[i][j];
            }
            cout<<endl;
        }
        if(cases!=0) cout<<endl;
    }
    return 0;
}
