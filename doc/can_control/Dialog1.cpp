// Dialog1.cpp: Implementierungsdatei
//

#include "stdafx.h"
#include "can_control.h"
#include "Dialog1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Dialogfeld Dialog1 


Dialog1::Dialog1(CWnd* pParent /*=NULL*/)
	: CDialog(Dialog1::IDD, pParent)
{
	//{{AFX_DATA_INIT(Dialog1)
	//}}AFX_DATA_INIT
}


void Dialog1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Dialog1)
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Dialog1, CDialog)
	//{{AFX_MSG_MAP(Dialog1)
		// HINWEIS: Der Klassen-Assistent fügt hier Zuordnungsmakros für Nachrichten ein
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Behandlungsroutinen für Nachrichten Dialog1 

CString Dialog1::test()
{
	return m_string;
}
