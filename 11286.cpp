#include <stdio.h>
#include <queue>
using namespace std;
int n;
int x;
int abs(int x){
	return x>0?x:-x;
}
struct cmp{
	bool operator()(int a,int b){
		if(abs(a)==abs(b)) return a>b;
		return abs(a)>abs(b);
	}
};
int main(){
	scanf("%d",&n);
	priority_queue<int,vector<int>,cmp> pq;
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		if(x==0){
			if(pq.empty()) printf("0\n");
			else{
				printf("%d\n",pq.top());
				pq.pop();
			}
		} else pq.push(x);
	}
}