#include <bits/stdc++.h>
using namespace std;
string Parents(string a, string b, bool flag){
    string res="";
    if(a=="O" && b=="O"){
        res+="O-";
        if(!flag) res+=", O+, ";
    }else if((a=="A" && b=="AB") || (a=="AB" && b=="B") || (a=="AB" && b=="AB")){
        string s[4] = {"AB", "B", "A"};
        for(int i=0; i<3; i++){
            res +=s[i]+"-, ";
            if(!flag) res += s[i]+"+, ";
        }
    }else if((a=="A" && b=="O" ) || (a=="A" && b=="A")){
        string s[3] = {"A", "O"};
        for(int i=0; i<2; i++){
            res +=s[i]+"-, ";
            if(!flag) res += s[i]+"+, ";
        }
    }else if((a=="B" && b=="O") || (a=="B" && b=="B")) {
        string s[3] = {"B", "O"};
        for(int i=0; i<2; i++){
            res +=s[i]+"-, ";
            if(!flag) res += s[i]+"+, ";
        }
    }else if(a=="A" && b=="B"){
        string s[5] = {"A", "AB","B", "O"};
        for(int i=0; i<4; i++){
            res +=s[i]+"-, ";
            if(!flag) res += s[i]+"+, ";
        }
    }else if(a=="AB" && b=="O"){
        string s[3] = {"A", "B"};
        for(int i=0; i<2; i++){
            res +=s[i]+"-, ";
            if(!flag) res += s[i]+"+, ";
        }
    }
    return res;
}
string PH(string a, string b, bool flag){
    string res="";
    if((a=="AB" && b=="O") || (a=="O" && b=="AB") ){
        res+="IMPOSSIBLE";

    }else if((a=="A" && b=="O") || (a=="O" && b=="O")){
        string s[4] = {"A", "B","O"};
        for(int i=0; i<3; i++){
            res +=s[i]+"+, ";
            if(!flag) res += s[i]+"-, ";
        }
    }else if((a=="A" && b=="A")|| (a=="B" && b=="B") || (a=="AB" && b=="B") || (a=="AB" && b=="A")){
        string s[5] = {"A", "AB","B", "O"};
        for(int i=0; i<4; i++){
            res +=s[i]+"+, ";
            if(!flag) res += s[i]+"-, ";
        }
    }else if((a=="A" && b=="B") || (a=="A" && b=="AB")  || (a=="O" && b=="B")){
        string s[3] = {"AB", "B"};
        for(int i=0; i<2; i++){
            res +=s[i]+"+, ";
            if(!flag) res += s[i]+"-, ";
        }
    }else if((a=="B" && b=="A") || (a=="B" && b=="AB") || (a=="O" && b=="A") ){
        string s[3] = {"AB", "A"};
        for(int i=0; i<2; i++){
            res +=s[i]+"+, ";
            if(!flag) res += s[i]+"-, ";
        }
    }else if(a=="B" && b=="O"){
        string s[4] = {"A", "B","O"};
        for(int i=0; i<3; i++){
            res +=s[i]+"+, ";
            if(!flag) res += s[i]+"-, ";
        }
    }else if(a=="B" && b=="AB"){
        string s[3] = {"A", "AB"};
        for(int i=0; i<2; i++){
            res +=s[i]+"+, ";
            if(!flag) res += s[i]+"-, ";
        }
    }else if(a=="AB" && b=="AB"){
        string s[4] = {"A", "AB", "B"};
        for(int i=0; i<3; i++){
            res +=s[i]+"+, ";
            if(!flag) res += s[i]+"-, ";
        }
    }
    return res;
}
int main(){
    string a, b, c;
    //cout<<PH("O","O" ,false)<<endl;
    int cases=0;
    while(true){
        cin>>a>>b>>c;
        cases++;
        string cad="";
        if(a=="E" && b=="N" && c=="D") break;
        if(c=="?"){
            bool t = false;
            string a1;
            string b1;
            int da =1, db =1;
            if(a.size()==3){
                a1 = a.substr(0,2);
                da ++ ;
            }else a1 = a.substr(0,1);
            if(b.size()==3){
                b1 = b.substr(0,2);
                db ++ ;
            }else b1 = b.substr(0,1);
            //cout<<a1<<" "<<b<<endl;
           // cout<<a1<<" "<<b1<<endl;
            if(a[da]=='-' && b[db]=='-') t = true;
            if(a1<b1){
                cad = Parents(a1, b1, t);
            }else{
                cad = Parents(b1, a1, t);
            }
            if(a=="O-" && b=="O-"){
                c = cad;
            }else{
                c = "{"+cad.substr(0, cad.size()-2)+"}";
            }
        }else{

            bool t = false;
            if(a=="?"){

                string b1;
                string c1;
                int db=1, dc=1;
                if(b.size()==3){
                    b1 = b.substr(0,2);
                    db ++ ;
                }else b1 = b.substr(0,1);
                if(c.size()==3){
                    c1 = c.substr(0,2);
                    dc ++ ;
                }else c1 = c.substr(0,1);
                if(b[db]=='-' && c[dc]=='+') t = true;
                cad = PH(b1, c1, t);
                if(cad!="IMPOSSIBLE") a = "{"+cad.substr(0, cad.size()-2)+"}";
                else a = cad;
            }else{
                string a1;
                string c1;
                int da=1, dc=1;
                if(a.size()==3){
                    a1 = a.substr(0,2);
                    da ++ ;
                }else a1 = a.substr(0,1);
                if(c.size()==3){
                    c1 = c.substr(0,2);
                    dc ++ ;
                }else c1 = c.substr(0,1);
                if(a[da]=='-' && c[dc]=='+') t = true;
                cad = PH(a1, c1, t);
                if(cad!="IMPOSSIBLE") b = "{"+cad.substr(0, cad.size()-2)+"}";
                else b = cad;
            }
        }
        cout<<"Case "<<cases<<": "<<a<<" "<<b<<" "<<c<<endl;

    }
    return  0;
}
