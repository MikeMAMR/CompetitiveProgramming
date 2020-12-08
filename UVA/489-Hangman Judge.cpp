#include <bits/stdc++.h>
using namespace std;
bool lowe[100];
bool res[100];
int main(){

    while(true){
        for(int i=0; i<='z'-'a'; i++){
            lowe[i]=false;
            res[i]=false;
        }
        int n;
        string s, s2;
        scanf("%d", &n);
        if(n==-1){
            break;
        }
        cin>>s>>s2;
        int ver=0;
        for(int i=0; i<s.size(); i++){
            if(!lowe[s[i]-'a']) ver++;
            lowe[s[i]-'a'] =true;

        }
        int cont = 0, cont2=0;
        bool flag = true, win = false;
        for(int i=0; i<s2.size(); i++){
            if(!res[s2[i]-'a']){
                //cout<<s2[i]<<endl;
                if(!lowe[s2[i]-'a']){
                    cont++;
                    if(cont == 7){
                        flag=false;
                    }
                }else{
                    ver --;
                    if(ver==0){
                        win  = true;
                        break;
                    }
                }
            }
            res[s2[i]-'a']=true;
        }
       // cout<<cont<<endl;
        printf("Round %d\n", n);
        if(!flag){
            cout<<"You lose."<<endl;
        }else if(win){
            cout<<"You win."<<endl;
        }else{
            bool t = true;
            for(int i=0; i<='z'-'a'; i++){
                if(lowe[i]!=res[i]){
                    t=false;
                }
            }
            printf(t?"You win.\n":"You chickened out.\n");
        }
    }
    return 0;
}
