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

  FILE *f = fopen("array1.txt", "rt");

  int n;
  fscanf(f, "%d", &n);

  int count = 0;
  int a[100][100];

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      fscanf(f, "%d", &a[i][j]);
      if (is_prime(a[i][j]))
      {
        count++;
      }
    }
  }

  f = fopen("array1.out.txt", "wt");
  fprintf(f, "%6d", count);

  fclose(f);
  return 0;
}