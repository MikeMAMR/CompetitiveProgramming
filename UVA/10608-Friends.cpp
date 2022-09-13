#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
const int MAX = 1e7;
int p[MAX], leng[MAX];
int n, m, a, b;
void unionFind(int N){
	//p.assign(N, 0);
	//leng.assign(N, 1);
	for(int i=1; i<=N; i++){
		p[i] = i;
		leng[i] = 1;
	} 
}
int findSet(int i){
	return (p[i] == i) ? i : (p[i] = findSet(p[i]));
}
bool isSameSet(int i, int j){
	return findSet(i) == findSet(j);
}
void unionSet(int i, int j){
	if(!isSameSet(i, j)){
		int x = findSet(i), y = findSet(j);
		leng[x] = leng[x] + leng[y];
		leng[y] = leng[x];
		p[y] = x;
	}
}
int main(){
	int cases;
	scanf("%d",&cases);
	while(cases--){
		scanf("%d%d", &n,&m);
		unionFind(n);
		for(int i=0; i<m; i++){
			scanf("%d%d",&a,&b);
			unionSet(a, b);
		}
		int mx = 0;
		for(int i=1; i<=n; i++){
			if(p[i] == i) mx  = max(mx, leng[i]);
			//cout<<"r "<<p[i]<<endl;
		}
		printf("%d\n", mx);
	}
	return 0;
}