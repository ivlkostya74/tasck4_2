
#include <iostream>
#include <cstring>
#include <fstream>
#include <windows.h>
#include <string>



class Adress {
private:
	std::string city_;
	std::string street_;
	int house_ = 0;
	int apartment_ = 0;
	std::string FullAdress_;
public:
	
	Adress();
	Adress(std::string city, std::string street, int house, int apartment)
	{
		city_ = city;
		street_ = street;
		house_ = house;
		apartment_ = apartment;

	};

	std::string Output_address() {
		FullAdress_ = city_ + ", " + street_ + ", " + std::to_string(house_)
			+ ", " + std::to_string(apartment_);
		return FullAdress_;
	}

	int getHose() { return house_; }
	int getApartment() { return apartment_; }
	std::string getCity() { return city_; }
	std::string getStreet() { return street_; }
};




//Adress* createTextArr(const int size)
//{
//	Adress* adr = nullptr;
//
//	return TextArr;
//}
//
//
//void deleteTextArr(std::string* TextArr, const int size)
//{
//	delete[] TextArr;
//	TextArr = nullptr;
//}

int main()
{
	/*setlocale(LC_ALL, "Russian");
	system("chcp 1251");*/
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	std::system("cls");
	std::cout << " открытие файла\n";
	std::ifstream fin("in.txt"); // открытие файла
	if (!fin.is_open()) {
		std::cout << "неудачное открытие файла\n";
		return 0;
	}
	int size = 0;//число карточек адресов
	fin >> size;
	std::cout << size << std::endl;
	std::string city;
	std::string street;
	int house;
	int apartment;

	
		Adress* adr = new Adress[size];
	
	//Adress *adr = new Adress (city, street, house,  apartment)[size];



	for (int i = 0; i < size; i++) {
		/*std::string city;
		std::string street;
		int house;
		int apartment;*/
		fin >> city >> street >> house >> apartment;
		Adress adress(city, street, house, apartment);
		adr[i] = adress;
		//std::cout << &adr[i];

		std::cout << city <<", " << street << ", " << house << ", " << apartment << std::endl;





	}
	std::ofstream fout("OUT.txt");

	//std::cout << adr[0].getCity().compare(adr[1].getCity());
	// 
	// 
	// сортировка
	if (adr)
	{
		bool cont;
		do
		{
			cont = false;
			Adress temp = adr[0];
			for (int i = 1; i < size; ++i)
			{
				if (adr[i].getCity() < temp.getCity())
				{
					adr[i - 1] = adr[i];
					adr[i] = temp;
					cont = true;
				}
				else temp = adr[i];
			}
		} while (cont);
	}

	if (fout.is_open())
	{
		if (adr)
		{
			fout << size << std::endl;
			for (int i = 0; i < size; i++)
			{
				//std::cout << adr[i].getCity() + ", " + adr[i].getStreet() + ", " + std::to_string(adr[i].getHose())
				//	+ ", " + std::to_string(adr[i].getApartment() )  << std::endl;
				
				fout << adr[i].getCity() + ", " + adr[i].getStreet() + ", " + std::to_string(adr[i].getHose())
					+ ", " + std::to_string(adr[i].getApartment() )  << std::endl;




			}
			std::cout << "файл записан " << std::endl;;
		}
		delete[] adr;
		//deleteTextArr(adr, size);
	}
}

Adress::Adress()
{
};
