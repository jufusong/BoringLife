#include <bits/stdc++.h>

using namespace std;

const int N = 400005;

set<pair<int, int>> se;

bool equal(int x, int y) {
  if ((x & 1) && (y & 1)) return true;
  return se.count({x, y});
}

int Mp[N];
void manacher(int len) {
  int mx = 0, idx = 0;
  for (int i = 1; i < len; i++) {
    Mp[i] = (mx > i ? min(Mp[2 * idx - i], mx - i) : 1);
    while (equal(i - Mp[i], i + Mp[i])) Mp[i]++;
    if (i + Mp[i] > mx) {
      mx = i + Mp[i];
      idx = i;
    }
  }
}

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    if (x > y) swap(x, y);
    se.insert({x * 2, y * 2});
  }
  manacher(n * 2 + 1);
  int mx = 0;
  for (int i = 1; i <= n * 2; i++) {
    mx = max(mx, Mp[i] - 1);
  }
  cout << mx << endl;
  return 0;
}
