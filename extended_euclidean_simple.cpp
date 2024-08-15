/**
 * Our goal is to rewrite 1 in terms of x and m, each multiplied by a coefficient.
 *
 * We use the euclidean algorithm to approach 1. As we do so, we keep track of the two most recently obtained numbers.
 *
 * The most recent number is given by value1, and value1 can be written as a1 * x + a2 * m.
 *
 * Likewise, the second most recent number is given by value2, and it can be rewritten b1 * x + b2 * m.
 *
 * We stop iterating when we reach 1, and the result will be a1. We add the modululo in case it is negative.
 *
 * REQUIRES THAT X AND M ARE COPRIME; THROWS DIVISION BY ZERO EXCEPTION OTHERWISE
 */
int mminv(int x, int m) {
    int value1 = x, a1 = 1, a2 = 0, value2 = m, b1 = 0, b2 = 1;
    while (value1 > 1) {
        int subtractCnt = value1 / value2;
        value1 %= value2;
        a1 += -subtractCnt * b1;
        a2 += -subtractCnt * b2;
        swap(value1, value2);
        swap(a1, b1);
        swap(a2, b2);
    }
    if (a1 < 0) {
        a1 += m;
    }
    return a1;
}

