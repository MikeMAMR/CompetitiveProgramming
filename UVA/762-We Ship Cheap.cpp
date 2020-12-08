#include <bits/stdc++.h>
using namespace std;
struct nodo{
    string city;
    int cont;
    vector<string> visited;
    nodo(string city, int cont){
        this->city = city;
        this->cont = cont;
    }
    nodo(string city, int cont, vector<string> visited){
        this->city = city;
        this->cont = cont;
        this->visited = visited;
    }
};
map<string, vector<string>> mp;
map<string, int> usd;

int main(){
    int n;
    int c =0;
    while(scanf("%d",&n) != EOF){
        if(c!=0) cout<<endl;
        c++;
        usd.clear();
        mp.clear();
        string ini, fin;
        for(int i=0; i<=n; i++){
            cin>>ini>>fin;
            if(i<n){
                mp[ini].push_back(fin);
                mp[fin].push_back(ini);
            }
        }
        queue<nodo> q;
        q.push({ini, 0});
        int mx = 1e9;
        vector<string> nuevos;
        bool f = false;
        while(!q.empty()){
            nodo tmp = q.front();
            q.pop();
            usd[tmp.city] = 1;
            for(int i=0; i<mp[tmp.city].size(); i++){
                if(usd[mp[tmp.city][i]]!=1){
                    usd[mp[tmp.city][i]] = 1;
                    if(mp[tmp.city][i]==fin){
                        tmp.visited.push_back(fin);
                        if(tmp.cont<mx){
                            mx = tmp.cont;
                            nuevos = tmp.visited;
                        }
                        f = true;

                    }else{
                        tmp.visited.push_back(mp[tmp.city][i]);
                        q.push({mp[tmp.city][i], tmp.cont+1, tmp.visited});
                        tmp.visited.pop_back();
                    }

                }

            }
        }
        if(!f) cout<<"No route"<<endl;
        else{
            cout<<ini<< " ";
                    for(int i=0; i<nuevos.size(); i++){
                        if(i==nuevos.size()-1){
                            cout<<nuevos[i]<<endl;
                        }else
                            cout<<nuevos[i]<<endl<<nuevos[i]<<" ";
                    }

        }

    }

    return 0;
}
