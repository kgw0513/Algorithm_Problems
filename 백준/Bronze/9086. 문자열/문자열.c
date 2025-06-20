#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
char w[500];
int main() {
	int n;
	scanf("%d", &n);
	while (scanf("%s", w)!=EOF) {
		printf("%c%c\n", w[0],w[strlen(w)-1]);
	}
}