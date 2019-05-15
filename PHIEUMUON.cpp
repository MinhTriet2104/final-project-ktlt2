#include "PHIEUMUON.h"

int	PHIEUMUON::getSoPhieuMuon()
{
	return this->iSoPhieu;
}
int PHIEUMUON::getTinhTrangPhieuMuon()
{
	return iTinhTrangPhieuMuon;
}
void PHIEUMUON::setTinhTrangPhieuMuon(int iTinhTrangPhieuMuon)
{
	this->iTinhTrangPhieuMuon = iTinhTrangPhieuMuon;
}

Date PHIEUMUON::tinhNgayTra() {
	Date xNgayTra = this->xNgayMuon;
	xNgayTra.iNgay += 7;
	switch (xNgayTra.iThang) {
	case 2:
		if (xNgayTra.iNam % 400 == 0 || xNgayTra.iNam % 4 == 0 && xNgayTra.iNam % 100 != 0) {
			if (xNgayTra.getNgay() > 29) {
				xNgayTra.iNgay -= 29;
				xNgayTra.iThang++;
			} else {
				xNgayTra.iNgay -= 28;
				xNgayTra.iThang++;
			}
		}
		break;
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		if (xNgayTra.getNgay() > 31) {
			xNgayTra.iNgay -= 31;
			xNgayTra.iThang++;
		}
		if (xNgayTra.iThang > 12) {
			xNgayTra.iThang = 1;
			xNgayTra.iNam++;
		}
		break;
	default:
		if (xNgayTra.getNgay() > 30) {
			xNgayTra.iNgay -= 30;
			xNgayTra.iThang++;
		}
		break;
	}
	return xNgayTra;
}