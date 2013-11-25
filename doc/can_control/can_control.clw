; CLW-Datei enthält Informationen für den MFC-Klassen-Assistenten

[General Info]
Version=1
LastClass=CCan_controlDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "can_control.h"

ClassCount=4
Class1=CCan_controlApp
Class2=CCan_controlDlg
Class3=CAboutDlg

ResourceCount=5
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_CAN_CONTROL_DIALOG
Resource4=IDD_ABOUTBOX (Neutral)
Class4=Dialog1
Resource5=IDD_CAN_CONTROL_DIALOG (Neutral)

[CLS:CCan_controlApp]
Type=0
HeaderFile=can_control.h
ImplementationFile=can_control.cpp
Filter=W

[CLS:CCan_controlDlg]
Type=0
HeaderFile=can_controlDlg.h
ImplementationFile=can_controlDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_SentCountStatic

[CLS:CAboutDlg]
Type=0
HeaderFile=can_controlDlg.h
ImplementationFile=can_controlDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Class=CAboutDlg


[DLG:IDD_CAN_CONTROL_DIALOG]
Type=1
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Class=CCan_controlDlg

[DLG:IDD_CAN_CONTROL_DIALOG (Neutral)]
Type=1
Class=CCan_controlDlg
ControlCount=63
Control1=IDC_SerialList,combobox,1344340226
Control2=IDC_SelBitrateCombo,combobox,1344339970
Control3=IDC_OpenBtn,button,1342242816
Control4=IDC_LOModeBtn,button,1342242816
Control5=IDC_IDEdit,edit,1350631552
Control6=IDC_ExtCheck,button,1342242819
Control7=IDC_RTRCheck,button,1342242819
Control8=IDC_Data1Edit,edit,1350631552
Control9=IDC_Data2Edit,edit,1350631552
Control10=IDC_Data3Edit,edit,1350631552
Control11=IDC_Data4Edit,edit,1350631552
Control12=IDC_Data5Edit,edit,1350631552
Control13=IDC_Data6Edit,edit,1350631552
Control14=IDC_Data7Edit,edit,1350631552
Control15=IDC_Data8Edit,edit,1350631552
Control16=IDC_ACREdit,edit,1350631552
Control17=IDC_AMREdit,edit,1350631552
Control18=IDC_StatusBtn,button,1342242816
Control19=IDC_VersionBtn,button,1342242816
Control20=IDC_TimestampBtn,button,1342242816
Control21=IDC_ReadALCBtn,button,1342242816
Control22=IDC_ReadECRBtn,button,1342242816
Control23=IDC_ReadRegEdit,edit,1350631424
Control24=IDC_ReadRegBtn,button,1342242816
Control25=IDC_WriteRegEdit,edit,1350631552
Control26=IDC_WriteRegDataEdit,edit,1350631552
Control27=IDC_WriteRegBtn,button,1342242816
Control28=IDC_SendMsgBtn,button,1342242816
Control29=IDC_ClearBtn,button,1342242816
Control30=IDC_ClearDataBtn,button,1342242816
Control31=IDCANCEL,button,1342246656
Control32=IDC_msgBox,edit,1352732676
Control33=IDC_SelOpenDev,button,1342177287
Control34=IDC_sendFramesStatic,static,1342308354
Control35=IDC_recvFramesStatic,static,1342308354
Control36=IDC_SentCountStatic,static,1342308352
Control37=IDC_RecvCountStatic,static,1342308352
Control38=IDC_MsgListStatic,static,1342308352
Control39=IDC_ReadSJAStatic,button,1342177287
Control40=IDC_RegStatic,static,1342308352
Control41=IDC_WriteRegStatic,button,1342177287
Control42=IDC_WriteRegName,static,1342308352
Control43=IDC_WriteDataName,static,1342308352
Control44=IDC_SelBaudStatic,button,1342177287
Control45=IDC_TxMsgStatic,button,1342177287
Control46=IDC_IDStatic,button,1342177287
Control47=IDC_FlagsStatic,button,1342177287
Control48=IDC_DataStatic,button,1342177287
Control49=IDC_TextStatic,static,1342308352
Control50=IDC_BTRHelpStatic,static,1342308352
Control51=IDC_ACRStatic,button,1342177287
Control52=IDC_AMRStatic,button,1342177287
Control53=IDC_MSGLIST,SysListView32,1350631433
Control54=IDC_CLEARMSGLISTBTN,button,1342242816
Control55=IDC_SAVELISTBTN,button,1342242816
Control56=IDC_KNOWNID,SysListView32,1350631441
Control57=IDC_FILTERID,SysListView32,1350631441
Control58=IDC_ADDIDBTN,button,1342242816
Control59=IDC_DELIDBTN,button,1342242816
Control60=IDC_SENDCYCLICINTERVAL,edit,1350639744
Control61=IDC_SENDCYCLIC,button,1342242819
Control62=IDC_STATIC,static,1342308352
Control63=IDC_ASCII_HEX,button,1342242819

[DLG:IDD_ABOUTBOX (Neutral)]
Type=1
Class=CAboutDlg
ControlCount=6
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352

[CLS:Dialog1]
Type=0
HeaderFile=Dialog1.h
ImplementationFile=Dialog1.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=Dialog1

