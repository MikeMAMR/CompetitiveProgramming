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

int n, m;
char mat[200][200];
int usd[200][200];

int di[6] = {1,-1,0,0};
int dj[6] = {0,0,1,-1};

int rec, no;

int solve(int i, int j){
    if(!usd[i][j]) return 0;

    int ans = usd[i][j];
    usd[i][j] = 0;

    for(int k=0; k<4; k++){
        if(j+dj[k]==m+1){
            ans += solve(i+di[k], 1);
        }else if(j+dj[k]==0){
            ans += solve(i+di[k], m);
        }else ans += solve(i+di[k], j+dj[k]);

    }

    return ans;
}

int main(){
    //std::cin.tie(nullptr);
    //std::ios_base::sync_with_stdio(false);
    int a, b;
    char h, k;
    while(scanf("%d%d", &n, &m) != EOF ){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                cin>>mat[i][j];
            }
        }
        h = mat[1][1];

        cin>> a>> b;
        a += 1;
        b += 1;
        if(mat[a][b]==h){
            for(int i=1; i<=n; i++){
                for(int j=1; j<=m; j++){
                    if(mat[i][j]==h) usd[i][j] = 1;
                    else usd[i][j] = 0;
                }
            }
        }else{
            for(int i=1; i<=n; i++){
                for(int j=1; j<=m; j++){
                    if(mat[i][j]==mat[a][b]) usd[i][j] = 1;
                    else usd[i][j] = 0;
                }
            }
        }
        int ans = 0;
        int l = solve(a, b);
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(usd[i][j]==1){
                    int tmp = solve(i, j);
                    ans = max(tmp, ans);

                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}