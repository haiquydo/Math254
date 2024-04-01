#include <stdio.h>
void in_taphop(int a[], int n, char c)
{

  printf("\n %c = {", c);
  for (int i = 0; i < n; i++)
  {
    printf("%d", a[i]);
    if (i != n - 1)
    {
      printf(",");
    }
  }
  printf("}");
}
int check(int arr[], int n, int value)
{
  for (int i = 0; i < n; i++)
  {
    if (arr[i] == value)
    {
      return 1;
    }
  }
  return 0;
}
int checkAconB(int a[], int na, int b[], int nb)
{
  for (int i = 0; i < na; i++)
  {
    int found = 0;
    for (int j = 0; i < nb; j++)
    {
      if (a[i] == b[j])
      {
        found = 1;
        break;
      }
    }
    if (!found)
    {
      return 0;
    }
  }
  return 1;
}
void checkAgiaoB(int a[], int na, int b[], int nb, int c[])
{
  int nc = 0;
  for (int i = 0; i < na; i++)
  {
    for (int j = 0; j < nb; j++)
      if (a[i] == b[j])
      {
        c[nc] = a[i];
        nc++;
      }
  }
  in_taphop(c, nc, 'C');
}
void checkAhợpB(int a[], int na, int b[], int nb, int c[])
{
  int k = 0;
  for (int i = 0; i < na; i++)
  {
    c[k++] = a[i];
  }
  for (int j = 0; j < nb; j++)
  {
    if (!check(a, na, b[j]))
    {
      c[k++] = b[j];
    }
  }
  in_taphop(c,k,'C');
}
int main()
{
  int a[] = {1, 2}, b[] = {4, 1, 2}, na = 2, nb = 3, c[10], nc;
  // in_taphop(a,na,'A');
  // in_taphop(b,nb,'B');
  if (checkAconB(a, na, b, nb))
  {
    printf("\n A la con cua B");
  }
  else
  {
    return 0;
  }
  checkAgiaoB(a, na, b, nb, c);
  checkAhợpB(a, na, b, nb, c);

  return 0;
}
