#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  vector<int> a, b;
  string s;
  cin >> s;
  s += 'T';
  int now = 0, dir = 0;
  for (auto c : s) {
    if (c == 'F') {
      now++;
    } else {
      dir ? b.push_back(now) : a.push_back(now);
      dir ^= 1;
      now = 0;
    }
  }
  auto check = [](int val, vector<int> a) {
    for (auto x : a) {
      val += x;
    }
    vector<int> f(val + 1);
    f[0] = 1;
    for (auto x : a) {
      for (int j = val; j - 2 * x >= 0; j--) {
        f[j] |= f[j - 2 * x];
      }
    }
    return f[val];
  };
  int x, y;
  cin >> x >> y;
  cout << (check(abs(x - a[0]), {a.begin() + 1, a.end()}) && check(abs(y), b) ? "Yes" : "No") << endl;
  return 0;
}
