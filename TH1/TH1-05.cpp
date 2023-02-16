#include <iostream>
#include <cmath>
using namespace std;

int random(int n)
{
  return 1 + rand() % (n * n + 1);
}

int main()
{
  srand(time(NULL));

  int n = 5;
  bool check[n * n];
  FILE *f = fopen("taci.txt", "wt");
  int i = 0, j = 0;

  while (i != n)
  {
    int k = random(n);
    while (check[k] == true)
    {
      k = random(n);
    }

    check[k] = true;

    fprintf(f, "%6d", k);

    if (j != n - 1)
    {
      j++;
    }
    else
    {
      fprintf(f, "\n");
      j = 0;
      i++;
    }
  }

  fclose(f);

  return 0;
}