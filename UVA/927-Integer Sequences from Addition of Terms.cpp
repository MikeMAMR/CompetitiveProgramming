#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, d, k;
    long long arr[100];
    scanf("%d", &n);
    while(n--){
        long long sum = 0;
        int f;
        scanf("%d", &m);
        for(int i=0;i<=m; i++){
            scanf("%lld", &arr[i]);
        }
        scanf("%d%d", &d, &k);
        for(f=1; f*f+f < 2*k/d; f++);
        for(int i=0; i<=m; i++){
            sum += arr[i]*(long long)pow(f, i);
        }

        printf("%lld\n", sum);
    }
    return 0;
}

