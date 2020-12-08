#include <bits/stdc++.h>
using namespace std;
bool usd[10];
int x[20];
int y[20];
int arr[100];
int mx = 1000;
int check(int a, int b, int idx) {
    int i;
    for(i = 0; i < idx; i++)
        if(abs(x[i]-a) == abs(y[i]-b))
            return 0;
    return 1;
}
void solve(int pos){
    if(pos==8){
        int cont = 0;
        for(int i=0; i<8; i++){
            if(arr[i]!=y[i]+1){
                cont++;
            }
        }
        mx = min(cont, mx);
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
    string s;
    int cases=1;
    while(getline(cin, s)){
        int ind = 0;
        int pos = 0;
        while(ind < 8){
            arr[ind++] = s[pos]- '0';
            pos += 2;
        }
        mx = 1000;
        solve(0);

        printf("Case %d: %d\n", cases, mx);
        cases++;
    }
    return 0;
}
