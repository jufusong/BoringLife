#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  int n, cnt = 0;
  cin >> n;
  vector<int> a(n + 1, -1);
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    if (a[x] == -1) {
      cnt++;
    }
    a[i] = 0;
    a[x] = -1;
  }
  cout << cnt << endl;
  return 0;
}
