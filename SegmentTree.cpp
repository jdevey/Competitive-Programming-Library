#include <iostream>

using namespace std;

//Organized by sum
class ST {

	int* st = new int[64];
	int sz;

	public:

	ST(int* a, int _sz) {
		//st = new int[sz * 4];
		sz = _sz;
		construct(a, 0, sz - 1, 0);
	}

	~ST() {
		delete st;
	}

	int queryUtil(int ql, int qr, int l, int r, int ind) {
		if (l > qr || r < ql) return 0;
		if (l >= ql && r <= qr) return st[ind];
		return queryUtil(ql, qr, l, (l + r) / 2, ind * 2 + 1) +
			queryUtil(ql, qr, (l + r) / 2 + 1, r, ind * 2 + 2);
	}

	int query(int ql, int qr) {
		queryUtil(ql, qr, 0, sz - 1, 0);
	}

	void updateUtil(int node, int diff, int l, int r, int ind) {
		if (l > node || r < node) return;
		st[ind] += diff;
		if (l == r) return;
		updateUtil(node, diff, l, (l + r) / 2, ind * 2 + 1);
		updateUtil(node, diff, (l + r) / 2 + 1, r, ind * 2 + 2);
	}

	//Change node from current value to value + diff
	//the array 'a' must be the same array that the segment tree was constructed from
	void update(int* a, int node, int val) {
		int diff = val - a[node];
		a[node] = val;
		updateUtil(node, diff, 0, sz - 1, 0);
	}

	void construct(int* a, int l, int r, int ind) {
		if (l == r) {
			st[ind] = a[l];
			return;
		}
		construct(a, l, (l + r) / 2, ind * 2 + 1);
		construct(a, (l + r) / 2 + 1, r, ind * 2 + 2);
		st[ind] = st[ind * 2 + 1] + st[ind * 2 + 2];
	}
};

int main() {

	int a[] = {4, 1, 9, 12, 7, 4, 8, 8, 23, 20, 18, 0, 11, 10, 1, 3};
	int sz = 16;

	ST* segmentTree = new ST(a, sz);

	cout << segmentTree->query(3, 8) << endl; //12 + 7 + 4 + 8 + 8 + 23 = 62
	cout << segmentTree->query(4, 8) << endl;
	cout << segmentTree->query(5, 8) << endl;

	segmentTree->update(a, 5, 6); //Increment the fifth element (4) by 6, making it 10.

	cout << segmentTree->query(3, 8) << endl; //12 + 7 + 10 + 8 + 8 + 23 = 66

	delete segmentTree;

	return 0;
}
