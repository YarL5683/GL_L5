#include "hashMap.h"
#include <algorithm>
#include <chrono>
#include <fstream>

HashMap::HashMap() { data.hash_name = "hashtable"; }

void HashMap::LoadDict() {
  std::stringstream dict_stream(dict);
  std::chrono::time_point<std::chrono::system_clock> start, end;

  std::string dict_item;

  // start dictionary load
  start = std::chrono::system_clock::now();

  while (dict_stream >> dict_item) {
    // Add new word to dictionary
    work[String_hash(dict_item)].push_back(dict_item);
  }

  // end dictionary load
  end = std::chrono::system_clock::now();

  data.dict_load_time =
      std::chrono::duration_cast<std::chrono::milliseconds>(end - start)
          .count();
}

void HashMap::DataChecking() {
  std::chrono::time_point<std::chrono::system_clock> start, end;

  // start texts checking
  start = std::chrono::system_clock::now();

  for (int i = 0; i < book_number; i++) {
    std::stringstream data_stream(books[i]);
    std::string books_item;

    while (data_stream >> books_item) {
      data.all_word++;

      auto list_start = work[String_hash(books_item)].begin();
      auto list_end = work[String_hash(books_item)].end();

      if (std::find(list_start, list_end, books_item) == list_end) {
        data.not_found_word++;
      }
    }
  }

  // end texts checking
  end = std::chrono::system_clock::now();

  data.text_processing_time =
      std::chrono::duration_cast<std::chrono::milliseconds>(end - start)
          .count();
}

void HashMap::BadWord() {
  std::string filename = "bad_word_1.txt";

  for (int i = 0; i < book_number; i++) {
    std::stringstream data_stream(books[i]);
    std::string books_item;

    std::ofstream out;

    out.open(filename);
    filename[9]++;  // change number of file
    while (data_stream >> books_item) {
      data.all_word++;

      auto list_start = work[String_hash(books_item)].begin();
      auto list_end = work[String_hash(books_item)].end();

      if (std::find(list_start, list_end, books_item) == list_end) {
        data.not_found_word++;
        out << books_item << "\n";
      }
    }
    out.close();
  }
}

HashMap::~HashMap() = default;
