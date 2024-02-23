#define UPLIM 1000001
// Pass a boolean array populated with only zeros. Since sum_1^n[1/n] is approximately n*log(log(n)), this algorithm is quite fast.
void eratos(bool* a) {
	for (int i = 2; i < UPLIM; ++i) for (int j = a[i] ? UPLIM : 2 * i; j < UPLIM; j += i) a[j] = true;
}

