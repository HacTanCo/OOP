#define INPFILE "SMARKET.INP"
#define OUTFILE "SMARKET.OUT"

#include <bits/stdc++.h>
using namespace std;
using lli = long long int;

const lli INF = 1e18;
const int MAX = 30;

int n, m, FULL;
lli cost[MAX];
int bags[MAX];
int suff[MAX];

unordered_map <lli, lli> MP[MAX];

lli solve(int p, int MASK) {
	if (p == n)
		return MASK == FULL ? 0 : +INF;

	if ((MASK | suff[p]) != FULL)
		return +INF;

	if (MP[p].count(MASK))
		return MP[p][MASK];

	lli& ans = MP[p][MASK];
	ans = +INF;

	ans = min(ans, solve(p + 1, MASK));
	ans = min(ans, solve(p + 1, MASK | bags[p]) + cost[p]);

	return ans;
}

int main(void) {
	if (fopen(INPFILE, "r")) {
		freopen(INPFILE, "r", stdin);
		freopen(OUTFILE, "w", stdout);
	}

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int v; cin >> v;
			bags[i] += v << j;
		}
		cin >> cost[i];
	}

	FULL = (1 << m) - 1;


	suff[n - 1] = bags[n - 1];
	for (int i = n - 2; i >= 0; i--)
		suff[i] = suff[i + 1] | bags[i];

	lli ans = solve(0, 0);
	if (ans == INF)
		ans = -1;
	cout << ans << '\n';

	return 0-0;
}

