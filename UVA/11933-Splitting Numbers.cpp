#include <bits/stdc++.h>
using namespace std;
int ones(int n){
    int c = 0;
    while(n){
        n = n & (n-1);
        c++;
    }
    return c;
}
bool check(int n, int i){
    if(n & (1<<i)){
        return true;
    }else{
        return false;
    }
}
long long a1=0, b1=0;
int main(){
    int n;
	while(scanf("%d", &n)!=EOF , n){
        int one = ones(n), ind = 0, m=0;
        string a="", b="";
        while(one){
            if(check(n, ind)){
                if(m%2==0){
                    a+="1";
                    b+="0";
                }else{
                    b+="1";
                    a+="0";
                }
                m++;
                one--;
            }else{
                a+="0";
                b+="0";
            }
            ind++;

        }
        a1=b1=0;
        int pot = 1;
        for(int i=0; i<a.size(); i++){
            if(a[i]=='1'){
                a1 += pot;
            }
            if(b[i]=='1'){
                b1 += pot;
            }
            pot = pot * 2;
        }

        cout<<a1<<" "<<b1<<endl;
	}
	return 0;
}
