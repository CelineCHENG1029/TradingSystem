// DlgDataFeedingModule.h

#pragma  once

#include <afxwin.h>
#include <afxdtctl.h>
#include "Resource.h"
#include "DataFeedingInfoManager.h"
#include <afxcmn.h>
#include "DataFeedingItemInfoList.h"
#include "DataFeedingGridCtrl.h"
#include "DataBunchGridCtrl.h"
#include "DataBunchItemGridCtrl.h"
#include "DataFeedingEditCtrl.h"


class IXingAPI;
class InstrumentCodeMaker;
class CModuleRelationView;

class CDlgDataFeedingModule : public CDialog{
	DECLARE_DYNCREATE(CDlgDataFeedingModule)

public:
	enum { IDD = IDD_DIALOG1 };
	CModuleRelationView* pParentView;


public:
	CDlgDataFeedingModule(CWnd* pParent = NULL);
	virtual ~CDlgDataFeedingModule();
	virtual void PostNcDestroy();
	virtual BOOL OnInitDialog();

	int AddDataFeedingInstrument(const DataFeedingItemInfo& item);

	tstring GetSelectedBroker();
	tstring GetSelectedInstrumentType();
	tstring GetSelectedTRType();

	CDataFeedingGridCtrl& GetGridCtrl() const;
	CDataBunchGridCtrl& GetDataBunchGridCtrl() const;
	CDataBunchItemGridCtrl& GetDataBunchItemGridCtrl() const;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);

	DECLARE_MESSAGE_MAP()
	afx_msg void SelectOptions();
	afx_msg void SelectComboBoxBroker();
	afx_msg void SelectComboBoxInstrumentType();
	afx_msg void OnButtonCliekedBook();
	afx_msg void OnButtonClickedEdit();
	afx_msg void OnButtonClickedAdd();
	afx_msg void OnButtonClickedSave();
	afx_msg void OnButtonClickedStart();
	afx_msg void OnButtonClickedStop();
	afx_msg LRESULT OnXMReceiveRealData(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT ReadviseDataFeeding(WPARAM wParam, LPARAM lParam);
	afx_msg void OnClose();
	afx_msg void OnTimer(UINT_PTR nIDEvent);


private:
	void InitComboBoxBroker();
	void InitComboBoxInstrumentType();
	void InitComboBoxTRType();
	int GetIndexFromComboBoxBroker(const tstring& broker);
	int GetIndexFromComboBoxInstrumentType(const tstring& instrumentType);
	void ListDataFeedingInfoInGrid(const DataFeedingInfoItemListInGrid& itemList);
	void ListDataBunchList(const DataBunchList& dataBunchList);
	void ListDataBunch(const DataBunch& dataBunch);
	


	// XingAPI������ ��û ���� �Լ�
	void StartETradeDataFeeding(); // ���̾�α� ������ �ѹ� ����
	void StopETradeDataFeeding();
	void DisplayFeedingResult();

public:
	IXingAPI* xingAPI;
	DataFeedingInfoManager* pDataFeedingInfoManager;
	InstrumentCodeMaker* p_InstrumentCodeMaker;	
	

private:

	BOOL dataFeeding;

	// Grid
	CDataFeedingGridCtrl gridCtrl;
	CDataBunchGridCtrl dataBunchGridCtrl;
	CDataBunchItemGridCtrl dataBunchItemGridCtrl;
	//CGridCtrl gridCtrl;

	// ��ư (DataFeedingItemInfoList)
	CButton buttonEdit;
	CButton buttonAdd;
	CButton buttonSave;
	CButton buttonStart;
	CButton buttonStop;
	CButton buttonClearTrace;
	CButton buttonAutoOnly;
	// ��ư (DataBunchList)
	CButton buttonDeleteDataBunchList;
	CButton buttonNewDataBunchList;
	// ��ư (DataBunch)
	CButton buttonDeleteDataBunch;
	CButton buttonAddDataBunch;

	// Combo Box
	CComboBox comboBoxBroker;
	CComboBox comboBoxInstrumentType;
	CComboBox comboBoxTRType;

	// Edit
	CDataFeedingEditCtrl editCtrl;

	// Reserve ����
	CButton buttonBooking;
	CDateTimeCtrl timeCtrl;
	CDateTimeCtrl dateCtrl;

	int bookDataFeedingID;
	BOOL bookedDataFeeding;
};

//inline DataFeedingInfoManager& CDlgDataFeedingModule::GetDataFeedingIntoManager() const{
//	return const_cast<DataFeedingInfoManager&>(this->dataFeedingInfoManager);
//}



inline CDataFeedingGridCtrl& CDlgDataFeedingModule::GetGridCtrl() const{
	return const_cast<CDataFeedingGridCtrl&>(this->gridCtrl);
}


inline CDataBunchGridCtrl& CDlgDataFeedingModule::GetDataBunchGridCtrl() const{
	return const_cast<CDataBunchGridCtrl&>(this->dataBunchGridCtrl);
}


inline CDataBunchItemGridCtrl& CDlgDataFeedingModule::GetDataBunchItemGridCtrl() const{
	return const_cast<CDataBunchItemGridCtrl&>(this->dataBunchItemGridCtrl);
}
