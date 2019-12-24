#include "MyLib.h"

void Tot1::move(int newx, int newy)
{
	Banco[x][y] = new QuanCo(x, y); // Chuyển vị trí cũ thành quân cờ rỗng
	Banco[newx][newy] = new Tot1(newx, newy); // tới vị trí mới-> chuyển vị trí mới thành quân tốt 1
};
int Tot1::KiemTra(int newx, int newy)
{
	if (newx<0 || newx>7 || newy<0 || newy>7 || ((newx == x) && (newy == y)))
		return 0; // Tràn ra ngoài bàn cờ và đứng yên một chỗ
	// Không tới được khi ô đó có quân cờ team 1
	if (Banco[newx][newy]->team == 1)
		return 0;
	else if (Banco[newx][newy]->team == 0) // Là một ô rỗng
	{
		if (newx == x - 1 && newy == y) // ô nằm phía trên
			return 1;
		if (x == 6 && newx == 4 && newy == y) // Nhảy 2 ô tại vị trí ban đầu
			return 1;
		return 0;
	}
	else // Chứa quân cờ team 2
	{
		if (newx == x - 1 && newy == y - 1) // Ô trên bên trái
			return 1;
		if (newx == x - 1 && newy == y + 1) // ô trêm bên phải
			return 1;
		return 0;
	}
};
void Tot2::move(int newx, int newy)
{
	Banco[x][y] = new QuanCo(x, y); // Chuyển vị trí cũ thành quân cờ rỗng
	Banco[newx][newy] = new Tot2(newx, newy); // tới vị trí mới-> chuyển vị trí mới thành quân tốt 2
};
int Tot2::KiemTra(int newx, int newy)
{
	if (newx<0 || newx>7 || newy<0 || newy>7 || ((newx == x) && (newy == y)))
		return 0; // Tràn ra ngoài bàn cờ và đứng yên một chỗ
	// Không tới được khi ô đó có quân cờ team 2
	if (Banco[newx][newy]->team == 2)
		return 0;
	else if (Banco[newx][newy]->team == 0) // Là một ô rỗng
	{
		if (newx == x + 1 && newy == y) // ô nằm phía dưới
			return 1;
		if (x == 1 && newx == 3 && newy == y) // Nhảy 2 ô tại vị trí ban đầu
			return 1;
		return 0;
	}
	else // Chứa quân cờ team 1
	{
		if (newx == x + 1 && newy == y - 1) // Ô dưới bên trái
			return 1;
		if (newx == x + 1 && newy == y + 1) // ô dưới bên phải
			return 1;
		return 0;
	}
};
// HÀM TƯỚNG
int Tuong::KiemTra(int newx, int newy)
{
	if (newx<0 || newx>7 || newy<0 || newy>7 || ((newx == x) && (newy == y)))
		return 0; // Tràn ra ngoài bàn cờ và đứng yên một chỗ
	if (Banco[newx][newy]->team == Banco[x][y]->team)
		return 0; // 2 ô có 2 quân cùng team


	if ((newx - x == -1 && newy - y == -1) || (newx - x == -1 && newy == y) || (newx - x == -1 && newy - y == 1) || (newx == x && newy - y == -1) || (newx == x && newy - y == 1) || (newx - x == 1 && newy - y == -1) || (newx - x == 1 && newy == y) || (newx - x == 1 && newy - y == 1)) // Nước đi hợp lệ của quan tướng
	{
		return 1;
	}
	else
		return 0;

};
void Tuong1::move(int newx, int newy)
{
	Banco[x][y] = new QuanCo(x, y); // Chuyển vị trí cũ thành quân cờ rỗng
	Banco[newx][newy] = new Tuong1(newx, newy); // tới vị trí mới-> chuyển vị trí mới thành quân Tướng 1
};
void Tuong2::move(int newx, int newy)
{
	Banco[x][y] = new QuanCo(x, y); // Chuyển vị trí cũ thành quân cờ rỗng
	Banco[newx][newy] = new Tuong2(newx, newy); // tới vị trí mới-> chuyển vị trí mới thành quân Tướng 2
};
// HÀM TỊNH
int Tinh::KiemTra(int newx, int newy)
{
	if (newx<0 || newx>7 || newy<0 || newy>7 || ((newx == x) && (newy == y)))
		return 0; // Tràn ra ngoài bàn cờ và đứng yên một chỗ
	if (Banco[newx][newy]->team == Banco[x][y]->team)
		return 0; // 2 ô có 2 quân cùng team


	if (abs(newx - x) == abs(newy - y)) // Nằm trên 1 trong 2 đường chéo
	{
		if (newx<x && newy>y) // Góc thứ I
		{
			int i, j;
			for (i = x - 1, j = y + 1; i > newx; i--, j++)
			{
				if (Banco[i][j]->team != 0) // Đã có quân cờ khác rỗng ở trên đường đi
					return 0;
			}
			return 1;
		}
		else if (newx<x && newy<y) // Góc thứ II
		{
			int i, j;
			for (i = x - 1, j = y - 1; i > newx; i--, j--)
			{
				if (Banco[i][j]->team != 0) // Đã có quân cờ khác rỗng ở trên đường đi
					return 0;
			}
			return 1;
		}
		else if (newx>x && newy < y) // Góc thứ III
		{
			int i, j;
			for (i = x + 1, j = y - 1; i < newx; i++, j--)
			{
				if (Banco[i][j]->team != 0) // Đã có quân cờ khác rỗng ở trên đường đi
					return 0;
			}
			return 1;
		}
		else // Góc thứ IV
		{
			int i, j;
			for (i = x + 1, j = y + 1; i < newx; i++, j++)
			{
				if (Banco[i][j]->team != 0) // Đã có quân cờ khác rỗng ở trên đường đi
					return 0;
			}
			return 1;
		}
	}
	else
		return 0;

};
void Tinh1::move(int newx, int newy)
{
	Banco[x][y] = new QuanCo(x, y); // Chuyển vị trí cũ thành quân cờ rỗng
	Banco[newx][newy] = new Tinh1(newx, newy); // tới vị trí mới-> chuyển vị trí mới thành quân Tịnh 1
};
void Tinh2::move(int newx, int newy)
{
	Banco[x][y] = new QuanCo(x, y); // Chuyển vị trí cũ thành quân cờ rỗng
	Banco[newx][newy] = new Tinh2(newx, newy); // tới vị trí mới-> chuyển vị trí mới thành quân Tịnh 2
};
// HÀM THÀNH
int Thanh::KiemTra(int newx, int newy)
{
	if (newx<0 || newx>7 || newy<0 || newy>7 || ((newx == x) && (newy == y)))
		return 0; // Tràn ra ngoài bàn cờ và đứng yên một chỗ
	if (Banco[newx][newy]->team == Banco[x][y]->team)
		return 0; // 2 ô có 2 quân cùng team
	if (newy == y) // Vị trí mới nằm trên trục dọc
	{
		if (newx > x) // Nằm ở trục dưới
		{
			for (int i = x + 1; i < newx; i++)
			{
				if (Banco[i][y]->team != 0) // Đã có quân cờ khác rỗng ở trên đường đi
					return 0;
			}
			return 1;
		}
		else // newx<x Nằm ở trục trên
		{
			for (int i = x - 1; i > newx; i--)
			{
				if (Banco[i][y]->team != 0) // Đã có quân cờ khác rỗng ở trên đường đi
					return 0;
			}
			return 1;
		}
	}
	else if (newx == x) // Nằm trên trục ngang
	{
		if (newy > y) // Nằm ở trục bên phải
		{
			for (int j = y + 1; j < newy; j++)
			{
				if (Banco[x][j]->team != 0) // Đã có quân cờ khác rỗng ở trên đường đi
					return 0;
			}
			return 1;
		}
		else // newy<y Nằm ở trục trên
		{
			for (int j = y - 1; j > newy; j--)
			{
				if (Banco[x][j]->team != 0) // Đã có quân cờ khác rỗng ở trên đường đi
					return 0;
			}
			return 1;
		}
	}
	return 0;
}
void Thanh1::move(int newx, int newy)
{
	Banco[x][y] = new QuanCo(x, y); // Chuyển vị trí cũ thành quân cờ rỗng
	Banco[newx][newy] = new Thanh1(newx, newy); // tới vị trí mới-> chuyển vị trí mới thành quân Thành 1
};
void Thanh2::move(int newx, int newy)
{
	Banco[x][y] = new QuanCo(x, y); // Chuyển vị trí cũ thành quân cờ rỗng
	Banco[newx][newy] = new Thanh2(newx, newy); // tới vị trí mới-> chuyển vị trí mới thành quân Thành 2
};
// HÀM MÃ
int Ma::KiemTra(int newx, int newy)
{
	if (newx<0 || newx>7 || newy<0 || newy>7 || ((newx == x) && (newy == y)))
		return 0; // Tràn ra ngoài bàn cờ và đứng yên một chỗ
	if (Banco[newx][newy]->team == Banco[x][y]->team)
		return 0; // 2 ô có 2 quân cùng team
	if ((newy - y)*(newy - y) + (newx - x)*(newx - x) == 5) // Bước di chuyển hợp lệ của quân mã
		return 1;
	else
		return 0;

};
void Ma1::move(int newx, int newy)
{
	Banco[x][y] = new QuanCo(x, y); // Chuyển vị trí cũ thành quân cờ rỗng
	Banco[newx][newy] = new Ma1(newx, newy); // tới vị trí mới-> chuyển vị trí mới thành quân Mã 1
};
void Ma2::move(int newx, int newy)
{
	Banco[x][y] = new QuanCo(x, y); // Chuyển vị trí cũ thành quân cờ rỗng
	Banco[newx][newy] = new Ma2(newx, newy); // tới vị trí mới-> chuyển vị trí mới thành quân Mã 2
};
// HÀM HẬU
int Hau::KiemTra(int newx, int newy)
{
	if (newx<0 || newx>7 || newy<0 || newy>7 || ((newx == x) && (newy == y)))
		return 0; // Tràn ra ngoài bàn cờ và đứng yên một chỗ
	if (Banco[newx][newy]->team == Banco[x][y]->team)
		return 0; // 2 ô có 2 quân cùng team
	if (newy == y) // Vị trí mới nằm trên trục dọc
	{
		if (newx > x) // Nằm ở trục dưới
		{
			for (int i = x + 1; i < newx; i++)
			{
				if (Banco[i][y]->team != 0) // Đã có quân cờ khác rỗng ở trên đường đi
					return 0;
			}
			return 1;
		}
		else // newx<x Nằm ở trục trên
		{
			for (int i = x - 1; i > newx; i--)
			{
				if (Banco[i][y]->team != 0) // Đã có quân cờ khác rỗng ở trên đường đi
					return 0;
			}
			return 1;
		}
	}
	else if (newx == x) // Nằm trên trục ngang
	{
		if (newy > y) // Nằm ở trục bên phải
		{
			for (int j = y + 1; j < newy; j++)
			{
				if (Banco[x][j]->team != 0) // Đã có quân cờ khác rỗng ở trên đường đi
					return 0;
			}
			return 1;
		}
		else // newy<y Nằm ở trục trên
		{
			for (int j = y - 1; j > newy; j--)
			{
				if (Banco[x][j]->team != 0) // Đã có quân cờ khác rỗng ở trên đường đi
					return 0;
			}
			return 1;
		}
	}
	else if (abs(newx - x) == abs(newy - y)) // Nằm trên 1 trong 2 đường chéo
	{
		if (newx<x && newy>y) // Góc thứ I
		{
			int i, j;
			for (i = x - 1, j = y + 1; i > newx; i--, j++)
			{
				if (Banco[i][j]->team != 0) // Đã có quân cờ khác rỗng ở trên đường đi
					return 0;
			}
			return 1;
		}
		else if (newx<x && newy<y) // Góc thứ II
		{
			int i, j;
			for (i = x - 1, j = y - 1; i > newx; i--, j--)
			{
				if (Banco[i][j]->team != 0) // Đã có quân cờ khác rỗng ở trên đường đi
					return 0;
			}
			return 1;
		}
		else if (newx>x && newy < y) // Góc thứ III
		{
			int i, j;
			for (i = x + 1, j = y - 1; i < newx; i++, j--)
			{
				if (Banco[i][j]->team != 0) // Đã có quân cờ khác rỗng ở trên đường đi
					return 0;
			}
			return 1;
		}
		else // Góc thứ IV
		{
			int i, j;
			for (i = x + 1, j = y + 1; i < newx; i++, j++)
			{
				if (Banco[i][j]->team != 0) // Đã có quân cờ khác rỗng ở trên đường đi
					return 0;
			}
			return 1;
		}
	}
	return 0;
};
void Hau1::move(int newx, int newy)
{
	Banco[x][y] = new QuanCo(x, y); // Chuyển vị trí cũ thành quân cờ rỗng
	Banco[newx][newy] = new Hau1(newx, newy); // tới vị trí mới-> chuyển vị trí mới thành quân Hậu 1
};
void Hau2::move(int newx, int newy)
{
	Banco[x][y] = new QuanCo(x, y); // Chuyển vị trí cũ thành quân cờ rỗng
	Banco[newx][newy] = new Hau2(newx, newy); // tới vị trí mới-> chuyển vị trí mới thành quân Hậu 2
};
void LamSang(int i, int j, int color)
{
	int xx = 10 * j + minx;
	int yy = 6 * i + miny;
	if (color == 1)
		textcolor(492);
	else if (color == 2)
		textcolor(460);
	else
		textcolor(32);
	gotoxy(xx, yy);
	cout << " ";
	gotoxy(xx, yy + 5);
	cout << " ";
	gotoxy(xx + 9, yy);
	cout << " ";
	gotoxy(xx + 9, yy + 5);
	cout << " ";
	textcolor(7);
}
void HuySang(int i, int j)
{
	int xx = 10 * j + minx;
	int yy = 6 * i + miny;
	if (i % 2 == j % 2)
		textcolor(391);
	else
		textcolor(48);
	gotoxy(xx, yy);
	cout << " ";
	gotoxy(xx, yy + 5);
	cout << " ";
	gotoxy(xx + 9, yy);
	cout << " ";
	gotoxy(xx + 9, yy + 5);
	cout << " ";
	textcolor(7);
}
void VeOCo(int t, int x, int y)
{
	if (t % 2 == 0) // white
	{

		textcolor(48);
		for (int j = y; j < y + 6; j++)
		{
			gotoxy(x, j);

			cout << "          ";

		}

	}
	else // black
	{
		textcolor(391);
		for (int j = y; j < y + 6; j++)
		{
			gotoxy(x, j);

			cout << "          ";

		}

	}
	textcolor(7);
}
void VeBanCo()
{
	// Vẽ ô cờ
	int t;
	for (int i = 0; i <= 7; i++)
	{
		for (int j = 0; j <= 7; j++)
		{
			if ((i % 2) == (j % 2))
				t = 1;
			else
				t = 0;
			VeOCo(t, minx + 10 * i, miny + 6 * j);
		}
	}
	// Vẽ thanh 1, 2, 3.. bên lề trái
	for (int i = 0; i <= 7; i++)
	{
		gotoxy(3, 3 + 6 * i + 3);
		cout << i + 1;
	}
	// Vẽ thanh a, b , c .. ở trên
	char c = 'a';
	for (int i = 0; i <= 7; i++)
	{
		gotoxy(4 + 10 * i + 4, 2);
		cout << c;
		c++;
	}
}
void XuatLuotDi(int team)
{
	if (team == 1)
	{
		gotoxy(100, 28);
		textcolor(14);
		cout << "PLAYER 1";
		gotoxy(100, 25);
		textcolor(7);
		cout << "PLAYER 2";
	}
	else
	{
		gotoxy(100, 25);
		textcolor(14);
		cout << "PLAYER 2";
		gotoxy(100, 28);
		textcolor(7);
		cout << "PLAYER 1";
	}
}
void XacDinhQuanCo(char c, int &x, int &y)
{
	if (c == 's' && (x + 1 < 8))
	{
		HuySang(x, y);
		x++;
	}
	if (c == 'w' && (x - 1 >= 0))
	{
		HuySang(x, y);
		x--;
	}
	if (c == 'd' && (y + 1 < 8))
	{
		HuySang(x, y);
		y++;
	}
	if (c == 'a' && (y - 1 >= 0))
	{
		HuySang(x, y);
		y--;
	}
	LamSang(x, y, 1);
}
void SetWindow(int Width, int Height)
{
	_COORD coord;
	coord.X = Width;
	coord.Y = Height;

	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Bottom = Height - 1;
	Rect.Right = Width - 1;

	HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);      // Get Handle 
	SetConsoleScreenBufferSize(Handle, coord);            // Set Buffer Size 
	SetConsoleWindowInfo(Handle, TRUE, &Rect);            // Set Window Size 
}
void InMenu()
{

	fstream f;
	gotoxy(1, 28);
	f.open("Screen5.txt", ios::in);
	while (!f.eof())
	{
		string s;
		getline(f, s);
		cout << s << endl;
	}
	f.close();
}
void Inp1vsp2()
{
	InMenu();
	fstream f;
	gotoxy(1, 28);
	textcolor(14);
	f.open("Screen1.txt", ios::in);
	while (!f.eof())
	{
		string s;
		getline(f, s);
		cout << s << endl;
	}
	textcolor(7);
	f.close();
}
void Inhistory()
{
	InMenu();
	fstream f;
	gotoxy(1, 36);
	textcolor(14);
	f.open("Screen3.txt", ios::in);
	while (!f.eof())
	{
		string s;
		getline(f, s);
		cout << s << endl;
	}
	textcolor(7);
	f.close();
}
void Inexit()
{
	InMenu();
	fstream f;
	gotoxy(1, 40);
	textcolor(14);
	f.open("Screen4.txt", ios::in);
	while (!f.eof())
	{
		string s;
		getline(f, s);
		cout << s << endl;
	}
	textcolor(7);
	f.close();
}
void Inlaw()
{
	InMenu();
	fstream f;
	gotoxy(1, 32);
	textcolor(14);
	f.open("Screen2.txt", ios::in);
	while (!f.eof())
	{
		string s;
		getline(f, s);
		cout << s << endl;
	}
	textcolor(7);
	f.close();
}
void QuanCoKhongHopLe(int team)
{
	textcolor(463);
	if (team == 2)
	{
		gotoxy(90, 20);
		cout << "				";
		gotoxy(90, 21);
		cout << "				";
		gotoxy(90, 22);
		cout << "				";
		gotoxy(91, 21);
		cout << "ILLEGAL. Please choose again";
		textcolor(7);
	}
	else
	{
		gotoxy(90, 30);
		cout << "				";
		gotoxy(90, 31);
		cout << "				";
		gotoxy(90, 32);
		cout << "				";
		gotoxy(91, 31);
		cout << "ILLEGAL. Please choose again";
		textcolor(7);
	}
}
void HuyNuocDi(int team)
{
	textcolor(164);
	if (team == 2)
	{
		gotoxy(90, 20);
		cout << "				";
		gotoxy(90, 21);
		cout << "				";
		gotoxy(90, 22);
		cout << "				";
		gotoxy(93, 21);
		cout << "	Go Back";
		textcolor(7);
	}
	else
	{
		gotoxy(90, 30);
		cout << "				";
		gotoxy(90, 31);
		cout << "				";
		gotoxy(90, 32);
		cout << "				";
		gotoxy(93, 31);
		cout << "	Go Back";
		textcolor(7);
	}
}
void ViTriKhongHopLe(int team)
{
	textcolor(116);
	if (team == 2)
	{
		gotoxy(90, 20);
		cout << "				";
		gotoxy(90, 21);
		cout << "				";
		gotoxy(90, 22);
		cout << "				";
		gotoxy(91, 21);
		cout << "ILLEGAL. Please choose again";
		textcolor(7);
	}
	else
	{
		gotoxy(90, 30);
		cout << "				";
		gotoxy(90, 31);
		cout << "				";
		gotoxy(90, 32);
		cout << "				";
		gotoxy(91, 31);
		cout << "ILLEGAL. Please choose again";
		textcolor(7);
	}
}
void ThongBaoNguoiWin(int team)
{

	textcolor(462);
	gotoxy(30, 24);
	cout << "	   		     ";
	gotoxy(30, 25);
	cout << "	   		     ";
	gotoxy(30, 26);
	cout << "			     ";
	gotoxy(30, 27);
	cout << "			     ";
	gotoxy(30, 26);
	if (team != 0)
		cout << "     Player  " << team << " Won ";
	else
		cout << "	    --> Draw <--";
	gotoxy(32, 25);
	textcolor(202);
	cout << "   Outcome of game: ";
	textcolor(7);
}
const std::string currentDateTime()
{
	time_t     now = time(0);
	struct tm  tstruct;
	char       buf[80];
	tstruct = *localtime(&now);
	// Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
	// for more information about date/time format
	strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

	return buf;
}
void GhiVaoLichSu(char* ten1, char* ten2, int KetQua) // Doi thang 1 2
{

	fstream f;
	// đầu tiên đảo lịch sử
	stack <string> history;
	f.open("History.txt", ios::in);
	while (!f.eof())
	{
		string s;
		getline(f, s);
		history.push(s);
	}
	f.close();
	f.open("History.txt", ios::out);
	while (history.empty() != 1)
	{
		f << history.top() << endl;
		history.pop();
	}
	f.close();
	f.open("History.txt", ios::app);
	// ghi lịch sử vào cuối
	if (KetQua == 1)
	{
		f << ten1 << " -Won- " << ten2 << "                            " << currentDateTime() << endl;
	}
	else if (KetQua == 2)
	{
		f << ten1 << " -Lost- " << ten2 << "                            " << currentDateTime() << endl;
	}
	else
	{
		f << ten1 << " -Draw- " << ten2 << "                            " << currentDateTime() << endl;
	}
	f.close();
	// Đảo lại
	f.open("History.txt", ios::in);
	while (!f.eof())
	{
		string s;
		getline(f, s);
		history.push(s);
	}
	f.close();
	f.open("History.txt", ios::out);
	while (history.empty() != 1)
	{
		f << history.top() << endl;
		history.pop();
	}
	f.close();

}
int CauHoa(int team)
{
	textcolor(463);
	gotoxy(30, 23);
	cout << "	   		          ";
	gotoxy(30, 24);
	cout << "	   		          ";
	gotoxy(30, 25);
	cout << "	   		          ";
	gotoxy(30, 26);
	cout << "			          ";
	gotoxy(30, 27);
	cout << "			          ";
	gotoxy(45, 26);
	cout << " YES";
	textcolor(462);
	gotoxy(35, 26);
	cout << ">NO";
	textcolor(202);
	gotoxy(30, 24);
	cout << "Do you want to Claim a DRAW ?";

	int draw = 0;
	while (1)
	{
		if (_kbhit())
		{
			char c = _getch();
			if (c == 'd' && draw == 0)
			{
				textcolor(463);
				gotoxy(35, 26);
				cout << " NO";
				textcolor(462);
				gotoxy(45, 26);
				cout << ">YES";
				draw++;
			}
			if (c == 'a' && draw == 1)
			{
				textcolor(463);
				gotoxy(45, 26);
				cout << " YES";
				textcolor(462);
				gotoxy(35, 26);
				cout << ">NO";
				draw--;
			}
			if (c == 13)
				break;
		}
	}
	textcolor(7);
	if (draw == 1)
		return 1;
	else
		return 0;
}
int DongYHoa(int team)
{
	textcolor(463);
	gotoxy(30, 23);
	cout << "	   		     ";
	gotoxy(30, 24);
	cout << "	   		     ";
	gotoxy(30, 25);
	cout << "	   		     ";
	gotoxy(30, 26);
	cout << "			     ";
	gotoxy(30, 27);
	cout << "			     ";
	gotoxy(30, 24);
	cout << "	      EXIT ?    ";
	gotoxy(45, 26);
	cout << " YES";
	textcolor(462);
	gotoxy(35, 26);
	cout << ">NO";
	textcolor(202);
	gotoxy(30, 24);
	cout << "	 P" << team % 2 + 1 << " OFFERS DRAW ?";

	int draw = 0;
	while (1)
	{
		if (_kbhit())
		{
			char c = _getch();
			if (c == 'd' && draw == 0)
			{
				textcolor(463);
				gotoxy(35, 26);
				cout << " NO";
				textcolor(462);
				gotoxy(45, 26);
				cout << ">YES";
				draw++;
			}
			if (c == 'a' && draw == 1)
			{
				textcolor(463);
				gotoxy(45, 26);
				cout << " YES";
				textcolor(462);
				gotoxy(35, 26);
				cout << ">NO";
				draw--;
			}
			if (c == 13)
				break;
		}
	}
	textcolor(7);
	if (draw == 1)
		return 1;
	else
		return 0;
}
void PlayMusic(int n)
{
	if (n == 0)
		sndPlaySound("LacTroi.wav", SND_ASYNC);
	else
	if (n == 1)
		sndPlaySound("HowLong.wav", SND_ASYNC);
	else
		sndPlaySound("TuyAm.wav", SND_ASYNC);
}
void StopMusic()
{
	sndPlaySound(NULL, SND_ASYNC);
}
// HÀM BÀN CỜ
void TaoBanCo()
{
	for (int i = 0; i < 8; i++)
	for (int j = 0; j < 8; j++)
	{
		Banco[i][j] = new QuanCo(i, j);
	}// Tạo tốt cho 2 team
	for (int j = 0; j < 8; j++)
	{
		Banco[1][j] = new Tot2(1, j);
		Banco[6][j] = new Tot1(6, j);
	}
	// Tạo các quân cờ team 2
	Banco[0][0] = new Thanh2(0, 0);
	Banco[0][7] = new Thanh2(0, 7);
	Banco[0][1] = new Ma2(0, 1);
	Banco[0][6] = new Ma2(0, 6);
	Banco[0][2] = new Tinh2(0, 2);
	Banco[0][5] = new Tinh2(0, 5);
	Banco[0][3] = new Hau2(0, 3);
	Banco[0][4] = new Tuong2(0, 4);
	// Tạo các quân cờ team 1
	Banco[7][0] = new Thanh1(7, 0);
	Banco[7][7] = new Thanh1(7, 7);
	Banco[7][1] = new Ma1(7, 1);
	Banco[7][6] = new Ma1(7, 6);
	Banco[7][2] = new Tinh1(7, 2);
	Banco[7][5] = new Tinh1(7, 5);
	Banco[7][3] = new Hau1(7, 3);
	Banco[7][4] = new Tuong1(7, 4);
}
// Hàm vẽ ra bàn cờ
void XuatBanCo(char* ten1, char* ten2)
{
	gotoxy(50, 10);
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		if (Banco[i][j]->team != 0)
			Banco[i][j]->display(i, j);
	}
	gotoxy(85, 26);
	cout << " __ __ _ __ ______________ __ __ __ __ ";
	gotoxy(109, 28);
	cout << ": " << ten1;
	gotoxy(109, 25);
	cout << ": " << ten2;
	gotoxy(1, 53);
	cout << "  W, A, S, D: Move	   BACKSPACE: Back      ENTER: Choose     R: Resign    O: Offer draw    M: Music   N: Next song";
}
// Hàm tìm xem trên bàn cờ có nước đi nào hợp lệ không
int CoNuocDi(QuanCo* &x)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		if (x->KiemTra(i, j) == 1)
			return 1;
	}
	return 0;
}
// Hàm in ra các vị trí khả thi
void InCacViTriKhaThi(int x, int y)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		if (Banco[x][y]->KiemTra(i, j) == 1)
			LamSang(i, j, 3);
	}
}
// Hàm xác định vị trí
void XacDinhViTri(char c, int x, int y, int &newx, int &newy)
{

	if (c == 's' && (newx + 1 < 8))
	{
		HuySang(newx, newy);
		newx++;
	}
	if (c == 'w' && (newx - 1 >= 0))
	{
		HuySang(newx, newy);
		newx--;
	}
	if (c == 'd' && (newy + 1 < 8))
	{
		HuySang(newx, newy);
		newy++;
	}
	if (c == 'a' && (newy - 1 >= 0))
	{
		HuySang(newx, newy);
		newy--;
	}
	InCacViTriKhaThi(x, y);
	LamSang(newx, newy, 1);
}
// Cơ chế phong tốt
void PhongTot(int newx, int newy, int team)
{
	textcolor(463);
	gotoxy(27, 25);
	cout << "		   		     ";
	gotoxy(27, 26);
	cout << "				     ";
	gotoxy(27, 27);
	cout << "				     ";
	gotoxy(27, 28);
	cout << "				     ";
	gotoxy(30, 26);
	textcolor(202);
	cout << "	  ---> PROMOTE <---    ";
	textcolor(463);
	gotoxy(40, 27);
	cout << " Rock";
	gotoxy(47, 27);
	cout << " Bishop";
	gotoxy(55, 27);
	cout << " Queen";
	textcolor(462);
	gotoxy(30, 27);
	cout << ">Knight";
	int ChonQuan = 1; // 1 ma 2 thanh 3 tinh 4 hau
	while (1)
	{
		if (_kbhit())
		{
			char c = _getch();
			if (c == 'd' &&  ChonQuan<4)
				ChonQuan++;
			if (c == 'a' && ChonQuan>1)
				ChonQuan--;
			if (ChonQuan == 1)
			{
				textcolor(463);
				gotoxy(40, 27);
				cout << " Rock";
				gotoxy(47, 27);
				cout << " Bishop";
				gotoxy(55, 27);
				cout << " Queen";
				textcolor(462);
				gotoxy(30, 27);
				cout << ">Knight";
			}
			else if (ChonQuan == 2)
			{
				textcolor(463);
				gotoxy(30, 27);
				cout << " Knight";
				gotoxy(47, 27);
				cout << " Bishop";
				gotoxy(55, 27);
				cout << " Queen";
				textcolor(462);
				gotoxy(40, 27);
				cout << ">Rock";
			}
			else if (ChonQuan == 3)
			{
				textcolor(463);
				gotoxy(30, 27);
				cout << " Knight";
				gotoxy(40, 27);
				cout << " Rock";
				gotoxy(55, 27);
				cout << " Queen";
				textcolor(462);
				gotoxy(47, 27);
				cout << ">Bishop";
			}
			else
			{
				textcolor(463);
				gotoxy(30, 27);
				cout << " Knight";
				gotoxy(40, 27);
				cout << " Rock";
				gotoxy(47, 27);
				cout << " Bishop";
				textcolor(462);
				gotoxy(55, 27);
				cout << ">Queen";
			}
			if (c == 13)
				break;
		}
	}
	if (team == 1)
	{
		switch (ChonQuan)
		{
		case 1:
		{
				  Banco[newx][newy] = new Ma1(newx, newy);
				  break;
		}
		case 2:
		{
				  Banco[newx][newy] = new Thanh1(newx, newy);
				  break;
		}
		case 3:
		{
				  Banco[newx][newy] = new Tinh1(newx, newy);
				  break;
		}
		case 4:
		{
				  Banco[newx][newy] = new Hau1(newx, newy);
				  break;
		}
		default:
			break;
		}
	}
	else
	{

		switch (ChonQuan)
		{
		case 1:
		{
				  Banco[newx][newy] = new Ma2(newx, newy);
				  break;
		}
		case 2:
		{
				  Banco[newx][newy] = new Thanh2(newx, newy);
				  break;
		}
		case 3:
		{
				  Banco[newx][newy] = new Tinh2(newx, newy);
				  break;
		}
		case 4:
		{
				  Banco[newx][newy] = new Hau2(newx, newy);
				  break;
		}
		default:
			break;
		}
	}
	textcolor(7);
}
// Cơ chế Menu
void Lawofchess()
{
	gotoxy(40, 2);
	textcolor(14);
	cout << "The law of The Chess";
	gotoxy(4, 48);
	cout << "Press ESC to BACK to Menu";
	textcolor(7);
	Tot1 a;
	Thanh1 b;
	Ma1 c;
	Tinh1 d;
	Hau1 e;
	Tuong1 f;
	a.display(0, 0);
	gotoxy(13, 4);
	cout << "The pawn may move forward to the square immediately in front of it on the same file, ";
	gotoxy(13, 5);
	cout << "provided that this square is unoccupied, or on its first move the pawn may move ";
	gotoxy(13, 6);
	cout << "or alternatively it may advance two squares along the same file, provided that both squares are unoccupied";
	gotoxy(13, 7);
	cout << "the pawn may move to a square occupied by an opponent’s piece diagonally in front of it on an adjacent file, ";
	gotoxy(13, 8);
	cout << "capturing that piece.";
	b.display(2, 0);
	gotoxy(14, 15);
	cout << "The rook may move to any square along ";
	gotoxy(14, 16);
	cout << "the file or the rank on which it stands.";
	c.display(2, 5);
	gotoxy(64, 15);
	cout << "The knight may move to one of the squares";
	gotoxy(64, 16);
	cout << "nearest to that on which it stands but";
	gotoxy(64, 17);
	cout << "not on the same rank, file or diagonal.";
	d.display(4, 0);
	gotoxy(14, 27);
	cout << "The bishop may move to any square";
	gotoxy(14, 28);
	cout << "along a diagonal on which it stands.";
	e.display(4, 5);
	gotoxy(64, 27);
	cout << "The queen may move to any square along the file,";
	gotoxy(64, 28);
	cout << "the rank or a diagonal on which it stands.";
	f.display(6, 0);
	gotoxy(14, 39);
	cout << "There are two different ways of moving the king: ";
	gotoxy(14, 40);
	cout << "by moving to an adjoining square and by 'castling'.";
}
void Intro(char* ten1, char* ten2)
{
Login:
	system("cls");
	fstream f;
	f.open("Screen.txt", ios::in);
	int color = 9;
	while (!f.eof())
	{
		string s;
		getline(f, s);
		if (color < 15)
			color++;
		else
			color = 9;
		textcolor(color);
		cout << s << endl;
	}
	textcolor(7);
	InMenu();
	int Menu = 0;
	while (1)
	{

		textcolor(7);
		f.close();
		// 0. p1 vs p2 // //2, history // 1. The law of chess // 3. exit
		// gotoxy(100, 20);
		if (_kbhit())
		{

			char c = _getch();
			if (c == 'w' && Menu > 0)
			{
				Menu--;
			}
			if (c == 's' && Menu < 4)
			{
				Menu++;
			}
			if (Menu == 0)
			{
				Inp1vsp2();
			}
			if (Menu == 1)
			{
				Inlaw();
			}
			if (Menu == 2)
			{
				Inhistory();
			}
			if (Menu == 3)
			{
				Inexit();
			}
			if (c == 13)
				break;
		}
		XoaManHinh();
	}
	if (Menu == 2)
	{
		system("cls");
		textcolor(14);
		cout << "	Histoty <ESC to Back> " << endl << endl;
		textcolor(7);
		f.open("History.txt", ios::in);
		while (!f.eof())
		{
			string s;
			getline(f, s);
			cout << s << endl;
		}
		while (1)
		{
			if (_kbhit())
			{
				char c = _getch();
				if (c == 27)
					goto Login;
			}
		}
	}
	if (Menu == 3)
	{
		exit(0);
	}
	if (Menu == 1)
	{
		system("cls");
		Lawofchess();
		while (1)
		{
			if (_kbhit())
			{
				char c = _getch();
				if (c == 27)
					goto Login;
			}
		}
	}
	if (Menu == 0)
	{
		textcolor(8);
		gotoxy(5, 34);
		cout << "(Max is 15 characters)";
		gotoxy(5, 36);
		textcolor(14);
		cout << "Name of player 1: ";
		textcolor(7);

		do{
			gotoxy(5, 37);
			cin.getline(ten1, 15);
		} while (strlen(ten1) == 0);

		gotoxy(5, 40);
		textcolor(14);
		cout << "Name of player 2: ";
		textcolor(7);
		do
		{
			gotoxy(5, 41);
			cin.getline(ten2, 15);
		} while (strlen(ten2) == 0);
	}
	system("cls");
	Sleep(500);
}
// Thông báo số quân 
void ThongBaoQuanMat(int ntot, int nthanh, int nma, int ntinh, int  nhau, int team)
{
	if (team == 2)
	{
		QuanCo* a = new Tot2;
		QuanCo* b = new Ma2;
		QuanCo* c = new Thanh2;
		QuanCo* d = new Hau2;
		QuanCo* e = new Tinh2;
		textcolor(140);
		for (int dem = 0; dem < 12; dem++)
		{
			gotoxy(minx + 10 * 8 + 1, miny + 6 * 6 + dem);
			cout << "                                       ";
		}
		// Tọa độ thông báo team 1
		a->display(7, 8);
		b->display(7, 9);
		c->display(7, 10);
		d->display(6, 8);
		e->display(6, 9);
		textcolor(14);
		gotoxy(minx + 10 * 8 + 1 + 3, miny + 7 * 6 + 5);
		cout << ntot;
		gotoxy(minx + 10 * 9 + 1 + 3, miny + 7 * 6 + 5);
		cout << nma;
		gotoxy(minx + 10 * 10 + 1 + 3, miny + 7 * 6 + 5);
		cout << nthanh;
		gotoxy(minx + 10 * 8 + 1 + 3, miny + 6 * 6 + 5);
		cout << nhau;
		gotoxy(minx + 10 * 9 + 1 + 3, miny + 6 * 6 + 5);
		cout << ntinh;
		textcolor(7);
		delete a, b, c, d, e;
	}
	else
	{
		QuanCo* a = new Tot1;
		QuanCo* b = new Ma1;
		QuanCo* c = new Thanh1;
		QuanCo* d = new Hau1;
		QuanCo* e = new Tinh1;
		textcolor(140);
		for (int dem = 0; dem < 12; dem++)
		{
			gotoxy(minx + 10 * 8 + 1, miny + dem);
			cout << "                                       ";
		}
		// Tọa độ thông báo team 2
		gotoxy(minx + 10 * 8 + 1, miny);
		a->display(1, 8);
		b->display(1, 9);
		c->display(1, 10);
		d->display(0, 8);
		e->display(0, 9);
		textcolor(30);
		gotoxy(minx + 10 * 8 + 1 + 3, miny + 1 * 6 + 5);
		cout << ntot;
		gotoxy(minx + 10 * 9 + 1 + 3, miny + 1 * 6 + 5);
		cout << nma;
		gotoxy(minx + 10 * 10 + 1 + 3, miny + 1 * 6 + 5);
		cout << nthanh;
		gotoxy(minx + 10 * 8 + 1 + 3, miny + 5);
		cout << nhau;
		gotoxy(minx + 10 * 9 + 1 + 3, miny + 5);
		cout << ntinh;
		textcolor(7);
		delete a, b, c, d, e;
	}
}
// Thông báo chiếu tướng
void ThongBaoChieuTuong(int team)
{
	int xTuong, yTuong;
	// Xác định vị trí tướng của team 
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (team == 1 && Banco[i][j]->name == "tuong1")
			{
				xTuong = i;
				yTuong = j;
				break;
			}
			else
			if (team == 2 && Banco[i][j]->name == "tuong2")
			{
				xTuong = i;
				yTuong = j;
				break;
			}

		}
	}
	// đã xác định được vị trí tướng team
	// Kiểm tra xem có bị quân nào team kia chiếu đến không
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		if (Banco[i][j]->KiemTra(xTuong, yTuong) == 1)
		{
			LamSang(i, j, 2);
			LamSang(xTuong, yTuong, 2);
		}
	}
}
// Muốn đầu hàng
int MuonDauHang(int team)
{
	textcolor(463);
	gotoxy(30, 23);
	cout << "	   		     ";
	gotoxy(30, 24);
	cout << "	   		     ";
	gotoxy(30, 25);
	cout << "	   		     ";
	gotoxy(30, 26);
	cout << "			     ";
	gotoxy(30, 27);
	cout << "			     ";
	gotoxy(30, 24);
	cout << "	      EXIT ?    ";
	gotoxy(45, 26);
	cout << " YES";
	textcolor(462);
	gotoxy(35, 26);
	cout << ">NO";
	textcolor(202);
	gotoxy(30, 24);
	cout << "	  P" << team << " want RESIGN ?";

	int exit = 0;
	while (1)
	{
		if (_kbhit())
		{
			char c = _getch();
			if (c == 'd' && exit == 0)
			{
				textcolor(463);
				gotoxy(35, 26);
				cout << " NO";
				textcolor(462);
				gotoxy(45, 26);
				cout << ">YES";
				exit++;
			}
			if (c == 'a' && exit == 1)
			{
				textcolor(463);
				gotoxy(45, 26);
				cout << " YES";
				textcolor(462);
				gotoxy(35, 26);
				cout << ">NO";
				exit--;
			}
			if (c == 13)
				break;
		}
	}
	textcolor(7);
	if (exit == 1)
		return 1;
	else
		return 0;
}
int NhanVaoNutDauHang(char c, int team, char* ten1, char* ten2)
{
	if (c == 'r')
	{
		if (MuonDauHang(team))
		{
			return 1;
		}
		else
		{
			VeBanCo();
			XuatBanCo(ten1, ten2);
			XuatLuotDi(team);
			return 0;
		}
	}
	else
		return 0;
}
// Cầu hòa
int NhanVaoNutCauHoa(char c, int team, char* ten1, char* ten2)
{
	if (c == 'o')
	{
		if (CauHoa(team))
		{
			VeBanCo();
			XuatBanCo(ten1, ten2);
			XuatLuotDi(team);
			return 1;
		}
		else
		{
			VeBanCo();
			XuatBanCo(ten1, ten2);
			XuatLuotDi(team);
			return 0;
		}
	}
	else
		return 0;
}
// Hàm chơi nhạc
void ChoiNhac(int n, int m)
{
	if (n == 1)
		PlayMusic(m);
	else
		StopMusic();
}
void Sound(int &music, int &n, char c)
{
	if (c == 'm')
	{
		music = music % 2 + 1;
		ChoiNhac(music, n);
	}
	if (c == 'n')
	{
		StopMusic();
		n++;
		n = n % 3;
		ChoiNhac(music, n);
	}
}
// Xử lí game
void XuLiGame()
{
Start:
	char ten1[16], ten2[16];
	system("cls");
	XoaManHinh();
	Intro(ten1, ten2);
	TaoBanCo();
	VeBanCo();
	XuatBanCo(ten1, ten2);
	// Số lượng các quân cờ bị mất ban đầu
	int ntot1 = 0, ntot2 = 0, nthanh1 = 0, nthanh2 = 0, nma1 = 0, nma2 = 0, ntinh1 = 0, ntinh2 = 0, nhau1 = 0, nhau2 = 0;
	int team = 1; int ch1 = 0, ch2 = 0;
	int music = 2; int n = 0;
	while (1)
	{

		int x, y = 3;
	TimQuanCo:
		// Thông báo số quân cờ bị mất
		ThongBaoQuanMat(ntot1, nthanh1, nma1, ntinh1, nhau1, 1);
		ThongBaoQuanMat(ntot2, nthanh2, nma2, ntinh2, nhau2, 2);
		VeBanCo();
		XuatBanCo(ten1, ten2);
		XuatLuotDi(team);
		if (team == 1)
		{
			x = 7;
		}
		else
		{
			x = 0;
		}
		// Vòng lặp xác định quân cờ di chuyển
		while (1)
		{
			// Chiếu Tướng
			ThongBaoChieuTuong(team);
			if (_kbhit())
			{
				char c = _getch();
				XacDinhQuanCo(c, x, y);
				//if (NhanVaoNutExit(c, team, ten1, ten2) == 1) // xac dinh exit game
				//goto Start;
				if (NhanVaoNutDauHang(c, team, ten1, ten2) == 1)  // Xac dinh dau hang
				{
					ThongBaoNguoiWin((team % 2) + 1);
					GhiVaoLichSu(ten1, ten2, (team % 2) + 1);
					_getch();
					goto Start;
				}
				// Code chơi nhạc
				Sound(music, n, c);
				// code đầu hàng
				if (NhanVaoNutCauHoa(c, team, ten1, ten2) == 1)
				{
					if (team == 1)
						ch1 = 1;
					else
						ch2 = 1;
				}
				if (team == 1 && ch2 == 1)
				{
					if (DongYHoa(team) == 1)
					{
						GhiVaoLichSu(ten1, ten2, 0);
						ThongBaoNguoiWin(0);
						_getch();
						goto Start;
					}
					else
					{
						ch2 = 0;
						VeBanCo();
						XuatBanCo(ten1, ten2);
						XuatLuotDi(team);

					}
				}
				if (team == 2 && ch1 == 1)
				{
					if (DongYHoa(team) == 1)
					{
						GhiVaoLichSu(ten1, ten2, 0);
						ThongBaoNguoiWin(0);
						_getch();
						goto Start;
					}
					else
					{
						ch1 = 0;
						VeBanCo();
						XuatBanCo(ten1, ten2);
						XuatLuotDi(team);
					}
				}
				//
				if (c == 13)
				{
					if (Banco[x][y]->team == team && CoNuocDi(Banco[x][y]) == 1) // Quân Cờ hợp lệ
					{
						break;
					}
					else
					{
						QuanCoKhongHopLe(team);
						HuySang(x, y);
						goto TimQuanCo;
					}
				}

			}
		}
	TimViTri:
		int newx = x, newy = y;
		// Vòng lặp xác định vị trí di chuyển tới
		while (1)
		{
			if (newx == x && newy == y)
				InCacViTriKhaThi(x, y);
			LamSang(x, y, 2);
			if (_kbhit())
			{
				char c = _getch();

				XacDinhViTri(c, x, y, newx, newy);
				//if (NhanVaoNutExit(c, team, ten1, ten2)==1)
				//goto Start ;
				if (NhanVaoNutDauHang(c, team, ten1, ten2) == 1)  // Xac dinh dau hang
				{
					ThongBaoNguoiWin((team % 2) + 1);
					GhiVaoLichSu(ten1, ten2, (team % 2) + 1);
					_getch();
					goto Start;
				}
				// Code chơi nhạc
				Sound(music, n, c);
				// code đầu hàng
				if (NhanVaoNutCauHoa(c, team, ten1, ten2) == 1)
				{
					if (team == 1)
						ch1 = 1;
					else
						ch2 = 1;
				}
				if (team == 1 && ch2 == 1)
				{
					if (DongYHoa(team) == 1)
					{
						GhiVaoLichSu(ten1, ten2, 0);
						ThongBaoNguoiWin(0);
						_getch();
						goto Start;
					}
					else
					{
						ch2 = 0;
						VeBanCo();
						XuatBanCo(ten1, ten2);
						XuatLuotDi(team);

					}
				}
				if (team == 2 && ch1 == 1)
				{
					if (DongYHoa(team) == 1)
					{
						GhiVaoLichSu(ten1, ten2, 0);
						ThongBaoNguoiWin(0);
						_getch();
						goto Start;
					}
					else
					{
						ch1 = 0;
						VeBanCo();
						XuatBanCo(ten1, ten2);
						XuatLuotDi(team);
					}
				}
				//
				if (c == 8)
				{
					HuySang(x, y);
					HuySang(newx, newy);
					HuyNuocDi(team);
					goto TimQuanCo;
				}
				if (c == 13)
				{
					if (Banco[x][y]->KiemTra(newx, newy) == 0)// di chuyen khong thanh cong 
					{
						ViTriKhongHopLe(team);
						HuySang(newx, newy);
						goto TimViTri;
					}
					break;
				}

			}
		}
		int end = 0;
		if (Banco[newx][newy]->name == "tuong1" || Banco[newx][newy]->name == "tuong2" && Banco[x][y]->KiemTra(newx, newy) == 1)
			end = 1; // Tướng bị ăn
		string s = Banco[newx][newy]->name;
		// Đếm số quân bị mất
		if (s == "tot1")
			ntot1++;
		if (s == "tot2")
			ntot2++;
		if (s == "thanh1")
			nthanh1++;
		if (s == "thanh2")
			nthanh2++;
		if (s == "ma1")
			nma1++;
		if (s == "ma2")
			nma2++;
		if (s == "tinh1")
			ntinh1++;
		if (s == "tinh2")
			ntinh2++;
		if (s == "hau1")
			nhau1++;
		if (s == "hau2")
			nhau2++;
		Banco[x][y]->move(newx, newy);
		if (end == 1)
		{
			ThongBaoNguoiWin(team);
			if (team == 1)
				GhiVaoLichSu(ten1, ten2, 1);
			else
				GhiVaoLichSu(ten1, ten2, 2);
			_getch();
			goto Start;
		}
		// Phong tốt
		if ((Banco[newx][newy]->name == "tot1" || Banco[newx][newy]->name == "tot2") && (newx == 0 || newx == 7))
			PhongTot(newx, newy, team);
		if (team == 1)
			team = 2;
		else
			team = 1;
		system("cls");
	}
}
// Giải phóng bộ nhớ
void GiaiPhong()
{
	for (int i = 0; i < 8; i++)
	for (int j = 0; j < 8; j++)
		delete Banco[i][j];
}