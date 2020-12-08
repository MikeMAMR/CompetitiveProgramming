#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n, d, r;
    while(scanf("%d%d%d", &n,&d,&r), (d || n || r)){
        int a[10000], b[10000];
        for(int i=0; i<n; i++){
            scanf("%d", &a[i]);
        }
        for(int i=0; i<n; i++){
            scanf("%d", &b[i]);
        }
        sort(a,a+n);
        sort(b, b+n, greater<int>());
        ll cont = 0;
        for(int i=0; i<n; i++){
            int j = a[i]+b[i] - d;
            if(j>0){
                cont += j;
            }

        }
        cont *= r;
        cout<<cont<<endl;
    }
    return  0;
}
