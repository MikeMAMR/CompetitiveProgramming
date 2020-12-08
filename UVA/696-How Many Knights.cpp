#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    while(scanf("%d %d", &n, &m), (n || m)){
        if(n==0 || m==0){
            cout<<min(n, m)<<" knights may be placed on a "<<n<<" row "<<m<<" column board."<<endl;
        }else if(n==1 || m==1){
            cout<<max(n, m)<<" knights may be placed on a "<<n<<" row "<<m<<" column board."<<endl;
        }else if(n==2 || m==2){
            int p = n*m;
            if(n%2!=0 || m%2!=0){
                p = (p/2)+1;
                cout<<p<<" knights may be placed on a "<<n<<" row "<<m<<" column board."<<endl;
            }else{
                if(p%8!=0){
                    p = (p/8)+1;
                }else{
                    p = (p/8);
                }
                cout<<p*4<<" knights may be placed on a "<<n<<" row "<<m<<" column board."<<endl;
            }
        }else if (n!=2 || m!=2){
            int k = n/2;
            int k2 = m/2;
            if(n%2==0 || m%2==0){
                if(n%2==0){
                    cout<<k*m<<" knights may be placed on a "<<n<<" row "<<m<<" column board."<<endl;
                }else{
                    cout<<k2*n<<" knights may be placed on a "<<n<<" row "<<m<<" column board."<<endl;
                }

            }else{
                k++;
                k2++;
                 int tol = (k*k2)+((k-1)*(k2-1));
                cout<<tol<<" knights may be placed on a "<<n<<" row "<<m<<" column board."<<endl;
            }
        }
    }
    return 0;
}
