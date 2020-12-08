#include <bits/stdc++.h>
using namespace std;
bool usd[100000];
int arr[100000];
int n,m ;
vector<string> vec;
set<string> st;
void fun(int num, int pos){
    if(pos==n){
        if(num==m){
            string tmp = "";
            for(int i=0; i<n; i++){
                if(usd[i]){
                    tmp+=to_string(arr[i]);
                    tmp+="+";
                }
            }
            tmp = tmp.substr(0, tmp.size()-1);
            if(!st.count(tmp)) vec.push_back(tmp);
            st.insert(tmp);
        }
        return;
    }
    if(num>m) return;
    usd[pos] = 1;
    fun(num+arr[pos], pos+1);
    usd[pos] = 0;
    fun(num, pos+1);
}
int main(){
    while(scanf("%d%d", &m, &n), (m || n)){
        for(int i=0; i<n; i++){
            scanf("%d", &arr[i]);
        }
        fun(0, 0);
        printf("Sums of %d:\n", m);
        if(st.size()==0){
            printf("NONE\n");
        }
        for(int i=0; i<vec.size(); i++){
            cout<<vec[i]<<endl;
        }
        vec.clear();
        st.clear();
        for(int i=0; i<n; i++){
            usd[arr[i]] = 0;
        }
    }
    return 0;
}
