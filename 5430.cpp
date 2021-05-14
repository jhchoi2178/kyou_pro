#include <stdio.h>
#include <deque>
int t;
char a[100010];
char b[500010];
int n;
bool front = true;
bool isError = false;
int main(){
	scanf("%d",&t);
	while(t--){
		for(int i=0;i<=100000;i++){
			a[i] = 0;
		}
		for(int i=0;i<=500000;i++){
			b[i] = 0;
		}
		front = true;
		isError = false;
		std::deque<int> Q;
		scanf("%s",a);
		scanf("%d",&n);
		scanf("%s",b);
		for(int i=0;b[i]!=0;i++){
			if(b[i]>='0'&&b[i]<='9'){
				int t = b[i]-'0';
				while(b[i+1]>='0'&&b[i+1]<='9'){
					t = t*10+(b[i+1]-'0');
					i++;
				}
				Q.push_back(t);
			}
		}
		for(int i=0;a[i]!=0;i++){
			if(a[i]=='R'){
				front = !front;
			} else if(a[i] == 'D'){
				if(Q.empty()){
					isError = true;
					break;
				}
				if(front) Q.pop_front();
				else Q.pop_back();
			}
		}
		if(isError) printf("error\n");
		else {
			printf("[");
			while(!Q.empty()){
				printf("%d",front?Q.front():Q.back());
				front ? Q.pop_front() : Q.pop_back();
				if(!Q.empty()) printf(",");
			}
			printf("]\n");
		}
	}
}
