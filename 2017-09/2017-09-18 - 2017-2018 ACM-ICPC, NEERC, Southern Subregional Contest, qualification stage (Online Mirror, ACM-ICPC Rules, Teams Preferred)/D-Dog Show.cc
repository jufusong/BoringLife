#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  int n, T;
  cin >> n >> T;
  vector<int> a(n);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    q.push({a[i] - i - 1, i + 1});
  }
  q.push({0, -1});
  priority_queue<int> q2;
  int ans = 0;
  while (!q.empty()) {
    int x = q.top().first, y = q.top().second;
    q.pop();
    if (y != -1) q2.push(y);
    while(!q2.empty() && T - x <= q2.top()) q2.pop();
    if (x >= 0) {
      ans = max(ans, (int)q2.size());
    }
  }
  cout << ans << endl;
  return 0;
}
