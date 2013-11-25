#if !defined(AFX_DIALOG1_H__BC092B92_D9A6_4875_885A_781DB333EC6F__INCLUDED_)
#define AFX_DIALOG1_H__BC092B92_D9A6_4875_885A_781DB333EC6F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dialog1.h : Header-Datei
//

/////////////////////////////////////////////////////////////////////////////
// Dialogfeld Dialog1 

class Dialog1 : public CDialog
{
// Konstruktion
public:
	CString test(void);
	Dialog1(CWnd* pParent = NULL);   // Standardkonstruktor

// Dialogfelddaten
	//{{AFX_DATA(Dialog1)
	enum { IDD = IDD_DIALOG1 };
	//}}AFX_DATA


// Überschreibungen
	// Vom Klassen-Assistenten generierte virtuelle Funktionsüberschreibungen
	//{{AFX_VIRTUAL(Dialog1)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterstützung
	//}}AFX_VIRTUAL

// Implementierung
protected:

	// Generierte Nachrichtenzuordnungsfunktionen
	//{{AFX_MSG(Dialog1)
		// HINWEIS: Der Klassen-Assistent fügt hier Member-Funktionen ein
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ fügt unmittelbar vor der vorhergehenden Zeile zusätzliche Deklarationen ein.

#endif // AFX_DIALOG1_H__BC092B92_D9A6_4875_885A_781DB333EC6F__INCLUDED_
