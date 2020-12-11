#include <bits/stdc++.h>
using namespace std;
vector<int> num;
map<int, int> mp;
long long solve(){
    for(int i=0; i<num.size(); i++){
        for(int j=i+1; j<num.size(); j++){
            for(int k=j+1; k<num.size(); k++){
                if(num[i]+num[j]+num[k]==2020){
                    return num[i]*num[j]*num[k];
                }
            }
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
