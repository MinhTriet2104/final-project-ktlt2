#pragma once
#include "BANDOC.h"
class GIAOVIEN :
	public BANDOC
{
private:
	string sDiaChi;
	string sSDT;
public:
	GIAOVIEN()
	{
		this->sDiaChi = "";
		this->sSDT = "";
	}
	GIAOVIEN(string sMaBanDoc, string sHoTen, string sKhoa, string sDiaChi, string sSDT, int iNgay, int iThang, int iNam)
		:BANDOC(sHoTen, sKhoa, sMaBanDoc, iNgay, iThang, iNam)
	{
		this->sDiaChi = sDiaChi;
		this->sSDT = sSDT;
	}
	string getDiachi();
	string getSDT();
	void setDiachi(string sDiaChi);
	void setSDT(string sSDT);
	void setGIAOVIEN(string sDiaChi, string sSDT);

	friend istream& operator >> (istream&is, GIAOVIEN &xGV) {
		SetColor(11);
		cout << "\t\tNhap Ho ten: ";
		rewind(stdin);
		SetColor(15);
		getline(is, xGV.sHoTen);

		SetColor(11);
		cout << "\t\tKhoa: ";
		rewind(stdin);
		SetColor(15);
		getline(is, xGV.sKhoa);

		SetColor(11);
		cout << "\t\tDia Chi: ";
		rewind(stdin);
		SetColor(15);
		getline(is, xGV.sDiaChi);

		SetColor(11);
		cout << "\t\tSDT: ";
		rewind(stdin);
		SetColor(15);
		getline(is, xGV.sSDT);

		return is;
	}
	friend ostream& operator << (ostream&os, GIAOVIEN &xGV) {
		SetColor(13);
		os << "\t\tMa ban doc: ";
		SetColor(15);
		os << xGV.sMaBanDoc << endl;

		SetColor(13);
		os << "\t\tHo va ten: ";
		SetColor(15);
		os << xGV.sHoTen << endl;

		SetColor(13);
		os << "\t\tKhoa: ";
		SetColor(15);
		os << xGV.sKhoa << endl;

		SetColor(13);
		os << "\t\tNgay tham gia: ";
		SetColor(15);
		os << xGV.xNgayThamGia;

		SetColor(13);
		os << "\t\tDiaChi: ";
		SetColor(15);
		os << xGV.sDiaChi << endl;

		SetColor(13);
		os << "\t\tSDT: ";
		SetColor(15);
		os << xGV.sSDT << endl;

		return os;
	}
	friend ifstream& operator >> (ifstream &ifs, GIAOVIEN &xGV) {
		getline(ifs, xGV.sMaBanDoc, '#');
		getline(ifs, xGV.sHoTen, '#');
		getline(ifs, xGV.sKhoa, '#');
		ifs >> xGV.xNgayThamGia;
		ifs.ignore(1);
		getline(ifs, xGV.sDiaChi, '#');
		getline(ifs, xGV.sSDT);
		return ifs;
	}
	friend ofstream& operator << (ofstream &ofs, GIAOVIEN &xGV) {
		ofs << xGV.sMaBanDoc << '#';
		ofs << xGV.sHoTen << '#';
		ofs << xGV.sKhoa << '#';
		ofs << xGV.xNgayThamGia << '#';
		ofs << xGV.sDiaChi << '#';
		ofs << xGV.sSDT;
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

	~GIAOVIEN() {};
};

