// first value of returned pair represents the modular multiplicative inverse of a with respect to b
pair<ll, ll> bezoutCoefficients(ll a, ll b) {
    ll q = a / b, s1 = 1, s2 = 0, t1 = 0, t2 = 1, temp;
    while (b > 0) {
        temp = b;
        b = a - q * b;
        a = temp;
        temp = s2;
        s2 = s1 - q * s2;
        s1 = temp;
        temp = t2;
        t2 = t1 - q * t2;
        t1 = temp;
        q = a / max(b, 1LL);
    }
    return {s1, t1};
}
