#include <iostream>
#include <cmath>
#include <iomanip>

int main ()
{
    std::string vp;
    int n=5,paz[100],egz,sum=0;
    double galBalas;
    std::cout<<"iveskite mokinio/studento varda ir pavarde: ";
    getline (std::cin,vp);
    std::cout<<"iveskite visus "<<n<<" namu darbu pazymius: "<<std::endl;
    for (int i=0;i<n;i++)
    {
        std::cin>>paz[i];
    }
    std::cout<<"iveskite mokinio/studento egzamino pazymi: ";
    std::cin>>egz;
    for (int i=0; i<n; i++)
    {
        sum+=paz[i];
    }
    galBalas=0.4*(sum/n)+0.6*egz;
    std::cout<<"moknio/studento galutinis balas: "<<std::fixed<<std::setprecision(2)<<galBalas;
    return 0;
}
