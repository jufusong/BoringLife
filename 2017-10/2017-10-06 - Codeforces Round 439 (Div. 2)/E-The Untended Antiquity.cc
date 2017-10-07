#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 2501;
const int mod = 998244353;

inline int inverse(int a, int mod) {
  a %= mod;
  if (a < 0) a += mod;
  int b = mod, u = 0, v = 1;
  while (a) {
    int t = b / a;
    b -= t * a; swap(a, b);
    u -= t * v; swap(u, v);
  }
  assert(b == 1);
  if (u < 0) u += mod;
  return u;
}

ll in[2][N][N];

int lowbit(int n) {
  return n & (-n);
}

void update(ll in[N][N], int x, int y, int val) {
  for (int i = x; i < N; i += lowbit(i)) {
    for (int j = y; j < N; j += lowbit(j)) {
      in[i][j] = in[i][j] * val % mod;
    }
  }
}

ll query(ll in[N][N], int x, int y) {
  ll ans = 1;
  for (int i = x; i; i -= lowbit(i)) {
    for (int j = y; j; j -= lowbit(j)) {
      ans = ans * in[i][j] % mod;
    }
  }
  return ans;
}

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  vector<int> a(1000001), b;
  for (int i = 2; i <= 1000000; i++) {
    if (!a[i]) {
      b.push_back(i);
      for (int j = i + i; j <= 1000000; j += i) {
        a[j] = true;
      }
    }
  }
  for (int i = 1; i <= 2500; i++) {
    for (int j = 1; j <= 2500; j++) {
      in[0][i][j] = in[1][i][j] = 1;
    }
  }
  int n, m, q;
  cin >> n >> m >> q;
  map<tuple<int, int, int, int>, int> mp;
  while (q--) {
    int t, x1, y1, x2, y2;
    cin >> t >> x1 >> y1 >> x2 >> y2;
    if (t == 3) {
      cout << (query(in[0], x1, y1) == query(in[0], x2, y2) && query(in[1], x1, y1) == query(in[1], x2, y2) ? "Yes" : "No") << endl;
    } else {
      int k1, k2;
      if (t == 1) {
        k1 = b.back();
        b.pop_back();
        mp[{x1, y1, x2, y2}] = k1;
        k2 = inverse(k1, mod);
      } else {
        k1 = inverse(mp[{x1, y1, x2, y2}], mod);
        k2 = inverse(k1, mod);
      }
      for (int i = 0; i < 2; i++) {
        update(in[i], x1, y1, k1);
        update(in[i], x2 + 1, y1, k2);
        update(in[i], x1, y2 + 1, k2);
        update(in[i], x2 + 1, y2 + 1, k1);
      }
    }
  }
  return 0;
}
