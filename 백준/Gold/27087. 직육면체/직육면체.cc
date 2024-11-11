#include <iostream>
int main() {
	int t,a,b,c,p;
    scanf("%d",&t);
	while (t--) {
		scanf("%d %d %d %d",&a,&b,&c,&p);
		int cal = (a % p == 0) + (b % p == 0) + (c % p == 0);
		printf("%c\n", "01"[cal >= 2]);
	}
}