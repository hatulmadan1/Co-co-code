#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <queue>

using namespace std;

struct trans {
	int to;
	char with;
	trans(int _to, int _with) {
		to = _to;
		with = _with;
	}
};

vector<trans> g[10101];
set<int> sol[10101];
set<int> ac;

int main() {
	freopen("problem2.in", "r", stdin);
	freopen("problem2.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	int n, m, k;

	cin >> s;
	cin >> n >> m >> k;

	int h;
	for (int i = 0; i < k; i++) {
		cin >> h;
		ac.insert(h);
	}

	int a, b; char c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		g[a].push_back(trans(b, c));
	}

	sol[0].insert(1);

	for (int i = 1; i <= s.size(); i++) { 
		for (set<int>::iterator j = sol[i - 1].begin(); j != sol[i - 1].end(); j++) { 
			int v = *j;
			for (int u = 0; u < g[v].size(); u++) { 
				if (g[v][u].with == s[i - 1]) {
					sol[i].insert(g[v][u].to);
				}
			}
		}
	}

	bool ans = false;
	for (set<int>::iterator i = sol[s.size()].begin(); i != sol[s.size()].end(); i++) {
		if (ac.find(*i) != ac.end()) {
			ans = true; break;
		}
	}

	if (ans) cout << "Accepts";
	else cout << "Rejects";

	return 0;
}