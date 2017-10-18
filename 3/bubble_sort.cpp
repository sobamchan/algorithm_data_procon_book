#include <iostream>
using namespace std;

void trace(int A[], int N)
{
  int i;
  for (i = 0; i < N; i++) {
    if (i > 0) cout << " ";
    cout << A[i];
  }
  cout << endl;
}

int bubbleSort(int A[], int N)
{
  int sw = 0;
  bool flag = 1;
  for (int i = 0; flag; i++) {
    flag = 0;
    for (int j = N - 1; j >= i; j--) {
      if (A[j] < A[j - 1]) {
        swap(A[j], A[j - 1]);
        flag = 1;
        sw++;
      }
      trace(A, N);
    }
  }
  return sw;
}

int main()
{
  int A[100], N, sw;
  cin >> N;
  for (int i = 0; i < N; i++) cin >> A[i];

  sw = bubbleSort(A, N);

  trace(A, N);

  return 0;
}
