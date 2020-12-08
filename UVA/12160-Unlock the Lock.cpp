#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int p = 1e5;
int convert(int n){
    int num = 0;
    int d = 1;
    for(int i=0; i<4; i++){
        num += ((n%10)* d);
        d *= 10;
        n = (n/10);
    }
    return num;
}
map<int, int> mp;
int main(){
    int l, u, r;
    int c = 1;
    while(scanf("%d%d%d", &l, &u, &r), (l || r || u)){
        mp.clear();
        int button[100];
        for(int i=0; i<r; i++){
            scanf("%d", &button[i]);
        }
        int mn = 1e9;
        queue<pii> q;
        q.push({l, 0});
        bool flag = false;
        while(!q.empty()){
            pii tmp = q.front();
            q.pop();
            for(int i=0; i<r; i++){
                int sum = button[i] + tmp.f;
                if(mp[sum]!=1 and !flag and sum<=1e18 and tmp.s<=9999){
                    if(sum>=9999){
                        int f = convert(sum);
                        if(mp[f]!=1){
                            mp[f] = 1;
                            if(f==u){
                                flag = true;
                                mn = min(mn, tmp.s+1);
                            }
                            q.push({f, tmp.s+1});

                        }
                    }else{
                        if(sum==u){
                            flag = true;
                            mn = min(mn, tmp.s+1);
                        }
                        q.push({sum, tmp.s+1});
                        mp[sum] = 1;
                    }


                }
            }
        }
        if(flag) printf("Case %d: %d\n", c, mn);
        else printf("Case %d: Permanently Locked\n", c, mn);
        c++;
    }

    return 0;
}
