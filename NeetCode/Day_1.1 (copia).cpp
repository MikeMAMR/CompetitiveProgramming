#include <bits/stdc++.h>
using namespace std;
vector<int> num;
map<int, int> mp;
long long solve(){
    for(int i=0; i<num.size(); i++){

        if(mp[2020-num[i]]==1){
            return num[i] * (2020-num[i]);
        }
    }
}
 int main(){

    int n;
    while(scanf("%d", &n) != EOF){
        num.push_back(n);
        mp[n] = 1;
    }
    cout<<solve()<<endl;
    return 0;
 }
