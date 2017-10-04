#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n, K, C;
  cin >> n >> K >> C;
  vector<bool> a(n + 1);
  for (int i = 0; i < C; i++) {
    int t;
    cin >> t;
    a[t] = true;
  }
  int cnt = 0;
  for (int i = 1, now = 0; i <= n; i++) {
    if (a[i]) {
      cnt++, now = 0;
    } else {
      now++;
      cnt += now / K;
      now %= K;
    }
  }
  cout << cnt << endl;
  return 0;
}
