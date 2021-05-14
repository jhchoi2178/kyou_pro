#include <stdio.h>

int t,k;
char op[2];
int x;
int h[1000010];
int len = 0;
void init(){
	for(int i=0;i<1000010;i++){
		h[i] = 0;
	}
	len = 1;
}
void insert(int x){
	int cur = ++len;
	if(len%2&&x<h[len-1]){
		h[len] = h[len-1];
		cur--;
	}
	bool done = false;

	while(!done && cur >= 4){
		int gp = cur/4;
		int lcgp = 2 * gp;
		int rcgp = 2 * gp + 1;
		if(x < h[lcgp]){
			h[cur] = h[lcgp];
			cur = lcgp;
		} else if( x > h[rcgp]) {
			h[cur] = h[rcgp];
			cur = rcgp;
		} else done = true;
	}
	h[cur] = x;
}
void heapify(int cur){
	if(cur%2){
		if(h[cur-1]>h[cur]){
			int temp = h[cur];
			h[cur] = h[cur-1];
			h[cur-1] = temp;
		}
		int max_node = cur;
		if(2*cur+1 <= len && h[2*cur+1] > h[max_node] ) max_node = 2*cur+1;
		if(2*cur-1 <= len && h[2*cur-1] > h[max_node]) max_node = 2*cur-1;
		if(max_node == cur) return;
		int temp = h[cur];
		h[cur] = h[max_node];
		h[max_node] = temp;
		heapify(max_node);
	} else {
		if(cur+1<=len && h[cur]>h[cur+1]){
			int temp = h[cur];
			h[cur] = h[cur+1];
			h[cur+1] = temp;
		}
		int min_node = cur;
		if(2*cur <= len && h[2*cur] < h[min_node] ) min_node = 2*cur;
		if(2*cur+2 <= len && h[2*cur+2] < h[min_node]) min_node = 2*cur+2;
		if(min_node == cur) return;
		int temp = h[cur];
		h[cur] = h[min_node];
		h[min_node] = temp;
		heapify(min_node);
	}
}
int find_min(){
	return h[2];
}
int find_max(){
	if(len>2) return h[3];
	return h[2];
}
void delete_min(){
	if(len<2) return;
	h[2] = h[len];
	len--;
	if(len>1) heapify(2);
}
void delete_max(){
	if(len < 2) return;
	if(len <= 3){
		len--;
	} else {
		h[3] = h[len];
		len--;
		heapify(3);
	}
}
bool isEmpty(){
	return len<2;
}
int main(){
	scanf("%d",&t);
	while(t--){
		init();
		scanf("%d",&k);
		for(int i=0;i<k;i++){
			scanf("%s %d",op,&x);
			if(op[0]=='I'){
				insert(x);
			} else{
				if(x==1){
					delete_max();
				} else if(x==-1){
					delete_min();
				}
			}
		}
		if(isEmpty()) printf("EMPTY\n");
		else{
			printf("%d %d\n",find_max(),find_min());
		}
	}
}