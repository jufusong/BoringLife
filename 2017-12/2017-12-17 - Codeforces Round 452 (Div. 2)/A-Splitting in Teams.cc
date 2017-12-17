#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  vector<int> a(3, 0);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int t;
    cin >> t;
    a[t]++;
  }
  cout << min(a[1], a[2]) + (a[1] > a[2] ? (a[1] - a[2]) / 3 : 0) << endl;
  return 0;
}
