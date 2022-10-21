#include <bits/stdc++.h>
using namespace std;
int main(int argc, const char **argv) {
    int fruNum, temp, cnt = 0, cur = -1;
    vector<vector<int>> blc;
    scanf("%d", &fruNum);
    for (int i = 1; i <= fruNum; i++) {
        scanf("%d", &temp);
        if (!i) cur = temp;
        cnt += temp == cur;
        if (temp != cur || i == fruNum - 1) {
            vector<int> t;
            for (int j = 1; j <= cnt; j++) t.push_back(i - cnt + j);
            blc.push_back(t);
            cnt = 1, cur = temp;
        }
    }
    while (!blc.empty()) {
        for (int i = 0; i < (int)blc.size(); i++) //取出水果
            if (blc[i].size()) {
                blc[i].erase(blc[i].begin());
                cout << blc[i].front() << ' ';
            }
        cout << endl;
        for (int i = 0; i < (int)blc.size() - 1; i++) { //合并块
            if (blc[i].size()) {
                if (blc[i].front() == blc[i + 1].front()) {
                    blc[i].insert(blc[i].end(), blc[i + 1].begin(),
                                  blc[i + 1].end());
                    blc.erase(blc.begin() + i + 1);
                }
            }
            else
                blc.erase(blc.begin() + i);
        }
    }
    return 0;
}