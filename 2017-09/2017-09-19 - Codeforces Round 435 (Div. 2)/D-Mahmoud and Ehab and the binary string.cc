#include <bits/stdc++.h>

using namespace std;

int query(string s) {
  cout << "? " << s << endl;
  int t;
  cin >> t;
  return t;
}

int a1, a2, n;

int dfs(int l, int r, int sum, int v2) {
  int m = (l + r) / 2;
  string s;
  for (int i = 1; i <= n; i++) {
    if (i > m && i <= r) s += '1';
    else s += '0';
  }
  int k = query(s), L = r - m;
  int x = (sum - (k - L)) / 2;
  if (x == 0) {
    if (m - l + 1 == v2) a1 = r, a2 = l;
    else dfs(l, m, sum, v2);
  } else if (x == v2) {
    if (L == v2) a1 = l, a2 = r;
    else dfs(m + 1, r, sum, v2);
  } else {
    if (x == L) dfs(l, m, sum, v2 - x);
    else dfs(m + 1, r, sum, x);
  }
}

int main(int argc, char *argv[]) {
  cin >> n;
  int sum = query(string(n, '0'));
  dfs(1, n, sum, sum);
  printf("! %d %d\n", a1, a2);
  return 0;
}
