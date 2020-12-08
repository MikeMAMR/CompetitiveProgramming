#include <bits/stdc++.h>

using namespace std;
char s[1000000];
int main(){

    while(true){
        fgets(s, 1000000,stdin);
        string cad="";
        for(int i=0; i<strlen(s); i++){
            if(s[i]!=' ' && s[i]!='.' && s[i]!='?' && s[i]!='!' && s[i]!=','){
                cad+=tolower(s[i]);
            }
        }
        if(cad=="done\n"){
            break;
        }
        int c, l;
        c = l = cad.size()-1;
        if(l%2==0) l /= 2;
        else l = (l/2)+1;
        bool flag = true;
        for(int i=0; i<l; i++){
            if(cad[i]!=cad[c-i-1]){
                flag = false;
                break;
            }
        }
        printf(flag?"You won't be eaten!\n":"Uh oh..\n");
    }
    return 0;
}
