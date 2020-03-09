#ifndef UNTITLED7_MYHASH_H
#define UNTITLED7_MYHASH_H

#include "checker.h"
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


    std::string work[52];
};

#endif //UNTITLED7_MYHASH_H
