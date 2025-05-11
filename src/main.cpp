#include "../include/Blockchain.h"
#include <iostream>

int main() {
    Blockchain blockchain;

    blockchain.addBlock("First Block");
    blockchain.addBlock("Second Block");

    for (const Block& block : blockchain.getChain()) {
        std::cout << "Index: " << block.getHash() << "\n"
                  << "Previous Hash: " << block.getPrevHash() << "\n"
                  << "-----------------------------\n";
    }

    return 0;
}