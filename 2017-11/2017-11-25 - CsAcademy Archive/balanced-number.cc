#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  string s;
  cin >> s;
  vector<int> a(255);
  for (auto c : s) {
    a[c]++;
  }
  bool flag = true;
  for (int i = '1'; i <= '9'; i++) {
    flag &= (a[i] == a['0']);
  }
  cout << flag << endl;
  return 0;
}
