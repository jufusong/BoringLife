#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;
const int MAXL = 105;

struct MAT {
  int len;
  ll a[MAXL][MAXL];
  MAT(int l = MAXL) {
    memset(a, 0, sizeof(a));
    len = l;
  }
  friend MAT operator*(const MAT &x, const MAT &y) {
    int len = x.len;
    MAT ans(len);
    for (int i = 0; i < len; i++) {
      for (int j = 0; j < len; j++) {
        for (int k = 0; k < len; k++) {
          ans.a[i][j] = (ans.a[i][j] + x.a[i][k] * y.a[k][j]) % mod;
        }
      }
    }
    return ans;
  }
  friend MAT operator^(const MAT &x, ll n) {
    int len = x.len;
    MAT ans(len);
    MAT a = x;
    for (int i = 0; i < len; i++) {
      ans.a[i][i] = 1;
    }
    while (n) {
      if (n & 1) {
        ans = ans * a;
      }
      a = a * a;
      n >>= 1;
    }
    return ans;
  }
};

int main(int argc, char *argv[]) {
  int n, L, M;
  scanf("%d%d%d", &n, &L, &M);
  vector<int> a(M);
  for (int i = 0, t; i < n; i++) {
    scanf("%d", &t);
    a[t % M]++;
  }
  vector<ll> sum(M), c(n);
  for (int i = 0, t; i < n; i++) {
    scanf("%d", &t);
    c[i] = t;
    sum[t % M]++;
  }
  vector<ll> b(M);
  vector<ll> d(M);
  for (int i = 0, t; i < n; i++) {
    scanf("%d", &t);
    d[(t + c[i]) % M]++;
    //    for (int j = 0; j < M; j++) {
    //  b[(t + j + c[i]) % M] = (b[(t + j + c[i]) % M] + a[j]) % mod;
    //}
  }
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < M; j++) {
      b[(i + j) % M] = (b[(i + j) % M] + a[j] * d[i]) % mod;
    }
  }
  MAT m(M);
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < M; j++) {
      m.a[i][(i + j) % M] += sum[j];
    }
  }
  m = (m ^ (L - 2));
  ll ans = 0;
  for (int i = 0; i < M; i++) {
    ans = (ans + m.a[i][0] * b[i]) % mod;
  }
  cout << ans << endl;
  return 0;
}
