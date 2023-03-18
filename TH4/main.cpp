#include <iostream>
#include <vector>
using namespace std;

void readFile(int a[][10], int &n)
{
  FILE *f = fopen("color1.txt", "rt");
  fscanf(f, "%d", &n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
    {
      {
        fscanf(f, "%d", &a[i][j]);
      }
    }
}

void printfArrayOne(int a[], int n, char *name)
{
  for (int i = 0; i < n; i++)
  {
    cout << name << "[" << i + 1 << "]: " << a[i] << "\n";
  }
  cout << endl;
}

void printfArrayTwo(int a[][10], int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << a[i][j] << "\t";
    }
    cout << endl;
  }
  cout << endl;
}

int sumEdge(int a[], int n)
{
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    sum += a[i];
  }
  return sum;
}

void sumEdgeOfAllPeak(int edge[], int peak[], int a[][10], int n)
{
  for (int i = 0; i < n; i++)
  {
    edge[i] = sumEdge(a[i], n);
    peak[i] = i + 1;
  }
}

void swapValue(int &a, int &b)
{
  a = a - b;
  b = b + a;
  a = b - a;
}

void sort(int edge[], int peak[], int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (edge[i] > edge[j])
      {
        swapValue(edge[i], edge[j]);
        swapValue(peak[i], peak[j]);
      }
    }
  }
}

int main()
{
  int n;
  int a[10][10];

  readFile(a, n);
  printfArrayTwo(a, n);

  int edge[n];
  int peak[n];
  sumEdgeOfAllPeak(edge, peak, a, n);

  printfArrayOne(edge, n, "edge");
  printfArrayOne(peak, n, "peak");
  sort(edge, peak, n);

  printfArrayOne(edge, n, "edge");
  printfArrayOne(peak, n, "peak");

  return 0;
}