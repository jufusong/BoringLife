#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  int n;
  cin >> n;
  priority_queue<ll, vector<ll>, greater<ll>> q;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    q.push(t);
  }
  ll ans = 0;
  bool f = true;
  while (q.size() > 1) {
    ll t1 = q.top();
    q.pop();
    ll t2 = q.top();
    q.pop();
    ll t3 = 0;
    if (!f || n % 2) {
      t3 = q.top();
      q.pop();
    }
    f = false;
    q.push(t1 + t2 + t3);
    ans += t1 + t2 + t3;
  }
  cout << ans << endl;
  return 0;
}
