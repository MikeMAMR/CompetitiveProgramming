#include<bits/stdc++.h>
using namespace std;
const long long cons = 1e6;
int main(){
    for(int i=1; i<=2000; i++){
        if(i+i+i+i>2000) break;
        for(int j=i; j<=2000; j++){
            if(i+j+j+j>2000) break;
            for(int k=j; k<=2000; k++){
                if(i+j+k+k>2000) break;
                int p = i*j*k;
                if(p>cons){
                    int s = i+j+k;
                    if((s*cons) % (p-cons)==0){
                        int d = (s*cons) / (p-cons);
                        if(k<=d and i+j+k+d<=2000) cout<<fixed<<setprecision(2)<<float(i)/100.0<<" "<<float(j)/100<<" "<<float(k)/100<<" "<<float(d)/100<<endl;
                    }
                }
            }
        }
    }
    return 0;
}
