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

int brr[1001] = {};
int crr[1001] = {};
struct Node {
	int e = 0;
	int pay = 0;
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<vector<Node*>>arr;
	int n, m, a, b, c;
	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		arr.push_back(vector<Node*>());
		brr[i] = -1;
	}
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		Node* makeNode = new Node();
		makeNode->e = b;
		makeNode->pay = c;
		arr[a].push_back(makeNode);
	}
	cin >> a >> b;
	brr[a] = 0;
	while (a != b) {
		crr[a] = 1;
		for (int i = 0; i < arr[a].size(); i++) {
			if (brr[arr[a][i]->e] == -1) {
				brr[arr[a][i]->e] = brr[a] + arr[a][i]->pay;
			}
			else {
				brr[arr[a][i]->e] = min(brr[arr[a][i]->e], brr[a] + arr[a][i]->pay);
			}
		}
		c = -1;
		//cout << a << "에서\n";
		for (int i = 1; i <= n; i++) {
			//cout << "brr[" << i << "] :" << brr[i] << " ";
			if (!crr[i] && (c == -1 || c > brr[i])&&brr[i]!=-1) {
				a = i;
				c = brr[i];
			}
		}
		//cout << "\na:" << a << "선정.\n";
	}
	cout << brr[b];
}