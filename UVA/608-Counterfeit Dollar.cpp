#include <bits/stdc++.h>
using namespace std;
int up[100];
int down[100];
string a, b, c;

int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        for(int i=0; i<3; i++){
            cin>>a>>b>>c;
            if(c=="down"){
                for(int j=0; j<a.size(); j++){
                    down[a[j]]++;
                    up[b[j]]++;
                }
            }else if(c=="even"){
                for(int j=0; j<a.size(); j++){
                    down[a[j]]-=3;
                    down[b[j]]-=3;
                    up[a[j]]-=3;
                    up[b[j]]-=3;

                }
            }else if(c=="up"){
                for(int j=0; j<a.size(); j++){
                    up[a[j]]++;
                    down[b[j]]++;
                }
            }
        }
        int mid = -5;
        bool flag = true;
        int index = 0;
        for(int i='A'; i<='Z'; i++){
            if(mid<up[i]){
                mid = up[i];
                index = i;
                flag = false;
            }
            if(mid<down[i]){
                mid = down[i];
                index = i;
                flag = true;
            }

        }
        char s = index;
        if(!flag){
            cout<<s<<" is the counterfeit coin and it is heavy."<<endl;
        }else{
            cout<<s<<" is the counterfeit coin and it is light."<<endl;
        }
        for(int i='A'; i<='Z'; i++){
            down[i]=0;
            up[i]=0;
        }

    }
    return 0;

}
