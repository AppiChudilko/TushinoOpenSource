//---------------------------------------------------------------------------

// This software is Copyright (c) 2015 Embarcadero Technologies, Inc.
// You may only use this software if you are an authorized licensee
// of an Embarcadero developer tools product.
// This software is considered a Redistributable as defined under
// the software license agreement that comes with the Embarcadero Products
// and is subject to that software license agreement.

//---------------------------------------------------------------------------

#ifndef uMainH
#define uMainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.ActnList.hpp>
#include <FMX.Gestures.hpp>
#include <FMX.Objects.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.TabControl.hpp>
#include <FMX.Types.hpp>
#include <System.Actions.hpp>
#include <FMX.MobilePreview.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Advertising.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.MultiView.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdHTTP.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
#include <FMX.Grid.hpp>
#include <System.Rtti.hpp>
#include <FMX.ListBox.hpp>
#include <FMX.ImgList.hpp>
#include <System.ImageList.hpp>
#include <FMX.Memo.hpp>
#include <FMX.ScrollBox.hpp>
#include <System.Notification.hpp>
#include <memory>
#include <System.JSON.hpp>
//#include <thread>
//#include "RegExpr.hpp"
#include <System.RegularExpressions.hpp>
#include <System.IniFiles.hpp>
#include <System.Ioutils.hpp>
#include <ctime>
//---------------------------------------------------------------------------
class TMain : public TForm
{
__published:	// IDE-managed Components
	TTabControl *TabControlMain;
	TTabItem *TabItem1;
	TTabItem *TabItem2;
	TGestureManager *GestureManager1;
	TActionList *TabActionList;
	TChangeTabAction *ChangeTabActionPrev;
	TChangeTabAction *ChangeTabActionNext;
	TRectangle *RectangleBG1;
	TLabel *LabelByAppi;
	TRectangle *Rectangle1;
	TRectangle *Rectangle2;
	TRectangle *Rectangle3;
	TImage *Image1;
	TLabel *LabelNick;
	TRectangle *Rectangle4;
	TImage *Image2;
	TLabel *Label2;
	TVertScrollBox *VertScrollBox1;
	TVertScrollBox *VertScrollBox2;
	TImage *Image3;
	TButton *ButtonOpenMultiView;
	TButton *ButtonRefresh;
	TMultiView *MultiView1;
	TVertScrollBox *VertScrollBox3;
	TRectangle *RectangleBG2;
	TRectangle *RectangleBG3;
	TButton *ButtonMM1;
	TRectangle *RectangleBG5;
	TButton *ButtonMM4;
	TRectangle *RectangleBG6;
	TRectangle *RectangleBG7;
	TButton *ButtonMM3;
	TRectangle *RectangleBG8;
	TRectangle *RectangleBG4;
	TButton *ButtonMM2;
	TRectangle *RectangleBG9;
	TRectangle *RectangleBG10;
	TLabel *LabelFirst;
	TLabel *LabelReg;
	TRectangle *RectangleBG11;
	TLabel *LabelID;
	TRectangle *RectangleBG12;
	TRectangle *RectangleBG14;
	TLabel *LabelLast;
	TRectangle *RectangleBG15;
	TLabel *LabelMaceTime;
	TRectangle *RectangleBG16;
	TLabel *LabelSGTime;
	TRectangle *RectangleBG17;
	TLabel *LabelSide;
	TRectangle *RectangleBG18;
	TLabel *LabelGroup;
	TRectangle *RectangleBG19;
	TLabel *LabelName;
	TRectangle *RectangleBG20;
	TLabel *EditID;
	TLabel *LabelMobID;
	TRectangle *RectangleBG21;
	TRectangle *RectangleBG22;
	TIdHTTP *IdHTTP1;
	TStringGrid *StringGrid1;
	TStringColumn *StringColumn1;
	TStringColumn *StringColumn2;
	TStringColumn *StringColumn3;
	TLabel *Label1;
	TLabel *LabelGUID;
	TRectangle *RectangleLogo;
	TLabel *LabelSG;
	THorzScrollBox *Servers;
	TRectangle *Rectangle8;
	TLabel *Label6;
	TRectangle *RectangleSrv1;
	TLabel *LabelServer1;
	TRectangle *Rectangle9;
	TLabel *LabelStatusS1;
	TRectangle *Rectangle11;
	TLabel *LabelMissionS1;
	TLabel *LabelIPS1;
	TLabel *LabelVS1;
	TLabel *LabelPlayersS1;
	TLabel *LabelMapS1;
	TRectangle *Rectangle13;
	TRectangle *Rectangle15;
	TRectangle *Rectangle16;
	TRectangle *Rectangle17;
	TRectangle *Rectangle18;
	TRectangle *RectangleSrv3;
	TLabel *LabelMissionS3;
	TLabel *LabelIPS3;
	TLabel *LabelVS3;
	TLabel *LabelPlayersS3;
	TLabel *LabelMapS3;
	TLabel *LabelStatusS3;
	TLabel *LabelServer3;
	TRectangle *Rectangle12;
	TRectangle *Rectangle14;
	TRectangle *Rectangle19;
	TRectangle *Rectangle20;
	TRectangle *Rectangle21;
	TRectangle *Rectangle22;
	TRectangle *Rectangle23;
	TLabel *Label20;
	TRectangle *Rectangle24;
	TRectangle *RectangleSrv2;
	TLabel *LabelMissionS2;
	TLabel *LabelIPS2;
	TLabel *LabelVS2;
	TLabel *LabelPlayersS2;
	TLabel *LabelMapS2;
	TLabel *LabelStatusS2;
	TLabel *LabelServer2;
	TRectangle *Rectangle26;
	TRectangle *Rectangle27;
	TRectangle *Rectangle28;
	TRectangle *Rectangle29;
	TRectangle *Rectangle30;
	TRectangle *Rectangle31;
	TRectangle *Rectangle32;
	TLabel *Label28;
	TRectangle *Rectangle33;
	TSpeedButton *RefreshServer1;
	TImageList *ImageList1;
	TSpeedButton *RefreshServer2;
	TSpeedButton *RefreshServer3;
	TMemo *MemoInfo;
	TVertScrollBox *Settings;
	TRectangle *Rectangle5;
	TImage *Image4;
	TLabel *Label3;
	TRectangle *Rectangle10;
	TRectangle *Rectangle25;
	TLabel *Label4;
	TRectangle *Rectangle34;
	TSwitch *SwitchServ1;
	TLabel *Label5;
	TRectangle *Rectangle35;
	TSwitch *SwitchServ2;
	TLabel *Label7;
	TRectangle *Rectangle36;
	TSwitch *SwitchServ3;
	TLabel *Label8;
	TRectangle *Rectangle37;
	TRectangle *Rectangle38;
	TRectangle *Rectangle39;
	TLabel *Label9;
	TComboBox *ComboBoxTime;
	TRectangle *Rectangle40;
	TButton *ButtonSave;
	TRectangle *Rectangle41;
	TSwitch *SwitchFullScr;
	TLabel *Label10;
	TStyleBook *StyleBook1;
	TNotificationCenter *NotificationCenter1;
	TTimer *TimerRefresh;
	TRectangle *Rectangle6;
	TRectangle *Rectangle7;
	TButton *ButtonMM5;
	void __fastcall ChangeTabActionPrevUpdate(TObject *Sender);
	void __fastcall ButtonOpenMultiViewClick(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall ButtonRefreshClick(TObject *Sender);
	void __fastcall ProfileRefresh();
	String __fastcall UnixTimeToTime(int UnixTime);
	String __fastcall HttpRefresh(int ServerNumber);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall ButtonMM1Click(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall RefreshServer1Click(TObject *Sender);
	void __fastcall RefreshServer2Click(TObject *Sender);
	void __fastcall RefreshServer3Click(TObject *Sender);
	void __fastcall ButtonMM2Click(TObject *Sender);
	void __fastcall ButtonMM3Click(TObject *Sender);
	void __fastcall ButtonMM4Click(TObject *Sender);
	void __fastcall ButtonSaveClick(TObject *Sender);
	void __fastcall TimerRefreshTimer(TObject *Sender);
	void __fastcall SwitchServ1Switch(TObject *Sender);
	void __fastcall SwitchServ2Switch(TObject *Sender);
	void __fastcall SwitchServ3Switch(TObject *Sender);
	void __fastcall SwitchFullScrSwitch(TObject *Sender);
	void __fastcall ComboBoxTimeChange(TObject *Sender);
	void __fastcall Image3Gesture(TObject *Sender, const TGestureEventInfo &EventInfo,
          bool &Handled);
	void __fastcall ButtonMM5Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	String MobileID="0";
	short int Srv1=0,Srv2=0,Srv3=0;
	String OldMissionS1,OldMissionS2,OldMissionS3;
	String GameState1,GameState2,GameState3;
	__fastcall TMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMain *Main;
//---------------------------------------------------------------------------
#endif
