#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6;
int p[MAX], rank1[MAX];
void unionFind(int N){
	for(int i=1; i<=N; i++){
		p[i] = i;
		rank1[i] = 0;
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
		int x = findSet(i), y=findSet(j);
		if(rank1[x] > rank1[y]) p[y] = x;
		else{
			p[x] = y;
			if(rank1[x] == rank1[y]) rank1[y] ++;
 		}
	}
}
int main(){
	int cases, n, a, b;
	string cad;
	char inst;
	scanf("%d", &cases);
	while(cases--){
		int success = 0, unsuccess = 0;
		scanf("\n%d\n", &n);
		unionFind(n);
		while(true){
			if(!getline(cin, cad) || cad.empty()) break;
			sscanf(cad.c_str(), "%c %d %d", &inst, &a, &b);
			//cout<<inst<<" "<<a<<"-"<<b<<endl;
			if(inst == 'c'){
				unionSet(a, b);
			}else{
				if(isSameSet(a, b)){
					//cout<<a<<" "<<b<<endl;
					success++;
				}
				else {
					unsuccess ++;
				}
			}
		}
		printf("%d,%d\n", success, unsuccess);
		if(cases) printf("\n");
	}
	return 0;
}