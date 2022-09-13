#include <bits/stdc++.h>
using namespace std;
map<string, int> mp;
vector<int> p, leng;
string a, b;
void UnionFind(int n){
	leng.assign(n, 1);
	p.assign(n, 0);
	for(int i=0; i<n; i++) p[i] = i;
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
		//cout<<x<<" "<<y<<endl;
		leng[x] = leng[x] + leng[y];
		leng[y] = leng[x];
		p[y] = x;
	}
}
int main(){
	int cases, n;
	int cont = 0;
	scanf("%d", &cases);
	while(cases--){
		scanf("%d", &n);
		UnionFind(n*2);
		for(int i=0;i<n;i++){
			cin>>a>>b;
			if(mp.count(a) == 0){
				mp[a] = cont;
				p[cont] = cont;	
				cont++;
			}
			if(mp.count(b) == 0){
				mp[b] = cont;
				p[cont] = cont;	
				cont++;
			} 
			unionSet(mp[a], mp[b]);
			cout<<leng[findSet(mp[a])]<<endl;	
		}	
	}
	
	return 0;
}