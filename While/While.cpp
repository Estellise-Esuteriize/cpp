#include <iostream>


void WhileReturn(bool*);
void WhileBreak(bool*);

int main()
{
	
	bool* isOutside = new bool(false);

	/**
	|	While Return
	|	@param bool
	|		- when return is read, and outside of while is run it will return true else false
	|	
	|	check if using return does not run the ff codes in while.
	*/
	WhileReturn(isOutside);

	std::cout << "RETURN - is code after while is run " << std::boolalpha << *isOutside << std::endl;
	

	/**
	|	While Return
	|	END
	*/

	std::cout << "\n\n\n";

	/**
	| While Break
	|
	|	- check if codes after while is run when using break
	*/
	WhileBreak(isOutside);
	
	std::cout << "BREAK - is code after while is run " << std::boolalpha <<*isOutside << std::endl;
	/**
	| While Break
	| END
	*/
}


void WhileReturn(bool* outside) 
{

	int i = 0;

	while (i < 10)
	{
		i++;

		//std::cout << "Inside While, i value is " << i << std::endl;

		if (i == 5)
		{
			std::cout << "return if i value is 5, i value is " << i << std::endl;

			return;

		}

	}

	*outside = true;

	std::cout << "Outside of while, I value is " << i << std::endl;


}


void WhileBreak(bool* outside)
{
	int i = 0;

	while (i < 10)
	{
		i++;

		//std::cout << "Inside While, i value is " << i << std::endl;

		if (i == 5)
		{
			std::cout << "return if i value is 5, i value is " << i << std::endl;

			break;
		}

	}

	*outside = true;

	std::cout << "after of while, I value is " << i << std::endl;
}