#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vii;
typedef pair<int, int> pii;
long long const MAX = 1e5+10;
int const MAX2 = 500;
int const MOD = 1000000000+7;
const int inf=1e9;


int main(){
    //std::cin.tie(nullptr);
    //std::ios_base::sync_with_stdio(false);
    int n;
    while(scanf("%d", &n) != EOF){
        int arr[5], tmp = n;
        for(int i=0; i<4; i++){
            arr[i] = n&255;
            n = n>>8;
        }
        int ans = 0;
        for(int i=0; i<4; i++){
            ans = ans << 8;
            ans |= arr[i];
        }
        printf("%d converts to %d\n", tmp, ans);
    }
    return 0;
}
