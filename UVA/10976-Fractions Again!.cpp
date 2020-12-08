#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;
ii arr[10000];
map<int, int> mp;
int main(){
    int n;
    while(scanf("%d",&n) != EOF){
        ll x = 0, y=0;
        int ind = 0;
        mp.clear();
        for(ll i=n+1; i<=(n*2); i++){
            x = (n*i) / (i-n);
            y = (x*i)/(x+i);
            if(y==n){
                if(mp[i]!=1){
                    mp[i]=1;
                    mp[x] =1;
                    arr[ind].f =x;
                    arr[ind].s = i;
                    ind++;
                }

            }
        }
        printf("%d\n", ind);
        for(int i=0; i<ind;  i++){
            printf("1/%d = 1/%lld + 1/%lld\n", n, arr[i].f, arr[i].s);

        }
    }
    return 0;
}
