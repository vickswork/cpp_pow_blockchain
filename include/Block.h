#ifndef BLOCK_H
#define BLOCK_H

#include <string>
#include <ctime> 
using namespace std;

class Block{
    public: 
    int index;
    string previoushash;
    string data;
    string hash;
    long nonce;
    time_t timestamp;
    
    Block(int idx,string prevhash,string blockdata);

    string calculateHash() const;
    void mine(int difficulty);

    private:
        static string sha256(const string str);
};

#endif