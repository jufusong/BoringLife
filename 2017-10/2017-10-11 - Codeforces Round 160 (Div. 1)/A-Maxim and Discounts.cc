#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  int m;
  cin >> m;
  vector<int> a(m);
  for (int i = 0; i < m; i++) {
    cin >> a[i];
  }
  int n;
  cin >> n;
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end(), greater<int>());
  int sum = 0;
  for (int i = 0, now = 0; i < n; i++) {
    sum += b[i];
    now++;
    if (now == a[0]) i += 2, now = 0;
  }
  cout << sum << endl;
  return 0;
}
