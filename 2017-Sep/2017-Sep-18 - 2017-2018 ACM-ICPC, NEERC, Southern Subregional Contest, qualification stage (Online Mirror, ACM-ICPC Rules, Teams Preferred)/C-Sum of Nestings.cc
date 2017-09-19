#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char *argv[]) {
  ll n, K;
  cin >> n >> K;
  if (K > n * (n - 1) / 2) {
    cout << "Impossible" << endl;
    return 0;
  }
  ll p = 0;
  for (; p <= K; p++) {
    K -= p;
  }
  p--;
  int sum = 0;
  for (int i = 0; i <= p; i++) {
    cout << "(";
    sum++;
    if (i && i == K) cout << ")(", sum++;
  }
  for (int i = 0; i <= p; i++) {
    cout << ")";
  }
  for (int i = sum; i < n; i++) {
    cout << "()";
  }
  return 0;
}
