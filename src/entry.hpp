#ifndef __ENTRY_H__
#define __ENTRY_H__
#include <string>
enum XZs {
    XZ_LD=0,
    XZ_FC,
    XZ_NC, 
    XZ_ZP,
    XZ_XD, 
    XZ_TL,
    XZ_WYZ,
    XZ_LG,
    XZ_BF, 
    XZ_YD,
    XZ_FS, 
    XZ_CD,
    XZ_XZ,
    XZ_MZ,
    XZ_JG,
    XZ_KFQ,
    XZ_NULL,
    XZ_SIZE,
};
struct Entry {
    int id; 
    XZs xz;
    std::string  address; //地址
    std::string name; //购买人
    std::string passport; //户口
    std::string idcard; //身份证
    std::string cat; //产品种类
    std::string product_id; //产品标号
    std::string product_n; //产品编号
    std::string invoice; //发票
    std::string price; //售价
    std::string allowance; //补贴
    std::string name2; //领款人
    std::string time; //受理时间
    std::string phone; //电话
};
struct Entry2 {
    std::string address; //乡镇
    int number; //人数
    double prices; //销售总计
    double allowances; //补贴总计
};
std::string get_page3(const char*);
XZs which_XZ(std::string);
#endif
