#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n, cnt = 0;
  cin >> n;
  for (int i = 0; i < 2 * n; ++i) {
    int t;
    cin >> t;
    if (i & 1) cnt += t;
  }
  cout << min(cnt, n - cnt) << endl;
  return 0;
}
