#ifndef UNTITLED7_BinTree_H
#define UNTITLED7_BinTree_H

#include <list>
#include <memory>
#include "Checker.h"

class BinTree : public Checker {
 public:
  BinTree();

  void LoadDict() override;
  void DataChecking() override;

  ~BinTree();

 private:
  struct node {
    int hash_data;
    std::list<std::string> chain;

    std::unique_ptr<node> left;
    std::unique_ptr<node> right;
  };

  void Add(std::unique_ptr<node>&, const std::string&, int);
  bool Find(const std::unique_ptr<node>&, int, const std::string&);

  std::unique_ptr<node> root;
};

#endif  // UNTITLED7_BinTree_H
