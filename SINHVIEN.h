#pragma once
#include "BANDOC.h"
class SINHVIEN :
	public BANDOC
{
private:
	string sKhoaHoc;
public:
	SINHVIEN()
	{
		this->sKhoaHoc = "";
	}
	SINHVIEN(string sMaBanDoc, string sHoTen, string sKhoa, int iNgay, int iThang, int iNam, string sKhoaHoc) :
		BANDOC(sMaBanDoc, sHoTen, sKhoa, iNgay, iThang, iNam)
	{
		this->sKhoaHoc = sKhoaHoc;
	}

	string getKhoahoc();
	void setKhoahoc(string sKhoaHoc);

	friend istream& operator >> (istream&is, SINHVIEN &xSV) {
		SetColor(11);
		cout << "\t\tNhap ho ten: ";
		rewind(stdin);
		SetColor(15);
		getline(is, xSV.sHoTen);

		SetColor(11);
		cout << "\t\tNhap khoa: ";
		rewind(stdin);
		SetColor(15);
		getline(is, xSV.sKhoa);

		SetColor(11);
		cout << "\t\tNhap Khoa hoc: ";
		rewind(stdin);
		SetColor(15);
		getline(is,xSV.sKhoaHoc);

		return is;
	}
	friend ostream& operator << (ostream&os, SINHVIEN &xSV) {
		SetColor(13);
		os << "\t\tMa ban doc: ";
		SetColor(15);
		os << xSV.sMaBanDoc << endl;

		SetColor(13);
		os << "\t\tHo va ten: ";
		SetColor(15);
		os << xSV.sHoTen << endl;

		SetColor(13);
		os << "\t\tKhoa: ";
		SetColor(15);
		os << xSV.sKhoa << endl;

		SetColor(13);
		os << "\t\tNgay tham gia: ";
		SetColor(15);
		os << xSV.xNgayThamGia;

		SetColor(13);
		os << "\t\tKhoa hoc: ";
		SetColor(15);
		os << xSV.sKhoaHoc << endl;

		return os;
	}
	//doc va ghi file
	friend ifstream& operator >> (ifstream &ifs, SINHVIEN &xSV) {
		getline(ifs, xSV.sMaBanDoc, '#');

		getline(ifs, xSV.sHoTen, '#');

		getline(ifs, xSV.sKhoa, '#');

		ifs >> xSV.xNgayThamGia;
		ifs.ignore(1);

		getline(ifs, xSV.sKhoaHoc);

		return ifs;
	}
	friend ofstream& operator << (ofstream &ofs, SINHVIEN &xSV) {
		ofs << xSV.sMaBanDoc << '#';
		ofs << xSV.sHoTen << '#';
		ofs << xSV.sKhoa << '#';
		ofs << xSV.xNgayThamGia << '#';
		ofs << xSV.sKhoaHoc;
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

	~SINHVIEN() {};
};

