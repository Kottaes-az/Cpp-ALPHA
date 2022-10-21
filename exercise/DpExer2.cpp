#include <iostream>
// 01背包
using namespace std;
struct itemType {
    int take, worth; //采摘耗时，草药价值
};
int main() {
    int timeLim, itemLim; //最多用的时间(上限)，草药数目(上限)
    cin >> timeLim >> itemLim;
    itemType itemData[itemLim + 1];
    for (int i = 1; i <= itemLim; i++)
        cin >> itemData[i].take >> itemData[i].worth;
    int dp[itemLim + 1][timeLim + 1] = {0};
    for (int curNum = 1; curNum <= itemLim; curNum++)        //草药数目
        for (int curTime = 1; curTime <= timeLim; curTime++) //采摘可用时间
            dp[curNum][curTime] =
                (itemData[curNum].take > curTime) //如果当前草药的耗时比预算多，
                    ? dp[curNum - 1][curTime] //则用上一行的耗时总和充之
                    : max(dp[curNum - 1][curTime],
                          dp[curNum - 1][curTime - itemData[curNum].take] +
                              itemData[curNum]
                                  .worth); //否则判断上一行的价值总和与(现在的价值总和与余下时间能获得的最大价值总和)之和那一个更大
    cout << dp[itemLim][timeLim];
    return 0;
}