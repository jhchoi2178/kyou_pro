#include <stdio.h>
#include <stack>
int k;
int x;
std::stack<int> S;
int sum;
int main(){
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		scanf("%d",&x);
		if(x==0) S.pop();
		else S.push(x);
	}
	while(!S.empty()){
		sum += S.top();
		S.pop();
	}
	printf("%d\n",sum);
}