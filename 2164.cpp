#include <stdio.h>
#include <queue>
int n,t;
std::queue<int> Q;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		Q.push(i);
	}
	while(!Q.empty()){
		t = Q.front();
		Q.pop();
		if(Q.empty()){
			printf("%d\n",t);
		} else {
			int x = Q.front();
			Q.pop();
			Q.push(x); 
		}
	}
}