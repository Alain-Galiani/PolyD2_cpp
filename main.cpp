// Polynôme de degré 2
// Par Alain Galiani
// Langage C++
// OS Gnu Linux Xubuntu 22.04.4 LTS

#include <iostream>
#include <cmath>
#include <limits>
#include <string>

class POLYNOME2
{
  public:

    POLYNOME2(double A, double B, double C);
    ~POLYNOME2();

    void manuel();
    int choix();
    double delta();
    double racines();
    
  private:
  
    int debug,nb_erreur;
    int cc;
    double a,b,c,dis,x1,x2,rd,aa;    
};

POLYNOME2::POLYNOME2(double A, double B, double C)
{
  std::cout<<"Constructeur d'objet de class POLYNOME2"<<std::endl;
  a=A;
  if(a==0) a++;
  b=B;
  c=C; 
}

POLYNOME2::~POLYNOME2()
{
  std::cout<<"Destructeur d'objet de class POLYNOME2"<<std::endl;
}

void POLYNOME2::manuel()
{
  std::cout<<"*** Affiche le manuel ***"<<std::endl;
}

int POLYNOME2::choix()
{
  int erreur;
  nb_erreur=0;

  std::cout<<"\n";
  std::cout<<"**********************************************************"<<std::endl
           <<"*** Entrez les valeurs a, b, c du polynome avec a!=0 : ***"<<std::endl
           <<"**********************************************************"<<std::endl;

  do
  {
    erreur=0;
    std::cout<<"\n\t Pour le polynome ax²+bx+c , entrez la valeur non nul a = ";
    std::cin>>a;

    if(std::cin.good())
    {
      if(a!=0.0)
      {
        erreur=0;
      }
      else
      {
        std::cout<<"\n\n\t*** Attention la valeur 'a' du polynome 'ax²+bx+c' ne doit pas être nul , a!=0 *** \n\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        erreur=1;
        nb_erreur++;
      }
    }
    else
    {
      std::cout<<"\n\n\t*** Attention la valeur 'a' du polynome 'ax²+bx+c' doit être un chiffre, et non nul *** \n\n";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      erreur=1;
      nb_erreur++;
    }
  } while (erreur);

  std::cout<<"\n\t\t"<<a<<" x²+bx+c"<<std::endl;

  do
  {
    erreur=0;
    std::cout<<"\n\t Pour le polynome ax²+bx+c , entrez la valeur b = ";
    std::cin>>b;

    if(std::cin.good())
    {
      erreur=0;
    }
    else
    {
      std::cout<<"\n\n\t*** Attention la valeur 'b' du polynome 'ax²+bx+c' doit être un chiffre *** \n\n";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      erreur=1;
      nb_erreur++;
    }
  } while (erreur);

  std::cout<<"\n\t\t"<<a<<" x²+ "<<b<<" x+c"<<std::endl;

  do
  {
    erreur=0;
    std::cout<<"\n\t Pour le polynome ax²+bx+c , entrez la valeur c = ";
    std::cin>>c;

    if(std::cin.good())
    {
      erreur=0;
    }
    else
    {
      std::cout<<"\n\n\t*** Attention la valeur 'c' du polynome 'ax²+bx+c' doit être un chiffre *** \n\n";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      erreur=1;
      nb_erreur++;
    }
  } while (erreur);

  std::cout<<"\n\t\t"<<a<<" x²+ "<<b<<" x+ "<<c<<std::endl;

  std::cout<<"\n"
           <<"**********************************************************"<<std::endl
           <<"\n";

  return nb_erreur;
}   

double POLYNOME2::delta()
{
  std::cout<<"\n*************************************************************************\n"
             <<"*** Calcul de delta pour le polynome : "<<a<<" x²+ "<<b<<" x+ "<<c<<"               ***\n"
             <<"*************************************************************************\n";

  dis=b*b-(4*a*c);
  std::cout<<"\n\tDelta est égale à : "<<dis<<std::endl;
  std::cout<<"\n**************************************************************************\n\n";

  return dis;
}

double POLYNOME2::racines()
{
  std::cout<<"\n**********************************************************************************\n"
             <<"*** Calcul les racines éventuelles du polynome : "<<a<<" x²+ "<<b<<" x+ "<<c<<"                ***\n"
             <<"**********************************************************************************\n";

  dis=b*b-(4*a*c);

  if(dis>0)  
  {
    std::cout<<"\n*** Delta est > 0 donc on calcul les deux racines x1 et x2 ***\n";
    rd=sqrt(dis);
    aa=2*a;
    x1=(-b-rd)/aa;
    x2=(-b+rd)/aa;
    std::cout<<"\n\t Les racines du polynome sont x1 = "<<x1<<"   et x2 = "<<x2<<std::endl;
  }
  else if(dis==0.0)
  {
    std::cout<<"\n*** Delta est = 0 donc on calcul la racine x1 ***\n";
    aa=2*a;
    x1=-b/aa;
    std::cout<<"\n\t La racine du polynome x1 = "<<x1<<std::endl;
  }
  else
  {
    std::cout<<"\n*** Delta est < 0 donc il n'y a pas de solution dans R ***\n";
  }

  return 0.0;
}

int main()
{
  POLYNOME2 PolynomeD2(1.0,2.0,-3.0);

  int nb_erreur=0;

  PolynomeD2.manuel();

  nb_erreur=PolynomeD2.choix();
  std::cout<<"Le nombre d'erreur de saisie est égale à : "<<nb_erreur<<std::endl;
  PolynomeD2.delta();
  PolynomeD2.racines();

  std::cout<<"int "<<sizeof(int)<<std::endl<<
             "long int "<<sizeof(long int)<<std::endl<<
             "long long int "<<sizeof(long long int)<<std::endl;

  std::cout<<"Hello World !\n";

  return 0;
}