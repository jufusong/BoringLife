#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n, K;
  cin >> n >> K;
  if (n == 2 && K == 0) {
    puts("-1");
    return 0;
  }
  if (n == 3 && K == 0) {
    puts("-1");
    return 0;
  }
  int fk = 1;
  vector<tuple<int, int, int>> vec;
  for (int i = 1; i < n; i++) {
    vec.push_back({i, i + 1, fk++});
  }
  K = n - 1 - K;
  for (int i = 1; i <= K; i++) {
    if (i < n - 1) {
      vec.push_back({i, n, fk++});
    } else {
      vec.push_back({1, n - 1, fk++});
    }
  }
  cout << vec.size() << endl;
  for (auto e : vec) {
    cout << get<0>(e) << " " << get<1>(e) << " " << get<2>(e) << endl;
  }
  return 0;
}
