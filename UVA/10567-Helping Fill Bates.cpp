#include<bits/stdc++.h>
#define DBG(x) cerr << #x << " = " << (x) << endl
using namespace std;
typedef long long ll;
typedef vector<ll> vii;
typedef pair<int, int> pii;
typedef pair<int, string> ps;
long long const MAX = 1e5+10;
int const MAX2 = 2e5;
int const MOD = 10007;//1000000000+7;
const double inf=1e9;

vii arr[200];
map<char, int> mp;

int BS(int n, int pos, char k){
    int ini = 0;
    int fin = n;
    while(ini<fin){
        int mid = ((ini+fin)/2)+1;
        if(arr[k][mid]>pos){
            fin = mid - 1;
        }else{
            ini = mid;
        }
    }
    return ini;

}

int main(){
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    string str, cad;
    int n;
    cin>>str;
    cin>>n;

    for(int i='a'; i<='z'; i++){
        char l = i;
        char k = i-32;
        arr[l].push_back(-1);
        arr[k].push_back(-1);
    }
    for(int i=0; i<str.size(); i++){
        arr[str[i]].push_back(i);
    }
    for(int i=0; i<n; i++){
        cin>>cad;
        mp.clear();
        int ant = 0, pos=0;
        bool ans = true;
        for(int j=0; j<cad.size(); j++){
            mp[cad[j]] += 1;
            if(arr[cad[j]].size()-1<mp[cad[j]]){
                ans = false;
                break;
            }else{
                if(j==0){
                    pos = arr[cad[j]][mp[cad[j]]];
                    ant = pos;
                }else{
                    int tmp = BS(arr[cad[j]].size()-1, pos, cad[j]);
                    if(tmp==arr[cad[j]].size()-1){
                        ans = false;
                        break;
                    }
                    pos = arr[cad[j]][tmp+1];
                }
            }
        }
        if(ans){
          cout<<"Matched "<<ant<<" "<<pos<<"\n";
        }
        else cout<<"Not matched\n";
    }
    return 0;
}
