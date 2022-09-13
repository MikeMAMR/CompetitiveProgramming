#include<bits/stdc++.h>
#define DBG(x) cerr << #x << " = " << (x) << endl
using namespace std;
typedef long long ll;
typedef vector<int> vii;
typedef pair<int, int> pii;
typedef pair<int, string> ps;
long long const MAX =  1e3;
int const MAX2 = 1e5+10;
int const MOD = 1000000000+7;
const int inf=1e9;
const double PI = acos(-1.0);

int dj[6] = {0, 1, 0, -1};
int di[6] = {-1, 0, 1, 0};


int main(){
    //std::cin.tie(nullptr);
    //std::ios_base::sync_with_stdio(false);
    int n, m, s;
    char mat[200][200];
    string ins;
    while(scanf("%d%d%d", &n, &m, &s), (n || m || s)){
        int mark[200][200];
        char dir;
        int x, y;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                cin>>mat[i][j];
                if(mat[i][j]!='*' && mat[i][j]!='.' && mat[i][j]!='#'){
                    dir = mat[i][j];
                    x = i;
                    y = j;
                    if(mat[i][j]=='L') dir = 'E';
                }
            }
        }
        cin>>ins;
        int ans = 0;
        for(int i=0; i<ins.size(); i++){

            if(ins[i]=='F'){
                if(dir == 'N'){
                    if(x+di[0]>=1 && x+di[0]<=n && y+dj[0]>=1 && y+dj[0]<=m && mat[x+di[0]][y+dj[0]]!='#'){
                        x += di[0];
                        y += dj[0];
                    }
                }
                else if(dir == 'E'){
                    if(x+di[1]>=1 && x+di[1]<=n && y+dj[1]>=1 && y+dj[1]<=m && mat[x+di[1]][y+dj[1]]!='#'){
                        x += di[1];
                        y += dj[1];
                    }
                }
                else if(dir == 'S'){
                    if(x+di[2]>=1 && x+di[2]<=n && y+dj[2]>=1 && y+dj[2]<=m && mat[x+di[2]][y+dj[2]]!='#'){
                        x += di[2];
                        y += dj[2];
                    }
                }
                else if(dir == 'O'){
                    if(x+di[3]>=1 && x+di[3]<=n && y+dj[3]>=1 && y+dj[3]<=m && mat[x+di[3]][y+dj[3]]!='#'){
                        x += di[3];
                        y += dj[3];
                    }
                }

            }else if(ins[i]=='E'){
                if(dir == 'N') dir = 'O';
                else if(dir == 'O') dir = 'S';
                else if(dir == 'S') dir = 'E';
                else if(dir == 'E') dir = 'N';
            }else if(ins[i]=='D'){
                if(dir == 'N') dir = 'E';
                else if(dir == 'E') dir = 'S';
                else if(dir == 'S') dir = 'O';
                else if(dir == 'O') dir = 'N';
            }
            if(mat[x][y]=='*'){
                ans++;
                mat[x][y] = '.';
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
