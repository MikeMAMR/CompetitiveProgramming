#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, arr[100];
    int cont = 0;
    while(scanf("%d", &n), n){
        if(cont != 0) printf("\n");
        cont++;
        for(int i=0; i<n; i++){
            scanf("%d", &arr[i]);
        }
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                for(int k=j+1; k<n; k++){
                    for(int h=k+1; h<n; h++){
                        for(int g=h+1; g<n; g++){
                            for(int f=g+1; f<n; f++){
                                printf("%d %d %d %d %d %d\n", arr[i], arr[j], arr[k], arr[h], arr[g], arr[f]);
                            }
                        }
                    }
                }
            }
        }

    }
    return 0;
}
