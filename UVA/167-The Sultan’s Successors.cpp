#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int x[100];
int y[100];
bool usd[100];
int mat[100][100];
ll mx2 = -1;
bool check(int a, int b, int dx){
    for(int i=0; i<dx; i++){
        if(abs(x[i]-a)==abs(y[i]-b)) return false;
    }
    return true;
}
void solve(int pos){
    if(pos==8){
        ll re = 0;
        for(int i=0; i<8; i++){
            re += mat[i][y[i]];
        }
        mx2 = max(mx2, re);

        return;
    }
    for(int i=0; i<8; i++){
        if(!usd[i] and check(pos, i, pos)){
            usd[i]=true;
            y[pos] = i;
            x[pos]=pos;
            solve(pos+1);
            usd[i]=false;
        }
    }
}
int main(){
    int cases;
    scanf("%d", &cases);
    while(cases--){
        for(int i=0; i<8; i++){
            for(int j=0; j<8; j++){
                scanf("%d", &mat[i][j]);
            }
        }
        mx2 = -1;
        solve(0);
        printf("%5.d\n", mx2);
    }
    return 0;
}
