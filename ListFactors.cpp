void factorLister(vector <int>& completeList, int n) {
	for (int i = 1; i * i <= n; ++i) {
		if (n % i == 0) {
			completeList.push_back(i);
			if (i * i != n) completeList.push_back(n / i);
		}
	}
	sort(completeList.begin(), completeList.end());
}
