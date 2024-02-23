#include <iostream>

using namespace std;

class ST {
	ll* st;
	int sz;

	public:
	ST(int* a, int _sz) : sz(_sz) {
		st = new ll[sz * 4];
		construct(a, 0, sz - 1, 0);
	}

	~ST() {
		delete st;
	}

	int queryUtil(int ql, int qr, int l, int r, int ind) {
		if (l > qr || r < ql) return 0;
		if (l >= ql && r <= qr) return st[ind];
		return combine(queryUtil(ql, qr, l, (l + r) / 2, ind * 2 + 1),
			queryUtil(ql, qr, (l + r) / 2 + 1, r, ind * 2 + 2));
	}

	int query(int ql, int qr) {
		return queryUtil(ql, qr, 0, sz - 1, 0);
	}

	void updateUtil(int node, int combineValue, int l, int r, int ind) {
		if (l > node || r < node) return;
		st[ind] = combine(st[ind], combineValue);
		if (l == r) return;
		updateUtil(node, combineValue, l, (l + r) / 2, ind * 2 + 1);
		updateUtil(node, combineValue, (l + r) / 2 + 1, r, ind * 2 + 2);
	}

	void update(int node, int combineValue) {
		updateUtil(node, combineValue, 0, sz - 1, 0);
	}

	void construct(int* a, int l, int r, int ind) {
		if (l == r) {
			st[ind] = a[l];
			return;
		}
		construct(a, l, (l + r) / 2, ind * 2 + 1);
		construct(a, (l + r) / 2 + 1, r, ind * 2 + 2);
		st[ind] = combine(st[ind * 2 + 1], st[ind * 2 + 2]);
	}

    ll combine(ll a, ll b) {
        return a + b; // Modify as desired
    }
};

int main() {

	int a[] = {4, 1, 9, 12, 7, 4, 8, 8, 23, 20, 18, 0, 11, 10, 1, 3};
	int sz = 16;

	ST* segmentTree = new ST(a, sz);

	cout << segmentTree->query(3, 8) << endl; //12 + 7 + 4 + 8 + 8 + 23 = 62
	cout << segmentTree->query(4, 8) << endl; //7 + 4 + 8 + 8 + 23 = 50
	cout << segmentTree->query(5, 8) << endl; //4 + 8 + 8 + 23 = 43

	segmentTree->update(a, 5, 2); //Change the fifth element (4) to 6

	cout << segmentTree->query(3, 8) << endl; //12 + 7 + 6 + 8 + 8 + 23 = 64

	delete segmentTree;

	return 0;
}
