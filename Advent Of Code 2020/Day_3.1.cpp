#include <bits/stdc++.h>
using namespace std;
string arr[100000];
int ind = 0;
int main(){
    string s;
    int cont = 0;
    while(getline(cin, s)){
        arr[ind++] = s;
    }
    int pos = 3, lim = arr[0].size()-1;
    for(int i=1; i<ind; i++){
        if(arr[i][pos]=='#'){
            cont++;
        }
        if(pos+3>lim){
            pos = 2 -(lim-pos);
        }else{
            pos+=3;
        }
    }
    cout<<cont<<endl;
    return 0;
}
