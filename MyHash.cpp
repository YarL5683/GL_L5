//
// Created by admin on 08.03.2020.
//

#include "MyHash.h"
#include <chrono>

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
    while(dict_stream >> dict_item)
    {
        node unit;
        unit.hash=String_hash(dict_item);
        unit.word=dict_item;

        work.push_back(unit);
    }
    //end dictionary load
    end = std::chrono::system_clock::now();

    data.dict_load_time= std::chrono::duration_cast<std::chrono::seconds>(end-start).count();
}


void MyHash::DataChecking() {
    std::chrono::time_point<std::chrono::system_clock> start, end;

    //start texts checking
    start = std::chrono::system_clock::now();

    for (int i = 0; i < 5; i++)
    {
        std::stringstream data_stream(books[i]);
        std::string books_item;
        while (data_stream >> books_item)
        {
            data.all_word++;

            auto vec_start = work.begin();
            auto vec_end = work.end();

            node temp;
            temp.word=books_item;
            temp.hash=String_hash(books_item);

            if(std::find(vec_start, vec_end, temp)==vec_end)
            {
                data.not_found_word++;
            }
        }
    }
    //end dictionary load
    end = std::chrono::system_clock::now();

    data.text_processing_time = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
}



MyHash::~MyHash()
{}

bool operator==(const MyHash::node& p1, const MyHash::node &p2) {
    return p1.hash == p2.hash && p1.word==p2.word;
}
