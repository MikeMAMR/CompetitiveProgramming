#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    while(cin>>s, s!="#"){
        string tmp = s;
        sort(tmp.begin(), tmp.end());
        next_permutation(s.begin(), s.end());
        if(s==tmp) cout<<"No Successor"<<endl;
        else  cout<<s<<endl;

    }
    return 0;
}
