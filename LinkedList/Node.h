#pragma once
#include <iostream>

using namespace std;


class Node
{

	//
	template <typename T, typename = void>
	struct has : false_type {};
	//
	template <typename T>
	struct has <T, decltype(declval<T>().next, void())> : true_type {};


	template <typename T, class = typename enable_if<has<T>::value, T>::type>
	void pushingNext(T** head, T* newData, bool& isLost) 
	{
		if ((*head) == nullptr) 
		{
			newData->next = nullptr;
		}

		(*head) = newData;

		isLost = false;
	}

	void pushingNext(...) {  };



	public:
		template<typename T, typename C>
		void push(T** head, C data) 
		{
			bool isLost = true;

			T* newData = new T();

			newData->data = data;

			newData->next = nullptr;

			pushingNext(head, newData);

			if (isLost)
			{
				delete newData;
			}

		}


};

