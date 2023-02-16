#include <iostream>
#include <cmath>
using namespace std;

bool is_prime(int n)
{
  if (n <= 1)
    return false;
  for (int i = 2; i <= sqrt(n); i++)
  {
    if (n % i == 0)
      return false;
  }
  return true;
}

int main()
{

  FILE *f = fopen("array2.txt", "rt");
  FILE *fout = fopen("array2.out.txt", "wt");
  int m, n;
  fscanf(f, "%d", &m);
  fscanf(f, "%d", &n);

  int temp;
  int count = 0;
  int sumRow = 0;
  int sumCol = 0;
  int a[100][100];

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      fscanf(f, "%d", &a[i][j]);
    }
  }

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (is_prime(a[i][j]))
      {
        count++;
      }
    }
  }

  fprintf(fout, "Cau 1: %6d\n", count);

  fprintf(fout, "Cau 2: ");
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      sumRow += a[i][j];
    }
    fprintf(fout, "%6d", sumRow);
    sumRow = 0;
  }

  fprintf(fout, "\nCau 3: ");
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      sumCol += a[j][i];
    }
    fprintf(fout, "%6d", sumCol);
    sumCol = 0;
  }

  return 0;
}