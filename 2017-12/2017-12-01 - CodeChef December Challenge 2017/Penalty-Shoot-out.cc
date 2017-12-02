#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  string s;
  while (cin >> s) {
    auto solve = [](string s) {
      auto check = [](int s1, int s2, int x, int y) {
        if (x <= 5) {
          if (s1 - s2 > 5 - y) {
            printf("TEAM-A %d\n", x + y);
            return 1;
          }
          if (s2 - s1 > 5 - x) {
            printf("TEAM-B %d\n", x + y);
            return 1;
          }
        }
        if (x >= 5 && x == y) {
          if (s1 > s2) {
            printf("TEAM-A %d\n", x + y);
            return 1;
          }
          if (s2 > s1) {
            printf("TEAM-B %d\n", x + y);
            return 1;
          }
        }
        return 0;
      };
      int s1 = 0, s2 = 0, x = 0, y = 0;
      for (int i = 0; i < 20; ++i) {
        if (i & 1) {
          s2 += (s[i] == '1'), y++;
        } else {
          s1 += (s[i] == '1'), x++;
        }
        if (check(s1, s2, x, y)) return;
      }
      puts("TIE");
      return;
    };
    solve(s);
  }
  return 0;
}
