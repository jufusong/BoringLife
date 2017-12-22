#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  auto check = [](int n) {
    string s = to_string(n);
    string t = s;
    reverse(t.begin(), t.end());
    return s == t;
  };
  long long S = 0;
  set<int> se;
  for (int i = 1; i <= 10000; i++) {
    int sum = i * i;
    for (int j = i + 1; j <= 10000; j++) {
      sum += j * j;
      if (sum > 100000000) break;
      if (check(sum)) {
        se.insert(sum);
      }
    }
  }
  cout << se.size() << endl;
  for (auto x : se) {
    S += x;
  }
  cout << S << endl;
  return 0;
}
