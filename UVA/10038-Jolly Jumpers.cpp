#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while(scanf("%d", &n) != EOF){
        long long arr[30000];
        long long mark[30000];
        for(int i=1; i<=n; i++){
            mark[i] = 0;
        }
        for(int i=0; i<n; i++){
            scanf("%lld", &arr[i]);
            if(i>=1){
                //cout<<abs(arr[i]-arr[i-1])<<endl;
                if(abs(arr[i]-arr[i-1])<=n) mark[abs(arr[i]-arr[i-1])]=1;
            }

        }
        int cont=0;
        for(int i=1; i<=n-1; i++){
            //cout<<mark[i]<<endl;
            if(mark[i]==1) cont++;
        }
        if(cont==n-1) cout<<"Jolly"<<endl;
        else cout<<"Not jolly"<<endl;

    }
    return 0;
}
