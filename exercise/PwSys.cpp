#include "PwSource.h"
#include <iostream>
using namespace std;
struct {
    codeType curCode = BASE64_CODE;
    string inputLine, destLine, existSignal = "-1";
    bool oprType;
} Pw;
// at break of day,in hope we rise
enum codeType { BASE64_CODE = 1, AES_CODE };
class pwModule {
  public:
    int existFlag = 0;
    void Work(), Input(), Out();
};
void pwModule::Input() {
    getline(cin, Pw.inputLine);
    if (Pw.existSignal == Pw.inputLine) {
        existFlag |= 1;
        return;
    }
    cin >> Pw.oprType;
}
void pwModule::Work(void) {
    if (Pw.oprType)
        switch (Pw.curCode) {
            case BASE64_CODE:
                Pw.destLine =
                    encryptionBase64(Pw.inputLine.c_str(), Pw.inputLine.size());
                break;
            case AES_CODE: Pw.destLine = encryptionAES(Pw.inputLine); break;
        }
    else
        switch (Pw.curCode) {
            case BASE64_CODE:
                Pw.destLine = decryptionBase64(Pw.inputLine);
                break;
            case AES_CODE: Pw.destLine = decryptionAES(Pw.inputLine); break;
        }
}
void pwModule::Out() {
    cout << (Pw.oprType ? "->Encoded:" : "->Decoded: ") << Pw.destLine << endl;
}
int main(int argc, char *argv[], char **env) {
    pwModule PwObj;
    PwObj.Input();
    PwObj.Work();
    PwObj.Out();
    return 0;
}