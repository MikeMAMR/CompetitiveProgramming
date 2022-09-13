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

bool usd[200];
vector<int> listAd[200];
vector<int> ord;

void limp(int n){
    for(int i=0; i<=n; i++){
        usd[i] = false;
        listAd[i].clear();
    }
}
void orden(int i){
    usd[i] = true;
    for(int k=0; k<listAd[i].size(); k++){
        if(!usd[listAd[i][k]]){
            orden(listAd[i][k]);
        }
    }
    ord.push_back(i);
}


int main(){
    //std::cin.tie(nullptr);
    //std::ios_base::sync_with_stdio(false);
    int n, m, a, b;
    while(scanf("%d%d", &n, &m) , (n || m)){
        limp(n);
        ord.clear();
        for(int i=0; i<m; i++){
            scanf("%d%d",&a,&b);
            listAd[a].push_back(b);
        }
        for(int i=1; i<=n; i++){
            if(!usd[i]) orden(i);
        }
        for(int i=ord.size()-1; i>=0;i--){
            cout<<ord[i];
            if(i) cout<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
