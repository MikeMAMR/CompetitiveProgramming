#include <bits/stdc++.h>
using namespace std;
int main(){
    int c, n;
    scanf("%d", &c);
    while(c--){
        int arr[200], mn=1e9,mx=-1;
        scanf("%d", &n);
        for(int i=0; i<n; i++){
            scanf("%d", &arr[i]);
            if(arr[i]>mx) mx = arr[i];
            if(arr[i]<mn) mn = arr[i];
        }
        printf("%d\n", (mx-mn)*2);
    }
    return 0;
}
