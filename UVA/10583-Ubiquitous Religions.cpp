#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
const int MAX = 1e6;
vi p;
int n, m;
bool mark[MAX];
void clearMark(int N){
	for(int i=1; i<=N; i++) mark[i] = false;
}
void unionFind(int N){
	p.assign(N, 0);
	for(int i=1; i<=N; i++) p[i] = i;
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
		p[x] = y;
	}
}
int main(){
	int cases = 0;
	while(scanf("%d%d",&n, &m) &&  (n || m)){
		int a, b;
		cases++;
		unionFind(n);
		//clearMark(n);
		for(int i=0; i<m; i++){
			scanf("%d%d", &a,&b);
			unionSet(a, b);
		}
		int religions = 0;
		for(int i=1; i<=n; i++){
			if(p[i] == i) religions ++;
		}
		printf("Case %d: %d\n",cases, religions);
	}	
	return 0;
}