#include <bits/stdc++.h>
using namespace std;
class military_base {
  private:
    enum GUN_TYPE { PS = 0, SMG, ST, ASR, SNR, LMG, HMG };
    string GUN_AMMO[9901] = {"5.56 NATO", ".45 AP"};
    string GUN_CALIBER[9901] = {};
    
  public:
    struct Common_Gun {
        GUN_TYPE current_type; //泛类型
        string manufer, manuf_date, std_serial_number, informal_code,
            service_code,
            simply_info[21]; //制造商,初次生产日期,厂内序列号,简称,服役代号,简介
        string caliber;               //口径
        double evaluation = 0;        //综合实力评估打分
        double length, width, height; //长,宽,高(单位：mm)
    } common_gun_group[66535];
} Base;