#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;
struct calc{
    int val;
    int paso;
};
bool repe[100000];
int a, b, c;
int main(){
    queue<calc> q;

    scanf("%d%d%d", &a,&b,&c);

    repe[1]=1;
    calc nv;

    nv.val=1;
    nv.paso=0;

    q.push(nv);

    while(!q.empty()){

        calc act = q.front();
        q.pop();
        //cout<<act.val<<" " <<act.paso<<endl;
        if(act.val==c){
            cout<<act.paso<<endl;
            return 0;
        }
        int valor = act.paso;
        int por2 = act.val*a;
        int divb = act.val/b;
        if(divb>0 && divb<=9999){
            if(repe[divb]==false){
                calc nueva;
                nueva.val = divb;
                nueva.paso = valor+1;
                q.push(nueva);
                repe[divb]=true;
            }
        }
        if(por2>0 && por2<=9999){
            if(repe[por2]==false){
                calc nueva;
                nueva.val = por2;
                nueva.paso = valor+1;
                q.push(nueva);
                repe[por2]=true;
            }

        }


    }
    cout<<nv.paso;
    return 0;
}
