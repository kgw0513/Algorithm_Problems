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
#define INF -1000000000

using namespace std;

struct Node {
	int x = 0;
	int y = 0;
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	queue<Node*>player;
	queue<Node*>fire;
	vector<vector<char>>arr;
	char w;
	int r, c;
	cin >> r >> c;
	for (int i = 0; i <= r + 1; i++) {
		arr.push_back(vector<char>());
		for (int j = 0; j <= c + 1; j++) {
			if (i == 0 || i == r + 1 || j == 0 || j == c + 1)arr[arr.size() - 1].push_back('S');
			else {
				cin >> w;
				arr[arr.size() - 1].push_back(w);
				if (w == 'J') {
					Node* makeNode = new Node();
					makeNode->x = i;
					makeNode->y = j;
					player.push(makeNode);
				}
				else if (w == 'F') {
					Node* makeNode = new Node();
					makeNode->x = i;
					makeNode->y = j;
					fire.push(makeNode);
				}
			}
		}
	}
	int time = 1;
	while (player.size()) {
		int size = player.size();
		while (size--) {
			if (arr[player.front()->x][player.front()->y] == 'J') {
				if (arr[player.front()->x - 1][player.front()->y] == '.') {
					arr[player.front()->x - 1][player.front()->y] = 'J';
					Node* makeNode = new Node();
					makeNode->x = player.front()->x - 1;
					makeNode->y = player.front()->y;
					player.push(makeNode);
				}
				else if (arr[player.front()->x - 1][player.front()->y] == 'S') {
					cout << time;
					return 0;
				}

				if (arr[player.front()->x + 1][player.front()->y] == '.') {
					arr[player.front()->x + 1][player.front()->y] = 'J';
					Node* makeNode = new Node();
					makeNode->x = player.front()->x + 1;
					makeNode->y = player.front()->y;
					player.push(makeNode);
				}
				else if (arr[player.front()->x + 1][player.front()->y] == 'S') {
					cout << time;
					return 0;
				}

				if (arr[player.front()->x][player.front()->y - 1] == '.') {
					arr[player.front()->x][player.front()->y - 1] = 'J';
					Node* makeNode = new Node();
					makeNode->x = player.front()->x;
					makeNode->y = player.front()->y - 1;
					player.push(makeNode);
				}
				else if (arr[player.front()->x][player.front()->y - 1] == 'S') {
					cout << time;
					return 0;
				}

				if (arr[player.front()->x][player.front()->y + 1] == '.') {
					arr[player.front()->x][player.front()->y + 1] = 'J';
					Node* makeNode = new Node();
					makeNode->x = player.front()->x;
					makeNode->y = player.front()->y + 1;
					player.push(makeNode);
				}
				else if (arr[player.front()->x][player.front()->y + 1] == 'S') {
					cout << time;
					return 0;
				}
			}
			player.pop();
		}
		size = fire.size();
		while (size--) {
			if (arr[fire.front()->x - 1][fire.front()->y] == '.' ||
				arr[fire.front()->x - 1][fire.front()->y] == 'J') {
				arr[fire.front()->x - 1][fire.front()->y] = 'F';
				Node* makeNode = new Node();
				makeNode->x = fire.front()->x - 1;
				makeNode->y = fire.front()->y;
				fire.push(makeNode);
			}
			if (arr[fire.front()->x + 1][fire.front()->y] == '.' ||
				arr[fire.front()->x + 1][fire.front()->y] == 'J') {
				arr[fire.front()->x + 1][fire.front()->y] = 'F';
				Node* makeNode = new Node();
				makeNode->x = fire.front()->x + 1;
				makeNode->y = fire.front()->y;
				fire.push(makeNode);
			}
			if (arr[fire.front()->x][fire.front()->y - 1] == '.' ||
				arr[fire.front()->x][fire.front()->y - 1] == 'J') {
				arr[fire.front()->x][fire.front()->y - 1] = 'F';
				Node* makeNode = new Node();
				makeNode->x = fire.front()->x;
				makeNode->y = fire.front()->y - 1;
				fire.push(makeNode);
			}
			if (arr[fire.front()->x][fire.front()->y + 1] == '.' ||
				arr[fire.front()->x][fire.front()->y + 1] == 'J') {
				arr[fire.front()->x][fire.front()->y + 1] = 'F';
				Node* makeNode = new Node();
				makeNode->x = fire.front()->x;
				makeNode->y = fire.front()->y + 1;
				fire.push(makeNode);
			}
			fire.pop();
		}
		time++;
	}
	cout << "IMPOSSIBLE";
	return 0;
}