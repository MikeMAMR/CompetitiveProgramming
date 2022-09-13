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

int B[MAX], S[MAX];


int main(){
    //std::cin.tie(nullptr);
    //std::ios_base::sync_with_stdio(false);
    int n, m, c=1;
    while(scanf("%d%d", &n, &m) , (n && m)){
        for(int i=0; i<n; i++){
            cin>>B[i];
        }
        for(int i=0; i<m; i++){
            cin>>S[i];
        }
        if(m>=n){
            cout<<"Case "<<c<<": 0\n";
        }
        else{
            sort(B, B+n);
            cout<<"Case "<<c<<": "<<n-m<<" "<<B[0]<<"\n";
        }
        c++;
    }
    return 0;
}
