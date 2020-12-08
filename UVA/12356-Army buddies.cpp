#include <bits/stdc++.h>
using namespace std;
struct nodo{
    int sig, ant;
};
nodo arr[100010];
void llenar(int n){
    for(int i=1; i<n; i++){
        arr[i].ant = i - 1;
        arr[i].sig = i + 1;
    }
    arr[n].ant = n - 1;
    arr[n].sig = 0;
}
int main(){
    int n, m;
    int a, b;
    while(scanf("%d%d", &n, &m) , (m || n)){
        llenar(n);
        for(int i=0; i<m; i++){
            scanf("%d%d", &a, &b);
            arr[arr[a].ant].sig = arr[b].sig;
            arr[arr[b].sig].ant = arr[a].ant;
            if(arr[arr[b].sig].ant==0){
                printf("* ");
            }else{
                printf("%d ", arr[arr[b].sig].ant);
            }
            if(arr[arr[a].ant].sig ==0 ){
                printf("*\n");
            }else{
                printf("%d\n", arr[arr[a].ant].sig);
            }
            //cout<<"Nodos: "<<arr[arr[a].ant].sig <<" " <<arr[arr[b].sig].ant<<endl;
        }
        printf("-\n");
    }
    return 0;
}
