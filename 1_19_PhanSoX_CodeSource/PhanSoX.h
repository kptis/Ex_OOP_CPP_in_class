#ifndef DEF_PHANSOX
#define DEF_PHANSOX

#include <iostream>

class PhanSoX{
    public:
        //Phuong thuc khoi tao
        PhanSoX(int tuSo, int mauSo);
        PhanSoX(int giaTri);
        PhanSoX();

        //Hien thi
        void hienThi(std::ostream& luong) const;

        //Phep toan so hoc
        PhanSoX& operator+=(PhanSoX const& phanSoKhac);
        PhanSoX& operator*=(PhanSoX const& phanSoKhac);

        //Phuong thuc so sanh
        bool bang(PhanSoX const& phanSoKhac) const;
        bool nhoHon(PhanSoX const& phanSoKhac) const;

    private:
        int m_tuSo;
        int m_mauSo;

        // Rut gon phan so
        void rutGon();

};

//Phep toan voi luong
std::ostream& operator<<(std::ostream& luong, PhanSoX const& phanSo);

//Phep toan so hoc
PhanSoX operator+(PhanSoX const& a, PhanSoX const& b);
PhanSoX operator*(PhanSoX const& a, PhanSoX const& b);

//Phep toan so sanh
bool operator==(PhanSoX const& a, PhanSoX const& b);
bool operator!=(PhanSoX const& a, PhanSoX const& b);
bool operator<(PhanSoX const& a, PhanSoX const& b);
bool operator>(PhanSoX const& a, PhanSoX const& b);
bool operator>=(PhanSoX const& a, PhanSoX const& b);
bool operator<=(PhanSoX const& a, PhanSoX const& b);

//Tinh uoc chung lon nhat
int ucln(int a, int b);

#endif

