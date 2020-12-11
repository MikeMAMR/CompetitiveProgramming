#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ii;
int n;
string str;
char mat[20][20];
int usd[20][20];
int mx = 0;
map<char, vector<ii>> mp;
void solve(int x, int y, int pos){
    //cout<<mat[x][y]<<endl;
    if(usd[x][y]==1) return;
    if(x<0 or y<0 or x>=4 or y>=4 or
       usd[x][y]==1 or mat[x][y]!=str[pos]
       or pos==n){
        int pas = 0;
        if(pos==3 or pos==4) pas=1;
        else if(pos==5) pas=2;
        else if(pos==6) pas=3;
        else if(pos==7) pas=5;
        else if(pos>=8) pas=11;

        mx = max(mx, pas);
        return;
    }
    usd[x][y]=1;
    solve(x, y+1, pos+1);
    solve(x, y-1, pos+1);
    solve(x+1, y, pos+1);
    solve(x-1, y, pos+1);
    solve(x+1, y+1, pos+1);
    solve(x-1, y+1, pos+1);
    solve(x+1, y-1, pos+1);
    solve(x-1, y-1, pos+1);
    usd[x][y]=0;
}
int main(){
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            scanf(" %c", &mat[i][j]);
            mp[mat[i][j]].push_back({i,j});
        }
    }
    int cas;
    int suma = 0;
    scanf("%d", &cas);
    for(int i=0; i<cas; i++){
        cin>>str;
        n = str.size();
        int mm = 0;
        for(int j=0; j<mp[str[0]].size(); j++){
            mx = 0;
            solve(mp[str[0]][j].first,mp[str[0]][j].second,0);
            mm = max(mm, mx);
        }
        suma+=mm;

    }
    cout<<suma<<endl;
    return 0;
}
