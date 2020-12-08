#include <bits/stdc++.h>
using namespace std;
int dig(int n){
    int sum = 0;
    while(n>0){
        sum+=n%10;
        n/=10;
    }
    return sum;
}
int main(){
    int n;
    while(scanf("%d", &n), (n)){
        int tmp = n;
        while((tmp/10)>0){
            tmp = dig(n);
            n = dig(n);
        }
        printf("%d\n", tmp);
    }

	return 0;
}
