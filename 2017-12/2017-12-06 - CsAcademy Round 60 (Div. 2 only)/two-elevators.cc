#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n, E[2];
  cin >> n >> E[0] >> E[1];
  vector<int> b(4, 0);
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].first >> a[i].second;
  }
  for (int i = 0; i < n; ++i) {
    int x = a[i].first, y = a[i].second;
    for (int j = 0; j < 4; ++j) {
      bool flag = false;
      for (int k = 0; k < 2; ++k) {
        if (x < y) {
          flag |= (((1 << k) & j) && x >= E[k]);
        } else {
          flag |= (!((1 << k) & j) && x <= E[k]);
        }
      }
      b[j] += flag;
    }
  }
  cout << *max_element(b.begin(), b.end()) << endl;
  return 0;
}
