#ifndef UNTITLED7_VECSTD_H
#define UNTITLED7_VECSTD_H

#include <vector>
#include "Checker.h"

class VecStd : public Checker {
 public:
  VecStd();

  void LoadDict() override;
  void DataChecking() override;

  ~VecStd();

 private:
  struct list_node {
    std::string data;
    int hash_data;
  };

  friend bool operator==(const list_node&, const list_node&);

  void Add(const std::string&, int);
  bool Find(const std::string&, int);

  std::vector<list_node> bucket[20];
};
#endif  //UNTITLED7_VECSTD_H
