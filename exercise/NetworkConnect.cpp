#include <bits/stdc++.h>
using namespace std;
struct connect {
    string op, ad;
    int index, suc;
};
bool legal(string addr) {
    ssize_t a, b, c, d, e;
    if (sscanf(addr.c_str(), "%lld.%lld.%lld.%lld:%lld"
                            , &a, &b, &c, &d, &e) != 5)
        return false;
    if (a < 0 || a > 255 || b < 0 || b > 255 || c < 0 || c > 255
                || d < 0 || d > 255 || e < 0 || e > 65535)
        return false;
    stringstream tmpStream;
    tmpStream << a << '.' << b << '.' << c << '.' << d << ':' << e;
    return tmpStream.str() == addr;
}
int main() {
    int cncNum;
    // freopen("network.in","r",stdin);
    // freopen("network.out","w",stdout);
    cin >> cncNum;
    connect arr[cncNum + 1];
    for (int i = 1; i <= cncNum; i++) {
        arr[i].index = i;
        cin >> arr[i].op >> arr[i].ad;
        bool tmpSuc;
        if (legal(arr[i].ad)) {
            if (arr[i].op == "Server") { //服务机
                tmpSuc = true;
                for (int j = 1; j < i && tmpSuc; j++) //查重服务机
                    if (arr[j].op == "Server" && arr[j].ad == arr[i].ad) {
                        tmpSuc = false;
                        cout << "FAIL";
                    }
                if (tmpSuc) cout << "OK";
            }
            else { //客户机
                tmpSuc = false;
                for (int j = 1; j < i && !tmpSuc; j++) //匹配服务机
                    if (arr[j].ad == arr[i].ad && arr[j].op == "Server" &&
                        arr[j].suc) {
                        tmpSuc = true;
                        cout << arr[j].index;
                    }
                if (!tmpSuc) cout << "FAIL";
            }
        }
        else cout << "ERR";
        cout << endl;
        arr[i].suc = tmpSuc;
    }
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}