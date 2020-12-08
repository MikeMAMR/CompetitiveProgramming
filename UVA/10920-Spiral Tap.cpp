#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n;
    long long pos;
    while(scanf("%d %lld", &n, &pos), (n, pos)) {
        int half = n / 2;
        long long c = 1, cont = 1;
        int x, y;
        int xa, ya;
        x = y = half;
        while (true) {
            if (c == pos) {
                xa = x, ya = y;
                break;
            }
            if (pos > c && pos <= c + cont) {
                ya = y;
                xa = x - (pos - c);
                break;
            }
            else {
                x -= cont;
                c += cont;
            }
            if (pos > c && pos <= c + cont) {
                xa = x;
                ya = y - (pos - c);
                break;
            }
            else {
                y -= cont;
                c += cont;
            }
            cont++;
            if (pos > c && pos <= c + cont) {
                ya = y;
                xa = x + (pos - c);
                break;
            }
            else {
                x += cont;
                c += cont;
            }
            if (pos > c && pos <= c + cont) {
                xa = x;
                ya = y + (pos - c);
                break;
            }
            else {
                y += cont;
                c += cont;
            }
            cont++;
        }
        printf("Line = %d, column = %d.\n", n-xa, ya+1);
    }
}

