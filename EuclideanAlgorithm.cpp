int gcd(int n, int m) {
	return m ? gcd(m, n % m) : n;
}

