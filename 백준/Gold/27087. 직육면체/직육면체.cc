#include <iostream>
int main() {
	int t,a,b,c,p;
    scanf("%d",&t);
	while (t--) {
		scanf("%d %d %d %d",&a,&b,&c,&p);
		printf("%c\n","01"[!(a%p)+!(b%p)+!(c%p)>= 2]);
	}
}