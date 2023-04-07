#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 100

struct Point
{
  int x, y;
};

Point points[1000000];
int n = 0;

bool comparePoints1(Point a, Point b)
{
  return a.x < b.x;
}

bool comparePoints3(Point a, Point b)
{
  return a.x > b.x;
}

void readArr(Point points[], int &n)
{
  FILE *f = fopen("line2.txt", "rt");
  fscanf(f, "%d", &n);

  for (int i = 0; i < n; i++)
  {

    fscanf(f, "%d", &points[i].x);
    fscanf(f, "%d", &points[i].y);
  }

  fclose(f);
}

void writeArr(Point points[], int &n)
{
  for (int i = 0; i < n; i++)
  {
    cout << points[i].x << " " << points[i].y;
    cout << endl;
  }
  cout << endl;
}

void greedy1(Point points[], int n)
{
  sort(points, points + n, comparePoints1);
  // writeArr(points, n);
  // cout << "(" << points[0].x << "," << points[0].y << ") ";
  Point current = points[0];
  int count = 1;
  for (int i = 1; i < n; i++)
  {
    if (points[i].x > current.y)
    {
      // cout << "(" << points[i].x << "," << points[i].y << ") ";
      current = points[i];
      count++;
    }
  }

  cout << endl;
  cout << "So luong diem khong bi trung nhau la: " << count << endl;
}

void greedy3(Point points[], int n)
{
  sort(points, points + n, comparePoints3);
  // writeArr(points, n);
  // cout << "(" << points[0].x << "," << points[0].y << ") ";
  Point current = points[0];
  int count = 1;
  for (int i = 1; i < n; i++)
  {
    if (points[i].y < current.x)
    {
      // cout << "(" << points[i].x << "," << points[i].y << ") ";
      current = points[i];
      count++;
    }
  }

  cout << endl;
  cout << "So luong diem khong bi trung nhau la: " << count;
}

int main()
{
  readArr(points, n);
  // writeArr(points, n);

  greedy1(points, n);
  greedy3(points, n);

  return 0;
}