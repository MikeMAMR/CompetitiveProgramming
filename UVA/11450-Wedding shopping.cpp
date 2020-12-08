#include <bits/stdc++.h>
using namespace std;
int dp[30][400];
vector<int> prendas[30];
const int inf = 1e9;
int cPrenda;
int pres;
int buy(int pos, int dinero){
    if(dinero<0){
        return -inf;
    }
    if(pos==cPrenda){

        return pres-dinero;
    }
    if(dp[pos][dinero]!=-1){
        return dp[pos][dinero];
    }
    int res = -inf;
    for(int precio:prendas[pos]){
        res = max(res, buy(pos+1, dinero-precio));
    }
    dp[pos][dinero]=res;
    return dp[pos][dinero];
    //return res;
}
int main(){
    int h;
    scanf("%d", &h);
    while(h--){
        scanf("%d%d", &pres, &cPrenda);
        for(int i=0; i<30; i++){
            for(int j=0; j<250; j++){
                dp[i][j]=-1;
            }
        }
        for(int i=0; i<cPrenda; i++){
            int k, g;
            scanf("%d", &k);
            for(int j=0; j<k; j++){
                scanf("%d", &g);
                prendas[i].push_back(g);
            }
        }
        int total = buy(0, pres);
        if(total==-inf){
            cout<<"no solution"<<endl;
        }else
            cout<<total<<endl;

        for(int i=0; i<cPrenda; i++){
            prendas[i].clear();
        }
    }
    return 0;
}
