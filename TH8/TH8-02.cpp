#include "../lib/rwarray.h"

#define N 100

// Tính giá trị H1 của trạng thái ban đầu đối với trạng thái kết thúc.
int h1(int **a, int **b, int n)
{
  int diff = 0;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (a[i][j] != b[i][j])
      {
        diff++;
      }
    }
  }
  return diff;
}

// Tính giá trị H2 của trạng thái ban đầu đối với trạng thái kết thúc.
int h2(int **a, int **b)
{
  int dist = 0;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (a[i][j] == 0)
      {
        continue;
      }
      int x = (a[i][j] - 1) / N;
      int y = (a[i][j] - 1) % N;
      dist += abs(x - i) + abs(y - j);
    }
  }
  return dist;
}

int main()
{
  int **a;
  int n;

  readMatrix("bandau.txt", a, n);
  printMatrix(a, n);

  return 0;
}