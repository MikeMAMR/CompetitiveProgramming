#include <bits/stdc++.h>
using namespace std;
bool isPal(string s){
    for(int i=0; i<s.size(); i++){
        if(s[i]!=s[s.size()-i-1]){
            return false;
        }
    }
    return true;
}
int main(){
    int n;
    cin>>n;
    cin.ignore();
    string s;
    int cases=0;
    while(n--){
        cases++;
        getline(cin, s);
        string tmp="";
        for(int i=0; i<s.size(); i++){
            if(s[i]>='a' && s[i]<='z') tmp+=s[i];
        }
        int sq = sqrt(tmp.size());
        char mat[sq+1][sq+1];
        int ind=0;
        for(int i=0; i<sq; i++){
            for(int j=0; j<sq; j++){
                mat[i][j] = tmp[ind++];
            }
        }
        string c2="";
        for(int i=0; i<sq; i++){
            for(int j=0; j<sq; j++){
                c2+= mat[j][i];
            }
        }
        if(sq*sq!=tmp.size() || !isPal(tmp) || !isPal(c2)){
            cout<<"Case #"<<cases<<":"<<endl<<"No magic :("<<endl;
        }else{
             cout<<"Case #"<<cases<<":"<<endl<<sq<<endl;
        }

    }
    return 0;
}
