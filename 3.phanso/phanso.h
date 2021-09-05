// Move to source folder of visual studio
// the parent folder need 3 file: phanso.h, phanso.cpp, main.cpp

#ifndef DEF_PHANSO
#define DEF_PHANSO
#include <iostream>

class PhanSo{

    public:
    // Phương thức khởi tạo

    PhanSo(int tuso, int mauso);
    Phanso(int tuso);
    Phanso();

    // Display
    void display(std::ostream & phanso) const;

    //Các phép toán
    Phanso& operator+=(Phanso const& pskhac);
    Phanso& operator*=(Phanso const& pskhac);


    private:
        int tuSo;
        int mauSo;
};

// Tìm UCLN --> rút gọn phân số
int ucln(int a, int b);


#endif // !DEF_PHANSO

