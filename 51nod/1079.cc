#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int Inverse(int a, int md) {
  a %= md;
  if (a < 0) a += md;
  int b = md, u = 0, v = 1;
  while (a) {
    int t = b / a;
    b -= t * a; swap(a, b);
    u -= t * v; swap(u, v);
  }
  assert(b == 1);
  if (u < 0) u += md;
  return u;
}

int CRT(const vector<int>& a, const vector<int>& m) {
  int M = 1, ret = 0;
  for (auto x : m) {
    M *= x;
  }
  for (int i = 0; i < a.size(); i++) {
    ret = (ret + (ll)a[i] * (M / m[i]) % M * Inverse(M / m[i], m[i])) % M;
  }
  return ret;
}

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  vector<int> a(n), m(n);
  for (int i = 0; i < n; i++) {
    cin >> m[i] >> a[i];
  }
  cout << CRT(a, m) << endl;
  return 0;
}
