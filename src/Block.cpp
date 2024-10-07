#include "../include/Block.h"
#include <sstream>
#include <iomanip>
#include <openssl/sha.h>
#include <iostream>
using namespace std;

Block::Block(int idx, string prevHash, string blockData) {
    index = idx;
    previoushash = prevHash;
    data = blockData;
    timestamp = time(nullptr);
    nonce = 0;
    hash = calculateHash();
}

string Block::calculateHash() const {
    stringstream ss;
    ss<< index << previoushash << data << timestamp << nonce;
    return sha256(ss.str());
}

void Block::mine(int difficulty)
{
    string target(difficulty,0);
    while(hash.substr(0,difficulty)!= target){
        nonce++;
        hash = calculateHash();
    }
    cout<<"Block mined:"<< hash << endl;
}

string Block::sha256(const string str) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str.c_str(), str.size());
    SHA256_Final(hash, &sha256);

    std::stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    return ss.str();
}