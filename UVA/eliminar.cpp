#include<bits/stdc++.h>
#define DBG(x) cerr << #x << " = " << (x) << endl
using namespace std;
typedef long long ll;
typedef vector<int> vii;
typedef pair<int, int> pii;
typedef pair<int, string> ps;
long long const MAX =  500;
int const MAX2 = 1e5+10;
int const MOD = 1000000000+7;
const int inf=1e9;
const double PI = acos(-1.0);

string unionF(string a, string b){
    string ans = a;
    int ind = 0, j=0;
    for(int i=0; i<a.size(); i++){
        if(a[i]==b[j]){
            j++;
            ind++;
        }else{
            j = 0;
        }
    }
    for(int i=j; i<b.size(); i++){
        ans += b[i];
    }
    return ans;
}

string arr[100];


int main(){
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    string ans = "";
    sort(arr, arr+n);
    vector<string> k;
    int p = 0;
    do{
        string tmp = "";
        tmp += arr[0];
        for(int i=1; i<n; i++){
            tmp = unionF(tmp, arr[i]);
        }
        //cout<<tmp<<"\n";
        k.push_back(tmp);
        /*if(p==0) ans = tmp;
        else{
            if(ans.size()>=tmp.size() && tmp < ans) ans = tmp;
        }
        p++;*/
    }while(next_permutation(arr, arr+n));
    //cout<<ans<<"\n";
    sort(k.begin(), k.end());
    ans = k[0];
    for(string h: k){
        if(h.size()<ans.size()) ans = h;
    }
    cout<<ans<<"\n";
    return 0;
}
