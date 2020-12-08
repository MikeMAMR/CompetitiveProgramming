#include <bits/stdc++.h>
using namespace std;
vector<int> q;
int main(){
    string s;
    while(true){
        getline(cin, s);
        if(s=="Game Over") break;
        for(char a:s){
            if(a=='/'){
                q.push_back(10 - q[q.size()-1]);
            }
            else if(a=='X') q.push_back(10);
            else if(a!=' ') q.push_back(a-'0');
        }
        int intentos = 0;
        int sum = 0;
        for(int i=0; i<q.size(); i++){
            if(intentos==10) break;

            if(q[i]==10){
                sum += q[i]+q[i+1]+q[i+2];
                intentos++;
            }
            else if(q[i]+q[i+1]==10){
                sum += q[i+1]+q[i]+q[i+2];
                intentos++;
                i++;
            }
            else{
                sum += q[i]+q[i+1];
                intentos++;
                i++;
            }
        }
        cout<<sum<<endl;
        q.clear();
    }
    return 0;
}
