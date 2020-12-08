#include<bits/stdc++.h>
using namespace std;
map<string, map<string, string> > mp;
int main() {
	mp["+x"]["+y"] = "+y";
	mp["+x"]["-y"] = "-y";
	mp["+x"]["+z"] = "+z";
	mp["+x"]["-z"] = "-z";
	mp["-x"]["+y"] = "-y";
	mp["-x"]["-y"] = "+y";
	mp["-x"]["+z"] = "-z";
	mp["-x"]["-z"] = "+z";
	mp["+y"]["+y"] = "-x";
	mp["+y"]["-y"] = "+x";
	mp["+y"]["+z"] = "+y";
	mp["+y"]["-z"] = "+y";
	mp["-y"]["+y"] = "+x";
	mp["-y"]["-y"] = "-x";
	mp["-y"]["+z"] = "-y";
	mp["-y"]["-z"] = "-y";
	mp["+z"]["+y"] = "+z";
	mp["+z"]["-y"] = "+z";
	mp["+z"]["+z"] = "-x";
	mp["+z"]["-z"] = "+x";
	mp["-z"]["+y"] = "-z";
	mp["-z"]["-y"] = "-z";
	mp["-z"]["+z"] = "+x";
	mp["-z"]["-z"] = "-x";
    int n;
    string cad, cab;
	while(true){
		scanf("%d", &n);
		if(n==0) break;
		cab = "+x";
		for(long i = 0; i < n-1; i++) {
			cin >> cad;
			if(cad != "No")
				cab = mp[cab][cad];
		}
		cout<<cab<<endl;
	}
}
