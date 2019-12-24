#include "CenterLib.h"
// CÁC CLASS QUÂN CỜ
class OCo
{
public:
	int x;
	int y;
};
class QuanCo :public OCo
{
public:
	int  team; // 0: là một quân cờ rỗng
	// 1: là quân cờ team 1
	// 2: là quân cờ team 2
	string name; // tên quân cờ, mặc định là null
public:
	QuanCo::QuanCo()
	{
		x = 0;
		y = 0;
		team = 0;
		name = "null";
	}
	QuanCo::QuanCo(int i, int j) // Khởi tạo
	{
		x = i; // i là hoành độ trên bàn cờ
		y = j; // j là tung độ
		team = 0;
		name = "null";
	}
	virtual void move(int newx, int newy) // (newx, newy) tọa độ chuyển đến
	{};
	virtual void display(int i, int j)
	{};
	virtual int KiemTra(int newx, int newy)
	{
		return 0;
	};

};
static QuanCo* Banco[8][8];
// CLASS TỐT
class Tot1 :public QuanCo // Lớp tốt team 1
{
public:
	Tot1::Tot1()
	{
		x = 0;
		y = 0;
		team = 1;
		name = "tot1";
	}
	Tot1::Tot1(int i, int j)
	{
		x = i;
		y = j;
		team = 1;
		name = "tot1";
	}
	void move(int newx, int newy);
	int KiemTra(int newx, int newy);
	void display(int i, int j)
	{
		int xx = 10 * j + minx;
		int yy = 6 * i + miny;
		textcolor(17);
		gotoxy(xx + 4, yy + 1);
		cout << "  ";
		gotoxy(xx + 5, yy + 2);
		cout << " ";
		gotoxy(xx + 4, yy + 3);
		cout << "  ";
		gotoxy(xx + 4, yy + 4);
		cout << "  ";
		gotoxy(xx + 2, yy + 5);
		cout << "      ";
		textcolor(7);
	}
};
class Tot2 :public QuanCo // Lớp tốt team 2
{
public:
	Tot2::Tot2()
	{
		x = 0;
		y = 0;
		team = 2;
		name = "tot2";
	}
	Tot2::Tot2(int i, int j)
	{
		x = i;
		y = j;
		team = 2;
		name = "tot2";
	}
	void move(int newx, int newy);
	int KiemTra(int newx, int newy);
	void display(int i, int j)
	{
		int xx = 10 * j + minx;
		int yy = 6 * i + miny;
		textcolor(0);
		gotoxy(xx + 4, yy + 1);
		cout << "  ";
		gotoxy(xx + 5, yy + 2);
		cout << " ";
		gotoxy(xx + 4, yy + 3);
		cout << "  ";
		gotoxy(xx + 4, yy + 4);
		cout << "  ";
		gotoxy(xx + 2, yy + 5);
		cout << "      ";
		textcolor(7);
	}
};
// CLASS TƯỚNG
class Tuong : public QuanCo // Class Quân Tướng
{
public:
	virtual void move(int newx, int newy)
	{};
	int KiemTra(int newx, int newy);
	virtual void display(int i, int j)
	{};
};
class Tuong1 : public Tuong // lớp Tương Team 1
{
public:
	Tuong1::Tuong1()
	{
		x = 0;
		y = 0;
		team = 1;
		name = "tuong1";
	}
	Tuong1::Tuong1(int i, int j)
	{
		x = i;
		y = j;
		team = 1;
		name = "tuong1";
	}
	void move(int newx, int newy);
	void display(int i, int j)
	{
		int xx = 10 * j + minx;
		int yy = 6 * i + miny;
		textcolor(17);
		gotoxy(xx + 2, yy + 5);
		cout << "      ";
		gotoxy(xx + 2, yy + 1);
		cout << "      ";
		gotoxy(xx + 3, yy + 4);
		cout << "    ";
		gotoxy(xx + 4, yy);
		cout << "  ";
		gotoxy(xx + 4, yy + 2);
		cout << "  ";
		gotoxy(xx + 4, yy + 3);
		cout << "  ";
		textcolor(7);
	};
};
class Tuong2 : public Tuong // lớp tướng Team 2
{
public:
	Tuong2::Tuong2()
	{
		x = 0;
		y = 0;
		team = 2;
		name = "tuong2";
	}
	Tuong2::Tuong2(int i, int j)
	{
		x = i;
		y = j;
		team = 2;
		name = "tuong2";
	}
	void move(int newx, int newy);
	void display(int i, int j)
	{
		int xx = 10 * j + minx;
		int yy = 6 * i + miny;
		textcolor(0);
		gotoxy(xx + 2, yy + 5);
		cout << "      ";
		gotoxy(xx + 2, yy + 1);
		cout << "      ";
		gotoxy(xx + 3, yy + 4);
		cout << "    ";
		gotoxy(xx + 4, yy);
		cout << "  ";
		gotoxy(xx + 4, yy + 2);
		cout << "  ";
		gotoxy(xx + 4, yy + 3);
		cout << "  ";
		textcolor(7);
	};
};
// CLASS TỊNH
class Tinh : public QuanCo // Class Quân Tịnh
{
public:
	virtual void move(int newx, int newy)
	{};
	int KiemTra(int newx, int newy);
	virtual void display(int i, int j)
	{};
};
class Tinh1 : public Tinh // lớp Tịnh Team 1
{
public:
	Tinh1::Tinh1()
	{
		x = 0;
		y = 0;
		team = 1;
		name = "tinh1";
	}
	Tinh1::Tinh1(int i, int j)
	{
		x = i;
		y = j;
		team = 1;
		name = "tinh1";
	}
	void move(int newx, int newy);
	// int KiemTra(int newx, int newy);
	void display(int i, int j)
	{
		int xx = 10 * j + minx;
		int yy = 6 * i + miny;
		textcolor(17);
		for (int j = yy; j <= yy + 5; j++)
		{
			gotoxy(xx + 4, j);
			cout << "  ";
		}
		gotoxy(xx + 3, yy + 3);
		cout << "    ";
		gotoxy(xx + 2, yy + 5);
		cout << "      ";
		textcolor(7);
	};
};
class Tinh2 : public Tinh // lớp tịnh Team 2
{
public:
	Tinh2::Tinh2()
	{
		x = 0;
		y = 0;
		team = 2;
		name = "tinh2";
	}
	Tinh2::Tinh2(int i, int j)
	{
		x = i;
		y = j;
		team = 2;
		name = "tinh2";
	}
	void move(int newx, int newy);
	void display(int i, int j)
	{
		int xx = 10 * j + minx;
		int yy = 6 * i + miny;
		textcolor(0);
		for (int j = yy; j <= yy + 5; j++)
		{
			gotoxy(xx + 4, j);
			cout << "  ";
		}
		gotoxy(xx + 3, yy + 3);
		cout << "    ";
		gotoxy(xx + 2, yy + 5);
		cout << "      ";
		textcolor(7);
	};
};
// CLASS THÀNH
class Thanh : public QuanCo // Class Quân Thành
{
public:
	virtual void move(int newx, int newy)
	{};
	int KiemTra(int newx, int newy);
	virtual void display(int i, int j)
	{};
};
class Thanh1 : public Thanh // lớp Thành Team 1
{
public:
	Thanh1::Thanh1()
	{
		x = 0;
		y = 0;
		team = 1;
		name = "thanh1";
	}
	Thanh1::Thanh1(int i, int j)
	{
		x = i;
		y = j;
		team = 1;
		name = "thanh1";
	}
	void move(int newx, int newy);
	void display(int i, int j)
	{
		int xx = 10 * j + minx;
		int yy = 6 * i + miny;
		textcolor(17);
		gotoxy(xx + 1, yy + 5);
		cout << "        ";
		gotoxy(xx + 3, yy + 2);
		cout << "    ";
		gotoxy(xx + 3, yy + 3);
		cout << "    ";
		gotoxy(xx + 3, yy + 4);
		cout << "    ";
		gotoxy(xx + 1, yy + 1);
		cout << "        ";
		gotoxy(xx + 1, yy);
		cout << " ";
		gotoxy(xx + 3, yy);
		cout << " ";
		gotoxy(xx + 6, yy);
		cout << " ";
		gotoxy(xx + 8, yy);
		cout << " ";
		textcolor(7);
	};
};
class Thanh2 : public Thanh // lớp Thành Team 2
{
public:
	Thanh2::Thanh2()
	{
		x = 0;
		y = 0;
		team = 2;
		name = "thanh2";
	}
	Thanh2::Thanh2(int i, int j)
	{
		x = i;
		y = j;
		team = 2;
		name = "thanh2";
	}
	void move(int newx, int newy);
	void display(int i, int j)
	{
		int xx = 10 * j + minx;
		int yy = 6 * i + miny;
		textcolor(0);
		gotoxy(xx + 1, yy + 5);
		cout << "        ";
		gotoxy(xx + 3, yy + 2);
		cout << "    ";
		gotoxy(xx + 3, yy + 3);
		cout << "    ";
		gotoxy(xx + 3, yy + 4);
		cout << "    ";
		gotoxy(xx + 1, yy + 1);
		cout << "        ";
		gotoxy(xx + 1, yy);
		cout << " ";
		gotoxy(xx + 3, yy);
		cout << " ";
		gotoxy(xx + 6, yy);
		cout << " ";
		gotoxy(xx + 8, yy);
		cout << " ";
		textcolor(7);
	};
};
// CLASS MÃ
class Ma : public QuanCo // Class Quân Mã
{
public:
	virtual void move(int newx, int newy)
	{};
	int KiemTra(int newx, int newy);
	virtual void display(int i, int j)
	{};
};
class Ma1 : public Ma // lớp Mã Team 1
{
public:
	Ma1::Ma1()
	{
		x = 0;
		y = 0;
		team = 1;
		name = "ma1";
	}
	Ma1::Ma1(int i, int j)
	{
		x = i;
		y = j;
		team = 1;
		name = "ma1";
	}
	void move(int newx, int newy);
	// int KiemTra(int newx, int newy);
	void display(int i, int j)
	{
		int xx = 10 * j + minx;
		int yy = 6 * i + miny;
		textcolor(17);
		for (int i = xx + 1; i <= xx + 8; i++)
		{
			gotoxy(i, yy + 5);
			cout << " ";
		}
		for (int i = xx + 3; i <= xx + 8; i++)
		{
			gotoxy(i, yy + 4);
			cout << " ";
		}
		for (int i = xx + 4; i <= xx + 7; i++)
		{
			gotoxy(i, yy + 3);
			cout << " ";
		}
		for (int i = xx + 2; i <= xx + 6; i++)
		{
			gotoxy(i, yy + 2);
			cout << " ";
		}
		for (int i = xx + 4; i <= xx + 6; i++)
		{
			gotoxy(i, yy + 1);
			cout << " ";
		}
		textcolor(7);
	};
};
class Ma2 : public Ma // lớp Mã Team 2
{
public:
	Ma2::Ma2()
	{
		x = 0;
		y = 0;
		team = 2;
		name = "ma2";
	}
	Ma2::Ma2(int i, int j)
	{
		x = i;
		y = j;
		team = 2;
		name = "ma2";
	}
	void move(int newx, int newy);
	void display(int i, int j)
	{
		int xx = 10 * j + minx;
		int yy = 6 * i + miny;
		textcolor(0);
		for (int i = xx + 1; i <= xx + 8; i++)
		{
			gotoxy(i, yy + 5);
			cout << " ";
		}
		for (int i = xx + 3; i <= xx + 8; i++)
		{
			gotoxy(i, yy + 4);
			cout << " ";
		}
		for (int i = xx + 4; i <= xx + 7; i++)
		{
			gotoxy(i, yy + 3);
			cout << " ";
		}
		for (int i = xx + 2; i <= xx + 6; i++)
		{
			gotoxy(i, yy + 2);
			cout << " ";
		}
		for (int i = xx + 4; i <= xx + 6; i++)
		{
			gotoxy(i, yy + 1);
			cout << " ";
		}
		textcolor(7);
	};
};
// CLASS HẬU
class Hau : public QuanCo // Class Quân Hậu
{
public:
	virtual void move(int newx, int newy)
	{};
	int KiemTra(int newx, int newy);
	virtual void display(int i, int j)
	{};
};
class Hau1 : public Hau // lớp Hậu Team 1
{
public:
	Hau1::Hau1()
	{
		x = 0;
		y = 0;
		team = 1;
		name = "hau1";
	}
	Hau1::Hau1(int i, int j)
	{
		x = i;
		y = j;
		team = 1;
		name = "hau1";
	}
	void move(int newx, int newy);
	// int KiemTra(int newx, int newy);
	void display(int i, int j)
	{
		int xx = 10 * j + minx;
		int yy = 6 * i + miny;
		textcolor(17);
		gotoxy(xx + 2, yy + 5);
		cout << "      ";
		gotoxy(xx + 3, yy + 4);
		cout << "    ";
		gotoxy(xx + 4, yy + 3);
		cout << "  ";
		gotoxy(xx + 4, yy + 2);
		cout << "  ";
		gotoxy(xx + 4, yy + 1);
		cout << "  ";
		gotoxy(xx + 4, yy);
		cout << "  ";
		gotoxy(xx + 2, yy);
		cout << " ";
		gotoxy(xx + 7, yy);
		cout << " ";
		textcolor(7);
	};
};
class Hau2 : public Hau // lớp Hậu Team 2
{
public:
	Hau2::Hau2()
	{
		x = 0;
		y = 0;
		team = 2;
		name = "hau2";
	}
	Hau2::Hau2(int i, int j)
	{
		x = i;
		y = j;
		team = 2;
		name = "hau2";
	}
	void move(int newx, int newy);
	void display(int i, int j)
	{
		int xx = 10 * j + minx;
		int yy = 6 * i + miny;
		textcolor(0);
		gotoxy(xx + 2, yy + 5);
		cout << "      ";
		gotoxy(xx + 3, yy + 4);
		cout << "    ";
		gotoxy(xx + 4, yy + 3);
		cout << "  ";
		gotoxy(xx + 4, yy + 2);
		cout << "  ";
		gotoxy(xx + 4, yy + 1);
		cout << "  ";
		gotoxy(xx + 4, yy);
		cout << "  ";
		gotoxy(xx + 2, yy);
		cout << " ";
		gotoxy(xx + 7, yy);
		cout << " ";
		textcolor(7);
	};
};
// Hàm vẽ ô cờ
void VeOCo(int t, int x, int y);
// Hàm vẽ bàn cờ
void VeBanCo();
// Hàm làm sáng ô cờ
void LamSang(int i, int j, int color);
// Hàm hủy sáng ô cờ
void HuySang(int i, int j);
// Xuất lượt đi
void XuatLuotDi(int team);
// Hàm xác định quân cờ
void XacDinhQuanCo(char c, int &x, int &y);
// Các hàm in ra menu
void InMenu();
void Inp1vsp2();
void Inhistory();
void Inexit();
void Inlaw();
// Các hàm in thông báo
void QuanCoKhongHopLe(int team);
void HuyNuocDi(int team);
void ViTriKhongHopLe(int team);
void ThongBaoNguoiWin(int team);
// Lịch sử chơi
void GhiVaoLichSu(char* ten1, char* ten2, int KetQua);
// Cầu hòa
int CauHoa(int team);
int DongYHoa(int team);
// Chơi nhạc
void PlayMusic(int n);
void StopMusic();
void TaoBanCo();
void XuatBanCo(char* ten1, char* ten2);
int CoNuocDi(QuanCo* &x);
void InCacViTriKhaThi(int x, int y);
void XacDinhViTri(char c, int x, int y, int &newx, int &newy);
void PhongTot(int newx, int newy, int team);
void Lawofchess();
void Intro(char* ten1, char* ten2);
void ThongBaoQuanMat(int ntot, int nthanh, int nma, int ntinh, int  nhau, int team);
void ThongBaoChieuTuong(int team);
int MuonDauHang(int team);
int NhanVaoNutDauHang(char c, int team, char* ten1, char* ten2);
int NhanVaoNutCauHoa(char c, int team, char* ten1, char* ten2);
void ChoiNhac(int n, int m);
void Sound(int &music, int &n, char c);
void XuLiGame();
void GiaiPhong();
