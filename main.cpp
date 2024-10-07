#include "./include/Blockchain.h"
#include <iostream>

int main() {
    Blockchain myBlockchain;

    std::cout << "Mining block 1..." << std::endl;
    myBlockchain.addBlock(Block(1, myBlockchain.chain.back().hash, "Block 1 Data"));

    std::cout << "Mining block 2..." << std::endl;
    myBlockchain.addBlock(Block(2, myBlockchain.chain.back().hash, "Block 2 Data"));

    return 0;
}
