#include <bits/stdc++.h>
using namespace std;
long long vec[100000];
int main(){
    long long n;
    int id=0;
    while(scanf("%lld", &n) != EOF){
        vec[id] = n;
        id++;
       // cout<<lengh<<endl;

        sort(vec, vec+id);
       // cout<<vec[lengh-1]<<endl;
        if(id%2==0){
            cout<<(vec[id/2]+vec[(id/2)-1])/2<<endl;
        }else{
            cout<<vec[id/2]<<endl;
        }
    }
    return 0;
}
