#include "common.h"
#include "account_item.h"
#include "input.cpp"
#include "menus.cpp"
#include "operations.cpp"
int main()
{
    // 加载账目数据
    std::vector<AccountItem> items;
    loadDataFromFile(items);

    bool quit = false;
    while (!quit)
    {
        // 显示界面
        showMainMenu();
        // 读取输入并校验
        char ch = readMenuSelection(3);
        //
        switch (ch)
        {
        case '1': // 记账
            showAccountMenu();
            accounting(items);
            break;
        case '2': // 查询
            showQueryMenu();
            query(items);
            break;
        case '3':
            std::cout << "是否确认退出? (Y/N)\n";
            if (readConfirm() == 'Y')
                quit = true;
            accounting(items);
        default:
            quit = true;
        }
        std::cout << std::endl;
    }

    return 0;
}
