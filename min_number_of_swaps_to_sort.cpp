// https://www.geeksforgeeks.org/minimum-number-swaps-required-sort-array/
#include <bits/stdc++.h>

using namespace std;

// This works in O(n) for a permutation and O(nlog(n)) generally. 0-based indexing is assumed. Distinct elements are assumed.
// There is another algorithm that uses cycles. It's harder to implement and no faster.
int min_swaps(vector <int>& a, bool is_permutation = false) {
	int n = a.size();
	vector <int> expected, pos(n);
	if (is_permutation) {
		expected.resize(n);
		for (int i = 0; i < n; ++i) {
			expected[i] = i;
		}
	}
	else {
		expected = a;
		sort(expected.begin(), expected.end());
	}
	for (int i = 0; i < n; ++i) {
		pos[a[i]] = i;
	}
	int count = 0;
	for (int i = 0; i < n - 1; ++i) {
		if (a[i] != expected[i]) {
			++count;
			int a_i_copy = a[i];
			swap(a[i], a[pos[expected[i]]]);
			swap(pos[expected[i]], pos[a_i_copy]);
		}
	}
	return count;
}

int main() {
//	vector <int> a = {1, 0, 2, 6, 3, 4, 5};
	vector <int> a = {5, 3, 20, 60, 30, 40, -5};
//	vector <int> a = {1, 0, 2, 5, 6, 3, 4};
//	vector <int> a = {0, 4, 2, 1, 3};
	cout << min_swaps(a) << endl;
	return 0;
}

