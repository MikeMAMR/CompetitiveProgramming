#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m, a, arr[10000], num=0,num2=0, cas =0;
    while(scanf("%d", &n), n){
        cas++;
        printf("Case %d:\n", cas);
        int tmp[500500], ind=0;
        for(int i=0; i<n; i++){
            scanf("%d", &arr[i]);
        }
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                tmp[ind++] = arr[i] + arr[j];
            }
        }
        sort(tmp, tmp+ind);
        scanf("%d", &m);
        for(int i=0; i<m; i++){
            scanf("%d", &a);
            num2=tmp[0];
            for(int j=0; j<ind; j++){
                num = tmp[j];
                if(tmp[j]>=a) break;
                num2=tmp[j];
            }
            if(abs(a-num)<abs(a-num2)){
                printf("Closest sum to %d is %d.\n", a, num);
            }else{
                printf("Closest sum to %d is %d.\n", a, num2);
            }
            //cout<<num<<" "<<num2<<endl;
            //
        }
    }
    return 0;
}
