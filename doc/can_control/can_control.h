// can_control.h : Haupt-Header-Datei f�r die Anwendung CAN_CONTROL
//

#if !defined(AFX_CAN_CONTROL_H__CA6CB642_4FF0_4A4E_96BD_0915617F2158__INCLUDED_)
#define AFX_CAN_CONTROL_H__CA6CB642_4FF0_4A4E_96BD_0915617F2158__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// Hauptsymbole

/////////////////////////////////////////////////////////////////////////////
// CCan_controlApp:
// Siehe can_control.cpp f�r die Implementierung dieser Klasse
//

class CCan_controlApp : public CWinApp
{
public:
	CCan_controlApp();

// �berladungen
	// Vom Klassenassistenten generierte �berladungen virtueller Funktionen
	//{{AFX_VIRTUAL(CCan_controlApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementierung

	//{{AFX_MSG(CCan_controlApp)
		// HINWEIS - An dieser Stelle werden Member-Funktionen vom Klassen-Assistenten eingef�gt und entfernt.
		//    Innerhalb dieser generierten Quelltextabschnitte NICHTS VER�NDERN!
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ f�gt unmittelbar vor der vorhergehenden Zeile zus�tzliche Deklarationen ein.

#endif // !defined(AFX_CAN_CONTROL_H__CA6CB642_4FF0_4A4E_96BD_0915617F2158__INCLUDED_)
