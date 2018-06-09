//Fk data structure!
#include <iostream>
#include <cstdio>
using namespace std;

const int maxn = 500005;

int a[maxn], c[maxn];
int n, m, op, k, x, l, r;

inline int lowbit(int x) {
  return x & (-x);
}

void update(int k, int x) {
  for (int i = k; i <= n; i += lowbit(i)) {
    c[i] += x;
  }
}

int getsum(int x) {
  int ans = 0;
  for (int i = x; i; i -= lowbit(i)) { 
    ans += c[i];
  } 
  return ans;
}

int ask(int l, int r) {
  return getsum(r) - getsum(l - 1);
}

int find_kth(int k) {
  int ans = 0, cnt = 0, i;
  for (i = 20; i >= 0; i--) {
    ans += (1 << i);
    if (ans >= maxn || cnt + c[ans] >= k) ans -= (1 << i);
    else cnt += c[ans];
  }
  return ans + 1;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    update(i, a[i]);
  }
  for (int j = 1; j <= m; j++) {
    scanf("%d", &op);
    if (op == 1) {
      scanf("%d%d", &k, &x);
      update(k, x);
    } else {
      scanf("%d%d", &l, &r);
      printf("%d\n", ask(l, r));
    }
  }
}
