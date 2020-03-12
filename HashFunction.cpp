#include "HashFunction.h"

int Str2hash(const std::string& data)
{
    int hash = data[0];

    for (int i = 1; i < data.size(); i++) {
        data[i] % 2 == 0 ? hash -= data[i] ^ ((data[i]*data[i-1]) <<3)
                         : hash += data[i] & ((data[i]*data[i-1]) <<2);

    }

    if (hash < 0) {
        hash *= -1;
    }

    return hash;
}


