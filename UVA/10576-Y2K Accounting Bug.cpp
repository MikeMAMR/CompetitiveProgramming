#include <bits/stdc++.h>
using namespace std;
int s, d;
long long arr[100];
long long mx = 0;
void solve(int pos, long long num){
    if(pos==12){
        long long tmp = 0;
        for(int i=(pos-5); i<pos; i++){
            tmp+=arr[i];
        }
        if(tmp<0){
             mx = max(num, mx);
        }

        return;
    }
    if(pos>=5){
        //cout<<pos<<endl;
        long long tmp = 0;
        for(int i=(pos-5); i<pos; i++){
            tmp+=arr[i];
        }
        if(tmp>=0){return;}
    }
    arr[pos] = s;
    solve(pos+1, num+s);
    arr[pos] = -d;
    solve(pos+1, num-d);

}
int main(){
    while(scanf("%d%d", &s, &d) != EOF){
        for(int i=0; i<=12; i++){
            arr[i]=0;
        }
        mx = 0;
        solve(0,0);
        if(mx<=0) cout<<"Deficit"<<endl;
        else cout<<mx<<endl;

    }
    return 0;
}
