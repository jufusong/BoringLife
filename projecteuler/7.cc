#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  vector<bool> v(1000001);
  for (int i = 2, now = 0; ; i++) {
    if (!v[i]) {
      now++;
      if (now == 10001) {
        cout << i << endl;
        return 0;
      }
      for (int j = i + i; j <= 1000000; j += i) {
        v[j] = true;
      }
    }
  }
  return 0;
}
