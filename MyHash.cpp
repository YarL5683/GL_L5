#include "MyHash.h"
#include <chrono>
#include <fstream>

MyHash::MyHash()
{
    data.hash_name="myhash";
}

void MyHash::LoadDict()
{
    std::stringstream dict_stream(dict);
    std::chrono::time_point<std::chrono::system_clock> start, end;

    std::string dict_item;

    //start dictionary load
    start = std::chrono::system_clock::now();

    while(dict_stream >> dict_item) {
        //Add new word to dictionary
        work[dict_item[0]*2-2*'a'].append(" "+dict_item+ " ");
    }

    //end dictionary load
    end = std::chrono::system_clock::now();

    data.dict_load_time= std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
}

void MyHash::DataChecking() {
    std::chrono::time_point<std::chrono::system_clock> start, end;

    //start texts checking
    start = std::chrono::system_clock::now();

    for (int i = 0; i < book_number; i++)
    {
        std::stringstream data_stream(books[i]);
        std::string books_item;

        while (data_stream >> books_item)
        {
            data.all_word++;

            if(work[books_item[0]*2-2*'a'].find(" "+books_item+" ")==std::string::npos)
            {
                data.not_found_word++;
            }
        }
    }

    //end texts checking
    end = std::chrono::system_clock::now();
    data.text_processing_time += std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
}


MyHash::~MyHash()
{}
