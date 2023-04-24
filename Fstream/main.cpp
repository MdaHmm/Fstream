#include <iostream>
#include <fstream>
#include <string>

// Кодировка UTF-8

bool print_file(std::string file_path) {
	static std::ifstream in;
	in.open(file_path);

	if (in.is_open()) {
		char sym;
		while (in.get(sym))
			std::cout << sym;
		std::cout << std::endl;
		in.close();
		return true;
	}

	in.close();
	return false;
}

bool insert_file(std::string file_path, std::string str, int position);

int main() {
	setlocale(LC_ALL, "Russian");
	int n;

	//std::string path = "file.txt";
	
	// Класс fstream
	/*
	std::fstream file; // объект класса fstream, позволяющий одновременно записывать и считывать данные из файла
	file.open(path, std::ios::in | std::ios::app); // открытие файла с режимами in и app

	if (file.is_open()) {
		std::cout << "Файл открыт.\n";
		// Добавление записи в файл
		
		// seekg - seek get pointer - что-то считать 
		// seekp - seek put pointer - что-то вписать
		
		// ios::beg - начало файла
		// ios::end - конец файла
		// ios::cur - текущее положение


		std::cout << "Запись в файл.\nВведите строку -> ";
		std::string str;
		std::getline(std::cin, str);
		file << str << "\n";
		std::cout << "Запись добавлена в файл.\n";
		
		file.seekg(0, std::ios::beg); // перемещение курсора для считывания данных в начало файла

		// Чтение записи из файла
		std::cout << "Содержимое файла:\n";
		char sym;
		while (file.get(sym))
			std::cout << sym;
	}
	else
		std::cout << "Ошибка открытия файла.\n";


	file.close();
	*/

	// Задача "Ввод в позицию файла"
	/*
	std::cout << "Содержимое файла:\n";
	print_file(path);

	std::cout << "Введите строку -> ";
	std::string substr;
	std::getline(std::cin, substr);

	std::cout << "Введите позицию -> ";
	std::cin >> n;
	std::cin.ignore();

	if (insert_file(path, substr, n)) {
		std::cout << "Вставка выполнена успешно\n";
		std::cout << "Итоговое содержимое файла:\n";
		print_file(path);
		std::cout << std::endl;
	}
	else
		std::cout << "Ошибка выполнения функции.\n";
		*/

	// Задача "Дата из файла"

	std::string date_path = "date.txt";
	std::cout << "Содержимое файла:\n";
	print_file(date_path);

	std::ifstream file;
	std::string text;

	file.open(date_path);
	if (file.is_open()) {
		std::cout << "Файл открыт для считывания.\n";

		char sym;
		while (file.get(sym))
			text += sym;
		std::cout << text;
	}
	else
		std::cout << "Ошибка открытия файла.\n";
	

	file.close();


	return 0;
}

bool insert_file(std::string file_path, std::string str, int position) {
	std::string file_text;

	std::fstream file;
	file.open(file_path, std::ios::in);
	if (file.is_open()) {
		char sym;
		while (file.get(sym))
			file_text += sym;
	}
	else {
		file.close();
		return false;
	}
	file.close();

	file_text.insert(position, str);

	file.open(file_path, std::ios::out);
	if (file.is_open()) {
		file << file_text;
		file.close();
		return true;
	}
	file.close();
	return false;
}

