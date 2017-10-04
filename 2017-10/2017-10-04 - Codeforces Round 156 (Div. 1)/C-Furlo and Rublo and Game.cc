#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1000005;

struct FW {
  int in[N];

  int lowbit(int n) {return n & (-n);}

  void update(int p, int val) {
    for (int i = p; i < N; i += lowbit(i)) {
      in[i] += val;
    }
  }

  int query(int p) {
    int sum = 0;
    for (int i = p; i; i -= lowbit(i)) {
      sum += in[i];
    }
    return sum;
  }
}fw[20];

int main(int argc, char *argv[]) {
  auto cal = [](ll n) {
    int x = ceil(pow(n, 0.25));
    int y = floor(sqrt(n));
    y = min((ll)y, n - 1);
    for (int j = 0; ; j++) {
      assert(j < 20);
      if (fw[j].query(y + 1) - fw[j].query(x) == 0) {
        return j;
      }
    }
    return -1;
  };
  fw[0].update(1, 1);
  for (int i = 1; i <= 1000000; i++) {
    int ret = cal(i);
    fw[ret].update(i + 1, 1);
  }
  cin.sync_with_stdio(false);
  int n;
  cin >> n;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ll t;
    cin >> t;
    ans ^= cal(t);
  }
  cout << (ans == 0 ? "Rublo" : "Furlo") << endl;
  return 0;
}
