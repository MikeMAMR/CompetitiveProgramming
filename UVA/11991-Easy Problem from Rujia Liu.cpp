#include <bits/stdc++.h>
using namespace std;
map<int, vector<int>> mp;
int main(){
    int n, m, ele, a, b;
    while(scanf("%d%d", &n, &m) != EOF){
        mp.clear();
        for(int i=0; i<n; i++){
            scanf("%d", &ele);
            mp[ele].push_back(i+1);
        }
        for(int i=0; i<m; i++){
            scanf("%d%d", &a, &b);
            if(a> mp[b].size()){
                printf("0\n");
            }else{
                printf("%d\n", mp[b][a-1]);
            }
        }

    }
    return 0;
}
