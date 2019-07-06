#include <iostream>

using namespace std;


void PointPointers(int**);

int main()
{

	/**
		Pointers & Arrays;
	*/
	int arr[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
	int* pArr = arr;

	//
	// this array for below examples
	// array[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
	//
	// - pArr + 1 
	//		- output is the address of value 20 in the array
	//		- cout << pArr + 1 << " Value of array" << endl;
	cout << pArr + 1 << "Address in array index of" << endl;
	//		- output : 35352 ( address )
	// 
	// - *pArr + 1
	//		- output is the value of first address in an array + 1
	//		- cout << *(pArr + 1) << " Value of array " << endl;
	cout << *(pArr + 1) << " Value of array " << endl;
	//		- output : 21 
	//
	//
	// - pArr = &arr[2]
	pArr = &arr[2];
	//		- store the address of value from the array index n (in this case 2) to the pointer 
	//		- so, in the pointer the value 30 become the first index;
	//		- cout << *pArr << endl
	cout << *pArr << endl;
	//			- output : 30;
	//
	// - *(pArr - 1)
	//		- above code is the same as pArr[-1]
	//		- pArr pointer points to the address of n ( in this case 2 value of 30 );
	//		- the pArr pointer can retrieve the value of -1 ( 20 ) cause it exist from the array;
	//		- cout << *(pArr - 1) << endl;
	cout << *(pArr - 1) << endl;
	//			- output : 20
	//		- if somehow we retrieve an index not exist in array
	//		- value will be just random numbers or address
	//		- cout << *(pArr - 4) << endl;
	cout << *(pArr - 4) << endl;
	//			- output : 231415 ( random numbers )

	pArr = arr;
	int* pArr2 = pArr;

	pArr = &arr[2];

	*pArr2 = *pArr + 1 + arr[7];

	cout << "First pointer > " << *pArr << endl;
	cout << "Second pointer > " << *pArr2 << endl;
	/**/
	/**
		pointers & array 
		- END -
	*/


	/**
		void pointer
	*/

	void* pVoid = new int(2);
	//
	// void* pVoid = new int(2);
	//		- declare a void pointer that points to int
	// 
	//
	int* pInt = nullptr;
	//
	// int* pInt = nullptr;
	//		- declare an int pointer
	//
	pInt = static_cast<int*>(pVoid);
	//
	// pInt = static_cast<int*>(pVoid);
	//		- cast int pointer to void pointer an assign it to int pointer
	//
	cout << *pInt << endl;
	//
	// cout << *pInt << endl;
	//		- output : 2

	//
	// cout << *pVoid << endl;
	//		- if accessing the value of the void pointer without casting it to it's type
	//		- output error read exception
	//		- output : Exception occured
	//
	/**
		void pointer
		- END -
	*/


	//
	//	Dynamic memory allocation heap
	//	- START -
	//
	//		- dynamic memory allocation happens when using
	//		- new : operator
	//		- ex. new int[2]; create new int with an array of 2
	//		-	  new int(3); create new int with a value of 3
	//		- when deleting a memory allocated
	//		- delete : operator
	//		- ex. delete pointer; delete the allocated memory this pointer points to;
	//		-	  delete[] pointer; delete a pointer that points to array;
	//
	int* pOint = nullptr;

	PointPointers(&pOint);

	cout << *pOint << endl;

	//
	// - END -
	//

}


// 
// Dynamic memory allocation heap
// 
void PointPointers(int** p)
{
	// allocate new memory of int with a value of 30
	// assign "a" pointer variable to new allocated memory
	int* a = new int(30);

	// assign the address of p
	// to the same as a;
	*p = a;

}
//
// - END -
//