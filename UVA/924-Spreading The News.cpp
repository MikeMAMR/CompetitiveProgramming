#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
vector<int> arr[2550];
typedef pair<int, int> pi;
pair<int, int> bfs(int ini){
    bool mark[2550]={0};
    int diam=0;
    int dia[2550]={0};
    queue<pi> q;
    q.push({ini, 0});
    while(!q.empty()){
        pi tmp = q.front();
        mark[tmp.f]=true;
        q.pop();
        int di = tmp.s;
        for(int i=0; i<arr[tmp.f].size(); i++){
            if(!mark[arr[tmp.f][i]]){
                dia[di]++;
                mark[arr[tmp.f][i]]=true;
                q.push({arr[tmp.f][i],di+1 });
                diam=di+1;
            }
        }
    }
    int mx=-2, po=0;
    for(int i=0; i<diam; i++){
        if(dia[i]>mx){
            mx =  dia[i];
            po=i;
        }
    }
    pi f = {mx, po};
    return f;
}
int main(){
    int n, m, a;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &m);
        while(m--){
            scanf("%d", &a);
            arr[i].push_back(a);
        }
    }
    int p;
    scanf("%d", &p);
    while(p--){
        scanf("%d", &a);
        pi s = bfs(a);
        if(s.f==-2){
            cout<<"0"<<endl;
        }else{
            cout<<s.f<<" "<<s.s+1<<endl;
        }
    }


    return 0;
}
