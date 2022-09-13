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

string cad[20];
map<int, string> mp;
bool ans;
int n;
void solve(string error, int pos, int num){
    if(pos==(n)){
        ans = true;
        return;
    }
    string tmp = mp[num];
    string def = cad[pos];
    //getchar();
    //cout<<mp[num]<<" - "<<cad[pos]<<" - "<<error<<"\n";
    bool f = true;
    for(int i=0; i<7;  i++){
        if(tmp[i]!=def[i]){
            if(tmp[i]=='N' && def[i]=='Y'){
                f = false;
            }else{
                error[i] = '1';
            }
        }
        if(error[i]=='1' && def[i]=='Y'){
            f =false;
        }
    }
    if(!f) return;
    solve(error, pos+1, num-1);
}

void llenar(){
    mp[0] = "YYYYYYN";
    mp[1] = "NYYNNNN";
    mp[2] = "YYNYYNY";
    mp[3] = "YYYYNNY";
    mp[4] = "NYYNNYY";
    mp[5] = "YNYYNYY";
    mp[6] = "YNYYYYY";
    mp[7] = "YYYNNNN";
    mp[8] = "YYYYYYY";
    mp[9] = "YYYYNYY";
}

int main(){
    //UVA NO
    //std::cin.tie(nullptr);
    //std::ios_base::sync_with_stdio(false);
    llenar();
    while(scanf("%d",&n), n){
        for(int i=0; i<n; i++){
            cin>>cad[i];
        }
        ans = false;
        for(int i=9; i>=n-1; i--){
            solve("0000000", 0, i);
        }
        if(ans) cout<<"MATCH\n";
        else cout<<"MISMATCH\n";
    }

    return 0;
}
