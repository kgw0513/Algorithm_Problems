#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
#include <set>
#include <map>
#pragma warning(disable:4996)
#define nINF -1000000000
#define INF 1000000000

using namespace std;

vector<int>arr;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t, w,mycard=0,yourcard=0,sum=0,maxcard;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> w;
		if (i % 2 == 1)mycard += w;
		else yourcard += w;
		arr.push_back(w);
	}
	maxcard = mycard;
	for (int i = 0; i < t; i++) {
		if (i % 2 == 0) {
			if (yourcard + sum > maxcard)maxcard = yourcard + sum;
			mycard -= arr[i];
			sum += arr[i];
		}
		else {
			if (t % 2 == 0) {
				if (yourcard - arr.back() + sum > maxcard)maxcard = yourcard - arr.back() + sum;
			}
			else {
				if (yourcard + sum > maxcard)maxcard = yourcard + sum;
			}
			yourcard -= arr[i];
		}
	}
	cout << maxcard;
}