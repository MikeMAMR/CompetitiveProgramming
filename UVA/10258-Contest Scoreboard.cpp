#include <bits/stdc++.h>
using namespace std;
struct usuario{
    int ind, problem, escore;
    char s;
};
struct UF{
    int ind, PS, score;
    bool pres[10];
};
bool compare(usuario a, usuario b){
    if(a.ind==b.ind){
        return a.problem<b.problem;
    }
    return a.ind<b.ind;
}
bool compare2(UF a, UF b){
    if(a.PS==b.PS){
        if(a.score==b.score){
            return a.ind<b.ind;
        }
        return a.score<b.score;
    }
    return a.PS>b.PS;
}
int main(){
    int cas;
    string s;
    scanf("%d", &cas);
    getline(cin, s);
    getline(cin, s);
    while(cas--){
        usuario user[10000], us;
        int index = 0;
        map<int, UF> mp;
        while(getline(cin, s)){
            if(s=="") break;
            istringstream var(s);
            var >> us.ind >> us.problem>>us.escore>>us.s;
            if(us.s == 'I' or us.s=='C'){

                if(us.s=='C'){
                    if(!mp[us.ind].pres[us.problem]){
                        mp[us.ind].pres[us.problem] = true;
                        mp[us.ind].PS ++;
                        mp[us.ind].score += us.escore;
                        }
                }else{
                    if(!mp[us.ind].pres[us.problem])
                        user[index++] = us;
                }

            }
            mp[us.ind].ind= us.ind;
        }

        //cout<<index<<endl;
        //sort(user, user+index, compare);
        for(int i=0; i<index; i++){
            //cout<<user[i].ind<<" "<< user[i].problem<<" "<<user[i].escore<<" "<<user[i].s<<endl;
            if(mp[user[i].ind].pres[user[i].problem]){
                mp[user[i].ind].score += 20;
            }

        }

    vector<UF> vec;
        UF tmp;
        map<int, UF> :: iterator it;
        for(it=mp.begin(); it!=mp.end(); it++){
            tmp.ind = it->second.ind;
            tmp.PS=it->second.PS;
            tmp.score=it->second.score;;
            vec.push_back(tmp);
            //cout<<"->"<<it->second.ind<<" "<<it->second.PS<<" "<<it->second.score<<endl;
        }
        sort(vec.begin(), vec.end(), compare2);
        for(int i=0; i<vec.size(); i++){
            cout<<vec[i].ind<<" "<<vec[i].PS<<" "<<vec[i].score<<endl;
        }
        if(cas>0) cout<<endl;

    }
    return 0;
}
