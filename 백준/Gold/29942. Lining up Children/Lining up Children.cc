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
#include <unordered_set>
#include <unordered_map>
#pragma warning(disable:4996)
#define fi first
#define se second
using namespace std;
/*
rope c++
#include <ext/rope>
using namespace __gnu_cxx;
*/

/*
pbds c++ set전용
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>

multiset을 쓰고 싶으면 위의 코드에서 마지막 줄만 아래 코드로 변경.(대신 erase가 정상작동 되지 않는다.)
#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>

이외에 범위를 늘리고 싶으면 타입변경하면 된다.
ex. int->ll, less_equal<ll>
*/

const long long INF = 2147483647;
const long long lINF = 9000000000000000000;
const long long nlINF = lINF / 100;
const int nINF = 1007483647;
unsigned long long MOD1 = 1000000363;
unsigned long long MOD2 = 1000000007;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<short, short>sh_sh;
typedef pair<int, int> intint;
typedef pair<int, double> int_d;
typedef pair<double, double> dd;
typedef pair<intint, double> int2_d;
typedef pair<int, ll> intlong;
typedef pair<ll, ll> ll_ll;
typedef pair<intint, int> int2_int;
typedef pair<int, intint> int_int2;
typedef pair<ll, ll_ll> ll_ll2;
typedef pair<ll_ll, ll>ll2_ll;
typedef pair<intint, intint> int2_int2;
typedef pair<ll_ll, ll_ll> ll2_ll2;
typedef pair<char, int> char_int;

string inputs[100001];

set<pair<string, string>>check;
map<string, vector<string>>lines;
set<string>use_name;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> inputs[i];
	}
	while (m--) {
		string a, b;
		cin >> a >> b;
		if (a == b)continue;
		if (check.find({ a,b }) != check.end())continue;
		if (check.find({ b,a }) != check.end())continue;
		check.insert({ a,b });
		check.insert({ b,a });
		lines[a].push_back(b);
		lines[b].push_back(a);
	}

	vector<string>ans;
	for (int i = 0; i < n; i++) {
		if (lines[inputs[i]].size() >= 3) {
			cout << "EI SAA";
			return 0;
		}
		if (use_name.find(inputs[i]) != use_name.end())continue;
		if (lines[inputs[i]].size() == 0) {
			use_name.insert(inputs[i]);
			ans.push_back(inputs[i]);
			continue;
		}
		if (lines[inputs[i]].size() >= 2)continue;
		use_name.insert(inputs[i]);
		queue<pair<string,string>>arr;
		arr.push({ inputs[i] ,""});
		while (arr.size()) {
			string now_name = arr.front().fi;
			string last_name = arr.front().se;
			ans.push_back(now_name);
			arr.pop();
			if (lines[now_name].size() >= 3) {
				cout << "EI SAA";
				return 0;
			}

			for (int j = 0; j < lines[now_name].size(); j++) {
				string new_name = lines[now_name][j];
				if (use_name.find(new_name) != use_name.end()) {
					if (new_name != last_name) {
						cout << "EI SAA";
						return 0;
					}
					continue;
				}
				arr.push({ new_name,now_name });
				use_name.insert(new_name);
			}
		}
	}
	if (ans.size() != n) {
		cout << "EI SAA";
		return 0;
	}
	cout << "SAAB\n";
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i];
		if (i + 1 != ans.size())cout << " ";
	}
}