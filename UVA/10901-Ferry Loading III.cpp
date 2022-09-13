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
const int inf=1e9;


int main(){
    //UVA NO
    //std::cin.tie(nullptr);
    //std::ios_base::sync_with_stdio(false);
    int cases, n, t, m, a;
    int ans[10010];
    string b;
    cin>>cases;
    while(cases--){
        cin>>n>>t>>m;
        queue<pii> L, R;
        int time = 0;
        for(int i=0; i<m; i++){
            cin>>a>>b;
            if(b=="left") L.push({a, i});
            else R.push({a, i});
        }
        bool turn = true;
        int cnt = 0;
        //true IZQ, false DER
        while(!L.empty() || !R.empty()){
            //getchar();

            pii pa, pb;
            int r = 0;
            cnt = 0;
            if(R.empty()){
                pa = L.front();
                r = pa.first;
            }else if(L.empty()){
                pb = R.front();
                r = pb.first;
            }else{
                pa = L.front();
                pb = R.front();
                r = min(pa.first, pb.first);
            }
            if(time<r) time = r;

            if(turn){
                //cout<<"left t: "<<time<<"\n";

                vii vec;
                if(!L.empty()){

                    if(!R.empty()){
                        if(pa.first<=pb.first || pa.first<=time){
                            while(!L.empty()){
                                pii sac = L.front();
                                if(sac.first>time) break;
                                if(cnt==n) break;
                                cnt++;
                                L.pop();
                                vec.push_back(sac.second);
                            }
                        }
                    }else{
                            while(!L.empty()){
                                pii sac = L.front();
                                if(sac.first>time) break;
                                if(cnt==n) break;
                                cnt++;
                                L.pop();
                                vec.push_back(sac.second);
                            }
                    }
                }
                time += t;
                turn = false;
                if(cnt!=0){
                    for(int i=0;i<cnt; i++){
                        //cout<<"i: "<<vec[i]<<"\n";
                        ans[vec[i]] = time;
                    }
                    cnt = 0;
                }
            }else{
                //cout<<"right t: "<<time<<"\n";

                vii vec;
                if(!R.empty()){
                    //cout<<"puto\n";
                    if(!L.empty()){
                        if(pb.first<=pa.first || pb.first<=time){
                            //cout<<"p1\n";
                            while(!R.empty()){
                                pii sac = R.front();
                                if(sac.first>time) break;
                                if(cnt==n) break;
                                cnt++;
                                R.pop();
                                vec.push_back(sac.second);
                            }
                        }
                    }else{
                            while(!R.empty()){
                                pii sac = R.front();
                                if(sac.first>time) break;
                                if(cnt==n) break;
                                cnt++;
                                R.pop();
                                vec.push_back(sac.second);
                            }
                    }
                }
                time += t;
                turn = true;
                if(cnt!=0){
                    for(int i=0;i<cnt; i++){
                            //cout<<"i: "<<vec[i]<<"\n";
                        ans[vec[i]] = time;
                    }
                    cnt = 0;
                }
            }
        }
        for(int i=0; i<m; i++){
            cout<<ans[i]<<"\n";
        }
        if(cases) cout<<"\n";
    }
    return 0;
}
