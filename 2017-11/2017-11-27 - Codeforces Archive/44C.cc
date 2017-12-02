#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n, m;
  cin >> n >> m;
  std::vector<int> a(n + 1, 0);
  for (int i = 0; i < m; ++i) {
    int l, r;
    cin >> l >> r;
    for (int j = l; j <= r; ++j) {
      a[j]++;
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (a[i] != 1) {
      cout << i << " " << a[i] << endl;
      return 0;
    }
  }
  cout << "OK" << endl;
  return 0;
}
