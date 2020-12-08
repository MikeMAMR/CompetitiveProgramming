#include <bits/stdc++.h>
using namespace std;
map<string, int> mp1;
map<string, string> mp2;
vector<string > g;
int main(){
    string s, arr[10000];
    while(true){
        cin>>s;
        if(s=="#"){
            break;
        }
        string tmp=s;
        for(int i=0; i<s.size(); i++){
            s[i] = tolower(s[i]);
        }
        sort(s.begin(), s.end());
        if(mp1[s]==0){
            g.push_back(s);
        }
        mp2[s] = tmp;
        mp1[s]++;
    }
    int c=0;
    for(int i=0; i<g.size(); i++){
        if(mp1[g[i]]==1){
            arr[c]=mp2[g[i]];
            c++;
        }
    }
    sort(arr, arr+c);
    for(int i=0; i<c; i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}
