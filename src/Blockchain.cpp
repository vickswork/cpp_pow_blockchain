#include "../include/Blockchain.h"


Blockchain::Blockchain() {
    chain.push_back(genesisblock());
    difficulty = 0; 
}


Block Blockchain::genesisblock() {
    return Block(0, "0", "Genesis Block");
}


Block Blockchain::getLastBlock() const {
    return chain.back();
}


void Blockchain::addBlock(Block newBlock) {
    newBlock.previoushash = getLastBlock().hash;
    newBlock.mine(difficulty);
    chain.push_back(newBlock);
}
