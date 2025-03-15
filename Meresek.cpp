#include <iostream>
#include <fstream>
using namespace std;

class Meresek
{
	private:
		int db=0;
		double* y=nullptr;
		double ln = 0;
		double lk = 0;
	public:
		Meresek();
		Meresek(string fnev);
		~Meresek();
		double getLn() const;
		double getLk() const;
		int getDb() const;
		double gety(int i) const;
		void Kiir();
		void Kiir(string fnev);
};


int main()
{
	//Meres m; // Beolvasás billentyûzetrõl.
	setlocale(LC_ALL, "HUN");
	Meresek m("meres.txt"); // Beolvasás fájlból.
	cout << "\nA mért adatok:" << endl;
	m.Kiir();
	cout << "\nA legnagyobb mért adat: " << m.getLn() << endl;
	cout << "\nA legkisebb mért adat: " << m.getLk() << endl;
	cout << "Az adatok kiírása fájlba." << endl;
	m.Kiir("adatok.txt");
	// Dinamikus objektum.
	Meresek* p = new Meresek("meres.txt");
	if (p == NULL)
	{
		cerr << "Kevés a memória" << endl;
		system("pause");
		exit(-2);
	}
	cout << "\nA dinamikus objektum adatai:" << endl;
	p->Kiir();
	cout << "A legnagyobb adat: " << p->getLn() << endl;
	system("pause");
	return 0;
}


// Paraméter nélküli konstruktor. 
// Bekéri az adatok számát és az adatokat a billnetyûzetrõl.
Meresek::Meresek()
{
	do
	{
		cout << "Az adatok száma: ";
		cin >> db;
		cin.ignore();
	} while (db < 1);
	y = new double[db];
	if (y == NULL)
	{
		cerr << "Kevés a memória" << endl;
		exit(-1);
	}
	for (int i = 0; i < db; i++)
	{
		cout << i + 1 << ". adat: ";
		cin >> y[i];
		if (i == 0)
		{
			ln = y[i]; lk = y[i];
		}
		else
			if (y[i] > ln)
				ln = y[i];
			else
				if (y[i] < lk)
					lk = y[i];
	}
}

// Paraméteres konstruktor.
// Beolvassa az adatokat a paraméterként megadott fájlból. 
Meresek::Meresek(string fnev)
{
	ifstream be(fnev);
	if (!be.is_open())
	{
		cerr << "Hibás fájlnyitás" << endl;
		exit(-3);
	}
	be >> db;
	y = new double[db];
	if (y == NULL)
	{
		cerr << "Kevés a memória" << endl;
		exit(-1);
	}
	
	for (int i = 0; i < db; i++)
	{
		be >> y[i];
		if (i == 0)
		{
			ln = y[i]; lk = y[i];
		}
		else
			if (y[i] > ln)
				ln = y[i];
			else
				if (y[i] < lk)
					lk = y[i];
	}
	be.close();
}

int Meresek::getDb() const
{
	return db;
}

double Meresek::gety(int i) const
{
	return (i<0)?y[0]:((i>=db)?y[db-1]:y[i]);
}

// Destruktor. 
Meresek::~Meresek()
{
	delete[]y;
}

double Meresek::getLn() const
{
	return ln;
}

double Meresek::getLk() const
{
	return lk;
}



// Kiírja az adatokat a konzolra.
void Meresek::Kiir()
{
	cout << endl;
	for (int i = 0; i < db; i++)
	{
		cout << i + 1 << ". " << y[i] << endl;
	}
}

// Lementi az adatokat egy szöveges fájlba.
void Meresek::Kiir(string fnev)
{
	ofstream ki(fnev);
	if (!ki.is_open())
	{
		cerr << "Nem sikerült létrehozni az " << fnev << " adatállományt!";
		exit(-3);
	}
	ki << db << endl;
	for (int i = 0; i < db; i++)
		ki << y[i] << " ";
	ki.close();
}
