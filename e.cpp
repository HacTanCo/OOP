#define INPFILE "MAGIC.INP"
#define OUTFILE "MAGIC.OUT"

#include <bits/stdc++.h>
using namespace std;


template <typename T>
T inverse_modulo(T a, T m) {
	T u = 0, v = 1;
	while (a > 0) {
		T t = m / a;
		m -= t * a; swap(a, m);
		u -= t * v; swap(u, v);
	}
	assert(m == 1);
	return u;
}

template <typename T>
class ModInt {
public:
	using Type = typename decay <decltype (T::value)>::type;

	//initializers
	constexpr ModInt(void): value() {}
	template <typename U>
	ModInt (const U& x) {
		value = normalize(x);
	}

	//fix value to mod
	template <typename U>
	static Type normalize(const U& x) {
		Type v;
		if (-mod() <= x and x < mod())
			v = static_cast <Type> (x);
		else
			v = static_cast <Type> (x % mod());
		if (v < 0)
			v += mod();
		return v;
	}

	//return value
	const Type& operator () (void) const { return value; }
	template <typename U> //convert to other type
	explicit operator U(void) const { return static_cast <U> (value); }
	constexpr static Type mod(void) { return T::value; } //return modular base

	//operator
	ModInt& operator += (const ModInt &oth) {
		if ((value += oth.value) >= mod())
			value -= mod();
		return *this;
	}

	ModInt& operator -= (const ModInt &oth) {
		if ((value -= oth.value) < 0)
			value += mod();
		return *this;
	}

	template <typename U> ModInt& operator += (const U& x) { return *this += ModInt(x); }
	template <typename U> ModInt& operator -= (const U& x) { return *this -= ModInt(x); }

	ModInt& operator ++ (void) { return *this += 1; }
	ModInt& operator -- (void) { return *this -= 1; }

	ModInt operator ++ (int) { ModInt tmp(*this); *this += 1; return tmp; }
	ModInt operator -- (int) { ModInt tmp(*this); *this -= 1; return tmp; }

	ModInt operator - (void) const { return ModInt(-value); }

	template <typename U>
	typename enable_if <is_integral <U>::value, ModInt>::type fmul(U b) const {
		ModInt ans, a = *this;
		while (b) {
			if (b & 1)
				ans += a;
			a += a;
			b /= 2;
		}
		return ans;
	}

	template <typename U = T>
	typename enable_if <is_same <typename ModInt <U>::Type, int32_t>::value, ModInt>::type& operator *= (const ModInt& oth) {
		value = normalize(static_cast <int64_t> (value) * static_cast <int64_t> (oth.value));
		return *this;
	}

	template <typename U = T>
	typename enable_if <is_same <typename ModInt <U>::Type, int64_t>::value, ModInt>::type& operator *= (const ModInt& oth) {
		value = (*this).fmul(oth.value) ();
		return *this;
	}

	template <typename U = T>
	typename enable_if <not is_integral <typename ModInt <U>::type>::value, ModInt>::type& operator *= (const ModInt& oth) {
		value = normalize(static_cast <int64_t> (value) * static_cast <int64_t> (oth.value));
		return *this;
	}

	ModInt& operator /= (const ModInt& oth) { return *this *= inverse_modulo(oth.value, mod()); }

	friend const Type& ABS(const ModInt& x) { return x.value; }

	//input, output
	template <typename stream>
	friend stream& operator << (stream& cout, const ModInt& a) {
		return cout << a();
	}

	template <typename stream>
	friend stream& operator >> (stream& cin, ModInt& a) {
		typename common_type <Type, int64_t>::type x;
		cin >> x;
		a = ModInt (x);
		return cin;
	}
private:
	Type value;
};

template <typename T> bool operator == (const ModInt <T>& lhs, const ModInt <T>& rhs) { return lhs() == rhs(); }
template <typename T, typename U> bool operator == (const ModInt <T>& lhs, U rhs) { return lhs() == rhs; }
template <typename T, typename U> bool operator == (U lhs, const ModInt <T>& rhs) { return lhs == rhs(); }

template <typename T> bool operator != (const ModInt <T>& lhs, const ModInt <T>& rhs) { return !(lhs() == rhs()); }
template <typename T, typename U> bool operator != (const ModInt <T>& lhs, U rhs) { return !(lhs() == rhs); }
template <typename T, typename U> bool operator != (U lhs, const ModInt <T>& rhs) { return !(lhs == rhs()); }

template <typename T> bool operator > (const ModInt <T>& lhs, const ModInt <T>& rhs) { return lhs() > rhs(); }
template <typename T, typename U> bool operator > (const ModInt <T>& lhs, U rhs) { return lhs() > rhs; }
template <typename T, typename U> bool operator > (U lhs, const ModInt <T>& rhs) { return lhs > rhs(); }

template <typename T> bool operator >= (const ModInt <T>& lhs, const ModInt <T>& rhs) { return lhs() >= rhs(); }
template <typename T, typename U> bool operator >= (const ModInt <T>& lhs, U rhs) { return lhs() >= rhs; }
template <typename T, typename U> bool operator >= (U lhs, const ModInt <T>& rhs) { return lhs >= rhs(); }

template <typename T> bool operator < (const ModInt <T>& lhs, const ModInt <T>& rhs) { return lhs() < rhs(); }
template <typename T, typename U> bool operator < (const ModInt <T>& lhs, U rhs) { return lhs() < rhs; }
template <typename T, typename U> bool operator < (U lhs, const ModInt <T>& rhs) { return lhs < rhs(); }

template <typename T> bool operator <= (const ModInt <T>& lhs, const ModInt <T>& rhs) { return lhs() <= rhs(); }
template <typename T, typename U> bool operator <= (const ModInt <T>& lhs, U rhs) { return lhs() <= rhs; }
template <typename T, typename U> bool operator <= (U lhs, const ModInt <T>& rhs) { return lhs <= rhs(); }

template <typename T> ModInt <T> operator + (const ModInt <T>& lhs, const ModInt <T>& rhs) { return ModInt <T> (lhs) += rhs; }
template <typename T, typename U> ModInt <T> operator + (const ModInt <T>& lhs, U rhs) { return ModInt <T> (lhs) += rhs; }
template <typename T, typename U> ModInt <T> operator + (U lhs, const ModInt <T>& rhs) { return ModInt <T> (lhs) += rhs; }

template <typename T> ModInt <T> operator - (const ModInt <T>& lhs, const ModInt <T>& rhs) { return ModInt <T> (lhs) -= rhs; }
template <typename T, typename U> ModInt <T> operator - (const ModInt <T>& lhs, U rhs) { return ModInt <T> (lhs) -= rhs; }
template <typename T, typename U> ModInt <T> operator - (U lhs, const ModInt <T>& rhs) { return ModInt <T> (lhs) -= rhs; }

template <typename T> ModInt <T> operator * (const ModInt <T>& lhs, const ModInt <T>& rhs) { return ModInt <T> (lhs) *= rhs; }
template <typename T, typename U> ModInt <T> operator * (const ModInt <T>& lhs, U rhs) { return ModInt <T> (lhs) *= rhs; }
template <typename T, typename U> ModInt <T> operator * (U lhs, const ModInt <T>& rhs) { return ModInt <T> (lhs) *= rhs; }

template <typename T> ModInt <T> operator / (const ModInt <T>& lhs, const ModInt <T>& rhs) { return ModInt <T> (lhs) /= rhs; }
template <typename T, typename U> ModInt <T> operator / (const ModInt <T>& lhs, U rhs) { return ModInt <T> (lhs) /= rhs; }
template <typename T, typename U> ModInt <T> operator / (U lhs, const ModInt <T>& rhs) { return ModInt <T> (lhs) /= rhs; }

template <typename T, typename U>
ModInt <T> fpow(const ModInt <T>& a, const U &b) {
	ModInt <T> x = a, res = 1;
	U p = b;
	while (p) {
		if (p & 1)
			res *= x;
		x *= x;
		p /= 2;
	}
	return res;
}

template <class T>
struct Matrix {
	int n, m;
	vector <vector <T>> self;

	Matrix(int _n = 0, int _m = 0, bool unit = false) : n(_n), m(_m) {
		self.assign(n, vector <T> (m + 1, 0));
		if (unit)
			for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
				self[i][j] = i == j;
	}

	Matrix(const vector <vector <T>>& value) {
		n = value.size();
		m = n ? value.begin()->size() : 0;
		self = value;
	}

	Matrix(initializer_list <initializer_list <T>> value) {
		n = value.size();
		m = n ? value.begin()->size() : 0;
		self.reserve(n);
		self.insert(self.end(), value.begin(), value.end());
	}

	auto& operator [] (int i) { assert(i < n); return self[i]; }
	const auto& operator [] (int i) const { assert(i < n); return self[i]; }

	Matrix operator + (const Matrix& other) const {
		assert(n == other.n and m == other.m);
		Matrix ans(n, m);
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
			ans[i][j] = (*this)[i][j] + other[i][j];
		return ans;
	}

	Matrix operator - (const Matrix& other) const {
		assert(n == other.n and m == other.m);
		Matrix ans(n, m);
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
			ans[i][j] = (*this)[i][j] - other[i][j];
		return ans;
	}

	Matrix operator - (void) const {
		Matrix ans(n, m);
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
			ans[i][j] = -(*this)[i][j];
		return ans;
	}

	Matrix operator * (const Matrix& other) const {
		assert(m == other.n);
		Matrix ans(n, other.m);
		for (int i = 0; i < n; i++)
				for (int k = 0; k < m; k++)
			for (int j = 0; j < other.m; j++)
			ans[i][j] += (*this)[i][k] * other[k][j];
		return ans;
	}

	inline Matrix& operator += (const Matrix& other) { return *this = (*this) + other; }
	inline Matrix& operator -= (const Matrix& other) { return *this = (*this) - other; }
	inline Matrix& operator *= (const Matrix& other) { return *this = (*this) * other; }
	inline bool operator == (const Matrix& other) const { return self == other.self; }
	inline bool operator != (const Matrix& other) const { return not (self == other.self); }

	template <class U>
	friend ostream& operator << (ostream& cout, const Matrix <U>& lhs) {
		for (int i = 0; i < lhs.n; i++) for (int j = 0; j < lhs.m; j++)
			cout << lhs[i][j] << " \n"[j + 1 == lhs.m];
		return cout;
	}
};

template <class U>
Matrix <U> fpow(Matrix <U> base, int64_t b) {
	Matrix <U> ans(base.n, base.m, true);
	while (b) {
		if (b & 1)
			ans *= base;
		base *= base;
		b >>= 1;
	}
	return ans;
}

const int MOD = 1e9 + 7;
using Mint = ModInt <integral_constant <decay <decltype (MOD)>::type, MOD>>;

Matrix <Mint> BASE = {
	{0, 0, 1},
	{1, 0, 0},
	{0, 1, 1},
};

Mint solve(int64_t n) {
	return fpow(BASE, n) [2][2];
}

int main(void) {
	if (fopen(INPFILE, "r")) {
		freopen(INPFILE, "r", stdin);
		freopen(OUTFILE, "w", stdout);
	}

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int TC; cin >> TC;
	while (TC--) {
		int64_t n; cin >> n;
		cout << solve(n) << '\n';
	}

	return 0-0;
}

