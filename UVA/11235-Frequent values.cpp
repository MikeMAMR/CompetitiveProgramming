#include<bits/stdc++.h>
#define DBG(x) cerr << #x << " = " << (x) << endl
using namespace std;
typedef long long ll;
typedef vector<ll> vii;
typedef pair<int, int> pii;
typedef pair<int, string> ps;
long long const MAX = 2e5+10;
int const MAX2 = 2e5;
int const MOD = 10007;//1000000000+7;
const int inf=1e9;

map<int, pii> mp;
int arr[MAX], mat[MAX];
vii st, A;

int left(int p){return p<<1;}
int right(int p) {return (p<<1)+1;}

void build(int nodos, int L, int R){
	if(L==R) st[nodos] = L;
	else{
		build(left(nodos), L, (L+R)/2);
		build(right(nodos), (L+R)/2+1, R );
		int p1 = st[left(nodos)], p2 = st[right(nodos)];
		st[nodos] = (A[p1]>=A[p2])  ? p1 : p2;
	}
}

int rqm(int nodos, int L, int R, int i, int j){
	if(i > R || j < L) return -1;
	if(L >= i && R<=j ) return st[nodos];
	int p1 = rqm(left(nodos), L, (L+R)/2, i, j);
	int p2 = rqm(right(nodos), (L+R)/2+1, R, i, j);
	if(p1==-1) return p2;
	if(p2==-1) return p1;
	return(A[p1] >= A[p2]) ? p1 : p2;
}
void iniTree(int n){
	st.assign(4*n, 0);
	build(1,0, n-1);
}

int main(){
    //UVA NO
    //std::cin.tie(nullptr);
    //std::ios_base::sync_with_stdio(false);
    int n, m;

    while(scanf("%d", &n), n){
        scanf("%d", &m);
        mp.clear();
        A.clear();
        st.clear();
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        int ini = 0, fin = 0, ind = 0, c = 1;
        vii vec;
        for(int i=1; i<n;i++){
            if(arr[i]!=arr[i-1]){
                fin = i-1;
                mp[ind++] = {ini, fin};
                ini = i;
                vec.push_back(c);
                c=0;
            }
            if(i==n-1){
                fin = n-1;
                mp[ind++] = {ini, fin};
                vec.push_back(c+1);
                c=0;
            }
            c++;
        }
        ind = 0;
        for(int i=0; i<n;i++){
            A.push_back(vec[ind]);
            mat[i] = ind;
            if(arr[i]!=arr[i+1]){
                ind++;
            }
        }
        iniTree(n);
        int a, b;
        int cini = 0, cfin=0;
        for(int i=0; i<m; i++){
            cin>>a>>b;
            if(a<1) a = 1;
            if(b>n) b = n;
            a--;
            b--;
            if(a==b) cout<<"1\n";
            else if(mp[mat[a]].first==mp[mat[b]].first){
                cout<<b-a+1<<"\n";
            }
            else{
            cini = cfin = 0;
            if(mp[mat[a]].second==a){
                a++;
                cini = 1;
            }
            if(a>mp[mat[a]].first && a<mp[mat[a]].second){
                cini = ((mp[mat[a]].second)) - a + 1;
                a = mp[mat[a]].second + 1;

            }

            if(mp[mat[b]].first==b){
                b--;
                cfin = 1;
            }
            if(b>mp[mat[b]].first && b<mp[mat[b]].second){
                cfin = b - mp[mat[b]].first + 1;
                b = mp[mat[b]].first - 1;
            }
                int q = rqm(1, 0, n-1, a, b);
                //cout<<cini<<" "<<cfin<<"\n";
                //cout<<A[q]<<"\n";
                if(q!=-1){
                    int tmp = A[q];
                    cout<<max(max(cfin, cini),tmp)<<"\n";
                }else{
                    cout<<max(cfin, cini)<<"\n";
                }
            }
        }
    }
    return 0;



}
