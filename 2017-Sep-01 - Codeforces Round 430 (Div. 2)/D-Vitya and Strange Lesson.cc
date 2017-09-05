#include <bits/stdc++.h>

using namespace std;

const int N = 30 * 300005;

int ch[N][2], val[N], cnt = 1;

void insert(int x) {
  for (int i = 30, now = 0; i >= 0; i--) {
    int v = (((1 << i) & x) > 0);
    if (!ch[now][v]) {
      ch[now][v] = cnt++;
    }
    now = ch[now][v];
    val[now]++;
  }
}

int main(int argc, char *argv[]) {
  int n, m;
  scanf("%d%d", &n, &m);
  set<int> se;
  for (int i = 0, x; i < n; i++) {
    scanf("%d", &x);
    if (!se.count(x)) {
      insert(x);
      se.insert(x);
    }
  }
  for (int z = 0, t, last = 0; z < m; z++) {
    scanf("%d", &t);
    last ^= t;
    int ans = 0;
    for (int i = 30, now = 0; i >= 0; i--) {
      int v = (((1 << i) & last) > 0);
      if (ch[now][v] && val[ch[now][v]] == (1 << i)) {
        ans ^= (1 << i);
        now = ch[now][!v];
      } else {
        now = ch[now][v];
      }
      if (!now) break;
    }
    printf("%d\n", ans);
  }
  return 0;
}
