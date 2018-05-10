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
vector<long long> ways(N);
set<int> allowing;

long long dfs_str(int v) {
	if (cycle_exists) {
		return 0;
	}

	if (color[v] == 2) {
		return ways[v];
	}
	else if (color[v] == 1) {
		cycle_exists = true;
		return 0;
	}

	color[v] = 1;

	long long ans = 0;
	for (int i = 0; i < str[v].size(); i++) {
		int u = str[v][i];

		if (useful[u]) {
			ans += dfs_str(u);
		}
	}

	color[v] = 2;
	ways[v] = ans + (allowing.find(v) != allowing.end() ? 1 : 0);
	ways[v] %= (long long)(1e9 + 7);

	return ways[v];
}

//�����������



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
		allowing.insert(h);
	}

	int a, b; char c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		str[a].push_back(b);
		rev[b].push_back(a);
	}

	for (set<int>::iterator i = allowing.begin(); i != allowing.end(); i++) {
		dfs_rev(*i);
	}

	ways[1] = 1;
	int ff = dfs_str(1);

	if (cycle_exists) {
		cout << "-1"; return 0;
	}

	cout << ff;

	return 0;
}