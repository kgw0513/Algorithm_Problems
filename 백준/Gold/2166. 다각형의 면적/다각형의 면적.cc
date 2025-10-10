#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <deque>
#include <stack>
#include <cmath>
#include <map>
#pragma warning(disable:4996)

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long a, b, c, d, e, f;
	long long suma = 0, sumb = 0;
	int n;
	cin >> n;
	cin >> a >> b;
	e = a;
	f = b;
	n--;
	while (n--) {
		cin >> c >> d;
		suma += a * d;
		sumb += b * c;
		a = c;
		b = d;
	}
	c = e;
	d = f;
	suma += a * d;
	sumb += b * c;
	a = c;
	b = d;
	//cout << suma << " " << sumb << "\n";
	double sumc = abs(suma - sumb)/2.0;
	printf("%.1lf", sumc);
}