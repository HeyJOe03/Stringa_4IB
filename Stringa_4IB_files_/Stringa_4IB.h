#pragma once
#include <iostream>
#include <vector>
#include <string>

class Stringa_4IB
{
	private:
		char* lettere;
		int n = 69;

	public:

		Stringa_4IB();
		Stringa_4IB(const char*);
		Stringa_4IB(char[]);
		Stringa_4IB(char);
		Stringa_4IB(int, const char[]);
		//~Stringa_4IB();

		int length();

		char operator[](int pos);

		Stringa_4IB operator+(const char[]);
		Stringa_4IB operator+(char[]);
		Stringa_4IB operator+(Stringa_4IB);
		void operator +=(char[]);
		void operator +=(const char[]);
		void operator +=(Stringa_4IB);

		bool operator>(Stringa_4IB);
		bool operator<(Stringa_4IB);
		bool operator>=(Stringa_4IB);
		bool operator<=(Stringa_4IB);
		bool operator==(Stringa_4IB);
		bool operator!=(Stringa_4IB);

		Stringa_4IB substring(int, int);
		Stringa_4IB substring(int);

		int find(Stringa_4IB, int);
		int find(char, int);
		int find(Stringa_4IB);
		int find(char);

		Stringa_4IB insert(char stringa_da_inserire[], int pos);
		Stringa_4IB insert(const char* stringa_da_inserire, int pos);
		Stringa_4IB insert(Stringa_4IB stringa_da_inserire, int pos);
		Stringa_4IB insert(char car, int pos);

		std::vector<Stringa_4IB>* split();
		std::vector<Stringa_4IB>* split(char);

		friend std::istream& operator>> (std::istream& file, Stringa_4IB &a) {
			std::string input; //utilizzo una stringa per rendere dinamico l'input
			file >> input;
			///std::cout << input<< std::endl;
			a.lettere = new char[int(input.size())+1];
			///for (int i = 0; '\0' != input[i]; i++) std::cout << int(input[i]) << std::endl;
			for (int i = 0; i <= input.size(); i++) {
				*(a.lettere + i) = input[i];
			}
			return file;
		}
		friend std::ostream& operator<<(std::ostream& out, Stringa_4IB& a) {
			char* i = NULL;
			if (a.lettere == NULL) return out << '\0';
			for (i = a.lettere; *i != '\0'; i++) {
				out << *i;
			}
			out << *i; // cout '\0'
			return out;
		}
};

