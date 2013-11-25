// can_controlDlg.cpp : Implementierungsdatei
//
#ifdef _DEBUG
   #define _CRTDBG_MAP_ALLOC // include Microsoft memory leak detection procedures
   #define _INC_MALLOC	     // exclude standard memory alloc procedures
#endif

#include "stdafx.h"
#include "can_control.h"
#include "can_controlDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg-Dialogfeld für Anwendungsbefehl "Info"

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialogfelddaten
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// Vom Klassenassistenten generierte Überladungen virtueller Funktionen
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterstützung
	//}}AFX_VIRTUAL

// Implementierung
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// Keine Nachrichten-Handler
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCan_controlDlg Dialogfeld

CCan_controlDlg::CCan_controlDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCan_controlDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCan_controlDlg)
	m_dataReadReg = _T("");
	m_dataWriteRegData = _T("");
	m_dataWriteReg = _T("");
	m_dataAMR = _T("");
	m_dataACR = _T("");
	m_MsgId = _T("");
	m_Data0 = _T("");
	m_Data1 = _T("");
	m_Data2 = _T("");
	m_Data3 = _T("");
	m_Data4 = _T("");
	m_Data5 = _T("");
	m_Data6 = _T("");
	m_Data7 = _T("");
	m_sentFrames = _T("");
	m_receivedFrames = _T("");
	m_dataSerialList = _T("");
	m_dataSelBitrate = _T("");
	m_dataIntervalTime = _T("");
	//}}AFX_DATA_INIT
	// Beachten Sie, dass LoadIcon unter Win32 keinen nachfolgenden DestroyIcon-Aufruf benötigt
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCan_controlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCan_controlDlg)
	DDX_Control(pDX, IDC_SENDCYCLIC, m_ctrl_CheckCyclic);
	DDX_Control(pDX, IDC_ASCII_HEX, m_ctrl_CheckASCII);
	DDX_Control(pDX, IDCANCEL, m_ctrlExitBtn);
	DDX_Control(pDX, IDC_KNOWNID, m_ctrlKnownID);
	DDX_Control(pDX, IDC_FILTERID, m_ctrlFilterID);
	DDX_Control(pDX, IDC_MSGLIST, m_MsgList);
	DDX_Control(pDX, IDC_RTRCheck, m_ctrlCheckRTR);
	DDX_Control(pDX, IDC_ExtCheck, m_ctrlExtended);
	DDX_Control(pDX, IDC_OpenBtn, m_ctrlOpenBtn);
	DDX_Control(pDX, IDC_SerialList, m_ctrlSerialList);
	DDX_Text(pDX, IDC_ReadRegEdit, m_dataReadReg);
	DDV_MaxChars(pDX, m_dataReadReg, 4);
	DDX_Text(pDX, IDC_WriteRegDataEdit, m_dataWriteRegData);
	DDV_MaxChars(pDX, m_dataWriteRegData, 4);
	DDX_Text(pDX, IDC_WriteRegEdit, m_dataWriteReg);
	DDV_MaxChars(pDX, m_dataWriteReg, 4);
	DDX_Text(pDX, IDC_AMREdit, m_dataAMR);
	DDV_MaxChars(pDX, m_dataAMR, 10);
	DDX_Text(pDX, IDC_ACREdit, m_dataACR);
	DDV_MaxChars(pDX, m_dataACR, 10);
	DDX_Text(pDX, IDC_IDEdit, m_MsgId);
	DDV_MaxChars(pDX, m_MsgId, 10);
	DDX_Text(pDX, IDC_Data1Edit, m_Data0);
	DDV_MaxChars(pDX, m_Data0, 4);
	DDX_Text(pDX, IDC_Data2Edit, m_Data1);
	DDV_MaxChars(pDX, m_Data1, 4);
	DDX_Text(pDX, IDC_Data3Edit, m_Data2);
	DDV_MaxChars(pDX, m_Data2, 4);
	DDX_Text(pDX, IDC_Data4Edit, m_Data3);
	DDV_MaxChars(pDX, m_Data3, 4);
	DDX_Text(pDX, IDC_Data5Edit, m_Data4);
	DDV_MaxChars(pDX, m_Data4, 4);
	DDX_Text(pDX, IDC_Data6Edit, m_Data5);
	DDV_MaxChars(pDX, m_Data5, 4);
	DDX_Text(pDX, IDC_Data7Edit, m_Data6);
	DDV_MaxChars(pDX, m_Data6, 4);
	DDX_Text(pDX, IDC_Data8Edit, m_Data7);
	DDV_MaxChars(pDX, m_Data7, 4);
	DDX_Text(pDX, IDC_SentCountStatic, m_sentFrames);
	DDX_Text(pDX, IDC_RecvCountStatic, m_receivedFrames);
	DDX_CBString(pDX, IDC_SerialList, m_dataSerialList);
	DDX_CBString(pDX, IDC_SelBitrateCombo, m_dataSelBitrate);
	DDX_Text(pDX, IDC_SENDCYCLICINTERVAL, m_dataIntervalTime);
	DDV_MaxChars(pDX, m_dataIntervalTime, 5);
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_RICHEDIT21, m_ctrl_Log);
}

BEGIN_MESSAGE_MAP(CCan_controlDlg, CDialog)
	//{{AFX_MSG_MAP(CCan_controlDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ClearBtn, OnClearBtn)
	ON_BN_CLICKED(IDC_OpenBtn, OnOpenBtn)
	ON_BN_CLICKED(IDC_LOModeBtn, OnLOModeBtn)
	ON_BN_CLICKED(IDC_StatusBtn, OnStatusBtn)
	ON_BN_CLICKED(IDC_VersionBtn, OnVersionBtn)
	ON_BN_CLICKED(IDC_ReadECRBtn, OnReadECRBtn)
	ON_BN_CLICKED(IDC_TimestampBtn, OnTimestampBtn)
	ON_BN_CLICKED(IDC_ReadALCBtn, OnReadALCBtn)
	ON_BN_CLICKED(IDC_ReadRegBtn, OnReadRegBtn)
	ON_BN_CLICKED(IDC_WriteRegBtn, OnWriteRegBtn)
	ON_EN_ERRSPACE(IDC_msgBox, OnErrspacemsgBox)
	ON_BN_CLICKED(IDC_SendMsgBtn, OnSendMsgBtn)
	ON_BN_CLICKED(IDC_ClearDataBtn, OnClearDataBtn)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDCANCEL, OnExitBtn)
	ON_BN_CLICKED(IDC_CLEARMSGLISTBTN, OnClearMsgListBtn)
	ON_BN_CLICKED(IDC_SAVELISTBTN, OnSaveListBtn)
	ON_BN_CLICKED(IDC_ADDIDBTN, OnAddIDBtn)
	ON_NOTIFY(LVN_DELETEITEM, IDC_FILTERID, OnDeleteItemFilterID)
	ON_BN_CLICKED(IDC_DELIDBTN, OnDelIDBtn)
	ON_BN_CLICKED(IDOK, OnExitBtn)
	ON_BN_CLICKED(IDC_SENDCYCLIC, OnSendCyclic)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCan_controlDlg Nachrichten-Handler

BOOL CCan_controlDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Hinzufügen des Menübefehls "Info..." zum Systemmenü.

	// IDM_ABOUTBOX muss sich im Bereich der Systembefehle befinden.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{	
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Symbol für dieses Dialogfeld festlegen. Wird automatisch erledigt
	//  wenn das Hauptfenster der Anwendung kein Dialogfeld ist
	SetIcon(m_hIcon, TRUE);			// Großes Symbol verwenden
	SetIcon(m_hIcon, FALSE);		// Kleines Symbol verwenden
	
	// ZU ERLEDIGEN: Hier zusätzliche Initialisierung einfügen

	char str[50];
	strcpy_s(str,50,"I/O");
	m_MsgList.InsertColumn(0,str,LVCFMT_LEFT,30,0);
	strcpy_s(str,50,"Flags");
	m_MsgList.InsertColumn(1,str,LVCFMT_LEFT,40,0);
	strcpy_s(str,50,"ID");
	m_MsgList.InsertColumn(2,str,LVCFMT_LEFT,80,0);
	strcpy_s(str,50,"Len");
	m_MsgList.InsertColumn(3,str,LVCFMT_LEFT,30,0);
	strcpy_s(str,50,"Data");
	m_MsgList.InsertColumn(4,str,LVCFMT_LEFT,140,0);
	strcpy_s(str,50,"Time Stamp");
	m_MsgList.InsertColumn(5,str,LVCFMT_LEFT,70,0);

	strcpy_s(str,50,"Known IDs");
	m_ctrlKnownID.InsertColumn(0,str,LVCFMT_LEFT,80,0);

	strcpy_s(str,50,"Filter IDs");
	m_ctrlFilterID.InsertColumn(0,str,LVCFMT_LEFT,80,0);

	// Lade driver DLL
	LoadDLL();

	// Suche angeschlossene Devices
	DevSearch();

	// Device Open Status = FT_Close
	m_DevOpen = FALSE;
	
	// Listen Only Mode disabled
	m_ListenOnlyModeEnable = FALSE;
	
	// Init message counter
	m_cntReceivedFrames = 0;
	m_cntSentFrames = 0;

	m_sentFrames = _T("0");
	m_receivedFrames = _T("0");

	// Init Frame cylce intervall
	m_dataIntervalTime = _T("1000");

	// Init Status flags
	m_Status = 0;

	loadRegistryData();

	return TRUE;  // Geben Sie TRUE zurück, außer ein Steuerelement soll den Fokus erhalten
}

void CCan_controlDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// Wollen Sie Ihrem Dialogfeld eine Schaltfläche "Minimieren" hinzufügen, benötigen Sie 
//  den nachstehenden Code, um das Symbol zu zeichnen. Für MFC-Anwendungen, die das 
//  Dokument/Ansicht-Modell verwenden, wird dies automatisch für Sie erledigt.

void CCan_controlDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // Gerätekontext für Zeichnen

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Symbol in Client-Rechteck zentrieren
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Symbol zeichnen
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// Die Systemaufrufe fragen den Cursorform ab, die angezeigt werden soll, während der Benutzer
//  das zum Symbol verkleinerte Fenster mit der Maus zieht.
HCURSOR CCan_controlDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}



/*************************************************************************/
//
// Treiber DLL laden und alle Funktionen überprüfen
//
void CCan_controlDlg::LoadDLL()
{
	m_hmodule = LoadLibrary("Ftd2xx.dll");	
	if(m_hmodule == NULL)
	{
		AfxMessageBox("Error: Can't Load Driver ftd2xx.dll");
		return;
	}

	FT_HANDLE ftHandle;
	FT_STATUS status;
	DWORD dwDriverVer;
	CString str;
	//
	// Get driver version
	//
	status = FT_Open(0,&ftHandle);
	if (status == FT_OK)
	{
		status = FT_GetDriverVersion(ftHandle,&dwDriverVer);
		if (status == FT_OK)
			str.Format("Driver version = %x.%x.%x\n",(dwDriverVer&0x00FF0000)>>16, (dwDriverVer&0x0000FF00)>>8, dwDriverVer&0x000000FF);
		else
			str.Format("Error reading driver version\n");
		AppendToLog(str);
		FT_Close(ftHandle);
	}
}


/*************************************************************************/
//
// Suche angeschlossene Devices
//
void CCan_controlDlg::DevSearch()
{
	//search for Descriptions or Serial Numbers depending on the current mode
	FT_STATUS ftStatus;
	DWORD numDevs;
	FT_DEVICE_LIST_INFO_NODE *devInfo;

	UpdateData(TRUE);

	// Get number of device connected
	ftStatus = FT_CreateDeviceInfoList(&numDevs);
	if( (ftStatus == FT_OK) && (numDevs > 0)) 
	{
		// Allocate storage
		devInfo = (FT_DEVICE_LIST_INFO_NODE*)malloc(sizeof(FT_DEVICE_LIST_INFO_NODE)*numDevs);

		// Get device list
		ftStatus = FT_GetDeviceInfoList(devInfo,&numDevs);

		// FT_ListDevices OK, show number of devices connected in list box
		CString str;
		str.Format("Device(s) found: %d\r\n", numDevs);
		AppendToLog(str);

		// read serial for each device
		for(int u=0; u < numDevs; ++u)
		{
			m_ctrlSerialList.AddString(devInfo[u].Description);
		}
	
		free(devInfo);
		str.FreeExtra();
		UpdateData(FALSE);
	}
	else 
	{
		// FT_ListDevices failed
		AfxMessageBox("No FTDI devices found!"); 
	}	
}


/*************************************************************************/
//
// Message Box leeren
//
void CCan_controlDlg::OnClearBtn() 
{
	UpdateData(true);
	m_ctrl_Log.SetReadOnly(FALSE);
	m_ctrl_Log.SetSel(0,-1);
	m_ctrl_Log.Clear();
	m_ctrl_Log.SetReadOnly(TRUE);
	UpdateData(false);
}


/*************************************************************************/
//
// Click auf Open Button
//
void CCan_controlDlg::OnOpenBtn() 
{
	FT_STATUS status;
	char buffer[25];
	DWORD ret_bytes;
	DWORD rx_bytes;
	CString str;

	UpdateData(true);
	if(!m_DevOpen){

		if ( m_dataSerialList.IsEmpty() ) {
			// No Serial Selected
			AfxMessageBox("Error: No device selected.\n\rEnter or Select Device Serial." );
			return;
		}

		if ( m_dataSelBitrate.IsEmpty() ) {
			// No Bitrate selected
			AfxMessageBox("Error: No Baudrate selected.\n\rEnter or Select Baudrate." );
			return;
		}

		// Open device
		status = FT_OpenEx((PVOID)(LPCTSTR)m_dataSerialList, FT_OPEN_BY_DESCRIPTION, &m_ftHandle);

		if(status != FT_OK){
			// Fehler beim Device öffnen
			AfxMessageBox("Error: Opening selected device.");
			return;
		}

		SetTimer( IDD_TIMER_TIMEOUT, 500, NULL );

		FT_ResetDevice(m_ftHandle);
		FT_SetTimeouts(m_ftHandle, 1000, 1000);

		buffer[0] = 0x0d;
		FT_Write(m_ftHandle, buffer, 1, &ret_bytes);

		m_timeOut = false;
		do{
			FT_GetQueueStatus(m_ftHandle, &rx_bytes);

			if( m_timeOut ){
				AfxMessageBox("Connection timeout. (1)" );
				FT_Close(m_ftHandle);
				return;
			}

		}while(rx_bytes == NULL);

		buffer[0] = 'C';
		buffer[1] = CAN_CR;
		FT_Write(m_ftHandle, buffer, 2, &ret_bytes);

		m_timeOut = false;
		do{
			FT_GetQueueStatus(m_ftHandle, &rx_bytes);

			if( m_timeOut ){
				AfxMessageBox("Connection timeout. (2)" );
				FT_Close(m_ftHandle);
				return;
			}

		}while(rx_bytes == NULL);

		FT_Purge(m_ftHandle, FT_PURGE_RX || FT_PURGE_TX);

		if ( NULL == strchr( m_dataSelBitrate, ':') ){

			buffer[0] = 'S';
		
			switch(atoi(m_dataSelBitrate)){
				case 10:
					buffer[1] = '0';
					break;
				case 20:
					buffer[1] = '1';
					break;
				case 50:
					buffer[1] = '2';
					break;
				case 100:
					buffer[1] = '3';
					break;
				case 125:
					buffer[1] = '4';
					break;
				case 250:
					buffer[1] = '5';
					break;
				case 500:
					buffer[1] = '6';
					break;
				case 800:
					buffer[1] = '7';
					break;
				case 1000:
					buffer[1] = '8';
					break;
				case 95:
					buffer[1] = '9';
					break;
				case 83:
					buffer[1] = 'a';
					break;
				case 47:
					buffer[1] = 'b';
					break;
				case 33:
					buffer[1] = 'c';
					break;
				case 5:
					buffer[1] = 'd';
					break;
				default:
					// Baudrate unknown
					AfxMessageBox("Error: Unkown fixed Baudrate." );
					FT_Close(m_ftHandle);
					return;
			}
			buffer[2] = CAN_CR;
		
			FT_Write(m_ftHandle, buffer, 3, &ret_bytes);
		
		}else{

			UpdateData(false);
			char *token;
			char *next_token;
			const char *pntr;
			pntr = m_dataSelBitrate;
			unsigned char val_btr0, val_btr1;

			token = strtok_s((char*)pntr,":", &next_token);

			val_btr0 = (unsigned char)getDataValue(token);

			token = strtok_s(NULL,":", &next_token);

			val_btr1 = (unsigned char)getDataValue(token);

			sprintf_s(buffer, 25,"s%02X%02X\r",val_btr0, val_btr1);

			FT_Write(m_ftHandle, buffer, 6, &ret_bytes);
			UpdateData(true);
		}

		m_timeOut = false;
		do{
			FT_GetQueueStatus(m_ftHandle, &rx_bytes);

			if( m_timeOut ){
				AfxMessageBox("Connection timeout. (3)" );
				FT_Close(m_ftHandle);
				return;
			}

		}while(rx_bytes == NULL);

		FT_Read(m_ftHandle, buffer,rx_bytes,&ret_bytes);

		if( buffer[0] != CAN_OK ){
			// Baudrate setting failed
			AfxMessageBox("Error: Setting Baudrate failed." );
			FT_Close(m_ftHandle);
			return;
		}

		// set ACR if necessary
		if(!m_dataACR.IsEmpty()){

			long val_acr = getDataValue(m_dataACR);

			sprintf_s(buffer, 25,"M%08X\r", val_acr);

			m_dataACR.Format("0x%08lX",val_acr);

			FT_Write(m_ftHandle, buffer, 10, &ret_bytes);

			m_timeOut = false;
			do{
				FT_GetQueueStatus(m_ftHandle, &rx_bytes);

				if( m_timeOut ){
					AfxMessageBox("Connection timeout. (4)" );
					FT_Close(m_ftHandle);
					return;
				}

			}while(rx_bytes == NULL);

			FT_Read(m_ftHandle, buffer,rx_bytes,&ret_bytes);
		}

		// set AMR if necessary
		if(!m_dataAMR.IsEmpty()){

			long val_amr = getDataValue(m_dataAMR);

			sprintf_s(buffer, 25,"m%08X\r",val_amr);

			m_dataAMR.Format("0x%08lX",val_amr);

			FT_Write(m_ftHandle, buffer, 10, &ret_bytes);

			m_timeOut = false;
			do{
				FT_GetQueueStatus(m_ftHandle, &rx_bytes);

				if( m_timeOut ){
					AfxMessageBox("Connection timeout. (5)" );
					return;
				}

			}while(rx_bytes == NULL);

			FT_Read(m_ftHandle, buffer,rx_bytes,&ret_bytes);
		}



		if(m_ListenOnlyModeEnable){
			buffer[0] = 'L';  // Enter Listen Only mode
		}else{
			buffer[0] = 'O';  // Open CAN channel
		}

		buffer[1] = CAN_CR;
		FT_Write(m_ftHandle, buffer,2,&ret_bytes);

		m_timeOut = false;
		do{
			FT_GetQueueStatus(m_ftHandle, &rx_bytes);

			if( m_timeOut ){
				AfxMessageBox("Connection timeout. (6)" );
				FT_Close(m_ftHandle);
				return;
			}

		}while(rx_bytes == NULL);

		FT_Read(m_ftHandle, buffer,rx_bytes,&ret_bytes);

		if( buffer[0] != CAN_OK ){
			// Open CAN channel failed
			AfxMessageBox("Error: Failed to open CAN channel." );
			FT_Close(m_ftHandle);
			return;
		}
		else{
			if(m_ListenOnlyModeEnable)
				AppendToLog("Listen Only enabled\r\n");
			else
				AppendToLog("CAN channel open\r\n");
		}

		
		if( !SetTimer( IDD_TIMER_READ, 100, NULL ) ){
			// Setup timer failed
			AfxMessageBox("Error: Failed to setup receive timer." );
			FT_Close(m_ftHandle);
			return;
		}
		m_DevOpen = TRUE;
		m_ctrlOpenBtn.SetWindowText("Close");
		GetDlgItem(IDC_LOModeBtn)->EnableWindow(false);
//		KillTimer(IDD_TIMER_TIMEOUT);

	}
	else{
	/*
		CLOSE CAN CHANNEL AND DEVICE
	*/
		KillTimer(IDD_TIMER_READ);

		buffer[0] = 'C';
		buffer[1] = CAN_CR;
		FT_Write(m_ftHandle, buffer, 2, &ret_bytes);

		AppendToLog("CAN channel closed\r\n");

		Sleep(50);
		FT_Purge(m_ftHandle, FT_PURGE_RX || FT_PURGE_TX);

		// FT_Close device
		FT_Close(m_ftHandle);

		m_ListenOnlyModeEnable = FALSE;
		m_DevOpen = FALSE;

		m_ctrlOpenBtn.SetWindowText("Open");
		GetDlgItem(IDC_LOModeBtn)->EnableWindow(true);

	}
	// clear cyclic frame timer in any case on open or close
	m_ctrl_CheckCyclic.SetCheck(0);
	KillTimer( IDD_TIMER_CYCLICFRAME);

	UpdateData(false);
}


/*************************************************************************/
//
// Click auf Listen Only Mode Button
//
void CCan_controlDlg::OnLOModeBtn() 
{
	if( m_DevOpen ){
		// CAN channel allready open
		AfxMessageBox("Error: CAN channel open." );
		return;
	}

	if( !m_ListenOnlyModeEnable ){
		m_ListenOnlyModeEnable = TRUE;
		OnOpenBtn();
	}

}


/*************************************************************************/
//
// Get data value
//
unsigned long CCan_controlDlg::getDataValue( const char *szData )
{
	unsigned long val;
	char *nstop;

	if ( ( NULL != strchr( szData, 'x' ) ) ||
			( NULL != strchr( szData, 'X' ) ) ) {
		val = strtoul( szData, &nstop, 16 );
	}
	else {
		val = strtoul( szData, &nstop, 10 );
	}

	return val;	
}


/*************************************************************************/
//
// Click on Status Button
//
void CCan_controlDlg::OnStatusBtn() 
{
	if( !m_DevOpen ){
//		AfxMessageBox("Error: Device not open." );
		return;
	}

	unsigned char buffer[25];
	DWORD ret_bytes;

	buffer[0] = 'F';
	buffer[1] = CAN_CR;
	FT_Write(m_ftHandle, buffer, 2, &ret_bytes);
}


/*************************************************************************/
//
// Click on Version Button
//
void CCan_controlDlg::OnVersionBtn() 
{
	if( !m_DevOpen ){
//		AfxMessageBox("Error: Device not open." );
		return;
	}
	
	unsigned char buffer[25];
	DWORD ret_bytes;

	buffer[0] = 'V';
	buffer[1] = CAN_CR;
	FT_Write(m_ftHandle, buffer, 2, &ret_bytes);

	Sleep(10);

	buffer[0] = 'N';
	buffer[1] = CAN_CR;
	FT_Write(m_ftHandle, buffer, 2, &ret_bytes);
}


/*************************************************************************/
//
// Click on ECR Button
//
void CCan_controlDlg::OnReadECRBtn() 
{
	if( !m_DevOpen ){
//		AfxMessageBox("Error: Device not open." );
		return;
	}

	unsigned char buffer[25];
	DWORD ret_bytes;

	buffer[0] = 'E';
	buffer[1] = CAN_CR;
	FT_Write(m_ftHandle, buffer, 2, &ret_bytes);
}


/*************************************************************************/
//
// Click on Time Stamp Button
//
void CCan_controlDlg::OnTimestampBtn() 
{
	if( !m_DevOpen ){
//		AfxMessageBox("Error: Device not open." );
		return;
	}

	FT_Purge(m_ftHandle, FT_PURGE_RX || FT_PURGE_TX);
	unsigned char buffer[10];
	DWORD ret_bytes;

	buffer[0] = 'Z';
	buffer[1] = CAN_CR;
	FT_Write(m_ftHandle, buffer, 2, &ret_bytes);
}


/*************************************************************************/
//
// Click on ALC Button
//
void CCan_controlDlg::OnReadALCBtn() 
{
	if( !m_DevOpen ){
//		AfxMessageBox("Error: Device not open." );
		return;
	}

	unsigned char buffer[25];
	DWORD ret_bytes;

	buffer[0] = 'A';
	buffer[1] = CAN_CR;
	FT_Write(m_ftHandle, buffer, 2, &ret_bytes);
}


/*************************************************************************/
//
// Click on FT_Read Register Button
//
void CCan_controlDlg::OnReadRegBtn() 
{
	if( !m_DevOpen ){
//		AfxMessageBox("Error: Device not open." );
		return;
	}

	UpdateData(true);

	if( m_dataReadReg.IsEmpty()){
		AfxMessageBox("Error: Enter register number." );
		return;
	}

	char buffer[25];
	DWORD ret_bytes;
	CString str;
	
	unsigned char reg = (unsigned char)getDataValue(m_dataReadReg);
	reg &= 0x7F;

	UpdateData(true);
	str.Format("Register 0x%02X = ",reg);
	AppendToLog(str);
	UpdateData(false);

	sprintf_s(buffer, 25,"G%02X\r",reg);

	FT_Write(m_ftHandle, buffer, 4, &ret_bytes);
}


/*************************************************************************/
//
// Click on FT_Write Register Button
//
void CCan_controlDlg::OnWriteRegBtn() 
{
	if( !m_DevOpen ){
//		AfxMessageBox("Error: Device not open." );
		return;
	}

	UpdateData(true);

	if( m_dataWriteReg.IsEmpty()){
		AfxMessageBox("Error: Enter register number." );
		return;
	}

	if( m_dataWriteRegData.IsEmpty() ){
		AfxMessageBox("Error: Enter data to write." );
		return;
	}
	
	char buffer[25];
	DWORD ret_bytes;

	unsigned char reg_num = (unsigned char)getDataValue(m_dataWriteReg);
	reg_num &= 0x7F;
	
	unsigned char reg_data = (unsigned char)getDataValue(m_dataWriteRegData);
	reg_data &= 0xFF;

	sprintf_s(buffer, 25,"W%02X%02X\r",reg_num,reg_data);

	FT_Write(m_ftHandle, buffer, 6, &ret_bytes);

	UpdateData(false);
}


/*************************************************************************/
//
// On memory overflow of MsgBox
//
void CCan_controlDlg::OnErrspacemsgBox() 
{

}



/*************************************************************************/
//
// Get all data
//
bool CCan_controlDlg::getDataValues( CANMsg *pMsg )
{
	unsigned char nData = 0;

	// Initialize message structure
	pMsg->flags = 0;
	pMsg->id = 0;
	pMsg->len = 0;
	pMsg->timestamp = 0;

	for ( int i=0; i<8; i++ ) {
		pMsg->data[ i ] = 0;
	}

	// Must have somewhere to store data
	if ( NULL == pMsg ) return false;

	UpdateData( true );

	pMsg->id = getDataValue( m_MsgId );

	// Is the ID valid?
//	if ( pMsg->id  > 0x1FFFFFFF ) return false;

	pMsg->id &= 0x1FFFFFFF;  // make valid extened frame
	
	pMsg->data[ 7 ] = (unsigned char)getDataValue( m_Data7 );
	if ( m_Data7.GetLength() > 0 ) nData = 8;

	pMsg->data[ 6 ] = (unsigned char)getDataValue( m_Data6 );
	if ( ( 0 == nData ) && ( m_Data6.GetLength() > 0  ) ) nData = 7;
	
	pMsg->data[ 5 ] = (unsigned char)getDataValue( m_Data5 );
	if ( ( 0 == nData ) && ( m_Data5.GetLength() > 0  ) ) nData = 6;
	
	pMsg->data[ 4 ] = (unsigned char)getDataValue( m_Data4 );
	if ( ( 0 == nData ) && ( m_Data4.GetLength() > 0  ) ) nData = 5;
	
	pMsg->data[ 3 ] = (unsigned char)getDataValue( m_Data3 );
	if ( ( 0 == nData ) && ( m_Data3.GetLength() > 0  ) ) nData = 4;
	
	pMsg->data[ 2 ] = (unsigned char)getDataValue( m_Data2 );
	if ( ( 0 == nData ) && ( m_Data2.GetLength() > 0  ) ) nData = 3;
	
	pMsg->data[ 1 ] = (unsigned char)getDataValue( m_Data1 );
	if ( ( 0 == nData ) && ( m_Data1.GetLength() > 0  ) ) nData = 2;
	
	pMsg->data[ 0 ] = (unsigned char)getDataValue( m_Data0 );
	if ( ( 0 == nData ) && ( m_Data0.GetLength() > 0  ) ) nData = 1;
	
	pMsg->len = nData;

	// Extended message
	pMsg->flags = 0;

	if ( m_ctrlExtended.GetCheck() || (pMsg->id > 0x7FF) ) {
		pMsg->flags |= CANMSG_EXTENDED; 
	}

	// Remote Frame
	if ( m_ctrlCheckRTR.GetCheck() ) {
		pMsg->flags |= CANMSG_RTR; 	
	}
	
	// FT_Write back data to dialog
	writeDataToDialog( pMsg );

	return true;
}	


/*************************************************************************/
//
// FT_Write data to dialog
//
void CCan_controlDlg::writeDataToDialog(CANMsg *pMsg)
{
	
	_ultoa_s( pMsg->id, m_MsgId.GetBufferSetLength( 32 ), 32, 16 );	
	m_MsgId = "0x" + m_MsgId; 
	
	// Extended flag
	if ( pMsg->flags & CANMSG_EXTENDED ) {
		m_ctrlExtended.SetCheck( 1 ); 
	}
	else {
		m_ctrlExtended.SetCheck( 0 );
	}

	if ( pMsg->id  > 0x7ff ) {
		m_ctrlExtended.SetCheck( 1 ); 
	}

	// RTR flag
	if ( pMsg->flags & CANMSG_RTR ) {
		m_ctrlCheckRTR.SetCheck( 1 ); 
	}
	else {
		m_ctrlCheckRTR.SetCheck( 0 );
	}

	// Clear all data fields
	m_Data0 = "";
	m_Data1 = "";
	m_Data2 = "";
	m_Data3 = "";
	m_Data4 = "";
	m_Data5 = "";
	m_Data6 = "";
	m_Data7 = "";


	if ( pMsg->len > 0 ) {
		m_Data0.Format("0x%02hX",pMsg->data[0]);
	}

	if ( pMsg->len > 1 ) {
		m_Data1.Format("0x%02hX",pMsg->data[1]);
	}

	if ( pMsg->len > 2 ) {
		m_Data2.Format("0x%02hX",pMsg->data[2]);
	}

	if ( pMsg->len > 3 ) {
		m_Data3.Format("0x%02hX",pMsg->data[3]);
	}

	if ( pMsg->len > 4 ) {
		m_Data4.Format("0x%02hX",pMsg->data[4]);
	}

	if ( pMsg->len > 5 ) {
		m_Data5.Format("0x%02hX",pMsg->data[5]);
	}

	if ( pMsg->len > 6 ) {
		m_Data6.Format("0x%02hX",pMsg->data[6]);
	}

	if ( pMsg->len > 7 ) {
		m_Data7.Format("0x%02hX",pMsg->data[7]);
	}

	UpdateData( false );	
}


/*************************************************************************/
//
// FT_Write message to MsgList
//
void CCan_controlDlg::msgToStatusList(CANMsg *pmsg, bool bDirOut)
{
	// Add ID to known list
	AddIDtoKnown(pmsg);

	int FilterItemCnt = m_ctrlFilterID.GetItemCount();

	// show all messages if ID filter list is empty
	if( FilterItemCnt != 0){

		char Buffer[20];

		LVFINDINFO info;
		info.flags = LVFI_STRING;
		
		sprintf_s(Buffer, 20,"%08X",pmsg->id);
		info.psz = Buffer;

		// add ID if not exist in known list
		if(m_ctrlFilterID.FindItem(&info) == -1){
			return;
		}
	}

	int itemcnt;
	char Buffer[ 50 ],wrkbuffer[10];
	char cExtended;
	char cRTR;

	itemcnt=m_MsgList.GetItemCount();

	if(pmsg->len > 8){ pmsg->len = 8;}

	cExtended = 'S';
	if ( pmsg->flags & CANMSG_EXTENDED ) {
		cExtended = 'E';
	}

	cRTR = ' ';
	if ( pmsg->flags & CANMSG_RTR ) {
		cRTR = 'R';
	}

	if ( bDirOut ) { m_MsgList.InsertItem(itemcnt,"In");}
	else {m_MsgList.InsertItem(itemcnt,"Out");}

	sprintf_s(Buffer, 50,"%c%c",cExtended,cRTR);
	m_MsgList.SetItemText(itemcnt,1,Buffer);

	sprintf_s(Buffer, 50,"%08X",pmsg->id);
	m_MsgList.SetItemText(itemcnt,2,Buffer);

	sprintf_s(Buffer, 50,"%d",pmsg->len);
	m_MsgList.SetItemText(itemcnt,3,Buffer);
	
	sprintf_s(Buffer, 50,"");
	if ( !(pmsg->flags & CANMSG_RTR) ) {
		for (int i=0; i<pmsg->len; i++ ) {
			if( m_ctrl_CheckASCII.GetCheck() ){
				sprintf_s( wrkbuffer, 10, "%c", pmsg->data[ i ] );
			} else {
				sprintf_s( wrkbuffer, 10, "%02X ", pmsg->data[ i ] );
			}
			strcat_s( Buffer, 50, wrkbuffer );
		}
	}
	m_MsgList.SetItemText(itemcnt,4,Buffer);

	sprintf_s(Buffer, 50,"%04X",pmsg->timestamp);
	m_MsgList.SetItemText(itemcnt,5,Buffer);

	m_MsgList.EnsureVisible(itemcnt,false);

	UpdateData( true );
	_ltoa_s( m_cntReceivedFrames, m_receivedFrames.GetBuffer(80), 80, 10 );
	UpdateData( false );
}


/*************************************************************************/
//
// Send message
//
void CCan_controlDlg::OnSendMsgBtn() 
{
	CANMsg msg;
  
	if( !m_DevOpen ){
//		AfxMessageBox("Error: Device not open." );
		return;
	}

	UpdateData( true );
	getDataValues( &msg );
	if ( !SendMsg(&msg) ) {
		AfxMessageBox("Failed to send message");
	}
	else {
		m_cntSentFrames++;
		_ltoa_s( m_cntSentFrames, m_sentFrames.GetBuffer(80), 80, 10 );
		UpdateData( false );
		msgToStatusList( &msg, false );
	}

	UpdateData( false );

}


/*************************************************************************/
//
// Clear message data fields
//
void CCan_controlDlg::OnClearDataBtn() 
{
	m_Data0.Empty();
	m_Data1.Empty();
	m_Data2.Empty();
	m_Data3.Empty();
	m_Data4.Empty();
	m_Data5.Empty();
	m_Data6.Empty();
	m_Data7.Empty();

	UpdateData( false );	

}


/*************************************************************************/
//
// Send CAN message
//
bool CCan_controlDlg::SendMsg(CANMsg *pMsg)
{
	FT_Purge(m_ftHandle,FT_PURGE_TX);
	char buffer[50];
	char wrkbuf[50];
	DWORD ret_bytes;
	DWORD rx_bytes;

	if ( pMsg->flags & CANMSG_EXTENDED ) {
		if ( pMsg->flags & CANMSG_RTR ) {
			sprintf_s(buffer, 50, "R%08.8X%d", pMsg->id, pMsg->len);
		}else{
			sprintf_s(buffer, 50, "T%08.8X%d", pMsg->id, pMsg->len);
		}
	}else{
		if ( pMsg->flags & CANMSG_RTR ) {
			sprintf_s(buffer, 50, "r%03.3X%d", pMsg->id, pMsg->len);
		} else {
			sprintf_s(buffer, 50, "t%03.3X%d", pMsg->id, pMsg->len);
		}
	}
	
	// send data only if it's no RTR frame
	if ( !(pMsg->flags & CANMSG_RTR) ) {
		for (unsigned char i=0; i<pMsg->len; i++ ) {
			sprintf_s( wrkbuf, 50, "%02.2X", pMsg->data[ i ] );
			strcat_s( buffer, 50, wrkbuf );
		}
	}

	strcat_s( buffer, 50, "\r" );

	TRACE("Send message: %.30s\n",buffer);

	if ( pMsg->flags & CANMSG_EXTENDED ) {
		if ( !(pMsg->flags & CANMSG_RTR) ) {
			FT_Write(m_ftHandle, buffer, 10+(pMsg->len*2)+1, &ret_bytes);
		}else{
			FT_Write(m_ftHandle, buffer, 10+1, &ret_bytes);
		}
	}else{
		if ( !(pMsg->flags & CANMSG_RTR) ) {
			FT_Write(m_ftHandle, buffer, 5+(pMsg->len*2)+1, &ret_bytes);
		}else{
			FT_Write(m_ftHandle, buffer, 5+1, &ret_bytes);
		}
	}

	m_timeOut = false;
	do{
		FT_GetQueueStatus(m_ftHandle, &rx_bytes);

		if( m_timeOut ){
			return false;
		}

	}while(rx_bytes == NULL);

	FT_Read(m_ftHandle, buffer,rx_bytes,&ret_bytes);

	if(buffer[0] != CAN_OK){return false;}

	return true;
}


/*************************************************************************/
//
// OnTimer read all received messages
//
void CCan_controlDlg::OnTimer(UINT nIDEvent) 
{
	CANMsg msg;

	if( nIDEvent == IDD_TIMER_READ ){
		ReadMsg(&msg);
	}

	if( nIDEvent == IDD_TIMER_CYCLICFRAME ){
		OnSendMsgBtn();
	}

	if( nIDEvent == IDD_TIMER_TIMEOUT ){
		m_timeOut = true;
	}


//	CDialog::OnTimer(nIDEvent);
}


/*************************************************************************/
//
// On Exit
//
void CCan_controlDlg::OnExitBtn() 
{
	saveRegistryData();

	// Empty all CStrings
	m_dataSerialList.Empty();
	m_dataSelBitrate.Empty();
	m_sentFrames.Empty();
	m_receivedFrames.Empty();
	m_dataReadReg.Empty();
	m_dataWriteRegData.Empty();
	m_dataWriteReg.Empty();
	m_dataAMR.Empty();
	m_dataACR.Empty();
	m_MsgId.Empty();
	m_Data0.Empty();
	m_Data1.Empty();
	m_Data2.Empty();
	m_Data3.Empty();
	m_Data4.Empty();
	m_Data5.Empty();
	m_Data6.Empty();
	m_Data7.Empty();
	m_dataIntervalTime.Empty();

	// Free any memory used by CStrings to prevent memory leaks
	m_dataSerialList.FreeExtra();
	m_dataSelBitrate.FreeExtra();
	m_sentFrames.FreeExtra();
	m_receivedFrames.FreeExtra();
	m_dataReadReg.FreeExtra();
	m_dataWriteRegData.FreeExtra();
	m_dataWriteReg.FreeExtra();
	m_dataAMR.FreeExtra();
	m_dataACR.FreeExtra();
	m_MsgId.FreeExtra();
	m_Data0.FreeExtra();
	m_Data1.FreeExtra();
	m_Data2.FreeExtra();
	m_Data3.FreeExtra();
	m_Data4.FreeExtra();
	m_Data5.FreeExtra();
	m_Data6.FreeExtra();
	m_Data7.FreeExtra();
	m_dataIntervalTime.FreeExtra();

	KillTimer( IDD_TIMER_CYCLICFRAME);
	KillTimer( IDD_TIMER_TIMEOUT);
	KillTimer( IDD_TIMER_READ);

	CDialog::OnCancel();

}


/*************************************************************************/
//
// FT_Read CAN message
//
bool CCan_controlDlg::ReadMsg( CANMsg *pMsg )
{
	char wrkbuffer[10];
	char *token;
	char *next_token;
	char *buffer;
	DWORD ret_bytes;
	DWORD rx_bytes;
	CString str;
	unsigned char error_val;

	if(FT_GetQueueStatus(m_ftHandle, &rx_bytes) != FT_OK){
		return false;
	}
	
	if(rx_bytes == NULL){ return false; }

	buffer = (char*) malloc(rx_bytes);

	if(buffer == NULL){
		AfxMessageBox("Error: Insufficient memory to\r\nallocate receive buffer." );
		free(buffer);
		return false;
	}


	if(FT_Read(m_ftHandle, buffer,rx_bytes,&ret_bytes) != FT_OK){
		free(buffer);
		return false;
	}

	token = strtok_s(buffer,"\r", &next_token);

	while(token != NULL){
		
		pMsg->flags = 0;

		if ( (*(token)== 't') || (*(token)== 'r') ){
			TRACE("Receive: 11 Bit");
			if(*(token)== 'r'){ pMsg->flags |= CANMSG_RTR; }
			TRACE(" Flags: %01X",pMsg->flags);
			strncpy_s(wrkbuffer, 10, token+1,3);

			wrkbuffer[3] = 0;

			pMsg->id = strtoul(wrkbuffer,0,16);
			TRACE(" ID: %03X",pMsg->id);

			strncpy_s(wrkbuffer, 10, token+4,1);
			wrkbuffer[1] = 0;

			pMsg->len = (unsigned char)strtoul(wrkbuffer,0,16);
			TRACE(" Len: %d Data: ",pMsg->len);

			char u = 0;
			if ( !(pMsg->flags & CANMSG_RTR) ) {
				for(char i=0; i<pMsg->len;++i){
					strncpy_s(wrkbuffer, 10,token+5+u,2);
					wrkbuffer[2]=0;
					pMsg->data[i] = (unsigned char)strtoul(wrkbuffer,0,16);
					TRACE(" %02X",pMsg->data[i]);
					u += 2;
				}
			}
			
			unsigned char data_len = pMsg->len*2;
			if( *(token+5+data_len) != CAN_CR ){
				if ( pMsg->flags & CANMSG_RTR ) {data_len = 0;}
				strncpy_s(wrkbuffer, 10,token+5+data_len,4);

				wrkbuffer[4] = 0;

				pMsg->timestamp = strtoul(wrkbuffer,0,16);
			}else{
				pMsg->timestamp = 0;
			}
			TRACE(" Timestamp: %04X\n",pMsg->timestamp);
			++m_cntReceivedFrames;  // count message
			msgToStatusList( pMsg, true );  // print message to list
	
		}  // end if pStdFrame

		// process extented frame
		else if ( (*(token)== 'T') || (*(token)== 'R') ){
			TRACE("Receive: 29 Bit");
			if(*(token)== 'R'){ pMsg->flags |= CANMSG_RTR; }
			pMsg->flags |= CANMSG_EXTENDED;
			TRACE(" Flags: %01X",pMsg->flags);
			strncpy_s(wrkbuffer, 10,token+1,8);

			wrkbuffer[8] = 0;

			pMsg->id = strtoul(wrkbuffer,0,16);
			TRACE(" ID: %08X",pMsg->id);
			strncpy_s(wrkbuffer, 10, token+9,1);
			wrkbuffer[1] = 0;

			pMsg->len = (unsigned char)strtoul(wrkbuffer,0,16);
			TRACE(" Len: %d Data: ",pMsg->len);

			char u = 0;
			if ( !(pMsg->flags & CANMSG_RTR) ) {
				for(char i=0; i<pMsg->len;++i){
					strncpy_s(wrkbuffer, 10, token+10+u,2);
					wrkbuffer[2]=0;
					pMsg->data[i] = (unsigned char)strtoul(wrkbuffer,0,16);
					TRACE(" %02X",pMsg->data[i]);
					u += 2;
				}
			}

			unsigned char data_len = pMsg->len*2;
			if( *(token+10+data_len) != CAN_CR ){
				if ( pMsg->flags & CANMSG_RTR ) {data_len = 0;}
				strncpy_s(wrkbuffer, 10, token+10+data_len,4);

				wrkbuffer[4] = 0;

				pMsg->timestamp = strtoul(wrkbuffer,0,16);
			}else{
				pMsg->timestamp = 0;
			}
			TRACE(" Timestamp: %04X\n",pMsg->timestamp);
			++m_cntReceivedFrames;  // count message
			msgToStatusList( pMsg, true );  // print message to list

		}  // end if ExtFrame

		else if( *(token)== 'F' ){
			UpdateData(true);
			str.Format("0x%c%c",*(token+1),*(token+2));
			error_val = (unsigned char)getDataValue(str);

			m_Status = error_val;

			str.Empty();
			str += "Status: ";
			if(error_val == NULL){ str += "No Error detected\r\n";}
			if(error_val & 0x80){str += "Bus Error detected\r\n";}
			if(error_val & 0x40){str += "Arbitration Lost Error detected\r\n";}
			if(error_val & 0x20){str += "Error Passive Mode detected\r\n";}
			if(error_val & 0x08){str += "Data Overrun detected\r\n";}
			if(error_val & 0x04){str += "Error Warning detected\r\n";}

			AppendToLog(str);
			UpdateData(false);
		}

		else if(*(token)== 'V'){
			UpdateData(true);
			str.Format("Version HW: %c.%c SW: %c.%c\r\n",
					   *(token+1),*(token+2),*(token+3),*(token+4));
			AppendToLog(str);
			UpdateData(false);
		}

		else if(*(token)== 'N'){
			UpdateData(true);
			str.Format("Serial: %c%c%c%c\r\n",
					   *(token+1),*(token+2),*(token+3),*(token+4));
			AppendToLog(str);
			UpdateData(false);
		}

		else if(*(token)== 'E'){
			UpdateData(true);
			str.Format("0x%c%c",*(token+1),*(token+2));
		
			error_val = (unsigned char)getDataValue(str);

			str.Empty();

			str += "ECR: ";

			if(error_val == NULL){ str += "No Error detected\r\n";}
			else{
				
				if(error_val & 0x20){str += "RX Error detected";}
				else{ str += "TX Error detected";}

				str += "\r\nType: ";

				if(error_val & 0xC0){ str += "Other";}
				else if(error_val & 0x80){ str += "Stuff Error";}
				else if(error_val & 0x40){ str += "Form Error";}
				else { str += "Bit Error";}

				str += "\r\nSegment: ";

				error_val &= 0x1F;

				switch(error_val){

				case 0x03:
					str += "SOF";
					break;
				
				case 0x02:
					str += "ID.28 to ID.21";
					break;

				case 0x06:
					str += "ID.20 to ID.18";
					break;

				case 0x04:
					str += "SRTR Bit";
					break;

				case 0x05:
					str += "IDE Bit";
					break;

				case 0x07:
					str += "ID.17 to ID.13";
					break;

				case 0x0F:
					str += "ID.12 to ID.5";
					break;

				case 0x0E:
					str += "ID.4 to ID.0";
					break;

				case 0x0C:
					str += "RTR Bit";
					break;

				case 0x0D:
					str += "Reserved Bit 1";
					break;

				case 0x09:
					str += "Reserved Bit 0";
					break;

				case 0x0B:
					str += "Data Length Code";
					break;

				case 0x0A:
					str += "Data Field";
					break;

				case 0x08:
					str += "CRC Sequence";
					break;

				case 0x18:
					str += "CRC Delimiter";
					break;

				case 0x19:
					str += "Acknowledge Slot";
					break;

				case 0x1B:
					str += "Acknowledge Delimiter";
					break;

				case 0x1A:
					str += "EOF";
					break;

				case 0x12:
					str += "Intermission";
					break;

				case 0x11:
					str += "Active Error Flag";
					break;

				case 0x16:
					str += "Passive Error Flag";
					break;

				case 0x13:
					str += "Tolerate Dominant Bits";
					break;

				case 0x17:
					str += "Error Delimiter";
					break;

				case 0x1C:
					str += "Overload Flag";
					break;
				
				default:
					str += "Unkown";
				} // end switch


				str += "\r\n";
			}  // end else

			AppendToLog(str);
			UpdateData(false);
		} // end else if pECR

		else if(*(token)== 'A'){
			UpdateData(true);
			if(m_Status & 0x40){
				str.Format("0x%c%c",*(token+1),*(token+2));
				error_val = (unsigned char)getDataValue(str);

				str.Empty();
				str += "Arbitration Lost in Bit: ";
				error_val &= 0x1F;

				if(error_val == 11){ str += "SRTR";}
				else if(error_val == 12){ str += "IDE";}
				else if(error_val == 31){ str += "RTR";}
				else{
					CString buf;
					buf.Format("%d of ID", error_val+1);
					str += buf;
				}

			}else{
				str = "ALC: No Error detected";		
			}	
			str += "\r\n";
			AppendToLog(str);
			UpdateData(false);
		}

		else if(*(token)== 'G'){
			UpdateData(true);
			str.Format("0x%c%c\r\n",*(token+1),*(token+2));
			AppendToLog(str);
			UpdateData(false);
		}

		token = strtok_s(NULL,"\r", &next_token);  // get next token from buffer

	}  // end while token

	free(buffer);
	return true;
}



/*************************************************************************/
//
//FT_Write persistant data to the registry
//
void CCan_controlDlg::saveRegistryData()
{
	CANMsg canmsg;
	HKEY hk;
	char buffer[ 512 ];


	// Get screen data
	getDataValues( &canmsg );

	
	if ( ERROR_SUCCESS == RegOpenKeyEx(	HKEY_LOCAL_MACHINE,
											"software",
											NULL,
											KEY_ALL_ACCESS,
											&hk ) )
	{
		
		HKEY hk_preopt;
		DWORD predisp;
 
		RegCreateKeyEx( hk, "Mictronics", 0L, 
							REG_OPTION_NON_VOLATILE, 
							NULL,
							KEY_ALL_ACCESS,
							NULL,
							&hk_preopt,
							&predisp );
		
		
		
		HKEY hk_opt;
		DWORD disp;
 
		RegCreateKeyEx( hk_preopt, "CAN_Control", 0L, 
							REG_OPTION_NON_VOLATILE, 
							NULL,
							KEY_ALL_ACCESS,
							NULL,
							&hk_opt,
							&disp );
		
		DWORD val;

		// CAN id
		val =  canmsg.id;
		RegSetValueEx( hk_opt,
						"canid",
						NULL,
						REG_DWORD,
						(CONST BYTE *)&val,
						sizeof( val )		
						);

		// CAN Data bytes
		for ( int i = 0; i< 8; i++ ) {
			val =  canmsg.data[ i ];
			sprintf_s( (char *)buffer, 512, "data%i", i );
			RegSetValueEx( hk_opt,
						(const char *)buffer,
						NULL,
						REG_DWORD,
						(CONST BYTE *)&val,
						sizeof( val )		
						);	
		}

		// # of data bytes
		val =  canmsg.len;
		RegSetValueEx( hk_opt,
						"nDataBytes",
						NULL,
						REG_DWORD,
						(CONST BYTE *)&val,
						sizeof( val )	);

		// extended id check box
		val =  m_ctrlExtended.GetCheck();
		RegSetValueEx( hk_opt,
						"bExtended",
						NULL,
						REG_DWORD,
						(CONST BYTE *)&val,
						sizeof( val )	);

		// RTR check box
		val =  m_ctrlCheckRTR.GetCheck();
		RegSetValueEx( hk_opt,
						"bRTR",
						NULL,
						REG_DWORD,
						(CONST BYTE *)&val,
						sizeof( val )	);

		// DriverID
		if(	m_dataSerialList.IsEmpty()){
			m_dataSerialList.Format("\0\0\0");
		}
		strcpy_s( buffer, 512, m_dataSerialList );
		RegSetValueEx( hk_opt,
						"DeviceDesc",
						NULL,
						REG_SZ,
						(const unsigned char *)buffer,
						m_dataSerialList.GetLength());

		// Baudrate
		strcpy_s( buffer, 512, m_dataSelBitrate );
		RegSetValueEx( hk_opt,
						"Baudrate",
						NULL,
						REG_SZ,
						(const unsigned char *)buffer,
						m_dataSelBitrate.GetLength());



		RegCloseKey( hk );
		RegCloseKey( hk_opt ); 
		RegCloseKey( hk_preopt ); 
	}
}


/*************************************************************************/
//
// Load data from registry
//
void CCan_controlDlg::loadRegistryData()
{
	HKEY hk;
	DWORD val;
	DWORD lv;
	DWORD type;
	char nDataBytes = 0;
	unsigned char buffer[ 512 ];
	
	if ( ERROR_SUCCESS == RegOpenKeyEx(	HKEY_LOCAL_MACHINE,
											"software\\Mictronics\\CAN_Control",
											NULL,
											KEY_READ,
											&hk ) ) {
				
		// * * * canid * * *
		lv = sizeof( DWORD );
		if ( ERROR_SUCCESS == RegQueryValueEx(	hk,
												"canid",
												NULL,
												&type,
												(unsigned char *)&val,
												&lv ) ) {
			
		}
		else {
			val = 0;
		}

		_ultoa_s( val, m_MsgId.GetBufferSetLength( 32 ), 32, 16 );
		m_MsgId = "0x" + m_MsgId;

		// * * * CAN Data bytes * * *
		lv = sizeof( DWORD );
		if ( ERROR_SUCCESS == RegQueryValueEx(	hk,
													"nDataBytes",
													NULL,
													&type,
													(unsigned char *)&val,
													&lv ) ) {
			nDataBytes = (char)val;
		}

		// * * * Data 0 * * *
		if ( nDataBytes > 0 ) {
			lv = sizeof( DWORD );
			if ( ERROR_SUCCESS == RegQueryValueEx(	hk,
														"data0",
														NULL,
														&type,
														(unsigned char *)&val,
														&lv ) ) {
				_ultoa_s( val, m_Data0.GetBufferSetLength( 32 ), 32, 16 );
				m_Data0 = "0x" + m_Data0;
			}
			else {
				m_Data0 = "";
			}
		}

		// * * * Data 1 * * *
		if ( nDataBytes > 1 ) {
			lv = sizeof( DWORD );
			if ( ERROR_SUCCESS == RegQueryValueEx(	hk,
														"data1",
														NULL,
														&type,
														(unsigned char *)&val,
												&lv ) ) {
				_ultoa_s( val, m_Data1.GetBufferSetLength( 32 ), 32, 16 );
				m_Data1 = "0x" + m_Data1;
			}
			else {
				m_Data1 = "";
			}
		}

		// * * * Data 2 * * *
		if ( nDataBytes > 2 ) {
			lv = sizeof( DWORD );
			if ( ERROR_SUCCESS == RegQueryValueEx(	hk,
														"data2",
														NULL,
														&type,
														(unsigned char *)&val,
														&lv ) ) {
				_ultoa_s( val, m_Data2.GetBufferSetLength( 32 ), 32, 16 );
				m_Data2 = "0x" + m_Data2;
			}
			else {
				m_Data2 = "";
			}
		}

		// * * * Data 3 * * *
		if ( nDataBytes > 3 ) {
			lv = sizeof( DWORD );
			if ( ERROR_SUCCESS == RegQueryValueEx(	hk,
														"data3",
														NULL,
														&type,
														(unsigned char *)&val,
														&lv ) ) {
				_ultoa_s( val, m_Data3.GetBufferSetLength( 32 ), 32,16 );
				m_Data3 = "0x" + m_Data3;
			}
			else {
				m_Data3 = "";
			}
		}

		// * * * Data 4 * * *
		if ( nDataBytes > 4 ) {
			lv = sizeof( DWORD );
			if ( ERROR_SUCCESS == RegQueryValueEx(	hk,																							"data4",
														NULL,
														&type,
														(unsigned char *)&val,
														&lv ) ) {
				_ultoa_s( val, m_Data4.GetBufferSetLength( 32 ), 32, 16 );
				m_Data4 = "0x" + m_Data4;
			}
			else {
				m_Data4 = "";
			}
		}

		// * * * Data 5 * * *
		if ( nDataBytes > 5 ) {
			lv = sizeof( DWORD );
			if ( ERROR_SUCCESS == RegQueryValueEx(	hk,
														"data5",
														NULL,
														&type,
														(unsigned char *)&val,
														&lv ) ) {
				_ultoa_s( val, m_Data5.GetBufferSetLength( 32 ), 32, 16 );
				m_Data5 = "0x" + m_Data5;
			}
			else {
				m_Data5 = "";
			}
		}

		// * * * Data 6 * * *
		if ( nDataBytes > 6 ) {
			lv = sizeof( DWORD );
			if ( ERROR_SUCCESS == RegQueryValueEx(	hk,
														"data6",
														NULL,
														&type,
														(unsigned char *)&val,
														&lv ) ) {
				_ultoa_s( val, m_Data6.GetBufferSetLength( 32 ), 32, 16 );
				m_Data6 = "0x" + m_Data6;
			}
			else {
				m_Data6 = "";
			}
		}

		// * * * Data 7 * * *
		if ( nDataBytes > 7 ) {
			lv = sizeof( DWORD );
			if ( ERROR_SUCCESS == RegQueryValueEx(	hk,
														"data7",
														NULL,
														&type,
														(unsigned char *)&val,
														&lv ) ) {
				_ultoa_s( val, m_Data7.GetBufferSetLength( 32 ), 32, 16 );
				m_Data7 = "0x" + m_Data7;
			}
			else {
				m_Data7 = "";
			}
		}

		// * * * extended id check box * * *
		lv = sizeof( DWORD );
		if ( ERROR_SUCCESS == RegQueryValueEx(	hk,
												"bExtended",
												NULL,
												&type,
												(unsigned char *)&val,
												&lv ) ) {
			if ( val )  m_ctrlExtended.SetCheck( 1 ) ;
		}		 

		// * * * RTR check box * * *
		lv = sizeof( DWORD );
		if ( ERROR_SUCCESS == RegQueryValueEx(	hk,
												"bRTR",
												NULL,
												&type,
												(unsigned char *)&val,
												&lv ) ) {
			if ( val )  m_ctrlCheckRTR.SetCheck( 1 ) ;
		}

		// * * * device serial * * *
		lv = sizeof( buffer );
		strcpy_s((char*)buffer,512,"\0\0\0");
		if ( ERROR_SUCCESS == RegQueryValueEx(	hk,
												"DeviceDesc",
												NULL,
												&type,
												buffer,
												&lv ) ) {
			m_dataSerialList = buffer;
		}

		// * * * baudrate * * *
		lv = sizeof( buffer );
		if ( ERROR_SUCCESS == RegQueryValueEx(	hk,
												"Baudrate",
												NULL,
												&type,
												buffer,
												&lv ) ) {
			m_dataSelBitrate = buffer;
		}
		
		RegCloseKey( hk );

	}

	UpdateData( false );

}


/*************************************************************************/
//
// Clear Message List
//
void CCan_controlDlg::OnClearMsgListBtn() 
{
	UpdateData(true);
	m_cntSentFrames = 0;
	m_cntReceivedFrames = 0;
	_ltoa_s( m_cntSentFrames, m_sentFrames.GetBuffer(20),20, 10 );
	_ltoa_s( m_cntReceivedFrames, m_receivedFrames.GetBuffer(20),20, 10 );
	UpdateData(false);
	m_MsgList.DeleteAllItems();
}


/*************************************************************************/
//
// Save Message List
//
void CCan_controlDlg::OnSaveListBtn() 
{
	CFileDialog dlg( false, "*.txt",NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, "text files (*.txt)|*.txt||",this );
	if (dlg.DoModal() == IDOK)
	{
		HANDLE file = CreateFile(dlg.GetPathName(),GENERIC_READ|GENERIC_WRITE,0,NULL,CREATE_ALWAYS,0,0);
		if(file==INVALID_HANDLE_VALUE) return;
		int itemcnt = m_MsgList.GetItemCount();
		char Buffer[200],text[20];
		const char  eol[]={13,10,0x00};
		DWORD res;
		int col;
		for (int item=0;item < itemcnt;item++)
		{
			*Buffer=0;
			col=0;
			do
			{
				m_MsgList.GetItemText(item,col++,text,20);
				if(strlen(text)&&strlen(Buffer)) strcat_s(Buffer,200," ");
				 strcat_s(Buffer,200,text);
			} while (strlen(text));
			strcat_s(Buffer,200,eol);
			WriteFile(file,Buffer,strlen(Buffer),&res,NULL);
		}
		CloseHandle(file);
	}
}


/*************************************************************************/
//
// Add ID to known list if not exist
//
void CCan_controlDlg::AddIDtoKnown(CANMsg *pMsg)
{
	int itemcnt=m_ctrlKnownID.GetItemCount();
	char Buffer[20];

	LVFINDINFO info;
	info.flags = LVFI_STRING;
	sprintf_s(Buffer,20,"%08X",pMsg->id);
	info.psz = Buffer;

	// add ID if not exist in known list
	if(m_ctrlKnownID.FindItem(&info) == -1){
		m_ctrlKnownID.InsertItem(itemcnt,Buffer);	
	}
}


/*************************************************************************/
//
// Add ID to filter list
//
void CCan_controlDlg::OnAddIDBtn() 
{
	char Buffer[20];
	unsigned int KnownSelCnt = m_ctrlKnownID.GetSelectedCount();
	int FilterItemCnt = m_ctrlFilterID.GetItemCount();

	POSITION pos = m_ctrlKnownID.GetFirstSelectedItemPosition();

	LVFINDINFO info;
	info.flags = LVFI_STRING;

	if( KnownSelCnt > 0 ){

		for(unsigned int i=0; i < KnownSelCnt; i++){
			
			int SelectedItem = m_ctrlKnownID.GetNextSelectedItem(pos);
			
			m_ctrlKnownID.GetItemText(SelectedItem,0,Buffer,20);
			info.psz = Buffer;

			// add ID if not exist in known list
			if(m_ctrlFilterID.FindItem(&info) == -1){
				m_ctrlFilterID.InsertItem(FilterItemCnt,Buffer);	
			}
		}
	}
}


/*************************************************************************/
//
// Delete ID from filter list
//
void CCan_controlDlg::OnDeleteItemFilterID(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;

	unsigned int itemState = 0;

	// Loop through all items.
	for (size_t i = 0; i < static_cast<size_t>(m_ctrlFilterID.GetItemCount()); ++i)
	{
		itemState = m_ctrlFilterID.GetItemState(static_cast<int>(i), LVIS_SELECTED);

		if (itemState & LVIS_SELECTED){
			m_ctrlFilterID.DeleteItem(i);
		}
	}	

	*pResult = 0;
}


/*************************************************************************/
//
// Delete ID from filter list
//
void CCan_controlDlg::OnDelIDBtn() 
{
	unsigned int itemState = 0;

	// Loop through all items.
	for (size_t i = 0; i < static_cast<size_t>(m_ctrlFilterID.GetItemCount()); ++i)
	{
		itemState = m_ctrlFilterID.GetItemState(static_cast<int>(i), LVIS_SELECTED);

		if (itemState & LVIS_SELECTED){
			m_ctrlFilterID.DeleteItem(i);
		}
	}
}



/*************************************************************************/
//
// Setup timer to send frame in cyclic interval
//
void CCan_controlDlg::OnSendCyclic() 
{	
	if( !m_DevOpen ){
//		AfxMessageBox("Error: Device not open." );
		return;
	}

	unsigned int val = (unsigned int)getDataValue( m_dataIntervalTime );

	TRACE("Interval Cyclic Time: %u\n", val);
	
	UpdateData(true);
	if(val < 10 ) {
		val = 10;
		m_dataIntervalTime = _T("10");
	}
	UpdateData(false);

	if( m_ctrl_CheckCyclic.GetCheck() ){

		if(!SetTimer( IDD_TIMER_CYCLICFRAME, val, NULL ) )
		{
			AfxMessageBox("Error: Failed to setup cyclic timer.");
			return;
		}
	} else {
		KillTimer( IDD_TIMER_CYCLICFRAME);
	}	
}


// ********************************************************
//
// Append some text to the RichEdit log field
//
// Use like this:
//
// AppendToLog("This is dark green text.\n", RGB(0, 0x99, 0));
//
// ********************************************************
int CCan_controlDlg::AppendToLog( CString str)
{
  int nOldLines = 0, nNewLines = 0, nScroll = 0;
  long nInsertionPoint = 0;
  CHARFORMAT cf;
  // Save number of lines before insertion of new text
  nOldLines = m_ctrl_Log.GetLineCount();
  // Initialize character format structure
  cf.cbSize = sizeof(CHARFORMAT);
  cf.dwMask = CFM_COLOR;
  cf.dwEffects = 0; // To disable CFE_AUTOCOLOR
  cf.crTextColor = RGB(0, 0, 0);
  // Set insertion point to end of text
  nInsertionPoint = m_ctrl_Log.GetWindowTextLength();
  m_ctrl_Log.SetSel(nInsertionPoint, -1);
  // Set the character format
  m_ctrl_Log.SetSelectionCharFormat(cf);
  // Replace selection. Because we have nothing 
  // selected, this will simply insert
  // the string at the current caret position.
  m_ctrl_Log.ReplaceSel(str);
  // Get new line count
  nNewLines = m_ctrl_Log.GetLineCount();
  // Scroll by the number of lines just inserted
  nScroll = nNewLines - nOldLines;
  m_ctrl_Log.LineScroll(nScroll);
  return 0;
}