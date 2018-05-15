#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <queue>

using namespace std;

#define mod %

const long long INF = 1e9 + 7;

vector<long long> str[111];
set<int> allowing;

int sol[110][1010];

int dfs(int v, int len, int l) {
	if (len < l) {
		long long ans = 0;
		for (int i = 0; i < str[v].size(); i++) {
			int u = str[v][i];
			if (sol[u][len + 1] == -1) {
				sol[u][len + 1] = dfs(u, len + 1, l);
				sol[u][len + 1] %= INF;
			}
			ans += sol[u][len + 1];
			ans = ans mod INF;
		}
		sol[v][len] = ans;
		return ans mod INF;
	}
	else {
		if (allowing.find(v) != allowing.end()) {
			sol[v][l] = 1;
			return sol[v][l];
		}
	}
}


int main() {
	freopen("problem4.in", "r", stdin);
	freopen("problem4.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k, l;

	cin >> n >> m >> k >> l;

	int h = 0;
	for (int i = 0; i < k; i++) {
		cin >> h;
		allowing.insert(h);
	}

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= l; j++) {
			sol[i][j] = -1;
		}
	}

	int a, b; char c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		str[a].push_back(b);
	}

	int res = dfs(1, 0, l);
	cout << res;

	return 0;
}