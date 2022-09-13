//MIKE
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
long long const MAX = 50000;
int const MAX2 = 1e9;
int const MOD = 1000000000+7;
const int inf=1e9;
map<string, int> mp;
vector<int> p, rank1;
void unionFind(int n){
    rank1.assign(n, 0);
    p.assign(n, 0);
    for(int i=0; i<n; i++) p[i] = i;
}
int findSet(int i){
    return (p[i]==i) ? i : (p[i] = findSet(p[i]));
}
bool isSameSet(int i, int j){
    return findSet(i)==findSet(j);
}

void unionSet(int i, int j){
    if(!isSameSet(i, j)){
        int x = findSet(i), y = findSet(j);
        if(rank1[x] > rank1[y]) p[y] = x;
        else{
            p[x] = y;
            if(rank1[x] == rank1[y]) rank1[y]++;
        }
    }
}

int main(){
    //std::cin.tie(nullptr);
    //std::ios_base::sync_with_stdio(false);
    string arr[MAX];
    int n, m;
    while(scanf("%d%d", &n,&m), (n || m)){
        unionFind(n);
        mp.clear();
        for(int i=0; i<n; i++){
            cin>>arr[i];
            mp[arr[i]] = i;
        }
        string a, b;
        while(m--){
            cin>>a>>b;
            unionSet(mp[a], mp[b]);
        }
        vector<int> cubeta;
        cubeta.assign(n, 0);
        int mx = 0;
        for(int i=0; i<n; i++){
            int tmp = findSet(i);
            cubeta[tmp] ++;
            mx = max(mx, cubeta[tmp]);
        }
        cout<<mx<<"\n";
    }

    return 0;
}
