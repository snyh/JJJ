///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Dec 20 2010)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "gui.h"

///////////////////////////////////////////////////////////////////////////

maindialog::maindialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxHORIZONTAL );
	
	m_sstaticText1 = new wxStaticText( this, wxID_ANY, wxT("当前文件数:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_sstaticText1->Wrap( -1 );
	bSizer4->Add( m_sstaticText1, 0, wxALL, 5 );
	
	number = new wxStaticText( this, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	number->Wrap( -1 );
	bSizer4->Add( number, 0, wxALL, 5 );
	
	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	m_staticline1->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_APPWORKSPACE ) );
	
	bSizer4->Add( m_staticline1, 1, wxEXPAND | wxALL, 5 );
	
	b_listen = new wxButton( this, wxID_ANY, wxT("开始监听"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( b_listen, 0, wxALL, 5 );
	
	b_doc = new wxButton( this, wxID_ANY, wxT("存档文件夹"), wxDefaultPosition, wxDefaultSize, 0 );
	b_doc->SetDefault(); 
	bSizer4->Add( b_doc, 0, wxALL, 5 );
	
	dir_doc = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	dir_doc->Wrap( -1 );
	bSizer4->Add( dir_doc, 0, wxALL, 5 );
	
	bSizer2->Add( bSizer4, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );
	
	m_notebook = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	bSizer3->Add( m_notebook, 1, wxEXPAND | wxALL, 5 );
	
	bSizer2->Add( bSizer3, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxHORIZONTAL );
	
	b_print = new wxButton( this, wxID_ANY, wxT("总上报表"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add( b_print, 0, wxALL, 5 );
	
	c_all = new wxCheckBox( this, wxID_ANY, wxT("全选"), wxDefaultPosition, wxDefaultSize, 0 );
	c_all->SetValue(true); 
	bSizer5->Add( c_all, 0, wxALL, 5 );
	
	m_staticline2 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	m_staticline2->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_APPWORKSPACE ) );
	
	bSizer5->Add( m_staticline2, 1, wxEXPAND | wxALL, 5 );
	
	b_table1 = new wxButton( this, wxID_ANY, wxT("统计表"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add( b_table1, 0, wxALL, 5 );
	
	bSizer2->Add( bSizer5, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText4 = new wxStaticText( this, XZ_0, wxT("李店"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	m_staticText4->SetForegroundColour( wxColour( 85, 152, 215 ) );
	
	bSizer7->Add( m_staticText4, 0, wxALL, 5 );
	
	m_staticText5 = new wxStaticText( this, XZ_1, wxT("府城"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	m_staticText5->SetForegroundColour( wxColour( 222, 165, 165 ) );
	
	bSizer7->Add( m_staticText5, 0, wxALL, 5 );
	
	m_staticText6 = new wxStaticText( this, XZ_2, wxT("南城"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	m_staticText6->SetForegroundColour( wxColour( 255, 118, 118 ) );
	
	bSizer7->Add( m_staticText6, 0, wxALL, 5 );
	
	m_staticText7 = new wxStaticText( this, XZ_3, wxT("赵棚"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	m_staticText7->SetForegroundColour( wxColour( 3, 156, 154 ) );
	
	bSizer7->Add( m_staticText7, 0, wxALL, 5 );
	
	m_staticText8 = new wxStaticText( this, XZ_4, wxT("巡店"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8->Wrap( -1 );
	m_staticText8->SetForegroundColour( wxColour( 24, 201, 49 ) );
	
	bSizer7->Add( m_staticText8, 0, wxALL, 5 );
	
	m_staticText9 = new wxStaticText( this, XZ_5, wxT("棠棣"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText9->Wrap( -1 );
	m_staticText9->SetForegroundColour( wxColour( 145, 52, 52 ) );
	
	bSizer7->Add( m_staticText9, 0, wxALL, 5 );
	
	m_staticText10 = new wxStaticText( this, XZ_6, wxT("王义贞"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText10->Wrap( -1 );
	m_staticText10->SetForegroundColour( wxColour( 233, 51, 225 ) );
	
	bSizer7->Add( m_staticText10, 0, wxALL, 5 );
	
	m_staticText11 = new wxStaticText( this, XZ_7, wxT("雷公"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11->Wrap( -1 );
	m_staticText11->SetForegroundColour( wxColour( 79, 25, 73 ) );
	
	bSizer7->Add( m_staticText11, 0, wxALL, 5 );
	
	m_staticText12 = new wxStaticText( this, XZ_8, wxT("孛畈"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText12->Wrap( -1 );
	m_staticText12->SetForegroundColour( wxColour( 228, 217, 4 ) );
	
	bSizer7->Add( m_staticText12, 0, wxALL, 5 );
	
	m_staticText13 = new wxStaticText( this, XZ_9, wxT("烟店"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText13->Wrap( -1 );
	m_staticText13->SetForegroundColour( wxColour( 191, 118, 8 ) );
	
	bSizer7->Add( m_staticText13, 0, wxALL, 5 );
	
	m_staticText14 = new wxStaticText( this, XZ_10, wxT("洑水"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText14->Wrap( -1 );
	m_staticText14->SetForegroundColour( wxColour( 2, 4, 115 ) );
	
	bSizer7->Add( m_staticText14, 0, wxALL, 5 );
	
	m_staticText15 = new wxStaticText( this, XZ_11, wxT("陈店"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText15->Wrap( -1 );
	m_staticText15->SetForegroundColour( wxColour( 160, 34, 180 ) );
	
	bSizer7->Add( m_staticText15, 0, wxALL, 5 );
	
	m_staticText16 = new wxStaticText( this, XZ_12, wxT("辛榨"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText16->Wrap( -1 );
	m_staticText16->SetForegroundColour( wxColour( 28, 112, 4 ) );
	
	bSizer7->Add( m_staticText16, 0, wxALL, 5 );
	
	m_staticText17 = new wxStaticText( this, XZ_13, wxT("木梓"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText17->Wrap( -1 );
	m_staticText17->SetForegroundColour( wxColour( 26, 119, 50 ) );
	
	bSizer7->Add( m_staticText17, 0, wxALL, 5 );
	
	m_staticText18 = new wxStaticText( this, XZ_14, wxT("接官"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText18->Wrap( -1 );
	m_staticText18->SetForegroundColour( wxColour( 176, 242, 17 ) );
	
	bSizer7->Add( m_staticText18, 0, wxALL, 5 );
	
	m_staticText19 = new wxStaticText( this, XZ_15, wxT("开发区"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText19->Wrap( -1 );
	m_staticText19->SetForegroundColour( wxColour( 66, 7, 7 ) );
	
	bSizer7->Add( m_staticText19, 0, wxALL, 5 );
	
	bSizer2->Add( bSizer7, 0, 0, 5 );
	
	this->SetSizer( bSizer2 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	b_listen->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( maindialog::b_listenOnButtonClick ), NULL, this );
	b_doc->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( maindialog::b_docOnButtonClick ), NULL, this );
	m_notebook->Connect( wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED, wxNotebookEventHandler( maindialog::m_notebookOnNotebookPageChanged ), NULL, this );
	b_print->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( maindialog::b_printOnButtonClick ), NULL, this );
	c_all->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( maindialog::c_allOnCheckBox ), NULL, this );
	b_table1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( maindialog::b_table1OnButtonClick ), NULL, this );
	m_staticText4->Connect( wxEVT_LEFT_DOWN, wxMouseEventHandler( maindialog::m_select_xz ), NULL, this );
	m_staticText5->Connect( wxEVT_LEFT_DOWN, wxMouseEventHandler( maindialog::m_select_xz ), NULL, this );
	m_staticText6->Connect( wxEVT_LEFT_DOWN, wxMouseEventHandler( maindialog::m_select_xz ), NULL, this );
	m_staticText7->Connect( wxEVT_LEFT_DOWN, wxMouseEventHandler( maindialog::m_select_xz ), NULL, this );
	m_staticText8->Connect( wxEVT_LEFT_DOWN, wxMouseEventHandler( maindialog::m_select_xz ), NULL, this );
	m_staticText9->Connect( wxEVT_LEFT_DOWN, wxMouseEventHandler( maindialog::m_select_xz ), NULL, this );
	m_staticText10->Connect( wxEVT_LEFT_DOWN, wxMouseEventHandler( maindialog::m_select_xz ), NULL, this );
	m_staticText11->Connect( wxEVT_LEFT_DOWN, wxMouseEventHandler( maindialog::m_select_xz ), NULL, this );
	m_staticText12->Connect( wxEVT_LEFT_DOWN, wxMouseEventHandler( maindialog::m_select_xz ), NULL, this );
	m_staticText13->Connect( wxEVT_LEFT_DOWN, wxMouseEventHandler( maindialog::m_select_xz ), NULL, this );
	m_staticText14->Connect( wxEVT_LEFT_DOWN, wxMouseEventHandler( maindialog::m_select_xz ), NULL, this );
	m_staticText15->Connect( wxEVT_LEFT_DOWN, wxMouseEventHandler( maindialog::m_select_xz ), NULL, this );
	m_staticText16->Connect( wxEVT_LEFT_DOWN, wxMouseEventHandler( maindialog::m_select_xz ), NULL, this );
	m_staticText17->Connect( wxEVT_LEFT_DOWN, wxMouseEventHandler( maindialog::m_select_xz ), NULL, this );
	m_staticText18->Connect( wxEVT_LEFT_DOWN, wxMouseEventHandler( maindialog::m_select_xz ), NULL, this );
	m_staticText19->Connect( wxEVT_LEFT_DOWN, wxMouseEventHandler( maindialog::m_select_xz ), NULL, this );
}

maindialog::~maindialog()
{
	// Disconnect Events
	b_listen->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( maindialog::b_listenOnButtonClick ), NULL, this );
	b_doc->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( maindialog::b_docOnButtonClick ), NULL, this );
	m_notebook->Disconnect( wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED, wxNotebookEventHandler( maindialog::m_notebookOnNotebookPageChanged ), NULL, this );
	b_print->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( maindialog::b_printOnButtonClick ), NULL, this );
	c_all->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( maindialog::c_allOnCheckBox ), NULL, this );
	b_table1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( maindialog::b_table1OnButtonClick ), NULL, this );
	m_staticText4->Disconnect( wxEVT_LEFT_DOWN, wxMouseEventHandler( maindialog::m_select_xz ), NULL, this );
	m_staticText5->Disconnect( wxEVT_LEFT_DOWN, wxMouseEventHandler( maindialog::m_select_xz ), NULL, this );
	m_staticText6->Disconnect( wxEVT_LEFT_DOWN, wxMouseEventHandler( maindialog::m_select_xz ), NULL, this );
	m_staticText7->Disconnect( wxEVT_LEFT_DOWN, wxMouseEventHandler( maindialog::m_select_xz ), NULL, this );
	m_staticText8->Disconnect( wxEVT_LEFT_DOWN, wxMouseEventHandler( maindialog::m_select_xz ), NULL, this );
	m_staticText9->Disconnect( wxEVT_LEFT_DOWN, wxMouseEventHandler( maindialog::m_select_xz ), NULL, this );
	m_staticText10->Disconnect( wxEVT_LEFT_DOWN, wxMouseEventHandler( maindialog::m_select_xz ), NULL, this );
	m_staticText11->Disconnect( wxEVT_LEFT_DOWN, wxMouseEventHandler( maindialog::m_select_xz ), NULL, this );
	m_staticText12->Disconnect( wxEVT_LEFT_DOWN, wxMouseEventHandler( maindialog::m_select_xz ), NULL, this );
	m_staticText13->Disconnect( wxEVT_LEFT_DOWN, wxMouseEventHandler( maindialog::m_select_xz ), NULL, this );
	m_staticText14->Disconnect( wxEVT_LEFT_DOWN, wxMouseEventHandler( maindialog::m_select_xz ), NULL, this );
	m_staticText15->Disconnect( wxEVT_LEFT_DOWN, wxMouseEventHandler( maindialog::m_select_xz ), NULL, this );
	m_staticText16->Disconnect( wxEVT_LEFT_DOWN, wxMouseEventHandler( maindialog::m_select_xz ), NULL, this );
	m_staticText17->Disconnect( wxEVT_LEFT_DOWN, wxMouseEventHandler( maindialog::m_select_xz ), NULL, this );
	m_staticText18->Disconnect( wxEVT_LEFT_DOWN, wxMouseEventHandler( maindialog::m_select_xz ), NULL, this );
	m_staticText19->Disconnect( wxEVT_LEFT_DOWN, wxMouseEventHandler( maindialog::m_select_xz ), NULL, this );
	
}
