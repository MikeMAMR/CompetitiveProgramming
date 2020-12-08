#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef pair<int, int> pii;
pii one[10000], three[10000];
char s[1000][1000];
int main(){
    int n, a, b, in1=0, in3=0;
    while(scanf("%d", &n) != EOF){
        in1 = in3 = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                scanf(" %c", &s[i][j]);
                if(s[i][j]=='1') one[in1++] ={i,j};
                if(s[i][j]=='3') three[in3++] = {i,j};
            }
        }
        int mi = -1, mx = 1e9;
        for(int i=0; i<in1; i++){
            for(int j=0; j<in3; j++){
                mx = min (mx, abs(one[i].f-three[j].f) + abs(one[i].s - three[j].s));
            }
            mi = max(mx, mi);
            mx = 1e9;
        }
        cout<<mi<<endl;
    }
    return 0;
}
