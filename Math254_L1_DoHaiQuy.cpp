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
int CON(int a[], int na, int b[], int nb)
{
  for (int i = 0; i < na; i++)
  {
    int found = 0;
    for (int j = 0; j < nb; j++)
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
void GIAO(int a[], int na, int b[], int nb, int c[])
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
void HOP(int a[], int na, int b[], int nb, int c[])
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
  in_taphop(c, k, 'C');
}
void BANG(int a[], int na, int b[], int nb)
{
  if (CON(a, na, b, nb) && CON(b, nb, a, na))
  {
    printf("A=B\n");
  }
  else
  {
    printf("A khac B");
  }
}
void HIEU(int a[], int na, int b[], int nb, int c[])
{
  int nc = 0;
  if (na >= nb)
  {
    for (int i = 0; i < na; i++)
    {
      int found = 0;
      for (int j = 0; j < nb && found == 0; j++)
      {
        if (a[i] == b[j])
        {
          found = 1;
          break;
        }
      }
      if (!found)
      {
        c[nc++] = a[i];
      }
    }
    in_taphop(c, nc, 'C');
  }else{
    for (int i = 0; i < nb; i++)
    {
      int found = 0;
      for (int j = 0; j < na && found == 0; j++)
      {
        if (b[i] == a[j])
        {
          found = 1;
          break;
        }
      }
      if (!found)
      {
        c[nc++] = b[i];
      }
    }
    in_taphop(c, nc, 'C');
  }
}
int main()
{
  int a[] = {1, 2}, b[] = {4, 1, 2}, na = 2, nb = 3, c[10], nc;
  // in_taphop(a,na,'A');
  // in_taphop(b,nb,'B');
  if (CON(a, na, b, nb))
  {
    printf("A la con cua B\n");
  }
  else
  {
    return 0;
  }
  BANG(a, na, b, nb);
  GIAO(a, na, b, nb, c);
  HOP(a, na, b, nb, c);
  HIEU(a, na, b, nb, c);
  return 0;
}
