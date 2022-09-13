#include<bits/stdc++.h>
using namespace std;


typedef long long ll;
const int infl = 1e9;

struct STNode{
    ll inf, sup;
    ll val;

    STNode *izq = NULL, *der=NULL;
    STNode(const vector<int>&vec, ll _inf, ll _sup){
        inf = _inf, sup = _sup;
        if(inf==sup){
            val = vec[sup];
            return;
        }
        int med = (inf + sup) / 2;
        izq = new STNode(vec, inf, med);
        der = new STNode(vec, med+1, sup);
        val = izq->val * der->val;
    }
    STNode(const vector<int>&vec): STNode(vec, 0, vec.size()-1){}
    void update(ll pos, ll nval){
        if(inf==sup && inf==pos){
            val = nval;
            return;
        }
        int med = (inf + sup) /2;
        if(pos<=med){
            izq -> update(pos, nval);
        }else{
            der -> update(pos, nval);
        }
        val = izq->val * der->val;
    }
    ll query(ll _inf, ll _sup){
        if(_inf <= inf && sup <=_sup){
            return val;
        }
        if(_inf > sup || _sup < inf){
            return 1;
        }
        return izq->query(_inf, _sup) * der->query(_inf, _sup);
    }

};

STNode *st;

int main(){
    //std::cin.tie(nullptr);
    //std::ios_base::sync_with_stdio(false);
    int n, m, a, b;
    string c;
    while(scanf("%d%d", &n, &m) != EOF){
        vector<int> v;
        for(int i=0; i<n; i++){
            cin>>a;
            if(a<0) a = -1;
            else if (a > 0) a=1;
            v.push_back(a);
        }
        st = new STNode(v);
        string ans = "";
        for(int i=0; i<m; i++){
            cin>>c>>a>>b;
            if(c=="C"){
                if(b<0) b = -1;
                else if (b > 0) b = 1;
                st->update(a-1, b);
            }else{
                ll num = st->query(a-1, b-1);
                if(num==0) ans += "0";
                else if(num>0) ans += "+";
                else ans += "-";
                //cout<<v[a-1]<<" "<<v[b-1]<<"\n";
                //cout<<ans<<"\n";
                //cout<<num<<"\n";
            }

        }
        cout<<ans<<"\n";
    }

	return 0;
}