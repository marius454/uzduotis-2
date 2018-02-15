#include <iostream>
#include <cmath>
#include <iomanip>

int main ()
{
    std::string vp;
    int n,egz,sum=0,a;
    double galBalas;
    std::cout<<"iveskite mokinio/studento varda ir pavarde: ";
    getline (std::cin,vp);
    std::cout<<"iveskite kiek pazymiu bus vedama: "; std::cin>>n;
    int paz[n];
    std::cout<<"iveskite visus "<<n<<" namu darbu pazymius: "<<std::endl;
    for (int i=0;i<n;i++)
    {
        std::cin>>paz[i];
    }
    std::cout<<"iveskite mokinio/studento egzamino pazymi: ";
    std::cin>>egz;
    std::cout<<std::endl;
    for (int i=0; i<n; i++)
        for (int j=i; j<n; j++)
        {
            a=0;
            if (paz[j]<paz[i])
                {
                    a=paz[i];
                    paz[i]=paz[j];
                    paz[j]=a;
                }
        }
    if (n%2!=0)
        galBalas=0.4*paz[n/2]+0.6*egz;
    else
    {
        double med=(paz[n/2-1]+paz[n/2])/2;
        galBalas=0.4*med+0.6*egz;
    }

    std::cout<<"moknio/studento galutinis balas: "<<std::fixed<<std::setprecision(2)<<galBalas;
    return 0;
}
