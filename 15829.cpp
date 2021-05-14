#include <iostream>
#include <string>
using namespace std;
int l;
string a;
long long m =1234567891;
long long r = 31;
long long k[52];
long long sum;
int main(){
	cin>>l;
	cin>>a;
	k[0] = 1;
	for(int i=1;i<l;i++){
		k[i] = (k[i-1]*r)%m;
	}
	for(int i=0;i<a.length();i++){
		sum += ((long long)(a[i]-'a'+1)*k[i]);
		sum %= m;
	}
	printf("%lld\n",sum);
}