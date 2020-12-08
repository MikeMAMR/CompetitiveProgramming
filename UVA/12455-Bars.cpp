#include <bits/stdc++.h>
using namespace std;
bool mark[100000], flag;
int arr[10000];
int n, a;
void fun(int num, int pos){
    if(pos==n){
        if(num==a){
            flag=true;
        }
        return;
    }
    if(flag){
        return;
    }
    fun(num+arr[pos], pos+1);
    fun(num, pos+1);
}
int main(){
    int cases;
    scanf("%d", &cases);
    while(cases--){
        scanf("%d%d", &a, &n);
        for(int i=0; i<n; i++){
            scanf("%d", &arr[i]);
        }
        flag=false;
        fun(0,0);
        printf(flag?"YES\n":"NO\n");
    }
    return 0;
}
