// can_controlDlg.h : Header-Datei
//
#ifdef _DEBUG
	#define _CRTDBG_MAP_ALLOC
	#include <stdlib.h>
	#include <crtdbg.h>
#endif

#include "ftd2xx.h"
#include "afxcmn.h"
#include "afxwin.h"

#if !defined(AFX_CAN_CONTROLDLG_H__E9C7C553_9DE4_4D00_9176_8857FB529DE0__INCLUDED_)
#define AFX_CAN_CONTROLDLG_H__E9C7C553_9DE4_4D00_9176_8857FB529DE0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCan_controlDlg Dialogfeld

class CCan_controlDlg : public CDialog
{
// Konstruktion
public:
	bool m_timeOut;
	CCan_controlDlg(CWnd* pParent = NULL);	// Standard-Konstruktor

	#define CAN_OK		13
	#define CAN_ERROR	7
	#define CAN_CR		13

	#define CANMSG_EXTENDED	0x80 // Extended CAN id
	#define CANMSG_RTR		0x40 // Remote frame


	typedef struct {
		unsigned long id;        // Message id
		unsigned long timestamp; // timestamp in milliseconds	
		unsigned char flags;     // [extended_id|1][RTR:1][reserver:6]
		unsigned char len;       // Frame size (0.8)
		unsigned char data[ 8 ]; // Databytes 0..7
	} CANMsg;

	// Dialogfelddaten
	//{{AFX_DATA(CCan_controlDlg)
	enum { IDD = IDD_CAN_CONTROL_DIALOG };
	CButton	m_ctrl_CheckCyclic;
	CButton	m_ctrl_CheckASCII;
	CButton	m_ctrlExitBtn;
	CListCtrl	m_ctrlKnownID;
	CListCtrl	m_ctrlFilterID;
	CListCtrl	m_MsgList;
	CButton	m_ctrlCheckRTR;
	CButton	m_ctrlExtended;
	CButton	m_ctrlOpenBtn;
	CComboBox	m_ctrlSerialList;

	CString	m_dataReadReg;
	CString	m_dataWriteRegData;
	CString	m_dataWriteReg;
	CString	m_dataAMR;
	CString	m_dataACR;
	CString	m_MsgId;
	CString	m_Data0;
	CString	m_Data1;
	CString	m_Data2;
	CString	m_Data3;
	CString	m_Data4;
	CString	m_Data5;
	CString	m_Data6;
	CString	m_Data7;
	CString	m_sentFrames;
	CString	m_receivedFrames;
	CString	m_dataSerialList;
	CString	m_dataSelBitrate;
	CString	m_dataIntervalTime;
	//}}AFX_DATA

	// Vom Klassenassistenten generierte Überladungen virtueller Funktionen
	//{{AFX_VIRTUAL(CCan_controlDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV-Unterstützung
	//}}AFX_VIRTUAL

// Implementierung
protected:
	int AppendToLog( CString str);
	void AddIDtoKnown(CANMsg *pMsg);
	void loadRegistryData();
	void saveRegistryData();
	bool ReadMsg( CANMsg *pMsg );
	bool SendMsg( CANMsg *pMsg );
	unsigned long m_cntSentFrames;
	unsigned long m_cntReceivedFrames;
	void msgToStatusList( CANMsg *pmsg, bool bDirOut );
	void writeDataToDialog( CANMsg *pMsg );
	bool getDataValues( CANMsg *pMsg );
	unsigned char m_Status;
	bool m_ListenOnlyModeEnable;
	bool m_DevOpen;
	void DevSearch();
	void LoadDLL();
	unsigned long getDataValue( const char *szData );
	HMODULE m_hmodule;
	HICON m_hIcon;

	FT_HANDLE m_ftHandle;

	// Generierte Message-Map-Funktionen
	//{{AFX_MSG(CCan_controlDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClearBtn();
	afx_msg void OnOpenBtn();
	afx_msg void OnLOModeBtn();
	afx_msg void OnStatusBtn();
	afx_msg void OnVersionBtn();
	afx_msg void OnReadECRBtn();
	afx_msg void OnTimestampBtn();
	afx_msg void OnReadALCBtn();
	afx_msg void OnReadRegBtn();
	afx_msg void OnWriteRegBtn();
	afx_msg void OnErrspacemsgBox();
	afx_msg void OnSendMsgBtn();
	afx_msg void OnClearDataBtn();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnExitBtn();
	afx_msg void OnClearMsgListBtn();
	afx_msg void OnSaveListBtn();
	afx_msg void OnAddIDBtn();
	afx_msg void OnDeleteItemFilterID(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDelIDBtn();
	afx_msg void OnSendCyclic();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	CRichEditCtrl m_ctrl_Log;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ fügt unmittelbar vor der vorhergehenden Zeile zusätzliche Deklarationen ein.

#endif // !defined(AFX_CAN_CONTROLDLG_H__E9C7C553_9DE4_4D00_9176_8857FB529DE0__INCLUDED_)
