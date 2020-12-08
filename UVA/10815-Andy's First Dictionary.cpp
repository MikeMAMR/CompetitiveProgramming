#include <bits/stdc++.h>
using namespace std;
set<string> diccionary;
int main(){
    string s;
    while(getline(cin, s)){
        string tmp="";
        for(int i=0; i<s.size(); i++){
            if((s[i]>='a' and s[i]<='z') or (s[i]>='A' and s[i]<='Z') ){
                tmp+=tolower(s[i]);
            }else{
                if(tmp!="") diccionary.insert(tmp);
                tmp="";
            }
            if(i==s.size()-1){
                if(tmp!="") diccionary.insert(tmp);
                tmp="";
            }
        }
    }
    set<string> :: iterator it;
    for(it = diccionary.begin(); it != diccionary.end(); it++){
        cout<<*it<<endl;
    }
    return 0;
}
