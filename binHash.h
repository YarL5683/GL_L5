#ifndef UNTITLED7_BINHASH_H
#define UNTITLED7_BINHASH_H

#include "checker.h"
#include <list>

class BinHash : public Checker{
public:
    BinHash();

    void LoadDict() override;
    void DataChecking() override ;

    ~BinHash();

private:
    struct node
        {
        int hash_data;
        std::list<std::string> chain;

        std::shared_ptr<node> left;
        std::shared_ptr<node> right;
        };

    void Add(std::shared_ptr<node>& , std::string, int);
    bool Find(const std::shared_ptr<node>&, int, const std::string&);

    std::shared_ptr<node> root;
};

#endif //UNTITLED7_BINHASH_H