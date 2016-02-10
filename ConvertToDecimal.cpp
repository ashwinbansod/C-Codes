/*
 *  Description: Convert roman number to decimal
 */ 
#include <iostream>
using namespace std;



float convertToDecimal(string roman)
{
    float decimal = 0;
	for (int i = 0; i < roman.size(); i++ )  //you could use roman.length() if you like
	{
		switch (roman[i]) //roman.at(i) is just a more secure way to do it
		{
			case 'M': decimal += 1000; break;
			case 'D': decimal += 500; break;
			case 'C': decimal += 100; break;
			case 'L': decimal += 50; break;
			case 'X': decimal += 10; break;
			case 'V': decimal += 5; break;
			case 'I':
				if (roman[i + 1] != 'I' && i + 1 != roman.size())
					decimal -= 1;
				else
					decimal += 1;
				break;
		}
	}
	return decimal;
}

int main()
{
    string str;
    cout << "Enter the roman string:" ;
    cin >> str;
    
    cout << "Decimal value is " << convertToDecimal(str) <<  endl;
    return 0;
}
