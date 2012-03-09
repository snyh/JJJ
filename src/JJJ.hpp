#include "gui.h"
#include "entry.hpp"
#include <wx/wx.h>
#include <wx/grid.h>
#include <wx/html/htmlwin.h>
#include <wx/filename.h>

#include <vector>
#include <string>

class JJJmaindialog : public maindialog
{
  wxGrid *grid1, *grid2;
  wxHtmlWindow *page3;
  wxFileName dir_path;
  std::vector<Entry> entrys;
  std::vector<Entry2> entrys2;

  XZs selected_xz;

protected:
  void m_select_xz(wxMouseEvent& e);
  void maindialogOnClose( wxCloseEvent& event );
  void b_docOnButtonClick( wxCommandEvent& event );
  void b_printOnButtonClick( wxCommandEvent& event );
  void c_allOnCheckBox( wxCommandEvent& event );
  void b_table1OnButtonClick( wxCommandEvent& event );
  void b_clearOnButtonClick( wxCommandEvent& event );
  void b_listenOnButtonClick(wxCommandEvent& event);
  void m_notebookOnNotebookPageChanged(wxNotebookEvent& event);

  void m_grid1OnGridCellLeftDClick(wxGridEvent& event);


  void OnGridLabelLeftDClick(wxGridEvent& event);
  void notifyfun(int n, std::string f);
  void get_select_file(std::vector<wxString>& files);
  Entry get_entry(std::string);
  void draw_entry(Entry);
  void get_draw_entry(std::string);
public:
  JJJmaindialog( wxWindow* parent );
};
