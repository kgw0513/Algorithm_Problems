#include <iostream>
#include <vector>

using namespace std;


struct SegmentTree {
	int N;
	vector<int> tree;

	int merge(int left, int right) {
		if (left == 0 && right == 0)return 0;
		else if (left == 0)return right;
		else if (right == 0)return left;
		else return min(left, right);
	}

	int buildRec(const int arr[], int node, int nodeLeft, int nodeRight) {
		if (nodeLeft == nodeRight) {
			return tree[node] = arr[nodeLeft];
		}

		int mid = (nodeLeft + nodeRight)/2;
		int leftVal = buildRec(arr, node * 2, nodeLeft, mid);
		int rightVal = buildRec(arr, node * 2 + 1, mid + 1, nodeRight);

		return tree[node] = merge(leftVal, rightVal);
	}

	void build(const int arr[], int size) {
		N = size;
		tree.resize(N * 4);

		buildRec(arr, 1, 0, N - 1);
	}

	int queryRec(int left, int right, int node, int nodeLeft, int nodeRight) {
		if (right < nodeLeft || nodeRight < left) {
			return 0;
		}

		if (left <= nodeLeft && nodeRight <= right) {
			return tree[node];
		}
		
		int mid = (nodeLeft + nodeRight) / 2;
		return merge(queryRec(left, right, node * 2, nodeLeft, mid), queryRec(left, right, node * 2 + 1, mid + 1, nodeRight));
	}

	int query(int left, int right) {
		return queryRec(left, right, 1, 0, N - 1);
	}

	int updateRec(int index, int newValue, int node, int nodeLeft, int nodeRight) {
		if (index < nodeLeft || nodeRight < index) {
			return tree[node];
		}
		if (nodeLeft == nodeRight) {
			return tree[node] = newValue;
		}

		int mid = (nodeLeft + nodeRight) / 2;
		int leftVal = updateRec(index, newValue, node * 2, nodeLeft, mid);
		int rightVal = updateRec(index, newValue, node * 2 + 1, mid + 1, nodeRight);
	
		return tree[node] = merge(leftVal, rightVal);
	}

	int update(int index, int newValue) {
		return updateRec(index, newValue, 1, 0, N - 1);
	}
};

class NumArray {
	SegmentTree segTree;
public:
	NumArray(vector<int>& nums) {
		segTree.build(nums.data(), int(nums.size()));
	}

	void update(int i, int val) {
		segTree.update(i, val);
	}

	int sumRange(int i, int j) {
		return segTree.query(i, j);
	}

	void showseg() {
		for (int i = 0; i < segTree.tree.size(); i++) {
			cout << segTree.tree[i] << " ";
		}
		cout << endl;
	}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m,w, a, b;
	cin >> n >> m;
	vector<int>arr;
	for (int i = 0; i < n; i++) {
		cin >> w;
		arr.push_back(w);
	}

	NumArray A(arr);

	//A.showseg();

	for (int i = 0; i < m; i++) {
		cin >> a >> b;

		cout << A.sumRange(a - 1, b - 1) << "\n";
		//A.showseg();
	}

}