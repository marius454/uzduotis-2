#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

int main()
{
	std::string vp;
	int n = 0, egz, a, max = 1;
	double galBalas;
	int* paz = new int[max];
	std::cout << "iveskite mokinio/studento varda ir pavarde: ";
	std::getline(std::cin, vp);

	std::cout << "iveskite visus namu darbu pazymius: " << std::endl;
	while (std::cin >> paz[n] && paz[n] != -1)
	{
		n++;
		if (n >= max)
		{
			max = max * 2;
			int* temp = new int[max];
			for (int i = 0; i < n; i++)
			{
				temp[i] = paz[i];
			}
			delete[] paz;
			paz = temp;
		}
	}
	std::cout << "iveskite mokinio/studento egzamino pazymi: ";
	std::cin >> egz;
	std::cout << std::endl;
	for (unsigned int i = 0; i < n; i++)
		for (unsigned int j = i; j < n; j++)
		{
			a = 0;
			if (paz[j] < paz[i])
			{
				a = paz[i];
				paz[i] = paz[j];
				paz[j] = a;
			}
		}
	if ((n - 1) % 2 != 0)
		galBalas = 0.4*paz[(n / 2) + 1] + 0.6*egz;
	else
	{
		double med = (paz[(n) / 2] + paz[(n) / 2 + 1]) / 2;
		galBalas = 0.4*med + 0.6*egz;
	}

	std::cout << "moknio/studento galutinis balas: " << std::fixed << std::setprecision(2) << galBalas << std::endl;
	return 0;
}
