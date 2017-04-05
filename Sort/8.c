#include <stdio.h>
int main()
{
  printf("asdf");
  int length = 3;
  int j;
  for (int i = 0; i < length; ++i)
  {
    for (j = i + 1; j < length; ++j)
    {
      printf("i=%d,j=%d\n", i, j);
    }
  }
  for (int i = 0; i < length; ++i)
  {
    for (int k = i + 1; k < length; ++k)
    {
      printf("i=%d,k=%d\n", i, k);
    }
  }
  return 0;
}