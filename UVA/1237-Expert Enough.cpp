#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef pair<int, int> pii;
string s[10000];
pii arr[10000];
int main(){
    int cas,a, n, m;
    scanf("%d", &cas);
    while(cas--){
        scanf("%d", &n);
        for(int i=0; i<n; i++){
            cin>>s[i];
            cin>>arr[i].f>>arr[i].s;
        }
        scanf("%d", &m);
        string answer;
        for(int i=0; i<m; i++){
            answer = "UNDETERMINED";
            scanf("%d", &a);
            for(int j=0; j<n; j++){
                if(a>=arr[j].f and a<=arr[j].s){
                    if(answer=="UNDETERMINED"){
                        answer = s[j];
                    }else{
                        answer = "UNDETERMINED";
                        break;
                    }
                }
            }
            cout<<answer<<endl;
        }
        if(cas != 0) cout<<endl;
    }
    return 0;
}
