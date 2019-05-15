#pragma once
#include "Date.h"
#include "BANDOC.h"
#include "SACH.h"

class PHIEUMUON
{
private:
	static int iSoPhieuMuon;
	int iSoPhieu;
	BANDOC xBD;
	SACH xSach;
	string sMaBD;
	string sMaSach;
	Date xNgayMuon;
	Date xNgayTra;
	int iTinhTrangPhieuMuon;
public:
	PHIEUMUON() {
		iSoPhieuMuon++;
		this->iSoPhieu = iSoPhieuMuon;
		this->iTinhTrangPhieuMuon = 1;
		this->xNgayTra = tinhNgayTra();
	}

	PHIEUMUON(string sMaBD, string sMaSach) : xBD(sMaBD), xSach(sMaSach)  {
		iSoPhieuMuon++;
		this->iSoPhieu = iSoPhieuMuon;
		this->sMaBD = sMaBD;
		this->sMaSach = sMaSach;
		//this->xNgayMuon.iNgay = 25;
		//this->xNgayMuon.iThang = 5;
		//this->xNgayMuon.iNam = 2019;
		this->xNgayTra = this->tinhNgayTra();
		this->iTinhTrangPhieuMuon = 1;
	}
	
	void setMaSV(string sMaSV);
	void setMaGV(string sMaGV);
	int	getSoPhieuMuon();
	Date getNgayMuon() {
		return this->xNgayMuon;
	}
	Date tinhNgayTra();
	int getTinhTrangPhieuMuon();
	string getMaBD() {
		return this->sMaBD;
	}
	string getMaSach() {
		return this->sMaSach;
	}
	Date getNgayTra() {
		return this->xNgayTra;
	}
	void setSoPhieuMuon(int iSoPhieu);
	void setTinhTrangPhieuMuon(int iTinhTrangPhieuMuon);
	//Dinh nghia toan tu nhap/xuat:
	friend istream& operator >> (istream&is, PHIEUMUON &xPM) {	
		SetColor(11);
		cout << "\t\tMa Ban doc: ";
		rewind(stdin);
		SetColor(15);
		getline(is, xPM.sMaBD);

		SetColor(11);
		cout << "\t\tMa Sach: ";
		rewind(stdin);
		SetColor(15);
		getline(is, xPM.sMaSach);

		return is;
	}
	friend ostream& operator << (ostream&os, PHIEUMUON &xPM) {
		SetColor(13);
		os << "\t\tSo phieu muon : ";
		SetColor(15);
		os << xPM.iSoPhieu << endl;

		SetColor(13);
		os << "\t\tMa Ban doc: ";
		SetColor(15);
		os << xPM.sMaBD << endl;

		SetColor(13);
		os << "\t\tMa Sach: ";
		SetColor(15);
		os << xPM.sMaSach << endl;

		SetColor(13);
		os << "\t\tNgay muon : ";
		SetColor(15);
		os << xPM.xNgayMuon;

		SetColor(13);
		os << "\t\tNgay tra : ";
		SetColor(15);
		os << xPM.xNgayTra;

		SetColor(13);
		os << "\t\tTinh trang phieu muon : ";
		SetColor(15);
		os << xPM.iTinhTrangPhieuMuon << endl;

		return os;
	}
	//Doc va ghi file
	friend ifstream& operator >> (ifstream &ifs, PHIEUMUON &xPM) {
		ifs >> xPM.iSoPhieu;
		ifs.ignore(1);
		getline(ifs, xPM.sMaBD, '#');
		getline(ifs, xPM.sMaSach, '#');

		ifs >> xPM.xNgayMuon;
		ifs.ignore(1);

		ifs >> xPM.xNgayTra;
		ifs.ignore(1);

		ifs >> xPM.iTinhTrangPhieuMuon;

		return ifs;
	}

	friend ofstream& operator << (ofstream &ofs, PHIEUMUON &xPM) {
		ofs << xPM.iSoPhieuMuon << '#';
		ofs << xPM.sMaBD << '#';
		ofs << xPM.sMaSach << '#';
		ofs << xPM.xNgayMuon << '#';
		ofs << xPM.xNgayTra << '#';
		ofs << xPM.iTinhTrangPhieuMuon;
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

	~PHIEUMUON() {};
};

