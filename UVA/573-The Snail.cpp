#include <bits/stdc++.h>
using namespace std;
int main(){
    double h, u, d, f;
    while(true){
        int cont =1;
        bool flag=true;
        cin>>h>>u>>d>>f;
        //scanf("%f%f%f%f", &h,&u,&d,&f);
        if(h==0){
            break;
        }
        double r = (f*u)/(100.0);
        //cout<<"r "<<r<<endl;
        double res = 0 ;
        while(true){
            //cout<<cont<<" ";
            res += u;
            if(u > 0 ) u-=r;
            if(res>h){
                break;
            }
            res -= d;
            if(res<0){
                flag=false;
                break;
            }
            cont++;
            //cout<<res<<endl;
        }
        //cout<<res<<endl;
        if(!flag){
            cout<<"failure on day "<<cont<<endl;
        }else{
            cout<<"success on day "<<cont<<endl;
        }
        //cout<<"c "<<cont<<endl;
        //cout<<"cont "<<cont<<" res "<<res<<endl;

    }
    return 0;
}
