#include<bits/stdc++.h>
#define DBG(x) cerr << #x << " = " << (x) << endl
using namespace std;
typedef long long ll;
typedef vector<ll> vii;
typedef pair<int, int> pii;
typedef pair<int, string> ps;
long long const MAX = 1e5+10;
int const MAX2 = 2e5;
int const MOD = 10007;//1000000000+7;
const double inf=1e9;

int n, m, arr[MAX];

int solve(int cap){
    int cnt = 0;
    int c = 0;
    for(int i=0; i<n; i++){
        if(arr[i]>cap) return -1;
        if(c+arr[i]>cap){
            cnt++;
            c = 0;
        }
        c += arr[i];
    }
    if(c!=0){
        cnt++;
    }
    if(cnt==m) return 1;
    else if(cnt<m) return -2;
    else return -1;

}

int main(){
    //std::cin.tie(nullptr);
    //std::ios_base::sync_with_stdio(false);
    while(scanf("%d%d", &n, &m)!=EOF){
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        int ini = 0, fin = inf;
        while(ini<fin){
            int mid = ((ini+fin)/2)+1;
            int q = solve(mid);
            if(q==-1){
                ini = mid;
            }else if(q==-2){
                fin = mid -1;
            }
            else{
                fin = mid -1;
            }
        }
        cout<<ini+1<<"\n";
    }
    return 0;
}
