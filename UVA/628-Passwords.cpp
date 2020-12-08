#include <bits/stdc++.h>
using namespace std;
int arr[100];
int n;
int m, p;
string format;
void solve(int pos, string str){
    if(pos==n){
        int ind = 0;
        for(int i=0; i<format.size(); i++){
            if(format[i]=='#') cout<<str;
            else cout<<arr[ind++];
        }
        cout<<endl;
        return;
    }
    for(int i=0; i<=9; i++){
        arr[pos] = i;
        solve(pos+1, str);
    }
}
int main(){
    string cad[10000];
    while(scanf("%d", &m) != EOF){
        for(int i=0; i<m; i++){
            cin>>cad[i];
        }
        scanf("%d", &p);
        cout<<"--"<<endl;
        for(int i=0; i<p; i++){
            cin>>format;
            n = 0;
            for(int j=0; j<format.size(); j++){
                if(format[j]=='0') n++;
            }
            for(int j=0; j<m; j++){
                solve(0, cad[j]);
            }
        }
    }
    return  0;
}

