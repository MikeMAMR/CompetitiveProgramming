#include<bits/stdc++.h>
#define DBG(x) cerr << #x << " = " << (x) << endl
using namespace std;
typedef long long ll;
typedef vector<ll> vii;
typedef pair<int, int> pii;
typedef pair<int, string> ps;
long long const MAX =  1e4+10;
int const MAX2 = 1001;
int const MOD = 10007;//1000000000+7;
const int inf=1e9;


int main(){
    //std::cin.tie(nullptr);
    //std::ios_base::sync_with_stdio(false);
    int n, m;
    ll arr[MAX2];
    cin>>n;
    while(n--){
        cin>>m;
        for(int i=0; i<m; i++){
            cin>>arr[i];
        }
        int cont = 1, cant = arr[0];
        for(int i=1; i<m-1; i++){
            if(arr[i]+cant<arr[i+1]){
                cont++;
                cant += arr[i];
            }
        }
        cout<<cont+1<<"\n";
    }

    return 0;
}