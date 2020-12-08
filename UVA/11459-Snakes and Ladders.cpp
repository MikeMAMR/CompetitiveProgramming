#include <bits/stdc++.h>

using namespace std;
int portalA[120];
int portalB[120];
int player[1000000];
int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        int a, b, c;
        int c1, c2;
        scanf("%d%d%d", &a, &b, &c);
        for(int i=0; i<b; i++){
            scanf("%d%d", &c1,&c2);
            portalA[c1] = c2;
            /*if(c1>c2) portalA[c1] = c2;
            else portalB[c1] = c2;*/
        }
        for(int i=0; i<a; i++) player[i] = 1;
        int ind = 0;
        int paso;
        bool continuar = true;
        for(int i=0; i<c; i++){
            scanf("%d", &paso);
            if(continuar){
                player[ind]+= paso;
                if(portalA[player[ind]]!=0) player[ind] = portalA[player[ind]];
                //if(portalB[player[ind]]!=0) player[ind] = portalB[player[ind]];
                if(player[ind]>=100) continuar = false;
                ind++;
                if(ind==a) ind = 0;
            }
        }
        for(int i=0; i<a; i++){
            if(player[i]>100) player[i] = 100;
            cout<<"Position of player " <<i+1<<" is "<<player[i]<<"."<<endl;
            player[i] = 0;
        }
        for(int i=1; i<=100; i++){portalA[i] = 0;/* portalB[i] =0;*/ }
    }
    return 0;
}
