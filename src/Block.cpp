#include "../include/Block.h"
#include <openssl/sha.h>
#include <sstream>
#include <iomanip>
#include <string>

// 构造函数实现
Block::Block(int index, const std::vector<Transaction>& transactions, const std::string& prevHash)
    : index(index), transactions(transactions), prevHash(prevHash), timestamp(std::time(nullptr)), nonce(0) {
    hash = generateHash(); // 在构造时生成初始哈希值
}

// 计算当前区块的哈希值
std::string Block::calculateHash() const {
    return generateHash();
}

// 开始挖矿
void Block::mineBlock(int difficulty) {
    std::string target(difficulty, '0'); // 目标哈希前缀：difficulty 个 '0'
    
    // 不断调整 nonce，直到哈希值满足目标难度
    do {
        nonce++;
        hash = generateHash();
    } while (hash.substr(0, difficulty) != target);
}

// 返回当前区块的哈希值
const std::string& Block::getHash() const {
    return hash;
}

// 返回前一区块的哈希值
const std::string& Block::getPrevHash() const {
    return prevHash;
}

// 返回区块中的交易列表
const std::vector<Transaction>& Block::getTransactions() const {
    return transactions;
}

// 生成区块的哈希值
std::string Block::generateHash() const {
    std::stringstream ss;
    ss << index << timestamp << prevHash << nonce;

    // 将交易数据纳入哈希计算
    for (const auto& transaction : transactions) {
        ss << transaction.getSender() << transaction.getReceiver() << transaction.getAmount();
    }

    unsigned char hashResult[SHA256_DIGEST_LENGTH];
    SHA256(reinterpret_cast<const unsigned char*>(ss.str().c_str()), ss.str().size(), hashResult);

    // 将哈希结果转换为十六进制字符串
    std::stringstream hashString;
    for (unsigned char c : hashResult) {
        hashString << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(c);
    }

    return hashString.str();
}