#include <bits/stdc++.h>
using namespace std;
struct num{
    int id, val, ini;
    bool operator<(const num &o) const
    {
        if(val == o.val)
            return id > o.id;
        return  val > o.val;
    }
};
int main(){
    priority_queue<num> pq;
    string s;
    int id, val, n;
    while(true){
        cin>>s;
        if(s=="#") break;
        cin>>id>>val;
        pq.push({id, val, val});
    }
    cin>>n;
    num tmp;
    while(n--){
        tmp = pq.top();
        pq.pop();
        cout<<tmp.id<<endl;
        tmp.val = tmp.val + tmp.ini;
        pq.push(tmp);
    }

    return 0;
}
