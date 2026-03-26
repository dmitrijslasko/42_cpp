#ifndef ARRAY_TPP
# define ARRAY_TPP

// Constructors
template <typename T>
Array<T>::Array() : _data(NULL), _size(0)
{}

template <typename T>
Array<T>::Array(unsigned int n) : _data(new T[n]), _size(n)
{}

template <typename T>
Array<T>::Array(Array const &copy) : _data(new T[copy._size]), _size(copy._size)
{
	for (unsigned int i = 0; i < _size; i++)
		_data[i] = copy._data[i];
}

template <typename T>
Array<T>::~Array()
{
	delete [] _data;
}

// Operators
template <typename T>
Array<T> &Array<T>::operator=(Array const &copy)
{
	if (this != &copy)
	{
		delete [] _data;
		_size = copy._size;
		_data = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			_data[i] = copy._data[i];
	}
	return (*this);
}

template <typename T>
T &Array<T>::operator[](unsigned int i)
{
	if (i >= _size)
		throw OutOfBoundsException();
	return (_data[i]);
}

template <typename T>
T const &Array<T>::operator[](unsigned int i) const
{
	if (i >= _size)
		throw OutOfBoundsException();
	return (_data[i]);
}

// Methods
template <typename T>
unsigned int Array<T>::size() const
{
	return (_size);
}

// Exceptions
template <typename T>
const char *Array<T>::OutOfBoundsException::what() const throw()
{
	return ("Index out of bounds");
}

#endif