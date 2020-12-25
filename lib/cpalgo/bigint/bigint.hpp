#pragma once

#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>

class bigint {
    static const int L = 8, BASE = 1e8;
    bool negative;
    std::vector<int> a;
    bigint& normalize();
public:
    bigint(int x = 0);
    // Copy
    bigint& operator=(const bigint& x);
    bigint& operator=(int x);
    // Compare
    const bool operator<(const bigint& x) const;
    const bool operator>(const bigint& x) const;
    const bool operator<=(const bigint& x) const;
    const bool operator>=(const bigint& x) const;
    const bool operator!=(const bigint& x) const;
    const bool operator==(const bigint& x) const;
    // Arithmetic
    bigint operator-() const;
    bigint& operator+=(const bigint& x);
    bigint& operator-=(const bigint& x);
    bigint& operator*=(const bigint& x);
    bigint& operator/=(const bigint& x);
    bigint& operator%=(const bigint& x);
    const bigint operator+(const bigint& x) const;
    const bigint operator-(const bigint& x) const;
    const bigint operator*(const bigint& x) const;
    const bigint operator/(const bigint& x) const;
    const bigint operator%(const bigint& x) const;
    const bigint abs() const;
    const std::pair<bigint,bigint> divmod(const bigint& x) const;
    // Digit-wise
    int digits() const;
    int operator[](int idx) const;
    int trailing_zeros() const;
    // IO
    static bigint parse(const std::string& s);
    friend std::istream& operator>>(std::istream& is, bigint& x);
    friend std::ostream& operator<<(std::ostream& os, const bigint& x);
    friend std::string to_string(const bigint& value);
};

bigint::bigint(int x) : negative(x<0) {
    x = std::abs(x);
    for (; x > 0; x /= BASE) {
        a.push_back(x % BASE);
    }
}
bigint& bigint::normalize() {
    int i = a.size()-1;
    while (i >= 0 && a[i] == 0) --i;
    a.resize(i+1);
    if (a.size() == 0) negative = false;
    return *this;
}

//
// Copy
//
bigint& bigint::operator=(const bigint& x) {
    negative = x.negative;
    a = x.a;
    return *this;
}
bigint& bigint::operator=(int x) {
    return *this = bigint(x);
}

//
// Compare
//
const bool bigint::operator<(const bigint& x) const {
    if (negative != x.negative) {
        return negative < x.negative;
    }
    if (a.size() != x.a.size()) {
        return (a.size() < x.a.size()) ^ negative;
    }
    for (int i = a.size() - 1; i >= 0; --i) {
        if (a[i] != x.a[i]) {
            return (a[i] < x.a[i]) ^ negative;
        }
    }
    return false;
}
const bool bigint::operator>(const bigint& x) const {
    return x<(*this);
}
const bool bigint::operator<=(const bigint& x) const {
    return !((*this)>x);
}
const bool bigint::operator>=(const bigint& x) const {
    return !((*this)<x);
}
const bool bigint::operator!=(const bigint& x) const {
    return (*this) < x || (*this) > x;
}
const bool bigint::operator==(const bigint& x) const {
    return !((*this) != x);
}

//
// Arithmetic
//
bigint bigint::operator-() const {
    bigint res(*this);
    if (a.size() > 0) {
        res.negative ^= true;
    }
    return res;
}
bigint& bigint::operator+=(const bigint& x) {
    if (negative != x.negative) return *this -= -x;
    if (a.size() < x.a.size()) {
        a.resize(x.a.size());
    }
    int K = 0;
    for (size_t i = 0; i < a.size(); ++i) {
        a[i] += (i < x.a.size() ? x.a[i] : 0) + K;
        K = a[i] / BASE;
        a[i] %= BASE;
    }
    if (K > 0) {
        a.push_back(1);
    }
    return *this;
}
bigint& bigint::operator-=(const bigint& x) {
    if (negative != x.negative) return *this += -x;
    std::vector<int> b(x.a);
    if ((*this < x) ^ negative) {
        a.swap(b);
        negative ^= true;
    }
    for (size_t i = 0, K = 0; i < a.size(); ++i) {
        a[i] += BASE - (i < b.size() ? b[i] : 0) + K;
        K = a[i] / BASE - 1;
        a[i] %= BASE;
    }
    return this->normalize();
}
bigint& bigint::operator*=(const bigint& x) {
    negative ^= x.negative;
    std::vector<int> c(a.size() * x.a.size() + 1);
    for (size_t i = 0; i < a.size(); ++i) {
        long long K = 0;
        for (size_t j = 0; j < x.a.size(); ++j) {
            long long V = (long long)a[i] * x.a[j] + c[i+j] + K;
            K = V / BASE;
            c[i+j] = (int)(V % BASE);
        }
        if (K > 0) c[i+x.a.size()] += (int) K;
    }
    a.swap(c);
    return this->normalize();
}
bigint& bigint::operator/=(const bigint& x) {
    return *this = divmod(x).first;
}
bigint& bigint::operator%=(const bigint& x) {
    return *this = divmod(x).second;
}
const bigint bigint::operator+(const bigint& x) const {
    bigint res(*this); return res += x;
}
const bigint bigint::operator-(const bigint& x) const {
    bigint res(*this); return res -= x;
}
const bigint bigint::operator*(const bigint& x) const {
    bigint res(*this); return res *= x;
}
const bigint bigint::operator/(const bigint& x) const {
    return this->divmod(x).first;
}
const bigint bigint::operator%(const bigint& x) const {
    return this->divmod(x).second;
}
const std::pair<bigint,bigint> bigint::divmod(const bigint& x) const
{
    if (x.a.size() == 0) throw "division by zero";
    bigint b = x.abs(), q, r;
    for (int i = a.size() - 1; i >= 0; --i) {
        r = r * BASE + a[i];
        int head = 0, tail = BASE;
        if (r >= b) {
            while (head + 1 < tail) {
                int m = (head + tail) / 2;
                if (b * bigint(m) > r) tail = m;
                else head = m;
            }
            r -= b * head;
        }
        q.a.push_back(head);
    }
    reverse(q.a.begin(), q.a.end());
    bool neg = negative ^ x.negative;
    q.negative = r.negative = neg;
    return { q.normalize(), r.normalize() };
}
const bigint bigint::abs() const {
    bigint x = *this;
    x.negative = false;
    return x;
}

//
// Digit-wise
//
int bigint::digits() const {
    if (a.size() == 0) return 0;
    int digits = bigint::L * (a.size() - 1);
    int top = a.back();
    while (top > 0) {
        top /= 10;
        digits++;
    }
    return digits;
}
int bigint::operator[](int idx) const {
    int M = digits();
    if (idx < 0 || idx >= M) throw;
    int i = idx / L, j = idx - i * L;
    int num = a[i];
    while (j > 0) {
        num /= 10;
        --j;
    }
    return num % 10;
}
int bigint::trailing_zeros() const {
    if (a.empty() || (a.size() == 1 && a[0] == 0)) return 1;

    int zeros = 0;
    size_t i;
    for (i = 0; i < a.size() && a[i] == 0; ++i) {
        zeros += bigint::L;
    }
    int num = a[i];
    while (num % 10 == 0 && num > 0) {
        ++zeros;
        num /= 10;
    }
    return zeros;
}

//
// IO
//
bigint bigint::parse(const std::string& s) {
    bool neg = false;
    size_t p = 0;
    bigint value(0);

    if (s[p] == '-') {
        neg = true; ++p;
    } else if (s[p] == '+') {
        ++p;
    }
    for (; p < s.size(); ++p) {
        int x = s[p] - '0';
        if (x < 0 || x > 9) throw "parse error";
        value *= 10;
        value += x;
    }
    value.negative = neg;
    return value.normalize();
}
std::istream& operator>>(std::istream& is, bigint& x) {
    std::string s;
    is >> s;
    x = bigint::parse(s);
    return is;
}
std::ostream& operator<<(std::ostream& os, const bigint& x) {
    if (x.negative) os << '-';
    if (x.a.size() == 0) {
        os << 0;
    } else {
        os << x.a.back();
    }
    for (int i = x.a.size() - 2; i >= 0; --i) {
        os.width(bigint::L);
        os.fill('0');
        os << x.a[i];
    }
    return os;
}
std::string to_string(const bigint& x) {
    std::ostringstream os;
    os << x;
    return os.str();
}