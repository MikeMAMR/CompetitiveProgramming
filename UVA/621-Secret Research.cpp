#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    string s;
    scanf("%d", &n);
    while(n--){
        cin>>s;
        if(s=="1" or s=="4" or s=="78"){
            cout<<"+"<<endl;
        }else if(s[s.size()-2]=='3' and s[s.size()-1]=='5'){
            cout<<"-"<<endl;
        }else if(s[0]=='9' and s[s.size()-1]=='4'){
            cout<<"*"<<endl;
        }else if(s[0]=='1' and s[1]=='9' and s[2]=='0'){
            cout<<"?"<<endl;
        }else{
            cout<<"?"<<endl;
        }
    }

	return 0;
}
