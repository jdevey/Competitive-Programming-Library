// Gauss Jordan elimination is faster than first implementation

#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
struct Frac {
    ll num;
    ll denom;
    Frac(ll n) {
        num = n;
        denom = 1;
        reduce();
    }
    Frac(ll _num, ll _denom) {
        num = _num;
        denom = _denom;
        reduce();
    }
    void reduce() {
        ll g = __gcd(num, denom);
        num /= g;
        denom /= g;
    }
    Frac operator*(Frac other) {
        assert(denom < (1LL << 32));
        assert(other.denom < (1LL << 32));
        assert(num < (1LL << 32));
        assert(other.num < (1LL << 32));
        other.num *= num;
        other.denom *= denom;
        other.reduce();
        return other;
    }
    void operator*=(Frac other) {
        Frac ret = operator*(other);
        num = ret.num;
        denom = ret.denom;
    }
    Frac operator/(Frac other) {
        assert(denom < (1LL << 32));
        assert(other.denom < (1LL << 32));
        assert(num < (1LL << 32));
        assert(other.num < (1LL << 32));
        other.num *= denom;
        other.denom *= num;
        swap(other.num, other.denom);
        other.reduce();
        return other;
    }
    void operator/=(Frac other) {
        Frac ret = operator/(other);
        num = ret.num;
        denom = ret.denom;
    }
    Frac operator+(Frac other) {
        assert(denom < (1LL << 32));
        assert(other.denom < (1LL << 32));
        ll g = __gcd(denom, other.denom);
        ll lcm = denom * other.denom / g;
        other.num = num * (lcm / denom) + other.num * (lcm / other.denom);
        other.denom = lcm;
        other.reduce();
        return other;
    }
    void operator+=(Frac other) {
        Frac ret = operator+(other);
        num = ret.num;
        denom = ret.denom;
    }
    Frac operator-(Frac other) {
        assert(denom < (1LL << 32));
        assert(other.denom < (1LL << 32));
        ll g = __gcd(denom, other.denom);
        ll lcm = denom * other.denom / g;
        other.num = num * (lcm / denom) - other.num * (lcm / other.denom);
        other.denom = lcm;
        other.reduce();
        return other;
    }
    void operator-=(Frac other) {
        Frac ret = operator-(other);
        num = ret.num;
        denom = ret.denom;
    }
    bool operator==(Frac other) {
        other.reduce();
        reduce();
        return num == other.num && denom == other.denom;
    }
};
 
void solve(vector<vector<Frac>>& mtr) {
    int n = mtr.size();
    for (int i = 0; i < n; ++i) {
        while (mtr[i][i].num == 0) { // Swap rows if current row is zero on the diagonal
            vector<Frac> currRow = mtr[i];
            mtr.erase(mtr.begin() + i);
            mtr.push_back(currRow);
        }
        Frac rowIndex = mtr[i][i];
        for (int j = 0; j <= n; ++j) {
            mtr[i][j] /= rowIndex;
        }
        for (int j = 0; j < n; ++j) {
            if (j == i) {
                continue;
            }
            Frac ratio = mtr[j][i] / mtr[i][i];
            for (int k = 0; k <= n; ++k) {
                mtr[j][k] -= ratio * mtr[i][k];
            }
        }
    }
}
 
int main() {
    Frac a(5, 10);
    Frac b(4, 3);
    Frac c = a * b;
    Frac d = a / b;
    Frac e = a + b;
    cout << c.num << '/' << c.denom << endl;
    cout << d.num << '/' << d.denom << endl;
    cout << e.num << '/' << e.denom << endl;
    vector<vector<Frac>> mtr {
        {3, 2, 1, 10},
        {1, 1, 1, 6},
        {3, 1, 5, 20}
    };
    solve(mtr);
    for (int i = 0; i < mtr.size(); ++i) {
        for (int j = 0; j <= mtr.size(); ++j) {
            Frac f = mtr[i][j];
            cout << f.num << '/' << f.denom << ' ';
        }
        cout << endl;
    }
    return 0;
}
