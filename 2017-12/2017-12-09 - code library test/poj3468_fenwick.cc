#include <vector>
#include <cstdio>

using namespace std;

template <class T> struct FenwickTree {
  std::vector<T> in;
  int N;
  FenwickTree(int N) : N(N), in(N) {}
  void update(int at, T by) {
    for (int i = at; i < N; i += (i & -i)) {
      in[i] += by;
    }
  }
  T query(int at) {
    T sum = 0;
    for (int i = at; i; i -= (i & -i)) {
      sum += in[i];
    }
    return sum;
  }
};

template <class T> struct FenwickTreeRangeUpdate {
  FenwickTree<T> add, mul;
  FenwickTreeRangeUpdate(int N) : add(N), mul(N) {}
  void update(int left, int right, T by) {
    mul.update(left, by), mul.update(right, -by);
    add.update(left, -by * (left - 1)), add.update(right, by * right);
  }
  T query(int at) {
    return mul.query(at) * at + add.query(at);
  }
};

int main(int argc, char *argv[]) {
  int n, Q;
  scanf("%d%d", &n, &Q);
  FenwickTreeRangeUpdate<long long> tree(n + 1);
  for (int i = 1; i <= n; i++) {
    int t;
    scanf("%d", &t);
    tree.update(i, i, t);
  }
  char s[5];
  for (int i = 0; i < Q; ++i) {
    int l, r;
    scanf("%s%d%d", s, &l, &r);
    if (s[0] == 'C') {
      int v;
      scanf("%d", &v);
      tree.update(l, r, v);
    } else {
      printf("%lld\n", tree.query(r) - tree.query(l - 1));
    }
  }
  return 0;
}
