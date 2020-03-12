#include "checker.h"
#include <fstream>
#include <iostream>
#include <string>

std::string Checker::dict;
std::string Checker::books[book_number];

Checker::Checker() {
  // Read dictionary
  if (dict.empty()) {
    ReadDictionary(dict, "dictionary.txt");
  }

  data.dict_load_time = 0;
  data.text_processing_time = 0;
  data.all_word = 0;
  data.not_found_word = 0;

  // Read&format books for test (allowed only a-z, ' ', '`')
  std::string books_name[book_number]{"alice.txt", "dracula.txt", "holmes.txt",
                                      "sherlock.txt", "tolstoy.txt"};
  for (int i = 0; i < book_number; i++) {
    if (books[i].empty()) {
      ReadFile(books[i], "texts\\" + books_name[i]);
    }
  }
}

void Checker::ReadDictionary(std::string& stringD,
                             const std::string& filename) {
  std::ifstream rStream(filename);

  if (rStream.is_open()) {
    std::string word;
    while (rStream >> word) {
      stringD.append(" " + word + " ");
    }
  }

  rStream.close();
}

void Checker::ReadFile(std::string& stringF, const std::string& filename) {
  std::ifstream rStream(filename);

  if (rStream.is_open()) {
    std::string word;
    while (rStream >> word) {
      for (int i = 0; i < word.size(); i++) {
        // Parse data
        if (word[i] >= 'a' && word[i] <= 'z') {
          continue;
        }

        // From upper to lower case
        if (word[i] >= 'A' && word[i] <= 'Z') {
          word[i] += 32;
          continue;
        }

        // delete unauthorized  characters
        if (word[0] == '\'' || word[word.size() - 1] == '\'' ||
            !Allowed_symbol(word[i])) {
          word.erase(i, 1);
          i--;
        }
      }

      if (word.size() > 1) {
        stringF.append(word + " ");
      }
    }
  }
  rStream.close();
}

bool Checker::Allowed_symbol(const char& s) {
  return (s == ' ' || s == '\'' || s == '\n');
}

void Checker::PrintResult() {
  std::cout << data.hash_name << " " << data.dict_load_time << " "
            << data.text_processing_time << " " << data.all_word << " "
            << data.not_found_word << "\n";
}

int Checker::String_hash(const std::string& data) {
  int hash = 1;

  for (int i = 0; i < data.size(); i++) {
    data[i] % 2 == 0 ? hash -= data[i] * (data[0] % 11)
                     : hash += data[data.size() - 1] * (data[i] % 13);
  }

  if (hash < 0) {
    hash *= -1;
  }

  return hash;
}

Checker::~Checker() = default;
