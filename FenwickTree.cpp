#include <iostream>

using namespace std;

int query(int* fTree, int left, int right) {
	++right;
	int sum = 0;
	while (right > 0) {
		sum += fTree[right - 1];
		right -= right & -right; //obtain the least-significant set bit of 'right'
	}
	if (left != 0) {
		while (left > 0) {
			sum -= fTree[left - 1];
			left -= left & -left;
		}
	}
	return sum;
}

// val represents the amount by which the value at 'ind' will increase
void update(int* fTree, int sz, int ind, int val) {
	++ind;
	while (ind <= sz) {
		fTree[ind - 1] += val;
		ind += ind & -ind;
	}
}

void construct(int* fTree, const int* arr, int sz) {
	for (int i = 0; i < sz; ++i) update(fTree, sz, i, arr[i]);
}

int main() {

	int a[] = {1, 6, 4, 7, 23, 7, 45, 9, 20, 11, 3, 0, 6, 4, 78, 77, 5, 2, 43, 21};
	int sz = 20; //Number of elements in the array

	int fTree[sz] = {};
	construct(fTree, a, sz);

	cout << query(fTree, 4, 7) << endl;
	update(fTree, sz, 5, 20);
	cout << query(fTree, 4, 7) << endl;
	update(fTree, sz, 4, 6);
	cout << query(fTree, 4, 7) << endl;

	return 0;
}

