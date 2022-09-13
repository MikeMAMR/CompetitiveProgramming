#include<bits/stdc++.h>
#define DBG(x) cerr << #x << " = " << (x) << endl
using namespace std;
typedef long long ll;
typedef vector<int> vii;
typedef pair<int, int> pii;
typedef pair<int, string> ps;
long long const MAX =  5e4+100;
int const MAX2 = 1e9;
int const MOD = 1000000000+7;
const int inf=1e9;
const double PI = acos(-1.0);

ll arr[MAX];


int bs(int n, ll num){
    int ini = 0, fin = n-1;
    while(ini<fin){
        int mid = ((ini+fin)/2)+1;
        if(arr[mid]>num){
            fin = mid - 1;
        }else{
            ini = mid;
        }
    }
    return ini;

}
//menor
map<long long, int> mp;
int main(){
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    int n, m;
    ll tmp;
    int j = 0;
    while(scanf("%d", &n) != EOF){
        for(int i=0; i<n; i++){
            scanf("%lld", &tmp);
            if(mp[tmp]!=1){
                arr[j++] = tmp;
                mp[tmp] = 1;
            }
        }
        scanf("%d", &m);
        ll p;
        for(int i=0; i<m; i++){
            scanf("%lld", &p);
            int pos = bs(j, p);
            //DBG(pos);
            if(arr[pos] == p){
                if(pos==0){
                    printf("X ");
                }else{
                    printf("%d ", arr[pos-1]);
                }
                if(pos==j-1){
                    printf("X\n");
                }else{
                    printf("%d\n", arr[pos+1]);
                }
            }else{
                if(arr[pos]<p){
                    printf("%d ", arr[pos]);
                }else if(pos==0){
                    printf("X ");
                }else{
                    printf("%d ", arr[pos-1]);
                }
                if(arr[pos]>p){
                    printf("%d\n", arr[pos]);
                }else if(pos==j-1){
                    printf("X\n");
                }else{
                    printf("%d\n", arr[pos+1]);
                }

            }
        }
    }
    return 0;
}
