#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <queue>

using namespace std;

#define pii pair<int, int> 

const int N = 1e3 + 7;

struct trans {
	int from;
	char c;
	trans(int ff, char cc) {
		from = ff;
		c = cc;
	}
};

bool operator< (trans a, trans b) {
	if (a.from != b.from) return a.from < b.from;
	return a.c < b.c;
}

map<trans, int> dsm1, dsm2;

vector<bool> ac1, ac2; //�����������
vector<bool> diab1, diab2; //�����������
						   //vector<int> num1, num2; //������� ���� �� �������;

bool used[N][N];

set<char> alp;

int main() {
	freopen("equivalence.in", "r", stdin);
	freopen("equivalence.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;
	bool ans = true;

	cin >> n >> m >> k;
	ac1.resize(n + 2, false);
	diab1.resize(n + 2, true);

	int h; int a, b; char c;
	for (int i = 0; i < k; i++) {
		cin >> h;
		ac1[h] = true;
	}

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		diab1[a] = false;
		dsm1[trans(a, c)] = b;
		alp.insert(c);
	}

	//sorry for copypasta, i don't know how to do it better
	//maybe with links, but i'm very bad at using them

	cin >> n >> m >> k;
	ac2.resize(n + 2, false);
	diab2.resize(n + 2, true);

	for (int i = 0; i < k; i++) {
		cin >> h;
		ac2[h] = true;
	}

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		diab2[a] = false;
		dsm2[trans(a, c)] = b;
		alp.insert(c);
	}

	queue<pii> q;
	q.push({ 1, 1 });



	while (!q.empty()) {
		pii h = q.front();
		q.pop();
		int v = h.first, u = h.second;
		if (ac1[v] != ac2[u]) {
			ans = false;
			break;
		}
		used[v][u] = true;
		for (set<char>::iterator i = alp.begin(); i != alp.end(); i++) {
			int v1 = dsm1[trans(v, *i)], u1 = dsm2[trans(u, *i)];
			if (!used[v1][u1]) {
				q.push({ v1, u1 });
			}
		}
	}

	if (ans) cout << "YES";
	else cout << "NO";

	return 0;
}