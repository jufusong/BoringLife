#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n, cnt = 0;
  cin >> n;
  for (int i = 0, now = -1, t; i < n; i++) {
    cin >> t;
    if (t > now) {
      cnt++;
      now = t;
    }
  }
  cout << cnt << endl;
  return 0;
}
