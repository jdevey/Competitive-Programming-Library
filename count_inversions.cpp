#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// Merge sort
pair <vector <int>, ll> count_inversions(vector <int>& a, int l, int r) {
    if (l == r) {
        return {{a[l]}, 0};
    }
    const int INF = 1e9 + 1;
    vector <int> sorted;
    int mid = (l + r) / 2;
    auto r1 = count_inversions(a, l, mid);
    auto r2 = count_inversions(a, mid + 1, r);
    ll count = r1.second + r2.second;
    int pt1 = 0, pt2 = 0, sz1 = r1.first.size(), sz2 = r2.first.size();
    while (!(pt1 == sz1 && pt2 == sz2)) {
        int v1 = pt1 == sz1 ? INF : r1.first[pt1];
        int v2 = pt2 == sz2 ? INF : r2.first[pt2];
        if (v2 < v1) {
            count += sz1 - pt1;
            ++pt2;
            sorted.push_back(v2);
        }
        else {
            ++pt1;
            sorted.push_back(v1);
        }
    }
    return {sorted, count};
}

ll count_inversions(vector <int>& a) {
    return count_inversions(a, 0, a.size() - 1).second;
}

int main() {
//    vector <int> a = {1, 0, 2, 6, 3, 4, 5};
	vector <int> a = {0, 4, 2, 1, 3};
    cout << count_inversions(a) << endl;
    return 0;
}
