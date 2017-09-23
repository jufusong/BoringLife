#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n, x;
  cin >> n >> x;
  set<int> se;
  for (int i = 0, t; i < n; i++) {
    cin >> t;
    se.insert(t);
  }
  int cnt = x;
  if (se.count(x)) cnt++;
  for (auto v : se) {
    if (v < x) cnt--;
  }
  cout << cnt << endl;
  return 0;
}
