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
struct Node {
	int num = 0;
	Node* root;
};
int ijintamsek(vector<Node*>&arr,int s, int e, int f) {
	if (arr[e]->num < f)return -1;
	while (s < e) {
		int mid = (s + e) / 2;
		//cout << arr[mid] << " " << f <<" " <<mid<< "\n";
		if (arr[mid]->num == f)return 0;
		else if (arr[mid]->num < f)s = mid + 1;
		else e = mid - 1;
	}
	//cout << arr[e] << " " << f << "\n";
	if (arr[e]->num == f)return 0;
	else if (arr[e]->num > f)return e;
	else return e + 1;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<Node*>arr;
	int t, w,k;
	Node* startNode1 = new Node();
	startNode1->num = -1000000001;
	arr.push_back(startNode1);
	cin >> t;
	t--;
	cin >> w;
	Node* startNode2 = new Node();
	startNode2->num = w;
	startNode2->root = startNode1;
	arr.push_back(startNode2);
	while (t--){
		cin >> w;
		Node* makeNode = new Node();
		makeNode->num = w;
		k=ijintamsek(arr, 0, arr.size() - 1, w);
		if (k == -1) {
			makeNode->root = arr[arr.size() - 1];
			arr.push_back(makeNode);
		}
		else if (k != 0) {
			makeNode->root = arr[k - 1];
			arr[k] = makeNode;
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
	cout << arr.size() - 1 << "\n";
	stack<int>brr;
	Node* findNode = arr[arr.size() - 1];
	while (findNode->num != -1000000001) {
		brr.push(findNode->num);
		findNode = findNode->root;
	}
	while (brr.size()) {
		cout << brr.top() << " ";
		brr.pop();
	}
}