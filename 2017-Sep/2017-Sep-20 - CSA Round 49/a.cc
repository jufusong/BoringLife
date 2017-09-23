#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n, cnt = 0;
  cin >> n;
  for (int i = 1, t; i <= n; i++) {
    cin >> t;
    cnt += t % 2;
  }
  cout << cnt * (n - cnt) << endl;
  return 0;
}
