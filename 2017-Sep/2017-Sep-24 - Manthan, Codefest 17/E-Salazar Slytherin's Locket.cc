#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll inf = (ll)1e18 + 22;

ll dp[11][1 << 10][10][70][2];
string s;

ll dfs1(int b, int sta, int p, int len, bool flag) {
  //  cout << b << " " << sta << " " << p << " " << len << " " << flag << endl;
  if (len == 1) {
    return (sta == 0 && !flag ? 1 : 0);
  }
  ll& v = dp[b][sta][p][len][flag];
  if (v == -1) {
    v = 0;
    for (int i = 0; i < b; i++) {
      v += dfs1(b, flag && i == 0 ? sta : sta ^ (1 << i), i, len - 1, flag && i == 0);
    }
  }
  //  cout << b << " " << sta << " " << p << " " << len << " " << flag << endl;
  //cout << v << endl;
  return v;
}

ll dfs2(int b, int sta, int len) {
  if (len == 0) {
    return sta == 0 ? 1 : 0;
  }
  ll ans = 0;
  int up = s[len - 1] - '0';
  for (int i = 0; i < up; i++) {
    ans += dfs1(b, i == 0 && len == s.size() ? sta : sta ^ (1 << i), i, len, i == 0 && len == s.size());
  }
  ans += dfs2(b, sta ^ (1 << up), len - 1);
  return ans;
}

int main(int argc, char *argv[]) {
  memset(dp, -1, sizeof(dp));
  auto trans = [](ll val, int b) {
    string s;
    while (val) {
      s += (char)(val % b + '0');
      val /= b;
    }
    if (s.size() == 0) {
      s = "0";
    }
    return s;
  };
  auto query = [&trans](ll val, int b) {
    if (val == 0) return 0LL;
    s = trans(val, b);
    return dfs2(b, 0, s.size());
  };
  int Q;
  scanf("%d", &Q);
  while (Q--) {
    int b;
    ll l, r;
    scanf("%d%lld%lld", &b, &l, &r);
    printf("%lld\n", query(r, b) - query(l - 1, b));
  }
  return 0;
}
