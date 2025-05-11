#ifndef BLOCK_H
#define BLOCK_H

#include <string>
#include <vector>
#include <ctime>
#include "Transaction.h"

// 区块类定义
// 每个区块包含区块索引、交易列表、哈希值、前一区块的哈希值、时间戳和随机数 nonce。
class Block {
public:
    // 构造函数
    // @param index: 区块在区块链中的位置
    // @param transactions: 区块存储的交易列表
    // @param prevHash: 前一区块的哈希值
    Block(int index, const std::vector<Transaction>& transactions, const std::string& prevHash);

    // 计算并返回当前区块的哈希值
    std::string calculateHash() const;

    // 开始挖矿，找到满足难度要求的哈希值
    void mineBlock(int difficulty);

    // 获取当前区块的哈希值
    const std::string& getHash() const;

    // 获取前一区块的哈希值
    const std::string& getPrevHash() const;

    // 获取区块中的交易列表
    const std::vector<Transaction>& getTransactions() const;

private:
    int index;                              // 区块索引
    std::vector<Transaction> transactions; // 区块存储的交易列表
    std::string hash;                       // 当前区块的哈希值
    std::string prevHash;                   // 前一区块的哈希值
    std::time_t timestamp;                  // 区块创建的时间戳
    int nonce;                              // 随机数，用于调整哈希值

    // 生成区块的哈希值
    std::string generateHash() const;
};

#endif // BLOCK_H