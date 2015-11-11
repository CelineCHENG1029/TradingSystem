#pragma once


// CModuleRelationView view

class CDlgDataFeedingModule;
class CDlgInstrumentManager;
class CDlgOptionStrategy;

class CModuleRelationView : public CView
{
	DECLARE_DYNCREATE(CModuleRelationView)

	protected:
		CModuleRelationView();           // protected constructor used by dynamic creation
		virtual ~CModuleRelationView();

	public:
		virtual void OnDraw(CDC* pDC);      // overridden to draw this view
		
		// CDlgDataFeedingModule ���� �Լ�
		CDlgDataFeedingModule* CreateDlgDataFeedingModule();


		// CDlgInstrumentManager ���� �Լ�
		CDlgInstrumentManager* CreateDlgInstrumentManager();

		// CDlgOptionStrategy �����Լ�
		CDlgOptionStrategy* CreateDlgOptionStrategy();

	public: // �� Viewâ���� �����Ǵ� Dialog ������
		CDlgDataFeedingModule* p_DlgDataFeedingModule;
		CDlgInstrumentManager* p_DlgInstrumentManager;
		CDlgOptionStrategy* p_DlgOptionStrategy;


	#ifdef _DEBUG
		virtual void AssertValid() const;
	#ifndef _WIN32_WCE
		virtual void Dump(CDumpContext& dc) const;
	#endif
	#endif

	protected:
		DECLARE_MESSAGE_MAP()
		afx_msg LRESULT ReadviseDataFeeding(WPARAM wParam, LPARAM lParam);

	private:
		CDialog* CreateManagerDialog(CRuntimeClass* pClass, UINT uID);

		
};


