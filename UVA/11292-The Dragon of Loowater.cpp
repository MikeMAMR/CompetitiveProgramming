#include<bits/stdc++.h>
#define DBG(x) cerr << #x << " = " << (x) << endl
using namespace std;
typedef long long ll;
typedef vector<ll> vii;
typedef pair<int, int> pii;
typedef pair<int, string> ps;
long long const MAX = 20010;
int const MAX2 = 2e5;
int const MOD = 10007;//1000000000+7;
const int inf=1e9;

int main(){
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    int n, m;
    int dragon[MAX], knight[MAX];
    while(scanf("%d%d", &n, &m), (n || m)){
        int posDra = 0, posKn = 0;
        for(int i=0; i<n; i++){
            scanf("%d", &dragon[i]);
        }
        for(int i=0; i<m; i++){
            scanf("%d", &knight[i]);
        }
        sort(dragon, dragon+n);
        sort(knight, knight+m);
        ll sum = 0;
        while(1){
            if(posKn>=m || posDra>=n) break;
            if(knight[posKn]>=dragon[posDra]){
                sum += knight[posKn];
                posKn++;
                posDra++;
            }else if(knight[posKn]<dragon[posDra]){
                posKn++;
            }
        }
        if(posDra==n) cout<<sum<<"\n";
        else cout<<"Loowater is doomed!\n";
    }
    return 0;
}
