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

struct stone{
    char s;
    int n;
};

vii ini, fin;
vector<stone> q;
ll mx = 0;
int cases, k=0;
ll a, b, n;
char s;

void solve(){
    for(int i=0; i<ini.size()-1; i++){
        mx = max(mx, ini[i+1]-ini[i]);
    }
    sort(fin.begin(), fin.end(), greater<ll>());
    for(int i=0; i<fin.size()-1; i++){
        mx = max(mx, fin[i]-fin[i+1]);
    }
}

int main(){
    //std::cin.tie(nullptr);
    //std::ios_base::sync_with_stdio(false);

    scanf("%d", &cases);
    while(cases--){
        ini.clear();
        fin.clear();
        mx = 0;
        scanf("%lld %lld",&a,&b);
        int pos =0;
        ini.push_back(0);
        fin.push_back(0);
        for(int i=0; i<a; i++){
            scanf(" %c-%lld",&s,&n);
            if(s=='B'){
                ini.push_back(n);
                fin.push_back(n);
                pos = 0;
            }else{
                pos++;
                if(pos%2!=0) ini.push_back(n);
                else fin.push_back(n);
            }
        }
        ini.push_back(b);
        fin.push_back(b);
        solve();
        k++;
        printf("Case %d: %d\n", k, mx);
    }
    return 0;
}
