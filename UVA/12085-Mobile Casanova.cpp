#include <bits/stdc++.h>
using namespace std;
string dig(long long a, long long b){
    string cad="";
    int ini = a%10;
    int fin = b%10;
    cad+=fin+'0';
    a/=10;
    b/=10;
    while(true){
        if(a==b) break;
        ini = a%10;
        fin = b%10;
        a/=10;
        b/=10;
        cad+=fin+'0';


    }
    reverse(cad.begin(), cad.end());
    return cad;
}
int main(){
    int n, cases=0;
    while(scanf("%d", &n), n){
        long long arr[100000];
        for(int i=0; i<n; i++){
            cin>> arr[i];
        }
        cout<<"Case "<<++cases<<":"<<endl;
        for(int i=0; i<n; i++){
            if(arr[i]+1 != arr[i+1]){
                cout<<"0"<<arr[i]<<endl;
            }else{
                long long ini = arr[i];
                long long fin = arr[i+1];
                int ind = 1;
                while(ini+ind==fin){
                    ind++;
                    if(ind==n) break;
                    fin = arr[i+ind];


                }
                fin = arr[i+ind-1];
                cout<<"0"<<ini<<"-"<<dig(ini, fin)<<endl;
                i+=ind-1;
            }
        }
        cout<<endl;
    }

    return 0;
}
