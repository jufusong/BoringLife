#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  vector<pair<int, int>> a(n + 1);
  vector<int> b, c;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  int x = -1;
  for (int i = 1; i <= n; i++) {
    if (a[i].first == 0) {
      if (x != -1) {
        int j = i;
        for (; a[j].second; j = a[j].second);
        a[j].second = x;
        a[x].first = j;
      }
      x = i;
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << a[i].first << " " << a[i].second << endl;
  }
  return 0;
}
