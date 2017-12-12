#include <bits/stdc++.h>

using namespace std;

template <class T> struct Treap {
  struct Node {
    int sz, fix;
    T key;
    Node* ch[2];
    Node(T key) : key(key) {
      sz = 1, fix = rand(), ch[0] = ch[1] = nullptr;
    }
    void pushup() {
      sz = 1;
      if (ch[0]) sz += ch[0]->sz;
      if (ch[1]) sz += ch[1]->sz;
    }
  }*root;
  Treap() : root(nullptr) {}
  
  void insert(T x) {insert(root, x);}
  Node* find_by_order(int k) {return find_by_order(root, k + 1);}
  int order_of_key(T val) {return order_of_key(root, val);}
  Node* lower_bound(T val) {return lower_bound(root, val);}
  void erase(T val) {erase(root, val);}
  
private:
  void rotate(Node* &t, int d) {
    Node* k = t->ch[d ^ 1];
    t->ch[d ^ 1] = k->ch[d];
    k->ch[d] = t;
    t->pushup();
    k->pushup();
    t = k;
  }
  
  void insert(Node* &t, T x) {
    if (t == nullptr) t = new Node(x);
    else {
      int d = (x < t->key ? 0 : 1);
      insert(t->ch[d], x);
      if (t->ch[d]->fix > t->fix) {
        rotate(t, d ^ 1);
      }
    }
    t->pushup();
  }

  void erase(Node* &t, T x) {
    if (t->key == x) {
      if (t->ch[0] == nullptr) {
        t = t->ch[1];
      } else if (t->ch[1] == nullptr) {
        t = t->ch[0];
      } else {
        int d = (t->ch[0]->fix < t->ch[1]->fix);
        rotate(t, d ^ 1);
        erase(t->ch[d ^ 1],x);
        t->pushup();
      }
    } else {
      erase(t->ch[t->key < x], x);
      t->pushup();
    }
  }
  
  Node* find_by_order(Node* t, int k) {
    int lsz = (t->ch[0] ? t->ch[0]->sz : 0);
    if (lsz == k - 1) return t;
    else return lsz >= k ? find_by_order(t->ch[0], k) : find_by_order(t->ch[1], k - lsz - 1);
  }

  int order_of_key(Node* t, T val) {
    if (t == nullptr) return 0;
    int lsz = (t->ch[0] ? t->ch[0]->sz : 0);
    if (t->key < val) return lsz + 1 + order_of_key(t->ch[1], val);
    return order_of_key(t->ch[0], val);
  }

  Node* lower_bound(Node* t, T val) {
    if (t == nullptr) return nullptr;
    if (t->key < val) return lower_bound(t->ch[1], val);
    auto ret = lower_bound(t->ch[0], val);
    return ret == nullptr ? t : ret;
  }
};

int main(int argc, char *argv[]) {
  Treap<long long> tree;
  set<long long> se;
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int op, x;
    scanf("%d%d", &op, &x);
    long long v = x;
    if (op == 1) {
      tree.insert(v << 20 | i);
      se.insert(v << 20 | i);
    } else if (op == 2) {
      tree.erase(tree.lower_bound(v << 20)->key);
      se.erase(se.lower_bound(v << 20));
    } else if (op == 3) {
      auto it = tree.lower_bound(v << 20);
      printf("%d\n", (int)tree.order_of_key(it->key) + 1);
    } else if (op == 4) {
      printf("%d\n", (int)(tree.find_by_order(v - 1)->key >> 20));
    } else if (op == 5) {
      auto it = se.lower_bound(v << 20);
      --it;
      printf("%d\n", (int)(*it >> 20));
    } else {
      auto it = tree.lower_bound((v + 1) << 20);
      printf("%d\n", (int)(it->key >> 20));
    }
  }  
  return 0;
}
