#ifndef UNTITLED7_HASHMAP_H
#define UNTITLED7_HASHMAP_H

#include "checker.h"
#include <map>
#include <list>

class HashMap : public Checker{
public:
    HashMap();

    void LoadDict() override;
    void DataChecking() override;

    //function to writing incorrect words
    void BadWord();
    ~HashMap();

private:
    std::map <int, std::list<std::string>> work;
};

#endif //UNTITLED7_HASHMAP_H