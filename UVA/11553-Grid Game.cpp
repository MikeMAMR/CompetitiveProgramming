#include<bits/stdc++.h>
#define DBG(x) cerr << #x << " = " << (x) << endl
using namespace std;
typedef long long ll;
typedef vector<ll> vii;
typedef pair<int, int> pii;
typedef pair<int, string> ps;
long long const MAX = 2e5+10;
int const MAX2 = 2e5;
int const MOD = 10007;//1000000000+7;
const int inf=1e9;

int usd[10];
int arr[10];
int mat[10][10];
int n;
int cont = 0;
int mn = inf;
void solve(int pos){
    if(pos==n){
        cont++;
        int mx = 0;
        for(int i=0; i<n; i++){
            mx += mat[i][arr[i]];
        }
        mn = min(mn, mx);
        return;
    }

    for(int i=0; i<n; i++){
        if(!usd[i]){
           arr[pos] = i;
           usd[i] = 1;
           solve(pos+1);
           usd[i]= 0;
        }
    }
}

int main(){
    //UVA NO
    //std::cin.tie(nullptr);
    //std::ios_base::sync_with_stdio(false);
    int cases;
    cin>>cases;
    while(cases--){
        cin>>n;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin>>mat[i][j];
            }
        }
        mn = inf;
        solve(0);
        cout<<mn<<"\n";
    }


    return 0;
}