
#include "MyHash.h"
#include "VecStd.h"
#include "BinTree.h"
#include "HashMap.h"

int main() {
  HashMap a;

  a.LoadDict();
  a.DataChecking();
  a.PrintResult();

  // This function for write bad word in .txt
  // Copy DataChecking, but does not count time
  a.BadWord();

  BinTree b;

  b.LoadDict();
  b.DataChecking();
  b.PrintResult();

  VecStd c;

  c.LoadDict();
  c.DataChecking();
  c.PrintResult();

  MyHash d;

  d.LoadDict();
  d.DataChecking();
  d.PrintResult();

  return 0;
}
