/**
 * Returns the value of (base ^ exp) % MD in O(log(exp)) time.
 * 
 * Works by beginning with some arbitrarily large exponent. It first checks to see if the exponent is odd. If so, it must first
 * multiply the final answer by the base, allowing use to consider the exponent as even.
 *
 * We then divide the exponent by two and multiply the base by itself, which produces an equivalent answer since
 * base ^ (2 * exp) = (base * base) ^ (exp).
 *
 * We now have the same problem as we started with, but with an exponent that is half as large, and can therefore repeat this process
 * until the exponent reaches zero.
 *
 * Note that ll denotes a long long.
 */

//Iterative
ll power(ll base, ll exp) {
	ll ans = 1;
	while (exp) {
		if (exp & 1) ans = (ans * base) % MD;
		exp >>= 1;
		base = (base * base) % MD;
	}
	return ans;
}

//Recursive
ll power(ll base, ll exp) {
	return exp ? power(base * base % MD, exp / 2) * (exp & 1 ? base : 1) % MD : 1;
}
