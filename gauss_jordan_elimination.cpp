ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}

struct Rational {
    ll numer, denom;
    Rational() : numer(0), denom(1) {}
    Rational(const Rational& r) {
        numer = r.numer;
        denom = r.denom;
    }
    explicit Rational(ll n) : numer(n), denom(1) {}
    Rational(ll _numer, ll _denom) : numer(_numer), denom(_denom) {}
    void normalize() {
        ll g = gcd(numer, denom);
        this->numer /= g;
        this->denom /= g;
        if (denom < 0) {
            denom = -denom;
            numer = -numer;
        }
    }
    Rational operator+(const Rational& other) const {
        ll newnumer = numer * other.denom + other.numer * denom;
        ll newdenom = denom * other.denom;
        Rational r(newnumer, newdenom);
        r.normalize();
        return r;
    }
    void operator+=(const Rational& other) {
        auto result = *this + other;
        *this = result;
    }
    Rational operator-(const Rational& other) const {
        ll newnumer = numer * other.denom - other.numer * denom;
        ll newdenom = denom * other.denom;
        Rational r(newnumer, newdenom);
        r.normalize();
        return r;
    }
    void operator-=(const Rational& other) {
        auto result = *this - other;
        *this = result;
    }
    Rational operator*(const Rational& other) const {
        ll newnumer = numer * other.numer;
        ll newdenom = denom * other.denom;
        Rational r(newnumer, newdenom);
        r.normalize();
        return r;
    }
    void operator*=(const Rational& other) {
        auto result = *this * other;
        *this = result;
    }
    Rational operator/(const Rational& other) const {
        ll newnumer = numer * other.denom;
        ll newdenom = denom * other.numer;
        Rational r(newnumer, newdenom);
        r.normalize();
        return r;
    }
    void operator/=(const Rational& other) {
        auto result = *this / other;
        *this = result;
    }
    bool operator<(const Rational& other) const {
        ll mynumer = numer * other.denom;
        ll othernumer = other.numer * denom;
        return mynumer < othernumer;
    }
    bool operator==(const Rational& other) const {
        ll mynumer = numer * other.denom;
        ll othernumer = other.numer * denom;
        return mynumer == othernumer;
    }
    bool operator!=(const Rational& other) const {
        return !(*this == other);
    }
    bool operator>(const Rational& other) const {
        return !(*this == other) && !(*this < other);
    }
    Rational operator-() const {
        Rational r(-numer, denom);
        r.normalize();
        return r;
    }
};

struct Row {
    vector<Rational> row;
    int ord;
    explicit Row(int _ord) : ord(_ord) {}
    Rational& operator[](int ind) {
        return row[ind];
    }
};

void gaussJordanElimination(vector<Row>& matrix) {
    int r = matrix.size();
    int c = matrix[0].row.size();
    for (int i = 0; i < r; ++i) {
        sort(matrix.begin() + i, matrix.end(), [&i](Row& a, Row& b) {
            return (a[i].numer == 0) < (b[i].numer == 0);
        });
        if (matrix[i][i].numer == 0) {
            continue;
        }
        for (int j = 0; j < r; ++j) {
            if (i == j) {
                continue;
            }
            Rational f = -matrix[j][i] / matrix[i][i];
            for (int k = i; k < c; ++k) {
                matrix[j][k] += f * matrix[i][k];
            }
        }
        Rational divFactor = matrix[i][i];
        for (int j = i; j < c; ++j) {
            matrix[i][j] /= divFactor;
        }
    }
}
