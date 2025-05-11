#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

// 交易类定义
// 表示区块链中的单笔交易
class Transaction {
public:
    // 构造函数
    // @param sender: 交易的发送方
    // @param receiver: 交易的接收方
    // @param amount: 交易的金额
    Transaction(const std::string& sender, const std::string& receiver, double amount);

    // 获取发送方
    const std::string& getSender() const;

    // 获取接收方
    const std::string& getReceiver() const;

    // 获取交易金额
    double getAmount() const;

private:
    std::string sender;   // 发送方
    std::string receiver; // 接收方
    double amount;        // 交易金额
};

#endif // TRANSACTION_H