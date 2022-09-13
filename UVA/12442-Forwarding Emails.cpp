#include<bits/stdc++.h>
#define DBG(x) cerr << #x << " = " << (x) << endl
using namespace std;
typedef long long ll;
typedef vector<int> vii;
typedef pair<int, int> pii;
typedef pair<int, string> ps;
long long const MAX =  500;
int const MAX2 = 1e5+10;
int const MOD = 1000000000+7;
const int inf=1e9;
const double PI = acos(-1.0);
long long M = 1e18;

vector<int> adj[50010];
bool usd[50010];
bool pas[50010];
int mx = 0;
int mx2 = 0;
void dfs(int nodo, int sum){
    //cout<<"Nodo: "<<nodo<<"sum: "<<sum<<"\n";
    for(int i: adj[nodo]){
        if(!usd[i]){
            pas[i] = true;
            usd[i] = true;
            mx = max(mx, sum+1);
            dfs(i, sum+1);
            usd[i] = false;
        }
    }
}
void limp(int n){
    for(int i=0; i<=n; i++){
        adj[i].clear();
        pas[i] = false;
    }

}
void limp2(int n){
    for(int i=0; i<=n; i++){
        usd[i] = false;

    }
}

int main(){
    //std::cin.tie(nullptr);
    //std::ios_base::sync_with_stdio(false);
    int cases, k=0, n, a, b;
    cin>>cases;
    while(cases--){
        cin>>n;
        limp(n);
        for(int i=0; i<n; i++){
            cin>>a>>b;
            adj[a].push_back(b);
        }
        mx = 0;
        mx2 = -1;
        int ans = 0;
        for(int i=1; i<=n; i++){
            if(!pas[i]){
                    //cout<<"i: "<<i<<"\n";
                mx = 0;
                pas[i] = true;
                //limp2(n);
                usd[i] = true;
                dfs(i, 0);
                if(mx>mx2){
                    mx2 = mx;
                    ans = i;
                }

                usd[i] = false;
            }
        }
        k++;
        cout<<"Case "<<k<<": "<<ans<<"\n";
    }
    return 0;
}
