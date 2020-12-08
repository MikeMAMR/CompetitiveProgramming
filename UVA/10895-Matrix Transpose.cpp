#include <bits/stdc++.h>
using namespace std;
struct coord{
    int x, y, val;
};
map<int, vector<coord>> mp;
int main(){
    int n, m;
    coord arr[100000];
    while(scanf("%d%d", &n, &m) != EOF){
        mp.clear();
        int k, a;
        for(int i=1; i<=n; i++){
            scanf("%d", &k);
            for(int j=1;j<=k; j++){
                scanf("%d", &a);
                arr[j].x = i;
                arr[j].y = a;
            }
            for(int j=1;j<=k; j++){
                scanf("%d", &a);
                arr[j].val = a;
                mp[arr[j].y].push_back(arr[j]);
            }
        }
        printf("%d %d\n", m, n);
        for(int i=1; i<=m; i++){
            cout<<mp[i].size();
            if(mp[i].size()==0) cout<<endl;
            else cout<<" ";
            for(int j=0; j<mp[i].size(); j++){
                cout<<mp[i][j].x;
                if(j!=mp[i].size()-1) cout<<" ";
            }
            if(mp[i].size()!=0) cout<<endl;
            for(int j=0; j<mp[i].size(); j++){
                cout<<mp[i][j].val;
                if(j!=mp[i].size()-1) cout<<" ";
            }
            /*while(!mp[i].empty()){
                coord tmp = mp[i].front();
                cout<<tmp.val<<" ";
                mp[i].pop();
            }*/
            cout<<endl;
        }
    }
    return 0;
}
