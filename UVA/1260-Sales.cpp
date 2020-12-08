#include <bits/stdc++.h>
using namespace std;
int main(){
    int N, m, arr[10000];
    scanf("%d", &N);
    while(N--){
        scanf("%d", &m);
        int cont = 0;
        for(int i=0; i<m; i++){
            scanf("%d", &arr[i]);
        }
        for(int i=m-1; i>0; i--){
            for(int j=0; j<i; j++){
                if(arr[j]<=arr[i]) cont++;
            }
        }
        printf("%d\n", cont);
    }
    return 0;
}
