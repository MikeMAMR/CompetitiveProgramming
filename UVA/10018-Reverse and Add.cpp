#include <bits/stdc++.h>
using namespace std;
string cad="";
long long invertirNumero(long long num) {
    long long inv=0;
    while(num>0){
        inv=inv * 10 + (num % 10);
        cad+= (num%10) +'0';
        num = num / 10;
    }
    return inv;
}
bool isPal(long long num){
    string s="";
    while(num>0){
        s+= (num%10) +'0';
        num = num / 10;
    }
    reverse(s.begin(), s.end());
    for(int i=0; i<s.size(); i++){
        if(s[i]!=s[s.size()-i-1]){
            return false;
        }
    }
    return true;
}
int main(){
    int n;
    long long a;
    scanf("%d", &n);
    while(n--){
        scanf("%lld", &a);
        long long cont = 0, nuevo=a;
        while(true){
            cont++;
            long long inv = invertirNumero(nuevo);
            nuevo+= inv;
            if(isPal(nuevo)) break;
        }
        cout<<cont<<" "<<nuevo<<endl;
    }
    return 0;
}
