#include <bits/stdc++.h>
using namespace std;
typedef pair<string, int> pp;

int check(string a, string b){
    int cont=0;
    for(int i=0; i<a.size(); i++){
        if(a[i]!=b[i]){
            cont++;
        }
    }
    return cont;
}
int main() {
    int n;
    scanf("%d", &n);
    while(n--){
        int ind = 0;
        string cadenas[250];
        string tmp="";
        map<string, int> mp;
        while(cin>>tmp, tmp!="*"){
            cadenas[ind++] = tmp;
            mp[tmp] = 0;
        }
    string cad;
    cin.ignore();
    while(getline(cin, cad) && cad!=""){
        string a, b;
        a = cad.substr(0, cad.size()/2);
        b = cad.substr((cad.size()/2)+1, cad.size());
        bool f = false;
        if(a==b) {
                cout<<a<<" "<<b<<" 0"<<endl;
            f = true;
        }
        //cout<<a<<endl<<b<<endl;
            queue<pair<string, int>> q;
            q.push({a, 0});
            int valor = 1e9;
            while(!q.empty() && !f){

               pp act = q.front();
            //cout<<act.first<<endl;
               mp[act.first] = 1;
               q.pop();
               int v = act.second;
               for(int i=0; i<ind; i++){
                    //cout<<cadenas[i]<<endl;
                    if(mp[cadenas[i]]==0 && cadenas[i].size()==act.first.size()){
                        if(check(act.first, cadenas[i])==1){
                            //cout<<cadenas[i]<<endl;
                            if(cadenas[i]==b){
                                if(v+1<valor) valor = v+1;
                            }else{
                                q.push({cadenas[i], v+1});
                                mp[cadenas[i]] = 1;
                            }
                        }
                    }
               }
            }
            for(int i=0; i<ind; i++){
                 mp[cadenas[i]] = 0;
            }
            if(!f) cout<<a<<" "<<b<<" "<<valor<<endl;
        }
        if(n!=0) cout<<endl;

    }
    return 0;
}
