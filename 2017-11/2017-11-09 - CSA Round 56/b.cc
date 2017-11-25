#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char *argv[]) {
  int T, C, N;
  cin >> T >> C >> N;
  vector<tuple<int, int, int>> a;
  for (int i = 0, x, y, s; i < N; i++) {
    cin >> x >> y >> s;
    a.emplace_back(x, y, s);
  }
  for (int i = 0; i < T; i++) {
    int cnt = 0;
    for (auto e : a) {
      int x, y, S;
      tie(x, y, S) = e;
      if ((ll)(x + i * C) * S == (ll)y * C) {
        cnt++;
      }
    }
    cout << cnt << endl;
  }
  return 0;
}
