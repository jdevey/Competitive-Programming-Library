// Returns the sum of the elements of the contiguous subarray with the maximum total sum
ll kadane(const int* a, int n) {
	ll grandMax = a[0], currMax = a[0];
	for (int i = 1; i < n, ++i) {
		currMax = a[i] > a[i] + currMax ? a[i] : a[i] + currMax;
		grandMax = grandMax > currMax ? grandMax : currMax;
	}
	return grandMax;
}
