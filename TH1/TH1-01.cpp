#include <iostream>

int random(int n)
{
  return 1 + rand() % (n + 1);
}

int main()
{
  srand(time(NULL));
  FILE *f = fopen("array2.txt", "wt");
  int m = 3, n = 4;
  fprintf(f, "%6d%6d", m, n);

  for (int i = 0; i < m; i++)
  {
    fprintf(f, "\n");
    for (int j = 0; j < n; j++)
    {
      fprintf(f, "%6d", random(10));
    }
  }

  fclose(f);
  return 0;
}