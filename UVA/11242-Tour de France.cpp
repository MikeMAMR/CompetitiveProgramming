#include <bits/stdc++.h>
using namespace std;
vector<double> vec;
int main(){
    int n, m;
    double fronts[100], ends[100];
    while(true){
        scanf("%d", &n);
        if(!n) break;
         scanf("%d", &m);
        vec.clear();
        for(int i=0; i<n; i++){
            scanf("%lf", &fronts[i]);
        }
        for(int i=0; i<m; i++){
            scanf("%lf", &ends[i]);
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                vec.push_back(double(ends[j]/fronts[i]));
            }
        }
        double mx = 0.0;
        sort(vec.begin(), vec.end());
        for(int i=1; i<vec.size(); i++){
            mx = max(mx, vec[i]/vec[i-1]);
        }
       cout<<fixed<<setprecision(2)<<mx<<endl;
    }
    return 0;
}
