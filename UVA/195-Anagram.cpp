#include <bits/stdc++.h>
using namespace std;
bool compare(char a, char b){
    if(tolower(a) == tolower(b)){
        return a<b;
    }
    return tolower(a)<tolower(b);
}
int main(){
    int n;
    char cad[10000];
    scanf("%d", &n);
    while(n--){
        scanf("%s", cad);
        sort(cad,cad+strlen(cad), compare);
        cout<<cad<<endl;
        while(next_permutation(cad, cad+strlen(cad), compare)){
            cout<<cad<<endl;
        }
    }
    return 0;
}
