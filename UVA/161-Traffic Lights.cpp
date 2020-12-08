#include <bits/stdc++.h>
using namespace std;
vector<int> q;
bool areGreen(int time)
{
	for (int i = 0; i < q.size(); ++i)
	{
		int sequences = time / q[i];
		if (sequences & 1)
			return false;
		int t = time % q[i];
		if (q[i] - 5 <= t)
			return false;
	}

	return true;
}

int main(){
    int n;
    while(scanf("%d", &n), (n)){
        q.push_back(n);
        int mind = n;
        while(scanf("%d", &n), (n)){
            mind = min(mind, n);
            q.push_back(n);
        }
        bool imposible = true;
        int time = (mind);
        int gt = mind-5;
        while(time<=18000){
            for(int i=0; i<=gt; ++i){
                if(time+i > 18000){
                    time = 18100;
                    break;
                }
                if(areGreen(time+i)){
                    time+=i;
                    imposible = false;
                    break;
                }
            }
            if(!imposible) break;
            time+=(mind);
        }
        if(imposible) cout << "Signals fail to synchronise in 5 hours"<<endl;
        else {
            printf("%02d:%02d:%02d\n", time/3600, time%3600/60, time%60);
        }
        q.clear();
    }
    return 0;
}
