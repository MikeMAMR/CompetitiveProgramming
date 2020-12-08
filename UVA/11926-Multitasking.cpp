#include <bits/stdc++.h>
using namespace std;
const int mx = 1e6 + 1;
bitset<mx> bs;
int main(){
    int n, m;
    long long a, b,c;
    while(scanf("%d%d", &n, &m), (n || m)){
        bs.reset();
        bool flag = true;
        int cont = 0;
        while(n--){
            scanf("%lld%lld", &a, &b);
            if(flag){
                for(int i=a; i<b; i++){
                    if(i<mx){
                        if(bs.test(i)){
                            flag = false;
                        }else bs.set(i);
                    }
                }
            }
        }

        while(m--){
            scanf("%lld%lld%lld", &a, &b, &c);
            bool lim = true;
            while(lim and flag){
                for(int i=a; i<b; i++){
                    if(i<mx){
                        if(bs.test(i)){
                            flag = false;
                        }
                        bs.set(i);
                    }else{
                        lim = false;
                        break;
                    }
                }
                cont = 0;
                a += c;
                b += c;
            }
        }
        printf(flag?"NO CONFLICT\n":"CONFLICT\n");
    }
    return 0;
}
