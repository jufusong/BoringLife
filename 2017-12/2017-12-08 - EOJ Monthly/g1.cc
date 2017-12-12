#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int q;
  string s;
  cin >> s >> q;
  while (q--) {
    int l, r;
    string t;
    cin >> l >> r >> t;
    int cnt = 0;
    for (int i = l; i - 1 + t.size() <= r; i++) {
      cnt += (s.substr(i, t.size()) == t);
    }
    cout << cnt << endl;
  }
  return 0;
}
