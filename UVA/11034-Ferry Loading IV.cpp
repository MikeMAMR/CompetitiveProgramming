#include <bits/stdc++.h>
using namespace std;

int main(){
    int cases;
    scanf("%d", &cases);
    while(cases--){
        int n, m, a;
        string place;
        queue<int> l, r;
        scanf("%d%d", &n, &m);
        n *= 100;
        for(int i=0; i<m; i++){
            scanf("%d", &a);
            cin>> place;
            if(place=="left") l.push(a);
            else r.push(a);
        }
        int cont = 0, carga = 0;
        while(true){

            while(!l.empty()){
                carga += l.front();
                if(carga > n){
                    carga -= l.front();
                    break;
                }else{
                    l.pop();
                }
            }
            cont++;
            carga = 0;
            if(r.empty() and l.empty() ) break;
            while(!r.empty()){
                carga += r.front();
                if(carga > n){
                    carga -= r.front();
                    break;
                }else{
                    r.pop();
                }
            }
            cont++;
            carga = 0;
            if(r.empty() and l.empty() ) break;
            /*cout<<l.empty()<<" ";
            cout<<r.empty()<<endl;*/
        }
        cout<<cont<<endl;
    }
    return 0;
}
