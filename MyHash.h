#ifndef UNTITLED7_MYHASH_H
#define UNTITLED7_MYHASH_H

#include "checker.h"
#include <list>
#include <vector>
class MyHash : public Checker{

public:
    MyHash();

    void LoadDict() override;
    void DataChecking() override;

    ~MyHash();

private:
    struct node{
        int hash;
        std::string word;
    };

   friend bool operator== (const node&, const node&);

    std::vector<node> work;
};

#endif //UNTITLED7_MYHASH_H
