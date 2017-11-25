#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  string s;
  cin >> s;
  for (int i = 0; i < 1 << 3; i++) {
    int sum = s[0] - '0';
    for (int j = 0; j < 3; j++) {
      if ((1 << j) & i) {
        sum += s[j + 1] - '0';
      } else {
        sum -= s[j + 1] - '0';
      }
    }
    if (sum == 7) {
      auto putc = [](bool x) {
        return x ? '+' : '-';
      };
      cout << s[0] << putc(1 & i) << s[1] << putc(2 & i) << s[2] << putc(4 & i) << s[3] << "=7" << endl;
      return 0;
    }
  }
  return 0;
}
