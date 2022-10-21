#include <algorithm>
#include <iostream>
//易读的代码，代价是牺牲简约的风格与更多的空间
using namespace std;
struct itemType {
    int price;
    bool isGrouped; // price:价值,flag:是否分组(0:未分组)
    itemType() : isGrouped(false) {}
};
bool cmp(itemType a, itemType b) { return a.price > b.price; } //降序排序子函数
int main() {
    int limPrice, itemNum, groupCnt = 0;
    // limPrice:每组纪念品价值总和上限，itemNum:纪念品总数，groupCnt:分组数
    cin >> limPrice >> itemNum;
    itemType arr[itemNum];
    for (int curItem = 0; curItem < itemNum; curItem++)
        scanf("%d", &arr[curItem].price);
    sort(arr, arr + itemNum, cmp); //降序排序
    for (int curItem = 0; curItem < itemNum; curItem++)
        //如果此纪念品未被分组，就为其寻找分组搭档
        if (!arr[curItem].isGrouped) {
            //算出当前纪念品的搭档的理想价值
            int idlPrice = limPrice - arr[curItem].price;
            int l = curItem + 1, r = itemNum - 1, mid;
            //开始进行二分查找
            while (l < r) {
                mid = (l + r) / 2;
                (arr[mid].price > idlPrice)
                    ? (l = mid + 1)
                    // 如果这件纪念品的价值大于理想价值，则舍弃mid和其左边所有位置的纪念品（因为为降序排序，所以左边的一定更大）
                    : (r = mid);
                //如果小于等于理想价值，则舍弃mid和其右边所有位置的纪念品（因为为降序排序，所以右边的一定更小）
            }
            //二分查找结束，但找到的此纪念品可能已经分过组了，便不断“退而求其次",直到找到未分组但价值更小一点的纪念品来分组
            while (arr[curItem].isGrouped && l < itemNum) l++;
            //如果l<itemNum则说明找到了一个合法的搭档的位置，将此搭档标记为已分组，没有找到则通过下一行单独分组
            arr[l].isGrouped = l < itemNum;
            //将正在操作的这一个纪念品也标记为分组(无论是价值过大没有找到搭档还是找到了合适的搭档)
            arr[curItem].isGrouped = true;
            //分组成功，加1到分组数
            groupCnt++;
        }
    printf("%d\n", groupCnt);
    return 0;
}