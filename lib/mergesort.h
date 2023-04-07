#ifndef MERGESORT_H
#define MERGESORT_H

template <typename T>
void merge(T *arr, int l, int m, int r, bool (*cmp)(T, T))
{
  int i = l, j = m + 1, k = 0;
  T *temp = new T[r - l + 1];
  while (i <= m && j <= r)
  {
    if (cmp(arr[i], arr[j]))
      temp[k++] = arr[i++];
    else
      temp[k++] = arr[j++];
  }
  while (i <= m)
    temp[k++] = arr[i++];
  while (j <= r)
    temp[k++] = arr[j++];
  for (i = l, k = 0; i <= r; i++, k++)
    arr[i] = temp[k];
  delete[] temp;
}

template <typename T>
void mergeSort(T *arr, int l, int r, bool (*cmp)(T, T))
{
  if (l >= r)
    return;
  int m = l + (r - l) / 2;
  mergeSort(arr, l, m, cmp);
  mergeSort(arr, m + 1, r, cmp);
  merge(arr, l, m, r, cmp);
}

#endif // MERGESORT_H
