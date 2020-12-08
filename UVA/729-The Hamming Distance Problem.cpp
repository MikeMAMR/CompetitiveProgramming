#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int mat[20];
int n, h;
void bin(int pos, int num){
    if(pos==n){
        if(num==h){
            for(int i=0; i<n; i++){
                printf("%d", mat[i]);
            }
            printf("\n");
        }
        return;
    }
    if(num>h) return;
    mat[pos]=0;
    bin(pos+1, num);
    mat[pos] = 1;
    bin(pos+1, num+1);
}
int main(){
    int cas;
    //int cont=1;
    scanf("%d", &cas);
    while(cas--){
        //printf("%d\n", cont++);
        scanf("%d%d", &n, &h);
        bin(0, 0);
        if(cas) printf("\n");
    }


    return 0;
}
