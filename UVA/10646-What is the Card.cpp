#include <bits/stdc++.h>
using namespace std;
bool mark[55];

int main(){
    int n;
    int cases = 0;
    scanf("%d", &n);
    while(n--){
        cases ++;
        string s[56];
        for(int i=0; i<52; i++){
            cin>>s[i];
        }
        int y=0;
        int l = -1;
        int cont = 0;
        for(int i=25; i>=0 && cont<3; i--){
            int x = 0;
            if(s[i][0] >='2' && s[i][0]<='9') x = s[i][0]-'0';
            else x = 10;
            y+=x;
            i -= (10-x);
            cont++;
            l = i;
        }
        cout<<"Case "<<cases<<": ";
        if(y<=l){
            cout<<s[y-1]<<endl;
        }else{
            cout<<s[26+(y-l)-1]<<endl;
        }
    }
    return 0;
}
