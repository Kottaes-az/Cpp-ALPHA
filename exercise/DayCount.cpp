//计算实际日期（从该年1月1日起到这一天的总天数）：
#include <cstring>
#include <iostream>
using namespace std;
int j;
static const short MonthDays[13] = {
    0,  31, 28, 31, 30, 31, 30,
    31, 31, 30, 31, 30, 31}; //第一个留空，意为在权加时往前少加一个月，最后一个月的日期由date.day来控制
struct dateInfo {
    size_t year, month, day;
};
bool isLeap(size_t a) {
    return (!(a % 4) && (a % 100)) || !(a % 400);
} //判断是否闰年
/*法一：*/

size_t getDateCount(dateInfo date) {

    size_t i, dateID = 0;
    for (i = 0; i < date.month; i++) dateID += MonthDays[i];
    dateID += date.day;
    return (date.month > 2 && isLeap(date.year)) ? ++dateID : dateID;
}
int main() {
    dateInfo inDate;
    char info[12], *token;
    cin.getline(info, 11);
    token = strtok(info, ","); //分隔符","可自定义为空格或其他
    while (token != NULL) {
        if (!j) inDate.year = atoi(token);
        if (j == 1) inDate.month = atoi(token);
        if (j == 2) inDate.day = atoi(token);
        token = strtok(NULL, ",");
        j++;
    } //拆分年月日为单独数据
    cout << getDateCount(inDate);
    return 0;
}