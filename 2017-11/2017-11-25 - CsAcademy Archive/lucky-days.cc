#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n, sum = 0;
  cin >> n;
  for (int i = 0, now = 0; i < n; i++) {
    int t;
    cin >> t;
    sum += (t > now);
    now = max(now, t);
  }
  cout << sum << endl;
  return 0;
}
