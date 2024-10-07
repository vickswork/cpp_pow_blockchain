#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <vector>
#include "Block.h"
using namespace std;

class Blockchain {
    public:
        vector<Block> chain;
        int difficulty;

        Blockchain();
        void addBlock(Block newBlock);
    
    private:
        Block genesisblock();
        Block getLastBlock() const;
};
#endif