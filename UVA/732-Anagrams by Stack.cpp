#include <bits/stdc++.h>
using namespace std;

const int lim = 1e6;
string in, out;
int bina[lim];
int n, m;
void bin(int pos, int lm, int ver, string entrada, string tmp, string acm, int otro){
    //cout<<acm<<" str "<<out.substr(0, otro)<<endl;
	if(pos == n){
		if(lm == m){
			if(acm == out){
                for(int i=0; i<n; i++){
                    if(bina[i]==0){
                        printf("o");
                    }else{
                        printf("i");
                    }
                    if(i!=n-1) printf(" ");
                }
                printf("\n");
			}
		}

		return;
	}
	if(lm>m) return;
	if(ver<0) return;
	if(acm!="" && acm != out.substr(0, otro)) return;
    //int pos, int lm, int ver, string in, string tmp, string acm
    if(entrada!=""){
        bina[pos] = 1;
        string g1 = entrada.substr(1, entrada.size());
        string g2 = tmp + entrada[0];
        bin(pos+1, lm+1, ver+1, g1, g2, acm, otro);
    }
    if(tmp!=""){
        bina[pos] = 0;
        string g1 = tmp.substr(0, tmp.size()-1);
        string g2 = acm + tmp[tmp.size()-1];
        bin(pos+1, lm, ver-1, entrada, g1, g2, otro+1);
    }
}
bool check(string a, string b){
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    return a == b;
}
int main(){
    while(cin >> in >> out){
        m = in.size();
        n = m * 2;
        printf("[\n");
        if(check(in, out)) bin(0,0,0, in, "", "", 0);
        printf("]\n");
    }

	return 0;
}

