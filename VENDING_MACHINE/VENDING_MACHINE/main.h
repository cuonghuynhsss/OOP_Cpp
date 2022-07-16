#ifndef _MAIN_H_
#define  _MAIN_H_
#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
using namespace std;

class SanPham
{
protected:
	string loai;
	int id;
	string ten;
	int gia;
	int soluong;
public:
	void giam_so_luong(int SOLUONG);
	virtual void Doc_file(ifstream&);
	virtual void Xuat();
	virtual void In_file(ofstream&);
	string get_loai();
	int get_gia();
	void set_id(int id_moi);
	void set_soluong(int soluong_moi);
	void set_gia(int gia_moi);
};
class Nuoc :public SanPham
{
private:
	float khuyen_mai_nuoc;
public:
	void Doc_file(ifstream&);
	void Xuat();
	void In_file(ofstream&);

};

class Mi :public SanPham
{
private:
	float khuyen_mai_mi;
public:
	void Doc_file(ifstream&);
	void Xuat();
	void In_file(ofstream&);
};
#endif 

