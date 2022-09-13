#include<bits/stdc++.h>
#define DBG(x) cerr << #x << " = " << (x) << endl
using namespace std;
typedef long long ll;
typedef vector<ll> vii;
typedef pair<int, int> pii;
typedef pair<int, string> ps;
long long const MAX =  1e3;
int const MAX2 = 1e6+1;
int const MOD = 10007;//1000000000+7;
const int inf=1e9;
const double PI = acos(-1.0);

int main(){
    //std::cin.tie(nullptr);
    //std::ios_base::sync_with_stdio(false);
    int n;
    vector<int> v;
    ll sum = 0;
    while(scanf("%d", &n), n){
        ll Acum = 0;
        int a;
        for(int i=0; i<n; i++){
            cin>>a;
            if(a!=0) v.push_back(a);
        }
        if(v.size()!=0){
            for(int i=0; i<v.size(); i++){
                cout<<v[i];
                if(i!=(v.size()-1)) cout<<" ";
            }
            cout<<"\n";
        }else cout<<"0\n";
        v.clear();
    }
    return 0;
}
