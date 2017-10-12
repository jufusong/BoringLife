#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int a[N], n, K;

void solve(int L, int R, int vl, int vr) {
  if (K <= 0) {
    for (int i = L, j = vl; i < R; i++, j++) {
      a[i] = j;
    }
    return;
  }
  if (L == R - 1) {
    a[L] = vl;
    return;
  }
  int m1 = (L + R) / 2, m2 = (vl + vr + 1) / 2;
  K -= 2;
  solve(L, m1, m2, vr);
  solve(m1, R, vl, m2);
}

int main(int argc, char *argv[]) {
  cin >> n >> K;
  K--;
  solve(0, n, 1, n + 1);
  if (K == 0) {
    for (int i = 0; i < n; i++) {
      cout << a[i] << " ";
    }
  } else {
    cout << -1 << endl;
  }
  return 0;
}
