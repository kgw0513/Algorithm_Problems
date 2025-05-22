#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <cmath>
#pragma warning(disable:4996)

using namespace std;

int num[100001] = {};
deque<int>arr;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int s, e;
	cin >> s >> e;
	num[s]++;
	if (s < e) {
		bool find = false;
		arr.push_back(s);
		int time = 0;
		while (arr.size()) {
			int size = arr.size();
			while (size--) {
				//cout << "arr:" << arr.front() << "\n";
				if (arr.front() == e) {
					find = true;
					break;
				}
				if (0 < arr.front() && num[arr.front() - 1] == 0) {
					if (arr.front() == 0) {
						num[arr.front() - 1] = -1;
					}
					else  num[arr.front() - 1] = arr.front();
					arr.push_back(arr.front() - 1);
				}
				if (arr.front() < 100000 && num[arr.front() + 1] == 0) {
					if (arr.front() == 0) {
						num[arr.front() + 1] = -1;
					}
					else num[arr.front() + 1] = arr.front();
					arr.push_back(arr.front() + 1);
				}
				if (arr.front() * 2 <= 100000 && num[arr.front() * 2] == 0) {
					if (arr.front() == 0) {
						num[arr.front() * 2] = -1;
					}
					else num[arr.front() * 2] = arr.front();
					arr.push_back(arr.front() * 2);
				}
				arr.pop_front();
			}
			if (find)break;
			//cout << "\n";
			time++;
		}
		cout << time << "\n";
		while (arr.size()) {
			arr.pop_front();
		}
		while (1) {
			arr.push_front(e);
			if (e == s)break;
			if (num[e] == -1) {
				e = 0;
			}
			else e = num[e];
		}
		while (arr.size()) {
			cout << arr.front() << " ";
			arr.pop_front();
		}
	}
	else {
		cout << s - e << "\n";
		for (int i = s; i >= e; i--) {
			cout << i << " ";
		}
	}
}