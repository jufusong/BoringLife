#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n, T;
  cin >> n >> T;
  for (int i = 1, v; i <= n; i++) {
    cin >> v;
    T -= (86400 - v);
    if (T <= 0) {
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}
