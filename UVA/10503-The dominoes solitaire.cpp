#include <bits/stdc++.h>
using namespace std;
bool mark[100];
int arr[100];
struct domino{
    int x, y;
};
domino doom[100];
domino ini, fin;
int n, m;
bool flag;

void solve(int pos, int num){
    if(pos==n){
        bool f = true;
        if(num!=fin.x) f = false;
        if(f) flag = true;
        return;
    }
    if(flag) return;
    for(int i=0; i<m; i++){
        if(!mark[i]){
            if(doom[i].x==num || doom[i].y==num){
                mark[i]=1;
                if(doom[i].x==num){
                    solve(pos+1, doom[i].y);
                }else solve(pos+1, doom[i].x);

                mark[i] = 0;
            }
        }
    }
    //cout<<endl;

}

int main(){
    while(scanf("%d", &n), n){
        scanf("%d", &m);
        scanf("%d%d", &ini.x, &ini.y);
        scanf("%d%d", &fin.x, &fin.y);
        for(int i=0; i<m; i++){
            scanf("%d%d", &doom[i].x, &doom[i].y);
        }
        flag = false;
        solve(0, ini.y);
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
