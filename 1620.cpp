#include <string>
#include <cstdio>
#include <set>
#include <map>
#include <functional>
using namespace std;
int n,m;
char a[100010][30];
long long r[20];
std::map<long long,int> S;
long long mod = 100000000003LL;
int string_to_int(char *x){
	int t = 0;
	for(int i=0;x[i]!=0;i++){
		t = t*10+(x[i]-'0');
	}
	return t;
}
long long hash_(char *x){
	long long ret = 0;
	for(int i=0;x[i]!=0;i++){
		if(x[i]>='A'&&x[i]<='Z') ret += (x[i]-'A')*r[i];
		else if(x[i]>='a'&&x[i]<='z') ret+= (x[i]-'a')*r[i];
		ret = ret%mod;
	}
	return ret;
}
int main(){
	r[0] = 1;
	for(int i=1;i<20;i++){
		r[i] = r[i-1]*31LL;
		r[i]%=mod;
	}
	scanf("%d %d\n",&n,&m);
	//a[0] = "Aaaaaaaaaaaaaaaaaaaa";
	for(int i=1;i<=n;i++){
		scanf("%s",a[i]);;
		/*a[i] = a[i-1];
		a[i][19] = a[i-1][19]+1;
		int t = 19;
		while(a[i][t]>'z'){
			a[i][t] -= 26;
			a[i][t-1] ++;
			t--;
		}*/
		//cout << a[i] << endl;
		S[hash_(a[i])] = i;
	}
	char query[30];
	for(int i=0;i<m;i++){
		scanf("%s",query);
		if(query[0]>='0'&&query[0]<='9'){
			printf("%s\n",a[string_to_int(query)]);
		} else {
			auto key = S.find(hash_(query));
			printf("%d\n",key->second);
		}
	}
}