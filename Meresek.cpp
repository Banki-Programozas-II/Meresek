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
	//Meres m; // Beolvas�s billenty�zetr�l.
	setlocale(LC_ALL, "HUN");
	Meresek m("meres.txt"); // Beolvas�s f�jlb�l.
	cout << "\nA m�rt adatok:" << endl;
	m.Kiir();
	cout << "\nA legnagyobb m�rt adat: " << m.getLn() << endl;
	cout << "\nA legkisebb m�rt adat: " << m.getLk() << endl;
	cout << "Az adatok ki�r�sa f�jlba." << endl;
	m.Kiir("adatok.txt");
	// Dinamikus objektum.
	Meresek* p = new Meresek("meres.txt");
	if (p == NULL)
	{
		cerr << "Kev�s a mem�ria" << endl;
		system("pause");
		exit(-2);
	}
	cout << "\nA dinamikus objektum adatai:" << endl;
	p->Kiir();
	cout << "A legnagyobb adat: " << p->getLn() << endl;
	system("pause");
	return 0;
}


// Param�ter n�lk�li konstruktor. 
// Bek�ri az adatok sz�m�t �s az adatokat a billnety�zetr�l.
Meresek::Meresek()
{
	do
	{
		cout << "Az adatok sz�ma: ";
		cin >> db;
		cin.ignore();
	} while (db < 1);
	y = new double[db];
	if (y == NULL)
	{
		cerr << "Kev�s a mem�ria" << endl;
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

// Param�teres konstruktor.
// Beolvassa az adatokat a param�terk�nt megadott f�jlb�l. 
Meresek::Meresek(string fnev)
{
	ifstream be(fnev);
	if (!be.is_open())
	{
		cerr << "Hib�s f�jlnyit�s" << endl;
		exit(-3);
	}
	be >> db;
	y = new double[db];
	if (y == NULL)
	{
		cerr << "Kev�s a mem�ria" << endl;
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



// Ki�rja az adatokat a konzolra.
void Meresek::Kiir()
{
	cout << endl;
	for (int i = 0; i < db; i++)
	{
		cout << i + 1 << ". " << y[i] << endl;
	}
}

// Lementi az adatokat egy sz�veges f�jlba.
void Meresek::Kiir(string fnev)
{
	ofstream ki(fnev);
	if (!ki.is_open())
	{
		cerr << "Nem siker�lt l�trehozni az " << fnev << " adat�llom�nyt!";
		exit(-3);
	}
	ki << db << endl;
	for (int i = 0; i < db; i++)
		ki << y[i] << " ";
	ki.close();
}
