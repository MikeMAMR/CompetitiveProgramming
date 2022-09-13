#include<bits/stdc++.h>
#define DBG(x) cerr << #x << " = " << (x) << endl
using namespace std;
typedef long long ll;
typedef vector<ll> vii;
typedef pair<int, int> pii;
typedef pair<int, string> ps;
long long const MAX = 2e5+10;
int const MAX2 = 2e5;
int const MOD = 10007;//1000000000+7;
const int inf=1e9;

int mark[200];
vii lisAd[200];
int nd[200];

int mn = -1;
vii tmp;
vii re;
int n, m, a, b;
bool isBlack(int nodo){
    for(int i=0; i<lisAd[nodo].size(); i++){
        if(mark[lisAd[nodo][i]]==1) return true;
    }
    return false;
}
//1 white
//0 black
void solve(int pos, int cont ){
    if(pos==(n+1)){
        if(cont>mn){
            mn = cont;
            vii gg;
            for(int i=1; i<=n; i++){
                if(nd[i]==1){
                    gg.push_back(i);
                }
            }
            tmp = gg;
        }
        return;
    }
    //if(mark[pos]) return;
    bool check = true;
    for(auto q: lisAd[pos]){
        if(mark[q] && nd[q]==1){
            check = false;
            break;
        }
    }
    mark[pos] = 1;
    if(check){
        nd[pos] = 1;
        solve(pos+1, cont+1);

    }
    nd[pos] = 0;
    solve(pos+1, cont);
    mark[pos] = 0;
}


int main(){
    //UVA NO
    //std::cin.tie(nullptr);
    //std::ios_base::sync_with_stdio(false);
    int cases;
    cin>>cases;
    while(cases--){
        mn = -1;
        tmp.clear();
        re.clear();
        for(int i=1; i<=100; i++)lisAd[i].clear();
        cin>>n>>m;
        for(int i=0; i<m;i++){
            cin>>a>>b;
            lisAd[a].push_back(b);
            lisAd[b].push_back(a);
        }
        solve(1, 0);
        cout<<tmp.size()<<"\n";
        for(int i=0; i<tmp.size(); i++){
            cout<<tmp[i];
            if(i!=tmp.size()-1) cout<<" ";

        }
        cout<<"\n";
    }
    return 0;
}