#include <bits/stdc++.h>
using namespace std;
int mat[4][4], tmp[4][4];
char s[4][4];
int di[4] = {1,-1,0,0};
int dj[4] = {0,0, 1, -1};
int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        int rec = 0, cont=0;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                scanf(" %c", &s[i][j]);
                mat[i][j] = s[i][j] - '0';
                if(s[i][j]=='0') rec++;

            }
        }
        if(rec==9) printf("-1\n");
        else{
            while(true){
                    rec = 0;
                for(int i=0; i<3; i++){
                    for(int j=0; j<3; j++){
                        int gg = 0;
                        for(int k=0; k<4; k++){
                            int xi = i + di[k];
                            int xj = j + dj[k];
                            if(xi>=0 and xi<3 and xj>=0 and xj<3){
                                gg += mat[xi][xj];
                            }
                        }
                        //cout<<"f "<<gg<<endl;
                        tmp[i][j] = gg%2;
                    }
                }
                cont++;
                for(int i=0; i<3; i++){
                    for(int j=0; j<3; j++){
                        //cout<<tmp[i][j];
                        mat[i][j] = tmp[i][j];
                        if(tmp[i][j]==0) rec++;
                    }
                    //cout<<endl;
                }
                if(rec==9) break;

            }
            printf("%d\n", cont-1);
        }
    }
    return 0;
}
