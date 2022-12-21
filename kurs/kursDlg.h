
// kursDlg.h: файл заголовка
//

#pragma once


// Диалоговое окно CkursDlg
class CkursDlg : public CDialogEx
{
// Создание
public:
	CkursDlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_KURS_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedTstbut();
	void StartTimer();
	void StopTimer();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnEnChangeEdit4();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void On32776();
	afx_msg void MenuClose();
	afx_msg void OnEnChangeMinutes();
	afx_msg void OnEnChangeHourses();
	afx_msg void OnEnChangeMilis();
	afx_msg void OnBnClickedRep();
	afx_msg void OnBnClickedRepp();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnEnChangeEdit5();
	afx_msg void OnEnChangeLedit();
	afx_msg void OnEnChangeEdit7();
	afx_msg void OnBnClickedButle();
	afx_msg void OnBnClickedPercheckbut();
	afx_msg void OnBnClickedButton3();
	CButton grframe;
	afx_msg void OnBnClickedGrframe();
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnEnChangeLogdeck();
	afx_msg void OnBnClickedLdcheck();
	afx_msg void OnBnClickedGotestbut();
	afx_msg void OnBnClickedCheckq1a3();
	afx_msg void OnBnClickedCheckq2a4();
	afx_msg void OnBnClickedCheckq3a4();
};
