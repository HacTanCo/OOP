#pragma GCC optimize("Ofast")

#define INPFILE "TEAM.INP"
#define OUTFILE "TEAM.OUT"

#include <bits/stdc++.h>
using namespace std;
using lli = long long int;

const lli INF = 1e18 + 9e7;

struct MaxCount {
	lli val;
	int cnt;

	MaxCount(void) : val(-INF), cnt(0) {}
	MaxCount(lli v) : val(v), cnt(1) {}

	MaxCount operator + (const MaxCount& other) const {
		MaxCount ans;

		ans.val = max(val, other.val);
		ans.cnt = 0;

		if (ans.val == val)
			ans.cnt += cnt;
		if (ans.val == other.val)
			ans.cnt += other.cnt;

		return ans;
	}

	MaxCount& operator += (const MaxCount& other) { return *this = *this + other; }
};

class SegmentTree {
private:
	int n;
	vector <MaxCount> node;
	vector <lli> lazy;

	bool pushDown(int id) {
		if (not lazy[id])
			return false;

		for (int i : {id << 1, id << 1 | 1}) {
			node[i].val += lazy[id];
			lazy[i] += lazy[id];
		}

		lazy[id] = 0;

		return true;
	}

	void traverse(int id, int l, int r, int left, int right, const array <function <void (int, int, int)>, 2>& f) {
		if (l > r or left > right or left > r or l > right)
			return;
		if (left <= l and r <= right) {
			f[0] (id, l, r);
			return;
		}

		int m = (l + r) >> 1;
		pushDown(id);
		traverse(id << 1, l, m, left, right, f);
		traverse(id << 1 | 1, m + 1, r, left, right, f);

		f[1] (id, l, r);
	}
public:
	SegmentTree(int n = 0) : n(n) {
		node.resize(4 * n + 7, MaxCount(0));
		lazy.resize(4 * n + 7, 0);
	}

	void addRange(int l, int r, lli x) {
		traverse(1, 1, n, l, r, {
			[&] (int id, int, int) {
				node[id].val += x;
				lazy[id] += x;
			},
			[&] (int id, int, int) {
				node[id] = node[id << 1] + node[id << 1 | 1];
			},
		});
	}

	MaxCount prod(int l, int r) {
		MaxCount res;
		traverse(1, 1, n, l, r, {
			[&] (int id, int, int) {
				res += node[id];
			},
			[&] (int, int, int) {

			},
		});
		return res;
	}
};

const int MAX = 1e6 + 7;

int n, Q;
lli a[MAX];
int tin[MAX], tout[MAX];
vector <int> adj[MAX];

void dfs(int u, int p) {
	static int TIME_DFS = 0;

	tin[u] = ++TIME_DFS;

	for (int v : adj[u]) if (v ^ p)
		dfs(v, u);

	tout[u] = TIME_DFS;
}

int main(void) {
	if (fopen(INPFILE, "r")) {
		freopen(INPFILE, "r", stdin);
		freopen(OUTFILE, "w", stdout);
	}

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> Q;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int T = n - 1; T--; ) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, 1);

	SegmentTree SMT(n);

	for (int i = 1; i <= n; i++) {
		SMT.addRange(tin[i], tin[i], a[i]);
	}

	while (Q--) {
		int t, u; cin >> t >> u;

		int l = tin[u], r = tout[u];

		if (t == 1) {
			lli x; cin >> x;
			SMT.addRange(l, r, x);
		}

		if (t == 2) {
			MaxCount ans = SMT.prod(l, r);
			cout << ans.val << ' ' << ans.cnt << '\n';
		}
	}

	return 0-0;
}

