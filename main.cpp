//Khai bao thu vien
#include "Administrator.h"
#include"SINHVIEN.h"
#include "GIAOVIEN.h"
#include "SACH.h"
#include "PHIEUMUON.h"
#include <conio.h>
#include <windows.h>
#include <vector>

//Khai bao nguyen mau ham
void SetColor(int ForgC);
void docDsSach();
void xuatDsSach();
void ghiDsSach();
void ghiDsSV();
void ghiDsGV();
void ghiDsPM();
void ghiMoiPM();
void docDsAdmin();
void xuatDsAdmin();
void docDsSV();
void xuatDsSV();
void docDsGV();
void xuatDsGV();
void docDsPM();
void xuatDsPM();
void loading(int iTime);
void login();
std::string inputPassword(size_t length_max);
int checkUsername(string sUser, string sPass);
void menu();
void QLPhieuMuon();
void QLSach();
void QLBanDoc();
void QLThongKe();
void menuQL();
void menuTK();
bool kiemTraMaBD(string sMaBD);
bool kiemTraMaSach(string sMaSach);
int kiemTraTinhTrangSach(string sMaSach);
int kiemTraSoPhieuMuon(int iSoPhieu);

//Khai bao bien tinh
int PHIEUMUON::iSoPhieuMuon = 0;

//Bien toan cuc
bool isAdmin = false;
vector<Administrator> dsAdmin;
vector<SACH> dsSach;
vector<SINHVIEN> dsSV;
vector<GIAOVIEN> dsGV;
vector<PHIEUMUON> dsPM;

//chuong trinh chinh
int main() 
{
	docDsAdmin();
	//xuatDsAdmin();

	docDsSach();
	//xuatDsSach();

	docDsSV();
	//xuatDsSV();
	

	docDsGV();
	//xuatDsGV();

	docDsPM();
	//xuatDsPM();

	login();

	system("pause");
	return 0;
}
//dinh nghia chuong trinh con
void QLPhieuMuon() {
	int iOption;
	SetColor(10);
	cout << "\t\t*************************************************" << endl;
	cout << "\t\t*                                               *" << endl;
	cout << "\t\t*                  ";
	SetColor(14);
	cout << "QL PHIEU MUON";
	SetColor(10);
	cout <<"                *" << endl;
	cout << "\t\t*                                               *" << endl;
	cout << "\t\t*************************************************" << endl;
	cout << endl;
	SetColor(12);
	cout << "\t\t=================================================" << endl;
	cout << "\t\t= "; SetColor(13); cout << "\t\t1. Xem danh sach Phieu muon";SetColor(12); cout << "     =" << endl;
	cout << "\t\t= "; SetColor(13); cout << "\t\t2. Tao Phieu muon moi";SetColor(12); cout << "           =" << endl;
	cout << "\t\t= "; SetColor(13); cout << "\t\t3. Tra Sach";SetColor(12); cout << "                     =" << endl;
	cout << "\t\t= "; SetColor(13); cout << "\t\t4. Thoat";SetColor(12); cout << "                        =" << endl;
	SetColor(12);
	cout << "\t\t=================================================" << endl;
	SetColor(11);
	cout << "\n\t\t-Choose service: ";
	SetColor(15);
	cin >> iOption;
	int iSoPhieu = 0;
	switch (iOption)
	{
	case 1:
		xuatDsPM();
		system("pause");
		system("cls");
		QLPhieuMuon();
		break;
	case 2:
		ghiMoiPM();
		system("pause");
		system("cls");
		QLPhieuMuon();
		break;
	case 3:
		do {
			SetColor(13);
			cout << "\n\t\tNhap so Phieu muon: ";
			SetColor(15);
			cin >> iSoPhieu;
			if (kiemTraSoPhieuMuon(iSoPhieu) == -2) {
				SetColor(12);
				cout << "\n\t\t\tSo phieu khong ton tai!\n\n";
			}
			if (kiemTraSoPhieuMuon(iSoPhieu) == -1) {
				SetColor(12);
				cout << "\n\t\t\tPhieu da duoc tra!\n\n";
			}
		} while (kiemTraSoPhieuMuon(iSoPhieu) == -2 || kiemTraSoPhieuMuon(iSoPhieu) == -1);
		for (int i = 0; i < dsSach.size(); i++) {
			if (dsSach[i].getTinhTrangSach() == iSoPhieu) {
				dsSach[i].setTinhTrangSach(0);
				break;
			}
		}
		ghiDsSach();
		for (int i = 0; i < dsPM.size(); i++) {
			if (dsPM[i].getSoPhieuMuon() == iSoPhieu) {
				dsPM[i].setTinhTrangPhieuMuon(0);
				break;
			}
		}
		ghiDsPM();
		SetColor(10);
		cout << "\n\t\t\tTra Sach thanh cong!\n\n";
		system("pause");
		system("cls");
		QLPhieuMuon();
		break;
	default:
		system("cls");
		menuQL();
		break;
	}
}

int kiemTraSoPhieuMuon(int iSoPhieu) {
	for (int i = 0; i < dsPM.size(); i++) {
		if (dsPM[i].getSoPhieuMuon() == iSoPhieu) {
			if (dsPM[i].getTinhTrangPhieuMuon() == 1) return i;
			else return -1;
		}
	}
	return -2;
}

void QLSach() {
	int iOption;
	SetColor(10);
	cout << "\t\t*************************************************" << endl;
	cout << "\t\t*                                               *" << endl;
	cout << "\t\t*                     ";
	SetColor(14);
	cout << "QL SACH";
	SetColor(10);
	cout <<"                   *" << endl;
	cout << "\t\t*                                               *" << endl;
	cout << "\t\t*************************************************" << endl;
	cout << endl;
	SetColor(12);
	cout << "\t\t=================================================" << endl;
	cout << "\t\t= "; SetColor(13); cout << "\t\t1. Xem danh sach Sach";SetColor(12); cout << "           =" << endl;
	cout << "\t\t= "; SetColor(13); cout << "\t\t2. Them Sach";SetColor(12); cout << "                    =" << endl;
	cout << "\t\t= "; SetColor(13); cout << "\t\t3. Xoa Sach";SetColor(12); cout << "                     =" << endl;
	cout << "\t\t= "; SetColor(13); cout << "\t\t4. Thoat";SetColor(12); cout << "                        =" << endl;
	SetColor(12);
	cout << "\t\t=================================================" << endl;
	SetColor(11);
	cout << "\n\t\t-Choose service: ";
	SetColor(15);
	cin >> iOption;
	SACH xSach;
	string sMaSach = "";
	switch (iOption)
	{
	case 1:
		xuatDsSach();
		system("pause");
		system("cls");
		QLSach();
		break;
	case 2:
		do {
			SetColor(11);
			cout << "\n\t\tNhap ma Sach: ";
			rewind(stdin);
			SetColor(15);
			getline(cin, sMaSach);
			if (kiemTraMaSach(sMaSach) == 1)  {
				SetColor(12);
				cout << "\n\t\t\tMa da ton tai!\n";
			}
		} while (kiemTraMaSach(sMaSach) == 1);
		xSach.setMasach(sMaSach);
		cin >> xSach;
		dsSach.push_back(xSach);
		ghiDsSach();
		system("pause");
		system("cls");
		QLSach();
		break;
	case 3:
		do {
			SetColor(11);
			cout << "\n\t\tNhap ma Sach: ";
			rewind(stdin);
			SetColor(15);
			getline(cin, sMaSach);
			if (kiemTraTinhTrangSach(sMaSach) == -2)  {
				SetColor(12);
				cout << "\n\t\t\tMa sach khong ton tai!\n";
			}
			if (kiemTraTinhTrangSach(sMaSach) == -1) {
				SetColor(12);
				cout << "\n\t\t\tSach dang duoc muon!\n\n";
				break;
			}
		} while (kiemTraTinhTrangSach(sMaSach) == -1 || kiemTraTinhTrangSach(sMaSach) == -2);
		if (kiemTraTinhTrangSach(sMaSach) >= 0) {
			dsSach.erase(dsSach.begin() + kiemTraTinhTrangSach(sMaSach)); 
			SetColor(10);
			cout << "\n\t\t\tXoa sach thanh cong\n\n";
			ghiDsSach();
		}
		system("pause");
		system("cls");
		QLSach();
		break;
	default:
		system("cls");
		menuQL();
		break;
	}
}

int kiemTraTinhTrangSach(string sMaSach) {
	for (int i = 0; i < dsSach.size(); i++) {
		if (sMaSach == dsSach[i].getMasach()) {
			if (dsSach[i].getTinhTrangSach() == 0) return i;
			else return -1;
		}
	}
	return -2;
}

bool kiemTraMaSach(string sMaSach) {
	for (int i = 0; i < dsSach.size(); i++) {
		if (sMaSach == dsSach[i].getMasach()) return 1;
	}
	return 0;
}

void QLBanDoc() {
	int iOption;
	SetColor(10);
	cout << "\t\t*************************************************" << endl;
	cout << "\t\t*                                               *" << endl;
	cout << "\t\t*                  ";
	SetColor(14);
	cout << "QL BAN DOC";
	SetColor(10);
	cout <<"                   *" << endl;
	cout << "\t\t*                                               *" << endl;
	cout << "\t\t*************************************************" << endl;
	cout << endl;
	SetColor(12);
	cout << "\t\t=================================================" << endl;
	cout << "\t\t= "; SetColor(13); cout << "\t\t1. Xem ban doc SV";SetColor(12); cout << "               =" << endl;
	cout << "\t\t= "; SetColor(13); cout << "\t\t2. Xem ban doc GV";SetColor(12); cout << "               =" << endl;
	cout << "\t\t= "; SetColor(13); cout << "\t\t3. Them ban doc SV";SetColor(12); cout << "              =" << endl;
	cout << "\t\t= "; SetColor(13); cout << "\t\t4. Them ban doc GV";SetColor(12); cout << "              =" << endl;
	cout << "\t\t= "; SetColor(13); cout << "\t\t5. Thoat";SetColor(12); cout << "                        =" << endl;
	SetColor(12);
	cout << "\t\t=================================================" << endl;
	SetColor(11);
	cout << "\n\t\t-Choose service: ";
	SetColor(15);
	cin >> iOption;
	SINHVIEN xSV;
	GIAOVIEN xGV;
	string sMaBD = "";
	switch (iOption)
	{
	case 1:
		xuatDsSV();
		system("pause");
		system("cls");
		QLBanDoc();
		break;
	case 2:
		xuatDsGV();
		system("pause");
		system("cls");
		QLBanDoc();
		break;
	case 3:
		do {
			SetColor(11);
			cout << "\n\t\tNhap ma ban doc: ";
			rewind(stdin);
			SetColor(15);
			getline(cin, sMaBD);
			if (kiemTraMaBD(sMaBD) == 1)  {
				SetColor(12);
				cout << "\n\t\t\tMa da ton tai!\n";
			}
		} while (kiemTraMaBD(sMaBD) == 1);
		xSV.setMabandoc(sMaBD);
		cin >> xSV;
		dsSV.push_back(xSV);
		ghiDsSV();
		SetColor(10);
		cout << "\n\t\t\tThem ban doc thanh cong\n\n";
		system("pause");
		system("cls");
		QLBanDoc();
		break;
	case 4:
		do {
			SetColor(11);
			cout << "\n\t\tNhap ma ban doc: ";
			rewind(stdin);
			SetColor(15);
			getline(cin, sMaBD);
			if (kiemTraMaBD(sMaBD) == 1)  {
				SetColor(12);
				cout << "\n\t\t\tMa da ton tai!\n";
			}
		} while (kiemTraMaBD(sMaBD) == 1);
		xGV.setMabandoc(sMaBD);
		cin >> xGV;
		cout << endl;
		dsGV.push_back(xGV);
		ghiDsGV();
		SetColor(10);
		cout << "\n\t\t\tThem ban doc thanh cong\n\n";
		system("pause");
		system("cls");
		QLBanDoc();
		break;
	default:
		system("cls");
		menuQL();
		break;
	}
}

bool kiemTraMaBD(string sMaBD) {
	for (int i = 0; i < dsSV.size(); i++) {
		if (sMaBD == dsSV[i].getMabandoc()) return 1;
	}
	for (int i = 0; i < dsGV.size(); i++) {
		if (sMaBD == dsGV[i].getMabandoc()) return 1;
	}
	return 0;
}

void QLThongKe() {
	int iOption;
	SetColor(10);
	cout << "\t\t*************************************************" << endl;
	cout << "\t\t*                                               *" << endl;
	cout << "\t\t*                   ";
	SetColor(14);
	cout << "THONG KE";
	SetColor(10);
	cout <<"                    *" << endl;
	cout << "\t\t*                                               *" << endl;
	cout << "\t\t*************************************************" << endl;
	cout << endl;
	SetColor(12);
	cout << "\t\t=================================================" << endl;
	cout << "\t\t= "; SetColor(13); cout << "\t1. Tong so sach con lai trong thu vien";SetColor(12); cout << "  =" << endl;
	cout << "\t\t= "; SetColor(13); cout << "\t2. Tong so sach da muon";SetColor(12); cout << "                 =" << endl;
	cout << "\t\t= "; SetColor(13); cout << "\t3. Liet ke sach ma chua duoc muon";SetColor(12); cout << "       =" << endl;
	cout << "\t\t= "; SetColor(13); cout << "\t4. Liet ke sach ma ban doc da muon";SetColor(12); cout << "      =" << endl;
	cout << "\t\t= "; SetColor(13); cout << "\t5. Tong so phieu muon chua tra";SetColor(12); cout << "          =" << endl;
	cout << "\t\t= "; SetColor(13); cout << "\t6. Thoat";SetColor(12); cout << "                                =" << endl;
	SetColor(12);
	cout << "\t\t=================================================" << endl;
	SetColor(11);
	cout << "\n\t\t-Choose service: ";
	SetColor(15);
	cin >> iOption;
	int nTong = 0;
	switch (iOption)
	{
	case 1:
		for (int i = 0; i < dsSach.size(); i++) {
			if (dsSach[i].getTinhTrangSach() == 0) {
				nTong++;
			}
		}
		SetColor(14);
		cout << "\n\t\tTong so sach con lai trong thu vien: " << nTong << endl << endl;
		system("pause");
		system("cls");
		QLThongKe();
		break;
	case 2:
		for (int i = 0; i < dsSach.size(); i++) {
			if (dsSach[i].getTinhTrangSach() != 0) {
				nTong++;
			}
		}
		SetColor(14);
		cout << "\n\t\tTong so sach da muon: " << nTong << endl << endl;
		system("pause");
		system("cls");
		QLThongKe();
		break;
	case 3:
		for (int i = 0; i < dsSach.size(); i++) {
			if (dsSach[i].getTinhTrangSach() == 0) {
				SetColor(14);
				cout << "\n\t\t- Sach thu " << nTong + 1 << " -\n";
				cout << dsSach[i];
				nTong++;
			}
		}
		cout << endl;
		SetColor(14);
		if (!nTong) cout << "\n\t\tKhong con sach nao trong thu vien\n\n";
		system("pause");
		system("cls");
		QLThongKe();
		break;
	case 4:
		for (int i = 0; i < dsSach.size(); i++) {
			if (dsSach[i].getTinhTrangSach() != 0) {
				SetColor(14);
				cout << "\n\t\t- Sach thu " << nTong + 1 << " -\n";
				cout << dsSach[i];
				nTong++;
			}
		}
		cout << endl;
		SetColor(14);
		if (!nTong) cout << "\n\t\tKhong co sach nao duoc muon\n\n";
		system("pause");
		system("cls");
		QLThongKe();
		break;
	case 5:
		for (int i = 0; i < dsPM.size(); i++) {
			if (dsPM[i].getTinhTrangPhieuMuon() != 0) {
				nTong++;
			}
		}
		SetColor(14);
		cout << "\n\t\tTong so phieu muon ma chua tra sach: " << nTong << endl << endl;
		system("pause");
		system("cls");
		QLThongKe();
	default:
		system("cls");
		menuQL();
		break;
	}
}

void menuQL() {
	int iOption;
	SetColor(10);
	cout << "\t\t*************************************************" << endl;
	cout << "\t\t*                                               *" << endl;
	cout << "\t\t*                    ";
	SetColor(14);
	cout << "QUAN LY";
	SetColor(10);
	cout <<"                    *" << endl;
	cout << "\t\t*                                               *" << endl;
	cout << "\t\t*************************************************" << endl;
	cout << endl;
	SetColor(12);
	cout << "\t\t=================================================" << endl;
	cout << "\t\t= "; SetColor(13); cout << "\t\t1. Quan ly Phieu muon";SetColor(12); cout << "           =" << endl;
	cout << "\t\t= "; SetColor(13); cout << "\t\t2. Quan ly Sach";SetColor(12); cout << "                 =" << endl;
	cout << "\t\t= "; SetColor(13); cout << "\t\t3. Quan ly Ban doc";SetColor(12); cout << "              =" << endl;
	cout << "\t\t= "; SetColor(13); cout << "\t\t4. Thong ke";SetColor(12); cout << "                     =" << endl;
	cout << "\t\t= "; SetColor(13); cout << "\t\t5. Thoat";SetColor(12); cout << "                        =" << endl;
	SetColor(12);
	cout << "\t\t=================================================" << endl;
	SetColor(11);
	cout << "\n\t\t-Choose service: ";
	SetColor(15);
	cin >> iOption;
	switch (iOption) {
	case 1:
		system("cls");
		QLPhieuMuon();
		break;
	case 2:
		system("cls");
		QLSach();
		break;
	case 3:
		system("cls");
		QLBanDoc();
		break;
	case 4:
		system("cls");
		QLThongKe();
		break;
	default:
		system("cls");
		menu();
		break;
	}
}

void menuTK() {
	int iOption;
	SetColor(10);
	cout << "\t\t*************************************************" << endl;
	cout << "\t\t*                                               *" << endl;
	cout << "\t\t*                   ";
	SetColor(14);
	cout << "TIM KIEM";
	SetColor(10);
	cout <<"                    *" << endl;
	cout << "\t\t*                                               *" << endl;
	cout << "\t\t*************************************************" << endl;
	cout << endl;
	SetColor(12);
	cout << "\t\t=================================================" << endl;
	cout << "\t\t= "; SetColor(13); cout << "\t\t1. Tim kiem Sach";SetColor(12); cout << "                =" << endl;
	cout << "\t\t= "; SetColor(13); cout << "\t\t2. Tim kiem ban doc";SetColor(12); cout << "             =" << endl;
	cout << "\t\t= "; SetColor(13); cout << "\t\t3. Thoat";SetColor(12); cout << "                        =" << endl;
	SetColor(12);
	cout << "\t\t=================================================" << endl;
	SetColor(11);
	cout << "\n\t\t-Choose service: ";
	SetColor(15);
	cin >> iOption;
	string sMaSach;
	string sMaBD;
	bool exist = false;
	switch (iOption) {
	case 1:
		SetColor(11);
		cout << "\n\t\t-Nhap Ma sach: ";
		rewind(stdin);
		SetColor(15);
		getline(cin, sMaSach);
		for (int i = 0; i < dsSach.size(); i++) {
			if (dsSach[i].getMasach() == sMaSach) {
				cout << endl;
				cout << dsSach[i];
				exist = true;
				cout << endl;
				break;
			}
		}
		if (!exist) {
			SetColor(12);
			cout << "\n\t\tTua de sach khong ton tai!\n\n";
		}
		system("pause");
		system("cls");
		menuTK();
		break;
	case 2:
		SetColor(11);
		cout << "\n\t\t-Nhap Ma ban doc: ";
		rewind(stdin);
		SetColor(15);
		getline(cin, sMaBD);
		for (int i = 0; i < dsSV.size(); i++) {
			if (dsSV[i].getMabandoc() == sMaBD) {
				cout << endl;
				cout << dsSV[i];
				exist = true;
				cout << endl;
				break;
			}
		}
		for (int i = 0; i < dsGV.size(); i++) {
			if (dsGV[i].getMabandoc() == sMaBD) {
				system("cls");
				cout << dsGV[i];
				exist = true;
				break;
			}
		}
		if (!exist) {
			SetColor(12);
			cout << "\n\t\tMa ban doc khong ton tai!\n\n";
		}
		system("pause");
		system("cls");
		menuTK();
		break;
	default:
		system("cls");
		menu();
		break;
	}
}

void menu() {
	int iOption;
	SetColor(10);
	cout << "\t\t*************************************************" << endl;
	cout << "\t\t*                                               *" << endl;
	cout << "\t\t*                   ";
	SetColor(14);
	cout << "BOOK MENU";
	SetColor(10);
	cout <<"                   *" << endl;
	cout << "\t\t*                                               *" << endl;
	cout << "\t\t*************************************************" << endl;
	cout << endl;
	SetColor(12);
	cout << "\t\t=================================================" << endl;
	cout << "\t\t= "; SetColor(13); cout << "\t\t1. Hien thi thong tin Sach";SetColor(12); cout << "      =" << endl;
	cout << "\t\t= "; SetColor(13); cout << "\t\t2. Hien thi thong tin Ban doc";SetColor(12); cout << "   =" << endl;
	cout << "\t\t= "; SetColor(13); cout << "\t\t3. Tim kiem thong tin";SetColor(12); cout << "           =" << endl;
	cout << "\t\t= "; SetColor(13); cout << "\t\t4. Quan ly";SetColor(12); cout << "                      =" << endl;
	cout << "\t\t= "; SetColor(13); cout << "\t\t5. Thoat";SetColor(12); cout << "                        =" << endl;
	SetColor(12);
	cout << "\t\t=================================================" << endl;
	SetColor(11);
	cout << "\n\t\t-Choose service: ";
	SetColor(15);
	cin >> iOption;
	switch (iOption) {
	case 1:
		system("cls");
		xuatDsSach();
		cout << endl;
		system("pause");
		system("cls");
		menu();
		break;
	case 2:
		xuatDsSV();
		xuatDsGV();
		system("pause");
		system("cls");
		menu();
	case 3:
		system("cls");
		menuTK();
		break;
	case 4:
		if (isAdmin == 1) {
			system("cls");
			menuQL();
			break;
		}
		else {
			SetColor(12);
			cout << "\n\t\t\tBan khong co quyen truy cap vao day!\n\n";
			system("pause");
			system("cls");
			menu();
			break;
		}
	default:
		system("cls");
		isAdmin = 0;
		login();
		break;
	}
}

std::string inputPassword(size_t length_max)
{
    std::string strRet;
    char ch = 0;
    bool bShow = false;
    do {
        ch = getch();
        if((strRet.size() < length_max) &&
           (::isalpha(ch) || ::isalnum(ch)))
        {
            std::cout << (bShow ? ch : '*');
            strRet.push_back(ch);
        }
        else
        {
            if(0x1B == ch)
            {
                bShow = !bShow;
 
                std::cout << std::string(strRet.size(), '\b');
           
                if(bShow)
                    std::cout << strRet;
                else
                    std::cout << std::string(strRet.size(), '*');
               
            }
            if('\b' == ch && !strRet.empty())
            {
                std::cout << "\b \b";
                strRet.resize(strRet.size() - 1);
            }
        }
 
    }while ('\r' != ch);
    std::cout << std::endl;
    return strRet;
}

void login() {
	SetColor(10);
	cout << "\t\t*************************************************" << endl;
	cout << "\t\t*                                               *" << endl;
	cout << "\t\t*                    ";
	SetColor(14);
	cout << "SIGN IN";
	SetColor(10);
	cout <<"                    *" << endl;
	cout << "\t\t*                                               *" << endl;
	cout << "\t\t*************************************************" << endl;
	cout << endl;

	SetColor(13);
	cout << "\t\t\t 1. Administrator\n";
	cout << "\t\t\t 2. Ban doc\n\n";
	SetColor(11);
	cout << "\t\t\t\t - Ban la: ";
	int iOption;
	SetColor(15);
	cin >> iOption;

	if (iOption == 2) {
		system("cls");
		isAdmin = 0;
		menu();
	} else system("cls");

	int limit = 0;	

	while(limit < 3) {
		SetColor(10);
		cout << "\t\t*************************************************" << endl;
		cout << "\t\t*                                               *" << endl;
		cout << "\t\t*                    ";
		SetColor(14);
		cout << "SIGN IN";
		SetColor(10);
		cout <<"                    *" << endl;
		cout << "\t\t*                                               *" << endl;
		cout << "\t\t*************************************************" << endl;
		cout << endl;
		SetColor(13);
		string sUsername = "";
		cout << "\t\t\t-  Username:   ";
		SetColor(15);
		rewind(stdin);
		getline(cin, sUsername);

		SetColor(13);
		string sPass = "";
		char ch;
		cout << "\t\t\t-  Password:   ";
		SetColor(15);
		sPass = inputPassword(20);

		if (checkUsername(sUsername, sPass) == 1){
			isAdmin = true;
			SetColor(10);
			cout << "\n\n\t\t\t      Dang nhap thong cong!!!\n";
			cout << "\n\t\t\t\t\t\t";
			loading(1);
			system("cls");
			menu();
		}
		else {
			SetColor(12);
			cout << "\n\t\t\t      Sai ten hoac mat khau!\n";
			limit++;
			if (limit == 1) {
				cout << "\n\t\t\t      *Chu y: con 2 lan thu!\n" << endl;
			}
			if (limit == 2) {
				cout << "\n\t\t\t      *Chu y: con 1 lan thu!\n" << endl;
			}
			if (limit == 3) {
				cout << "\n\t\t\t      Qua so lan dang nhap!!!\n" << endl;
				break;
			}
			system("pause");
			system("cls");
		}
	}
}
void loading(int iTime) {
	for (int i = 0; i < iTime; i++) {
        std::cout << "\b\b\b\b\b\b\b\b\b\bLoading   " << std::flush;
        Sleep(200);
        std::cout << "\b\b\b\b\b\b\b\b\b\bLOading   " << std::flush;
        Sleep(200);
        std::cout << "\b\b\b\b\b\b\b\b\b\bLoAding   " << std::flush;
        Sleep(200);
        std::cout << "\b\b\b\b\b\b\b\b\b\bLoaDing   " << std::flush;
        Sleep(200);
        std::cout << "\b\b\b\b\b\b\b\b\b\bLoadIng   " << std::flush;
        Sleep(200);
        std::cout << "\b\b\b\b\b\b\b\b\b\bLoadiNg   " << std::flush;
        Sleep(200);
        std::cout << "\b\b\b\b\b\b\b\b\b\bLoadinG   " << std::flush;
        Sleep(200);
        std::cout << "\b\b\b\b\b\b\b\b\b\bLoading.  " << std::flush;
        Sleep(200);
        std::cout << "\b\b\b\b\b\b\b\b\b\bLoading.. " << std::flush;
        Sleep(200);
        std::cout << "\b\b\b\b\b\b\b\b\b\bLoading..." << std::flush;
        Sleep(200);
    }
	cout << endl;
}

int checkUsername(string sUser, string sPass) {
	for (int i = 0; i < dsAdmin.size(); i++) {
		if (dsAdmin[i].getUsername() == sUser && dsAdmin[i].getPassword() == sPass) {
			return 1;
		}
	}
	return 0;
}
void docDsPM() {
	ifstream docFile;
	docFile.open("Phieu_Muon.dat");
	while (docFile.eof() != 1) {
		PHIEUMUON xPM;
		docFile >> xPM;
		dsPM.push_back(xPM);
		docFile.ignore(1);
	}
	docFile.close();
}
void docDsSV() {
	ifstream docFile;
	docFile.open("User_Data_SV.dat");
	while (docFile.eof() != 1) {
		SINHVIEN xSV;
		docFile >> xSV;
		dsSV.push_back(xSV);
	}
	docFile.close();
}
void xuatDsSV() {
	for (int i = 0; i < dsSV.size(); i++) {
		SetColor(14);
		cout << "\n\t\t- Sinh vien " << i + 1 << " -\n";
		cout << dsSV[i];
	}
}
void docDsGV() {
	ifstream docFile;
	docFile.open("User_Data_GV.dat");
	while (docFile.eof() != 1) {
		GIAOVIEN xGV;
		docFile >> xGV;
		dsGV.push_back(xGV);
	}
	docFile.close();
}
void xuatDsPM() {
	for (int i = 0; i < dsPM.size(); i++) {
		SetColor(14);
		cout << "\n\t\t- Phieu muon " << i + 1 << " -\n";
		cout << dsPM[i];
	}
}
void xuatDsGV() {
	for (int i = 0; i < dsGV.size(); i++) {
		SetColor(14);
		cout << "\n\t\t- Giao vien " << i + 1 << " -\n";
		cout << dsGV[i];
	}
}
void xuatDsAdmin() {
	for (int i = 0; i < dsAdmin.size(); i++) {
		SetColor(14);
		cout << "\n\t\t- Admin " << i + 1 << " -\n";
		cout << dsAdmin[i];
	}
}

void docDsAdmin() {
	ifstream docFile;
	docFile.open("Administrator.dat");
	while (docFile.eof() != 1) {
		Administrator xAdmin;
		docFile >> xAdmin;
		dsAdmin.push_back(xAdmin);
	}
	docFile.close();
}
void ghiMoiPM() {
	ofstream ghiFile;
	ghiFile.open("Phieu_Muon.dat", ios_base::app);

	string sMaBD;
	string sMaSach;

	do {
		SetColor(11);
		cout << "\n\t\tMa Ban doc: ";
		rewind(stdin);
		SetColor(15);
		getline(cin, sMaBD);
		if (kiemTraMaBD(sMaBD) == 0) {
			SetColor(12);
			cout << "\n\t\t\tMa Ban doc khong ton tai!\n\n";
		}
	} while (kiemTraMaBD(sMaBD) == 0);
	
	do {
		SetColor(11);
		cout << "\t\tMa Sach: ";
		rewind(stdin);
		SetColor(15);
		getline(cin, sMaSach);
		if (kiemTraMaSach(sMaSach) == 0) {
			SetColor(12);
			cout << "\n\t\t\tMa Sach khong ton tai!\n\n";
		}
		if (kiemTraTinhTrangSach(sMaSach) == -1) {
			SetColor(12);
			cout << "\n\t\t\tSach dang duoc muon!\n\n";
		}
	} while (kiemTraMaSach(sMaSach) == 0 || kiemTraTinhTrangSach(sMaSach) == -1);

	PHIEUMUON xPM(sMaBD, sMaSach);
	ghiFile << endl;
	ghiFile << xPM;
	ghiFile.close();

	dsPM.push_back(xPM);

	for (int i = 0; i < dsSach.size(); i++) {
		if (dsSach[i].getMasach() == sMaSach) {
			dsSach[i].setTinhTrangSach(xPM.getSoPhieuMuon());
			ghiDsSach();
			break;
		}
	}
	SetColor(10);
	cout << "\n\t\tTao moi Phieu muon thanh cong!\n\n";
}
void ghiDsPM() {
	ofstream ghiFile;
	ghiFile.open("Phieu_Muon.dat");
	for (int i = 0; i < dsPM.size(); i++) {
		//ghiFile << dsPM[i];
		ghiFile << dsPM[i].getSoPhieuMuon() << '#';
		ghiFile << dsPM[i].getMaBD() << '#';
		ghiFile << dsPM[i].getMaSach() << '#';
		ghiFile << dsPM[i].getNgayMuon() << '#';
		ghiFile << dsPM[i].getNgayTra() << '#';
		ghiFile << dsPM[i].getTinhTrangPhieuMuon();
		if (i != dsPM.size() - 1) {
			ghiFile << endl;
		}
	}
	ghiFile.close();
}
void ghiDsSV() {
	ofstream ghiFile;
	ghiFile.open("User_Data_SV.dat");
	for (int i = 0; i < dsSV.size(); i++) {
		ghiFile << dsSV[i];
		if (i != dsSV.size() - 1) {
			ghiFile << endl;
		}
	}
	ghiFile.close();
}

void ghiDsGV() {
	ofstream ghiFile;
	ghiFile.open("User_Data_GV.dat");
	for (int i = 0; i < dsGV.size(); i++) {
		ghiFile << dsGV[i];
		if (i != dsGV.size() - 1) {
			ghiFile << endl;
		}
	}
	ghiFile.close();
}

void ghiDsSach() {
	ofstream ghiFile;
	ghiFile.open("Book_Data.dat");
	for (int i = 0; i < dsSach.size(); i++) {
		ghiFile << dsSach[i];
		if (i != dsSach.size() - 1) {
			ghiFile << endl;
		}
	}
	ghiFile.close();
}

void xuatDsSach() {
	for (int i = 0; i < dsSach.size(); i++) {
		SetColor(14);
		cout << "\n\t\t- Thong tin sach " << i + 1 << " -\n";
		cout << dsSach[i];
	}
}

void docDsSach() {
	ifstream docFile;
	docFile.open("Book_Data.dat");
	while (docFile.eof() != 1) {
		SACH xS;
		docFile >> xS;
		dsSach.push_back(xS);
		docFile.ignore(1);
	}
	docFile.close();
}

void SetColor(int ForgC) 
{ 
    WORD wColor; 

     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE); 
     CONSOLE_SCREEN_BUFFER_INFO csbi; 

         //We use csbi for the wAttributes word. 
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi)) 
    { 
       //Mask out all but the background attribute, and add in the forgournd  color 
      wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F); 
      SetConsoleTextAttribute(hStdOut, wColor); 
    } 
    return; 
} 