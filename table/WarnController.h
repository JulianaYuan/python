//======================================================================
//                                                                    //
//              CONFIDENTIAL VISTEON CORPORATION                      // 
//                                                                    // 
// This is an unpublished work of authorship, which contains trade    // 
// secrets, created in 2019. Visteon Corporation owns all rights to   // 
// this work and intends to maintain it in confidence to preserve     //
// its trade secret status. Visteon Corporation reserves the right,   //
// under the copyright laws of the United States or those of any      //
// other country that may have jurisdiction, to protect this work     //
// as an unpublished work, in the event of an inadvertent or          //
// deliberate unauthorized publication. Visteon Corporation also      //
// reserves its rights under all copyright laws to protect this       //
// work as a published work, when appropriate. Those having access    //
// to this work may not copy it, use it, modify it or disclose the    //
// information contained in it without the written authorization      //
// of Visteon Corporation.                                            //
//                                                                    //
//======================================================================
//======================================================================
/// @File Name        :  warning.h 
/// @Module Name      :  warning
/// @Author           :  Nan Huaping
/// @Organization     :  DI Software, SVEC
/// @Description      :  Comments for module.
/// @Date             :  Jan/27/2019
//======================================================================
#ifndef __WARNING_CONTROLLER_H__
#define __WARNING_CONTROLLER_H__

// Kanzi Include
#include <kanzi/kanzi.hpp>
#include "Utility.h"
#include "KanziUtil.h"
#include "Controller.h"
#include "CommonProj.h"
#include "WarnData.h"

using namespace kanzi;

class WarnController : public Controller
{
public:
	//======================================================================
	/// @Function Name     :  TelltalePresentation 
	/// @Description       :  Comments for TelltalePresentation().
	/// @Parameters        :  None
	/// @Return            :  None
	/// @Critical Section  :  Constructor
	//======================================================================
	WarnController();

	//======================================================================
	/// @Function Name     :  TelltalePresentation 
	/// @Description       :  Comments for TelltalePresentation().
	/// @Parameters        :  None
	/// @Return            :  None
	/// @Critical Section  :  Destructor
	//======================================================================
	virtual ~WarnController();

public:
	//================================================
	/// @Function Name   :  init. 
	/// @Description        :  Controller init interface.
	/// @Parameters        :  None.
	/// @Return              :  bool.
	///                               (true: init successed, false: init failed)
	/// @Critical Section  :  None.
	//================================================
	virtual bool init();

	//================================================
	/// @Function Name   :  deinit. 
	/// @Description        :  Controller deinit interface.
	/// @Parameters        :  None.
	/// @Return              :  None.
	/// @Critical Section  :  None.
	//================================================
	virtual void deinit();

	//================================================
	/// @Function Name   :  onControl. 
	/// @Description        :  Process the common status for all sub update.
	/// @Parameters        :  None.
	/// @Return              :  void.
	/// @Critical Section  :  None.
	//================================================
	virtual void onControl();
	void onUpdateNoti();
	//door
	void onUpdateHoodStatus();
	void onUpdateTrunkStatus();
	void onUpdateACChargeLidStatus();
	void onUpdateDCChargeLidStatus();
	void onUpdateDriverDoorStatus();
	void onUpdatePassengerDoorStatus();
	void onUpdateDriverRearDoorStatus();
	void onUpdatePassengerRearDoorStatus();
	UInt getNotiId(void);
	U8 getPA_DIM_DriverDoorStatus(void);
	U8 getPA_DIM_PassengerDoorStatus(void);
	U8 getPA_DIM_DriverRearDoorStatus(void);
	U8 getPA_DIM_PassengerRearDoorStatus(void);
	U8 getPA_DIM_HoodStatus(void);
	U8 getPA_DIM_TrunkStatus(void);
	U8 getPA_DIM_TankFlapStatus(void);
	U8 getPA_DIM_ACChargeLidStatus(void);
	U8 getPA_DIM_DCChargeLidStatus(void);
	U8 getPA_DIM_ACandDCChargeLidStatus(void);
	//tpms
	void onUpdateLeFrntTireMsgMsgOldFlg();
	void onUpdateLeReTireMsgMsgOldFlg();
	void onUpdateRiFrntTireMsgMsgOldFlg();
	void onUpdateRiReTireMsgMsgOldFlg();

	void onUpdateLeFrntTireMsgPWarnFlg();
	void onUpdateRiFrntTireMsgPWarnFlg();
	void onUpdateLeReTireMsgPWarnFlg();
	void onUpdateRiReTireMsgPWarnFlg();

	void onUpdateLeFrntTireMsgTWarnFlg();
	void onUpdateLeReTireMsgTWarnFlg();
	void onUpdateRiFrntTireMsgTWarnFlg();
	void onUpdateRiReTireMsgTWarnFlg();

	void onUpdateLeFrntTireMsgSysWarnFlg();
	void onUpdateLeReTireMsgSysWarnFlg();
	void onUpdateRiFrntTireMsgSysWarnFlg();
	void onUpdateRiReTireMsgSysWarnFlg();

	void onUpdateLeFrntTireMsgFastLoseWarnFlg();
	void onUpdateLeReTireMsgFastLoseWarnFlg();
	void onUpdateRiFrntTireMsgFastLoseWarnFlg();
	void onUpdateRiReTireMsgFastLoseWarnFlg();

	void onUpdateLeFrntTireMsgBattLoSt();
	void onUpdateLeReTireMsgBattLoSt();
	void onUpdateRiFrntTireMsgBattLoSt();
	void onUpdateRiReTireMsgBattLoSt();

	U8 getLeFrntTireMsgMsgOldFlg(void);
	U8 getLeReTireMsgMsgOldFlg(void);
	U8 getRiFrntTireMsgMsgOldFlg(void);
	U8 getRiReTireMsgMsgOldFlg(void);

	U8 getLeFrntTireMsgPWarnFlg(void);
	U8 getRiFrntTireMsgPWarnFlg(void);
	U8 getLeReTireMsgPWarnFlg(void);
	U8 getRiReTireMsgPWarnFlg(void);

	U8 getLeFrntTireMsgTWarnFlg(void);
	U8 getLeReTireMsgTWarnFlg(void);
	U8 getRiFrntTireMsgTWarnFlg(void);
	U8 getRiReTireMsgTWarnFlg(void);

	U8 getLeFrntTireMsgSysWarnFlg(void);
	U8 getLeReTireMsgSysWarnFlg(void);
	U8 getRiFrntTireMsgSysWarnFlg(void);
	U8 getRiReTireMsgSysWarnFlg(void);

	U8 getLeFrntTireMsgFastLoseWarnFlg(void);
	U8 getLeReTireMsgFastLoseWarnFlg(void);
	U8 getRiFrntTireMsgFastLoseWarnFlg(void);
	U8 getRiReTireMsgFastLoseWarnFlg(void);

	U8 getLeFrntTireMsgBattLoSt(void);
	U8 getLeReTireMsgBattLoSt(void);
	U8 getRiFrntTireMsgBattLoSt(void);
	U8 getRiReTireMsgBattLoSt(void);
private:
	DISABLE_COPY_AND_ASSIGN(WarnController);

	int				mNotiId;
	WarnData*		mWarnDataPtr;

	U8 mDriverDoorStatus;
	U8 mPassengerDoorStatus;
	U8 mDriverRearDoorStatus;
	U8 mPassengerRearDoorStatus;
	U8 mHoodStatus;
	U8 mTrunkStatus;
	U8 mTankFlapStatus;
	U8 mACChargeLidStatus;
	U8 mDCChargeLidStatus;
	U8 mACandDCChargeLidStatus;
	U8 mDoorStatus;
	UInt preNotiId;
	UInt curNotiId;
	UInt displayNotiId;

	U8 mLeFrntTireMsgMsgOldFlg;
	U8 mLeReTireMsgMsgOldFlg;
	U8 mRiFrntTireMsgMsgOldFlg;
	U8 mRiReTireMsgMsgOldFlg;

	U8 mLeFrntTireMsgPWarnFlg;
	U8 mRiFrntTireMsgPWarnFlg;
	U8 mLeReTireMsgPWarnFlg;
	U8 mRiReTireMsgPWarnFlg;

	U8 mLeFrntTireMsgTWarnFlg;
	U8 mLeReTireMsgTWarnFlg;
	U8 mRiFrntTireMsgTWarnFlg;
	U8 mRiReTireMsgTWarnFlg;

	U8 mLeFrntTireMsgSysWarnFlg;
	U8 mLeReTireMsgSysWarnFlg;
	U8 mRiFrntTireMsgSysWarnFlg;
	U8 mRiReTireMsgSysWarnFlg;

	U8 mLeFrntTireMsgFastLoseWarnFlg;
	U8 mLeReTireMsgFastLoseWarnFlg;
	U8 mRiFrntTireMsgFastLoseWarnFlg;
	U8 mRiReTireMsgFastLoseWarnFlg;

	U8 mLeFrntTireMsgBattLoSt;
	U8 mLeReTireMsgBattLoSt;
	U8 mRiFrntTireMsgBattLoSt;
	U8 mRiReTireMsgBattLoSt;
};

#define ALL_NOTI_NUM (sizeof(allNotiTable) / sizeof(sNotiArr))
#define ALL_PA_NOTI_NUM 497
static sNotiArr allNotiTable[] =
{
#if 1
	/***0***/{   0, " ", 	" ", 	" ", 	  0, 	  0},
	/* list start */
	/***1***/{   1, "Front Camera blocked\nSee detailes in\ncenter stack display", 	"前视摄像头遮挡\n请在显示屏查看受限功能", 	"kzb://kanzi_launch/Textures/Noti/icon4", 	  2, 	  1},

	/***2***/{   2, "Front Camera limited\nSee detailes in\ncenter stack display", 	"前视摄像头功能受限\n请在显示屏查看功能状态", 	"kzb://kanzi_launch/Textures/Noti/icon120", 	  2, 	  1},

	/***3***/{   3, "Rear Side Radar blocked\nSee detailes in\ncenter stack display", 	"侧后方雷达遮挡\n请在显示屏查看受限功能", 	"kzb://kanzi_launch/Textures/Noti/icon333", 	  2, 	  1},

	/***4***/{   4, "Rear Side Radar limited\nSee detailes in\ncenter stack display", 	"侧后方雷达功能受限\n请在显示屏查看受限功能", 	"kzb://kanzi_launch/Textures/Noti/icon334", 	  2, 	  1},

	/***5***/{   7, "Front Radar blocked\nSeedetailes in\ncenter stack display", 	"前雷达遮挡\n请在显示屏查看功能状态", 	"kzb://kanzi_launch/Textures/Noti/icon316", 	  2, 	  1},

	/***6***/{   8, "Front Radar limited\nSee detailes in\ncenter stack display", 	"前雷达受限\n请在显示屏查看功能状态", 	"kzb://kanzi_launch/Textures/Noti/icon212", 	  2, 	  1},

	/***7***/{   9, "Front side radar blocked\nSeedetailes in\ncenter stack display", 	"侧前方雷达遮挡\n请在显示屏查看功能状态", 	"kzb://kanzi_launch/Textures/Noti/icon331", 	  2, 	  1},

	/***8***/{  10, "Front side radar limited\nSee detailes in\ncenter stack display", 	"侧前方雷达受限\n请在显示屏查看功能状态", 	"kzb://kanzi_launch/Textures/Noti/icon332", 	  2, 	  1},

	/***9***/{  30, "Please brake ", 	"请制动", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  1, 	  1},

	/**10***/{  31, "Keep safety distance!", 	"请保持安全车距", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  1, 	  1},

	/**11***/{  32, "Emergency brake activated", 	"紧急制动功能已激活", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  1, 	  1},

	/**12***/{  33, "Be cautious when open the door", 	"开门请注意", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  1},

	/**13***/{  34, "Be cautious when open the door", 	"开门请注意", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  1},

	/**14***/{  35, "Be cautious when open the door", 	"开门请注意", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  1},

	/**15***/{  36, "Distractive\nPlease drive carefully", 	"请集中注意力\n谨慎驾驶", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  0},

	/**16***/{  37, "Please drive carefully", 	"您已疲劳\n请谨慎驾驶", 	"kzb://kanzi_launch/Textures/Noti/icon66", 	  2, 	  0},

	/**17***/{  38, "Please have a rest\nNavigate to the nearest road stop?", 	"您已疲劳\n请注意休息\n是否导航到最近休息区", 	"kzb://kanzi_launch/Textures/Noti/icon66", 	  2, 	  0},

	/**18***/{  39, "Driver Alert\nTime for a break", 	"您已疲劳\n请注意休息", 	"kzb://kanzi_launch/Textures/Noti/icon66", 	  2, 	  0},

	/**19***/{  40, "Drive in emergency lane", 	"您已占用应急车道", 	"kzb://kanzi_launch/Textures/Noti/icon353", 	  2, 	  1},

	/**20***/{  41, "Alert!\nDrive in emergency lane\nPlease change lanes", 	"危险！\n请尽快驶离应急车道", 	"kzb://kanzi_launch/Textures/Noti/icon353", 	  2, 	  0},

	/**21***/{  42, "Attention!\nEmergency lane parking", 	"应急车道停车\n请注意安全", 	"kzb://kanzi_launch/Textures/Noti/icon353", 	  2, 	  1},

	/**22***/{  43, "Emergency steering assist\nActivated", 	"紧急转向辅助已激活", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  1},

	/**23***/{  44, "Attention!\nLeft side crossing vehicle", 	"请注意左侧来车", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  1},

	/**24***/{  45, "Attention!\nRight side crossing vehicle", 	"请注意右侧来车", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  1},

	/**25***/{  46, "Auto brake activated", 	"紧急制动功能已激活", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  1, 	  1},

	/**26***/{  47, "Auto brake activated", 	"紧急制动功能已激活", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  1, 	  1},

	/**27***/{  68, "Emergency lane keep aid\nActivated", 	"紧急车道保持辅助\n已激活", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  0},

	/**28***/{  69, "Lane Keep Assist canceled\nDue to hands off", 	"车道保持辅助已取消\n手未握住方向盘", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  1},

	/**29***/{  70, "Please hold the\nSteering wheel", 	"请手握方向盘", 	"kzb://kanzi_launch/Textures/Noti/icon68", 	  1, 	  0},

	/**30***/{  71, "Please hold the\nSteering wheel", 	"请手握方向盘", 	"kzb://kanzi_launch/Textures/Noti/icon68", 	  1, 	  0},

	/**31***/{  72, "CoPilot canceled", 	"CoPilot功能已退出", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  0},

	/**32***/{  73, "CoPilot canceled\nNot take over in time", 	"CoPilot功能退出\n未及时接管", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  0},

	/**33***/{  89, "Parking emergency brake activated\nPress brake pedal to release", 	"低速紧急制动功能\n已激活\n请踩刹车解除", 	"kzb://kanzi_launch/Textures/Noti/icon15", 	  2, 	  1},

	/**34***/{  90, "Parking emergency brake unavailable\nHeavy rain!", 	"低速紧急制动功能受限\n雨量过大", 	"kzb://kanzi_launch/Textures/Noti/icon330", 	  2, 	  1},

	/**35***/{  91, "Front emergency brake\nSystem fault\nDrive carefully", 	"前低速紧急制动系统失效\n请谨慎驾驶", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  1},

	/**36***/{  92, "Rear emergency brake\nSystem fault\nDrive carefully", 	"后低速紧急制动系统失效\n请谨慎驾驶", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  1},

	/**37***/{  93, "Low battery voltage\nPlease stop safely\nService required", 	"蓄电池电压过低\n请安全停车\n请联系当地经销商", 	"kzb://kanzi_launch/Textures/Noti/icon33", 	  1, 	  0},

	/**38***/{  94, "Charging failure\nPlease stop safely\nService required", 	"充电故障\n请安全停车\n请联系当地经销商", 	"kzb://kanzi_launch/Textures/Noti/icon33", 	  1, 	  1},

	/**39***/{  95, "Low voltage battery system fault\nService urgent", 	"12V系统故障\n急需维修", 	"kzb://kanzi_launch/Textures/Noti/icon33", 	  2, 	  1},

	/**40***/{  96, "Low voltage battery level low\nPlease start engine ", 	"蓄电池电量过低\n请启动车辆", 	"kzb://kanzi_launch/Textures/Noti/icon344", 	  2, 	  1},

	/**41***/{  97, "Low voltage battery level low\nFunction limited", 	"蓄电池电量低\n功能受限", 	"kzb://kanzi_launch/Textures/Noti/icon33", 	  2, 	  1},

	/**42***/{  98, "Factory mode", 	"工厂模式", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  1},

	/**43***/{  99, "Exit factory mode", 	"工厂模式退出", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  1},

	/**44***/{ 100, "Transport mode", 	"运输模式", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  1},

	/**45***/{ 101, "Exit transport mode", 	"运输模式退出", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  1},

	/**46***/{ 102, "Norm mode", 	"用户模式", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  1},

	/**47***/{ 103, "Crash mode", 	"碰撞模式", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  1},

	/**48***/{ 104, "Changing car mode\nto dyno mode\nContinue?", 	"正将车辆模式更改\n为测功模式\n继续？", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  1, 	  1},

	/**49***/{ 108, "No valid key found", 	"未检测到有效钥匙", 	"kzb://kanzi_launch/Textures/Noti/icon70", 	  2, 	  0},

	/**50***/{ 111, "Vehicle is active\nReady to drive", 	"车辆已启动\n准备出发", 	"kzb://kanzi_launch/Textures/Noti/icon343", 	  2, 	  1},

	/**51***/{ 112, "Ignition on", 	"点火开关打开", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  0},

	/**52***/{ 113, "Select P or N\nto start the vehicle", 	"请选择P挡或N挡\n启动车辆", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  0},

	/**53***/{ 114, "Shift to N position\nto start the vehicle", 	"请换至N挡启动车辆", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  0},

	/**54***/{ 115, "Press Clutch Pedal\nto start the vehicle", 	"请踩下离合器踏板\n启动车辆", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  0},

	/**55***/{ 116, "Press Brake Pedal\nto start the vehicle", 	"请踩下制动踏板\n启动车辆", 	"kzb://kanzi_launch/Textures/Noti/icon346", 	  2, 	  0},

	/**56***/{ 117, "Turn and hold start knob\nTo turn vehicle off", 	"请转动启动旋钮\n将车辆熄火", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  0},

	/**57***/{ 118, "Hold start button\nto turn off\nthe vehicle", 	"请长按启动按钮\n将车辆熄火", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  0},

	/**58***/{ 119, "Turn start knob\nTo start vehicle", 	"请转动启动旋钮\n启动车辆", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  0},

	/**59***/{ 120, "Press start button\nto start the vehicle", 	"请按下启动按钮\n启动车辆", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  0},

	/**60***/{ 121, "System check\nPlease wait", 	"系统正在自检中\n请等待", 	"kzb://kanzi_launch/Textures/Noti/icon346", 	  2, 	  0},

	/**61***/{ 122, "Select P\nto turn off\nthe vehicle", 	"选择P挡将车辆熄火", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  0},

	/**62***/{ 123, "Hold start knob\nTo turn off vehicle", 	"请转动启动旋钮\n将车辆熄火", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  0},

	/**63***/{ 124, "Hold start button\nTo turn off vehicle", 	"请长按启动按钮\n将车辆熄火", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  0},

	/**64***/{ 125, "Charge Cable connected\nRemove before start", 	"充电电缆已连接\n请在启动前拔下", 	"kzb://kanzi_launch/Textures/Noti/icon44", 	  2, 	  0},

	/**65***/{ 126, "Charge cable\nstill connected.\nHold start button\n7s to force start", 	"确认已拔除充电电缆\n保持启动旋钮7秒\n启动车辆", 	"kzb://kanzi_launch/Textures/Noti/icon44", 	  2, 	  0},

	/**66***/{ 127, "Charge cable\nstill connected.\nHold start button\n7s to force start.", 	"确认已拔除充电电缆\n按下启动按钮7秒\n启动车辆", 	"kzb://kanzi_launch/Textures/Noti/icon44", 	  2, 	  0},

	/**67***/{ 128, "Charge Cable connected\nRemove before start", 	"确认已拔除充电电缆\n启动车辆", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  0},

	/**68***/{ 130, "Engine Remote Start\nActivated by Key", 	"发动机远程启动\n已通过钥匙激活", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  1},

	/**69***/{ 131, "Engine Remote Start\nActivated by Phone", 	"发动机远程启动\n已通过手机APP激活", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  1},

	/**70***/{ 132, "No Engine Remote\nStart\nLow coolant level", 	"发动机远程启动\n无法激活\n冷却液液位过低", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  1},

	/**71***/{ 133, "No Engine Remote\nStart\nGear not in P", 	"发动机远程启动\n无法激活\n未挂入P挡", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  1},

	/**72***/{ 134, "No Engine Remote\nStart\nLow fuel level", 	"发动机远程启动\n无法激活\n燃油油位过低", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  1},

	/**73***/{ 135, "No Engine Remote\nStart\nKey or user in vehicle", 	"发动机远程启动\n无法激活\n钥匙或用户在车内", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  1},

	/**74***/{ 136, "No Engine Remote\nStart\nStarts limit reached", 	"发动机远程启动\n无法激活\n已达到最大启动次数", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  1},

	/**75***/{ 137, "No Engine Remote Start\nWorkshop Mode", 	"发动机远程启动\n无法激活\n维修模式", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  1},

	/**76***/{ 138, "No Engine Remote\nStart\nEngine fault", 	"发动机远程启动\n无法激活\n发动机故障", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  1},

	/**77***/{ 139, "No Engine Remote\nStart\nHood or door open", 	"发动机远程启动\n无法激活\n发动机罩或车门开启", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  1},

	/**78***/{ 140, "No Engine Remote Start", 	"发动机远程启动\n无法激活", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  1},

	/**79***/{ 141, "Engine temp\nhigh\nReduce speed", 	"发动机温度过高\n请减速慢行", 	"kzb://kanzi_launch/Textures/Noti/icon21", 	  2, 	  1},

	/**80***/{ 142, "Engine temp\nhigh\nStop safely", 	"发动机温度过高\n请安全停车", 	"kzb://kanzi_launch/Textures/Noti/icon21", 	  1, 	  1},

	/**81***/{ 143, "Engine temp\nhigh\nStop Engine", 	"发动机温度过高\n请停车并熄火", 	"kzb://kanzi_launch/Textures/Noti/icon21", 	  1, 	  1},

	/**82***/{ 144, "Engine temp\nhigh\nSee user manual", 	"发动机温度过高\n请参阅用户手册", 	"kzb://kanzi_launch/Textures/Noti/icon21", 	  2, 	  1},

	/**83***/{ 145, "Coolant Level low\nStop Engine", 	"冷却液液位过低\n请停车并熄火", 	"kzb://kanzi_launch/Textures/Noti/icon114", 	  1, 	  1},

	/**84***/{ 146, "Coolant Level low\nStop safely", 	"冷却液液位过低\n请安全停车", 	"kzb://kanzi_launch/Textures/Noti/icon114", 	  1, 	  1},

	/**85***/{ 147, "Coolant Level low\nSee user manual", 	"冷却液液位过低\n请参阅用户手册", 	"kzb://kanzi_launch/Textures/Noti/icon114", 	  2, 	  1},

	/**86***/{ 148, "Coolant Level low\nCheck level", 	"冷却液液位过低\n请检查液位", 	"kzb://kanzi_launch/Textures/Noti/icon114", 	  2, 	  1},

	/**87***/{ 149, "Coolant System\nService required", 	"冷却系统异常\n请联系当地经销商", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  1},

	/**88***/{ 150, "48V battery\nCooling system fault\nService required", 	"48V电池冷却\n系统故障\n请联系当地经销商", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  1, 	  1},

	/**89***/{ 151, "High voltage battery system\nService required", 	"高压电池系统故障\n请联系当地经销商", 	"kzb://kanzi_launch/Textures/Noti/icon85", 	  2, 	  1},

	/**90***/{ 152, "Electric drive system\nService required", 	"电机系统故障\n请联系当地经销商", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  1},

	/**91***/{ 153, "Child lock\nLeft door locked", 	"儿童锁\n左侧车门已锁止", 	"kzb://kanzi_launch/Textures/Noti/icon312", 	  2, 	  0},

	/**92***/{ 154, "Child lock\nLeft door unlocked", 	"儿童锁\n左侧车门已解锁", 	"kzb://kanzi_launch/Textures/Noti/icon313", 	  2, 	  0},

	/**93***/{ 155, "Child lock\nRight door locked", 	"儿童锁\n右侧车门已锁止", 	"kzb://kanzi_launch/Textures/Noti/icon314", 	  2, 	  0},

	/**94***/{ 156, "Child lock\nRight door unlocked", 	"儿童锁\n右侧车门已解锁", 	"kzb://kanzi_launch/Textures/Noti/icon315", 	  2, 	  0},

	/**95***/{ 157, "Hide handle fault\nService required", 	"隐藏门把手异常\n请联系当地经销商", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  1},

	/**96***/{ 158, "Tailgate stops abnormally\nCheck obstacles", 	"后背门异常停止\n请检查障碍物", 	"kzb://kanzi_launch/Textures/Noti/icon322", 	  2, 	  1},

	/**97***/{ 159, "Obstacles detected\nplease be careful", 	"检测到障碍物\n请注意", 	"kzb://kanzi_launch/Textures/Noti/icon321", 	  2, 	  1},

	/**98***/{ 160, "Cinch latch have malfunction\nplease repair it", 	"吸合锁故障\n请及时维修", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  1},

	/**99***/{ 160, "Cinch latch have malfunction\nplease repair it", 	"吸合锁故障\n请及时维修", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  1},

	/**100**/{ 161, "Power door can't open\nBattery low", 	"电动门无法开启\n车辆电量不足", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  0},

	/**101**/{ 162, "Power door can't open\nDue to driving", 	"电动门无法开启\n车辆行驶中", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  0},

	/**102**/{ 163, "Power door can't open\nAvoid hill parking", 	"电动门无法开启\n停靠坡度过大", 	"kzb://kanzi_launch/Textures/Noti/icon321", 	  2, 	  1},

	/**103**/{ 164, "Power door can't open\nAvoid hill parking", 	"电动门无法开启\n停靠坡度过大", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  0},

	/**104**/{ 165, "Power door can't open\nGear not in P", 	"电动门无法开启\n请切换至P挡", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  0},

	/**105**/{ 166, "Driver seat sensor abnormal\nPlease check", 	"主驾座椅传感器异常\n请检查", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  0},

	/**106**/{ 167, "Home Safety Light\nactivated", 	"伴我回家灯亮起", 	"kzb://kanzi_launch/Textures/Noti/icon346", 	  2, 	  0},

	/**107**/{ 168, "AFS system fault\nService required", 	"自适应前照灯系统故障\n请联系当地经销商", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  1},

	/**108**/{ 169, "Position Light fault\nPlease check", 	"请检查前后位置灯", 	"kzb://kanzi_launch/Textures/Noti/icon323", 	  2, 	  1},

	/**109**/{ 170, "Front High Beam fault", 	"请检查远光灯", 	"kzb://kanzi_launch/Textures/Noti/icon324", 	  2, 	  1},

	/**110**/{ 171, "Front Low Beam fault", 	"请检查近光灯", 	"kzb://kanzi_launch/Textures/Noti/icon325", 	  2, 	  1},

	/**111**/{ 172, "DBL system fault\nService required", 	"弯道照明系统故障\n请联系当地经销商", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  0},

	/**112**/{ 173, "Head lamp leveling\nSystem fault\nService required", 	"大灯高度调节\n系统故障\n请联系当地经销商", 	"kzb://kanzi_launch/Textures/Noti/icon326", 	  2, 	  1},

	/**113**/{ 174, "External traffic light\nSet to left side mode", 	"外部灯光系统\n左侧驾驶模式", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  0},

	/**114**/{ 175, "External traffic light\nSet to right side mode", 	"外部灯光系统\n右侧驾驶模式", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  0},

	/**115**/{ 176, "Brake failure\nStop safely", 	"制动器故障\n请安全停车", 	"kzb://kanzi_launch/Textures/Noti/icon126", 	  1, 	  1},

	/**116**/{ 177, "ABS and ESC\nService required", 	"ABS和ESC异常\n请减速慢行\n请联系当地经销商", 	"kzb://kanzi_launch/Textures/Noti/icon126", 	  2, 	  1},

	/**117**/{ 178, "ABS and ESC\ntemporarily\nunavailable", 	"ABS和ESC系统\n暂时不可用\n请减速慢行", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  0},

	/**118**/{ 179, "ESC\nService required", 	"ESC异常\n请减速慢行\n请联系当地经销商", 	"kzb://kanzi_launch/Textures/Noti/icon60", 	  2, 	  0},

	/**119**/{ 180, "ESC temporarily unavailable", 	"ESC暂时不可用\n请减速慢行", 	"kzb://kanzi_launch/Textures/Noti/icon60", 	  2, 	  0},

	/**120**/{ 181, "Traction Control temporarily unavailable", 	"制动盘温度过高\n请谨慎驾驶", 	"kzb://kanzi_launch/Textures/Noti/icon60", 	  2, 	  1},

	/**121**/{ 183, "Brake System\nService required", 	"制动性能减弱\n真空度过低\n需要维修", 	"kzb://kanzi_launch/Textures/Noti/icon23", 	  2, 	  1},

	/**122**/{ 184, "Auto Hold\nService required", 	"自动驻车系统\n需要维修", 	"kzb://kanzi_launch/Textures/Noti/icon108", 	  2, 	  1},

	/**123**/{ 185, "Press Brake Pedal\nto disable\nAuto Hold", 	"请踩下制动踏板\n可解除AUTOHOLD", 	"kzb://kanzi_launch/Textures/Noti/icon15", 	  2, 	  0},

	/**124**/{ 186, "Fasten seat belt\nor close driver door\nto enable Auto Hold", 	"请系紧安全带\n或关闭驾驶员车门\n以启用自动驻车系统", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  0},

	/**125**/{ 187, "Auto Hold failure\nPress Brake Pedal", 	"自动驻车失效\n请踩下制动踏板", 	"kzb://kanzi_launch/Textures/Noti/icon15", 	  1, 	  0},

	/**126**/{ 188, "Autobrake activated", 	"自动制动功能激活", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  0},

	/**127**/{ 189, "Parking Brake not released", 	"EPB电子驻车功能\n未释放", 	"kzb://kanzi_launch/Textures/Noti/icon46", 	  2, 	  0},

	/**128**/{ 190, "Parking Brake\ncannot hold vehicle", 	"EPB电子驻车功能\n无法驻车\n请驶离当前环境", 	"kzb://kanzi_launch/Textures/Noti/icon57", 	  2, 	  0},

	/**129**/{ 191, "Parking Brake\nnot fully released", 	"EPB电子驻车功能\n未完全释放", 	"kzb://kanzi_launch/Textures/Noti/icon57", 	  2, 	  0},

	/**130**/{ 192, "Parking Brake\nnot applied", 	"EPB电子驻车功能\n未完全夹紧", 	"kzb://kanzi_launch/Textures/Noti/icon57", 	  2, 	  1},

	/**131**/{ 193, "Press brake pedal\nto release\nparking brake", 	"请踩下制动踏板\n以释放\nEPB电子驻车功能", 	"kzb://kanzi_launch/Textures/Noti/icon15", 	  2, 	  0},

	/**132**/{ 194, "Parking Brake\nService required", 	"EPB电子驻车功能\n异常\n请联系当地经销商", 	"kzb://kanzi_launch/Textures/Noti/icon57", 	  2, 	  0},

	/**133**/{ 195, "Parking Brake\ntemporarily\ninterrupted", 	"EPB电子驻车功能\n暂时停用", 	"kzb://kanzi_launch/Textures/Noti/icon46", 	  2, 	  0},

	/**134**/{ 196, "Use Parking Brake\ncontrol to release\nParking Brake", 	"请按下\nEPB电子驻车开关\n释放驻车制动器", 	"kzb://kanzi_launch/Textures/Noti/icon46", 	  2, 	  0},

	/**135**/{ 197, "Parking Brake applied\nAutomatic adjustments", 	"EPB电子驻车功能\n自动调节盘片间隙\n请等待", 	"kzb://kanzi_launch/Textures/Noti/icon46", 	  2, 	  0},

	/**136**/{ 198, "Test Mode activated\nParking Brake roller\nbench", 	"测试模式激活\nEPB电子驻车功能\n用于滚筒试验台", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  0},

	/**137**/{ 199, "Release Parking\nBrake or fasten\nseat belt ", 	"释放\nEPB电子驻车功能\n或系紧安全带", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  0},

	/**138**/{ 200, "EPB motor overheat\nDo not apply frequently", 	"EPB电子驻车功能\n电机过热\n请勿频繁操作电子驻车", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  1},

	/**139**/{ 204, "Hill Descent Control\ntemporarily unavailable", 	"陡坡缓降功能\n暂时退出\n制动盘过热", 	"kzb://kanzi_launch/Textures/Noti/icon6", 	  2, 	  0},

	/**140**/{ 206, "Brake Fluid Level low\nPlease check", 	"制动液位过低\n请检查", 	"kzb://kanzi_launch/Textures/Noti/icon126", 	  2, 	  1},

	/**141**/{ 207, "Current drive mode\nRestricted Vehicle stability ", 	"该模式下车辆稳定性降低", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  0},

	/**142**/{ 208, "Steering Assist System\nService required", 	"转向辅助系统异常\n请联系当地经销商", 	"kzb://kanzi_launch/Textures/Noti/icon125", 	  2, 	  1},

	/**143**/{ 209, "Steering Assist\nmalfunction\nStop safely", 	"转向辅助系统异常\n请安全停车", 	"kzb://kanzi_launch/Textures/Noti/icon125", 	  1, 	  1},

	/**144**/{ 210, "Steering Assist System\nService urgent", 	"转向辅助系统异常\n请联系当地经销商", 	"kzb://kanzi_launch/Textures/Noti/icon125", 	  2, 	  1},

	/**145**/{ 211, "Steering Assist\ntemporarily\nreduced", 	"转向辅助系统性能暂时减弱", 	"kzb://kanzi_launch/Textures/Noti/icon71", 	  2, 	  1},

	/**146**/{ 212, "Steering Assist System\nService required", 	"方向盘无法调节\n请联系当地经销商", 	"kzb://kanzi_launch/Textures/Noti/icon14", 	  2, 	  1},

	/**147**/{ 213, "Rear Suspension\nadjustment button pressed\nPlease check", 	"请检查\n后悬架调节开关是否被按压\n后悬架调节功能关闭", 	"kzb://kanzi_launch/Textures/Noti/icon100", 	  2, 	  1},

	/**148**/{ 214, "Air suspension temporary\nUnavaliable\nCompressor overheat", 	"空气悬架性能暂时降低\n压缩机过热", 	"kzb://kanzi_launch/Textures/Noti/icon56", 	  2, 	  1},

	/**149**/{ 215, "Air suspension system fault\nDrive carefully\nService required", 	"空气悬架系统异常\n请减速慢行就近售后维修店", 	"kzb://kanzi_launch/Textures/Noti/icon56", 	  2, 	  1},

	/**150**/{ 216, "Air suspension system fault\nStop safely\nService required", 	"空气悬架系统故障\n请立即安全停车\n请联系当地经销商", 	"kzb://kanzi_launch/Textures/Noti/icon56", 	  1, 	  1},

	/**151**/{ 217, "Air suspension too high\nSlow down", 	"空气悬架过高\n请减速慢行", 	"kzb://kanzi_launch/Textures/Noti/icon56", 	  2, 	  1},

	/**152**/{ 218, "Air suspension too Low\nSlow down", 	"空气悬架过低\n请减速慢行", 	"kzb://kanzi_launch/Textures/Noti/icon56", 	  2, 	  1},

	/**153**/{ 219, "Tire pressure low", 	"轮胎胎压过低", 	"kzb://kanzi_launch/Textures/Noti/icon28", 	  7, 	  1},

	/**154**/{ 220, "Tire temp high", 	"轮胎温度过高", 	"kzb://kanzi_launch/Textures/Noti/icon28", 	  7, 	  1},

	/**155**/{ 221, "TPMS system fault\nService required", 	"胎压监测系统故障\n请维修", 	"kzb://kanzi_launch/Textures/Noti/icon28", 	  2, 	  1},

	/**156**/{ 222, "Tire fast leaking", 	"轮胎正在漏气", 	"kzb://kanzi_launch/Textures/Noti/icon28", 	  7, 	  1},

	/**157**/{ 223, "TPMS Sensor battery low\nService required", 	"胎压传感器电量低\n请联系当地经销商", 	"kzb://kanzi_launch/Textures/Noti/icon28", 	  7, 	  1},

	/**158**/{ 232, "Towbar unlocked\nDrive carefully", 	"拖车钩已解锁\n请谨慎驾驶", 	"kzb://kanzi_launch/Textures/Noti/icon18", 	  1, 	  1},

	/**159**/{ 241, "Face regist successful", 	"人脸信息注册成功", 	"kzb://kanzi_launch/Textures/Noti/icon345", 	  2, 	  0},

	/**160**/{ 242, "Face regist failure\nPlease try again", 	"人脸信息注册失败\n请重新注册", 	"kzb://kanzi_launch/Textures/Noti/icon345", 	  2, 	  0},

	/**161**/{ 243, "Please look at\nFront camera", 	"人脸信息注册中\n请注视摄像头", 	"kzb://kanzi_launch/Textures/Noti/icon345", 	  2, 	  0},

	/**162**/{ 244, "Face recognition failed", 	"人脸识别失败", 	"kzb://kanzi_launch/Textures/Noti/icon345", 	  2, 	  0},

	/**163**/{ 245, "Face recognition succeeded", 	"人脸识别成功", 	"kzb://kanzi_launch/Textures/Noti/icon345", 	  2, 	  0},

	/**164**/{ 248, "Book time for maintenance", 	"请预约保养", 	"kzb://kanzi_launch/Textures/Noti/icon43", 	  2, 	  1},

	/**165**/{ 249, "Time for\nregular\nmaintenance", 	"请执行定期保养", 	"kzb://kanzi_launch/Textures/Noti/icon43", 	  2, 	  1},

	/**166**/{ 250, "Maintenance overdue", 	"保养已过期", 	"kzb://kanzi_launch/Textures/Noti/icon43", 	  2, 	  1},

	/**167**/{ 252, "动力电池电量低", 	"High voltage battery low", 	"kzb://kanzi_launch/Textures/Noti/icon84", 	  2, 	  0},

	/**168**/{ 255, "/", 	"/", 	"kzb://kanzi_launch/Textures/Noti/icon", 	  0, 	  2},

	/**169**/{ 260, "/", 	"/", 	"kzb://kanzi_launch/Textures/Noti/icon", 	  0, 	  2},

	/**170**/{ 265, "HV battery out of\nthermal control\nleave the car\nimmediately", 	"动力电池热失控\n请立即远离车辆\n拨打救援电话", 	"kzb://kanzi_launch/Textures/Noti/icon85", 	  1, 	  1},

	/**171**/{ 266, "High voltage system\nSelf-checking", 	"动力系统自检中\n请等待", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  0},

	/**172**/{ 267, "Power system fault\nCan not drive\nService required", 	"动力系统故障\n无法行车\n请联系当地经销商", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  1, 	  1},

	/**173**/{ 268, "Power system fault\nStop safely\nService required", 	"动力系统故障\n请立即安全停车\n请联系当地经销商", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  1, 	  1},

	/**174**/{ 269, "Edrive system fault\nStop safely\nService required", 	"驱动系统故障\n请立即安全停车\n请联系当地经销商", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  1, 	  1},

	/**175**/{ 270, "Power system fault\nCan not start again\nService required", 	"动力系统故障\n无法重新启动\n请联系当地经销商", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  1},

	/**176**/{ 271, "Power limited\nDrive carefully\nService required", 	"动力受限\n请谨慎驾驶\n请联系当地经销商", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  1},

	/**177**/{ 272, "Edrive system harsh behavior\nService required", 	"低速动力异常\n需要维修", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  0},

	/**178**/{ 273, "Power system fault\nCan not charge\nService required", 	"动力系统故障\n无法充电\n请联系当地经销商", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  1, 	  0},

	/**179**/{ 274, "Power system fault\nService required", 	"动力系统异常\n请联系当地经销商", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  1},

	/**180**/{ 276, "/", 	"/", 	"kzb://kanzi_launch/Textures/Noti/icon", 	  0, 	  2},

	/**181**/{ 277, "/", 	"/", 	"kzb://kanzi_launch/Textures/Noti/icon", 	  0, 	  2},

	/**182**/{ 283, "High voltage battery fault\nService required", 	"动力电池故障\n需要维修", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  1},

	/**183**/{ 285, "Don't forget your phone", 	"您的手机仍然在车内", 	"kzb://kanzi_launch/Textures/Noti/icon304", 	  2, 	  1},

	/**184**/{ 286, "Pedestrian protection\nsystem triggered", 	"行人保护系统触发", 	"kzb://kanzi_launch/Textures/Noti/icon88", 	  2, 	  0},

	/**185**/{ 287, "Pedestrian protection\nsystem fault\nService required", 	"行人保护系统异常\n请联系当地经销商", 	"kzb://kanzi_launch/Textures/Noti/icon88", 	  2, 	  1},

	/**186**/{ 288, "SRS\nService urgent", 	"安全气囊异常\n请联系当地经销商", 	"kzb://kanzi_launch/Textures/Noti/icon337", 	  2, 	  1},

	/**187**/{ 289, "Passenger Airbag\nON", 	"乘客安全气囊已激活", 	"kzb://kanzi_launch/Textures/Noti/icon132", 	  2, 	  0},

	/**188**/{ 290, "Passenger Airbag\nOFF", 	"乘客安全气囊已停用", 	"kzb://kanzi_launch/Textures/Noti/icon99", 	  2, 	  0},

	/**189**/{ 291, "Electrical Belts\nService required", 	"电动安全带异常\n请联系当地经销商", 	"kzb://kanzi_launch/Textures/Noti/icon119", 	  2, 	  1},

	/**190**/{ 297, "Cruise Control canceled", 	"定速巡航已取消", 	"kzb://kanzi_launch/Textures/Noti/icon103", 	  2, 	  1},

	/**191**/{ 297, "Cruise Control canceled", 	"定速巡航已取消", 	"kzb://kanzi_launch/Textures/Noti/icon103", 	  2, 	  1},

	/**192**/{ 298, "Cruise Control canceled\nAcceleration Pedal pressed and held for long time", 	"定速巡航已取消\n踩加速踏板时间过长", 	"kzb://kanzi_launch/Textures/Noti/icon103", 	  2, 	  1},

	/**193**/{ 298, "Cruise Control canceled\nAcceleration Pedal pressed and held for long time", 	"定速巡航已取消\n踩加速踏板时间过长", 	"kzb://kanzi_launch/Textures/Noti/icon103", 	  2, 	  1},

	/**194**/{ 299, "Cruise Control unavailable", 	"定速巡航\n保护性停用", 	"kzb://kanzi_launch/Textures/Noti/icon65", 	  2, 	  0},

	/**195**/{ 299, "Cruise Control unavailable", 	"定速巡航\n保护性停用", 	"kzb://kanzi_launch/Textures/Noti/icon65", 	  2, 	  0},

	/**196**/{ 300, "Cruise Control\nunavailable\nSpeed too low", 	"定速巡航不可用\n车速过低", 	"kzb://kanzi_launch/Textures/Noti/icon65", 	  2, 	  1},

	/**197**/{ 300, "Cruise Control\nunavailable\nSpeed too low", 	"定速巡航不可用\n车速过低", 	"kzb://kanzi_launch/Textures/Noti/icon65", 	  2, 	  1},

	/**198**/{ 301, "Cruise Control canceled\nSpeed too low", 	"定速巡航已取消\n车速过低", 	"kzb://kanzi_launch/Textures/Noti/icon103", 	  2, 	  0},

	/**199**/{ 301, "Cruise Control canceled\nSpeed too low", 	"定速巡航已取消\n车速过低", 	"kzb://kanzi_launch/Textures/Noti/icon103", 	  2, 	  0},

	/**200**/{ 302, "Cruise Control\nunavailable\nSwitch Drive Mode", 	"定速巡航不可用\n请切换驾驶模式", 	"kzb://kanzi_launch/Textures/Noti/icon65", 	  2, 	  1},

	/**201**/{ 302, "Cruise Control\nunavailable\nSwitch Drive Mode", 	"定速巡航不可用\n请切换驾驶模式", 	"kzb://kanzi_launch/Textures/Noti/icon65", 	  2, 	  1},

	/**202**/{ 303, "Cruise Control canceled\nBrake overheat", 	"定速巡航已取消\n制动系统过热", 	"kzb://kanzi_launch/Textures/Noti/icon103", 	  2, 	  1},

	/**203**/{ 303, "Cruise Control canceled\nBrake overheat", 	"定速巡航已取消\n制动系统过热", 	"kzb://kanzi_launch/Textures/Noti/icon103", 	  2, 	  1},

	/**204**/{ 304, "48V battery level too low\nStart engine to charge", 	"48V动力电池电量低\n请启动发动机", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  1},

	/**205**/{ 305, "Engine Hybrid Battery Fault\nStop Safely\nService required", 	"混合动力蓄电池异常\n请安全停车后重启\n若仍提示此故障\n请联系当地经销商", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  1, 	  1},

	/**206**/{ 306, "Engine Soot Filter full\nSee user manual", 	"汽油颗粒物捕集器已满\n需要清理\n请联系当地经销商", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  1},

	/**207**/{ 307, "Engine Performance reduced", 	"发动机进入保护模式\n请安全停车休眠\n若仍提示此故障\n请联系当地经销商", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  1},

	/**208**/{ 308, "Engine System\nService required", 	"发动机系统异常\n请安全停车休眠\n若仍提示此故障\n请联系当地经销商", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  1, 	  1},

	/**209**/{ 309, "Engine Fuel Filler\nCap leakage", 	"发动机燃油加注口盖渗漏", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  1},

	/**210**/{ 310, "Engine System\nService urgent", 	"发动机系统异常\n请安全停车休眠\n若仍提示此故障\n请联系当地经销商", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  1},

	/**211**/{ 311, "Engine restart not possible\nStop safely", 	"动力电池异常\n进入保护模式\n请联系当地经销商", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  1, 	  1},

	/**212**/{ 312, "Engine harsh behavior", 	"发动机低速时抖动\n车辆仍可使用", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  1},

	/**213**/{ 313, "AWD not available\nService required", 	"四驱系统异常\n请联系当地经销商", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  1},

	/**214**/{ 314, "Engine Hybrid system fault\nSpeed limited", 	"混合动力系统异常\n车速受限", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  1},

	/**215**/{ 315, "Engine Hybrid system fault\nAcceleation limited", 	"混合动力系统异常\n加速性能受限", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  1},

	/**216**/{ 316, "Engine Hybrid system fault\nService required", 	"混合动力系统异常\n请联系售后服务", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  1},

	/**217**/{ 317, "Oil Level\nSystem failure", 	"机油油位系统异常\n请联系当地经销商", 	"kzb://kanzi_launch/Textures/Noti/icon55", 	  2, 	  1},

	/**218**/{ 318, "Oil level high\nService required", 	"机油油位过高\n将影响发动机性能", 	"kzb://kanzi_launch/Textures/Noti/icon55", 	  2, 	  1},

	/**219**/{ 319, "Oil Level low\nFill 1l oil", 	"机油油位过低\n请添加1升机油", 	"kzb://kanzi_launch/Textures/Noti/icon25", 	  2, 	  1},

	/**220**/{ 320, "Oil Level low\nFill 1l oil", 	"机油油位过低\n请添加1升机油", 	"kzb://kanzi_launch/Textures/Noti/icon25", 	  2, 	  1},

	/**221**/{ 321, "Oil Pressure low\nStop Safely", 	"机油压力过低\n请安全停车", 	"kzb://kanzi_launch/Textures/Noti/icon54", 	  1, 	  1},

	/**222**/{ 322, "Oil Pressure low\nStop Engine", 	"机油压力过低\n请停车并熄火", 	"kzb://kanzi_launch/Textures/Noti/icon54", 	  2, 	  1},

	/**223**/{ 323, "The brake needs to be applied\n E-pedal is turned on or off", 	"需踩制动\n 检查e-pedal的开关状态", 	"kzb://kanzi_launch/Textures/Noti/icon302", 	  2, 	  1},

	/**224**/{ 324, "E-Peda system unavaliable", 	"E-Pedal无法开启\n系统异常", 	"kzb://kanzi_launch/Textures/Noti/icon320", 	  2, 	  1},

	/**225**/{ 325, "E-Peda system unavaliable", 	"E-Pedal无法开启\n当前工况受限", 	"kzb://kanzi_launch/Textures/Noti/icon302", 	  2, 	  1},

	/**226**/{ 326, "Please close fuel lid", 	"请关闭加油口盖", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  1},

	/**227**/{ 327, "Unlocking fuel lid", 	"正在解锁加油口盖\n请等待", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  1},

	/**228**/{ 328, "Please stop engine before refueling", 	"请熄火后加油", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  0},

	/**229**/{ 329, "Fuel lid open\nReady for refuel", 	"加油口盖已解锁\n请打开加油", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  1},

	/**230**/{ 330, "/", 	"油箱内压力过高\n若开启加油口盖\n有燃油溅出风险", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  1},

	/**231**/{ 331, "Aged fuel\nFill up fuel tank", 	"燃油长时间未消耗\n请加满燃油箱", 	"kzb://kanzi_launch/Textures/Noti/icon42", 	  2, 	  1},

	/**232**/{ 332, "Aged fuel\nIf possible,\nstart engine", 	"燃油长时间未消耗\n请启动发动机", 	"kzb://kanzi_launch/Textures/Noti/icon42", 	  2, 	  1},

	/**233**/{ 333, "Aged fuel\nEngine will run\nto consume fuel", 	"燃油长时间未消耗\n发动机将运行\n以消耗燃油", 	"kzb://kanzi_launch/Textures/Noti/icon42", 	  2, 	  1},

	/**234**/{ 334, "Low fuel level\nRefuel", 	"燃油油位低\n请加油", 	"kzb://kanzi_launch/Textures/Noti/icon90", 	  2, 	  1},

	/**235**/{ 335, "Empty fuel tank\nRefuel now", 	"燃油箱已空\n请立刻加油", 	"kzb://kanzi_launch/Textures/Noti/icon90", 	  2, 	  0},

	/**236**/{ 336, "Press brake\nto release\ngear lever", 	"请踩下制动踏板\n以释放换挡杆", 	"kzb://kanzi_launch/Textures/Noti/icon346", 	  2, 	  1},

	/**237**/{ 337, "Shift to D\nTo enable manual mode", 	"请在D挡下\n进入手动挡模式", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  1},

	/**238**/{ 338, "Next engine start\nmay not be possible", 	"发动机下次可能\n无法启动", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  0},

	/**239**/{ 339, "Vehicle movement\ndirection\ncannot be changed", 	"车辆移动方向\n无法改变", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  0},

	/**240**/{ 340, "Gear Shifter\nService required", 	"换挡系统异常\n需要维修", 	"kzb://kanzi_launch/Textures/Noti/icon217", 	  2, 	  1},

	/**241**/{ 341, "Manual Mode activated", 	"手动模式已激活", 	"kzb://kanzi_launch/Textures/Noti/icon72", 	  2, 	  0},

	/**242**/{ 344, "Please release shifter", 	"换挡杆卡滞\n请恢复初始位置", 	"kzb://kanzi_launch/Textures/Noti/icon50", 	  2, 	  1},

	/**243**/{ 345, "Shift to D\nTo enable manual mode", 	"请在D挡下\n进入手动挡模式", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  1},

	/**244**/{ 346, "Please release P-button", 	"P挡按键卡滞\n请检查", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  1},

	/**245**/{ 350, "Transmission\nService urgent\nDrive to workshop", 	"变速箱异常\n请安全停车休眠\n若仍提示此故障\n请联系当地经销商", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  1},

	/**246**/{ 351, "Transmission\nService required", 	"变速箱需要保养\n请联系当地经销商", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  1},

	/**247**/{ 352, "Transmission failure\nStop safely\nVehicle shall be\ntowed to service", 	"变速箱异常\n请安全停车休眠\n若仍提示此故障\n请联系当地经销商", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  1, 	  1},

	/**248**/{ 353, "Transmission\nService required", 	"变速箱换挡故障\n请联系售后服务", 	"kzb://kanzi_launch/Textures/Noti/icon29", 	  2, 	  1},

	/**249**/{ 354, "Transmission\nOil temp high\nStop safely", 	"变速箱油温高\n请安全停车", 	"kzb://kanzi_launch/Textures/Noti/icon30", 	  1, 	  1},

	/**250**/{ 355, "Transmission\nOil temp high", 	"变速箱油温高", 	"kzb://kanzi_launch/Textures/Noti/icon30", 	  2, 	  1},

	/**251**/{ 356, "Transmission\nAcceleration\nperformance low", 	"变速箱进入保护机制\n请安全停车休眠\n若仍提示此故障\n请联系当地经销商", 	"kzb://kanzi_launch/Textures/Noti/icon29", 	  2, 	  1},

	/**252**/{ 357, "Transmission\nAdjusted", 	"变速箱已调整", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  0},

	/**253**/{ 358, "Transmission overheat\nStop safely", 	"变速箱过热\n请安全停车", 	"kzb://kanzi_launch/Textures/Noti/icon30", 	  2, 	  1},

	/**254**/{ 359, "Transmission\nAdaptation mode", 	"变速箱\n自适应模式", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  0},

	/**255**/{ 360, "Gear lever\nIndication mode", 	"变速箱\n换挡指示模式", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  0},

	/**256**/{ 361, "Gear lever\nIndication mode", 	"变速箱\n换挡指示模式", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  0},

	/**257**/{ 362, "TRANSM. OVERHEAT\nPARK SAFELY", 	"变速箱过热\n请安全停车", 	"kzb://kanzi_launch/Textures/Noti/icon29", 	  2, 	  1},

	/**258**/{ 363, "Transmission cooling\nLet engine run", 	"变速箱正在冷却\n保持发动机运转", 	"kzb://kanzi_launch/Textures/Noti/icon29", 	  2, 	  1},

	/**259**/{ 364, "Performance reduced\nReverse not available", 	"变速箱性能下降\n倒挡不可用", 	"kzb://kanzi_launch/Textures/Noti/icon29", 	  2, 	  1},

	/**260**/{ 365, "Performance reduced\nAvoid stopping in uphill", 	"变速箱性能下降\n避免上坡停车", 	"kzb://kanzi_launch/Textures/Noti/icon29", 	  2, 	  1},

	/**261**/{ 366, "Performance reduced\nAvoid hill driving", 	"变速箱性能下降\n避免坡路行驶", 	"kzb://kanzi_launch/Textures/Noti/icon29", 	  2, 	  1},

	/**262**/{ 367, "Transmission\nperformance reduced", 	"变速箱性能受限\n安全停车并重启车辆", 	"kzb://kanzi_launch/Textures/Noti/icon29", 	  2, 	  1},

	/**263**/{ 368, "Check gear lever\nposition", 	"变速箱\n检查换挡杆位置", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  1},

	/**264**/{ 369, "Gear lever locked", 	"换挡杆已锁定", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  1},

	/**265**/{ 370, "Clutch overspeed\nSlow down", 	"变速箱离合器异常\n转速过高\n请减速", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  1},

	/**266**/{ 371, "Gear shift not possible\nStop safely\nService required", 	"变速箱换挡故障\n请安全停车\n请联系当地经销商", 	"kzb://kanzi_launch/Textures/Noti/icon29", 	  1, 	  1},

	/**267**/{ 372, "Rolling possible in N\nShift to P", 	"N挡存在溜车风险\n请挂入P挡", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  1},

	/**268**/{ 373, "Out of P", 	"挡位不在P挡", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  1},

	/**269**/{ 374, "Hybrid Engine\nService required", 	"混合动力系统故障\n请联系当地经销商", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  1},

	/**270**/{ 375, "Hybrid system fault\nStop safely\nService required", 	"混合动力系统故障\n请立即安全停车\n请联系当地经销商", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  1, 	  1},

	/**271**/{ 376, "High Voltage Battery over heat\nStop and leave vehicle\nImmediately", 	"动力电池热失控\n请立即远离车辆\n拨打救援电话", 	"kzb://kanzi_launch/Textures/Noti/icon85", 	  1, 	  1},

	/**272**/{ 381, "Please start engine\nAfter 2 min", 	"请在两分钟后\n再次启动发动机", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  0},

	/**273**/{ 382, "Do not start engine\nMay damage high voltage battery", 	"请不要启动发动机\n将造成动力电池损坏", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  0},

	/**274**/{ 383, "Start Stop\nService required", 	"智能启停系统\n需要维修", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  1},

	/**275**/{ 384, "All-Wheel Drive\nsystem\nTemporarily\ndeactivated\nHigh temperature", 	"四驱系统温度过高\n保护性停用", 	"kzb://kanzi_launch/Textures/Noti/icon210", 	  2, 	  1},

	/**276**/{ 385, "All-Wheel Drive\nperformance reduced", 	"四轮系统保护机制启动\n性能减弱", 	"kzb://kanzi_launch/Textures/Noti/icon210", 	  2, 	  1},

	/**277**/{ 386, "AWD System\nService required", 	"四驱系统异常\n请联系当地经销商", 	"kzb://kanzi_launch/Textures/Noti/icon210", 	  2, 	  1},

	/**278**/{ 387, "Alarm System\nsensor fault", 	"警报系统传感器异常", 	"kzb://kanzi_launch/Textures/Noti/icon20", 	  2, 	  1},

	/**279**/{ 388, "Car remotely immobilized\nStart not possible", 	"远程防盗锁止已开启\n车辆无法启动", 	"kzb://kanzi_launch/Textures/Noti/icon116", 	  1, 	  1},

	/**280**/{ 389, "Key not in car", 	"钥匙不在车内", 	"kzb://kanzi_launch/Textures/Noti/icon70", 	  2, 	  0},

	/**281**/{ 390, "Key still in the car", 	"钥匙仍在车内", 	"kzb://kanzi_launch/Textures/Noti/icon70", 	  2, 	  1},

	/**282**/{ 391, "Steering Column Lock fault\nStop safely", 	"转向柱锁异常\n请安全停车", 	"kzb://kanzi_launch/Textures/Noti/icon13", 	  1, 	  1},

	/**283**/{ 392, "Steering Column locked\nTry again", 	"转向柱锁止\n请再试一次", 	"kzb://kanzi_launch/Textures/Noti/icon13", 	  2, 	  1},

	/**284**/{ 393, "Steering Column Lock\nService required", 	"转向柱锁异常\n请联系当地经销商", 	"kzb://kanzi_launch/Textures/Noti/icon13", 	  1, 	  1},

	/**285**/{ 394, "Steering blocked\nMove steering\nwheel and\ntry again", 	"转向锁定\n请转动方向盘\n再试一次", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  1},

	/**286**/{ 395, "Transmission Failure\nRestart vehicle try again", 	"传动系统异常\n请重启车辆\n若仍提示此故障\n请联系当地经销商", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  1},

	/**287**/{ 396, "Remote Key\nBattery low", 	"遥控钥匙\n电池电量过低", 	"kzb://kanzi_launch/Textures/Noti/icon11", 	  2, 	  1},

	/**288**/{ 397, "Wiper system malfunction", 	"雨刮器系统异常\n请检查", 	"kzb://kanzi_launch/Textures/Noti/icon101", 	  2, 	  1},

	/**289**/{ 398, "Rain Sensor fault\nService required", 	"雨量传感器系统故障\n请联系当地经销商", 	"kzb://kanzi_launch/Textures/Noti/icon130", 	  2, 	  1},

	/**290**/{ 400, "Turn Signal\nfault", 	"请检查转向指示灯", 	"kzb://kanzi_launch/Textures/Noti/icon93", 	  2, 	  1},

	/**291**/{ 401, "Artificial external sound\nOff", 	"低速报警提示音关闭", 	"kzb://kanzi_launch/Textures/Noti/icon301", 	  2, 	  1},

	/**292**/{ 402, "Artificial external sound\nSystem fault\nService required", 	"低速报警系统故障\n需要维修", 	"kzb://kanzi_launch/Textures/Noti/icon347", 	  2, 	  1},

	/**293**/{ 408, "Brake Lights fault", 	"请检查制动灯", 	"kzb://kanzi_launch/Textures/Noti/icon94", 	  2, 	  1},

	/**294**/{ 409, "Display Error\nService required", 	"仪表显示异常\n请联系当地经销商", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  1, 	  1},

	/**295**/{ 411, "ARC highway mode activated", 	"主动侧倾控制系统\n高速模式已激活", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  0},

	/**296**/{ 412, "ARC degraded Mode activated\ndrive slowly", 	"主动侧倾控制系统\n进入降级模式\n请减速驾驶", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  0},

	/**297**/{ 413, "ARC enter into passive mode\ndrive slowly", 	"主动侧倾控制系统\n进入被动模式\n请减速驾驶", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  0},

	/**298**/{ 414, "ARC failure\ndrive slowly\nservice required", 	"主动侧倾控制系统故障\n请减速驾驶\n需要维修", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  1},

	/**299**/{ 415, "48V Battery failure\nService required", 	"48V电池故障\n请联系当地经销商", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  1},

	/**300**/{ 416, "Reservation will expire in 30 minutes", 	"分享车辆30分钟后到期", 	"kzb://kanzi_launch/Textures/Noti/icon346", 	  2, 	  0},

	/**301**/{ 417, "Reservation will expire in 15 minutes", 	"分享车辆15分钟后到期", 	"kzb://kanzi_launch/Textures/Noti/icon346", 	  2, 	  0},

	/**302**/{ 418, "Reservation expired", 	"分享车辆已到期", 	"kzb://kanzi_launch/Textures/Noti/icon346", 	  2, 	  0},

	/**303**/{ 419, "Reservation overtime", 	"分享车辆已超时", 	"kzb://kanzi_launch/Textures/Noti/icon346", 	  2, 	  0},

	/**304**/{ 420, "Reservation invalid", 	"分享车辆已失效", 	"kzb://kanzi_launch/Textures/Noti/icon346", 	  2, 	  0},

	/**305**/{ 432, "Rear HV thermal system error\nPlease parking safely", 	"后高压热风系统故障\n请停车下电", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  1},

	/**306**/{ 434, "Be cautious\ntyres are leftward", 	"轮胎偏向左方\n请注意", 	"kzb://kanzi_launch/Textures/Noti/icon318", 	  4, 	  1},

	/**307**/{ 435, "Be cautious\ntyres are rightward", 	"轮胎偏向右方\n请注意", 	"kzb://kanzi_launch/Textures/Noti/icon319", 	  5, 	  1},

	/**308**/{ 436, "Power system fault\nCan not DC charge\nTry to AC charge", 	"动力系统故障\n无法快充\n充电时请尝试慢充", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  1},

	/**309**/{ 443, "No face detected", 	"未检测到人脸", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  0},

	/**310**/{ 444, "Door latch\n Only open\n via emergency method \nduring moving", 	"车锁门\n行驶中只能通过\n紧急开启功能打开", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  0},

	/**311**/{ 445, "Launch Control active", 	"弹射模式激活", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  0},

	/**312**/{ 446, "Launch Control failed", 	"弹射模式失效", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  0},

	/**313**/{ 447, "ERMD failure\nplease stop safely", 	"外流媒体后视镜故障\n请安全停车!", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  1},

	/**314**/{ 448, "Rear view mirror malfunction\nplease contact customer service", 	"外流媒体后视镜故障\n请联系当地经销商", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  1},

	/**315**/{ 449, "The external camera of ERMD\n is not deployed\n please pay attention to driving safety", 	"外流媒体后视镜摄像头\n未展开\n请注意行车安全！", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  1},

	/**316**/{ 450, "Life Detection is limited\nplease do not leave living creature  in the vehicle", 	"生命体探测功能受限\n请不要\n遗留生命体在车上！", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  0},

	/**317**/{ 451, "please do not leave\n any living creature in the vehicle", 	"请不要\n遗留生命体在车上", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  0},

	/**318**/{ 452, "Service for the Alcohol Interlock is required", 	"酒精检测服务已请求", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  0},

	/**319**/{ 453, "Alcohol Breath Sample Required", 	"酒精检测中\n请吹气", 	"kzb://kanzi_launch/Textures/Noti/icon78", 	  1, 	  1},

	/**320**/{ 454, "Please wait for the result", 	"请等待检测结果", 	"kzb://kanzi_launch/Textures/Noti/icon78", 	  2, 	  0},

	/**321**/{ 455, "Engine enabled to start", 	"酒精检测通过\n请启动车辆", 	"kzb://kanzi_launch/Textures/Noti/icon78", 	  2, 	  0},

	/**322**/{ 456, "Failed breath test", 	"酒精检测失败", 	"kzb://kanzi_launch/Textures/Noti/icon78", 	  2, 	  0},

	/**323**/{ 457, "General Error", 	"酒精检测错误\n请重试", 	"kzb://kanzi_launch/Textures/Noti/icon82", 	  2, 	  0},

	/**324**/{ 458, "User Blew too early", 	"吹气过早", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  0},

	/**325**/{ 459, "User blew too soft", 	"吹气太轻", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  0},

	/**326**/{ 460, "User blew too hard", 	"吹气太强", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  0},

	/**327**/{ 461, "Not accepted breath sample", 	"酒精检测浓度超标", 	"kzb://kanzi_launch/Textures/Noti/icon78", 	  2, 	  0},

	/**328**/{ 462, "Test period has expired", 	"酒精检测超时", 	"kzb://kanzi_launch/Textures/Noti/icon78", 	  2, 	  0},

	/**329**/{ 463, "Permanent Lockout State", 	"酒精锁已锁定", 	"kzb://kanzi_launch/Textures/Noti/icon78", 	  2, 	  1},

	/**330**/{ 464, "Non Permanen Lockout\nWait for a new test", 	"临时锁定\n等待重新测试", 	"kzb://kanzi_launch/Textures/Noti/icon78", 	  2, 	  1},

	/**331**/{ 465, "Alcohol Interlock fault\nService required", 	"酒精锁异常\n请联系当地经销商", 	"kzb://kanzi_launch/Textures/Noti/icon82", 	  2, 	  1},

	/**332**/{ 466, "Alcohol Interlock in Service", 	"酒精锁服务中", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  0},

	/**333**/{ 467, "Alcohol Interlock Warming up\nPlease wait", 	"解锁中\n请等待", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  0},

	/**334**/{ 468, "ESC track", 	"ESC track", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  0},

	/**335**/{ 469, "ESC sport+", 	"ESC sport+", 	"kzb://kanzi_launch/Textures/Noti/icon0", 	  2, 	  0},

	/**336**/{ 495, "/", 	"/", 	"kzb://kanzi_launch/Textures/Noti/icon", 	  6, 	  0},

	/* list end */
#endif
};
#endif // !__WARNING_CONTROLLER_HPP__
