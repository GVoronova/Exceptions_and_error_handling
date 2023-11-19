#include <iostream>
#include <string>
#include <io.h>
#include <fcntl.h>
#include <exception>




int function(std::wstring str, int forbidden_length) {

	std::string bad_leghth {"You have entered a word of forbidden length! Goodbye"};

	if (str.length() == forbidden_length) {
		throw std::invalid_argument (bad_leghth);
	}
	return str.length();

}
	
	int wmain(int argc, char** argv) {

		_setmode(_fileno(stdout), _O_U16TEXT);
		_setmode(_fileno(stdin), _O_U16TEXT);
		_setmode(_fileno(stderr), _O_U16TEXT);

		//setlocale(LC_ALL, "Russian");

		std::wstring str;
		int forbidden_length;
		

			std::wcout << L"Введите запретную длину: ";
			std::wcin >> forbidden_length;

		while (true) {
			std::wcout << L"Введите слово: ";
			std::wcin >> str;
		
			try {

				function(str, forbidden_length);
				std::wcout << L"Длина слова " << char(34) << str << char(34) << L" равна " << function(str, forbidden_length) << std::endl;
			}
			catch (const std::invalid_argument& ex) {
				std::wcout << ex.what() << std::endl;
				break;
			}
			catch (...) {
				std::wcout << L"Неизветсная ошибка" << std::endl;
				break;
			}

		}
		return 0;
	}

	
	