#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
char w[5];
int main() {
	int n;
	scanf("%d", &n);
	while (scanf("%s", w)!=EOF) {
		printf("%c", w[0]);
		int i = 0;
		for (i = 0; w[i] != '\0'; i++) {
		}
		printf("%c\n", w[i - 1]);
	}
}