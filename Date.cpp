#include "Date.h"

int Date::getNgay()
{
	return iNgay;
}
int Date::getThang()
{
	return iThang;
}
int Date::getNam()
{
	return iNam;
}
void Date::setNgay(int iNgay)
{
	this->iNgay = iNgay;
}
void Date::setThang(int iThang)
{
	this->iThang = iThang;
}
void Date::setNam(int iNam)
{
	this->iNam = iNam;
}
void Date::setDate(int iNgay, int iThang, int iNam)
{
	this->iNgay = iNgay;
	this->iThang = iThang;
	this->iNam = iNam;
}