#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#pragma warning(disable:4996)

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int arr[10] = { 1,1,1,1,1,1,1,1,1,1 };
	int brr[10] = { 1,1,1,1,1,1,1,1,1,1 };
	int crr[1001] = { 0,10, };
	int t, n;
	for (int i = 2; i < 1001; i++) {
		brr[0] = arr[7];
		brr[1] = arr[2] + arr[4];
		brr[2] = arr[1] + arr[3] + arr[5];
		brr[3] = arr[2] + arr[6];
		brr[4] = arr[1] + arr[5] + arr[7];
		brr[5] = arr[2] + arr[4] + arr[6] + arr[8];
		brr[6] = arr[3] + arr[5] + arr[9];
		brr[7] = arr[0] + arr[4] + arr[8];
		brr[8] = arr[5] + arr[7] + arr[9];
		brr[9] = arr[6] + arr[8];
		for (int j = 0; j < 10; j++) {
			crr[i] += (brr[j] %= 1234567);
			arr[j] = brr[j];
		}
		crr[i] %= 1234567;
	}
	cin >> t;
	while (t--) {
		cin >> n;
		cout << crr[n] << "\n";
	}
}