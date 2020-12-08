#include <bits/stdc++.h>
using namespace std;
int arr1[500];
int arr2[500];
int arr3[500];
map<int, int> mp;
int main(){
    int ind = 0;
    for(int i=0; i<=20; i++){
        for(int j=1; j<=3; j++){
            if(mp[i*j]!=1){
                arr1[ind] = i*j;
                arr2[ind] = i*j;
                arr3[ind] = i*j;
                ind++;
                mp[i*j] = 1;
            }
        }
    }
    arr1[ind] = 50;
    arr2[ind] = 50;
    arr3[ind] = 50;
    ind++;
    int n;
    while(true){
        int permutacion = 0, combinacion = 0;
        scanf("%d", &n);
        int arr[4];
        set<string > st;
        if(n<=0) break;
        for(int i=0; i<ind; i++){
            for(int j=0; j<ind; j++){
                for(int k=0; k<ind; k++){
                    if((arr1[i] + arr2[j] + arr3[k]) == n){
                        arr[0] = arr1[i];
                        arr[1] = arr2[j];
                        arr[2] = arr3[k];
                        sort(arr, arr+3);
                        st.insert(to_string(arr[0]) + to_string(arr[1]) + to_string(arr[2]));

                        //cout<<arr1[i] << " "<< arr2[j] <<" "<<arr3[k]<<endl;
                        permutacion++;
                    }
                }
            }
        }
        if(permutacion==0){
            printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", n);
        }else{
            printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n", n, st.size());
            printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", n, permutacion);
        }
        printf("**********************************************************************\n");

    }
    printf("END OF OUTPUT\n");
    return 0;
}
