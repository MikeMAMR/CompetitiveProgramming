#include<bits/stdc++.h>
#define DBG(x) cerr << #x << " = " << (x) << endl
using namespace std;
typedef long long ll;
typedef vector<int> vii;
typedef pair<int, int> pii;
typedef pair<int, string> ps;
long long const MAX =  2e4+100;
int const MAX2 = 1e9;
int const MOD = 1000000000+7;
const int inf=1e9;
const double PI = acos(-1.0);

int arr[MAX];

int bs(int x, int y, int num){
   int ini = x, fin = y;
   while(ini<fin){
        int mid = ((ini+fin)/2)+1;
        //DBG(mid);
        if(arr[mid]>num){
            fin = mid-1;
        }else{
            ini = mid;
        }
   }
   return ini;

}

map<int, int> mp;

int main(){
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    int n, m;
    int cases = 1;
    while(scanf("%d%d", &n, &m) && (n, m)){
        for(int i=0; i<n; i++){
            scanf("%d", &arr[i]);
        }
        sort(arr, arr+n);
        mp.clear();
        for(int i=0; i<n; i++){
            if(mp[arr[i]]==0){
                mp[arr[i]] = i+1;
            }
        }
        printf("CASE# %d:\n", cases);
        cases++;
        for(int a, i=0; i<m; i++){
            scanf("%d", &a);
            //int ans = bs(0, n-1, a);
            if(mp[a]!=0){
                printf("%d found at %d\n", a, mp[a]);
            }else{
                printf("%d not found\n", a);
            }
        }

    }
    return 0;
}
