#include <iostream>
//长度最小的子数组
// using namespace std; (不需要用到标准命名空间内的语句)
int nums[1000] = {0};
int main()
{
    int n, target, sum = 0, subl = 0, subr = 0, min = __INT16_MAX__;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
    scanf("%d", &target);
    while (subl <= subr) {
        while (subr < n && sum < target) sum += nums[++subr];
        if (subr < n && sum >= target)
            min = (min < subr - subl) ? min : subr - subl;
        else if (subr == n && sum >= target)
            min = (min < n - subl) ? min : n - subl;
        else
            break;
        sum -= nums[++subl];
    }
    printf("%d\n", (min == __INT16_MAX__) ? 0 : min);
    for (int i = subl; i < subr; i++) printf("%d ", nums[i]);
    return 0;
}