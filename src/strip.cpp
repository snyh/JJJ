#include <iostream>
#include <fstream>
#include <sstream>
#include <boost/xpressive/xpressive.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/format.hpp>
#include <boost/filesystem.hpp>
#include <iterator>
#include <ctime>
using namespace boost::algorithm;

#include "entry.hpp"
#include "JJJ.hpp"
/*
 * 由于家电下乡软件倒出字符编码为GB2312
 * 所以本源代码使用GB2312格式 避免查找字符串时候的转换工作
 * 其他源码均为UTF8格式
 */
using namespace std;
using namespace boost::xpressive;

string now()
{
  time_t n;
  time(&n);
  struct tm *tm;
  tm = localtime(&n);
  return boost::str(boost::format("%1%-%2%-%3%") % (tm->tm_year+1900) % (tm->tm_mon+1) % tm->tm_mday);
}

string get_page3(const char* file)
{
  ifstream i(file);
  string t;
  ostringstream os;
  int found=0;
  while(getline(i, t)){
      size_t p = t.find("page-break-before");
      if(p == string::npos)
	continue;
      else
	found++;
      if(found == 2)
	break;
  }
  if(found != 2) 
    throw "Not An legal file";

  while(getline(i, t)) {
      size_t p = t.find("&nbsp;");
      if(p!=string::npos){
	  t.erase(p, 6);
      }
      if(t.find("/body") == string::npos &&
	 t.find("/html") == string::npos)
      os << t << endl;
  }

  return os.str();
}

Entry JJJmaindialog::get_entry(string file)
{

  using namespace boost::xpressive;
  Entry entry;
  istringstream is(get_page3(file.c_str()));
  string line;
  sregex exp = sregex::compile(">(.*)</td>");
  sregex exp3 = sregex::compile(">(.*)元</td>"); //销售价格
  smatch sr;
  while(getline(is, line)){
      if(entry.cat.empty() && string::npos != line.find("产品类型")){
	  getline(is, line);
	  regex_search(line, sr, exp);
	  entry.cat.assign(sr[1]);
	  trim(entry.cat);
	  continue;
      }

      if(entry.product_id.empty() && string::npos != line.find("标识卡号")){
	  getline(is, line);
	  regex_search(line, sr, exp);
	  entry.product_id.assign(sr[1]);
	  trim(entry.product_id);
	  continue;
      }

      if(entry.product_n.empty() && string::npos != line.find("产品编号")){
	  getline(is, line);
	  regex_search(line, sr, exp);
	  entry.product_n.assign(sr[1]);
	  trim(entry.product_n);
	  continue;
      }

      if(entry.price.empty() && string::npos != line.find("销售金额")){
	  getline(is, line);
	  regex_search(line, sr, exp3);
	  entry.price.assign(sr[1]);
	  trim(entry.price);
	  continue;
      }

      if(entry.invoice.empty() && string::npos != line.find("发票号码")){
	  getline(is, line);
	  regex_search(line, sr, exp);
	  entry.invoice.assign(sr[1]);
	  trim(entry.invoice);
	  continue;
      }


      if(entry.idcard.empty() && string::npos != line.find("身份证号码")){
	  getline(is, line);
	  regex_search(line, sr, exp);
	  entry.idcard.assign(sr[1]);
	  trim(entry.idcard);
	  continue;
      }

      if(entry.address.empty() && string::npos != line.find("购买人地址")){
	  getline(is, line);
	  regex_search(line, sr, exp);
	  entry.address.assign(sr[1]);
	  trim(entry.address);
	  continue;
      }

      if(entry.phone.empty() && string::npos != line.find("购买人固定电话")){
	  getline(is, line);
	  regex_search(line, sr, exp);
	  string tmp(sr[1]);
	  if(tmp.length() >= 7){
	    entry.phone.assign(tmp);
	    trim(entry.phone);
	  }
	  continue;
      }

      if(entry.phone.empty() && string::npos != line.find("手　　机")){
	  getline(is, line);
	  regex_search(line, sr, exp);
	  string tmp(sr[1]);
	  if(tmp.length() >= 7){
	    entry.phone.assign(tmp);
	    trim(entry.phone);
	  }
	  continue;
      }

      if(entry.passport.empty() && string::npos != line.find("户口本号")){
	  getline(is, line);
	  regex_search(line, sr, exp);
	  entry.passport.assign(sr[1]);
	  trim(entry.passport);
	  continue;
      }
      if(entry.name.empty() && string::npos != line.find("购买人姓名")){
	  getline(is, line);
	  regex_search(line, sr, exp);
	  entry.name.assign(sr[1]);
	  trim(entry.name);
	  continue;
      }
      if(entry.allowance.empty() && string::npos != line.find("实际补贴金额")){
	  getline(is, line);
	  regex_search(line, sr, exp);
	  entry.allowance.assign(sr[1]);
	  trim(entry.allowance);
	  continue;
      }
      if(entry.time.empty() && string::npos != line.find("受理日期")){
	  getline(is, line);
	  regex_search(line, sr, exp);
	  entry.time.assign(sr[1]);
	  trim(entry.time);
	  if(entry.time.empty())
	    entry.time = now();
	  continue;
      }
      if(entry.name2.empty() && string::npos != line.find("代领人姓名")){
	  getline(is, line);
	  regex_search(line, sr, exp);
	  entry.name2.assign(sr[1]);
	  trim(entry.name2);
	  if(entry.name2.empty())
	      entry.name2 = entry.name;
	  break;
      }
  }



  boost::filesystem::path p(file);
  entry.id = atoi(p.stem().string().c_str());
  entry.xz = which_XZ(entry.address);
  while(entry.id > entrys.size()){
      Entry e;
      e.id = -1;
      entrys.push_back(e);
  }
  entrys[entry.id-1] = entry;
 // this->entrys.push_back(entry);
  return entry;
}

const char *xz_str[XZ_SIZE] = {
    "李店", "府城", "南城", "赵棚", 
    "巡店", "棠棣", "王义贞", "雷公",
    "孛畈", "烟店", "洑水", "陈店", 
    "辛榨", "木梓", "接官", "开发区",
    "未检测出",
};
XZs which_XZ(string address)
{
  if(string::npos != address.find("李店"))
    return XZ_LD;
  if(string::npos != address.find("府城"))
    return XZ_FC;
  if(string::npos != address.find("南城"))
    return XZ_NC;
  if(string::npos != address.find("赵棚"))
    return XZ_ZP;
  if(string::npos != address.find("巡店"))
    return XZ_XD;
  if(string::npos != address.find("棠棣"))
    return XZ_TL;
  if(string::npos != address.find("王义贞"))
    return XZ_WYZ;
  if(string::npos != address.find("雷公"))
    return XZ_LG;
  if(string::npos != address.find("孛畈"))
    return XZ_BF;
  if(string::npos != address.find("烟店"))
    return XZ_YD;
  if(string::npos != address.find("洑水"))
    return XZ_FS;
  if(string::npos != address.find("陈店"))
    return XZ_CD;
  if(string::npos != address.find("辛榨"))
    return XZ_XZ;
  if(string::npos != address.find("木梓"))
    return XZ_MZ;
  if(string::npos != address.find("接官"))
    return XZ_JG;
  if(string::npos != address.find("开发区"))
    return XZ_KFQ;

  return XZ_NULL;
}
