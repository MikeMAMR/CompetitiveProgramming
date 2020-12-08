#include <bits/stdc++.h>
using namespace std;
map<int, int> mp;
int main(){
    int m, a, b, c;
    scanf("%d", &m);
    while(m--){
        scanf("%d%d%d", &a, &b, &c);
        int fin = max(a, max(b, c));
        fin = sqrt(fin) + 1;
        int ini = fin*-1;
        bool flag = false;
        mp.clear();
        for(int i=ini; i<=fin; i++){
            if(flag) break;
            for(int j=ini; j<=fin; j++){
                if(flag /*or (mp[i]==1 and mp[j]==1)*/) break;
                int x = a - i - j;
                //mp[i] = mp[j] = mp[x] = 1;

                if((i+j+x==a) and (i*j*x==b) and (i*i + j*j + x*x == c) ){
                    if(i!=j and i!=x and j!=x){
                        cout<<i<<" "<<j<<" "<<x<<endl;
                        flag = true;
                    }

                    break;
                }
            }
        }
        if(!flag) cout<<"No solution."<<endl;
    }
    return 0;
}

