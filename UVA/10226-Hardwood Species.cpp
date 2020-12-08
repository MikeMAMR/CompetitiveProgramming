#include<bits/stdc++.h>
using namespace std;
map<string, double>mp;
int main(){
    int cas;
    scanf("%d\n\n", &cas);
    while(cas--){
        string cad;
        string pal[10000];
        int ind=0;
        double total=0;
        while(getline(cin, cad)){
            if(cad=="") break;
            if(mp[cad]==0){
                mp[cad]=1;
                 pal[ind++]=cad;
            }else{
               mp[cad]=mp[cad]+1;
            }
            total++;
        }
        sort(pal, pal+ind);
        double p = 0.0;
        for(int i=0; i<ind; i++){
            p = (mp[pal[i]]*100.00)/total;
            mp[pal[i]]=0;
            cout<<pal[i]<<" "<<fixed<<setprecision(4)<<p<<endl;
        }
        if(cas>0){
            cout<<endl;
            mp.clear();
        }
    }
    return 0;
}
