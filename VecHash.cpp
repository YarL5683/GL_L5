#include "VecHash.h"
#include <chrono>

VecHash::VecHash(){
    data.hash_name="stdvect";
}

void VecHash::LoadDict()
{
    std::stringstream dict_stream(dict);
    std::chrono::time_point<std::chrono::system_clock> start, end;

    std::string dict_item;

    //start texts checking
    start = std::chrono::system_clock::now();

    while(dict_stream >> dict_item)
    {
        Add(dict_item,String_hash((dict_item)));
    }

    //end texts checking
    end = std::chrono::system_clock::now();

    data.dict_load_time= std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
}

void VecHash::DataChecking()
{
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
            if(!Find(books_item, String_hash(books_item)))
                data.not_found_word++;
        }
    }
    //end dictionary load
    end = std::chrono::system_clock::now();

    data.text_processing_time = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
}

void VecHash::Add(std::string inp_str, int hash_data)
{
    list_node temp;

    temp.data=inp_str;
    temp.hash_data=hash_data;

    bucket[inp_str.size()%20].push_back(temp);
}

//Compare struct
bool operator==(const VecHash::list_node& p1, const VecHash::list_node& p2){
    return p1.hash_data == p2.hash_data && p1.data==p2.data;
}

bool VecHash::Find(std::string bucket_n, int word_hash){
    auto begin = bucket[bucket_n.size()%20].begin();
    auto end = bucket[bucket_n.size()%20].end();

    list_node example;
    example.data=bucket_n;
    example.hash_data=String_hash(bucket_n);

    if(std::find(begin, end, example) != end){
        return true;
    }
    else{
        return false;
    }
};

VecHash::~VecHash() {

}