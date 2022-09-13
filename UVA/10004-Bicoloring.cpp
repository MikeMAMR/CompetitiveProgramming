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

bool usd[MAX];
int color[MAX];
vector<int> arr[MAX];
int cases, n, m, a, b;
bool bfs(){
    queue<pii> q;
    usd[0] = 1;
    color[0] = 1;
    q.push({0,1}); //nodo color
    while(!q.empty()){

        pii tmp = q.front();
        //cout<<tmp.first<<"\n";
        q.pop();
        for(int i=0; i<arr[tmp.first].size(); i++){
            if(usd[arr[tmp.first][i]]==true){
                if(color[arr[tmp.first][i]]==color[tmp.first]) return false;
            }else{
                usd[arr[tmp.first][i]] = true;
                int tmpC;
                if(tmp.second==1) tmpC = 2;
                else tmpC = 1;
                color[arr[tmp.first][i]] = tmpC;
                q.push({arr[tmp.first][i], tmpC});
            }
        }
    }
    return true;
}
void limp(){
    for(int i=0; i<=m; i++){
        usd[i] = false;
        color[i] = 0;
        arr[i].clear();
    }
}
int main(){
    //std::cin.tie(nullptr);
    //std::ios_base::sync_with_stdio(false);

    while(scanf("%d", &m) , m){
        cin>>n;
        limp();
        for(int i=0; i<n; i++){
            cin>>a>>b;
            arr[a].push_back(b);
            arr[b].push_back(a);
        }
        bool ans = bfs();
        if(ans) cout<<"BICOLORABLE.\n";
        else cout<<"NOT BICOLORABLE.\n";

    }
    return 0;
}
