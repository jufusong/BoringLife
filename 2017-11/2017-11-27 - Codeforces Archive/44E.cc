#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int k, a, b;
  string s;
  cin >> k >> a >> b >> s;
  auto check = [](int k, int a, int b, int size) {
    return a * k <= size && b * k >= size;
  };
  if (check(k, a, b, s.size())) {
    while (k--) {
      for (int j = a; j <= b; j++) {
        if (check(k, a, b, s.size() - j)) {
          cout << s.substr(0, j) << endl;
          s = s.substr(j);
          break;
        }
      }
    }
  } else {
    cout << "No solution" << endl;
  }
  return 0;
}
