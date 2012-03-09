///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Dec 20 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __gui__
#define __gui__

#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/statline.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/notebook.h>
#include <wx/checkbox.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////

#define XZ_0 1000
#define XZ_1 1001
#define XZ_2 1002
#define XZ_3 1003
#define XZ_4 1004
#define XZ_5 1005
#define XZ_6 1006
#define XZ_7 1007
#define XZ_8 1008
#define XZ_9 1009
#define XZ_10 1010
#define XZ_11 1011
#define XZ_12 1012
#define XZ_13 1013
#define XZ_14 1014
#define XZ_15 1015

///////////////////////////////////////////////////////////////////////////////
/// Class maindialog
///////////////////////////////////////////////////////////////////////////////
class maindialog : public wxFrame 
{
	private:
	
	protected:
		wxStaticText* m_sstaticText1;
		wxStaticText* number;
		wxStaticLine* m_staticline1;
		wxButton* b_listen;
		wxButton* b_doc;
		wxStaticText* dir_doc;
		wxNotebook* m_notebook;
		wxButton* b_print;
		wxCheckBox* c_all;
		wxStaticLine* m_staticline2;
		wxButton* b_table1;
		wxStaticText* m_staticText4;
		wxStaticText* m_staticText5;
		wxStaticText* m_staticText6;
		wxStaticText* m_staticText7;
		wxStaticText* m_staticText8;
		wxStaticText* m_staticText9;
		wxStaticText* m_staticText10;
		wxStaticText* m_staticText11;
		wxStaticText* m_staticText12;
		wxStaticText* m_staticText13;
		wxStaticText* m_staticText14;
		wxStaticText* m_staticText15;
		wxStaticText* m_staticText16;
		wxStaticText* m_staticText17;
		wxStaticText* m_staticText18;
		wxStaticText* m_staticText19;
		
		// Virtual event handlers, overide them in your derived class
		virtual void b_listenOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void b_docOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_notebookOnNotebookPageChanged( wxNotebookEvent& event ) { event.Skip(); }
		virtual void b_printOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void c_allOnCheckBox( wxCommandEvent& event ) { event.Skip(); }
		virtual void b_table1OnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_select_xz( wxMouseEvent& event ) { event.Skip(); }
		
	
	public:
		
		maindialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("永佳电子-家电下乡报表辅助生成"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 800,600 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		~maindialog();
	
};

#endif //__gui__
