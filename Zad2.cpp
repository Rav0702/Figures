#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <math.h>


using namespace std;

class Figura
{
	
};

class Czworokat: public Figura
{
	 public:
	 	double bok1, bok2, bok3, bok4, kat;
};

class Kolo: public Figura
{
	private:
		double promien;
	
	public:
		Kolo(double promien)
		{
			this-> promien= promien;
			if(promien< 0)
			{
				throw(string)" Niepoprawna dana";
				
			}
		}
		double pole()
		{
			return M_PI*promien*promien;
		}
		double obwod()
		{
			return 2*M_PI*promien;
		}
		~Kolo()
		{
			cout<<"zniszczono kolo\n";
		}
		
};

class Pieciokat: public Figura
{
	private:
		double bok;
	
	public:
		Pieciokat(double bok)
		{
			this-> bok= bok;
			if(bok< 0)
			{
				throw(string)" Niepoprawna dana";
				
			}
		}
		double pole()
		{
			return ((bok*bok)/4)*sqrt(25+10*sqrt(5));
		}
		double obwod()
		{
			return 5*bok;
		}
		~Pieciokat()
		{
			cout<<"zniszczono pieciokat\n";
		}
		
};

class Szesciokat: public Figura
{
	private:
		double bok;
	
	public:
		Szesciokat(double bok)
		{
			this-> bok= bok;
			if(bok< 0)
			{
				throw(string)" Niepoprawna dana";
				
			}
		}
		double pole()
		{
			return (3*bok*bok*sqrt(3))/2;
		}
		double obwod()
		{
			return 6*bok;
		}
		~Szesciokat()
		{
			cout<<"zniszczono szesciokat\n";
		}
		
};

class Kwadrat: public Czworokat
{
	private:
		double bok;
	
	public:
		Kwadrat(double bok)
		{
			this-> bok= bok;
			if(bok< 0)
			{
				throw(string)" Niepoprawna dana";
				
			}
		}
		double pole()
		{
			return bok*bok;
		}
		double obwod()
		{
			return 4*bok;
		}
		~Kwadrat()
		{
			cout<<"zniszczono kwadrat\n";
		}
		
};

class Prostokat: public Czworokat
{
	private:
		double b1, b2;
	
	public:
		Prostokat(double b1, double b2)
		{
			this-> b1= b1;
			this-> b2= b2;
			if(b1< 0|| b2< 0)
			{
				throw(string)" Niepoprawna dana";
				
			}
		}
		double pole()
		{
			return b1*b2;
		}
		double obwod()
		{
			return 2*b1+2*b2;
		}
		~Prostokat()
		{
			cout<<"zniszczono prostokat\n";
		}
		
};

class Romb: public Czworokat
{
	private:
		double bok, kat;
	
	public:
		Romb(double bok, double kat)
		{
			this-> bok= bok;
			this-> kat= kat;
			if(bok< 0 || kat>180 || kat<0)
			{
				throw(string)" Niepoprawna dana";
				
			}
		}
		double pole()
		{
			return bok*bok*sin(kat*M_PI/180);
		}
		double obwod()
		{
			return 4*bok;
		}
		~Romb()
		{
			cout<<"zniszczono romb\n";
		}
		
};

int main(int n, char* args[])
{
	if(n<2)
	{
		cout<<"brak dnych\n";
		return 1;
	}
	
	string kody_figur= args[1];
	int pozycja=2;
	
	for(int i=0; i<kody_figur.length(); i++)
	{
		if(kody_figur[i]== 'o')
		{
			try
			{
				Kolo* kolo= new Kolo(stod(args[pozycja]));
				pozycja++;
				cout<<"Obwod kola: "<< kolo->obwod()<< "\n";
				cout<<"Pole kola: "<< kolo->pole()<< "\n";
				delete kolo;
			}
			catch(string error)
			{
				cout<< args[pozycja] <<" "<< error<< "\n";
				exit(0);
			}
			
		}
		else if(kody_figur[i]== 'c')
		{
			double parametry[5];
			for(int j=0; j<5; j++)
			{
					parametry[j]= stod(args[pozycja]);
					pozycja++;					
			}
			if(parametry[0]== parametry[1] && parametry[1]== parametry[2] && parametry[2]== parametry[3] && parametry[4]==90)
			{
				try
				{
					Kwadrat* kwadrat= new Kwadrat(parametry[0]);
					cout<<"Obwod kwadratu: "<< kwadrat->obwod()<< "\n";
           			cout<<"Pole kwadratu: "<< kwadrat->pole()<< "\n";
           			delete kwadrat;
				}
				catch(string error)
				{
					cout<< args[pozycja] << error<< "\n";
					exit(0);
				}
				
			}
			else if(parametry[0]== parametry[1] && parametry[1]== parametry[2] && parametry[2]== parametry[3] && parametry[4]!=90)
			{
				try
				{
					Romb* romb= new Romb(parametry[0], parametry[4]);
					cout<<"Obwod Rombu: "<< romb->obwod()<< "\n";
           			cout<<"Pole Rombu: "<< romb->pole()<< "\n";
           			delete romb;
				}
				catch(string error)
				{
					cout<< args[pozycja]<< error<< "\n";
					exit(0);
				}
				
			}
			else if(parametry[0]== parametry[1] && parametry[2]== parametry[3] && parametry[4]==90)
			{
				try
				{
					Prostokat* prostokat= new Prostokat(parametry[0], parametry[2]);
					cout<<"Obwod Prostokatu: "<< prostokat->obwod()<< "\n";
           			cout<<"Pole Prostokatu: "<< prostokat->pole()<< "\n";
           			delete prostokat;
				}
				catch(string error)
				{
					cout<< args[pozycja] << error<< "\n";
				}
				
			}
			else
			{
				cout<< "nieprawidlowe dane czworokata\n";
			}
		}
		else if(kody_figur[i]== 'p')
		{
			try
			{
				Pieciokat* pieciokat= new Pieciokat(stod(args[pozycja]));
				pozycja++;
				cout<<"Obwod pieciokatu: "<< pieciokat->obwod()<< "\n";
				cout<<"Pole pieciokatu: "<< pieciokat->pole()<< "\n";
				delete pieciokat;
			}
			catch(string error)
			{
				cout<< args[pozycja] << error<< "\n";
				exit(0);
			}
			
		}
		else if(kody_figur[i]== 's')
		{
			try
			{
				Szesciokat* szesciokat= new Szesciokat(stod(args[pozycja]));
				pozycja++;
				cout<<"Obwod szesciokatu: "<< szesciokat->obwod()<< "\n";
				cout<<"Pole szesciokatu: "<< szesciokat->pole()<< "\n";
				delete szesciokat;
			}
			catch(string error)
			{
				cout<< args[pozycja] << error<< "\n";
				exit(0);
			}
			
		}
		else
		{
			cout<< "nieprawidlowy kod figury\n";
		}
	}
}
