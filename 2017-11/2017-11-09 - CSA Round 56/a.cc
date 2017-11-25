#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  vector<pair<int, int>> a;
  for (int i = 0, l, r; i < n; i++) {
    cin >> l >> r;
    a.push_back({l, r});
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    int l, r;
    tie(l, r) = a[i];
    for (int j = 0; j < n; j++) {
      if (l > a[j].first && r < a[j].second) {
        cnt++;
        break;
      }
    }
  }
  cout << cnt << endl;
  return 0;
}
