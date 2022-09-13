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
const int inf=1e9;

int cases, n;
int arr[MAX];

int solve(int p){
    int ant = 0;
    for(int i=0; i<n; i++){
        int tmp = arr[i] - ant;
        if(tmp>p) return -1;
        if(tmp==p) p--;
        ant = arr[i];
    }
    if(p<0) return -1;
    return 1;
}

int main(){
    //std::cin.tie(nullptr);
    //std::ios_base::sync_with_stdio(false);
    int c = 1;
    cin>>cases;
    while(cases--){
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        int ini = 0, fin = inf;
        while(ini<fin){
            int mid = ((ini+fin)/2)+1;
            if(solve(mid)==1){
                fin = mid-1;
            }else{
                ini = mid;
            }
        }
        //if(solve(ini)==-1) ini++;
        cout<<"Case "<<c<<": "<<ini+1<<"\n";
        c++;
    }
    return 0;
}