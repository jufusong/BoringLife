#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  vector<vector<int>> a(1201);
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  for (int i = n - 1; i >= 0; i--) {
    a[b[i] + i].push_back(i);
  }
  for (auto vec : a) {
    for (auto x : vec) {
      cout << x + 1 << " ";
    }
  }
  return 0;
}
