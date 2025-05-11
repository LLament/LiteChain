#include "../include/Transaction.h"

// 构造函数实现
Transaction::Transaction(const std::string& sender, const std::string& receiver, double amount)
    : sender(sender), receiver(receiver), amount(amount) {}

// 获取发送方
const std::string& Transaction::getSender() const {
    return sender;
}

// 获取接收方
const std::string& Transaction::getReceiver() const {
    return receiver;
}

// 获取交易金额
double Transaction::getAmount() const {
    return amount;
}