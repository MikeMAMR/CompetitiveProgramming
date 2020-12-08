#include <bits/stdc++.h>
using namespace std;

vector<int> q, r;
bool mark[100];
int main(){
    int a1,a2,a3,a4,a5;
    int arr[3] = {0,1,2};
    while(scanf("%d%d%d%d%d", &a1,&a2,&a3,&a4,&a5), (a1 && a2 && a3 && a4 && a5)){
        mark[a1] =true;
        mark[a2] =true;
        mark[a3] =true;
        mark[a4] =true;
        mark[a5] =true;
        int cont=0;
        bool f = false;
        for(int i=1; i<=52; i++){
            q.push_back(a4);
            q.push_back(a5);
            q.push_back(i);
            int mg=0;
            if(!mark[i]){
                do{
                    if(q[arr[0]] > a1) cont++;
                    if(q[arr[1]] > a2) cont++;
                    if(q[arr[2]] > a3) cont++;
                    /*cout<<q[arr[0]]<<endl;
                    cout<<q[arr[0]]<<endl;
                    cout<<q[arr[0]]<<endl;
                    */
                    //cout<<cont<<endl;
                    if(cont>=2){
                      mg++;
                    }
                    cont=0;
                }while(next_permutation(arr, arr+3));
                //cout<<"--"<<endl;
               // cout<<mg<<endl;
                if(mg==6){
                    cout<<i<<endl;
                    f=true;
                    break;
                }
                mg = 0;
            }

            q.clear();
        }
        if(!f) cout<<"-1\n";
            f = false;
         mark[a1] =false;
        mark[a2] =false;
        mark[a3] =false;
        mark[a4] =false;
        mark[a5] =false;
        q.clear();
    }
    return 0;
}
