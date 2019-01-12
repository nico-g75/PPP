#include "std_lib_facilities.h"

//1) Define template<typename T> struct S { T val; };
//2. Add a constructor, so that you can initialize with a T.
//5. Add a function template get() that returns a reference to val.
//6. Put the definition of get() outside the class.
//7. Make val private.
//9. Add a set() function template so that you can change val.
//10. Replace set() with an S<T>::operator=(const T&). Hint: Much simpler than §19.2.5.
//11. Provide const and non - const versions of get().
//12. Define a function template<typename T> read_val(T& v) that reads from cin into v.
//13. Use read_val() to read into each of the variables from 3 except the S<vector<int>> variable.
//14. Bonus: Define input and output operators (>> and <<) for vector<T>s.
//For both input and output use a { val, val, val } format. That will allow read_val() to also handle the S<vector<int>> variable.
template<typename T>
struct S {

	S(T v): val{v}{}	//constructor
	T& get();
	const T& get() const;
	void set(const T& v);
	T& operator=(const T& v);
	void read_val(T& v);

private:
	T val;
};

template<typename T>
T& S<T>::get() {return val;}

template<typename T>
const T& S<T>::get() const { return val; }

template<typename T>
void S<T>::set(const T& v) { val = v; }

template<typename T>
T& S<T>::operator=(const T& v) {
	val = v;
	return this;
}

template<typename T>
void S<T>::read_val(T& v) {
	cin >> v;
	val = v;
}

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	os << "{ ";
	for (int i = 0; i < v.size(); ++i) {
		os << v[i];
		if (i < v.size() - 1) os << ", ";
	}
	os << " }";

	return os;
}

template<typename T>
istream& operator>>(istream& is, vector<T>& v) {
	T x;
	char ch1, ch2;
	is >> ch1;
	
	if (ch1 != '{') {
		is.unget();
		is.clear(ios::failbit);
		return is;
	}

	while (is >> x >> ch2 && ch2 == ',') {		//read elements + ','
		v.push_back(x);
	}

	if (ch2 != '}') {
		is.unget();
		is.clear(ios::failbit);
		return is;
	}

	v.push_back(x); //read last element

	return is;

}
