#include <bits/stdc++.h>
using namespace std;
multiset<int> sg, sb;
int main(){
    int n, m, g, b,a ;
    scanf("%d", &n);
    while(n--){
        scanf("%d%d%d", &m, &g, &b);
        sg.clear();
        sb.clear();
        multiset<int> :: iterator ita;
        multiset<int> :: iterator itb;
        multiset<int> :: reverse_iterator rita;
        multiset<int> :: reverse_iterator ritb;
        for(int i=0; i<g;i++){
            scanf("%d", &a);
            sg.insert(a);
        }
        for(int i=0; i<b;i++){
            scanf("%d", &a);
            sb.insert(a);
        }
        vector<int> green, blue;
        while(true){

            for(int i=0; i<m; i++){
                if(sb.size()>0 and sg.size()>0){
                    ita = sg.end();
                    ita--;
                    itb = sb.end();
                    itb--;
                    int xg = *(ita);
                    int xb = *(itb);
                    sb.erase(itb);
                    sg.erase(ita);
                    if(xg>xb){
                        xg = xg-xb;
                        green.push_back(xg);
                    }else if(xb>xg){
                        xb = xb-xg;
                        blue.push_back(xb);
                    }
                }
            }
            for(int i=0; i<green.size(); i++){
                sg.insert(green[i]);
            }
            for(int i=0; i<blue.size(); i++){
                sb.insert(blue[i]);
            }
            blue.clear();
            green.clear();
            if(sb.size()==0 and sg.size()!=0){
                cout<<"green wins"<<endl;
                for(rita = sg.rbegin(); rita!=sg.rend(); ++rita){
                    cout<<*rita<<endl;
                }
                if(n>0)cout<<endl;
                break;
            }else if(sb.size()!=0 and sg.size()==0){
                cout<<"blue wins"<<endl;
                for(ritb = sb.rbegin(); ritb!=sb.rend(); ++ritb){
                    cout<<*ritb<<endl;
                }
                if(n>0)cout<<endl;
                break;
            }else if(sb.size()==0 and sg.size()==0){
                cout<<"green and blue died"<<endl;
                if(n>0)cout<<endl;
                break;
            }

        }
    }
    return 0;
}
