#include <queue>
#include <stdio.h>
#include <functional>
using namespace std;
int n;
priority_queue<int> Q;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		if(x==0){
			if(Q.empty()) printf("0\n");
			else{ 
				printf("%d\n",Q.top());
				Q.pop();
			}
		} else {
			Q.push(x);
		}
	}
}