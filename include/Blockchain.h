#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include "Block.h"
#include "Transaction.h"
#include <vector>

// 区块链类定义
// 区块链由一系列按顺序连接的区块组成
class Blockchain {
public:
    // 构造函数
    Blockchain();

    // 添加交易到交易池
    void addTransaction(const Transaction& transaction);

    // 添加新块到区块链
    void addBlock();

    // 获取区块链中所有区块
    const std::vector<Block>& getChain() const;

    // 获取当前的交易池
    const std::vector<Transaction>& getPendingTransactions() const;

private:
    std::vector<Block> chain;             // 区块链，存储所有区块
    std::vector<Transaction> transactionPool; // 交易池，存储未打包的交易
    int difficulty;                       // 挖矿难度

    // 创建创世区块
    Block createGenesisBlock() const;

    // 验证交易的合法性
    bool validateTransaction(const Transaction& transaction) const;
};

#endif // BLOCKCHAIN_H