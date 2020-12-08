#include <bits/stdc++.h>
using namespace std;
int mcd(int x, int y) {
    int t;
    while(x%y)
        t = x, x = y, y = t%y;
    return y;
}
int cifras(int n) {
    char m[15];
    sprintf(m, "%d", n);
    return strlen(m);
}
int main() {
    int n, a;
    int cases=1;
    while(scanf("%d", &n)!=EOF, n){
        int sum=0;
        bool negative = false;
        for(int i=0; i<n; i++){
            scanf("%d", &a);
            sum+=a;
        }
        if(sum<0){negative = true; sum*=-1;}
        cout<<"Case "<<cases++<<":"<<endl;
        if(sum%n==0){
            if(negative) cout<<"- ";
            cout<<sum/n<<endl;
        }else{
            int res = sum/n;
            if(res==0){
                int tmp = sum%n;
                int p = mcd(tmp,n);
                int c1 = cifras(tmp/p);
                int c2 = cifras(n/p);
                int sal = max(c1,c2)-c1;
                if(negative) sal+=2;
                for(int i=0; i<sal; i++)
                    cout<<" ";
                cout<<tmp/p<<endl;
                if(negative) cout<<"- ";
                for(int i=0; i<max(c1,c2); i++)
                    cout<<"-";
                cout<<endl;
                sal = max(c1,c2)-c2;
                if(negative) sal+=2;
                for(int i=0; i<sal; i++)
                    cout<<" ";

                cout<<n/p<<endl;
            }else{
                int tmp = sum%n;
                int p = mcd(tmp,n);
                int c1 = cifras(tmp/p);
                int c2 = cifras(n/p);
                int nc = cifras(res);
                int sal = nc+max(c1,c2)-c1;
                if(negative) sal+=2;
                for(int i=0; i<sal; i++)
                    cout<<" ";
                cout<<tmp/p<<endl;
                if(negative) cout<<"- ";
                cout<<res;
                for(int i=0; i<max(c1,c2); i++)
                    cout<<"-";
                cout<<endl;
                sal = nc+max(c1,c2)-c2;
                if(negative) sal+=2;
                for(int i=0; i<sal; i++)
                    cout<<" ";

                cout<<n/p<<endl;
            }
        }
    }
    return 0;
}
