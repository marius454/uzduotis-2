#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
int main ()
{
    std::string vp;
    int n,egz,a,b=0;
    double galBalas;
    std::vector<int> paz;
    std::cout<<"iveskite mokinio/studento varda ir pavarde: ";
    getline (std::cin,vp);

    std::cout<<"iveskite visus namu darbu pazymius: "<<std::endl;
    while (b!=-1)
    {
        std::cin>>b;
        paz.push_back(b);
    }
    std::cout<<"iveskite mokinio/studento egzamino pazymi: ";
    std::cin>>egz;
    std::cout<<std::endl;
    for (unsigned int i=0; i<paz.size()-1; i++)
        for (unsigned int j=i; j<paz.size()-1; j++)
        {
            a=0;
            if (paz.at(j)<paz.at(i))
                {
                    a=paz.at(i);
                    paz.at(i)=paz.at(j);
                    paz.at(j)=a;
                }
        }
    if ((paz.size()-1)%2!=0)
        galBalas=0.4*paz.at((paz.size()-1)/2)+0.6*egz;
    else
    {
        double med=(paz.at((paz.size()-1)/2-1)+paz.at((paz.size()-1)/2))/2;
        galBalas=0.4*med+0.6*egz;
    }

    std::cout<<"moknio/studento galutinis balas: "<<std::fixed<<std::setprecision(2)<<galBalas;
    return 0;
}
