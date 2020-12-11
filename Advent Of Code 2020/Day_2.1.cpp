#include <bits/stdc++.h>
using namespace std;
vector<int> num;
bool solve(int a,  int b, char s, string str){
    int cont = 0;
    for(int i=0; i<str.size(); i++){
        if(str[i]==s){
            cont++;
        }
    }
    if(cont>=a && cont<=b) return true;
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
