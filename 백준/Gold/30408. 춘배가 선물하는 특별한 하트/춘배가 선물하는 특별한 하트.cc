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
#pragma warning(disable:4996)
#define f first
#define s second
using namespace std;
 
const int INF = 2147483647;
const int nINF = 10000000;
 
typedef long long ll;
typedef pair<int, int> intint;
typedef pair<int, ll> intlong;
typedef pair<intint, int> int2_int;
typedef pair<int, char> int_char;
 
set<ll>arr;
queue<ll>brr;
ll a, b;
bool ans() {
	while (brr.size()) {
		ll h = brr.front();
		brr.pop();
 
		if (arr.find(ll(h / 2)) == arr.end()) {
			arr.insert(ll(h / 2));
			brr.push(ll(h / 2));
		}
		if (h % 2 == 1) {
			if (arr.find(ll(h / 2) + 1) == arr.end()) {
				arr.insert(ll(h / 2) + 1);
				brr.push(ll(h / 2) + 1);
			}
		}
	}
	if (arr.find(b) != arr.end())return true;
	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> a >> b;
	brr.push(a);
	arr.insert(a);
	if (ans())cout << "YES";
	else cout << "NO";
}
