#include <bits/stdc++.h>

using namespace std;

namespace oaht {

using std::size_t;

enum class node_state { FREE, IN_USE, ERASED };

template <typename _Key, typename _Value> struct node {
  _Key key;
  _Value value;
  node_state state = node_state::FREE;
};

template <typename _Key, typename _Value, typename _Hash = std::hash<_Key>>
class HashMap {
public:
  HashMap(size_t capacity) : capacity(capacity), size(0) {
    nodes = new node<_Key, _Value>[capacity];
    for (size_t i = 0; i < capacity; i++) {
      nodes[i] = node<_Key, _Value>();      
    }
  }

  HashMap() : HashMap(3) {}

  size_t count(const _Key &key) const {
    size_t index = getIndex(key, capacity);

    for (size_t d = 0; d < capacity; d++) {
      if (nodes[index].state == node_state::FREE) return false;
      if (nodes[index].state == node_state::IN_USE && nodes[index].key == key) return true;
      index++;
      if (index == capacity)index = 0;
    }
    return false;
  }

  void erase(const _Key &key) {
    size_t index = getIndex(key, capacity);
    for (size_t d = 0; d < capacity; d++) {
      if (nodes[index].state == node_state::FREE) break;
      if (nodes[index].state == node_state::IN_USE && nodes[index].key == key) {
        nodes[index].state = node_state::ERASED;
        return;
      };
      index++;
      if (index == capacity)index = 0;
    }
    throw std::logic_error("Unexpected case.");
  }
  
  _Value &operator[](const _Key &key) {
    if ((size << 1) > capacity) rehash();
    size_t index;
    bool result = put(key, index, nodes, capacity);
    if (result) size++;
    return nodes[index].value;
  }

  ~HashMap() { delete[] nodes; }

private:
  size_t getIndex(const _Key &key, size_t size) const {
    return (h(key) * 22543LL) % size;
  }

  void rehash() {
    size_t n_capacity = (capacity << 1);
    node<_Key, _Value> *n_nodes = new node<_Key, _Value>[n_capacity];
    for (size_t i = 0; i < n_capacity; i++) {
      n_nodes[i] = node<_Key, _Value>();
    }
    for (size_t i = 0; i < capacity; i++) {
      if (nodes[i].state == node_state::IN_USE) {
        size_t index;
        put(nodes[i].key, index, n_nodes, n_capacity);
        n_nodes[index].value = nodes[i].value;
      }
    }
    delete[] nodes;
    nodes = n_nodes;
    capacity = n_capacity;
  }

  bool put(const _Key &key, size_t &index, node<_Key, _Value> *nodes, size_t nodes_length) {
    index = getIndex(key, nodes_length);
    for (size_t i = 0; i < nodes_length; i++) {
      if (nodes[index].state == node_state::FREE || nodes[index].state == node_state::ERASED) {
        nodes[index].key = key;
        nodes[index].state = node_state::IN_USE;
        return true;
      }
      if (nodes[index].key == key) return false;
      index++;
      if (index == nodes_length) index = 0;
    }
    throw std::logic_error("Unexpected case.");
  }
  size_t capacity;
  size_t size;
  node<_Key, _Value> *nodes;
  _Hash h;
};
} // namespace oaht

typedef unsigned long long H;
static const H C = 123891739;

typedef H K;

struct HashInterval {
  vector<K> ha, pw;
  HashInterval(string &str) : ha(str.size() + 1), pw(ha) {
    pw[0] = 1;
    for (int i = 0; i < str.size(); ++i) {
      ha[i + 1] = ha[i] * C + str[i], pw[i + 1] = pw[i] * C;  
    }
  }
  H hashInterval(int a, int b) {
    return ha[b] - ha[a] * pw[b - a];
  }
};

char t[1000005];

int main(int argc, char *argv[]) {
  int BK = 100;
  scanf("%s", t);
  string s(t);
  HashInterval hi(s);
  oaht::HashMap<K, vector<int>> mp;
  for (int i = 0; i < s.size(); i++) {
    for (int j = 1; j <= BK && j <= i + 1; j++) {
      mp[hi.hashInterval(i - j + 1, i + 1)].push_back(i);
    }
  }
  int Q;
  scanf("%d", &Q);
  while (Q--) {
    int l, r;
    scanf("%d%d%s", &l, &r, t);
    string z(t);
    H key = HashInterval(z).hashInterval(0, z.size());
    if (z.size() > BK) {
      int cnt = 0;
      for (int i = l - 1 + z.size(); i <= r; i++) {
        cnt += (key == hi.hashInterval(i, i + z.size()));
      }
      printf("%d\n", cnt);
    } else {
      l = l - 1 + z.size();
      auto& vec = mp[key];
      int cnt = upper_bound(vec.begin(), vec.end(), r) - lower_bound(vec.begin(), vec.end(), l);
      printf("%d\n", cnt);
    }
  }
  return 0;
}
