#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
char w[18];
int main() {
	int n;
	scanf("%d", &n);
	getchar();
	while (n--) {
		fgets(w, sizeof(w), stdin);
        int i=0;
        printf("%c",w[0]);
        for(i=0;('A'<=w[i] && w[i]<='Z');i++){
            
        }
        printf("%c\n",w[i-1]);
		memset(w, 0, sizeof(w));
	}
}