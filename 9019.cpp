#include <stdio.h>
#include <queue>
#include <stack>
using namespace std;
int visit[10010];
char ans[10010];
int t,a,b;
int mod = 1e4;

int main(){
	scanf("%d",&t);
	for(int i=0;i<10000;i++){
		visit[i] = t;
	}
	while(t--){
		for(int i=0;i<10000;i++){
			visit[i] = -1;
		}
		queue<int> Q;
		scanf("%d %d",&a,&b);
		Q.push(a);
		visit[a] = 0;
		while(!Q.empty()){
			int cur = Q.front();
			Q.pop();
			if(cur==b){
				int back = cur;
				stack<char> S;
				while(back!=a){
					S.push(ans[back]);
					if(ans[back] == 'D'){
						if(visit[back/2] == visit[back] - 1){
							back /= 2;
						} else {
							back = (back+10000)/2;
						}
					} else if(ans[back] == 'S'){
						back = (back+1)%mod;
					} else if(ans[back] == 'L'){
						back = (back%10)*1000+back/10;
					} else if(ans[back] == 'R'){
						back = (back*10+back/1000)%mod;
					}
				}
				while(!S.empty()){
					printf("%c",S.top());
					S.pop();
				}
				puts("");
				break;
			}
			int nt[4] = {(cur*2)%mod,(cur+9999)%mod,(cur*10+cur/1000)%mod,(cur%10)*1000+cur/10};
			char nt_c[4] = {'D','S','L','R'};
			for(int i=0;i<4;i++){
				if(visit[nt[i]] == -1){
					visit[nt[i]] = visit[cur] + 1;
					Q.push(nt[i]);
					ans[nt[i]] = nt_c[i];
				}
			}
		}
	}
}