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

int n;
char mat[200][200];
int usd[200][200];

int di[6] = {1,1,0,0};
int dj[6] = {0,0,1,1};

int rec, no;

void solve(int i, int j){

    if(!usd[i][j]) return;
    rec++;
    if(mat[i][j]=='@') no++;

    usd[i][j] = 0;
    for(int k=0; k<4; k++){
        solve(i+di[k], j+dj[k]);
    }
}

int main(){
    //std::cin.tie(nullptr);
    //std::ios_base::sync_with_stdio(false);
    int cases, k=0;
    cin>> cases;
    while(cases--){
        cin>>n;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                cin>>mat[i][j];
                if(mat[i][j]=='x' || mat[i][j]=='@') usd[i][j] = 1;
                else usd[i][j] = 0;
            }
        }
        int ans = 0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(usd[i][j]){
                    rec = 0;
                    no = 0;
                    solve(i, j);
                    if(rec!=no) ans++;
                }
            }
        }
        k++;
        cout<<"Case "<<k<<": "<<ans<<"\n";

    }
    return 0;
}