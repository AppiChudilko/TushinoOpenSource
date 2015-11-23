//---------------------------------------------------------------------------

// This software is Copyright (c) 2015 Embarcadero Technologies, Inc.
// You may only use this software if you are an authorized licensee
// of an Embarcadero developer tools product.
// This software is considered a Redistributable as defined under
// the software license agreement that comes with the Embarcadero Products
// and is subject to that software license agreement.

//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Main.h"
#include "TRefMain.h"
#include "TRefServer.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
//#pragma resource ("*.LgXhdpiPh.fmx", _PLAT_ANDROID)

TMain *Main;
TRefMain *ThreadHistory;
TRefServer *ThreadServer;
//---------------------------------------------------------------------------
__fastcall TMain::TMain(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMain::ChangeTabActionPrevUpdate(TObject *Sender)
{
	if(TabControlMain->TabIndex < TabControlMain->TabCount - 1)
		ChangeTabActionNext->Tab = TabControlMain->Tabs[TabControlMain->TabIndex + 1];
	else
		ChangeTabActionNext->Tab = NULL;

	if (TabControlMain->TabIndex > 0)
		ChangeTabActionPrev->Tab = TabControlMain->Tabs[TabControlMain->TabIndex - 1];
	else
		ChangeTabActionPrev->Tab = NULL;


	/*if(TabControlSrv->TabIndex < TabControlSrv->TabCount - 1)
		ChangeTabActionNext->Tab = TabControlSrv->Tabs[TabControlSrv->TabIndex + 1];
	else
		ChangeTabActionNext->Tab = NULL;

	if (TabControlSrv->TabIndex > 0)
		ChangeTabActionPrev->Tab = TabControlSrv->Tabs[TabControlSrv->TabIndex - 1];
	else
		ChangeTabActionPrev->Tab = NULL;  */
}
//---------------------------------------------------------------------------



void __fastcall TMain::ButtonOpenMultiViewClick(TObject *Sender)
{
	MultiView1->ShowMaster();
}
//---------------------------------------------------------------------------

void __fastcall TMain::FormActivate(TObject *Sender)
{
	//TabControlMain->Visible=true;
	RectangleSrv1->Width = Main->Width;
	RectangleSrv2->Width = Main->Width;
	RectangleSrv3->Width = Main->Width;
}
//---------------------------------------------------------------------------


void __fastcall TMain::ButtonRefreshClick(TObject *Sender)
{
	if(TabControlMain->Visible) { //ProfileRefresh();
		//TRefMain *ThreadHistory = new TRefMain(true);
		//ThreadHistory->Start();
		//ShowMessage("Done2");
		//ButtonRefresh->Enabled=false;
		ProfileRefresh();
    }
	/*} else {
		HttpRefresh(4);
		TRefServer *ThreadServer = new TRefServer(true);
		ThreadServer->Start();
		Main->ButtonRefresh->Enabled=false;
	} */
}
//---------------------------------------------------------------------------

void __fastcall TMain::ProfileRefresh() {

	//LoadWebImage("http://xn--c1adahg2atfb8hee9d.xn--p1ai/uploads/fotos/foto_8987.jpg", ImagePhoto->Bitmap);

	LabelNick->Text=L"Nick";
	LabelGroup->Text=L"������:";
	LabelName->Text=L"���:";
	LabelGUID->Text=L"";
	LabelID->Text=L"Arma2 ID:";
	LabelSGTime->Text=L"SG: ";
	LabelMaceTime->Text=L"mACE: ";
	LabelSide->Text=L"�������:";
	LabelFirst->Text=L"������ ��������:";
	LabelLast->Text=L"������� ���:";
	LabelReg->Text=L"���� �����������:";

	std::auto_ptr<TStringStream> ss (new TStringStream("", TEncoding::GetEncoding(1251), true));
	try
	{
		IdHTTP1->Get("http://www.xn--c1adahg2atfb8hee9d.xn--p1ai/mobile_info.php?key=dsadas54sdgDF54cvdfghjsadf546&action=get_profile&mobile_id="+MobileID, ss.get());
	}
	catch(...)
	{
	}

	if (ss->DataString.Length() < 3) {
		LabelNick->Text=L"���������� ����������� �� ��� ������ � ������� �� �����";
		EditID->Text=MobileID;
	} else {

		String One = ss->DataString;
		String expr = "name =(.*?)&";
		TRegExOptions reg_opt = TRegExOptions() << roIgnoreCase << roMultiLine;
		if (TRegEx::IsMatch(One, expr, reg_opt)) LabelNick->Text=TRegEx::Match(One, expr, reg_opt).Groups[1].Value;

		expr = L"user_group =(.*?)&";
		reg_opt = TRegExOptions() << roIgnoreCase << roMultiLine;
		if (TRegEx::IsMatch(One, expr, reg_opt)) LabelGroup->Text=LabelGroup->Text+TRegEx::Match(One, expr, reg_opt).Groups[1].Value;

		expr = L"fullname =(.*?)&";
		reg_opt = TRegExOptions() << roIgnoreCase << roMultiLine;
		if (TRegEx::IsMatch(One, expr, reg_opt)) LabelName->Text=LabelName->Text+TRegEx::Match(One, expr, reg_opt).Groups[1].Value;

		expr = L"arma_guid =(.*?)&";
		reg_opt = TRegExOptions() << roIgnoreCase << roMultiLine;
		if (TRegEx::IsMatch(One, expr, reg_opt)) LabelGUID->Text=LabelGUID->Text+TRegEx::Match(One, expr, reg_opt).Groups[1].Value;

		expr = L"arma_id =(.*?)&";
		reg_opt = TRegExOptions() << roIgnoreCase << roMultiLine;
		if (TRegEx::IsMatch(One, expr, reg_opt)) LabelID->Text=LabelID->Text+TRegEx::Match(One, expr, reg_opt).Groups[1].Value;

		expr = L"arma_sg_time =(.*?)&";
		reg_opt = TRegExOptions() << roIgnoreCase << roMultiLine;
		if (TRegEx::IsMatch(One, expr, reg_opt)) LabelSGTime->Text=LabelSGTime->Text+UnixTimeToTime(StrToInt(TRegEx::Match(One, expr, reg_opt).Groups[1].Value));

		expr = L"arma_sg_miss =(.*?)&";
		reg_opt = TRegExOptions() << roIgnoreCase << roMultiLine;
		if (TRegEx::IsMatch(One, expr, reg_opt)) LabelSGTime->Text=LabelSGTime->Text+"\\"+TRegEx::Match(One, expr, reg_opt).Groups[1].Value;

		expr = L"arma_sg_death =(.*?)&";
		reg_opt = TRegExOptions() << roIgnoreCase << roMultiLine;
		if (TRegEx::IsMatch(One, expr, reg_opt)) LabelSGTime->Text=LabelSGTime->Text+" \\"+TRegEx::Match(One, expr, reg_opt).Groups[1].Value;

		expr = L"arma_mace_time =(.*?)&";
		reg_opt = TRegExOptions() << roIgnoreCase << roMultiLine;
		if (TRegEx::IsMatch(One, expr, reg_opt)) LabelMaceTime->Text=LabelMaceTime->Text+UnixTimeToTime(StrToInt(TRegEx::Match(One, expr, reg_opt).Groups[1].Value));

		expr = L"arma_mace_miss =(.*?)&";
		reg_opt = TRegExOptions() << roIgnoreCase << roMultiLine;
		if (TRegEx::IsMatch(One, expr, reg_opt)) LabelMaceTime->Text=LabelMaceTime->Text+"\\"+TRegEx::Match(One, expr, reg_opt).Groups[1].Value;

		expr = L"arma_mace_death =(.*?)&";
		reg_opt = TRegExOptions() << roIgnoreCase << roMultiLine;
		if (TRegEx::IsMatch(One, expr, reg_opt)) LabelMaceTime->Text=LabelMaceTime->Text+" \\"+TRegEx::Match(One, expr, reg_opt).Groups[1].Value;

		expr = L"arma_side =(.*?)&";
		reg_opt = TRegExOptions() << roIgnoreCase << roMultiLine;
		if (TRegEx::IsMatch(One, expr, reg_opt)) //LabelGUID->Text=LabelGUID->Text+TRegEx::Match(One, expr, reg_opt).Groups[1].Value;
		{
			switch(StrToInt(TRegEx::Match(One, expr, reg_opt).Groups[1].Value)) {
				case 0: LabelSide->Text=LabelSide->Text+L" �����������"; break;
				case 1: LabelSide->Text=LabelSide->Text+L" �������"; break;
				case 2: LabelSide->Text=LabelSide->Text+L" �����"; break;
			}
		}


		expr = L"firstmission =(.*?)&";
		reg_opt = TRegExOptions() << roIgnoreCase << roMultiLine;
		if (TRegEx::IsMatch(One, expr, reg_opt)) LabelFirst->Text=LabelFirst->Text+TRegEx::Match(One, expr, reg_opt).Groups[1].Value;

		expr = L"lastmission =(.*?)&";
		reg_opt = TRegExOptions() << roIgnoreCase << roMultiLine;
		if (TRegEx::IsMatch(One, expr, reg_opt)) LabelLast->Text=LabelLast->Text+TRegEx::Match(One, expr, reg_opt).Groups[1].Value;


		expr = L"reg_date =(.*?)&";
		reg_opt = TRegExOptions() << roIgnoreCase << roMultiLine;
		if (TRegEx::IsMatch(One, expr, reg_opt)) LabelReg->Text=LabelReg->Text+TRegEx::Match(One, expr, reg_opt).Groups[1].Value;

		EditID->Text=MobileID;


		try
		{
			IdHTTP1->Get("http://www.xn--c1adahg2atfb8hee9d.xn--p1ai/mobile_info.php?key=dsadas54sdgDF54cvdfghjsadf546&action=get_history&mobile_id="+MobileID, ss.get());
		}
		catch(...)
		{
		}
		One = ss->DataString;
		expr = L"<td style=\"text-align:center;\">(.*?)</td>";

		reg_opt = TRegExOptions() << roIgnoreCase << roMultiLine;
		TMatchCollection m;

		short int X=0,Y=0;

		if (TRegEx::IsMatch(One, expr, reg_opt))
		{
			m = TRegEx::Matches(One, expr, reg_opt);
			for (int i=2; i<m.Count; i++)
				for (int j=1; j<m.Item[i].Groups.Count; j++) {
					if(i%2 == 0)
						StringGrid1->Cells[0][X++]=m.Item[i].Groups[j].Value;
					else
						StringGrid1->Cells[1][Y++]=m.Item[i].Groups[j].Value;
				}
		}
		One = ss->DataString;
		expr = L"<td style=\"padding:5px; width: 500px; word-wrap:break-word;\">(.*?)</td>";
		reg_opt = TRegExOptions() << roIgnoreCase << roMultiLine;
		X=0;
		if (TRegEx::IsMatch(One, expr, reg_opt))
		{
			m = TRegEx::Matches(One, expr, reg_opt);
			for (int i=1; i<m.Count; i++)
				for (int j=1; j<m.Item[i].Groups.Count; j++)
					StringGrid1->Cells[2][X++]=m.Item[i].Groups[j].Value;
		}
		TIniFile *CfgIni = new TIniFile(System::Ioutils::TPath::GetDocumentsPath() + PathDelim + "SettingCfg.ini");
		CfgIni->WriteString("Prifile", "Nick", LabelNick->Text);
		CfgIni->WriteString("Prifile", "Group", LabelGroup->Text);
		CfgIni->WriteString("Prifile", "Name", LabelName->Text);
		CfgIni->WriteString("Prifile", "GUID", LabelGUID->Text);
		CfgIni->WriteString("Prifile", "ID", LabelID->Text);
		CfgIni->WriteString("Prifile", "SGTime", LabelSGTime->Text);
		CfgIni->WriteString("Prifile", "mACE", LabelMaceTime->Text);
		CfgIni->WriteString("Prifile", "Side", LabelSide->Text);
		CfgIni->WriteString("Prifile", "FirstMis", LabelFirst->Text);
		CfgIni->WriteString("Prifile", "LastMis", LabelLast->Text);
		CfgIni->WriteString("Prifile", "Reg", LabelReg->Text);
		delete CfgIni;
	}
	if (LabelNick->Text == "Nick") {
		LabelNick->Text=L"������� ���� ���������� ����������� � ������� �� �����";
		EditID->Text=MobileID;
	}

}

String __fastcall TMain::HttpRefresh(int ServerNumber) {

	TIdHTTP *http = new TIdHTTP(0);


	switch(ServerNumber) {
		case 0: ServerNumber=1; break;
		case 1: ServerNumber=2; break;
		case 2: ServerNumber=6; break;
	}

	std::auto_ptr<TStringStream> ss (new TStringStream("", TEncoding::GetEncoding(1251), true));

	try
	{
		http->Get("http://arma3.ru/tushino.php?server="+IntToStr(ServerNumber)+"&view=json", ss.get());
	}
	catch(...)
	{
	}

	String MissionStatus;

	switch(ServerNumber) {
		case 1: {
			LabelStatusS1->Text=L"������:";
			LabelMissionS1->Text=L"������:";
			LabelPlayersS1->Text=L"�������:";
			LabelMapS1->Text=L"�����:";
			LabelVS1->Text=L"������:";

			String One = ss->DataString;
			String expr = "\"State\":\"(.*?)\",";
			TRegExOptions reg_opt = TRegExOptions() << roIgnoreCase << roMultiLine;
			if (TRegEx::IsMatch(One, expr, reg_opt)) {
				String GameState;
				switch(StrToInt(TRegEx::Match(One, expr, reg_opt).Groups[1].Value)) {
					case -1: GameState = L"��� ������"; break;
					case 1: GameState = L"������ ����/����� ������"; break;
					case 3: GameState = L"�����/��������"; break;
					case 5: GameState = L"�������� ������"; break;
					case 6: GameState = L"�������"; break;
					case 7: GameState = L"���� ����"; break;
					case 9: GameState = L"���������"; break;
					case 12: GameState = L"���������"; break;
					case 13: GameState = L"�������"; break;
					case 14: GameState = L"���� ����"; break;
					default: GameState = L"����������"; break;
				}
				LabelStatusS1->Text=LabelStatusS1->Text+" "+GameState;
				GameState1=GameState;
			}

			expr = "\"Mission\":\"(.*?)\",";
			reg_opt = TRegExOptions() << roIgnoreCase << roMultiLine;
			if (TRegEx::IsMatch(One, expr, reg_opt)) {
				MissionStatus=TRegEx::Match(One, expr, reg_opt).Groups[1].Value;
				String Mission = "\""+TRegEx::Match(One, expr, reg_opt).Groups[1].Value+"\"";
				TJSONValue *JSON = TJSONObject::ParseJSONValue(TEncoding::UTF8->GetBytes(Mission), 0);
				LabelMissionS1->Text=LabelMissionS1->Text+" "+JSON->ToString();
			}

			String Players;

			expr = "\"PlayersNum\":(.*?),";
			reg_opt = TRegExOptions() << roIgnoreCase << roMultiLine;
			if (TRegEx::IsMatch(One, expr, reg_opt)) Players=TRegEx::Match(One, expr, reg_opt).Groups[1].Value;

			expr = "\"PlayersMax\":(.*?),";
			reg_opt = TRegExOptions() << roIgnoreCase << roMultiLine;
			if (TRegEx::IsMatch(One, expr, reg_opt)) LabelPlayersS1->Text=LabelPlayersS1->Text+" "+Players+"/"+TRegEx::Match(One, expr, reg_opt).Groups[1].Value;

			expr = "\"Island\":\"(.*?)\",";
			reg_opt = TRegExOptions() << roIgnoreCase << roMultiLine;
			if (TRegEx::IsMatch(One, expr, reg_opt)) LabelMapS1->Text=LabelMapS1->Text+" "+TRegEx::Match(One, expr, reg_opt).Groups[1].Value;

			expr = "\"Version\":\"(.*?)\",";
			reg_opt = TRegExOptions() << roIgnoreCase << roMultiLine;
			if (TRegEx::IsMatch(One, expr, reg_opt)) LabelVS1->Text=LabelVS1->Text+" "+TRegEx::Match(One, expr, reg_opt).Groups[1].Value;

			break;
		}
		case 2: {
			LabelStatusS2->Text=L"������:";
			LabelMissionS2->Text=L"������:";
			LabelPlayersS2->Text=L"�������:";
			LabelMapS2->Text=L"�����:";
			LabelVS2->Text=L"������:";

			String One = ss->DataString;
			String expr = "\"State\":\"(.*?)\",";
			TRegExOptions reg_opt = TRegExOptions() << roIgnoreCase << roMultiLine;
			if (TRegEx::IsMatch(One, expr, reg_opt)) {
				String GameState;
				switch(StrToInt(TRegEx::Match(One, expr, reg_opt).Groups[1].Value)) {
					case -1: GameState = L"��� ������"; break;
					case 1: GameState = L"������ ����/����� ������"; break;
					case 3: GameState = L"�����/��������"; break;
					case 5: GameState = L"�������� ������"; break;
					case 6: GameState = L"�������"; break;
					case 7: GameState = L"���� ����"; break;
					case 9: GameState = L"���������"; break;
					case 12: GameState = L"���������"; break;
					case 13: GameState = L"�������"; break;
					case 14: GameState = L"���� ����"; break;
					default: GameState = L"����������"; break;
				}
				LabelStatusS2->Text=LabelStatusS2->Text+" "+GameState;
				GameState2=GameState;
			}

			expr = "\"Mission\":\"(.*?)\",";
			reg_opt = TRegExOptions() << roIgnoreCase << roMultiLine;
			if (TRegEx::IsMatch(One, expr, reg_opt)) {
				MissionStatus=TRegEx::Match(One, expr, reg_opt).Groups[1].Value;
				String Mission = "\""+TRegEx::Match(One, expr, reg_opt).Groups[1].Value+"\"";
				TJSONValue *JSON = TJSONObject::ParseJSONValue(TEncoding::UTF8->GetBytes(Mission), 0);
				LabelMissionS2->Text=LabelMissionS2->Text+" "+JSON->ToString();
			}

			String Players;

			expr = "\"PlayersNum\":(.*?),";
			reg_opt = TRegExOptions() << roIgnoreCase << roMultiLine;
			if (TRegEx::IsMatch(One, expr, reg_opt)) Players=TRegEx::Match(One, expr, reg_opt).Groups[1].Value;

			expr = "\"PlayersMax\":(.*?),";
			reg_opt = TRegExOptions() << roIgnoreCase << roMultiLine;
			if (TRegEx::IsMatch(One, expr, reg_opt)) LabelPlayersS2->Text=LabelPlayersS2->Text+" "+Players+"/"+TRegEx::Match(One, expr, reg_opt).Groups[1].Value;

			expr = "\"Island\":\"(.*?)\",";
			reg_opt = TRegExOptions() << roIgnoreCase << roMultiLine;
			if (TRegEx::IsMatch(One, expr, reg_opt)) LabelMapS2->Text=LabelMapS2->Text+" "+TRegEx::Match(One, expr, reg_opt).Groups[1].Value;

			expr = "\"Version\":\"(.*?)\",";
			reg_opt = TRegExOptions() << roIgnoreCase << roMultiLine;
			if (TRegEx::IsMatch(One, expr, reg_opt)) LabelVS2->Text=LabelVS2->Text+" "+TRegEx::Match(One, expr, reg_opt).Groups[1].Value;

			break;
		}

		case 6: {
			LabelStatusS3->Text=L"������:";
			LabelMissionS3->Text=L"������:";
			LabelPlayersS3->Text=L"�������:";
			LabelMapS3->Text=L"�����:";
			LabelVS3->Text=L"������:";

			String One = ss->DataString;
			String expr = "\"State\":\"(.*?)\",";
			TRegExOptions reg_opt = TRegExOptions() << roIgnoreCase << roMultiLine;
			if (TRegEx::IsMatch(One, expr, reg_opt)) {
				String GameState;
				switch(StrToInt(TRegEx::Match(One, expr, reg_opt).Groups[1].Value)) {
					case -1: GameState = L"��� ������"; break;
					case 1: GameState = L"������ ����/����� ������"; break;
					case 3: GameState = L"�����/��������"; break;
					case 5: GameState = L"�������� ������"; break;
					case 6: GameState = L"�������"; break;
					case 7: GameState = L"���� ����"; break;
					case 9: GameState = L"���������"; break;
					case 12: GameState = L"���������"; break;
					case 13: GameState = L"�������"; break;
					case 14: GameState = L"���� ����"; break;
					default: GameState = L"����������"; break;
				}
				LabelStatusS3->Text=LabelStatusS3->Text+" "+GameState;
				GameState3=GameState;
			}

			expr = "\"Mission\":\"(.*?)\",";
			reg_opt = TRegExOptions() << roIgnoreCase << roMultiLine;
			if (TRegEx::IsMatch(One, expr, reg_opt)) {
				MissionStatus=TRegEx::Match(One, expr, reg_opt).Groups[1].Value;
				String Mission = "\""+TRegEx::Match(One, expr, reg_opt).Groups[1].Value+"\"";
				TJSONValue *JSON = TJSONObject::ParseJSONValue(TEncoding::UTF8->GetBytes(Mission), 0);
				LabelMissionS3->Text=LabelMissionS3->Text+" "+JSON->ToString();
			}

			String Players;

			expr = "\"PlayersNum\":(.*?),";
			reg_opt = TRegExOptions() << roIgnoreCase << roMultiLine;
			if (TRegEx::IsMatch(One, expr, reg_opt)) Players=TRegEx::Match(One, expr, reg_opt).Groups[1].Value;

			expr = "\"PlayersMax\":(.*?),";
			reg_opt = TRegExOptions() << roIgnoreCase << roMultiLine;
			if (TRegEx::IsMatch(One, expr, reg_opt)) LabelPlayersS3->Text=LabelPlayersS3->Text+" "+Players+"/"+TRegEx::Match(One, expr, reg_opt).Groups[1].Value;

			expr = "\"Island\":\"(.*?)\",";
			reg_opt = TRegExOptions() << roIgnoreCase << roMultiLine;
			if (TRegEx::IsMatch(One, expr, reg_opt)) LabelMapS3->Text=LabelMapS3->Text+" "+TRegEx::Match(One, expr, reg_opt).Groups[1].Value;

			expr = "\"Version\":\"(.*?)\",";
			reg_opt = TRegExOptions() << roIgnoreCase << roMultiLine;
			if (TRegEx::IsMatch(One, expr, reg_opt)) LabelVS3->Text=LabelVS3->Text+" "+TRegEx::Match(One, expr, reg_opt).Groups[1].Value;

			break;
		}

		//default:
		delete http;
	}
	return MissionStatus;
}

String __fastcall TMain::UnixTimeToTime(int UnixTime) {
	int Hours=UnixTime/3600;     // ����
	int Test = Hours*60;
	int Minute=UnixTime/60;
	String Target = IntToStr(Hours)+L"�. "+IntToStr(Minute-Test)+L"�.";
	return Target;

}

void __fastcall TMain::FormCreate(TObject *Sender)
{
	TIniFile *CfgIni = new TIniFile(System::Ioutils::TPath::GetDocumentsPath() + PathDelim + "SettingCfg.ini");
	MobileID=CfgIni->ReadString("ID", "MobileID",0);
	LabelNick->Text=CfgIni->ReadString("Prifile", "Nick", LabelNick->Text);
	LabelGroup->Text=CfgIni->ReadString("Prifile", "Group", LabelGroup->Text);
	LabelName->Text=CfgIni->ReadString("Prifile", "Name", LabelName->Text);
	LabelGUID->Text=CfgIni->ReadString("Prifile", "GUID", LabelGUID->Text);
	LabelID->Text=CfgIni->ReadString("Prifile", "ID", LabelID->Text);
	LabelSGTime->Text=CfgIni->ReadString("Prifile", "SGTime", LabelSGTime->Text);
	LabelMaceTime->Text=CfgIni->ReadString("Prifile", "mACE", LabelMaceTime->Text);
	LabelSide->Text=CfgIni->ReadString("Prifile", "Side", LabelSide->Text);
	LabelFirst->Text=CfgIni->ReadString("Prifile", "FirstMis", LabelFirst->Text);
	LabelLast->Text=CfgIni->ReadString("Prifile", "LastMis", LabelLast->Text);
	LabelReg->Text=CfgIni->ReadString("Prifile", "Reg", LabelReg->Text);

	SwitchServ1->IsChecked=CfgIni->ReadBool("Settings", "ServOn", false);
	SwitchServ2->IsChecked=CfgIni->ReadBool("Settings", "ServTw", false);
	SwitchServ3->IsChecked=CfgIni->ReadBool("Settings", "ServTr", false);
	SwitchFullScr->IsChecked=CfgIni->ReadBool("Settings", "FullScr", false);
	ComboBoxTime->ItemIndex=CfgIni->ReadInteger("Settings", "TimeOut", 1);

	delete CfgIni;

	TIdHTTP *http = new TIdHTTP(0);
	std::auto_ptr<TStringStream> ss (new TStringStream("", TEncoding::GetEncoding(1251), true));

	if (MobileID=="0") {

		try
		{
			IdHTTP1->Get("http://www.xn--c1adahg2atfb8hee9d.xn--p1ai/mobile_info.php?key=dsadas54sdgDF54cvdfghjsadf546&action=get_unique", ss.get());
		}
		catch(...)
		{
		} //<body style="zoom: 1;">55842F57BD1C5<pre></pre></body>

		String One = ss->DataString;
		String expr = "<meta charset=\"windows-1251\">(.*?)&";
		TRegExOptions reg_opt = TRegExOptions() << roIgnoreCase << roMultiLine;
		if (TRegEx::IsMatch(One, expr, reg_opt)) MobileID=TRegEx::Match(One, expr, reg_opt).Groups[1].Value;

		CfgIni = new TIniFile(System::Ioutils::TPath::GetDocumentsPath() + PathDelim + "SettingCfg.ini");
		CfgIni->WriteString("ID", "MobileID", MobileID);
		delete CfgIni;

		LabelNick->Text=L"������� ���� ���������� ����������� � ������� �� �����";
	}
	EditID->Text=MobileID;

}
//---------------------------------------------------------------------------

void __fastcall TMain::FormResize(TObject *Sender)
{
	RectangleSrv1->Width = Main->Width;
	RectangleSrv2->Width = Main->Width;
	RectangleSrv3->Width = Main->Width;
}
//---------------------------------------------------------------------------






void __fastcall TMain::RefreshServer1Click(TObject *Sender)
{
	HttpRefresh(0);
}
//---------------------------------------------------------------------------

void __fastcall TMain::RefreshServer2Click(TObject *Sender)
{
	HttpRefresh(1);
}
//---------------------------------------------------------------------------

void __fastcall TMain::RefreshServer3Click(TObject *Sender)
{
	HttpRefresh(2);
}
//---------------------------------------------------------------------------
void __fastcall TMain::ButtonMM1Click(TObject *Sender)
{
	TabControlMain->Visible=true;
	ButtonRefresh->Visible=true;
	Servers->Visible=false;
	MemoInfo->Visible=false;
	Settings->Visible=false;
	MultiView1->HideMaster();
}
//---------------------------------------------------------------------------
void __fastcall TMain::ButtonMM2Click(TObject *Sender)
{
	TabControlMain->Visible=false;
	ButtonRefresh->Visible=false;
	Servers->Visible=true;
	MemoInfo->Visible=false;
	Settings->Visible=false;
	MultiView1->HideMaster();
}
//---------------------------------------------------------------------------

void __fastcall TMain::ButtonMM3Click(TObject *Sender)
{
	TabControlMain->Visible=false;
	ButtonRefresh->Visible=false;
	Servers->Visible=false;
	MemoInfo->Visible=false;
	Settings->Visible=true;
	MultiView1->HideMaster();
}
//---------------------------------------------------------------------------

void __fastcall TMain::ButtonMM4Click(TObject *Sender)
{
	TabControlMain->Visible=false;
	ButtonRefresh->Visible=false;
	Servers->Visible=false;
	MemoInfo->Visible=true;
	Settings->Visible=false;
	MultiView1->HideMaster();
}

void __fastcall TMain::ButtonMM5Click(TObject *Sender)
{
	TabControlMain->Visible=false;
	ButtonRefresh->Visible=false;
	Servers->Visible=false;
	MemoInfo->Visible=false;
	Settings->Visible=false;
	MultiView1->HideMaster();
}
//---------------------------------------------------------------------------

void __fastcall TMain::ButtonSaveClick(TObject *Sender)
{
	TIniFile *CfgIni = new TIniFile(System::Ioutils::TPath::GetDocumentsPath() + PathDelim + "SettingCfg.ini");
	CfgIni->WriteBool("Settings", "ServOn", SwitchServ1->IsChecked);
	CfgIni->WriteBool("Settings", "ServTw", SwitchServ2->IsChecked);
	CfgIni->WriteBool("Settings", "ServTr", SwitchServ3->IsChecked);
	CfgIni->WriteBool("Settings", "FullScr", SwitchFullScr->IsChecked);
	CfgIni->WriteInteger("Settings", "TimeOut", ComboBoxTime->ItemIndex);
	delete CfgIni;

	ShowMessage(L"��������� ���������!");
}
//---------------------------------------------------------------------------

void __fastcall TMain::TimerRefreshTimer(TObject *Sender)
{
	if(SwitchServ3->IsChecked==false && SwitchServ2->IsChecked==false && SwitchServ1->IsChecked==false)
		TimerRefresh->Enabled=false;


	String NewMis1,NewMis2,NewMis3;

	if(SwitchServ1->IsChecked==true) {
		//ServerNumber=0;
		NewMis1=HttpRefresh(0);
	}
	if(SwitchServ2->IsChecked==true) {
		//ServerNumber=1;
		NewMis2=HttpRefresh(1);
	}
	if(SwitchServ3->IsChecked==true) {
		//ServerNumber=2;
		NewMis3=HttpRefresh(2);
	}

	if(NewMis1!=OldMissionS1 && GameState1 != "���� ����" && Srv1 > 0) {

		//if (NotificationCenter1->Supported()) {
			TNotification *myNotification = NotificationCenter1->CreateNotification();
			__try {
				myNotification->Name = "NotificationServ1";
				myNotification->AlertBody = L"������ �� ������� Arma 2 ���� ���������";
				myNotification->FireDate = Now();
				NotificationCenter1->ScheduleNotification(myNotification);
			}
			__finally {
				myNotification->DisposeOf();
			}

		//}
	}



	if(NewMis2!=OldMissionS2 && GameState2 != "���� ����" && Srv2 > 0) {
		//if (NotificationCenter1->Supported()) {
			TNotification *myNotification = NotificationCenter1->CreateNotification();
			__try {
				myNotification->Name = "NotificationServ2";
				myNotification->AlertBody = L"������ �� ������� 1(�3) ���� ���������";
				myNotification->FireDate = Now();
				NotificationCenter1->ScheduleNotification(myNotification);
			}
			__finally {
				myNotification->DisposeOf();
			}

		//}

	}
	if(NewMis3!=OldMissionS3 && GameState3 != "���� ����" && Srv3 > 0) {
		//if (NotificationCenter1->Supported()) {
			TNotification *myNotification = NotificationCenter1->CreateNotification();
			__try {
				myNotification->Name = "NotificationServ3";
				myNotification->AlertBody = L"������ �� ������� 2 (�3) ���� ���������";
				myNotification->FireDate = Now();
				NotificationCenter1->ScheduleNotification(myNotification);
			}
			__finally {
				myNotification->DisposeOf();
			}

		//}

	}
	if(SwitchServ1->IsChecked==true)
		Srv1++;
	if(SwitchServ2->IsChecked==true)
		Srv2++;
	if(SwitchServ3->IsChecked==true)
		Srv3++;
	OldMissionS1=NewMis1; OldMissionS2=NewMis2; OldMissionS3=NewMis3;
}
//---------------------------------------------------------------------------

void __fastcall TMain::SwitchServ1Switch(TObject *Sender)
{
	if(SwitchServ1->IsChecked==true)
		TimerRefresh->Enabled=true;
	else
		Srv1=0;
}
//---------------------------------------------------------------------------

void __fastcall TMain::SwitchServ2Switch(TObject *Sender)
{
	if(SwitchServ2->IsChecked==true)
		TimerRefresh->Enabled=true;
	else
		Srv2=0;
}
//---------------------------------------------------------------------------

void __fastcall TMain::SwitchServ3Switch(TObject *Sender)
{
	if(SwitchServ3->IsChecked==true)
		TimerRefresh->Enabled=true;
	else
		Srv3=0;
}
//---------------------------------------------------------------------------

void __fastcall TMain::SwitchFullScrSwitch(TObject *Sender)
{
	if(SwitchFullScr->IsChecked==true)
		Main->FullScreen=true;
	else
		Main->FullScreen=false;
}
//---------------------------------------------------------------------------

void __fastcall TMain::ComboBoxTimeChange(TObject *Sender)
{
	switch(ComboBoxTime->ItemIndex) {
		case 0: TimerRefresh->Interval=30*1000; break;
		case 1: TimerRefresh->Interval=60*1000; break;
		case 2: TimerRefresh->Interval=120*1000; break;
		case 3: TimerRefresh->Interval=180*1000; break;
		case 4: TimerRefresh->Interval=240*1000; break;
		case 5: TimerRefresh->Interval=300*1000; break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TMain::Image3Gesture(TObject *Sender, const TGestureEventInfo &EventInfo,
          bool &Handled)
{
	ShowMessage(L"�����������: Appi \n������: v3.0.0");
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

