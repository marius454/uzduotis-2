#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <random>
int main()
{
	std::string vp;
	int n = 9, egz, a, b = 0;
	double galBalas;
	std::vector<int> paz;
	std::cout << "iveskite mokinio/studento varda ir pavarde: ";
	getline(std::cin, vp);

	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(0, 10);
	for (int i = 0; i<n; i++)
	{
		std::cout << dist(mt) << " ";
		paz.push_back(dist(mt));
	}
	std::cout << std::endl;

	std::cout << "iveskite mokinio/studento egzamino pazymi: ";
	std::cin >> egz;
	std::cout << std::endl;
	for (unsigned int i = 0; i<paz.size(); i++)
		for (unsigned int j = i; j<paz.size(); j++)
		{
			a = 0;
			if (paz.at(j)<paz.at(i))
			{
				a = paz.at(i);
				paz.at(i) = paz.at(j);
				paz.at(j) = a;
			}
		}
	if ((paz.size() - 1) % 2 != 0)
		galBalas = 0.4*paz.at((paz.size()) / 2) + 0.6*egz;
	else
	{
		double med = (paz.at((paz.size()) / 2 - 1) + paz.at((paz.size()) / 2)) / 2;
		galBalas = 0.4*med + 0.6*egz;
	}

	std::cout << "moknio/studento galutinis balas: " << std::fixed << std::setprecision(2) << galBalas << std::endl;
	return 0;
}

