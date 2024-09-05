#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#define INCOME "收入"
#define EXPAND "支出"
#define FILENAME "data\\AccountBook.txt"

// 显示菜单函数
void showMainMenu();
void showAccountMenu();
void showQueryMenu();

// 读取输入函数
char readMenuSelection(int op);
char readConfirm();
int readAmount();