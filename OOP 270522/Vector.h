#pragma once
#include <iostream>

template<typename type>
class Vector {
private:
	type* vector;
	size_t size;
	size_t capacity;

	void copyFrom(const Vector<type>& other);
	void free();
	void resize(size_t newCapacity);

public:
	Vector();
	Vector(const Vector<type>& other);
	Vector<type>& operator=(const Vector<type>& other);
	~Vector();
	Vector(type* vector, size_t size, size_t capacity);

	void pushBack(type element);
	void popBack();
	size_t getSize() const;
	size_t getCapacity() const;
	bool empty() const;
	const type& operator[](const size_t& position) const;
	type& operator[](const size_t& position);
};

template<typename type>
void Vector<type>::copyFrom(const Vector<type>& other) {
	size = other.size;
	capacity = other.capacity;
	vector = new type[capacity];
	for (size_t i = 0; i < size; i++) {
		vector[i] = other.vector[i];
	}
}

template<typename type>
void Vector<type>::free() {
	delete[] vector;
}

template<typename type>
Vector<type>::Vector() {
	size = 0;
	capacity = 1;
	vector = new type[capacity];
}

template<typename type>
Vector<type>::Vector(const Vector<type>& other) {
	copyFrom(other);
}

template<typename type>
Vector<type>& Vector<type>::operator=(const Vector<type>& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

template<typename type>
Vector<type>::~Vector() {
	free();
}

template<typename type>
void Vector<type>::resize(size_t newCapacity) {
	if (newCapacity <= capacity) {
		return
	}

	capacity = newCapacity;
	type* tempArr = new type[capacity];
	for (size_t i = 0; i < size; i++) {
		tempArr[i] = vector[i];
	}
	delete[] vector;

	vector = tempArr;
}

template<typename type>
void Vector<type>::pushBack(type element) {
	if (size + 1 >= capacity) {
		resize(capacity * 2);
	}
	vector[size] = element;
	size++;
}

template<typename type>
void Vector<type>::popBack() {
	if (size < 1) {
		std::cout << "There is nothing to delete!";
		return;
	}
	size--;
}

template<typename type>
size_t Vector<type>::getSize() const {
	return this->size;
}

template<typename type>
size_t Vector<type>::getCapacity() const {
	return this->capacity;
}

template<typename type>
bool Vector<type>::empty() const {
	return size == 0;
}

template<typename type>
const type& Vector<type>::operator[](const size_t& position) const {
	if (position > size - 1) {
		throw "Position inalid!";
	}
	return vector[position];
}

template<typename type>
type& Vector<type>::operator[](const size_t& position) {
	if (position > size - 1) {
		throw "Invalid position";
	}
	return vector[position];
}