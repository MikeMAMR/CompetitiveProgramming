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
const double inf=1e-7;

int p, q, r, s, t, u;

double fun(double x){
    return p* exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*(x*x) + u;
}

double binarySearch(){
    double ini = 0.0, fin = 1.0;
    while(ini+inf < fin){
        double mid = (ini+fin)/2.0;
        if(fun(ini)*fun(mid) <=0.0){
            fin = mid;
        }else{
            ini = mid;
        }
    }
    return (ini);
}

int main(){
    //std::cin.tie(nullptr);
    //std::ios_base::sync_with_stdio(false);
    while(scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u)!=EOF){
        if(fun(0)*fun(1)>0){
            cout<<"No solution\n";
        }else{
            double ans = binarySearch();
            cout<<fixed<<setprecision(4)<<ans<<"\n";
        }
    }
    return 0;
}
