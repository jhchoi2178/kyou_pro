#include <stdio.h>

int m;
int s[21];
char a[15];
int x;
int main(){
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%s",a);
		if(a[0]=='a'){
			if(a[1]=='d'){
				scanf("%d",&x);
				s[x] = 1;
			} else if(a[1] == 'l'){
				for(int i=1;i<=20;i++){
					s[i] = 1;
				}
			}
		} else if(a[0]=='r'){
			scanf("%d",&x);
			s[x] = 0;
		} else if(a[0]=='c'){
			scanf("%d",&x);
			printf("%d\n",s[x]);
		} else if(a[0]=='t'){
			scanf("%d",&x);
			s[x] = !s[x];
		} else if(a[0]=='e'){
			for(int i=1;i<=20;i++){
				s[i] = 0;
			}
		}
	}
}
