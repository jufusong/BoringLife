#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n, sum = 0;
  cin >> n;
  vector<int> a(n), vis(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      for (int j = i + 1; j < n; j++) {
        if (!vis[j] && a[i] + a[j] == sum / (n / 2)) {
          vis[i] = vis[j] = true;
          cout << i + 1 << " " << j + 1 << endl;
          break;
        }
      }
    }
  }
  return 0;
}
