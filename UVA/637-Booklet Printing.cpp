#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(scanf("%d", &n), n){
        cout<<"Printing order for "<<n<<" pages:"<<endl;
        if(n==1){
            cout<<"Sheet 1, front: Blank, 1"<<endl;
        }else{
            int p = ceil(n/4.0);
            int ini = 1, fin = p*4;
            for(int i=0; i<p; i++){
                cout<<"Sheet "<<i+1<<", front: ";
                if(fin>n) cout<<"Blank, ";
                else cout<<fin<<", ";
                cout<<ini<<endl;
                ini++; fin--;
                cout<<"Sheet "<<i+1<<", back : "<<ini<<", ";

                if(fin>n) cout<<"Blank"<<endl;
                else cout<<fin<<endl;
                ini++; fin--;
            }
        }
    }
    return 0;
}
