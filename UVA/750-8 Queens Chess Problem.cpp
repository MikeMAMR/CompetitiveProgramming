#include <bits/stdc++.h>
using namespace std;
bool usd[10];
int x[20];
int y[20];
int arr[100];
int mx = 1000;
int cases;
int a, b;
int check(int a, int b, int idx) {
    int i;
    for(i = 0; i < idx; i++)
        if(abs(x[i]-a) == abs(y[i]-b))
            return 0;
    return 1;
}
void solve(int pos){
    if(pos==8){
        if(y[b-1] == a-1){
            printf("%2d      ", cases);
            cases++;
            for(int i=0; i<8; i++){
               printf("%d", y[i]+1);
               if(i!=7) printf(" ");
            }
            printf("\n");
        }
        return;
    }

    for(int i=0; i<8; i++){
        if(usd[i]==0 and check(pos, i, pos) != 0){
            usd[i]=true;
            y[pos] = i;
            x[pos] = pos;
            solve(pos+1);
            usd[i] = 0;
        }
    }
}
int main(){
    int h;
    scanf("%d", &h);
    while(h--){
        scanf("%d%d", &a,&b);
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        cases = 1;
        solve(0);
        if(h) printf("\n");
    }
    return 0;
}
