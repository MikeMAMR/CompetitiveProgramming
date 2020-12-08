#include <bits/stdc++.h>
using namespace std;

int main(){
    double h, m;
    while(true){
        scanf("%lf:%lf", &h, &m);
        if(h==0.0){
            break;
        }
        double res = h*30+(m/60)*30;
        double p = m*6;
        res = res-p;
        if(res<0){
            res*=-1;
        }
        if(res>180){
            res = 360-res;
        }
        printf("%.3f\n",res);
    }
    return 0;
}
