#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m,  a;
    while(scanf("%d%d", &n, &m), (n || m)){
        int cont = 0;
        multiset<int> cd;
        for(int i=0; i<n; i++){
            scanf("%d", &a);
            cd.insert(a);
        }
        for(int i=0; i<m; i++){
            scanf("%d", &a);
            if(cd.count(a)) cont++;
        }
        cout<<cont<<endl;
    }
    return 0;
}
