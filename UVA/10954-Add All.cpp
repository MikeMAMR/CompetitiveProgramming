#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, a;
    while(scanf("%d", &n), n){
        priority_queue<int, deque<int>, greater<int>> pq;
        for(int i=0; i<n; i++){
            scanf("%d", &a);
            pq.push(a);
        }
        int sum=0, tmp1, tmp2;
        while(pq.size() != 1){
            tmp1 = pq.top();
            pq.pop();
            tmp2 = pq.top();
            pq.pop();
            sum += tmp1 + tmp2;
            pq.push(tmp1 + tmp2);
        }
        printf("%d\n", sum);
    }
    return 0;
}
