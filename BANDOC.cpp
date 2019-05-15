#include "BANDOC.h"

string BANDOC::getHoten()
{
	return sHoTen;
}
string BANDOC::getKhoa()
{
	return sKhoa;
}
string BANDOC::getMabandoc()
{
	return sMaBanDoc;
}
void BANDOC::setHoten(string sHoTen)
{
	this->sHoTen = sHoTen;
}
void BANDOC::setKhoa(string sKhoa)
{
	this->sKhoa = sKhoa;
}
void BANDOC::setMabandoc(string sMaBanDoc)
{
	this->sMaBanDoc = sMaBanDoc;
}
void BANDOC::setBandoc(string sHoTen, string sKhoa, string sMaBanDoc)
{
	this->sHoTen = sHoTen;
	this->sKhoa = sKhoa;
	this->sMaBanDoc = sMaBanDoc;
}

