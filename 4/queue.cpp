#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#define LEN 100005
using namespace std;

typedef struct pp {
  char name[100];
  int t;
} P;

P Q[LEN];
int head, tail, n;

void enqueue(P x)
{
  Q[tail] = x;
  tail = (tail + 1) % LEN;
}

P dequeue()
{
  P x = Q[head];
  head = (head + 1) % LEN;
  return x;
}

int main()
{
  ifstream in("input.txt");
  cin.rdbuf(in.rdbuf());

  int elaps = 0, c;
  int i, q;
  P u;
  cin >> n >> q;

  for (i = 1; i <= n; i++) {
    cin >> Q[i].name >> Q[i].t;
  }
  head = 1; tail = n + 1;

  while (head != tail) {
    u = dequeue();
    c = min(q, u.t);
    u.t -= c;
    elaps += c;
    if (u.t > 0) {
      enqueue(u);
    }
    else {
      printf("%s %d\n", u.name, elaps);
    }
  }
}
