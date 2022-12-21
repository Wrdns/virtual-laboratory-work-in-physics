
#include "pch.h"
#include "framework.h"
#include "kurs.h"
#include "kursDlg.h"
#include "afxdialogex.h"
#include "mth.h"
#include <cmath>

constexpr auto M_PI = 3.14159265358979323846;;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace std;

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
protected:
	DECLARE_MESSAGE_MAP()
public:

};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Диалоговое окно CkursDlg



CkursDlg::CkursDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_KURS_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	AfxMessageBox(L"Добро пожаловать в виртуальную лабораторную работу по физике! Для начала работы, обязательно введите массу, нажмите кнопку расчёт, переместите маятник в начальное положение и запустите маятник кнопкой старт. После, расчитайте период и длину маятника, как завершите расчёты, обязательно проверьте их. После всех проделанных действий, заново запустите колебания и вычислите декремент затухания!");
}

void CkursDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_GRFRAME, grframe);
}

BEGIN_MESSAGE_MAP(CkursDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CkursDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_TSTBUT, &CkursDlg::OnBnClickedTstbut)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON1, &CkursDlg::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT1, &CkursDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON2, &CkursDlg::OnBnClickedButton2)
	ON_EN_CHANGE(IDC_EDIT2, &CkursDlg::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT3, &CkursDlg::OnEnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT4, &CkursDlg::OnEnChangeEdit4)
	ON_WM_SIZE()
	ON_COMMAND(ID_32776, &CkursDlg::MenuClose)
	ON_EN_CHANGE(IDC_MINUTES, &CkursDlg::OnEnChangeMinutes)
	ON_EN_CHANGE(IDC_HOURSES, &CkursDlg::OnEnChangeHourses)
	ON_EN_CHANGE(IDC_MILIS, &CkursDlg::OnEnChangeMilis)
	ON_BN_CLICKED(IDC_BUTTON4, &CkursDlg::OnBnClickedButton4)
	ON_EN_CHANGE(IDC_EDIT5, &CkursDlg::OnEnChangeEdit5)
	ON_EN_CHANGE(IDC_EDIT7, &CkursDlg::OnEnChangeEdit7)
	ON_BN_CLICKED(IDC_BUTLE, &CkursDlg::OnBnClickedButle)
	ON_BN_CLICKED(IDC_PERCHECKBUT, &CkursDlg::OnBnClickedPercheckbut)
	ON_BN_CLICKED(IDC_BUTTON3, &CkursDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_GRFRAME, &CkursDlg::OnBnClickedGrframe)
	ON_EN_CHANGE(IDC_LOGDECK, &CkursDlg::OnEnChangeLogdeck)
	ON_BN_CLICKED(IDC_LDCHECK, &CkursDlg::OnBnClickedLdcheck)
	ON_BN_CLICKED(IDC_GOTESTBUT, &CkursDlg::OnBnClickedGotestbut)
	ON_BN_CLICKED(IDC_CHECKQ1A3, &CkursDlg::OnBnClickedCheckq1a3)
	ON_BN_CLICKED(IDC_CHECKQ2A4, &CkursDlg::OnBnClickedCheckq2a4)
	ON_BN_CLICKED(IDC_CHECKQ3A4, &CkursDlg::OnBnClickedCheckq3a4)
END_MESSAGE_MAP()


// Обработчики сообщений CkursDlg

BOOL CkursDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CkursDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

void CkursDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	CRect dlgrect;
	GetClientRect(dlgrect);
	CPaintDC dc(this);
	//Объявление переменных для хранения координат.
	double Ml = dlgrect.Height() / 2.95,
		xsp = dlgrect.Width() / (5.0),
		ysp = dlgrect.Height() / (20.0),
		x, y;
	// Отрисовка маятника
		x = Ml * sin(alpha); // Отрисовка по x координате.
		y = Ml * cos(alpha); // Соответственно по y.
	// Работа с кистью
	CPen mpen(1, 2, RGB(1, 1, 1));
	CPen rpen(1, 3, RGB(21, 32, 110));
	CPen gpen(1, 2, RGB(255, 0, 0));
	dc.SelectObject(mpen);
	dc.MoveTo(xsp, ysp);
	dc.LineTo(xsp + 25, ysp);
	dc.LineTo(xsp - 25, ysp);
	dc.MoveTo(xsp, ysp);
	dc.LineTo(xsp + x, ysp + y);
	dc.SelectObject(rpen);
	dc.Ellipse((xsp + x - 10), (ysp + y - 10), (xsp + x + 10), (ysp + y + 10));
	SetDlgItemInt(IDC_EDIT1, seconds);
	SetDlgItemInt(IDC_MINUTES, minutes);
	SetDlgItemInt(IDC_HOURSES, y);
	SetDlgItemInt(IDC_MILIS, x);
	SetDlgItemInt(IDC_EDIT5, milis);
}
HCURSOR CkursDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
void CkursDlg::OnBnClickedOk()
{
	CDialogEx::OnOK();
}
void CkursDlg::OnBnClickedTstbut()
{
	SetTimer(1, 10, NULL);
	SetTimer(2, 100, NULL);
}
void CkursDlg::StartTimer()
{
}
void CkursDlg::StopTimer()
{
}

CWnd* m_DrawArea;
void CkursDlg::OnTimer(UINT_PTR nIDEvent)
{
	if (nIDEvent == 3)
	{
		omega += (-pow(w0, 2.) * sin(alpha) - gamma * omega) * Dtime; // Обработчик таймера
		alpha += omega * Dtime; // Перерасчёт угла
		if (alphamax < alpha)
		{
			alphamax = alpha;
		}
		else
		{
			KillTimer(3);
			endcheck = true;
		}
	}
	if (endcheck == true)
	{
		if (nIDEvent == 1)
		{
			omega += (-pow(w0, 2.) * sin(alpha) - gamma * omega) * Dtime; // Обработчик таймера
			alpha += omega * Dtime; // Перерасчёт угла
			this->RedrawWindow(); // обновление окна
		}
		else if (nIDEvent == 2)
		{
			if (milis < 9)
			{
				milis += 1;
			}
			else
			{
				milis = 0;
				if (seconds < 59)
				{
					seconds += 1;
				}
				else
				{
					seconds = 0;
					if (minutes < 59)
					{
						minutes++;
					}
					else
					{
						minutes = 0;
						hourses++;
					}
				}
			}
		}
		else if (nIDEvent == 4)
		{
			m_DrawArea = grframe.GetDC()->GetWindow();
			CClientDC dc(m_DrawArea);
			CRect gfrc;
			m_DrawArea->GetClientRect(&gfrc);
			gfh = gfrc.Height(); int gfw = gfrc.Width();
			omega += (-pow(w0, 2.) * sin(alpha) - gamma * omega) * Dtime; // Обработчик таймера
			alpha += omega * Dtime; // Перерасчёт угла
			if (gx < gfw)
			{
				gx += 0.4;
				CPen mpen(1, 4, RGB(1, 2, 3));
				CPen gpen(1, 2, RGB(255, 0, 0));
				CPen rpen(2, 1, RGB(1, 1, 1));
				dc.SelectObject(mpen);
				dc.MoveTo(0, 0);
				dc.LineTo(0, gfh);
				dc.MoveTo(0, gfh / 2);
				dc.LineTo(gfw, gfh / 2);
				dc.SelectObject(rpen);
				for (int i = 0; i <gfh; i+=10 )
				{
					dc.MoveTo(0, i);
					dc.LineTo(gfw, i);
				}
				dc.SelectObject(gpen);
				dc.Ellipse(gx - 1, gfh / 2 - 1 - sin(alpha) * 220, gx + 1, gfh / 2 + 1 - sin(alpha) * 220);
			}
			else 
			{
				KillTimer(4);
				gx = 0;
			}
		}
	}
}
void CkursDlg::OnBnClickedButton1()
{
	CString mstd;
	GetDlgItemText(IDC_EDIT4, mstd);
	//beta = 1.0;
	massa = _wtof(mstd); //
	length = 1.0;
	omega = omega0; // Определение начальных параметров.
	alpha = alpha0; //
	w0 = g / length; // 
	gamma = beta / massa;
	pi = M_PI;
	SetTimer(3, 10, NULL);
}
void CkursDlg::OnEnChangeEdit1()
{
	
}
//CWnd* m_DrawArea;
void CkursDlg::OnBnClickedButton2()
{
	KillTimer(1);
	KillTimer(2);
	milis = seconds = minutes = 0;
	this->RedrawWindow();
	AfxMessageBox(L"Введите период, исходя из формулы посчитайте длину");
	alpha = 0.0;
	omega = omega0;
	SetTimer(4, 1, NULL);

}
void CkursDlg::OnEnChangeEdit2()
{
}
void CkursDlg::OnEnChangeEdit3()
{
}
void CkursDlg::OnEnChangeEdit4()
{
}

void CkursDlg::OnSize(UINT nType, int cx, int cy)
{
}


void CkursDlg::MenuClose()
{
	DestroyWindow();
}


void CkursDlg::OnEnChangeMinutes()
{
}


void CkursDlg::OnEnChangeHourses()
{
}


void CkursDlg::OnEnChangeMilis()
{
}

void CkursDlg::OnBnClickedRep()
{
}


void CkursDlg::OnBnClickedRepp()
{
}


void CkursDlg::OnBnClickedButton4()
{
	this->RedrawWindow();
}


void CkursDlg::OnEnChangeEdit5()
{
}


void CkursDlg::OnEnChangeLedit()
{
}


void CkursDlg::OnEnChangeEdit7()
{
}


void CkursDlg::OnBnClickedButle()
{
}


void CkursDlg::OnBnClickedPercheckbut()
{
	CString pctmp;
	GetDlgItemText(IDC_EDIT7, pctmp);
	percheck = _wtof(pctmp);
	if (percheck > 2.2 || percheck < 1.8)
	{
		AfxMessageBox(L"Расчёт неверный");
	}
	else 
	{ 
		AfxMessageBox(L"Всё верно");
	}
}


void CkursDlg::OnBnClickedButton3()
{
	CString lctmp;
	GetDlgItemText(IDC_EDIT2, lctmp);
	lencheck = _wtof(lctmp);
	if (lencheck > 1.1 || lencheck < 0.9)
	{
		AfxMessageBox(L"Расчёт неверный");
	}
	else
	{
		AfxMessageBox(L"Всё верно");
		AfxMessageBox(L"Включены колебания с затуханием, проведите эксперимент еще раз, найдите коэф. затухания.");
		beta = 1.0;
		omega = omega0;
		alpha = alpha0;
		gx = 0;
		KillTimer(4);
		this->RedrawWindow();
	}
}


void CkursDlg::OnBnClickedGrframe()
{
}
void CkursDlg::OnEnChangeLogdeck()
{
}


void CkursDlg::OnBnClickedLdcheck()
{
	CString ldtd;
	GetDlgItemText(IDC_LOGDECK, ldtd);
	logdeck = _wtof(ldtd);
	if (logdeck > 0.18 || logdeck < 0.10)
	{
		AfxMessageBox(L"Расчёт неверный");
	}
	else
	{
		AfxMessageBox(L"Всё верно");
		this->RedrawWindow();
	}
}


void CkursDlg::OnBnClickedGotestbut()
{
	CString q1, q2, q3;
	if (q1f == true)
	{
		q1 = "1: Ответ верный\n";
	}
	else
	{
		q1 = ("1: Ответ неверный. При увеличении частоты колебаний маятника, уменьшается длина его нити\n");
	}
	if (q2f == true)
	{
		q2 = "2: Ответ верный\n";
	}
	else
	{
		q2 = ("2: Ответ неверный. Математический маятник (речь о движении без затуханий), не получает и не теряет энергию, трение в математическом маятнике принимается равным нулю.\n");
	}
	if (q3f == true)
	{
		q3 = "3: Ответ верный\n";
	}
	else
	{
		q3 = ("3: Ответ неверный. Необходимо, чтобы его груз имел малый размер, нить была бы нерастяжимой, и максимальное отклонение маятника было бы намного меньше его длины.\n");
	}
	AfxMessageBox(q1 + q2 + q3);
}


void CkursDlg::OnBnClickedCheckq1a3()
{
	q1f = true;
}


void CkursDlg::OnBnClickedCheckq2a4()
{
	q2f = true;
}


void CkursDlg::OnBnClickedCheckq3a4()
{
	q3f = true;
}
