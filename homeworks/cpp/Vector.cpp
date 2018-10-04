#include "Vector.h"
#include <cmath>

using std::shared_ptr;
using std::make_shared;

bool Vector::isSmallObject() const { //done
	return sizeOfObject <= 1;
}

void Vector::unique_checker() { //done
	if (!big.unique()) {
		big = make_shared<std::vector<uint32_t>>(*big);
	}
}

Vector::Vector() { //done
	sizeOfObject = 1;
	small = 0;
}

Vector::~Vector() { //done
	if (!isSmallObject()) {
		big.reset();
	}
}

size_t Vector::size() const { //done
	return sizeOfObject;
}

bool Vector::isEmpty() const { //done
	return (sizeOfObject == 0);
}

void Vector::pushBack(uint32_t val) { //done
	if (isEmpty()) {
		small = val;
	} else if (isSmallObject()) {
		new(&big) shared_ptr<std::vector<uint32_t>>(new std::vector<uint32_t>(1, small));
		big->push_back(val);
	} else {
	unique_checker();
		big->push_back(val);
	}
	++sizeOfObject;
}

void Vector::popBack() {  //done
	if (isSmallObject()) {
		small = 0;
	} else if (sizeOfObject > 2) {
		unique_checker();
		big->pop_back();
	} else {
		uint32_t tmp = big->operator[](0);
		big.reset();
		small = tmp;
	}
	--sizeOfObject;
}

void Vector::resize(size_t num_of_elements) { //done
	if (isSmallObject() && num_of_elements > 1) {
		new(&big) shared_ptr<std::vector<uint32_t>>(new std::vector<uint32_t>(num_of_elements, small));
	} else if (!isSmallObject()) {
		if (num_of_elements <= 1) {
			uint32_t tmp = operator[](0);
		big.reset();
		small = tmp;
		}
		else {
			unique_checker();
			big->resize(num_of_elements);
		}
	}
	sizeOfObject = num_of_elements;
}

void Vector::clear() { //done
	isSmallObject() ? small = 0 : big.reset();
	sizeOfObject = 0;
}

Vector &Vector::operator=(Vector const &x) { //done
	if (!isSmallObject()) {
		big.reset();
	}
	if (!x.isSmallObject()) {
		new(&big) shared_ptr<std::vector<uint32_t>>(x.big);
	}
	else {
		small = x.small;
	}
	sizeOfObject = x.sizeOfObject;
	return *this;
}

uint32_t &Vector::operator[](size_t id) { //done
	if (isSmallObject()) {
		return small;
	}
	unique_checker();
	return big->operator[](id);
}

uint32_t Vector::operator[](size_t id) const { //done
	if (isSmallObject()) {
		return small;
	}
	return big->operator[](id);
}

bool operator==(Vector const &first, Vector const &second) { //done
	if (first.isSmallObject() ^ second.isSmallObject()) {
		return false;
	}
	else if (first.isSmallObject()) {
		return first.small == second.small;
	}
	return *first.big == *second.big;
}
