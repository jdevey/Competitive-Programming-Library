//NOTE: <algorithm>, <cmath>, and <vector> headers needed
void factorLister(vector <int>& completeList, int n) {
	double sq = sqrt(n);
	for (int i = 1; i <= sq; ++i) {
		if (n % i == 0) {
			completeList.push_back(i);
			if (i * i != n) completeList.push_back(n / i);
		}
	}
	sort(completeList.begin(), completeList.end());
}
