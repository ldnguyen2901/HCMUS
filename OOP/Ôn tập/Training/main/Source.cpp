#include<iostream>
#include<string>
using namespace std;

class Phu_nu
{
public:


	void trang_diem()
	{

	}

	virtual string choi_nhac_cu(string nhac_cu)
	{
		return "AAAAA";
	}
	Phu_nu(const string& ht, int t, bool z = true) //ht = "Maria Ozawa"
		:ho_ten(ht), tuoi(t), con_zin(z)
	{

	}

	void va_zin()
	{
		if (tuoi < 25)
		{
			con_zin = true;
		}
	}

	void show_hang()
	{
		cout << ho_ten << " " << (con_zin ? "con zin" : "mat zin") << endl;
	}

	Phu_nu() {}
	~Phu_nu()
	{
		cout << "Chia tay " << ho_ten << endl;
	}

protected:
	bool con_zin;
	string ho_ten;
	int tuoi;
};

class Gai_Ngoan : public Phu_nu
{
public:
	Gai_Ngoan(const string& ht, int t, bool z = true) //ht = "Maria Ozawa"
		:Phu_nu(ht, t, z)
	{}

	string choi_nhac_cu(string nhac_cu)
	{
		return "OoOoOoO";
	}

	void noi_tro() 
	{
		cout << ho_ten << " " << "dang lam noi tro" << endl;
	}
	Gai_Ngoan();
	~Gai_Ngoan();

private:

};

class Gai_Hu : public Phu_nu
{
public:
	Gai_Hu(const string& ht, int t, bool z = true) //ht = "Maria Ozawa"
		:Phu_nu(ht, t, z)
	{}

	string choi_nhac_cu(string nhac_cu)
	{
		return "UuUuUuU";
	}

	void di_bar() {}
	Gai_Hu();
	~Gai_Hu();

private:

};

Gai_Hu::Gai_Hu()
{
}

Gai_Hu::~Gai_Hu()
{
}

Gai_Ngoan::Gai_Ngoan()
{
}

Gai_Ngoan::~Gai_Ngoan()
{
}

class Dan_ong
{
public:
	Dan_ong();
	~Dan_ong();

private:

};

Dan_ong::Dan_ong()
{
}

Dan_ong::~Dan_ong()
{
}

int main()
{
	Phu_nu* maria_ozawa = new Gai_Hu("Maria Ozawa", 22, false);
	cout << maria_ozawa->choi_nhac_cu("ken") << endl;
	/*maria_ozawa->va_zin();
	maria_ozawa->show_hang();
	maria_ozawa->noi_tro();*/

	delete maria_ozawa;

	Dan_ong* vu = new Dan_ong;
	return 0;
}