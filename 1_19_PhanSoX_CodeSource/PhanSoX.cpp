#include "PhanSoX.h"
using namespace std;

//Phuong thuc khoi tao
PhanSoX::PhanSoX(int tuSo, int mauSo) : m_tuSo(tuSo), m_mauSo(mauSo){
    rutGon();
}

PhanSoX:: PhanSoX(int giaTri) : m_tuSo(giaTri), m_mauSo(1){
}

PhanSoX:: PhanSoX() : m_tuSo(0), m_mauSo(1){
}

//Hien thi
void PhanSoX::hienThi(ostream& luong) const {
    if(m_mauSo == 1){
        luong << m_tuSo;
    }else{
        luong << m_tuSo << '/' << m_mauSo;
    }
}

//Phep toan voi luong
ostream& operator<<(ostream& luong, PhanSoX const& phanSo){
    phanSo.hienThi(luong);
    return luong;
}

//Phep toan so hoc
PhanSoX& PhanSoX::operator*=( PhanSoX const& phanSoKhac){
    m_tuSo *= phanSoKhac.m_tuSo;
    m_mauSo *= phanSoKhac.m_mauSo;
    rutGon();
    return *this;
}

PhanSoX& PhanSoX::operator+=( PhanSoX const& phanSoKhac){
    m_tuSo= phanSoKhac.m_mauSo * m_tuSo+ m_mauSo * phanSoKhac.m_tuSo;
    m_mauSo = m_mauSo  * phanSoKhac.m_mauSo;
    rutGon();
    return *this;
}

//Phep toan so sanh
bool PhanSoX::bang(PhanSoX const& phanSoKhac) const {
    return (m_tuSo == phanSoKhac.m_tuSo && m_mauSo == phanSoKhac.m_mauSo);
}

bool PhanSoX::nhoHon(PhanSoX const& phanSoKhac) const{
    if(m_tuSo * phanSoKhac.m_mauSo < m_mauSo * phanSoKhac.m_tuSo)
        return true;
    else
        return false;
}

//Rut gon
void PhanSoX::rutGon(){
    int uocSo = ucln(m_tuSo, m_mauSo);  //Tim uoc chung lon nhat
    m_tuSo /= uocSo;     //Roi rut gon phan so
    m_mauSo  /= uocSo;
}

//Cac phep toan ngoai khai bao lop
PhanSoX operator+( PhanSoX const& a, PhanSoX const& b){
    PhanSoX saoChep(a);
    saoChep+=b;
    return saoChep;
}

PhanSoX operator*( PhanSoX const& a, PhanSoX const& b){
    PhanSoX saoChep(a);
    saoChep*=b;
    return saoChep;
}

bool operator==( PhanSoX const& a, PhanSoX const& b){
    return (a.bang(b));
}

bool operator!=( PhanSoX const& a, PhanSoX const& b){
    return !(a.bang(b));
}

bool operator<( PhanSoX const& a, PhanSoX const& b) {
    return a.nhoHon(b);
}

bool operator>( PhanSoX const& a, PhanSoX const& b){
    return b.nhoHon(a);
}

bool operator<=( PhanSoX const& a, PhanSoX const& b){
    return !(b.nhoHon(a));
}

bool operator>=( PhanSoX const& a, PhanSoX const& b){
    return !(a.nhoHon(b));
}

//Tinh uoc chung lon nhat
int ucln(int a, int b){
    while (b != 0)    {
        const int t = b;
        b = a % b;
        a = t;
    }
    return a;
}
