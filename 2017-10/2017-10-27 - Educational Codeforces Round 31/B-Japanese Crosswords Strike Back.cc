#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  int n, K, x = 0;
  cin >> n >> K;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    x += t;
  }
  if (K - x == n - 1) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
