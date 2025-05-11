#include "../include/Blockchain.h"

// 构造函数实现
Blockchain::Blockchain() : difficulty(2) { // 默认挖矿难度为 2
    chain.push_back(createGenesisBlock());
}

// 添加交易到交易池
void Blockchain::addTransaction(const Transaction& transaction) {
    if (validateTransaction(transaction)) {
        transactionPool.push_back(transaction); // 将合法交易添加到交易池
    }
}

// 添加新块到区块链
void Blockchain::addBlock() {
    if (transactionPool.empty()) {
        return; // 如果没有交易，则不创建新块
    }

    const Block& prevBlock = chain.back();
    Block newBlock(chain.size(), transactionPool, prevBlock.getHash());
    newBlock.mineBlock(difficulty); // 挖矿

    chain.push_back(newBlock);      // 添加区块到链中
    transactionPool.clear();        // 清空交易池
}

// 获取区块链中的所有区块
const std::vector<Block>& Blockchain::getChain() const {
    return chain;
}

// 获取当前交易池
const std::vector<Transaction>& Blockchain::getPendingTransactions() const {
    return transactionPool;
}

// 创建创世区块
Block Blockchain::createGenesisBlock() const {
    return Block(0, {}, "0"); // 创世区块没有交易，交易列表为空
}

// 验证交易的合法性
bool Blockchain::validateTransaction(const Transaction& transaction) const {
    // 检查金额是否为正数
    return transaction.getAmount() > 0;
}