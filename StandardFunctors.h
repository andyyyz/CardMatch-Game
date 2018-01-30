#pragma once

class IsLess {
public:
	template<class T>
	static bool compare(const T& a, const T& b) {
		return a < b;
	}
};



class IsGreater {
public:
	template<class T>
	static bool compare(const T& a, const T&b) {
		return a > b;
	}
};

class IsLessDeref {
public:
	template<class T>
	static bool compare(const T& a, const T& b) {
		if (a == NULL) {
			return false;
		}
		else if (b == NULL) {
			return true;
		}
		else {
			return *a < *b;
		}
	}
};

class IsGreaterDeref {
public:
	template<class T>
	static bool compare(const T& a, const T& b) {
		if (b == NULL) {
			return false;
		}
		else if (a == NULL) {
			return true;
		}
		else return *a < *b;
	}
};

class IsEqual {
public:
	template<class T>
	static bool compare(const T &a, const T& b) {
		return a == b;
	}
};

class IsEqualDeref {
public:
	template<class T>
	static bool compare(const T& a, const T& b) {
		if (a == NULL || b == NULL) {
			return false;
		}
		else {
			return (*a) == (*b);
		}
	}
};