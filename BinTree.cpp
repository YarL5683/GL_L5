#include "BinTree.h"
#include "HashFunction.h"
#include <algorithm>
#include <chrono>

BinTree::BinTree() {
  root = nullptr;
  data.hash_name = "bintree";
}

void BinTree::LoadDict() {
  std::stringstream dict_stream(dict);
  std::chrono::time_point<std::chrono::system_clock> start, end;

  std::string dict_item;

  // start dictionary load
  start = std::chrono::system_clock::now();

  while (dict_stream >> dict_item) {
    Add(root, dict_item, Str2hash((dict_item)));
  }

  // end dictionary load
  end = std::chrono::system_clock::now();

  data.dict_load_time =
      std::chrono::duration_cast<std::chrono::milliseconds>(end - start)
          .count();
}

void BinTree::DataChecking() {
  std::chrono::time_point<std::chrono::system_clock> start, end;

  // start texts checking
  start = std::chrono::system_clock::now();

  for (int i = 0; i < book_number; i++) {
    std::stringstream data_stream(books[i]);
    std::string books_item;

    while (data_stream >> books_item) {
      data.all_word++;

      if (!Find(root, Str2hash(books_item), books_item)) {
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


void BinTree::Add(std::unique_ptr<node>& leaf, const std::string& inp_str,
                  int hash_str) {
  if (leaf != nullptr) {
    if (hash_str > leaf->hash_data) {
      Add(leaf->right, inp_str, hash_str);
    } else {
      Add(leaf->left, inp_str, hash_str);

    }

    if (hash_str == leaf->hash_data) {
      leaf->chain.push_back(inp_str);
    }
  } else {
    leaf = std::make_unique<node>();
    leaf->hash_data = hash_str;
    leaf->chain.push_back(inp_str);
    leaf->left = nullptr;
    leaf->right = nullptr;
  }
}

bool BinTree::Find(const std::unique_ptr<node>& current, int inp_hash,
                   const std::string& word) {
  if (current != nullptr) {
    if (current->hash_data == inp_hash) {
      auto find_word =
          std::find(current->chain.begin(), current->chain.end(), word);

      return (find_word != current->chain.end());
    }

    return inp_hash > current->hash_data
      ? Find(current->right, inp_hash, word)
      : Find(current->left, inp_hash, word);
  }

  return false;
}

BinTree::~BinTree() = default;