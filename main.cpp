#include "hashMap.h"
#include "binHash.h"
#include "VecHash.h"
#include "MyHash.h"

int main() {

    HashMap a;

    a.LoadDict();
    a.DataChecking();
    a.PrintResult();
/*
    //This function for write bad word in .txt
    //Copy DataChecking, but does not count time
    a.BadWord();

    BinHash b;

    b.LoadDict();
    b.DataChecking();
    b.PrintResult();

    VecHash c;

    c.LoadDict();
    c.DataChecking();
    c.PrintResult();

    MyHash d;

    d.LoadDict();
    d.DataChecking();
    d.PrintResult();
*/
    return 0;
}
