#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n, X;
  cin >> n >> X;
  std::vector<int> a(X + 1, 0);
  for (int i = 0; i < n; ++i) {
    int t;
    cin >> t;
    t *= (n - i);
    for (int j = X; j - t >= 0; j--) {
      a[j] = max(a[j], a[j - t] + 1);
    }
  }
  cout << a[X] << endl;
  return 0;
}
