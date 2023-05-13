/* 实现书店交易数据的汇总功能 */

#include <iostream>
#include "Sales_item.h"
int main ()
{
    Sales_item total;   // 保存已汇总的交易记录
    if(std::cin >> total)       //有数据的前提下
    {
        Sales_item Curr;    // 保存当前的交易记录
        while (std::cin >> Curr)
        {
            if (Curr.isbn() == total.isbn())
            {
                total += Curr;
            }
            else
            {
                std::cout << total << std::endl;
                total = Curr;       //更新total
            }
        }
    }
    else        //没有数据的前提下
    {
        std::cerr << "No data?!" << std::endl;
        return -1;
    }
    return 0;
}