#include <bits/stdc++.h>
using namespace std;
int main(){
    multiset <int> gquiz1;
     gquiz1.insert(10);
     gquiz1.insert(40);
    gquiz1.insert(30);
    gquiz1.insert(60);
    gquiz1.insert(20);
    gquiz1.insert(50);
    gquiz1.insert(50); // 50 will be added again to the multiset unlike set
    gquiz1.insert(10);

    // printing multiset gquiz1

    //gquiz1.erase(50);
    multiset <int> :: iterator it;
    it = gquiz1.begin();
    gquiz1.erase(it);
    it = gquiz1.begin();
    gquiz1.erase(it);

    multiset <int> :: iterator itr;
    cout << "\nThe multiset gquiz1 is : ";
    for (itr = gquiz1.begin(); itr != gquiz1.end(); ++itr)
    {
        cout << '\t' << *itr;
    }
    cout << endl;
    return 0;
}
