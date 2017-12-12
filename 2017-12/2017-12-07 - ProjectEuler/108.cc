#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  for (long long i = 1; ; ++i) {
    int cnt = 0;
    for (long long j = i + 1; j <= 2 * i; j++) {
      cnt += (i * j % (j - i) == 0);
    }
    cout << i << " " << cnt << endl;
    if (cnt > 1000) break;
  }

  return 0;
}
