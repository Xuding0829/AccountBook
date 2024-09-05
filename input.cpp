#include "common.h"

char readMenuSelection(int op)
{
    std::string str;
    while (true)
    {
        std::getline(std::cin, str);
        if (str.size() != 1 || str[0] - '0' <= 0 || str[0] - '0' > op)
            std::cout << "请输入正确的指令:\n";
        else
            break;
    }
    return str[0];
}

char readConfirm()
{
    std::string str;
    while (true)
    {
        std::getline(std::cin, str);
        if (str.size() != 1 || toupper(str[0]) != 'Y' && toupper(str[0]) != 'N')
            std::cout << "输入错误，请重新输入(Y/N):\n";
        else
            break;
    }

    // 输入合法
    return toupper(str[0]);
}
int readAmount()
{
    int amount;
    std::string str;
    while (true)
    {
        std::getline(std::cin, str);
        try
        {
            amount = stoi(str);
            break;
        }
        catch (std::invalid_argument e)
        {
            std::cout << "输入错误，请正确输入数字：";
        }
    }
    return amount;
}