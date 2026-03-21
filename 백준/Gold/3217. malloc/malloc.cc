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
//#include <ext/rope>
#pragma warning(disable:4996)
#define f first
#define s second
using namespace std;
//using namespace __gnu_cxx;

const long long INF = 2147483647;
const long long lINF = 9000000000000000000;
const int nINF = 1000000000;
unsigned long long MOD = 1000000007;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<short, short>sh_sh;
typedef pair<int, int> intint;
typedef pair<int, double> int_d;
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

int transform(string w) {
	if (w[0] == 'f' && w[1] == 'r' && w[2] == 'e' && w[3] == 'e')return 2;
	else if (w[0] == 'p' && w[1] == 'r' && w[2] == 'i' && w[3] == 'n' && w[4] == 't')return 3;
	return 1;
}

int get_number(string w) {
	int p = 0;
	while (w[p] != '(')p++;
	p++;
	int num = 0;
	while (w[p] != ')') {
		num *= 10;
		num += (w[p] - '0');
		p++;
	}
	return num;
}

string get_name(string w) {
	int p = 0;
	while (w[p] != '(')p++;
	p++;
	string name = "";
	while (w[p] != ')') {
		name += w[p];
		p++;
	}
	return name;
}

string get_num_name(string w) {
	int p = 0;
	string name = "";
	while (w[p] != '=') {
		name += w[p];
		p++;
	}
	return name;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	string w;
	cin >> n;
	map<int,int>start;//{start,end}
	map<int, int>end;//{end,start}
	map<string, intint>rem;
	start.insert({1,100000});

	int dummy_data = 1;
	while (n--) {
		cin >> w;
		int a = transform(w);
		if (a == 1) {//만들기
			int b = get_number(w);
			string c = get_num_name(w);
			if (rem.find(c) != rem.end()) {
				string h1 = c;
				int h2 = rem[h1].f;
				int h3 = rem[h1].s;
				rem.erase(h1);
				h1 = to_string(dummy_data++);
				rem.insert({ h1,{h2,h3} });
			}
			int find_p = 0;
			for (auto i = start.begin(); i != start.end(); i++) {
				if (i->s - i->f + 1 >= b) {
					find_p = i->f;
					break;
				}
			}

			if (find_p != 0) {
				int p_end = start[find_p];
				start.erase(find_p);
                end.erase(p_end);
				rem.insert({ c,{find_p,find_p + b - 1} });
				//cout << c << ":" << find_p << "~" << find_p + b - 1 << "\n";
				if (find_p + b <= p_end) {
				    start.insert({ find_p + b,p_end });
				    end.insert({ p_end,find_p + b });
                }
			}
		}
		else if (a == 2) {//할당 해제
			string b = get_name(w);
			if (rem.find(b) == rem.end())continue;
			int recover_s = rem[b].f;
			int recover_e = rem[b].s;
			rem.erase(b);
			if (end.find(recover_s - 1) != end.end()) {
				int h = end[recover_s - 1];
				end.erase(recover_s - 1);
				start.erase(h);
				recover_s = h;
			}
			if (start.find(recover_e + 1) != start.end()) {
				int h = start[recover_e + 1];
				start.erase(recover_e + 1);
				end.erase(h);
				recover_e = h;
			}
			start.insert({ recover_s,recover_e });
			end.insert({ recover_e,recover_s });
		}
		else {//출력
			w = get_name(w);
			if (rem.find(w) == rem.end())cout << "0\n";
			else cout << rem[w].f << "\n";
		}
	}
}