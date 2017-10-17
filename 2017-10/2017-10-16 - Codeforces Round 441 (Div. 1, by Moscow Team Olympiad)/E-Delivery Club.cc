#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int T[N * 12], f[N * 12];

void pushup(int p) {
  T[p] = T[p * 2] + T[p * 2 + 1];
}

void pushdown(int p) {
  if (f[p]) {
    f[p * 2] = f[p * 2 + 1] = 1;
    T[p * 2] = T[p * 2 + 1] = 0;
    f[p] = 0;
  }
}

void update(int l, int r, int p, int L, int R, int val) {
  if (l >= L && r <= R) {
    T[p] = val;
    if (val == 0) {
      f[p] = 1;
    }
    return;
  }
  pushdown(p);
  int m = (l + r) / 2;
  if (m >= L) update(l, m, p * 2, L, R, val);
  if (m + 1 <= R) update(m + 1, r, p * 2 + 1, L, R, val);
  pushup(p);
}

int D = 300000;

bool check(int s1, int s2, const vector<int>& a, int d) {
  set<int> se = {s1, s2};
  for (auto x : a) {
    while (!se.empty() && *se.begin() < x - d) se.erase(se.begin());
    while (!se.empty() && *se.rbegin() > x + d) se.erase(*se.rbegin());
    if (se.empty()) return false;
    se.insert(x);
  }
  return true;
  /*  vector<int> vec = a;
  vec.push_back(s1), vec.push_back(s2);
  for (auto x : a) {
    vec.push_back(x - d - 1);
    vec.push_back(x + d + 1);
  }
  sort(vec.begin(), vec.end());
  vec.erase(unique(vec.begin(), vec.end()), vec.end());
  auto getIndex = [&vec](int x) {
    return lower_bound(vec.begin(), vec.end(), x) - vec.begin() + 1;
  };
  int n = vec.size();
  update(1, D, 1, getIndex(s1), getIndex(s1), 1);
  update(1, D, 1, getIndex(s2), getIndex(s2), 1);
  for (int i = 0; i < a.size(); i++) {
    int now = a[i];
    update(1, D, 1, 1, getIndex(now - d - 1), 0);
    update(1, D, 1, getIndex(now + d + 1), n, 0);
    if (!T[1]) return false;
    update(1, D, 1, getIndex(now), getIndex(now), 1);
  }
  update(1, D, 1, 1, D, 0);
  return true;*/
}

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  int n, s1, s2;
  cin >> n >> s1 >> s2;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int low = abs(s1 - s2), high = 1e9;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (check(s1, s2, a, mid)) high = mid - 1;
    else low = mid + 1;
  }
  cout << low << endl;
  return 0;
}
