#include <bits/stdc++.h>

using namespace std;

class Primes {
	public:
	friend class constructor;
	class constructor {
		public:
		const int MAX = 1e6;
		bool* _sieve;
		int* _smallest_prime_divisor;
		vector <int> _primes;
		constructor() {
			_sieve = new bool[MAX]();
			memset(_sieve, 0, sizeof(*_sieve));
			_smallest_prime_divisor = new int[MAX]();
			memset(_smallest_prime_divisor, 0, sizeof(*_smallest_prime_divisor));
			for (int i = 2; i * i < MAX; ++i) {
                if (!_sieve[i]) {
                    for (int j = i * i; j < MAX; j += i) {
				        _sieve[j] = true;
					    _smallest_prime_divisor[j] = _smallest_prime_divisor[j] ? _smallest_prime_divisor[j] : i;
				    }
                }
			}
			for (int i = 2; i < MAX; ++i) {
				if (!_sieve[i]) {
					_primes.push_back(i);
                    _smallest_prime_divisor[i] = i;
				}
			}
		}
	};
	inline static constructor p;
	static int nth(int i) {
		assert(i < p._primes.size());
		return p._primes[i];
	}
	static map <int, int> factorization(int n) {
		map <int, int> prime_factors;
		while (p._smallest_prime_divisor[n]) {
			++prime_factors[p._smallest_prime_divisor[n]];
			n /= p._smallest_prime_divisor[n];
		}
		return prime_factors;
	}
	static vector <int> factors(int n) {
		vector <int> factors;
		for (int i = 1; i * i <= n; ++i) {
			if (n % i == 0) {
				factors.push_back(i);
				if (i * i != n) factors.push_back(n / i);
			}
		}
		sort(factors.begin(), factors.end());
		return factors;
	}
    static bool isPrime(int n) {
        if (n < p.MAX) {
            return !p._sieve[n];
        }
        int sq = sqrt(n);
        for (int i = 0; p._primes[i] <= sq; ++i) {
            if (n % p._primes[i] == 0) {
                return false;
            }
        }
        return true;
    }
};

int main() {
	auto v = Primes::factors(90);
	for (auto x : v) {
		cout << x << endl;
	}
	return 0;
}

