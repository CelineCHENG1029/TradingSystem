// DlgOptionStrategy.h

#pragma once


#include <afxcmn.h>
#include <afxdtctl.h>
#include "resource.h"
#include "OptionPositionGridGtrl.h"
#include "PositionList.h"
#include "ExpiryCalculator.h"
#include "OptionListGridCtrl.h"
#include "IXingAPI.h"
#include "OptionPriceBoard.h"
#include "OptionStrategyGridCtrl.h"
#include "OptionManager.h"

class CDlgOptionManager;
class CModuleRelationView;
class OptionManager;

class CDlgOptionStrategy : public CDialog{
	DECLARE_DYNCREATE(CDlgOptionStrategy)

	public:
		enum {IDD=IDD_DIALOG_OPTION_STRATEGY};
		CDlgOptionStrategy(CWnd* pParent = NULL);
		virtual ~CDlgOptionStrategy();
		virtual BOOL OnInitDialog();

		

	protected:
		virtual void DoDataExchange(CDataExchange* pDX);

		DECLARE_MESSAGE_MAP()
		afx_msg void OnButtonClickedRequestData();
		afx_msg void OnButtonClickedCalExpiry();
		afx_msg void OnButtonClickedCalTheoPrice();

		afx_msg void OnButtonClickedAdd();
		
		afx_msg void OnButtonClickedCreateStrategy();

		afx_msg void OnButtonClickedAutoCalculate();

		afx_msg void OnTimer(UINT_PTR nIDEvent); // ����ð� ��� üũ�� ���ʸ��� ȣ��Ǽ� ����ð� ������Ʈ ��
		afx_msg	LRESULT		OnXMReceiveData		( WPARAM wParam, LPARAM lParam );
		afx_msg	LRESULT		OnXMTimeoutData		( WPARAM wParam, LPARAM lParam );

		afx_msg void OnGridOptionListStartSelChange(NMHDR *pNotifyStruct, LRESULT* pResult);
		afx_msg void OnGridOptionListEndSelChange(NMHDR *pNotifyStruct, LRESULT* pResult);
		afx_msg void OnGridOptionStrategyStartSelChange(NMHDR *pNotifyStruct, LRESULT* pResult);
		afx_msg void OnGridOptionStrategyEndSelChange(NMHDR *pNotifyStruct, LRESULT* pResult);
		afx_msg void OnButtonClickedDrawValueCurve();
		afx_msg void OnButtonClickedDeletePosition();
		afx_msg void OnButtonClickedDeleteStrategy();

	private:
		double CalExpiryRatio();
		CString GetCheckedRadioButtonType();
		CString GetCheckedRadioButtonPosition();
		CString GetCheckedRadioButtonPremium();
		BOOL TakeAPosition(const OptionParameter& optionParameter, int positionNumber, CString strategyName);
		void InitExpiryCalculator();
		void InitOptionLifePeriodCtrls();
		void SetWindowTextExpiryRatio(double expiryRatio);
		void ResetCurrentDateTime();
		
		void InitComboboxOptionMonth();
		void SelectComboboxOptionMonth();

		void RequestData();
		void Request_t3521(); // CD 91�� ������ ������ ������
		void Request_t2101(); // KOSPI200 �����ڻ� ���� ���
		void Request_t2301(tstring yyyymm); // ��簡 ������

		void ProcessXRReceiveData_t2101OutBlock(LPRECV_PACKET pRpData);
		void ProcessXRReceiveData_t2301OutBlock1(LPRECV_PACKET pRpData);
		void ProcessXRReceiveData_t2301OutBlock2(LPRECV_PACKET pRpData);
		void ProcessXRReceiveData_t3521OutBlock(LPRECV_PACKET pRpData);

		void EnableParameterCtrls(BOOL enable);

		CDlgOptionManager* CreateOptionValueCurveDialog(CRuntimeClass* pClass, UINT uID);

	public:
		IXingAPI* xingAPI;
		CDlgOptionManager* pDlgOptionManager;
		CModuleRelationView* pParentView;
		OptionManager* optionManager;

	private:
		
		CEdit editPointInWON; //IDC_EDIT_POINT_IN_WON
		CEdit editName; // StrategyName, IDC_EDIT_NAME
		CEdit editCode; // Option Code, IDC_EDIT_OPTION_CODE
		CEdit editRate; // ������ ������, IDC_EDIT_RISK_FREE_RATE
		
		CEdit editVol;  // ������, IDC_EDIT_VOL
		CEdit editUnderlyingPrice;  //�����ڻ� ����, IDC_EDIT_UNDERLYING_ASSET_PRICE
		CEdit editContractCount; // # of Contract, IDC_EDIT_NUMBER_CONTRACT

		CButton radioLong; // ������: Long, IDC_RADIO_LONG
		CButton radioShort;// ������: Short, IDC_RADIO_SHORT

		CButton radioPremiumMarket; // IDC_RADIO_PREMIUM_MARKET
		CButton radioPremiumTheo; // IDC_RADIO_PREMIUM_THEO

		CButton buttonSelectOption; // Select Option, IDC_BUTTON_SELECT_OPTION
		CButton buttonAdd;  // Take a Position!, IDC_BUTTON_ADD
		CButton buttonDelete; // Delete, IDC_BUTTON_DELETE
		//CButton buttonEdit;  // Edit, IDC_BUTTON_EDIT
		CButton buttonSave; // Save Strategy, IDC_BUTTON_SAVE

		//�����Ⱓ
		CDateTimeCtrl dateFrom; // ������ ��¥, IDC_DATETIMEPICKER_FROM_DATE
		CDateTimeCtrl dateTo; // ������ ��¥, IDC_DATETIMEPICKER_TO_DATE
		CDateTimeCtrl timeTo; // ������ �ð�, IDC_DATETIMEPICKER_TO_TIME
		CDateTimeCtrl timeNow; // ����ð�, 
		CDateTimeCtrl dateNow; // ���� ��¥, IDC_DATETIMEPICKER_NOW_DATE
		CDateTimeCtrl marketOpenTime; // ��ð� ����, IDC_DATETIMEPICKER_MARKET_OPEN_TIME
		CDateTimeCtrl marketCloseTime; // ��ð� Ŭ����, IDC_DATETIMEPICKER_MARKET_CLOSE_TIME
		CEdit editTimeLeft; // �����Ⱓ [0~1], IDC_EDIT_EXP_TIME

		CEdit editDaysLeft; // ������ IDC_EDIT_DAYS_LEFT
		CEdit editExpiryRatio2; // �������� IDC_EDIT_EXPIRY_RATIO2


		CEdit editAutoSeconds; // IDC_EDIT_SECONDS
		CButton buttonAutoPremiumCalculate; // �ǽð� �ڵ� �̷а� ���


		CComboBox comboboxOptionMonth; //IDC_COMBO__OPTION_MONTH
		CButton buttonDrawValueCurve; // IDC_BUTTON_OPTION_VALUE_CHART


		COptionListGridCtrl gridCtrlOptionList; //IDC_CUSTOM_OPTION_LIST
		COptionPositionGridCtrl gridCtrl;
		COptionStrategyGridCtrl gridCtrlOptionStrategyList; //IDC_CUSTOM_OPTION_STRATEGY_LIST
		CButton buttonDeleteOptionStrategy; //IDC_BUTTON_DELETE_STRATEGY

		int statusTimeNowTimer;
		int statusAutoCalTimer;
		ExpiryCalculator expiryCalculator;

		BOOL t2101Received;
		BOOL t2301_1Received;
		BOOL t2301_2Received;
		BOOL t3521Received;

		//PositionList positionList;
		OptionPriceBoard optionPriceBoard;

		double undelyingAssetPrice;	// ProcessXRReceiveData_t2101OutBlock	���Լ����� ������
		double historicalVol;		// ProcessXRReceiveData_t2101OutBlock	���Լ����� ������
		double riskFreeRate;		// ProcessXRReceiveData_t3521OutBlock	���Լ����� ������
		double expiryRatio;			// ResetCurrentDateTime					���Լ����� ������
		double expiryRatioByDayCount; // �ܿ���/365 ������ �������� ��� (���Ŀ��)
		double pointInWON;

		tstring selectedStrategyName;
		int selectedStrategyIndex;
	public:
		tstring& GetSelectedStrategyName() const;
		int GetSelectedStrategyIndex() const;
		double GetUnderlyingAssetPrice() const;
		double GetHistoricalVol() const;
		double GetRiskFreeRate() const;
		double GetExpiryRatio() const;
		double GetExpiryRatioByDayCount() const;
};




inline tstring& CDlgOptionStrategy::GetSelectedStrategyName() const{
	return const_cast<tstring&>(this->selectedStrategyName);
}


inline int CDlgOptionStrategy::GetSelectedStrategyIndex() const{
	return this->selectedStrategyIndex;
}



inline double CDlgOptionStrategy::GetUnderlyingAssetPrice() const{
	return this->undelyingAssetPrice;
}


inline double CDlgOptionStrategy::GetHistoricalVol() const{
	return this->historicalVol;
}

inline double CDlgOptionStrategy::GetRiskFreeRate() const{
	return this->riskFreeRate;
}


inline double CDlgOptionStrategy::GetExpiryRatio() const{
	return this->expiryRatio;
}


inline double CDlgOptionStrategy::GetExpiryRatioByDayCount() const{
	return this->expiryRatioByDayCount;
}