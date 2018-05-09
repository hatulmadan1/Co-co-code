#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <queue>

using namespace std;

typedef pair<int, char> pic;

#define mod %

const int N = 1e5 + 7;

vector<int> str[N], rev[N];

//begin of looking for useful vertexes
vector<bool> useful(N);

void dfs_rev(int v) {
	useful[v] = true;

	for (int i = 0; i < rev[v].size(); i++) {
		int u = rev[v][i];
		if (!useful[u]) {
			dfs_rev(u);
		}
	}
}
//end of looking for useful vertexes

vector<int> color(N);
vector<int> tops;

bool cycle_exists = false;

void dfs_str(int v) {
	color[v] = 1;
	tops.push_back(v);
	for (int i = 0; i < str[v].size();i++) {
		int u = str[v][i];
		if (color[u] == 0) {
			if (useful[u]) dfs_str(u);
		}
		else {
			if (color[u] == 1) cycle_exists = true;
		}
	}
	color[v] = 2;
}

vector<int> allowing; 

vector<long long> ways(N);

int main() {
	freopen("problem3.in", "r", stdin);
	freopen("problem3.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;

	cin >> n >> m >> k;

	int h = 0;
	for (int i = 0; i < k; i++) {
		cin >> h;
		allowing.push_back(h);
	}

	int a, b; char c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		str[a].push_back(b);
		rev[b].push_back(a);
	}

	for (int i = 0; i < allowing.size(); i++) {
		dfs_rev(allowing[i]);
	}

	dfs_str(1);

	if (cycle_exists) {
		cout << "-1"; return 0;
	}

	ways[1] = 1;

	for (int t = 0; t < tops.size(); t++) {
		int v = tops[t];
		for (int i = 0; i < str[v].size(); i++) {
			int u = str[v][i];

			ways[u] += ways[v];
			ways[u] %= (int)(1e9 + 7);
		}
	}

	long long ans = 0;

	for (int i = 0; i < allowing.size(); i++) {
		ans += ways[allowing[i]];
		ans %= (int)(1e9 + 7);
	}

	cout << ans;

	return 0;
}