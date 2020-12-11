#include <bits/stdc++.h>
using namespace std;
vector<int> num;
bool solve(int a,  int b, char s, string str){
    int cont = 0;
    if(str[a-1]==s) cont++;
    if(str[b-1]==s) cont++;
    if(cont == 1) return true;
    return false;
}
 int main(){

    string a, b;
    int inf, sup, cont = 0;
    while(scanf("%d-%d", &inf, &sup) != EOF){
        cin>>a>>b;
        if(solve(inf, sup, a[0], b)){
            cont++;
        }
    }
    cout<<cont<<endl;

    return 0;
 }
