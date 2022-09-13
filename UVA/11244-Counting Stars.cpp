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

int mat[200][200];
char s[200][200];
int di[9] = {1,1,0,-1,-1,-1, 0, 1};
int dj[9] = {0,1,1,1 , 0,-1,-1,-1};



int solve(int i, int j){
    if(!mat[i][j]) return 0;

    int ans = mat[i][j];
    mat[i][j] = 0;

    for(int k=0; k<8; k++){
        ans += solve(i+di[k], j+dj[k]);

    }
    return ans;
}

int main(){
    //std::cin.tie(nullptr);
    //std::ios_base::sync_with_stdio(false);
    int n, m;
    while(scanf("%d%d", &n, &m), (n || m)){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                cin>>s[i][j];
                if(s[i][j]=='*') mat[i][j] = 1;
                else mat[i][j] = 0;
            }
        }
        int stars = 0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(mat[i][j]==1){
                    int tmp = solve(i, j);
                    if(tmp == 1) stars++;
                }
            }
        }
        cout<<stars<<"\n";
    }
    return 0;
}