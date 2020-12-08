#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, a, b;
    bool bpq = true, bq = true, bs=true, imposible=false;
    while(scanf("%d", &n) != EOF){
        int tmppq, tmpq, tmps;
        bpq = bq = bs = true;
        imposible = false;
        priority_queue<int> pq;
        queue<int> q;
        stack<int> s;
        while(n--){
            scanf("%d%d", &a, &b);
            if(a==1){
                pq.push(b);
                q.push(b);
                s.push(b);
            }else{
                if(!q.empty()){
                    tmppq = pq.top();
                    tmpq = q.front();
                    tmps = s.top();
                    if(tmppq != b) bpq = false;
                    if(tmpq != b) bq = false;
                    if(tmps != b) bs = false;
                    pq.pop();
                    q.pop();
                    s.pop();
                }else{
                    imposible = true;
                }
            }
        }
        if(imposible){
            cout<<"impossible"<<endl;
        }
        else if(!bpq and !bq and !bs){
            cout<<"impossible"<<endl;
        }else if(bpq and !bq and !bs){
            cout<<"priority queue"<<endl;
        }else if(!bpq and bq and !bs){
            cout<<"queue"<<endl;
        }else if(!bpq and !bq and bs){
            cout<<"stack"<<endl;
        }else{
            cout<<"not sure"<<endl;
        }
    }
    return 0;
}
