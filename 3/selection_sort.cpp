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

int selectionSort(int A[], int N)
{
  int i, j, t, sw = 0, minj;
  for (i = 0; i < N - 1; i++) {
    minj = i;
    for (j = i; j < N; j++) {
      if (A[j] < A[minj]) minj = j;
    }
    t = A[i]; A[i] = A[minj]; A[minj] = t;
    trace(A, N);
    if (i != minj) sw++;
  }

  return sw;
}

int main()
{
  int A[100], N, i, sw;
  cin >> N;
  for (i = 0; i < N; i++) cin >> A[i];

  sw = selectionSort(A, N);

  cout << sw << endl;
  return 0;
}
