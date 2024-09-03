#include "knothpch.h"
#include "Log.h"

Knoth::Log::Log(std::string name){
	_name = name;
	_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
}

Knoth::Log::Log(){
	_name = "Generic Log";
	_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
}

Knoth::Log::~Log(){
}

void Knoth::Log::Print(std::string text, const char* file, int line){
	SetConsoleTextAttribute(_hConsole, (int)_selectedColor);
	std::cout << _name << " (" << file << ", " << line << ")" << ": " << text << std::endl;
}

void Knoth::Log::Print_Log(std::string text, const char* file, int line){
	SetConsoleTextAttribute(_hConsole, (int)ConsoleColor::GREEN);
	std::cout << _name << " (" << file << ", " << line << ")" << ": " << text << std::endl;
}

void Knoth::Log::Print_Info(std::string text, const char* file, int line){
	SetConsoleTextAttribute(_hConsole, (int)ConsoleColor::CYAN);
	std::cout << _name << " (" << file << ", " << line << ")" << ": " << text << std::endl;
}

void Knoth::Log::Print_Error(std::string text, const char* file, int line){
	SetConsoleTextAttribute(_hConsole, (int)ConsoleColor::RED);
	std::cout << _name << " (" << file << ", " << line << ")" << ": " << text << std::endl;
}
