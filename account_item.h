#pragma once
#include "common.h"

struct AccountItem
{
    std::string itemtype;
    int amount;
    std::string detail;
};


// 加载
void loadDataFromFile(std::vector<AccountItem> &items);

// 记账
void accounting(std::vector<AccountItem>&items);
void insertIntoFile(const AccountItem& item);
void income(std::vector<AccountItem>& items);
void expand(std::vector<AccountItem>& items);

// 查询
void query(const std::vector<AccountItem>& items);
void queryItems(const std::vector<AccountItem>& items);
void queryItems(const std::vector<AccountItem>& items, const std::string itemType);
void printItem(const AccountItem& item);