#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    bool flag = false;
    while(getline(cin, s)){
       string tmp ="";
       for(int i=0; i<s.size(); i++){
            if(s[i]=='"' and !flag ){
                tmp+="``";
                flag = true;
            }else if(s[i]=='"' and flag){
                tmp+="''";
                flag = false;
            }else{
                tmp+=s[i];
            }
       }
       cout<<tmp<<endl;
    }
    return 0;
}
