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
pbds c++ set����
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>

multiset�� ���� ������ ���� �ڵ忡�� ������ �ٸ� �Ʒ� �ڵ�� ����.(��� erase�� �����۵� ���� �ʴ´�.)
#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>

�̿ܿ� ������ �ø��� ������ Ÿ�Ժ����ϸ� �ȴ�.
ex. int->ll, less_equal<ll>
*/

constexpr double PI = 3.1415926535;
constexpr long long INF = 2147483647;
constexpr long long lINF = 9000000000000000000;
constexpr long long nlINF = lINF / 10000;
constexpr int nINF = 1007483647;
constexpr unsigned long long MOD1 = 1000000363;
constexpr unsigned long long MOD2 = 1000000007;
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

struct Node 
{
	int Num = -1;
	Node* Left_Node = nullptr;
	Node* Right_Node = nullptr;
	
	void Make_Node(int s, int e) 
	{
		if (s >= e)return;
		Left_Node = new Node();
		Right_Node = new Node();
		Left_Node->Make_Node(s, (s + e) / 2);
		Right_Node->Make_Node((s + e) / 2 + 1, e);
	}

	Node* Update_Node(int s, int e,const int p,const int insert_num) 
	{
		if (p < s || e < p)
			return this;

		Node* New_Node = new Node();

		if (s == e && e == p) {
			New_Node->Num = insert_num;
			return New_Node;
		}
		
		New_Node->Left_Node = this->Left_Node->Update_Node(s, (s + e) / 2, p, insert_num);
		New_Node->Right_Node = this->Right_Node->Update_Node((s + e) / 2 + 1, e, p, insert_num);
		
		New_Node->Num = max(New_Node->Left_Node->Num, New_Node->Right_Node->Num);
		
		return New_Node;
	}

	//{��ġ, ��} ���� ������ {-1,-1}
	intint Find_Num(int s, int e, const int find_num)
	{
		if (Num < find_num)
			return { -1,-1 };

		if (s == e) {
			return { s,Num };
		}

		if (Left_Node->Num >= find_num)
			return Left_Node->Find_Num(s, (s + e) / 2, find_num);

		assert(Right_Node->Num >= find_num);

		return Right_Node->Find_Num((s + e) / 2 + 1, e, find_num);
	}
};

Node* Seg_Node[10002] = {};

//{���� ���� ��ġ, ���� ��� �ð�}
intint Check[102][102][102] = {};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 0; i < 102; i++) 
	{
		for (int j = 0; j < 102; j++) 
		{
			for (int k = 0; k < 102; k++) 
			{
				Check[i][j][k] = { INF,INF };
			}
		}
	}

	int n;
	cin >> n;
	vector<int>arr;

	{ //���� �ð� ���� ���� Ȯ���ؼ� ���������
		int max_time;
		cin >> max_time;

		int last_time = 0;
		int w;
		for (int i = 0; i < n; i++) {
			cin >> w;
			int left_time = w - last_time - 1;
			if (left_time > 0)
				arr.push_back(left_time);
			last_time = w;
		}

		int left_time = max_time - last_time - 1;
		if (left_time > 0)
			arr.push_back(left_time);

		if (arr.empty()) {
			cout << 0;
			return 0;
		}

		Check[0][0][0] = { 0,arr[0] };
	}
	
	Seg_Node[arr.size()] = new Node();
	Seg_Node[arr.size()]->Make_Node(0, int(arr.size()) - 1);
	for (int i = int(arr.size()) - 1; i >= 0; i--) {
		Seg_Node[i] = Seg_Node[i + 1]->Update_Node(0, int(arr.size()) - 1, i, arr[i]);
	}

	int S, M, E;
	cin >> S >> M >> E;
	vector<int>Science(S);
	vector<int>Math(M);
	vector<int>English(E);
	for (int i = 0; i < S; i++) {
		cin >> Science[i];
	}
	for (int i = 0; i < M; i++) {
		cin >> Math[i];
	}
	for (int i = 0; i < E; i++) {
		cin >> English[i];
	}

	/*cout << "�ڸ� ���� :\n";
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << ",";
	}
	cout << "\n";*/

	int ans = 0;
	for (int s = 0; s <= S; s++) {
		for (int m = 0; m <= M; m++) {
			for (int e = 0; e <= E; e++) {
				
				if (Check[s][m][e].fi == INF)
					continue;

				//cout << s << "," << m << "," << e << "�� " << Check[s][m][e].fi << "," << Check[s][m][e].se << "���·� ����.\n";
				//s,m,e�� ���� ���� ���� Ǭ ������ ����

				//���� ���¿��� ���� �Ҷ�
				if (s < S) {
					int now_p = Check[s][m][e].fi;
					int left_time = Check[s][m][e].se;

					int need_time = Science[s];

					if (need_time > left_time) { //���� ���� �ð��� �����ϸ�
						intint h = Seg_Node[now_p + 1]->Find_Num(0, int(arr.size()) - 1, need_time);
						now_p = h.fi;
						left_time = h.se - need_time;
						
						//cout << h.fi << "," << h.se << "���� (����)\n";
					}
					else { //���� ���� �ð��� �˳��ϸ�
						left_time -= need_time;
					}

					//cout << now_p << "," << left_time << "�� ���� (����)\n";

					if (now_p != -1) {
						if (Check[s + 1][m][e].fi > now_p || (Check[s + 1][m][e].fi == now_p && Check[s + 1][m][e].se < left_time))
						{
							Check[s + 1][m][e] = { now_p,left_time };

							ans = max(ans, s + m + e + 1);
							//cout << s + m + e + 1 << "����(����)\n";
						}
					}
				}

				//���� ���¿��� ���� �Ҷ�
				if (m < M) {
					int now_p = Check[s][m][e].fi;
					int left_time = Check[s][m][e].se;

					int need_time = Math[m];

					if (need_time > left_time) { //���� ���� �ð��� �����ϸ�
						intint h = Seg_Node[now_p + 1]->Find_Num(0, int(arr.size()) - 1, need_time);
						now_p = h.fi;
						left_time = h.se - need_time;

						//cout << h.fi << "," << h.se << "���� (����)\n";
					}
					else { //���� ���� �ð��� �˳��ϸ�
						left_time -= need_time;
					}

					//cout << now_p << "," << left_time << "�� ���� (����)\n";

					if (now_p != -1) {
						if (Check[s][m + 1][e].fi > now_p || (Check[s][m + 1][e].fi == now_p && Check[s][m + 1][e].se < left_time))
						{
							Check[s][m + 1][e] = { now_p,left_time };

							ans = max(ans, s + m + e + 1);
							//cout << s + m + e + 1 << "����(����)\n";
						}
					}
				}

				//���� ���¿��� ���� �Ҷ�
				if (e < E) {
					int now_p = Check[s][m][e].fi;
					int left_time = Check[s][m][e].se;

					int need_time = English[e];

					if (need_time > left_time) { //���� ���� �ð��� �����ϸ�
						//cout << need_time << "�̻��� �ʿ���.\n";
						intint h = Seg_Node[now_p + 1]->Find_Num(0, int(arr.size()) - 1, need_time);
						now_p = h.fi;
						left_time = h.se - need_time;

						//cout << h.fi << "," << h.se << "���� (����)\n";

					}
					else { //���� ���� �ð��� �˳��ϸ�
						left_time -= need_time;
					}

					//cout << now_p << "," << left_time << "�� ���� (����)\n";
					
					if (now_p != -1) {
						if (Check[s][m][e + 1].fi > now_p || (Check[s][m][e + 1].fi == now_p && Check[s][m][e + 1].se < left_time))
						{
							Check[s][m][e + 1] = { now_p,left_time };

							ans = max(ans, s + m + e + 1);
							//cout << s + m + e + 1 << "����(����)\n";
						}
					}
				}

				//cout << "\n";
			}
		}
	}

	cout << ans;
}
