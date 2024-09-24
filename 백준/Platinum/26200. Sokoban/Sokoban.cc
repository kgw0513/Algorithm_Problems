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
unsigned long long MOD = 1000000007;
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

bool visit[6][6][6][6][6][6][6][6][6][6];
//[box1_x][box1_y][box2_x][box2_y]
//[box3_x][box3_y][box4_x][box4_y]
//[p_x][p_y]

//{'#','.',' '}
deque<string>state;

intint dxdy[4] = { {-1,0},{1,0},{0,-1},{0,1} };

bool change_position(intint& now_p, int arrow) { //아웃바 ㄴㄴ
	assert(0 <= arrow && arrow < 4);
	now_p = { now_p.fi + dxdy[arrow].fi,
	now_p.se + dxdy[arrow].se };
	if (now_p.fi < 0 || now_p.fi >= state.size())return false;
	if (now_p.se < 0 || now_p.se >= state[now_p.fi].size())return false;
	if (state[now_p.fi][now_p.se] == '#')return false;
	return true;
}

bool check_visit(intint& now_p, vector<intint>& boxs) {
	assert(boxs.size() <= 4);
	int a = boxs[0].fi;
	int b = boxs[0].se;
	int c = (boxs.size() >= 2 ? boxs[1].fi : 0);
	int d = (boxs.size() >= 2 ? boxs[1].se : 0);
	int e = (boxs.size() >= 3 ? boxs[2].fi : 0);
	int f = (boxs.size() >= 3 ? boxs[2].se : 0);
	int g = (boxs.size() >= 4 ? boxs[3].fi : 0);
	int h = (boxs.size() >= 4 ? boxs[3].se : 0);
	if (visit[a][b][c][d][e][f][g][h][now_p.fi][now_p.se])return false;
	if (visit[a][b][e][f][c][d][g][h][now_p.fi][now_p.se])return false;
	if (visit[c][d][a][b][e][f][g][h][now_p.fi][now_p.se])return false;
	if (visit[c][d][e][f][a][b][g][h][now_p.fi][now_p.se])return false;
	if (visit[e][f][a][b][c][d][g][h][now_p.fi][now_p.se])return false;
	if (visit[e][f][c][d][a][b][g][h][now_p.fi][now_p.se])return false;
	
	visit[a][b][c][d][e][f][g][h][now_p.fi][now_p.se] = true;
	visit[a][b][e][f][c][d][g][h][now_p.fi][now_p.se] = true;
	visit[c][d][a][b][e][f][g][h][now_p.fi][now_p.se] = true;
	visit[c][d][e][f][a][b][g][h][now_p.fi][now_p.se] = true;
	visit[e][f][a][b][c][d][g][h][now_p.fi][now_p.se] = true;
	visit[e][f][c][d][a][b][g][h][now_p.fi][now_p.se] = true;
	return true;
}

bool is_box_position(intint& now_p, vector<intint>& boxs, intint** find_box) {
	for (int i = 0; i < boxs.size(); i++) {
		if (now_p.fi == boxs[i].fi &&
			now_p.se == boxs[i].se) {
			*find_box = &boxs[i];
			return true;
		}
	}
	return false;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string w;
	/*
	int n;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		getline(cin, w);
		state.push_back(w);
	}
	*/
	while (getline(cin, w)) {
		state.push_back(w);
	}

	state.pop_front();
	state.pop_back();
	for (int i = 0; i < state.size(); i++) {
		state[i].erase(0, 1);
		state[i].pop_back();
	}

	//{boxs,position}
	deque<pair<vector<intint>, pair<int,intint>>>arr;
	vector<intint>start_boxs;
	intint start_p;

	int out_box = 0;
	for (int x = 0; x < state.size(); x++) {
		for (int y = 0; y < state[x].size(); y++) {
			if (state[x][y] == ' ')continue;
			if (state[x][y] == '#')continue;
			if (state[x][y] == '.') {
				continue;
			}
			if (state[x][y] == '@') {
				state[x][y] = ' ';
				start_p = { x,y };
				continue;
			}
			if (state[x][y] == '+') {
				state[x][y] = '.';
				start_p = { x,y };
				continue;
			}
			if (state[x][y] == '$') {
				state[x][y] = ' ';
				start_boxs.push_back({ x,y });
				out_box++;
				continue;
			}
			if (state[x][y] == '*') {
				state[x][y] = '.';
				start_boxs.push_back({ x,y });
				continue;
			}
		}
	}

	if (out_box==0) {
		cout << 0;
		return 0;
	}
    check_visit(start_p,start_boxs);
	arr.push_back({ start_boxs,{out_box,start_p} });
    
	for (int timer = 1; arr.size(); timer++) {
		//cout << timer << "시간.!!!\n";
		int size = arr.size();
		while (size--) {
			//cout << size << "개 남음.\n";
			int now_out_box = arr.front().se.fi;
			intint now_p = arr.front().se.se;
			vector<intint> now_boxs = arr.front().fi;
			arr.pop_front();

			for (int xy = 0; xy < 4; xy++) {
				int new_out_box = now_out_box;
				intint new_p = now_p;
				vector<intint> new_boxs = now_boxs;
				if (!change_position(new_p, xy))continue;

				intint* collision_box = nullptr;
				bool player_push_box = is_box_position(new_p, new_boxs, &collision_box);

				if (!player_push_box) {
					//플레이어가 상자 안 밀때
					//(이땐 어차피 storage에 박스 완성 안되서 확인 x)
					if (!check_visit(new_p, new_boxs))continue;
					arr.push_front({ new_boxs,{new_out_box,new_p} });
					size++;
					continue;
				}

				//플레이어가 상자를 밀때

				intint* trash = nullptr;
				assert(collision_box != nullptr);
				intint new_box_p = *collision_box;
				if (state[new_box_p.fi][new_box_p.se] == '.')new_out_box++;
				//박스가 이동 불가능이면 금지
				//1.벽으로 이동 불가능 할때(또는 불가능한 상황이 주어질때)
				if (!change_position(new_box_p, xy))continue;

				if (state[new_box_p.fi][new_box_p.se] == '.')new_out_box--;
				//2. box가 다른 박스에 막혀 못 밀때
				bool box_push_box = is_box_position(new_box_p, new_boxs, &trash);
				if (box_push_box)continue;
				//여기 왔으면 다른 박스랑 충돌도 안했다는 거

				*collision_box = new_box_p;
				//3.이미 방문한 상태랑 완전 일치할때
				if (!check_visit(new_p, new_boxs))continue;

				if (new_out_box == 0) {
					cout << timer;
					return 0;
				}
				//박스가 storage랑 완전 일치하는지 확인
				arr.push_back({ new_boxs,{new_out_box,new_p} });
				continue;
			}
		}
	}

	//방법이 없다는 뜻
	return -1;
}