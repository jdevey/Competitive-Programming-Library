#include <bits/stdc++.h>

using namespace std;

int rand_discrete(int l, int r) {
	static std::random_device rd;
    static std::mt19937 rng(rd());
    std::uniform_int_distribution<std::mt19937::result_type> dist(l, r);
	return dist(rng);
}

double rand_continuous(double l, double r) {
	std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_real_distribution<> dist(l, r);
	return dist(rng);
}

template<typename T>
void random_shuffle(vector <T>& v) {
	for (int i = v.size() - 1; i > 0; --i) {
		int j = rand_discrete(0, i);
		swap(v[i], v[j]);
	}
}

int main() {
	cout << rand_continuous(-5, 5) << endl;
	vector <int> v({1,2,3,4,5,6,7});
	random_shuffle(v);
	for (auto x : v) {
		cout << x << endl;
	}
	return 0;
}
