// Cycles through every permutation of an array of chars 's'. A cout statement signifies a point where one would want to record a new permutation.
void heap(char* s, int n, int len) {
	if (n == len) cout << s << endl;
	for (int i = 0; ; ++i) {
		if (n > 2) heap(s, n - 1, len);
		if (i == n - 1) break;
		if (~n & 1) swap(s[i], s[n - 1]);
		else swap(s[0], s[n - 1]);
		cout << s << endl;
	}
}

