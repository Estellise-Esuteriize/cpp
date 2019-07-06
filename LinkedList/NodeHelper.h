#pragma once

#include <iostream>
#include <type_traits>

using namespace std;

class NodeHelper
{

	//template <typename... Ts> using void_t = void;

	//template <typename T>
	//struct has_typedef_foobar<T, void_t<typename T::intData>> : std::true_type {};
	
	template <typename T, typename = void>
	struct exists : false_type {};

	template <typename T>
	struct exists<T, decltype(declval<T>().data, void())> : true_type {};
	
	template <typename T>
	struct exists<T, decltype(declval<T>().next, void())> : true_type {};

	template <typename T>
	struct exists<T, decltype(declval<T>().back, void())> : true_type {};


	public:
		template <typename T, typename D>
		void push(T** head, D data);


};

