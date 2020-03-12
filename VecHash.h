#ifndef UNTITLED7_VECHASH_H
#define UNTITLED7_VECHASH_H

#include "checker.h"
#include <vector>

class VecHash : public Checker{
public:
    VecHash();

    void LoadDict() override;
    void DataChecking() override ;

    ~VecHash();
private:

    struct list_node{
        std::string data;
        int hash_data;
    };

   friend bool operator== (const list_node&, const list_node&);

    void Add(const std::string&, int);
    bool Find(const std::string&, int);

   std::vector<list_node> bucket[20];
};
#endif //UNTITLED7_VECHASH_H
