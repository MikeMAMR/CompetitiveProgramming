#include <bits/stdc++.h>
using namespace std;
int arr[100000];
int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        int pot = pow(2, n);
        for(int i=0; i<pot; i++){
            scanf("%d", &arr[i]);
        }
        int tmp[100000];
        for(int i=0; i<pot; i++){
            tmp[i]= 0;
            for(int j=0; j<pot; j++){
                if(i!=j){
                    int p = i ^ j;
                    if((p & (-p)) ==p){
                        tmp[i] += arr[j];
                    }
                }
            }
        }
        int mx = 0;
        for(int i=0; i<pot; i++){
            for(int j=0; j<pot; j++){
                if(i!=j){
                    int p = i ^ j;
                    if((p & (-p)) ==p){
                       mx = max(mx, tmp[i]+tmp[j]);
                    }
                }
            }
        }
        cout<<mx<<endl;
    }

    return 0;
}
