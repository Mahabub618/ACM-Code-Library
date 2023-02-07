#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 

const int maxn = 1e5 + 10; 
const int mx = 1e4 + 10; 
const int sz = 1225; 
const int tot = maxn / sz + 5;

int lucky[] = {4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777, 4444, 4447, 4474, 4477, 4744, 4747, 4774, 4777, 7444, 7447, 7474, 7477, 7744, 7747, 7774, 7777};
int islucky[mx], cnt[tot][mx], lazy[tot], a[maxn];
int block[maxn], st[tot], ed[tot]; 

void update(int l, int r, int v) {
	function<void(int, int, int)> doshit = [](int p, int idx, int v) {
		--cnt[idx][a[p]]; 
		a[p] += v;
		++cnt[idx][a[p]];
	};
	if(block[l] == block[r]) {
		for(int i = l; i <= r; ++i) 
			doshit(i, block[l], v);
	} else {
		for(int i = l; i <= ed[block[l]]; ++i) 
			doshit(i, block[i], v);
		for(int i = st[block[r]]; i <= r; ++i) 
			doshit(i, block[i], v);
		for(int i = block[l] + 1; i < block[r]; ++i)
			lazy[i] += v; 
	}
}

int query(int l, int r) {
	int ans = 0;
	if(block[l] == block[r]) {
		for(int i = l; i <= r; ++i) 
			ans += islucky[a[i] + lazy[block[i]]];
	} else {
		for(int i = l; i <= ed[block[l]]; ++i) 
			ans += islucky[a[i] + lazy[block[i]]];
		for(int i = st[block[r]]; i <= r; ++i)
			ans += islucky[a[i] + lazy[block[i]]];
		for(int i = block[l] + 1; i < block[r]; ++i) {
			for(int j = 0; j < 30; ++j) if(lucky[j] >= lazy[i]) {
				ans += cnt[i][lucky[j] - lazy[i]];
			}
		}
	} return ans;
}
int main(int argc, char const *argv[]) {
#ifdef LOCAL_TESTING
	freopen("in", "r", stdin);
#endif
	int n, m; scanf("%d %d", &n, &m);
	for(int i = 0, j = -1; i < n; ++i) {
		scanf("%d", &a[i]); 
		if(i % sz == 0) {
			block[i] = ++j; 
			st[block[i]] = i; 
			ed[block[i]] = min(n - 1, i + sz - 1);
		} else block[i] = j;
		++cnt[block[i]][a[i]];
	} 
	for(int i = 0; i < 30; ++i) 
		islucky[lucky[i]] = 1;

	while(m--) {
		char c[7]; 
		int l, r, d; 
		scanf(" %s %d %d", c, &l, &r); 
		l--, r--;

		if(c[0] == 'a') {
			scanf("%d", &d); 
			update(l, r, d); 
		} else {
			printf("%d\n", query(l, r));
		}
	}

}
// https://codeforces.com/contest/121/problem/E
