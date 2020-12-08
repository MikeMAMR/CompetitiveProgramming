#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    long long a, b;
    scanf("%d", &n);
    while(n--){
        scanf("%lld%lld", &a,&b);
        if(b>a){
            printf("impossible\n");
        }else{
           long long p = (a+b);
           if(p%2==0){
                p /= 2;
                b = p - b;
                printf("%lld %lld\n", p, b);
           }else{
            printf("impossible\n");
           }
        }

    }
    return 0;
}
