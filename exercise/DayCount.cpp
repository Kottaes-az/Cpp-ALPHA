//计算实际日期（从该年1月1日起到这一天的总天数）：
#include <cstring>
#include <iostream>
using namespace std;
int j;
bool isLeap(unsigned int a)
{
    return (!(a % 4) && (a % 100)) || !(a % 400);
} //判断是否闰年
/* 法一：*/
/*
int MonthMark[13] = {0,   31,  59,  90,  120, 151, 181,
                     212, 243, 273, 304, 334, 365};
int MonthDay(int year, int month, int day)
{
    if (LeapYear(year))
        if (month > 2)
            return MonthMark[month - 1] + 1 + day;
        else
            return MonthMark[month - 1] + day;
    else
        return MonthMark[month - 1] + day;
}
int main()
{
    int y, m, d;
    string info;
    char *token;
    cin >> info;
    token = strtok((char *)info.c_str(), ",");
    while (token != NULL) {
        if (!j) y = atoi(token);
        if (j == 1) m = atoi(token);
        if (j == 2) d = atoi(token);
        token = strtok(NULL, ",");
        j++;
    } //拆分年月日为单独数据
    cout << MonthDay(y, m, d) << endl;
    return 0;
}
 */
/*法二：*/
struct DATE
{
    unsigned int year, month, day;
};
unsigned int GetDateCount(DATE date)
{
    const static unsigned int MonthDays[13] = {
        0,  31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31}; //第一个留空，意为在权加时往前少加一个月，最后一个月的日期由date.day来控制
    unsigned int i, dateID = 0;
    for (i = 0; i < date.month; i++) dateID += MonthDays[i];
    dateID += date.day;
    return (date.month > 2 && isLeap(date.year)) ? ++dateID : dateID;
}
int main()
{
    DATE inDate;
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
    cout << GetDateCount(inDate);
    return 0;
}
