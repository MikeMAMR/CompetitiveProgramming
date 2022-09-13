//MIKE
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vii;
long long const MAX = 1e5+10;
int const MAX2 = 3e5+50;
int const MOD = 1000000000+7;
const int inf=1e9;
vii p, rank1;
void unionFind(int n){
    rank1.assign(n, 0);
    p.assign(n,0);
    for(int i=0; i<n; i++) p[i] = i;
}
int findSet(int i){
    return (p[i]==i) ? i : (p[i] = findSet(p[i]));
}

bool isSameSet(int i, int j){
    return findSet(i) == findSet(j);
}
void unionSet(int i, int j){
    if(!isSameSet(i, j)){
        int x = findSet(i), y= findSet(j);
        if(rank1[x] > rank1[j]) p[y] = x;
        else{
            p[x] = y;
            if(rank1[x]==rank1[y]) rank1[y]++;
        }
    }
}

int main(){
    //std::cin.tie(nullptr);
    //std::ios_base::sync_with_stdio(false);
    int n, m;
    while(scanf("%d%d", &n,&m), (n || m)){
        int k, arr[MAX2];
        unionFind(n+1);
        while(m--){
            cin>> k;
            for(int i=0; i<k;i++){
                cin>> arr[i];
                if(i!=0){
                    unionSet(arr[0], arr[i]);
                }
            }
        }
        int cont = 0;
        for(int i=0; i<n; i++){
            if(isSameSet(0, i)) cont++;
        }
        cout<<cont<<"\n";
    }
    return 0;
}