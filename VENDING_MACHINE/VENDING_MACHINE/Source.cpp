#include "main.h"
/////////////////   GET SET   ///////////////////////
/////////////////	         ////////////////////////
string SanPham::get_loai() {
	return loai;
}
void SanPham::giam_so_luong(int SOLUONG) {
	soluong = soluong - SOLUONG;
}
int SanPham::get_gia() {
	return gia;
}
void SanPham::set_soluong (int soluong_moi) {
	soluong = soluong_moi;
}
void SanPham::set_gia(int gia_moi) {
	gia = gia_moi;
}
void SanPham::set_id(int id_moi) {
	id = id_moi;
}
////////////////////////////////////////////
////////////// Them va xoa san pham ///////////////
///////////////////////////////////////////
void Them_sp(SanPham* ds[], int& n) {             
	ofstream ofs("sanpham.txt", ofstream::out);
	ofs.close();
	ofstream fileout;
	fileout.open("sanpham.txt", ios_base::app);
	fileout << n + 1;
	int id, gia, soluong, khuyenmai;
	string loai, ten;
	cout << "\nNhap LOAI (n, m): ";
	cin >> loai;
	cout << "\nNhap ID: ";
	cin >> id;
	cout << "\nNhap TEN: ";
	cin >> ten;
	cout << "\nNhap GIA: ";
	cin >> gia;
	cout << "\nNhap SO LUONG: ";
	cin >> soluong;
	cout << "\nNhap KHUYENMAI: ";
	cin >> khuyenmai;
	for (int i = 0; i < n; i++)
	{
		fileout << " ";
		ds[i]->In_file(fileout);
	}
	fileout << endl;
	fileout << loai;
	fileout << ", ";
	fileout << id;
	fileout << ", ";
	fileout << ten;
	fileout << ", ";
	fileout << gia;
	fileout << ", ";
	fileout << soluong;
	fileout << ", ";
	fileout << khuyenmai;
	fileout.close();
}
void Xoa_sp(SanPham* ds[], int& n, int idxoa) {
	ofstream ofs("sanpham.txt", ofstream::out);
	ofs.close();
	ofstream fileout;
	fileout.open("sanpham.txt", ios_base::app);
	fileout << n - 1;
	for (int i = 0; i < n; i++)
	{
		if (i == idxoa-1) {
			continue;
		}
		fileout << " ";
		ds[i]->In_file(fileout);
	}
}
/// ///////////////////////////////////////////////////////////////////////////|
/// //////////////////////////////////////    Đọc file  //////////////////////||
/// /// //////////////////////////////////////////////////////////////////////||
void SanPham::Doc_file(ifstream& filein) {
	filein.seekg(1, 1);
	getline(filein, loai, ',');
	filein.seekg(1, 1);
	filein >> id;
	filein.seekg(1, 1);
	getline(filein, ten, ',');
	filein.seekg(1, 1);
	filein >> gia;
	filein.seekg(1, 1);
	filein >> soluong;
	filein.seekg(1, 1);
}
void Nuoc::Doc_file(ifstream& filein)
{
	SanPham::Doc_file(filein);
	filein >> khuyen_mai_nuoc;
}
void Mi::Doc_file(ifstream& filein)
{
	SanPham::Doc_file(filein);
	filein >> khuyen_mai_mi;
}
/// ///////////////////////////////|
/// //////////////////////////////||
/// /// //////////////////////////||
/// //
/// //
/// ///////////////////////////////////////////////////////////////////////////|
/// //////////////////////////////////////     IN file  //////////////////////||
/// /// //////////////////////////////////////////////////////////////////////||
void SanPham::In_file(ofstream& fileout) {
	fileout << loai;
	fileout << ", ";
	fileout << id;
	fileout << ",";
	fileout << ten;
	fileout << ", ";
	fileout << gia;
	fileout << ", ";
	fileout << soluong;
	fileout << ", ";
}
void Mi::In_file(ofstream& fileout) {
	SanPham::In_file(fileout);
	fileout << khuyen_mai_mi;
}
void Nuoc::In_file(ofstream& fileout) {
	SanPham::In_file(fileout);
	fileout << khuyen_mai_nuoc;
}
void Xuatfile(SanPham* ds[], int& n) {              // Xuatfile
	ofstream ofs("sanpham.txt", ofstream::out);
	ofs.close();
	ofstream fileout;
	fileout.open("sanpham.txt", ios_base::app);
	fileout << n;
	for (int i = 0; i < n; i++)
	{
		fileout << " ";
		ds[i]->In_file(fileout);
	}
	fileout.close();
}

/// ////////////////////////////////////|
/// ///////////////////////////////////||
/// /// ////////////////////////////////
/////
/// ///////////////////////////////////////////////////////////////////////////|
/// //////////////////////////////////////    Hiển thị  //////////////////////||
/// /// //////////////////////////////////////////////////////////////////////||
void matcuoi() {
	system("cls");
	fstream filein;
	filein.open("matcuoi.txt", ios_base::in);
	while (!filein.eof()) {
		string s;
		getline(filein, s, '\n');
		cout << "\t\t\t\t" << s << endl;
		Sleep(1);
	}
	filein.close();
}
void Mi::Xuat() {
	SanPham::Xuat();
	cout << "|      Khuyen mai mi " << khuyen_mai_mi << " %     ||";
}
void Nuoc::Xuat()
{
	SanPham::Xuat();
	cout << "|      Khuyen mai nuoc " << khuyen_mai_nuoc << " %   ||";
}
void SanPham::Xuat() {
	cout << "\n||   ID: " << id << "    ";
	cout << "|      Ten: " << ten << "    ";
	cout << "|      Gia: " << gia << "    ";
	cout << "|      So luong: " << soluong << "    ||";
}
void Hien_thi(SanPham* ds[], int& n) {
	ifstream filein;
	filein.open("sanpham.txt", ios_base::in);
	filein >> n;
	SanPham* x = NULL;
	for (int i = 0; i < n; i++)
	{
		char c;
		filein >> c;
		filein.seekg(-3, 1);
		if (c == 'n') {
			x = new Nuoc();
			x->Doc_file(filein);
		}
		else if (c == 'm') {
			x = new Mi();
			x->Doc_file(filein);
		}
		ds[i] = x;
	}
	system("cls");
	cout << "=================================================================================================================";
	cout << "\n===============================================  MAY BAN HANG TU DONG  ==========================================";
	for (int i = 0; i < n; i++)
	{
		cout << "\n=================================================================================================================" << endl;
		ds[i]->Xuat();

	}
	cout << endl;
	cout << "=================================================================================================================" << endl;
	filein.close();
}
/// ///////////////////////////////////|
/// ///////////////////////////////\\\||
/// /// //////////////////////////////||
/// 
/// ///////////////////////////////////////////////////////////////////////////|
/// //////////////////////////////////////    ADMIN      //////////////////////||
/// /// //////////////////////////////////////////////////////////////////////||

void Admin(SanPham* ds[],int &n) {
	int chon;
	int thaydoi;
	int id_thaydoi;
	int id_xoa;
	system("cls");
	Hien_thi(ds, n);
	cout << "\n\t ========ADMIN========" << endl;
	cout << "\n 1. THAY DOI THONG TIN SAN PHAM";
	cout << "\n 2. THEM SAN PHAM";
	cout << "\n 3. XOA SAN PHAM";
	cout << "\n 0. THOAT";
	cout << "\n\t =========END========" << endl;
	cout << "LUA CHON: ";
	cin >> chon;
	switch (chon)
	{
	case 1:
		system("cls");
		Hien_thi(ds, n);
		cout << "\nNhap ID san pham muon doi: ";
		cin >> id_thaydoi;
		cout << "\n\t =========THAY DOI THONG TIN SAN PHAM========" << endl;
		cout << "\n 1. ID";
		cout << "\n 2. GIA";
		cout << "\n 3. SO LUONG";
		cout << "\n 0. THOAT";
		cout << "\n\t =====================END===================" << endl;
		cout << "LUA CHON: ";
		cin >> thaydoi;
		switch (thaydoi)
		{
		case 1:
			int id;
			cout << "\nNhap ID moi: ";
			cin >> id;
			ds[id_thaydoi - 1]->set_id(id);
			Xuatfile(ds, n);
			break;
		case 2:
			int gia;
			cout << "\nNhap gia moi: ";
			cin >> gia;
			ds[id_thaydoi - 1]->set_gia(gia);
			Xuatfile(ds, n);
			break;
		case 3:
			int soluong;
			cout << "\nNhap so luong moi: ";
			cin >> soluong;
			ds[id_thaydoi - 1]->set_soluong(soluong);
			Xuatfile(ds, n);
			break;
		default:
			break;
		}
		break;
	case 2:
		Them_sp(ds,n);
		break;
	case 3:
		cout << "\n Nhap ID can xoa: ";
		cin >> id_xoa;
		Xoa_sp(ds, n, id_xoa);
		break;
	default:
		break;
	}

}
/// ///////////////////////////////////|
/// ///////////////////////////////\\\||
/// /// //////////////////////////////||
/// 
/// ///////////////////////////////////////////////////////////////////////////|
/// ////////////////////////////////////    XU LY MUA     ////////////////////||
/// /// //////////////////////////////////////////////////////////////////////||

void Xuly(SanPham* ds[],int &n) {
	int tien = 0;
	int tong_tien = 0;
	int id_spm = 0;
	int soluong_mua = 0;
	int tien_them = 0;
	int tien_thua = 0;
	int chon;
	//int mssv;
	int dem = 0;
	cout << "\n Moi ban nhap so tien: ";
	cin >> tien;
muathem:
	cout << "Tien ban da nop: " << tien<< endl;
	cout << "\nMoi ban nhap id san pham: ";
	cin >> id_spm;
	cout << "\nMoi ban nhap so luong: ";
	cin >> soluong_mua;
	//cout << "\n Nhap MSSV de duoc giam gia (chi duoc mua 1 lan)(nhan 0 neu khong co): ";
	//cin >> mssv;
	for (int i = 0; i < soluong_mua; i++) {
		tong_tien += ds[id_spm-1]->get_gia();
	}
	ds[id_spm-1]->giam_so_luong(soluong_mua);
	cout << endl;
	cout << "Tong tien phai tra: " << tong_tien;
	Xuatfile(ds, n);
	//if (mssv != 0) {
	//	
	//}
	while (tien < tong_tien) {
		cout << "\n Tien khong du, moi ban nhap them!!!";
		Sleep(2000);
		cout << "\n Nhap tien: ";
		cin >> tien_them;
		tien += tien_them;
		cout << "\n Tong tien ban da nap vao: " << tien << endl;
	}
	tien_thua = tien - tong_tien;
	cout << "\nTien thua cua ban la: " << tien_thua << endl;
	system("pause");
	system("cls");
	cout << "\n Ban co muon mua them khong? (yes: 1, no: 0):  ";
	cin >> chon;
	if (chon == 1) {
		tien = tien_thua;
		tong_tien = 0;
		Hien_thi(ds, n);
		goto muathem;
	}
	
}
/// ///////////////////////////////////|
/// ///////////////////////////////\\\||
/// /// //////////////////////////////||
///
/// ///////////////////////////////////////////////////////////////////////////|
/// //////////////////////////////////////    MENU      //////////////////////||
/// /// //////////////////////////////////////////////////////////////////////||
void Menu(SanPham* ds[], int& n) {
	for (size_t i = 0; i < 3; i++)
	{
		matcuoi();
		Sleep(200);
	}
	int KM_nuoc, KM_mi;
	ifstream filein;
	filein.open("sanpham.txt", ios_base::in);
	filein >> n;
	filein.seekg(1, 1);
	filein >> KM_nuoc;
	filein.seekg(1, 1);
	filein >> KM_mi;
	SanPham* x = NULL;
	for (int i = 0; i < n; i++)
	{
		char c;
		filein >> c;
		filein.seekg(-3, 1);
		if (c == 'n') {
			x = new Nuoc();
			x->Doc_file(filein);
		}
		else if (c == 'm') {
			x = new Mi();
			x->Doc_file(filein);
		}
		ds[i] = x;
	}
	while (true) {

		system("cls");
		cout << "\n\t ========MENU========" << endl;
		cout << "\n         1. MUA HANG";
		cout << "\n         2. QUAN LY";
		cout << "\n         0. THOAT";
		cout << "\n\t ========END========" << endl;
		int luachon = 0;
		int tien_hang = 0;
		cout << "LUA CHON: ";
		cin >> luachon;
		if (luachon == 1)
		{
			Hien_thi(ds, n);
			Xuly(ds,n);
		}
		else if (luachon == 2) {
			int pass;
			int count = 4;
			cout << "\n NHAP MAT KHAU: ";
			cin >> pass;
			while (true) {
				if (pass == 12345) {

					Admin(ds,n);
					break;
				}
				else {
					count--;
					system("cls");
					cout << "\n Nhap sai con " << count + 1 << " lan de cho ban nhap lai!" << endl;
					system("pause");
					cout << "\n NHAP MAT KHAU: ";
					cin >> pass;
					if (count == 0) {
						break;
					}
				}
			}
			system("pause");
		}
		else
		{
			break;
		}
		break;
	}
	delete x;
	filein.close();
}
/// /////////////////////////////////////////|
/// ////////////////////////////////////////||
/// /// ////////////////////////////////////||


/// /////////////////////////////////////////|
/// ////////////  MAIN  ////////////////////||
/// /// ////////////////////////////////////||
int main() {
	int n = 0;
	SanPham* ds[100];
	while (true) {
		Menu(ds, n);
	}
	system("pause");
	return 0;
}