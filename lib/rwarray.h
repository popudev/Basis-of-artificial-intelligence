#ifndef RW_ARRAY_H
#define RW_ARRAY_H

#include <iostream>
#include <fstream>

using namespace std;

// Định nghĩa hàm đọc mảng 2 chiều từ file.
void readMatrix(string fileName, int **&arr, int &n)
{
  ifstream inputFile(fileName);
  if (inputFile.is_open())
  {
    inputFile >> n;
    arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
      arr[i] = new int[n];
      for (int j = 0; j < n; j++)
      {
        inputFile >> arr[i][j];
      }
    }
    inputFile.close();
  }
  else
  {
    cout << "Cannot open input file." << endl;
  }
}

void printMatrix(int **arr, int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

#endif
