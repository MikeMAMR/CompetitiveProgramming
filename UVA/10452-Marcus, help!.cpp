#include <bits/stdc++.h>
using namespace std;
char mat[100][100];
string god = "IEHOVA";
int n, m;
int x, y;
vector<string> vec;
bool flag=false;
void solve(int x, int y, int pos){
   // cout<<"t= "<<god[pos]<<endl;
    if(mat[x][y]=='#'){
        if(vec.size()==7){
            flag = true;
            for(int i=0; i<vec.size()-1; i++){
                cout<<vec[i]<<" ";
            }
            cout<<vec[vec.size()-1];

        }
        return;
    }
    if(flag) return;
    if(mat[x-1][y]==god[pos] or mat[x-1][y]=='#'){
        vec.push_back("forth");
        solve(x-1, y, pos+1);
        vec.pop_back();
    }
    if(mat[x][y-1]==god[pos] or mat[x][y-1]=='#'){
       vec.push_back("left");
        solve(x, y-1, pos+1);
        vec.pop_back();
    }
    if(mat[x][y+1]==god[pos] or mat[x][y+1]=='#'){
        vec.push_back("right");
        solve(x, y+1, pos+1);
        vec.pop_back();
    }
}
int main(){
    int cas;
    scanf("%d", &cas);
    while(cas--){
        scanf("%d%d", &n,&m);
        for(int i=0; i<n ; i++){
            for(int j=0; j<m; j++){
                scanf(" %c", &mat[i][j]);
                if(mat[i][j]=='@'){
                    x = i; y = j;
                }
            }
        }
        flag=false;
        solve(x, y, 0);
        printf("\n");
    }

    return 0;
}
