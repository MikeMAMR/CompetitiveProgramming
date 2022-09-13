#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5;
map<char, int> mp;
map<char, int> check;
int n, m;
string wake, cad;
int main(){
	while(scanf("%d", &n) != EOF){
		scanf("%d", &m);
		cin>>wake;
		mp.clear();
		check.clear();
		vector<int> arr[MAX];
		string ele="";
		for(int i=0; i<wake.size(); i++){
			mp[wake[i]] = 1;
		}
		for(int i=0; i<m; i++){
			cin>>cad;
			arr[cad[0]].push_back(cad[1]);
			arr[cad[1]].push_back(cad[0]);
		}
		int years=0;
		char letter;
		while(true){
			years++;
			vector<char> vec;
			for(int i='A'; i<='Z';i++){
				letter = i;
				if(mp[letter]!=1){
					int cont = 0 ;
					for(int j=0; j<arr[letter].size(); j++){
						if(mp[arr[letter][j]] == 1){
							cont++;
						}
					}
					if(cont>=3){
						vec.push_back(letter);
					}
				}
			}
			if(vec.size()==0) break;
			else {
				
				for(int i=0; i<vec.size(); i++){
					n--;
					mp[vec[i]] = 1;
				}
			}
					
		}
		if(n==3){
			printf("WAKE UP IN, %d, YEARS\n", years-1);
		}
		else{
			printf("THIS BRAIN NEVER WAKES UP\n", years);
		}
	}
	return 0;
}
