#include "JJJ.hpp"

#include <boost/function.hpp>
#include <boost/bind.hpp>
#include <boost/foreach.hpp>
#include <boost/lexical_cast.hpp>
#define BOOST_THREAD_USE_LIB
#include <boost/thread.hpp>
#include <boost/xpressive/xpressive.hpp>
#include <boost/algorithm/string.hpp>
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <wx/fs_mem.h>

using namespace std;
int init_dir(std::string, boost::function<void(string)>);
void write_excel(vector<Entry>&, vector<Entry2>&);


class MyApp: public wxApp{
public:
  virtual bool OnInit();
};
DECLARE_APP(MyApp)
IMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
  wxFileSystem::AddHandler(new wxMemoryFSHandler);
  wxImage::AddHandler(new wxGIFHandler());
  SetTopWindow(new JJJmaindialog(NULL));
  GetTopWindow()->Show();
  return true;
}

JJJmaindialog::JJJmaindialog( wxWindow* parent )
     : maindialog( parent ), selected_xz(XZ_NULL)
{
  dir_path.Assign(wxGetCwd(), _T("doc"));

  extern const char* xz_str[];
  for(int i=0; i<XZ_SIZE; i++){
      Entry2 e;
      e.address = xz_str[i];
      e.number = 0;
      e.prices = 0;
      e.allowances = 0;
      entrys2.push_back(e);
  }

  //dir_path 为存储文档的路径 默认为当前目录下的doc
  dir_doc->SetLabel(dir_path.GetFullPath());
  if(!wxDirExists(dir_path.GetFullPath()))
    wxMkdir(dir_path.GetFullPath());

  grid1 = new wxGrid(m_notebook, wxID_ANY, wxDefaultPosition);
  grid2 = new wxGrid(m_notebook, wxID_ANY, wxDefaultPosition);
  page3 = new wxHtmlWindow(m_notebook, wxID_ANY, wxDefaultPosition);

  grid1->Connect(wxEVT_GRID_LABEL_LEFT_DCLICK, 
		 wxGridEventHandler(JJJmaindialog::OnGridLabelLeftDClick), NULL, this);
  grid1->Connect(wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler(JJJmaindialog::m_grid1OnGridCellLeftDClick ), NULL, this);


  grid1->AutoSize();
  grid1->SetRowLabelSize(30);
  grid1->AutoSizeColumns();
  grid1->CreateGrid(0, 15);
  grid1->SetColFormatBool(0);
  grid1->EnableEditing(false);

  grid1->SetColLabelValue(0, _T(""));
  grid1->SetColSize(0, 20);
  grid1->SetColLabelValue(1, _T("序号"));
  grid1->SetColSize(1, 30);
  grid1->SetColLabelValue(2, _T("地址"));
  grid1->SetColSize(2, 300);
  grid1->SetColLabelValue(3, _T("购买人"));
  grid1->SetColSize(3, 60);
  grid1->SetColLabelValue(4, _T("户口"));
  grid1->SetColSize(4, 90);
  grid1->SetColLabelValue(5, _T("身份证"));
  grid1->SetColSize(5, 150);
  grid1->SetColLabelValue(6, _T("销售种类"));
  grid1->SetColSize(6, 60);
  grid1->SetColLabelValue(7, _T("产品标识卡"));
  grid1->SetColSize(7, 200);
  grid1->SetColLabelValue(8, _T("产品编号"));
  grid1->SetColSize(8, 200);
  grid1->SetColLabelValue(9, _T("发票"));
  grid1->SetColSize(9, 65);
  grid1->SetColLabelValue(10, _T("售价"));
  grid1->SetColSize(10, 40);
  grid1->SetColLabelValue(11, _T("补贴"));
  grid1->SetColSize(11, 50);
  grid1->SetColLabelValue(12, _T("领款人"));
  grid1->SetColSize(12, 60);
  grid1->SetColLabelValue(13, _T("受理时间"));
  grid1->SetColSize(13, 90);
  grid1->SetColLabelValue(14, _T("电话"));
  grid1->SetColSize(14, 100);

  grid2->EnableEditing(false);
  grid2->CreateGrid(0, 4);
  grid2->SetColLabelValue(0, _T("县镇"));
  grid2->SetColSize(0, 60);
  grid2->SetColLabelValue(1, _T("人数"));
  grid2->SetColSize(1, 50);
  grid2->SetColLabelValue(2, _T("销售额"));
  grid2->SetColSize(2, 150);
  grid2->SetColLabelValue(3, _T("补贴金额"));
  grid2->SetColSize(3, 150);


  m_notebook->AddPage(grid1, _T("总表1"), true);
  m_notebook->AddPage(grid2, _T("总表2"));
  m_notebook->AddPage(page3, _T("上报联"));

}

void JJJmaindialog::maindialogOnClose( wxCloseEvent& event )
{
  Destroy();
}

void JJJmaindialog::b_docOnButtonClick( wxCommandEvent& event )
{

  wxString dir = wxDirSelector(_T("选择保存表单的路径"));
  if(!dir.empty()) {
      this->dir_path = dir;
      dir_doc->SetLabel(dir_path.GetFullPath());

  }
}

//生成总上报表并用word打开 方便打印
void JJJmaindialog::b_printOnButtonClick(wxCommandEvent& event)
{
  wxString data;
  const wxString page_break(_("<br style='page-break-before:always'/>"));
  for(int i=0; i<grid1->GetNumberRows(); ++i){
      wxFileName file(dir_path.GetFullPath(),
		      wxString::Format(_T("%d"),i+1),
		      _T("doc"));
      cout << "file:" << file.GetFullPath().mb_str() << "\n";
      if(grid1->GetCellValue(i, 0) == _T("1")){
	  if(file.FileExists()) {
	      data += wxString(get_page3( file.GetFullPath().mb_str()).c_str(),
			       wxConvLocal);
	      data += page_break;
	  }
      }
  }
  if(data.length() > page_break.length()) //一个都没有选择的时候不能继续删除
    data.erase(data.length() - page_break.length(), page_break.length());
  ofstream of("sbb.doc");
  of << data.mb_str();
  of.close();
  wxFileName word(wxGetCwd(), _T("sbb.doc"));
  wxExecute(_T("explorer ") + word.GetFullPath());
}

void JJJmaindialog::b_listenOnButtonClick(wxCommandEvent& event)
{
  // 设置默认下载路径
  string down_dir(dir_path.GetFullPath().mb_str());
  size_t p1=0;
  do{
      try{
	  p1 = down_dir.find('\\', p1);
	  down_dir.insert(p1, "\\");
	  p1 = p1+2;
      } catch (...){
	  p1 = string::npos;
      }
  } while(p1 != string::npos);
#ifdef __WIN32__
  ofstream of("c:\\_JJJ_tmp.reg");
  of << "Windows Registry Editor Version 5.00\n"
    << "[HKEY_CURRENT_USER\\Software\\Microsoft\\Internet Explorer]\n"
    << "\"Download Directory\"=\""
    << down_dir << "\"\n";
  of.close();
  wxExecute(_T("regedit /s c:\\_JJJ_tmp.reg"));
  wxSleep(1);
  remove("c:\\_JJJ_tmp.reg");
#endif







  boost::function<void(string)> f=boost::bind(&JJJmaindialog::get_draw_entry, this, _1);
  int n = init_dir(string(dir_path.GetFullPath().mb_str()), f);
  number->SetLabel(wxString::Format(_T("%d"), n));


  typedef boost::function<void(int, std::string)> NotifyFun;
  b_doc->Enable(false);
  b_listen->SetLabel(_T("监听中.."));
  b_listen->Enable(false);
  void monitor(std::string, NotifyFun);
  NotifyFun fun = boost::bind(&JJJmaindialog::notifyfun, this, _1, _2);

  boost::thread t(boost::bind(monitor,std::string(dir_path.GetFullPath().mb_str()), fun));
  t.detach();

}
void JJJmaindialog::notifyfun(int n, std::string f)
{
  this->number->SetLabel(wxString::Format(_T("%d 个"), n));
  draw_entry(get_entry(f));
}

void JJJmaindialog::get_draw_entry(std::string f)
{
  draw_entry(get_entry(f));
}
void JJJmaindialog::draw_entry(Entry entry)
{
  int n = entry.id;
  using namespace boost::xpressive;

  int rows = grid1->GetNumberRows();
  if(rows <= n){
      grid1->AppendRows(n-rows);
  }
  n--;

  if(grid1->InsertRows(n))
    grid1->DeleteRows(n); //删除之前的错误颜色标记等

  static wxColour xz_colors[XZ_SIZE]={
      wxColour(85, 152, 215), //李店
      wxColour(222, 165, 165), //府城
      wxColour(255,118,118), //南城
      wxColour(3,156, 154), //赵棚
      wxColour(24, 201, 49), //巡店 
      wxColour(145, 52, 52), //棠棣
      wxColour(233, 51, 225), //王义贞
      wxColour(79, 25, 73), //雷公
      wxColour(228, 217, 4), //孛畈
      wxColour(191,118,8), //烟店
      wxColour(2,4,115), //洑水
      wxColour(160,34,180), //陈店
      wxColour(28,112,4),//辛榨
      wxColour(26,119,50),//木梓
      wxColour(176,242,17), //接官
      wxColour(66,7,7), //开发区
      wxColour(_T("white")), //未知区域
  };
  //设置地域背景颜色
  wxColour &bg_color = xz_colors[entry.xz];
  for(int i=1; i<15; i++){
      grid1->SetCellBackgroundColour(n, i, bg_color);
  }

    {
      //检测是否重复行 只检测 发票号 产品标示号 产品编码
      int i=0;
      for(i=0; i<grid1->GetNumberRows(); i++){
	  if( grid1->GetCellValue(i, 7) == wxString(entry.product_id.c_str(), wxConvLocal) ||
	      grid1->GetCellValue(i, 8) == wxString(entry.product_n.c_str(), wxConvLocal) ||
	      grid1->GetCellValue(i, 9) == wxString(entry.invoice.c_str(), wxConvLocal)) {

	      for(int j=7; j<=9; j++){
		  grid1->SetCellTextColour(i, j, *wxRED);
		  grid1->SetCellTextColour(n, j, *wxRED);
	      }
	      break;
	  }
      }
    }

  grid1->SetCellValue(n, 0, _T("1"));
  grid1->SetCellValue(n, 1, wxString::Format(_T("%d"), entry.id));
  grid1->SetCellValue(n, 2, wxString(entry.address.c_str(), wxConvLocal));
  grid1->SetCellValue(n, 3, wxString(entry.name.c_str(), wxConvLocal)); 

  grid1->SetCellValue(n, 4, wxString(entry.passport.c_str(), wxConvLocal));


  grid1->SetCellValue(n, 5, wxString(entry.idcard.c_str(), wxConvLocal)); //身份证15 or 18  
  if(entry.idcard.length() != 18 && entry.idcard.length() != 15)
    grid1->SetCellTextColour(n, 5, *wxRED);

  grid1->SetCellValue(n, 6, wxString(entry.cat.c_str(), wxConvLocal));

  grid1->SetCellValue(n, 7, wxString(entry.product_id.c_str(), wxConvLocal)); 
  grid1->SetCellValue(n, 8, wxString(entry.product_n.c_str(), wxConvLocal));

  grid1->SetCellValue(n, 9, wxString(entry.invoice.c_str(), wxConvLocal));
  if(entry.invoice.length() != 8) 
    grid1->SetCellTextColour(n, 9, *wxRED);

  grid1->SetCellValue(n, 10, wxString(entry.price.c_str(), wxConvLocal));  
  grid1->SetCellValue(n, 11, wxString(entry.allowance.c_str(), wxConvLocal));

  grid1->SetCellValue(n, 12, wxString(entry.name2.c_str(), wxConvLocal));
  grid1->SetCellValue(n, 13, wxString(entry.time.c_str(), wxConvLocal));
  grid1->SetCellValue(n, 14, wxString(entry.phone.c_str(), wxConvLocal));
}
void JJJmaindialog::OnGridLabelLeftDClick(wxGridEvent& event)
{
  if(event.GetRow() != -1) {
      wxString id = grid1->GetCellValue(event.GetRow(), 0);
      wxFileName file(dir_path.GetFullPath(), id, _T("doc"));
      if(file.FileExists()) {
	  std::string data = get_page3(file.GetFullPath().mb_str());
	  if(page3->SetPage(wxString(data.c_str(), wxConvLocal)))
	    m_notebook->ChangeSelection(2); 
      }
  }
}

//计算entrys2 并显示总表2
//函数名仅仅是机制名
void JJJmaindialog::m_notebookOnNotebookPageChanged(wxNotebookEvent& event)
{
  if(event.GetSelection() == 1){ 
      BOOST_FOREACH(Entry2& e, entrys2){ //重新初始化
	  e.allowances = 0;
	  e.number = 0;
	  e.prices = 0;
      }
      cout << "OK1\n";
      BOOST_FOREACH(const Entry e, entrys){
	  if(e.id == -1)
	    continue;
	  cout << e.id << "\n";
	  entrys2[e.xz].number++;
	  entrys2[e.xz].prices += atof(e.price.c_str()); 
	  entrys2[e.xz].allowances += atof(e.allowance.c_str()); 
      }
      cout << "OK2\n";
      double price = 0, allowance = 0;
      int number = 0;
      int i=0;
      grid2->DeleteRows(0, grid2->GetNumberRows());
      BOOST_FOREACH(Entry2 e, entrys2){
	  if(e.number != 0){
	      grid2->AppendRows();
	      grid2->SetCellValue(i, 0, wxString(e.address.c_str(), wxConvLocal));
	      grid2->SetCellValue(i, 1, wxString::Format(_T("%d"), e.number));
	      grid2->SetCellValue(i, 2, wxString::Format(_T("¥%f"), e.prices));
	      grid2->SetCellValue(i, 3, wxString::Format(_T("¥%f"), e.allowances));
	      price += e.prices;
	      allowance += e.allowances;
	      number += e.number;
	      i++;
	  }
      }
      grid2->AppendRows();
      grid2->SetCellValue(i, 0, _T("总计"));
      grid2->SetCellValue(i, 1, wxString::Format(_T("%d"), number));
      grid2->SetCellValue(i, 2, wxString::Format(_T("¥%f"), price));
      grid2->SetCellValue(i, 3, wxString::Format(_T("¥%f"), allowance));
  }
  event.Skip(true);
}
void JJJmaindialog::c_allOnCheckBox( wxCommandEvent& event )
{
  for(int i=0; i<grid1->GetNumberRows(); ++i){
      grid1->SetCellValue(i, 0, c_all->IsChecked() ? _T("1") : _T("0"));
  }
}

void JJJmaindialog::b_table1OnButtonClick( wxCommandEvent& event )
{
  m_notebook->SetSelection(1);
#ifdef WIN32
  write_excel(entrys, entrys2);
#endif
}


void JJJmaindialog::b_clearOnButtonClick( wxCommandEvent& event )
{
  // TODO: Implement b_clearOnButtonClick
}
void JJJmaindialog::m_grid1OnGridCellLeftDClick(wxGridEvent& event)
{
  int col = event.GetCol();
  int row = event.GetRow();
  if(col == 0){
      if(grid1->GetCellValue(row, col)==_T("1"))
	grid1->SetCellValue(row, col, _T("0"));
      else
	grid1->SetCellValue(row, col, _T("1"));
  }
  if(col == 2 && selected_xz != XZ_NULL &&
     which_XZ(string(grid1->GetCellValue(row, 2).mb_str())) == XZ_NULL
    ){
      Entry& e = entrys[row];
      e.xz = selected_xz;
      draw_entry(e);
      selected_xz = XZ_NULL;
      grid1->Refresh();
  }
}

void JJJmaindialog::m_select_xz(wxMouseEvent& e)
{
  this->selected_xz = XZs(e.GetId() - 1000); //magic ... sorry; 
  wxSetCursor(*wxCROSS_CURSOR);
  cout << "Ok\n";
}
