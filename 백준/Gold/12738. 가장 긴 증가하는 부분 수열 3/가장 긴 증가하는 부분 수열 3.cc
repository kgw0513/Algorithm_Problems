#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
#include <set>
#pragma warning(disable:4996)

using namespace std;

int ijintamsek(vector<int>&arr,int s, int e, int f) {
	if (arr[e] < f)return -1;
	while (s < e) {
		int mid = (s + e) / 2;
		//cout << arr[mid] << " " << f <<" " <<mid<< "\n";
		if (arr[mid] == f)return 0;
		else if (arr[mid] < f)s = mid + 1;
		else e = mid - 1;
	}
	//cout << arr[e] << " " << f << "\n";
	if (arr[e] == f)return 0;
	else if (arr[e] > f)return e;
	else return e + 1;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int>arr;
	int t, w,k;
	arr.push_back(-1000000001);
	cin >> t;
	t--;
	cin >> w;
	arr.push_back(w);
	while (t--){
		cin >> w;
		k=ijintamsek(arr, 0, arr.size() - 1, w);
		if (k == -1)arr.push_back(w);
		else if (k != 0) {
			arr[k] = w;
		}
		/*
		cout << "k:" << k << "\n";
		for (int i = 0; i < arr.size(); i++) {
			cout << "arr[" << i << "]: " << arr[i] << "\n";
		}
		cout << "\n";
		*/
	}
	/*
	for (int i = 0; i < arr.size(); i++) {
		cout << "arr[" << i << "]: " << arr[i] << "\n";
	}
	*/
	cout << arr.size() - 1;
}