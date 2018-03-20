ll euclidean(ll n, ll m) {
	return !m ? n : euclidean(m, n % m);
}
