#include <bits/stdc++.h>

using namespace std;

int a[200005 * 4];

void update(int l, int r, int p, int P, int val) {
  if (l == r) {
    a[p] += val;
    return;
  }
  int m = (l + r) / 2;
  if (m >= P) update(l, m, p * 2, P, val);
  else update(m + 1, r, p * 2 + 1, P, val);
  a[p] = max(a[p * 2], a[p * 2 + 1]);
}

int query(int l, int r, int p, int L, int R) {
  if (l >= L && r <= R) {
    return a[p];
  }
  int m = (l + r) / 2, mx = 0;
  if (m >= L) mx = max(mx, query(l, m, p * 2, L, R));
  if (m + 1 <= R) mx = max(mx, query(m + 1, r, p * 2 + 1, L, R));
  return mx;
}

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> b(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    update(1, n, 1, i, b[i]);
  }
  vector<vector<int>> ans;
  for (;;) {
    if (query(1, n, 1, 1, n) == 0) break;
    vector<int> vec;
    for (int L = 1, now = 0; ;) {
      int low = L, high = n;
      while (low <= high) {
        int mid = (low + high) / 2;
        if (query(1, n, 1, L, mid) <= now) {
          low = mid + 1;
        } else {
          high = mid - 1;
        }
      }
      if (low > n) break;
      vec.push_back(b[low]);
      update(1, n, 1, low, -b[low]);
      L = low + 1;
      now = b[low];
    }
    ans.push_back(vec);
  }
  for (auto v : ans) {
    for (auto x : v) {
      cout << x << " ";
    }
    cout << endl;
  }
  return 0;
}
