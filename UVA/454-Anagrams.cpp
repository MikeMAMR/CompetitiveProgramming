#include <bits/stdc++.h>
using namespace std;
typedef pair<string, string> v;
bool compare(v a, v b){
    return a.second < b.second;
}
int main(){
    int n;
    scanf("%d", &n);
    cin.ignore();
    cin.ignore();
    string s;
    while(n--){
        vector<v> q;
        while (getline(cin, s) && s != ""){
            string tmp;
            for(int i=0; i<s.size(); i++){
                if(s[i]!=' '){
                    tmp+= (s[i]);
                }
            }
            sort(tmp.begin(), tmp.end());
            q.push_back({tmp, s});
        }
        sort(q.begin(), q.end(), compare);
        for(int i=0; i<q.size(); i++){
            for(int j=i+1; j<q.size(); j++){
                if(q[i].first == q[j].first){
                    cout<<q[i].second <<" = "<<q[j].second<<endl;
                }
            }
        }
        if(n!=0) cout<<endl;
        q.clear();
    }
    return 0;
}
