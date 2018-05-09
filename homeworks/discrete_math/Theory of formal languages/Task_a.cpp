#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>

using namespace std;

struct trans {
	int from;
	char c;
	trans(int ff, char cc) {
		from = ff;
		c = cc;
	}
};

bool operator<(trans a, trans b) {
	if (a.from != b.from) return a.from < b.from;
	return a.c < b.c;
}

map<trans, int> dsm;

set<int> acceptable;

int main() {
	freopen("problem1.in", "r", stdin);
	freopen("problem1.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	int n, m, k;

	cin >> s;
	cin >> n >> m >> k;

	int h;
	for (int i = 0; i < k; i++) {
		cin >> h;
		acceptable.insert(h);
	}

	int a, b; char c;
	for (int i = 0;i < m; i++) {
		cin >> a >> b >> c;
		dsm[trans(a, c)] = b;
	}

	int cur = 1;
	for (int i = 0; i < s.size(); i++) {
		cur = dsm[trans(cur, s[i])];
	}

	if (acceptable.find(cur) != acceptable.end()) {
		cout << "Accepts";
	}
	else cout << "Rejects";

	return 0;
}