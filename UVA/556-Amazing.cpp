#include <bits/stdc++.h>
using namespace std;
int mat[109][109];
int num[10];
int a, b;
int x, y, d;
void camino() {
	if (d == 0) {
		if (mat[x - 1][y + 1] == -1 && mat[x - 1][y] != -1)
			x--;
		else if (mat[x - 1][y] != -1) {
			x--;
			d = 3;
		} else {
			d++;
			camino();
		}
	} else if (d == 1) {
		if (mat[x - 1][y - 1] == -1 && mat[x][y - 1] != -1)
			y--;
		else if (mat[x][y - 1] != -1) {
			y--;
			d--;
		} else {
			d++;
			camino();
		}
	} else if (d == 2) {
		if (mat[x + 1][y - 1] == -1 && mat[x + 1][y] != -1)
			x++;
		else if (mat[x+1][y]!=-1) {
			x++;
			d--;
		} else {
			d++;
			camino();
		}
	} else if (d == 3) {
		if (mat[x - 1][y+ 1] == -1 && mat[x][y + 1] != -1)
			y++;
		else if (mat[x][y + 1] != -1) {
			y++;
			d--;
		} else {
			d = 0;
			camino();
		}
	}
}
int main() {
    while(scanf("%d%d", &a, &b), (b || a)){
        char s[109][109];
        for(int i=1; i<=a; i++){
            for(int j=1; j<=b; j++){
                scanf(" %c", &s[i][j]);
            }
        }

        for(int i=0; i<=a+1; i++){
            for(int j=0; j<=b+1; j++){
                if(j==0 || i==0 || j>b || i>a || s[i][j]=='1'){
                    mat[i][j] = -1;
                }
            }
        }
        x =a, y =1, d=3;
        do{
            camino();
            mat[x][y]++;
        }while(!(x==a && y==1));
        for(int i=1; i<=a; i++){
            for(int j=1; j<=b; j++){
                if(mat[i][j]==0) num[0]++;
                if(mat[i][j]==1) num[1]++;
                if(mat[i][j]==2) num[2]++;
                if(mat[i][j]==3) num[3]++;
                if(mat[i][j]==4) num[4]++;

            }
        }
        for(int i=0; i<5; i++){
            printf("%3d ", num[i]);
            num[i]=0;
        }

        cout<<endl;
        /*for(int i=0; i<=a+1; i++){
            for(int j=0; j<=b+1; j++){
                mat[i][j]=0;
            }
        }/*
        /*for(int i=0; i<=a+1; i++){
            for(int j=0; j<=b+1; j++){
                printf("%3d", mat[i][j]);
            }
            cout<<endl;
        }*/
    }
	return 0;
}


