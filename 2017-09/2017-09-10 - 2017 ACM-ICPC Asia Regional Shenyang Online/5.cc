#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll mod = 998244353;
const int MAXL = 2;

struct MAT{
  int len;
  ll a[MAXL][MAXL];
  MAT(int l = MAXL){
    memset(a, 0, sizeof(a));
    len = l;
  }
  friend MAT operator * (const MAT& x, const MAT& y){
    int len = x.len;
    MAT ans(len);
    for(int i = 0; i < len; i ++){
      for(int j = 0; j < len; j ++){
        for(int k = 0; k < len; k ++){
          ans.a[i][j] = (ans.a[i][j] + x.a[i][k]*y.a[k][j]) % mod;
        }
      }
    }
    return ans;
  }
  friend MAT operator ^ (const MAT& x, ll n){
    int len = x.len;
    MAT ans(len);
    MAT a = x;
    for(int i = 0; i < len; i ++){
      ans.a[i][i] = 1;
    }
    while (n){
      if (n & 1){
        ans = ans * a;
      }
      a = a * a;
      n >>= 1;
    }
    return ans;
  }
};

int main(int argc, char *argv[]) {
  int n;
  while (cin >> n) {
    MAT m(2);
    m.a[0][0] = 0;
    m.a[0][1] = m.a[1][0] = m.a[1][1] = 1;
    m = (m ^ (2 * n + 3));
    cout << (m.a[1][0] + mod - 1) % mod << endl;
  }
  return 0;
}
