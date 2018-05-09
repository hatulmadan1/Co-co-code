#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <queue>

using namespace std;

const int N = 1e5 + 7;

struct trans1 {
	int to;
	char c;
	trans1(int tt, char cc) {
		to = tt;
		c = cc;
	}
};

struct trans2 {
	int from;
	char c;
	trans2(int ff, char cc) {
		from = ff;
		c = cc;
	}
};

bool operator< (trans2 a, trans2 b) {
	if (a.from != b.from) return a.from < b.from;
	return a.c < b.c;
}

vector<trans1> dsm1[N];
map<trans2, int> dsm2;

vector<bool> ac1, ac2; 
vector<bool> diab1, diab2; 
vector<int> num1, num2; 

bool visited[N];

bool dfs(int v, int u) {
	visited[v] = true;
	if (ac1[v] != ac2[u]) {
		return false;
	}

	bool result = true;
	for (int i = 0; i < dsm1[v].size(); i++) {
		int t1 = dsm1[v][i].to;
		int t2 = dsm2[trans2(u, dsm1[v][i].c)];
		if (diab1[t1] != diab2[t2]) {
			return false;
		}
		if (!visited[t1]) {
			result = result & dfs(t1, t2);
		}
	}
	return result;
}

int main() {
	freopen("isomorphism.in", "r", stdin);
	freopen("isomorphism.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;

	cin >> n >> m >> k;
	ac1.resize(n + 2, false);
	diab1.resize(n + 2, true);
	num1.resize(n + 2, 0);

	int h; int a, b; char c;
	for (int i = 0; i < k; i++) {
		cin >> h;
		ac1[h] = true;
	}

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		diab1[a] = false;
		num1[a]++;
		dsm1[a].push_back(trans1(b, c));
	}

	//sorry for copypasta, i don't know how to do it better
	//maybe with links, but i'm very bad at using them

	cin >> n >> m >> k;
	ac2.resize(n + 2, false);
	diab2.resize(n + 2, true);
	num2.resize(n + 2, 0);

	for (int i = 0; i < k; i++) {
		cin >> h;
		ac2[h] = true;
	}

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		diab2[a] = false;
		num2[a] ++;
		dsm2[trans2(a, c)] = b;
	}

	if (dfs(1, 1)) cout << "YES";
	else cout << "NO";

	return 0;
}