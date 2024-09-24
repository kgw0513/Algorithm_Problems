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
#include <bitset>
#include <utility>
#include <assert.h>
//#include <ext/rope>
#pragma warning(disable:4996)
#define f first
#define s second
using namespace std;
//using namespace __gnu_cxx;

const int INF = 2147483647;
const int nINF = 10000000;
const long long MOD = 1000000009;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> intint;
typedef pair<int, double> int_d;
typedef pair<intint, double> int2_d;
typedef pair<int, ll> intlong;
typedef pair<ll, ll> ll_ll;
typedef pair<intint, int> int2_int;
typedef pair<int, char> int_char;

struct Node {
	Node* alpha[26] = {};
	Node* fail_Node = nullptr;
	bool can_make = false;
	void insert(const string &w, int p) {
		assert(p <= w.size());
		if (w.size() == p) {
			can_make = true;
			return;
		}
		if (alpha[w[p] - 'a'] == nullptr)alpha[w[p] - 'a'] = new Node();
		alpha[w[p] - 'a']->insert(w, p + 1);
	}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Node* root = new Node();
	int n;
	string w;
	cin >> n;
	while (n--) {
		cin >> w;
		root->insert(w, 0);
	}
	queue<Node*>arr;
	arr.push(root);
	root->fail_Node = root;
	while (arr.size()) {
		Node* now_s = arr.front();
		arr.pop();
		for (int i = 0; i < 26; i++) {
			if (now_s->alpha[i] == nullptr)continue;

			if (now_s == root) {
				now_s->alpha[i]->fail_Node = root;
			   	 arr.push(now_s->alpha[i]);
				//root에 온거면 어차피 맞는게 없어서 온거니 can_make관리 ㄴㄴ
				continue;
			}

			Node* fail_n = now_s->fail_Node;
			while (fail_n != root && fail_n->alpha[i] == nullptr) {
				fail_n = fail_n->fail_Node;
			}

			if (fail_n->alpha[i] == nullptr) {
				now_s->alpha[i]->fail_Node = root;
			}
			else {
				now_s->alpha[i]->fail_Node = fail_n->alpha[i];
			}

			if (now_s->alpha[i]->fail_Node->can_make)now_s->alpha[i]->can_make = true;
			arr.push(now_s->alpha[i]);
		}
	}

	cin >> n;
	while (n--) {
		cin >> w;
		Node* now_s = root;
		bool find_ans = false;
		for (int i = 0; i < w.size(); i++) {
			while (now_s != root && now_s->alpha[w[i] - 'a'] == nullptr) {
				now_s = now_s->fail_Node;
			}
			if (now_s->alpha[w[i] - 'a'] == nullptr)continue;
			now_s = now_s->alpha[w[i] - 'a'];
			if (now_s->can_make) {
				find_ans = true;
				break;
			}
		}
		if (find_ans)cout << "YES\n";
		else cout << "NO\n";
	}
}
