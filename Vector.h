#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <vector>
using namespace std;
template <class T>

	/**
	 * @class Vector
	 * @brief Stores a dynamic array of any type
	 *
	 * Allows the user to place and extract elements in the array, which self expands
	 *
	 *
	 * @author Timothy Smith
	 * @version 01
	 * @date 22/04/2020, Timothy Smith, Begin class
	 *
	 *
	 * @todo Wait for next lab
	 *
	 * @bug No known bugs
	 */

class Vector
{
	public:

        /**
         * @brief  Overloads the [] operator
         *
         * Returns the value and the index passed in non cost version
         *
         * @param int - i
         * @return T&
         */

	    T& operator[](int i); //overload [] setter

        /**
         * @brief  Overloads the [] operator
         *
         * Returns the value and the index passed in cost version
         *
         * @param int - i
         * @return T&
         */


        T& operator[](int i) const; //cost overload [] getter

        /**
         * @brief  Default constructor for vector
         *
         * Pass in the integer to set the size of dynamic array, if nothing passed in default to 100
         *
         */

	    Vector(int i = 100);

        /**
         * @brief  Destructor for vector
         *
         * Destroys the vector when deleted
         *
         */

        ~Vector();

        /**
         * @brief  Returns length of array
         *
         * Returns listLength which is the current list length
         *
         * @param int - listLength
         */

	    int getLength() const;

        /**
         * @brief  Puts a new value into array
         *
         * Puts in a value at the element given
         *
         * @param void
         */

	    void insertValueAt(const int i, const T& myValue);

        /**
         * @brief  Copy constructor for vector
         *
         * Allows for a deep copy when called, makes use of the copy method
         *
         * @param Vector - &arr
         */

        Vector(const vector<T> &arr);

        void Insert(const T& myValue);


	private:

        /**
         * @brief  Overload = operator
         *
         * Overload the assignment operator used for making a deep copy
         *
         * @param Vector - &myArr
         * @return bool
         */

	    T& operator =(const vector<T> &myArr);

        /**
         * @brief  Used to expand the maxListLength
         *
         * When this is called, expand and copy all elements into a new dynamic array
         *
         * @param Vector - &myArr
         * @return T& - this
         */

        void expandMaxList();

            /// myList is a dynamic array used to store values of type T
		//T * myList;

		vector<T> myVector;

            /// The current size of the array
		//int listLength; //size

            /// The current capacity of the array
		//int maxListLength; //(capacity) Client will never see this value
};


template <class T>
T& Vector<T>::operator =(const vector<T> &myArr)
{
    myVector.clear();
    myVector = myArr;


    return *this;
}

template <class T>
Vector<T>::Vector(const vector<T> &arr)
{

    myVector.clear();
    vector<T> myVector(arr);

}

template <class T>
T& Vector<T>::operator[](int i)
{
    if(i > myVector.size() || i < 0){
        throw std::out_of_range("index out of rangee");
    }else
        return myVector[i];
}

template <class T>
T& Vector<T>::operator[](int i) const
{
    if(i > myVector.size() || i < 0){
        throw std::out_of_range("index out of rangee");
    }else
        return myVector[i];

}

template <class T>
Vector<T>::Vector(int i)
{
    if (i <= 0)
    {
        myVector.reserve(100);

    }
    else
        myVector.reserve(i);
} //end constructor

template <class T>
void Vector<T>::expandMaxList()
{
    myVector.reserve(myVector.capacity()*2);
}

template <class T>
int Vector<T>::getLength() const
{
    return myVector.size();
}

template <class T>
void Vector<T>::insertValueAt(const int i, const T& myValue)
{
    if(getLength() == myVector.capacity()){
        expandMaxList();
    }

    myVector.insert(myVector.begin()+i, myValue);

}

template <class T>
void Vector<T>::Insert(const T& myValue)
{
    myVector.push_back(myValue);
}

template <class T>
Vector<T>::~Vector()
{
    myVector.clear();
}

#endif

