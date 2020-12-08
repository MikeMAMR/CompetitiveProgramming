#include <bits/stdc++.h>
using namespace std;
 map<int, int> mp;
int main(){
    int n, m, a;
    scanf("%d", &n);
    while(n--){
        scanf("%d", &m);
       mp.clear();
        int cant=0, mx=0, num, c=0;
        for(int i=1; i<=m; i++){
            scanf("%d", &a);
            num = mp[a];
            if(num!=0){
                c = max(num, c);
                cant = i-c-1;
            }
            cant++;
            mp[a] = i;
            mx = max(mx, cant);
        }
        printf("%d\n", mx);
    }
    return 0;
}
