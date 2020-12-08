#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d", &n);
    char p;
    int x, y;
    while(n--){
        cin>>p>>x>>y;
        if(p=='r' || p=='Q'){
            printf("%d\n",min(x,y));
        }
        if(p=='k'){
            if((x*y)%2==0){
                printf("%d\n", (x*y)/2);
            }else{
                printf("%d\n", ((x*y)/2)+1);
            }

        }
        if(p=='K'){
            if(x%2!=0) x++;
            if(y%2!=0) y++;
            printf("%d\n", (x/2)*(y/2));
        }

    }
    return 0;
}
