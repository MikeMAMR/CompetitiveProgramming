#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    int rfp =0 ;
    while(true){
        rfp++;
        scanf("%d%d", &n,&m);
        if(n==0){
            break;
        }
        string s;
        for(int i=0; i<n; i++){
            cin.ignore();
            getline(cin, s);
        }
        double mx = 20000000000.00;
        int h=-1;
        string sm, pro;
        double cont;
        int cl;
        while(m--){
            getline(cin, pro);
            //cout<<pro<<endl;
            scanf("%lf %d", &cont, &cl);
           // cout<<cl<<endl;
            if(cl>h){
                h = cl;
                sm = pro;
                mx = cont;
            }
            if(cl ==h && (cont<mx)){
                h = cl;
                sm = pro;
                mx = cont;
            }
            for(int i=0; i<cl; i++){
                cin.ignore();
                getline(cin, s);
            }
        }
        if(rfp > 1) cout<<endl;
        cout<<"RFP #"<<rfp<<endl<<sm<<endl;
    }
    return 0;
}
