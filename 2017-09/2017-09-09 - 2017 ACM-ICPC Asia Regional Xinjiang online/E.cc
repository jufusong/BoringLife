#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll a[] = {1,
          8,
          49,
          288,
          1681,
          9800,
          57121,
          332928,
          1940449,
          11309768,
          65918161,
          384199200,
          2239277041,
          13051463048,
          76069501249,
          443365544448,
          2584123765441,
          15061377048200,
          87784138523761,
          511643454094368,
          2982076586042449,
          17380816062160328};

int main(int argc, char *argv[]) {
  int T, cas = 1;
  cin >> T;
  while (T--) {
    ll x;
    cin >> x;
    cout << "Case #" << cas++ << ": " << *lower_bound(a, a + 22, x) << endl;
  }
}
