#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int h1, a1, c1, h2, a2;
  cin >> h1 >> a1 >> c1 >> h2 >> a2;
  vector<string> vec;
  for (int i = 0; ; i++) {
    if (h2 <= a1) {
      vec.push_back("STRIKE");
      break;
    }
    if (a2 >= h1) {
      vec.push_back("HEAL");
      h1 += c1 - a2;
    } else {
      vec.push_back("STRIKE");
      h2 -= a1;
      h1 -= a2;
    }
  }
  cout << vec.size() << endl;
  for (auto x : vec) {
    cout << x << endl;
  }
  return 0;
}
