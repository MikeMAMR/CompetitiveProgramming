#include <bits/stdc++.h>
using namespace std;
set<char> st;
vector<stack<char>> vs;
int main(){
    string s;
    int cont = 1;
    while(true){
        cin>>s;
        if(s=="end") break;
        st.clear();
        vs.clear();
        bool flag = false;
        reverse(s.begin(), s.end());
        for(int i=0; i<s.size(); i++){
            st.insert(s[i]);
            flag = false;
            for(int j=0; j<vs.size(); j++){
                char tmp = vs[j].top();
                if(tmp<=s[i] and !flag){
                    vs[j].push(s[i]);
                    flag = true;
                }
            }
            if(!flag){
                stack<char> p;
                p.push(s[i]);
                vs.push_back(p);
            }
        }
        int m = min(st.size(), vs.size());
        /*for(int i=0; i<vs.size(); i++){
            while(!vs[i].empty()){
                cout<<vs[i].top()<<" ";
                vs[i].pop();
            }
            cout<<endl;
        }*/

        cout<<"Case "<<cont<<": "<<m<<endl;
        cont++;
    }
    return 0;
}
