#include <bits/stdc++.h>
using namespace std;
map<int, vector<int>> mp;
bitset<30> bs;
void solve(int ini){
    queue<int> p;
    p.push(ini);
    while(!p.empty()){
        int tmp = p.front();
        p.pop();
        bs.set(tmp, 0);
        for(int i=0; i<mp[tmp].size(); i++){
            if(bs[mp[tmp][i]]==1){
                p.push(mp[tmp][i]);
                bs.set(mp[tmp][i], 0);
            }
        }
    }

}

int main(){
    int cases;
    scanf("%d", &cases);
    while(cases--){
        bs.reset();
        mp.clear();
        int a, b;
        char s[10000], s2[60];
        int acorn = 0, trees = 0;
        while(scanf("%s", s)){
            if(s[0]=='*') break;
            a = s[1]- 'A';
            b = s[3] - 'A';
            mp[a].push_back(b);
            mp[b].push_back(a);
            bs.set(a, 1);
            bs.set(b, 1);
        }
        scanf("%s", s2);
        for(int i=0; i<strlen(s2); i+=2){
            if(bs[s2[i]-'A']==0){
                acorn++;
            }
        }
        for(int i=0; i<strlen(s2); i+=2){
            if(bs[s2[i]-'A']==1){
                trees ++;
                solve(s2[i]-'A');
            }
        }
        //cout<<bs<<endl;
        printf("There are %d tree(s) and %d acorn(s).\n", trees, acorn);
        //cout<<trees<<" "<<acorn<<endl;

    }
    return 0;
}
