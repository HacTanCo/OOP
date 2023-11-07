#define INPFILE "HASH.INP"
#define OUTFILE "HASH.OUT"

#include <bits/stdc++.h>
using namespace std;
using lli = long long int;

int MOD;

int fpow(lli a, lli b) {
	if (b == 0)
		return 1;
	int T = fpow(1LL * a * a % MOD, b >> 1);
	if (b & 1)
		return 1LL * T * a % MOD;
	return T;
}

const int M = 31;

class HashSegTree {
private:
	int n;
	vector <int> POW;
	vector <int> INV;
	vector <int> node;

	void build(int id, int l, int r, const vector <int>& a) {
		if (l > r)
			return;
		if (l == r) {
			node[id] = 1LL * a[l] * POW[n - l] % MOD;
			return;
		}

		int m = (l + r) >> 1;
		build(id << 1, l, m, a);
		build(id << 1 | 1, m + 1, r, a);

		node[id] = (node[id << 1] + node[id << 1 | 1]) % MOD;
	}

	void traverse(int id, int l, int r, int left, int right, const array <function <void (int, int, int)>, 2>& f) {
		if (l > r or left > right or left > r or l > right)
			return;
		if (left <= l and r <= right) {
			f[0] (id, l, r);
			return;
		}

		int m = (l + r) >> 1;
		traverse(id << 1, l, m, left, right, f);
		traverse(id << 1 | 1, m + 1, r, left, right, f);

		f[1] (id, l, r);
	}
public:
	HashSegTree(void) {}
	HashSegTree(int n, const vector <int>& a) : n(n) {
		POW.resize(n + 1, 1);
		INV.resize(n + 1, 1);

		for (int i = 1; i <= n; i++) {
			POW[i] = 1LL * POW[i - 1] * M % MOD;
			INV[i] = fpow(POW[i], MOD - 2);
		}

		node.resize(4 * n + 7, 0);
		build(1, 1, n, a);
	}

	void update(int p, int x) {
		traverse(1, 1, n, p, p, {
			[&] (int id, int l, int r) -> void {
				node[id] = 1LL * x * POW[n - r] % MOD;
			},
			[&] (int id, int l, int r) -> void {
				node[id] = (node[id << 1] + node[id << 1 | 1]) % MOD;
			},
		});
	}

	int prod(int l, int r) {
		int ans = 0;

		traverse(1, 1, n, l, r, {
			[&] (int id, int l, int r) -> void {
				ans = (ans + node[id]) % MOD;
			},
			[&] (int id, int l, int r) -> void {
				node[id] = (node[id << 1] + node[id << 1 | 1]) % MOD;
			},
		});

		ans = 1LL * ans * INV[n - r] % MOD;

		return ans;
	}
};

int main(void) {
	if (fopen(INPFILE, "r")) {
		freopen(INPFILE, "r", stdin);
		freopen(OUTFILE, "w", stdout);
	}

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string s; cin >> s;
	cin >> MOD;

	int n = s.size();
	vector <int> a(n + 1);
	for (int i = 1; i <= n; i++)
		a[i] = s[i - 1] - 'a' + 1;

	HashSegTree SMT(n, a);

	int Q; cin >> Q;
	while (Q--) {
		char t; cin >> t;

		if (t == '?') {
			int l, r; cin >> l >> r;
			cout << SMT.prod(l, r) << '\n';
		}

		if (t == '!') {
			int p; char c; cin >> p >> c;
			SMT.update(p, c - 'a' + 1);
		}
	}

	return 0-0;
}
