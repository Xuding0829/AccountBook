#include "common.h"
#include "account_item.h"

// 加载
void loadDataFromFile(std::vector<AccountItem> &items)
{
    std::ifstream input(FILENAME);

    AccountItem item;
    while (input >> item.itemtype >> item.amount >> item.detail)
    {
        items.push_back(item);
    }

    input.close();
}

// 记账
void accounting(std::vector<AccountItem> &items)
{
    char ch = readMenuSelection(3);
    switch (ch)
    {
    case '1':
        income(items); // 收入
        break;
    case '2':
        expand(items); // 支出
    default:
        break;
    }
}

// 写入文件
void insertIntoFile(const AccountItem &item)
{
    std::ofstream output(FILENAME, std::ios::out | std::ios::app);
    output << item.itemtype << '\t' << item.amount << '\t' << item.detail;
    output.close();
}

// 收入
void income(std::vector<AccountItem> &items)
{
    AccountItem item;
    item.itemtype = INCOME;
    std::cout << "本次收入金额:\n";
    item.amount = readAmount();
    std::cout << "备注:\n";
    std::getline(std::cin, item.detail);
    items.push_back(item);

    // 显示成功
    std::cout << "\n------------------------记账成功！--------------------------\n"
              << std::endl;
    std::cout << "\n请按回车键返回主菜单..." << std::endl;

    std::string str;
    std::getline(std::cin, str);
}

// 支出
void expand(std::vector<AccountItem> &items)
{
    AccountItem item;
    item.itemtype = EXPAND;

    std::cout << "本次支出金额:\n";
    item.amount = readAmount();
    std::cout << "备注:\n";
    std::getline(std::cin, item.detail);
    items.push_back(item);

    insertIntoFile(item);

    // 显示成功
    std::cout << "\n------------------------记账成功！--------------------------\n"
              << std::endl;
    std::cout << "\n请按回车键返回主菜单..." << std::endl;

    std::string str;
    std::getline(std::cin, str);
}

// 查询
void query(const std::vector<AccountItem> &items)
{
    char ch = readMenuSelection(3);

    switch (ch)
    {
    case '1':
        queryItems(items);
        break;
    case '2':
        queryItems(items, INCOME);
    case '3':
        queryItems(items, EXPAND);
    default:
        break;
    }
}

// 查询所有
void queryItems(const std::vector<AccountItem> &items)
{
    std::cout << "---------------- 查询结果 ---------------------" << std::endl;
    std::cout << "\n类型\t\t金额\t\t备注\n"
              << std::endl;

    int res = 0;
    for (auto item : items)
    {
        printItem(item);
        if (item.itemtype == INCOME)
            res += item.amount;
        else
            res -= item.amount;
    }
    // 输出信息
    std::cout << "===================================================\n"
              << std::endl;
    std::cout << "总收支：" << res << std::endl;
    std::cout << "\n请按回车键返回主菜单..." << std::endl;

    std::string line;
    std::getline(std::cin, line);
}

// 查询
void queryItems(const std::vector<AccountItem> &items, const std::string itemtype)
{
    std::cout << "---------------- 查询结果 ---------------------" << std::endl;
    std::cout << "\n类型\t\t金额\t\t备注\n"
              << std::endl;

    int res = 0;
    for (auto item : items)
    {
        if (item.itemtype != itemtype)
            continue;
        printItem(item);
        res += item.amount;
    }

    std::cout << "===================================================\n"
         << std::endl;
    std::cout << ((itemtype == INCOME) ? "总收入：" : "总支出：") << res << std::endl;
    std::cout << "\n请按回车键返回主菜单..." << std::endl;

    std::string line;
    std::getline(std::cin, line);
}
void printItem(const AccountItem &item)
{
    std::cout << item.itemtype << "\t\t" << item.amount << "\t\t" << item.detail << std::endl;
}