#include <bits/stdc++.h>
using namespace std;
map<char, double> q;
int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        int m, a, cont=0;
        string cad;
        char s;
        double sum=0.0;
        scanf("%d", &m);
        while(m--){
            cin>>s>>a;
            q[s] = a;
        }
        scanf("%d", &m);
        cin.ignore();
        while(m--){
            getline(cin, cad);
            for(int i=0; i<cad.size(); i++){
                sum+= q[cad[i]];
            }
        }
        double res = sum / 100.00;
        printf("%0.2lf$\n", res);
        q.clear();
    }
    return 0;
}

