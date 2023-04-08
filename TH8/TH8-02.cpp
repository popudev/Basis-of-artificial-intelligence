#include <iostream>
#include <fstream>
#include <algorithm>
#include "../lib/rwarray.h"
#include "../lib/mergesort.h"

using namespace std;

int hmin = 99999;

struct Taci
{
  int x;
  int y;
  int value;
};

void readTaci(string fileName, Taci *&a, Taci *&b, int &n)
{
  ifstream inputFile(fileName);
  if (inputFile.is_open())
  {
    inputFile >> n;
    a = new Taci[100 * 100];
    b = new Taci[100 * 100];

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        inputFile >> a[n * i + j].value;
        a[n * i + j].x = i;
        a[n * i + j].y = j;
      }
    }

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        b[n * i + j].x = i;
        b[n * i + j].y = j;
        inputFile >> b[n * i + j].value;
      }
    }
    inputFile.close();
  }
  else
  {
    cout << "Cannot open input file." << endl;
  }
}

void printTaci(Taci *a, int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << a[n * i + j].value;
      cout << "(" << a[n * i + j].x << "," << a[n * i + j].y << ") ";
    }
    cout << endl;
  }
  cout << endl;
}

void copy(Taci *a, Taci *&clone, int n)
{
  clone = new Taci[n * n];
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      clone[n * i + j].x = a[n * i + j].x;
      clone[n * i + j].y = a[n * i + j].y;
      clone[n * i + j].value = a[n * i + j].value;
    }
  }
}

bool compareTaci(Taci a, Taci b)
{
  return a.value < b.value;
}

Taci binarySearch(Taci *arr, int n, int x)
{
  Taci temp;
  int l = 0;
  int r = n * n - 1;

  while (l <= r)
  {
    int mid = l + (r - l) / 2;

    // nếu x nằm ở giữa mảng
    if (arr[mid].value == x)
    {
      temp = arr[mid];
      return temp;
    }

    // nếu x nhỏ hơn giá trị ở vị trí mid
    if (arr[mid].value > x)
    {
      r = mid - 1;
    }

    // nếu x lớn hơn giá trị ở vị trí mid
    else
    {
      l = mid + 1;
    }
  }

  // nếu x không có trong mảng
  return temp;
}

int h1(Taci *a, Taci *b, int n)
{
  int diff = 0;

  for (int i = 0; i < n * n; i++)
  {
    if (a[i].value != 0 && a[i].value != b[i].value)
      diff++;
  }
  return diff;
}

int h2(Taci *a, Taci *b, int n)
{
  Taci *sortHienTai;
  copy(b, sortHienTai, n);
  mergeSort(sortHienTai, 0, n * n - 1, compareTaci);

  int dist = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {

      if (a[n * i + j].value == 0)
        continue;

      Taci bTemp = binarySearch(sortHienTai, n, a[n * i + j].value);

      Taci aTemp = a[n * i + j];

      while (aTemp.x != bTemp.x)
      {
        if (aTemp.x > bTemp.x)
          aTemp.x--;
        if (aTemp.x < bTemp.x)
          aTemp.x++;
        dist++;
      }

      while (aTemp.y != bTemp.y)
      {
        if (aTemp.y > bTemp.y)
          aTemp.y--;
        if (aTemp.y < bTemp.y)
          aTemp.y++;
        dist++;
      }
    }
  }
  delete sortHienTai;
  return dist;
}

void swap(Taci &a, Taci &b)
{
  Taci temp;
  temp.value = a.value;
  a.value = b.value;
  b.value = temp.value;
}

bool compareH(Taci *truocdo, Taci *hientai, Taci *ketthuc, int n)
{
  if (truocdo == nullptr || (truocdo != nullptr && h1(hientai, truocdo, n) != 0))
  {
    int h = h1(hientai, ketthuc, n);

    cout << "h: " << h << endl;
    printTaci(hientai, n);

    if (h < hmin)
    {
      hmin = h;
      return true;
    }
  }
  return false;
}
int solan = 1;

void AKT(Taci *truocdo, Taci *hientai, Taci *ketthuc, int n)
{

  if (h1(hientai, ketthuc, n) == 0)
  {
    cout << "so lan phan tich la: " << solan << endl;
    printTaci(hientai, n);
    return;
  }

  printTaci(hientai, n);

  cout << "phan tich trang thai lan : " << solan << endl;

  Taci *sortHienTai;
  copy(hientai, sortHienTai, n);
  mergeSort(sortHienTai, 0, n * n - 1, compareTaci);

  Taci taci0 = sortHienTai[0];
  int i = taci0.x;
  int j = taci0.y;

  delete sortHienTai;

  cout << "toa do diem 0: "
       << "(" << i << "," << j << ")\n\n";

  int trangthaiduocchon = 0;
  hmin = 9999999;
  solan++;

  if (i - 1 >= 0)
  {
    swap(hientai[n * i + j], hientai[n * (i - 1) + j]);
    bool isChoice = compareH(truocdo, hientai, ketthuc, n);
    swap(hientai[n * i + j], hientai[n * (i - 1) + j]);

    if (isChoice)
    {
      trangthaiduocchon = 1;
    }
  }

  if (i + 1 < n)
  {
    swap(hientai[n * i + j], hientai[n * (i + 1) + j]);
    bool isChoice = compareH(truocdo, hientai, ketthuc, n);
    swap(hientai[n * i + j], hientai[n * (i + 1) + j]);

    if (isChoice)
    {
      trangthaiduocchon = 2;
    }
  }

  if (j - 1 >= 0)
  {
    swap(hientai[n * i + j], hientai[n * i + (j - 1)]);
    bool isChoice = compareH(truocdo, hientai, ketthuc, n);
    swap(hientai[n * i + j], hientai[n * i + (j - 1)]);

    if (isChoice)
    {
      trangthaiduocchon = 3;
    }
  }

  if (j + 1 <= n - 1)
  {
    swap(hientai[n * i + j], hientai[n * i + (j + 1)]);
    bool isChoice = compareH(truocdo, hientai, ketthuc, n);
    swap(hientai[n * i + j], hientai[n * i + (j + 1)]);

    if (isChoice)
    {
      trangthaiduocchon = 4;
    }
  }

  delete truocdo;

  Taci *clone;
  copy(hientai, clone, n);

  cout << "trang thai duoc chon: " << trangthaiduocchon << endl
       << endl;

  switch (trangthaiduocchon)
  {
  case 1:
    swap(hientai[n * i + j], hientai[n * (i - 1) + j]);
    AKT(clone, hientai, ketthuc, n);
    break;

  case 2:
    swap(hientai[n * i + j], hientai[n * (i + 1) + j]);
    AKT(clone, hientai, ketthuc, n);
    break;

  case 3:
    swap(hientai[n * i + j], hientai[n * i + (j - 1)]);
    AKT(clone, hientai, ketthuc, n);
    break;

  case 4:
    swap(hientai[n * i + j], hientai[n * i + (j + 1)]);
    AKT(clone, hientai, ketthuc, n);
    break;
  }
}

int main()
{
  int n;

  Taci *a;
  Taci *b;
  readTaci("taci1.txt", a, b, n);

  cout << "h theo chieu doc, ngang: " << h2(a, b, n) << endl;

  cout << "Bat dau thuat toan\n";
  AKT(nullptr, a, b, n);

  return 0;
}