#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 200005;

int in[N];

int lowbit(int n) {return n & (-n);}

void update(int p, int val) {
  for (int i = p; i < N; i += lowbit(i)) {
    in[i] += val;
  }
}

int query(int p) {
  int sum = 0;
  for (int i = p; i; i -= lowbit(i)) {
    sum += in[i];
  }
  return sum;
}

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<tuple<int, int, int, int>> b;
  vector<vector<int>> g1(n + 2), g2(n + 2);
  vector<ll> ans(q);
  auto cal = [](ll x){return x * (x - 1) / 2;};
  for (int i = 0; i < q; i++) {
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    b.push_back({x1, y1, x2, y2});
    g1[x1 - 1].push_back(i);
    g2[x2 + 1].push_back(i);
    ans[i] += cal(min(x1 - 1, (ll)n)) + cal(min(y1 - 1, (ll)n)) + cal(min(n - x2, (ll)n)) + cal(min(n - y2, (ll)n));
  }
  for (int i = 1; i <= n; i++) {
    update(a[i], 1);
    for (auto id : g1[i]) {
      int y1, y2;
      tie(ignore, y1, ignore, y2) = b[id];
      ans[id] -= (cal(query(y1 - 1)) + cal(i - query(y2)));
    }
  }
  memset(in, 0, sizeof(in));
  for (int i = n; i >= 1; i--) {
    update(a[i], 1);
    for (auto id : g2[i]) {
      int y1, y2;
      tie(ignore, y1, ignore, y2) = b[id];
      ans[id] -= (cal(query(y1 - 1)) + cal(n - i + 1 - query(y2)));
    }
  }
  for (auto x : ans) {
    cout << cal(n) - x << endl;
  }
  return 0;
}
