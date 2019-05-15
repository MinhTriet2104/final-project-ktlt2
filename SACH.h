#pragma once
#include "Date.h"
#include <string>
#include <windows.h>
using namespace std;

class PHIEUMUON;
class SACH
{
private:
	string sMaSach;
	string sTuaDe;
	string sTacGia;
	string sNhaXuatBan;
	Date xNgayNhapKho;
	int	iTriGia;
	int	iNamPhatHanh;
	int	iSoTrang;
	int iTinhTrangSach;

public:
	friend PHIEUMUON;
	SACH()
	{
		sMaSach = "";
		sTuaDe = "";
		sTacGia = "";
		sNhaXuatBan = "";
		iTriGia = 0;
		iNamPhatHanh = 0;
		iSoTrang = 0;
		iTinhTrangSach = 0;

	}
	SACH(string sMaSach) {
		this->sMaSach = sMaSach;
	}

	SACH(string sMaSach, string sTuaDe, string sTacGia, string sNhaXuatBan,
	int iNgay, int iThang, int iNam, int iTriGia, int iNamPhatHanh, int iSoTrang,
	int iTinhTrangSach) : xNgayNhapKho(iNgay, iThang, iNam) {
		this->sMaSach = sMaSach;
		this->sTuaDe = sTuaDe;
		this->sTacGia = sTacGia;
		this->sNhaXuatBan = sNhaXuatBan;
		this->iTriGia = iTriGia;
		this->iNamPhatHanh = iNamPhatHanh;
		this->iSoTrang = iSoTrang;
		this->iTinhTrangSach = 0;
	}

	string getMasach();
	string getTuaDe();
	string getTacGia();
	string getNhaXuatBan();
	int getTriGia();
	int getNamPhatHanh();
	int getSoTrang();
	int getTinhTrangSach();

	void setMasach(string sMaSach);
	void setTuaDe(string sTuaDe);
	void setTacGia(string sTacGia);
	void setNhaXuatBan(string sNhaXuatBan);
	void setTriGia(int iTriGia);
	void setNamPhatHanh(int iNamPhatHanh);
	void setSoTrang(int iSoTrang);
	void setTinhTrangSach(int iTinhTrangSach);
	void setSach(string sMaSach, string sTuaDe, string sTacGia, string sNhaXuatBan,
		string sNgayNhapKho, int iTriGia, int iNamPhatHanh, int iSoTrang, int iTinhTrangSach);

	//Dinh nghia toan tu nhap/xuat:
	friend istream& operator >> (istream &is, SACH &xS) {
		SetColor(11);
		cout << "\t\tNhap Tua de: ";
		rewind(stdin);
		SetColor(15);
		getline(cin, xS.sTuaDe);

		SetColor(11);
		cout << "\t\tNhap Tac gia: ";
		rewind(stdin);
		SetColor(15);
		getline(cin, xS.sTacGia);

		SetColor(11);
		cout << "\t\tNhap nha xuat ban: ";
		rewind(stdin);
		SetColor(15);
		getline(cin, xS.sNhaXuatBan);

		SetColor(11);
		cout << "\t\tNhap tri gia: ";
		SetColor(15);
		cin >> xS.iTriGia;

		SetColor(11);
		cout << "\t\tNhap nam phat hanh: ";
		SetColor(15);
		cin >> xS.iNamPhatHanh;

		SetColor(11);
		cout << "\t\tNhap so trang: ";
		SetColor(15);
		cin >> xS.iSoTrang;

		return is;
	}

	friend ostream& operator << (ostream &os, SACH &xS) {
		SetColor(13);
		os << "\t\tMa sach : ";
		SetColor(15);
		os << xS.sMaSach << endl;

		SetColor(13);
		os << "\t\tTua de : ";
		SetColor(15);
		os << xS.sTuaDe << endl;

		SetColor(13);
		os << "\t\tTac gia : ";
		SetColor(15);
		os << xS.sTacGia << endl;

		SetColor(13);
		os << "\t\tNha xuat ban : ";
		SetColor(15);
		os << xS.sNhaXuatBan << endl;

		SetColor(13);
		os << "\t\tNgay nhap kho : ";
		SetColor(15);
		os << xS.xNgayNhapKho;

		SetColor(13);
		os << "\t\tTri gia : ";
		SetColor(15);
		os << xS.iTriGia << endl;

		SetColor(13);
		os << "\t\tNam phat hanh : ";
		SetColor(15);
		os << xS.iNamPhatHanh << endl;

		SetColor(13);
		os << "\t\tSo trang : ";
		SetColor(15);
		os << xS.iSoTrang << endl;

		SetColor(13);
		os << "\t\tTinh trang sach : ";
		SetColor(15);
		os << xS.iTinhTrangSach << endl;

		return os;
	}

	//Doc va ghi file
	friend ifstream& operator >> (ifstream &ifs, SACH &xS) {
		getline(ifs, xS.sMaSach, '#');

		getline(ifs, xS.sTuaDe, '#');

		getline(ifs, xS.sTacGia, '#');

		getline(ifs, xS.sNhaXuatBan, '#');

		ifs >> xS.xNgayNhapKho;
		ifs.ignore(1);

		ifs >> xS.iTriGia;
		ifs.ignore(1);

		ifs >> xS.iNamPhatHanh;
		ifs.ignore(1);

		ifs >> xS.iSoTrang;
		ifs.ignore(1);

		ifs >> xS.iTinhTrangSach;

		return ifs;
	}

	friend ofstream& operator << (ofstream &ofs, SACH &xS) {
		ofs << xS.sMaSach << '#';
		ofs << xS.sTuaDe << '#';
		ofs << xS.sTacGia << '#';
		ofs << xS.sNhaXuatBan << '#';
		ofs << xS.xNgayNhapKho << '#';
		ofs << xS.iTriGia << '#';
		ofs << xS.iNamPhatHanh << '#';
		ofs << xS.iSoTrang << '#';
		ofs << xS.iTinhTrangSach;

		return ofs;
	}

	static void SetColor(int ForgC) 
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

	~SACH() {};

};