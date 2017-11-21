#include "BKVec.h"
#include <iostream>

int main(void)
{
  BKVec<int> bk2(5);
  bk2[0] = 0;
  bk2[1] = 1;
  bk2[2] = 2;
  bk2[3] = 3;
  bk2[4] = 4;
  BKVec<int> bk;
//   for(size_t cntr = 0; cntr < bk.BKSize(); cntr++)
//     std::cout << bk[cntr] << std::endl;
  for(size_t cntr = 0; cntr < 100000; cntr++)
    bk.BKPushBack(4);
  std::cout << bk.BKSize() << std::endl;
  bk2 = bk;
  std::cout << bk2.BKSize() << "   " << bk2[456] << "   " << bk[456] << std::endl;
  return 0;
}
