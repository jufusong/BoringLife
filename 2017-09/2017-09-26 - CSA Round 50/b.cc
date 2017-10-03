#include <bits/stdc++.h>

using namespace std;

int a[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string s[] = {"Monday", "Tuesday",  "Wednesday", "Thursday",
              "Friday", "Saturday", "Sunday"};

int main(int argc, char *argv[]) {
  for (int i = 1; i <= 12; i++) {
    a[i] += a[i - 1];
  }
  string t;
  cin >> t;
  int now = 0;
  for (int i = 0; i < 7; i++) {
    if (s[i] == t) now = i;
  }
  int ans = 0;
  for (int i = 1; i <= 12; i++) {
    if ((now + a[i - 1] + 12) % 7 == 4) ans++;
  }
  cout << ans << endl;
  return 0;
}
