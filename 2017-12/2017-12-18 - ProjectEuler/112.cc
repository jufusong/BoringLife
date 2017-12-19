#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int cnt = 0;
  auto check = [](int n) {
    string s = to_string(n);
    int x = 0;
    for (int i = 1; i < s.size(); i++) {
      if (s[i] > s[i - 1]) {
        x |= 2;
      }
      if (s[i] < s[i - 1]) {
        x |= 1;
      }
    }
    return x != 3;
  };
  for (int i = 1; ; i++) {
    cnt += check(i);
    cout << i << " " << cnt << " " << cnt * 1.0 / i << endl;
    if (cnt * 100 <= i) break;
  }
  return 0;
}
