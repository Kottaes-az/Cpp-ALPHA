#include <iostream>
#include <vector>
using namespace std;
const int MOD_NUM = 20123;
struct roomType
{
    bool haveStair;
    int signNum;
};
int main(int argc, const char **argv)
{
    int limFloor, limRoom, cntSignNum = 0, curRoom, curFloor = 1;
    scanf("%d%d", &limFloor, &limRoom);
    roomType dataArr[limFloor + 1][limRoom];
    int stairCnt[limFloor + 1] = {0};
    for (int curFloor = 1; curFloor <= limFloor; curFloor++)
        for (int curRoom = 0; curRoom < limRoom; curRoom++) {
            scanf("%d%d", &dataArr[curFloor][curRoom].haveStair,
                  &dataArr[curFloor][curRoom].signNum);
            if (dataArr[curFloor][curRoom].haveStair) stairCnt[curFloor]++;
        }
    scanf("%d", &curRoom);
    while (curFloor <= limFloor) {
        cntSignNum =
            (cntSignNum + dataArr[curFloor][curRoom].signNum) % MOD_NUM;
        int walkCnt =
                (dataArr[curFloor][curRoom].signNum - 1) % stairCnt[curFloor] +
                1,
            walkRoom = curRoom;
        while (true) { //从当前房间开始，找到第walkTar个有楼梯的房间
            if (walkRoom == limRoom) walkRoom = 0;
            walkCnt -= dataArr[curFloor][walkRoom].haveStair;
            if (!walkCnt) break;
            walkRoom++;
        }
        curRoom = walkRoom, curFloor++;
    }
    printf("%d\n", cntSignNum % MOD_NUM);
    return 0;
}