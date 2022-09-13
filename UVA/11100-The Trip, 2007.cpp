#include<bits/stdc++.h>
#define DBG(x) cerr << #x << " = " << (x) << endl
using namespace std;
typedef long long ll;
typedef vector<ll> vii;
typedef pair<int, int> pii;
typedef pair<int, string> ps;
long long const MAX =  10010;
int const MAX2 = 2e5;
int const MOD = 10007;//1000000000+7;
const int inf=1e9;

int n, arr[MAX];
map<int, int> mp;
int main(){
    //std::cin.tie(nullptr);
    //std::ios_base::sync_with_stdio(false);
    int gg = 0;
    while(scanf("%d", &n), n){
        mp.clear();
        if(gg!=0) cout<<"\n";
        gg++;
        int c = 0;
        for(int i=0; i<n; i++){
            cin>>arr[i];
            mp[arr[i]] += 1;
            c = max(c, mp[arr[i]]);
        }
        sort(arr, arr+n);
        vii v[c+1];
        int ind = 0;
        for(int i=0; i<n; i++){
            v[ind].push_back(arr[i]);
            ind++;
            if(ind==c) ind=0;
        }
        cout<<c<<"\n";
        for(int i=0; i<c; i++){
            for(int j=0; j<v[i].size(); j++){
                cout<<v[i][j];
                if(j!=v[i].size()-1) cout<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}