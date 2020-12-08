#include <bits/stdc++.h>
#include <string.h>
using namespace std;
char mirror[100];
bool Pmirror[100];
bool Nflag;
bool flagM;
bool flagR;
int main(){
    mirror['E'] = '3';
    mirror['3'] = 'E';
    mirror['J'] = 'L';
    mirror['L'] = 'J';
    mirror['S'] = '2';
    mirror['2'] = 'S';
    mirror['5'] = 'Z';
    mirror['Z'] = '5';

    Pmirror['A'] = true;
    Pmirror['H'] = true;
    Pmirror['I'] = true;
    Pmirror['M'] = true;
    Pmirror['O'] = true;
    Pmirror['T'] = true;
    Pmirror['U'] = true;
    Pmirror['V'] = true;
    Pmirror['W'] = true;
    Pmirror['X'] = true;
    Pmirror['Y'] = true;
    Pmirror['1'] = true;
    Pmirror['8'] = true;

    char s[100000];
    while(scanf("%s", s) != EOF){
        int p =0;
        int n =strlen(s);
        p = n/2 ;
        int cont=0, cont2=0;
        if(n%2!=0) p++;
        for(int i=0; i<p; i++){
            if(s[i]==s[n-1-i]){
                if(Pmirror[s[i]]){
                    flagM=true; //mirror
                    cont2++;
                }
                cont++;
            }else{
                //cout<<mirror[mirror[s[i]]]<<" "<<s[i]<<endl;
                if(mirror[mirror[s[i]]]==s[i]){

                    flagR=true; // espejo
                }else{
                    Nflag=true; // no es
                }
            }
        }
        cout<<flagR<<Nflag<<flagM<<endl;

        if(!Nflag && !flagR && cont==p && cont2==p){
            cout<<s<<" -- is a mirrored palindrome."<<endl;
        }else if(!Nflag && cont==p && cont2!=p){
            cout<<s<<" -- is a regular palindrome."<<endl;
        }else if(!Nflag && flagR){
            cout<<s<<" -- is a mirrored string."<<endl;
        }else if(Nflag){
            cout<<s<<" -- is not a palindrome."<<endl;
        }
    }
    return 0;
}
