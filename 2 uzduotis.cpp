#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

struct studentai
{
	std::string vardas, pavarde;
	std::vector<int> paz;
	unsigned short int egz;
	double vid;
	double med;
};

int main()
{
	unsigned int m, nd, nr;
	std::ifstream fd("kursiokai.txt");
	std::ofstream fr("rezultatai.txt");
	studentai stud[100];
	std::cout << "pasirinkite:" << std::endl;
	std::cout << "1) ivesti duomenis is klaviaturos" << std::endl;
	std::cout << "2) nuskaityti duomenys is failo (kursiokai.txt)" << std::endl;
	std::cin >> nr;
	if (nr == 1)
	{
		std::cout << "iveskite kiek bus vedama mokiniu: ";
		std::cin >> m;
		std::cout << "iveskite kiek bus vedama nd pazymiu: ";
		std::cin >> nd;
		for (unsigned int i = 0; i < m; i++)
		{
			std::cout << "iveskite " << i << "-ojo mokinio(es) pavarde: ";
			std::cin >> stud[i].pavarde;
			std::cout << "iveskite " << i << "-ojo mokinio(es) varda: ";
			std::cin >> stud[i].vardas;
			std::cout << "iveskite " << i << "-ojo mokinio(es) " << nd << " namu darbu pazymius:" << std::endl;
			for (unsigned int j = 0; j < nd; j++)
			{
				int a;
				std::cin >> a;
				stud[i].paz.push_back(a);
			}
			std::cout << "iveskite " << i << "-ojo mokinio egzamino bala: ";
			std::cin >> stud[i].egz;
		}
	}
	else
	{
		fd >> m >> nd;
		for (unsigned int i = 0; i < m; i++)
		{
			fd >> stud[i].pavarde;
			fd >> stud[i].vardas;
			for (unsigned int j = 0; j < nd; j++)
			{
				int a;
				fd >> a;
				stud[i].paz.push_back(a);
			}
			fd >> stud[i].egz;
		}
	}
	for (unsigned int i = 0; i < m; i++)
	{
		int sum = 0;
		for (unsigned int j = 0; j < nd; j++)
		{
			sum = sum + stud[i].paz.at(j);
		}
		stud[i].vid = 0.4*(sum / nd) + 0.6*stud[i].egz;

	}
	for (unsigned int i = 0; i < m; i++)

		std::sort(stud[i].paz.begin(), stud[i].paz.end());

	for (unsigned int i = 0; i < m; i++)
	{
		if ((nd) % 2 != 0)
			stud[i].med = 0.4*stud[i].paz[nd / 2] + 0.6*stud[i].egz;
		else
		{
			double med = (stud[i].paz[nd / 2 - 1] + stud[i].paz[nd / 2]) / 2;
			stud[i].med = 0.4*med + 0.6*stud[i].egz;
		}
	}
	for (unsigned int i = 0; i < m; i++)
		for (unsigned int j = i; j < m; j++)
		{
			studentai temp;
			if (stud[i].pavarde > stud[i].vardas)
			{
				temp = stud[i];
				stud[i] = stud[j];
				stud[j] = temp;
			}
		}
	fr << std::setw(20) << std::left << "Pavarde" << std::setw(20) << std::left << "Vardas" << std::setw(30) << "Galutinis-vidurkis" << "Galutinis-mediana" << std::endl;
	for (unsigned int i = 0; i < m; i++)
	{
		fr << std::setw(20) << std::left << stud[i].pavarde << std::setw(20) << std::left << stud[i].vardas << std::setw(30);
		fr << std::fixed << std::setprecision(2) << stud[i].vid << stud[i].med << std::endl;
	}
	fd.close();
	fr.close();
	return 0;
}
