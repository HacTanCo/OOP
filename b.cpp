#define INPFILE "ANC.INP"
#define OUTFILE "ANC.OUT"

#include <bits/stdc++.h>
using namespace std;

template <class T>
class RMQ {
private:
	int n, n_log;
	vector <int> LOG2;
	vector <vector <T>> node;
public:
	RMQ(void) {}

	RMQ(int n, const vector <T>& a) : n(n) {
		LOG2.resize(n + 1, 0);

		for (int i = 2; i <= n; i++)
			LOG2[i] = LOG2[i >> 1] + 1;

		n_log = LOG2[n] + 1;

		node.resize(n_log);
		node[0] = a;

		for (int j = 1; j < n_log; j++) {
			node[j].resize(n + 1);
			for (int i = 1; i + (1 << j) - 1 <= n; i++)
				node[j][i] = min(node[j - 1][i], node[j - 1][i + (1 << (j - 1))]);
		}
	}

	T operator () (int l, int r) const {
		int j = LOG2[r - l + 1];
		return min(node[j][l], node[j][r - (1 << j) + 1]);
	}
};

class Tree {
public:
	int n, n_log, TIME_DFS = 0;
	vector <vector <int>> g, up;
	vector <int> a, pxor, tin, parent, depth;
	vector <pair <int, int>> EULER;
	RMQ <pair <int, int>> INSTANT_LCA;

	Tree(int n = 0) : n(n) {
		a.resize(n + 1);
		parent.resize(n + 1);
		pxor.resize(n + 1);
		tin.resize(n + 1);
		depth.resize(n + 1);
		g.resize(n + 1);
	}

	void add_edge(int u, int v) {
		g[u].push_back(v);
		g[v].push_back(u);
	}

private:
	void dfs(int u) {
		tin[u] = ++TIME_DFS;
		EULER.emplace_back(depth[u], u);

		for (int v : g[u]) if (parent[u] ^ v) {
			pxor[v] = pxor[u] ^ a[v];
			parent[v] = u;
			depth[v] = depth[u] + 1;
			dfs(v);
			EULER.emplace_back(depth[u], u);
			++TIME_DFS;
		}
	}

public:
	void init(void) {
		parent[0] = 0;
		parent[1] = 0;
		pxor[1] = a[1];
		TIME_DFS = 0;

		dfs(1);

		n_log = 0;
		while ((1 << n_log) <= n)
			n_log++;

		EULER.emplace_back(n + 1, n + 1);

		up.resize(n_log);
		up[0] = parent;
		for (int j = 1; j < n_log; j++) {
			up[j].resize(n + 1);
			for (int i = 1; i <= n; i++)
				up[j][i] = up[j - 1][up[j - 1][i]];
		}
		INSTANT_LCA = RMQ <pair <int, int>> (TIME_DFS, EULER);
	}

	int LCA(int u, int v) const {
		int a = tin[u];
		int b = tin[v];

		return INSTANT_LCA(min(a, b), max(a, b)).second;
	}

	inline int GET_PXOR  (int u) const { return pxor[u]; }
	inline int GET_PARENT(int u) const { return parent[u]; }
};

const int THRESHOLD = 1000;

int main(void) {
	if (fopen(INPFILE, "r")) {
		freopen(INPFILE, "r", stdin);
		freopen(OUTFILE, "w", stdout);
	}

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n; cin >> n;
	Tree tree(n);

	for (int i = 1; i <= n; i++)
		cin >> tree.a[i];

	for (int T = n - 1; T--; ) {
		int u, v; cin >> u >> v;
		tree.add_edge(u, v);
	}

	tree.init();

	int ans = *max_element(tree.a.begin(), tree.a.end());
	for (int i = 1; i <= n; i++) for (int j = i + 1; j <= n; j++) {
		int lca = n <= THRESHOLD ? tree.LCA(i, j) : 1;
		ans = max(ans, tree.GET_PXOR(i) ^ tree.GET_PXOR(j) ^ tree.GET_PXOR(lca) ^ tree.GET_PXOR(tree.GET_PARENT(lca)));
	}
	cout << ans << '\n';

	return 0-0;
}
