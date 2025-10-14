#pragma once
#include <iostream>
#include <string>
namespace MyinputLib {

	int ReadPositiveNumber(){
		int Number;
		do {
			std::cout << "enter the positive number :\n";
			std::cin >> Number;
		} while (Number < 1 );
		return Number;
	}



}