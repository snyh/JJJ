#include <vole/vole.hpp>
#include <boost/format.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/foreach.hpp>
#include <comstl/util/initialisers.hpp>
#include <comstl/util/variant.hpp>
#include <winstl/error/error_desc.hpp>
#include <boost/array.hpp>
#include <boost/filesystem.hpp>
#include <iostream>
#include <vector>
#include "entry.hpp"
using namespace std;
using namespace boost::filesystem;

extern boost::array<char, 13824> _RC_template;

inline
string _r(const string& col, const int row){
    return boost::str(boost::format("%1%%2%") % col % (row + 6));
}
void write_excel(vector<Entry>& entrys, vector<Entry2>& entrys2)
{
  ofstream of("new.xls", ostream::binary);
  copy(_RC_template.begin(), _RC_template.end(),
       ostream_iterator<unsigned char>(of));
  of.close();

  path tmp = current_path();
  tmp /= "new.xls";

  try {
      comstl::ole_init    coinit;
      using vole::object;
      using vole::collection;
      object xlApp = object::create(L"Excel.Application", CLSCTX_LOCAL_SERVER, vole::coercion_level::naturalPromotion);
      xlApp.put_property(L"Visible", 1);
      collection xlBooks = xlApp.get_property<collection>(L"Workbooks");
      object xlBook = xlBooks.get_property<object>(L"Open", 
						   tmp.string().c_str());
      object xlSheet = xlApp.get_property<object>(L"ActiveSheet");
      int rows;
      for(rows=0; rows<entrys.size(); rows++){
	  object colA = xlSheet.get_property<object>(L"Range", _r("A", rows).c_str());
	  colA.put_property(L"Value", boost::lexical_cast<string>(entrys[rows].id).c_str());

	  object colB = xlSheet.get_property<object>(L"Range", _r("B", rows).c_str());
	  colB.put_property(L"Value", entrys[rows].address.c_str());

	  object colC = xlSheet.get_property<object>(L"Range", _r("C", rows).c_str());
	  colC.put_property(L"Value", entrys[rows].name.c_str());

	  object colD = xlSheet.get_property<object>(L"Range", _r("D", rows).c_str());
	  colD.put_property(L"Value", entrys[rows].passport.c_str());

	  object colE = xlSheet.get_property<object>(L"Range", _r("E", rows).c_str());
	  colE.put_property(L"Value", entrys[rows].idcard.c_str());

	  object colF = xlSheet.get_property<object>(L"Range", _r("F", rows).c_str());
	  colF.put_property(L"Value", entrys[rows].cat.c_str());

	  object colG = xlSheet.get_property<object>(L"Range", _r("G", rows).c_str());
	  colG.put_property(L"Value", entrys[rows].product_id.c_str());

	  object colH = xlSheet.get_property<object>(L"Range", _r("H", rows).c_str());
	  colH.put_property(L"Value", entrys[rows].product_n.c_str());

	  object colI = xlSheet.get_property<object>(L"Range", _r("I", rows).c_str());
	  colI.put_property(L"Value", entrys[rows].invoice.c_str());

	  object colJ = xlSheet.get_property<object>(L"Range", _r("J", rows).c_str());
	  colJ.put_property(L"Value", entrys[rows].price.c_str());

	  object colK = xlSheet.get_property<object>(L"Range", _r("K", rows).c_str());
	  colK.put_property(L"Value", entrys[rows].allowance.c_str());

	  object colL = xlSheet.get_property<object>(L"Range", _r("L", rows).c_str());
	  colL.put_property(L"Value", entrys[rows].name2.c_str());

	  object colM = xlSheet.get_property<object>(L"Range", _r("M", rows).c_str());
	  colM.put_property(L"Value", entrys[rows].time.c_str());

	  object colN = xlSheet.get_property<object>(L"Range", _r("N", rows).c_str());
	  colN.put_property(L"Value", entrys[rows].phone.c_str());
      }
	{
      object colI = xlSheet.get_property<object>(L"Range", _r("I", rows).c_str());
      colI.put_property(L"Value", "销售合计");

      object colJ = xlSheet.get_property<object>(L"Range", _r("J", rows).c_str());
      colJ.put_property(L"Value", ("=SUM(J6:J" + boost::lexical_cast<string>(rows+5) + ")").c_str());

      object colJK = xlSheet.get_property<object>(L"Range", 
						  (_r("J", rows) + ":" + _r("K", rows)).c_str());
      colJK.put_property(L"MergeCells", 1);
	}
      rows++;
	{
      object colI = xlSheet.get_property<object>(L"Range", _r("I", rows).c_str());
      colI.put_property(L"Value", "补贴合计");

      object colJ = xlSheet.get_property<object>(L"Range", _r("J", rows).c_str());
      colJ.put_property(L"Value", ("=SUM(K6:K" + boost::lexical_cast<string>(rows+4) + ")").c_str());

      object colJK = xlSheet.get_property<object>(L"Range", 
						  (_r("J", rows) + ":" + _r("K", rows)).c_str());
      colJK.put_property(L"MergeCells", 1);
	}

      //---表2
      object xlBook2 = xlApp.get_property<object>(L"Sheets", 2);
      xlBook2.invoke_method_v(L"Select");
      object xlSheet2 = xlApp.get_property<object>(L"ActiveSheet");

      int i=-2; // _r(x, i) i会被加上6， 但表而是以x4开始的
      BOOST_FOREACH(Entry2& e, entrys2){
	  if(e.number != 0) {
	      object colA = xlSheet2.get_property<object>(L"Range", _r("A", i).c_str());
	      colA.put_property(L"Value", e.address.c_str());

	      object colB = xlSheet2.get_property<object>(L"Range", _r("B", i).c_str());
	      colB.put_property(L"Value", (boost::lexical_cast<string>(e.number)).c_str());

	      object colC = xlSheet2.get_property<object>(L"Range", _r("C", i).c_str());
	      colC.put_property(L"Value", (boost::lexical_cast<string>(e.prices)).c_str());

	      object colD = xlSheet2.get_property<object>(L"Range", _r("D", i).c_str());
	      colD.put_property(L"Value", (boost::lexical_cast<string>(e.allowances)).c_str());
	      i++;
	  }
      }
      if(i > -2){
	  object colA = xlSheet2.get_property<object>(L"Range", _r("A", i).c_str());
	  colA.put_property(L"Value", "合计");

	  object colB = xlSheet2.get_property<object>(L"Range", _r("B", i).c_str());
	  colB.put_property(L"Value", ("=SUM(B4:B" + boost::lexical_cast<string>(i+5) + ")").c_str());

	  object colC = xlSheet2.get_property<object>(L"Range", _r("C", i).c_str());
	  colC.put_property(L"Value", ("=SUM(C4:C" + boost::lexical_cast<string>(i+5) + ")").c_str());

	  object colD = xlSheet2.get_property<object>(L"Range", _r("D", i).c_str());
	  colD.put_property(L"Value", ("=SUM(D4:D" + boost::lexical_cast<string>(i+5) + ")").c_str());
      }

  } catch (vole::vole_exception &x) {
      cout << "error: " << x.what() 
	<< ": " << winstl::error_desc(x.hr()).c_str() << endl;
  }
}
