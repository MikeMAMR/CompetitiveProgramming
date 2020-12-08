#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    cin.ignore();
    string s;
    while(n--){
        map<string, vector<string>> mp;
        map<string, int> che;
        vector<pair<string, int>> vec;
        vector<string> h;
        while (getline(cin, s) && s != ""){
                string tmp="", bin=s;
                for(int i=0; i<s.size(); i++){
                    if(s[i]!=' '){
                        tmp+= tolower(s[i]);
                    }
                }
                sort(tmp.begin(), tmp.end());
                mp[tmp].push_back(s);
                vec.push_back({tmp,mp[tmp].size()});
                h.push_back(s);
        }

        for(int i=0; i<vec.size(); i++){
            if(mp[vec[i].first].size()>1){
                for(int j=vec[i].second; j<mp[vec[i].first].size(); j++){
                    cout<<h[i]<<" = "<<mp[vec[i].first][j]<<endl;
                }
            }
        }
        cout<<endl;
    }

    return 0;
}
