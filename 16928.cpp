#include <stdio.h>
#include <queue>
int visit[110];
int a[110];
int n,m;
std::queue<int> Q;

int main(){
	for(int i=1;i<=100;i++){
		a[i] = i;
		visit[i] = -1;
	}
	visit[1] = 0;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		a[x] = y;
	}
	for(int i=0;i<m;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		a[x] = y;
	}
	Q.push(1);
	while(!Q.empty()){
		int cur = Q.front();
		Q.pop();
		if(cur == 100){
			printf("%d\n",visit[cur]);
			return 0;
		}
		for(int i=1;i<=6;i++){
			if(cur+i<=100 && visit[a[cur+i]] == -1){
				visit[a[cur+i]] = visit[cur] + 1;
				Q.push(a[cur+i]);
			}
		}
	}
}