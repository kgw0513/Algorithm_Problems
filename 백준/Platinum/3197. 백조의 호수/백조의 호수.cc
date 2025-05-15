#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <vector>
#include <deque>
#include <cmath>
#pragma warning(disable:4996)

using namespace std;

struct Node {
	int x = 0;
	int y = 0;
};
struct Node2 {
	int x = 0;
	int y = 0;
	int duck = 0;
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<vector<int>>arr;
	queue<Node*>brr;
	queue<Node2*>crr;
	queue<Node*>drr;
	queue<Node*>err;
	int n, m;
	char w;
	int time = 0;
	int duckcount = 1;
	cin >> n >> m;
	arr.push_back(vector<int>());
	for (int j = 0; j <= m+1; j++) {
		arr[arr.size() - 1].push_back(10);
	}
	for (int i = 1; i <= n; i++) {
		arr.push_back(vector<int>());
		arr[i].push_back(10);
		for (int j = 1; j <= m; j++) {
			cin >> w;
			if (w == '.') {
				arr[i].push_back(0);
			}
			if (w == 'X') {
				arr[i].push_back(9);
			}
			if (w == 'L') {
				arr[i].push_back(duckcount++);
				Node* makeNode = new Node();
				makeNode->x = i;
				makeNode->y = j;
				brr.push(makeNode);
			}
		}
		arr[i].push_back(10);
	}
	arr.push_back(vector<int>());
	for (int j = 0; j <= m + 1; j++) {
		arr[arr.size() - 1].push_back(10);
	}
	time++;
	while (brr.size()) {
		if (arr[brr.front()->x - 1][brr.front()->y] == 0) {
			arr[brr.front()->x - 1][brr.front()->y] = arr[brr.front()->x][brr.front()->y];
			Node* makeNode = new Node();
			makeNode->x = brr.front()->x - 1;
			makeNode->y = brr.front()->y;
			brr.push(makeNode);
		}
		else if (arr[brr.front()->x - 1][brr.front()->y] == 9) {
			arr[brr.front()->x - 1][brr.front()->y] = 11;
			Node2* makeNode2 = new Node2();
			makeNode2->x = brr.front()->x - 1;
			makeNode2->y = brr.front()->y;
			makeNode2->duck = arr[brr.front()->x][brr.front()->y];
			crr.push(makeNode2);
		}

		if (arr[brr.front()->x + 1][brr.front()->y] == 0) {
			arr[brr.front()->x + 1][brr.front()->y] = arr[brr.front()->x][brr.front()->y];
			Node* makeNode = new Node();
			makeNode->x = brr.front()->x + 1;
			makeNode->y = brr.front()->y;
			brr.push(makeNode);
		}
		else if (arr[brr.front()->x + 1][brr.front()->y] == 9) {
			arr[brr.front()->x + 1][brr.front()->y] = 11;
			Node2* makeNode2 = new Node2();
			makeNode2->x = brr.front()->x + 1;
			makeNode2->y = brr.front()->y;
			makeNode2->duck = arr[brr.front()->x][brr.front()->y];
			crr.push(makeNode2);
		}

		if (arr[brr.front()->x][brr.front()->y - 1] == 0) {
			arr[brr.front()->x][brr.front()->y - 1] = arr[brr.front()->x][brr.front()->y];
			Node* makeNode = new Node();
			makeNode->x = brr.front()->x;
			makeNode->y = brr.front()->y - 1;
			brr.push(makeNode);
		}
		else if (arr[brr.front()->x][brr.front()->y - 1] == 9) {
			arr[brr.front()->x][brr.front()->y - 1] = 11;
			Node2* makeNode2 = new Node2();
			makeNode2->x = brr.front()->x;
			makeNode2->y = brr.front()->y - 1;
			makeNode2->duck = arr[brr.front()->x][brr.front()->y];
			crr.push(makeNode2);
		}

		if (arr[brr.front()->x][brr.front()->y + 1] == 0) {
			arr[brr.front()->x][brr.front()->y + 1] = arr[brr.front()->x][brr.front()->y];
			Node* makeNode = new Node();
			makeNode->x = brr.front()->x;
			makeNode->y = brr.front()->y + 1;
			brr.push(makeNode);
		}
		else if (arr[brr.front()->x][brr.front()->y + 1] == 9) {
			arr[brr.front()->x][brr.front()->y + 1] = 11;
			Node2* makeNode2 = new Node2();
			makeNode2->x = brr.front()->x;
			makeNode2->y = brr.front()->y + 1;
			makeNode2->duck = arr[brr.front()->x][brr.front()->y];
			crr.push(makeNode2);
		}
		brr.pop();
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (arr[i][j] == 0) {
				arr[i][j] = 3;
				Node* makeNode2 = new Node();
				makeNode2->x = i;
				makeNode2->y = j;
				drr.push(makeNode2);
				while (drr.size()) {
					if (arr[drr.front()->x - 1][drr.front()->y] == 0) {
						arr[drr.front()->x - 1][drr.front()->y] = arr[drr.front()->x][drr.front()->y];
						Node* makeNode = new Node();
						makeNode->x = drr.front()->x - 1;
						makeNode->y = drr.front()->y;
						//cout << "1x,y:" << makeNode->x << " " << makeNode->y << "\n";
						drr.push(makeNode);
					}
					else if (arr[drr.front()->x - 1][drr.front()->y] == 9) {
						arr[drr.front()->x - 1][drr.front()->y] = arr[drr.front()->x][drr.front()->y];
						Node* makeNode = new Node();
						makeNode->x = drr.front()->x - 1;
						makeNode->y = drr.front()->y;
						//cout << "2x,y:" << makeNode->x << " " << makeNode->y << "\n";
						err.push(makeNode);
					}

					if (arr[drr.front()->x + 1][drr.front()->y] == 0) {
						arr[drr.front()->x + 1][drr.front()->y] = arr[drr.front()->x][drr.front()->y];
						Node* makeNode = new Node();
						makeNode->x = drr.front()->x + 1;
						makeNode->y = drr.front()->y;
						//cout << "3x,y:" << makeNode->x << " " << makeNode->y << "\n";
						drr.push(makeNode);
					}
					else if (arr[drr.front()->x + 1][drr.front()->y] == 9) {
						arr[drr.front()->x + 1][drr.front()->y] = arr[drr.front()->x][drr.front()->y];
						Node* makeNode = new Node();
						makeNode->x = drr.front()->x + 1;
						makeNode->y = drr.front()->y;
						//cout << "4x,y:" << makeNode->x << " " << makeNode->y << "\n";
						err.push(makeNode);
					}
					
					if (arr[drr.front()->x][drr.front()->y - 1] == 0) {
						arr[drr.front()->x][drr.front()->y - 1] = arr[drr.front()->x][drr.front()->y];
						Node* makeNode = new Node();
						makeNode->x = drr.front()->x;
						makeNode->y = drr.front()->y - 1;
						//cout << "5x,y:" << makeNode->x << " " << makeNode->y << "\n";
						drr.push(makeNode);
					}
					else if (arr[drr.front()->x][drr.front()->y - 1] == 9) {
						arr[drr.front()->x][drr.front()->y - 1] = arr[drr.front()->x][drr.front()->y];
						Node* makeNode = new Node();
						makeNode->x = drr.front()->x;
						makeNode->y = drr.front()->y - 1;
						//cout << "6x,y:" << makeNode->x << " " << makeNode->y << "\n";
						err.push(makeNode);
					}

					if (arr[drr.front()->x][drr.front()->y + 1] == 0) {
						arr[drr.front()->x][drr.front()->y + 1] = arr[drr.front()->x][drr.front()->y];
						Node* makeNode = new Node();
						makeNode->x = drr.front()->x;
						makeNode->y = drr.front()->y + 1;
						//cout << "7x,y:" << makeNode->x << " " << makeNode->y << "\n";
						drr.push(makeNode);
					}
					else if (arr[drr.front()->x][drr.front()->y + 1] == 9) {
						arr[drr.front()->x][drr.front()->y + 1] = arr[drr.front()->x][drr.front()->y];
						Node* makeNode = new Node();
						makeNode->x = drr.front()->x;
						makeNode->y = drr.front()->y + 1;
						//cout << "8x,y:" << makeNode->x << " " << makeNode->y << "\n";
						err.push(makeNode);
					}
					drr.pop();
				}
			}
		}
	}
	while (crr.size()) {
		Node* makeNode = new Node();
		makeNode->x = crr.front()->x;
		makeNode->y = crr.front()->y;
		arr[crr.front()->x][crr.front()->y] = crr.front()->duck;
		brr.push(makeNode);
		crr.pop();
	}
	while (err.size()) {
		drr.push(err.front());
		err.pop();
	}
	//cout << "\n";
	while (brr.size()) {
		
		/*
		cout << time << "\n";
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (arr[i][j] == 1 || arr[i][j] == 2)cout << arr[i][j];
				else if (arr[i][j] == 3)cout << ".";
				else if (arr[i][j] == 9)cout << "X";
				else cout << "?";
			}
			cout << "\n";
		}
		cout << "\n";
		*/
		
		while (brr.size()) {
			//cout << brr.front()->x << " " << brr.front()->y <<" "<<arr[brr.front()->x][brr.front()->y]<<"\n";
			if ((arr[brr.front()->x][brr.front()->y] == 2 && arr[brr.front()->x - 1][brr.front()->y] == 1) ||
				(arr[brr.front()->x][brr.front()->y] == 1 && arr[brr.front()->x - 1][brr.front()->y] == 2)) {
				cout << time;
				return 0;
			}
			else if (arr[brr.front()->x - 1][brr.front()->y] == 3&& arr[brr.front()->x][brr.front()->y]!=3) {
				arr[brr.front()->x - 1][brr.front()->y] = arr[brr.front()->x][brr.front()->y];
				Node* makeNode = new Node();
				makeNode->x = brr.front()->x - 1;
				makeNode->y = brr.front()->y;
				brr.push(makeNode);
			}
			else if (arr[brr.front()->x - 1][brr.front()->y] == 9) {
				arr[brr.front()->x - 1][brr.front()->y] = 11;
				Node2* makeNode2 = new Node2();
				makeNode2->x = brr.front()->x - 1;
				makeNode2->y = brr.front()->y;
				makeNode2->duck = arr[brr.front()->x][brr.front()->y];
				crr.push(makeNode2);
			}

			if ((arr[brr.front()->x][brr.front()->y] == 2 && arr[brr.front()->x + 1][brr.front()->y] == 1)||
				(arr[brr.front()->x][brr.front()->y] == 1 && arr[brr.front()->x + 1][brr.front()->y] == 2)) {
				cout << time;
				return 0;
			}
			else if (arr[brr.front()->x + 1][brr.front()->y] == 3 && arr[brr.front()->x][brr.front()->y] != 3) {
				arr[brr.front()->x + 1][brr.front()->y] = arr[brr.front()->x][brr.front()->y];
				Node* makeNode = new Node();
				makeNode->x = brr.front()->x + 1;
				makeNode->y = brr.front()->y;
				brr.push(makeNode);
			}
			else if (arr[brr.front()->x + 1][brr.front()->y] == 9) {
				arr[brr.front()->x + 1][brr.front()->y] = 11;
				Node2* makeNode2 = new Node2();
				makeNode2->x = brr.front()->x + 1;
				makeNode2->y = brr.front()->y;
				makeNode2->duck = arr[brr.front()->x][brr.front()->y];
				crr.push(makeNode2);
			}

			if ((arr[brr.front()->x][brr.front()->y] == 2 && arr[brr.front()->x][brr.front()->y - 1] == 1)||
				(arr[brr.front()->x][brr.front()->y] == 1 && arr[brr.front()->x][brr.front()->y - 1] == 2)) {
				cout << time;
				return 0;
			}
			else if (arr[brr.front()->x][brr.front()->y - 1] == 3 && arr[brr.front()->x][brr.front()->y] != 3) {
				arr[brr.front()->x][brr.front()->y - 1] = arr[brr.front()->x][brr.front()->y];
				Node* makeNode = new Node();
				makeNode->x = brr.front()->x;
				makeNode->y = brr.front()->y - 1;
				brr.push(makeNode);
			}
			else if (arr[brr.front()->x][brr.front()->y - 1] == 9) {
				arr[brr.front()->x][brr.front()->y - 1] = 11;
				Node2* makeNode2 = new Node2();
				makeNode2->x = brr.front()->x;
				makeNode2->y = brr.front()->y - 1;
				makeNode2->duck = arr[brr.front()->x][brr.front()->y];
				crr.push(makeNode2);
			}

			if ((arr[brr.front()->x][brr.front()->y] == 2 && arr[brr.front()->x][brr.front()->y + 1] == 1)||
				(arr[brr.front()->x][brr.front()->y] == 1 && arr[brr.front()->x][brr.front()->y + 1] == 2)) {
				cout << time;
				return 0;
			}
			else if (arr[brr.front()->x][brr.front()->y + 1] == 3 && arr[brr.front()->x][brr.front()->y] != 3) {
				arr[brr.front()->x][brr.front()->y + 1] = arr[brr.front()->x][brr.front()->y];
				Node* makeNode = new Node();
				makeNode->x = brr.front()->x;
				makeNode->y = brr.front()->y + 1;
				brr.push(makeNode);
			}
			else if (arr[brr.front()->x][brr.front()->y + 1] == 9) {
				arr[brr.front()->x][brr.front()->y + 1] = 11;
				Node2* makeNode2 = new Node2();
				makeNode2->x = brr.front()->x;
				makeNode2->y = brr.front()->y + 1;
				makeNode2->duck = arr[brr.front()->x][brr.front()->y];
				crr.push(makeNode2);
			}
			brr.pop();
		}
		while (crr.size()) {
			Node* makeNode = new Node();
			makeNode->x = crr.front()->x;
			makeNode->y = crr.front()->y;
			arr[crr.front()->x][crr.front()->y] = crr.front()->duck;
			brr.push(makeNode);
			crr.pop();
		}
		time++;
		while (drr.size()) {
			//cout << "x,y:" << drr.front()->x << " " << drr.front()->y << "\n";
			if (arr[drr.front()->x - 1][drr.front()->y] == 0) {
				arr[drr.front()->x - 1][drr.front()->y] = arr[drr.front()->x][drr.front()->y];
				Node* makeNode = new Node();
				makeNode->x = drr.front()->x - 1;
				makeNode->y = drr.front()->y;
				drr.push(makeNode);
			}
			else if (arr[drr.front()->x - 1][drr.front()->y] == 9) {
				arr[drr.front()->x - 1][drr.front()->y] = arr[drr.front()->x][drr.front()->y];
				Node* makeNode = new Node();
				makeNode->x = drr.front()->x - 1;
				makeNode->y = drr.front()->y;
				err.push(makeNode);
			}
			if (arr[drr.front()->x + 1][drr.front()->y] == 0) {
				arr[drr.front()->x + 1][drr.front()->y] = arr[drr.front()->x][drr.front()->y];
				Node* makeNode = new Node();
				makeNode->x = drr.front()->x + 1;
				makeNode->y = drr.front()->y;
				drr.push(makeNode);
			}
			else if (arr[drr.front()->x + 1][drr.front()->y] == 9) {
				arr[drr.front()->x + 1][drr.front()->y] = arr[drr.front()->x][drr.front()->y];
				Node* makeNode = new Node();
				makeNode->x = drr.front()->x + 1;
				makeNode->y = drr.front()->y;
				err.push(makeNode);
			}

			if (arr[drr.front()->x][drr.front()->y - 1] == 0) {
				arr[drr.front()->x][drr.front()->y - 1] = arr[drr.front()->x][drr.front()->y];
				Node* makeNode = new Node();
				makeNode->x = drr.front()->x;
				makeNode->y = drr.front()->y - 1;
				drr.push(makeNode);
			}
			else if (arr[drr.front()->x][drr.front()->y - 1] == 9) {
				arr[drr.front()->x][drr.front()->y - 1] = arr[drr.front()->x][drr.front()->y];
				Node* makeNode = new Node();
				makeNode->x = drr.front()->x;
				makeNode->y = drr.front()->y - 1;
				err.push(makeNode);
			}

			if (arr[drr.front()->x][drr.front()->y + 1] == 0) {
				arr[drr.front()->x][drr.front()->y + 1] = arr[drr.front()->x][drr.front()->y];
				Node* makeNode = new Node();
				makeNode->x = drr.front()->x;
				makeNode->y = drr.front()->y + 1;
				drr.push(makeNode);
			}
			else if (arr[drr.front()->x][drr.front()->y + 1] == 9) {
				arr[drr.front()->x][drr.front()->y + 1] = arr[drr.front()->x][drr.front()->y];
				Node* makeNode = new Node();
				makeNode->x = drr.front()->x;
				makeNode->y = drr.front()->y + 1;
				err.push(makeNode);
			}
			drr.pop();
		}
		while (err.size()) {
			drr.push(err.front());
			err.pop();
		}
	}
}