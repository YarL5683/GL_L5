#ifndef UNTITLED7_CHECKER_H
#define UNTITLED7_CHECKER_H

#include <sstream>

class Checker {
 public:
  Checker();
  void PrintResult();
  ~Checker();

 private:
  void ReadFile(std::string&, const std::string&);
  void ReadDictionary(std::string&, const std::string&);

  // All result out for each hash type
  struct result {
    std::string hash_name;
    double dict_load_time;
    int text_processing_time;
    int all_word;        // All word in all file
    int not_found_word;  // All not found word in all file
  };

  bool Allowed_symbol(const char&);

 protected:
  virtual void LoadDict() = 0;
  virtual void DataChecking() = 0;

  static const int book_number = 5;

  static std::string dict;
  static std::string books[book_number];

  result data;

};

#endif  //UNTITLED7_CHECKER_H
