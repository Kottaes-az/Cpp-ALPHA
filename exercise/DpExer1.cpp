#include <iostream>
// NOIP2006-T2 开心的金明 01背包
using namespace std;
struct itemType {
    int price, worth;
};
int main() {
    int priceLim, itemLim; //总钱数(上限)，希望购买的物品个数(上限)
    cin >> priceLim >> itemLim;
    itemType itemData[itemLim + 1];
    for (int i = 1; i <= itemLim; i++)
        cin >> itemData[i].price >> itemData[i].worth;
    int dp[itemLim + 1][priceLim + 1] = {0};
    for (int curNum = 1; curNum <= itemLim; curNum++)            //物品个数
        for (int curMoney = 1; curMoney <= priceLim; curMoney++) //钱数
            dp[curNum][curMoney] =
                (itemData[curNum].price >
                 curMoney) //如果当前物品的价格比预算贵，
                    ? dp[curNum - 1][curMoney] //则用上一行的价值总和充之
                    : max(dp[curNum - 1][curMoney],
                          dp[curNum - 1][curMoney - itemData[curNum].price] +
                              itemData[curNum].worth *
                                  itemData[curNum]
                                      .price); //否则看看上一行的价值总和与(现在的价值总和与余钱能获得的最大价值总和)之和那一个更大(状态转移方程)
    cout << dp[itemLim][priceLim];
    return 0;
}