#ifndef UNTITLED7_HASHMAP_H
#define UNTITLED7_HASHMAP_H

#include "checker.h"
#include <unordered_map>

class HashMap : public Checker{
public:
    HashMap();

    void LoadDict() override;
    void DataChecking() override;

    ~HashMap();

private:
    std::unordered_map <int, std::list<std::string>> work;
};

#endif //UNTITLED7_HASHMAP_H