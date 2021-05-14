#include <stdio.h>
#include <queue>
std::queue<int> Q;
int n,k;
int main(){
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		Q.push(i);
	}
	int cnt = 0;
	printf("<");
	while(!Q.empty()){
		int t = Q.front();
		Q.pop();
		cnt ++;
		if(cnt == k){
			printf("%d",t);
			if(Q.empty()){
				printf(">");
			} else {
				printf(", ");
			}
			cnt = 0;
		} else {
			Q.push(t);
		}
	}
}