#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
  short x, y;
  short mask1, mask2;
  short t1, t2;

  x = y = 0xAC;
  mask1 = 0x6;
  mask2 = ~((mask1 << 4) | mask1);

  t1 = (x & mask1) << 4;
  t2 = (x >> 4) & mask1;
  x = (x & mask2) | t1 | t2;

  t1 = (y^(y >> 4))&mask1;
  t2 = t1 << 4;
  y = y^t1^t2;

  printf("x = 0x%x\n", x);
  printf("y = 0x%x\n", y);

  return 0;
}
