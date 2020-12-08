#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(scanf("%d", &n) , (n)){
        map<string, int> mp;
        int cont=0, mx=1;
        string arr[6];
        string s="";
        for(int j=0; j<n; j++){
            for(int i=0; i<5; i++){
                cin>>arr[i];
            }
            sort(arr, arr+5);
            for(int i=0; i<5; i++){
                s+=arr[i];
            }
            if(mp[s]==0){
                mp[s]=1;
            }else{
                mp[s]++;
            }
            if(mp[s]>mx) mx = mp[s];
            s="";

        }
        map<string, int> :: iterator it;
        for(it=mp.begin(); it!=mp.end(); it++){
            if((it->second)==mx){
                cont+= mx;
                //cout<<"mx "<<mx<<endl;
            }
            //cout<<it->second<<endl;
        }
        cout<<cont<<endl;
    }
}
