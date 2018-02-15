#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
int main ()
{
    std::string vp;
    int n,egz,sum=0,a,b;
    double galBalas;
    std::cout<<"iveskite mokinio/studento varda ir pavarde: ";
    getline (std::cin,vp);
    std::cout<<"iveskite kiek pazymiu bus vedama: "; std::cin>>n;
    std::vector<int> paz;
    std::cout<<"iveskite visus "<<n<<" namu darbu pazymius: "<<std::endl;
    for (int i=0;i<n;i++)
    {
        std::cin>>b;
        paz.push_back(b);
    }
    std::cout<<"iveskite mokinio/studento egzamino pazymi: ";
    std::cin>>egz;
    std::cout<<std::endl;
    for (int i=0; i<n; i++)
        for (int j=i; j<n; j++)
        {
            a=0;
            if (paz.at(j)<paz.at(i))
                {
                    a=paz.at(i);
                    paz.at(i)=paz.at(j);
                    paz.at(j)=a;
                }
        }
    if (n%2!=0)
        galBalas=0.4*paz.at(n/2)+0.6*egz;
    else
    {
        double med=(paz.at(n/2-1)+paz.at(n/2))/2;
        galBalas=0.4*med+0.6*egz;
    }

    std::cout<<"moknio/studento galutinis balas: "<<std::fixed<<std::setprecision(2)<<galBalas;
    return 0;
}
