#include <bits/stdc++.h>
using namespace std;
int main(){
    int cas, n, m, a;
    while(scanf("%d", &cas) , (cas)){
        multiset<int> mset;
        multiset<int> :: iterator ita;
        multiset<int> :: iterator itb;
        long long sum = 0;
        while(cas--){
            scanf("%d", &m);
            for(int i=0; i<m; i++){
                scanf("%d", &a);
                mset.insert(a);
            }
            ita = mset.begin();
            itb = mset.end();
            itb--;
            sum += (*itb) - (*ita);
            mset.erase(ita);
            mset.erase(itb);


        }
        cout<<sum<<endl;
    }
    return 0;
}
