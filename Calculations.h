#ifndef Calculations_H
#define Calculations_H
#include "Vector.h"
#include <cmath>

template <class T>
	/**
	 * @class Calculations
	 * @brief Used for calculating average and standard deviation
	 *
	 * Calculates and hold the average and standard deviation from a vector passed in
	 *
	 *
	 * @author Timothy Smith
	 * @version 01
	 * @date 20/04/2020, Timothy Smith, Beginning creation
	 *
	 *
	 *
	 * @todo Wait for next lab
	 *
	 * @bug No known bugs
	 */
class Calculations{

    public:

        /**
         * @brief  Default constructor
         *
         * Assign myAverage and myStdDev to 0
         *
         */

        Calculations();

        /**
         * @brief  Finds and returns average
         *
         * Takes in a vector by reference and finds the average
         *
         * @param Vector<T> - &myArr
         * @return T - myAverage
         */

        T average(Vector<T> &myArr);

        /**
         * @brief  Find and returns sample deviation
         *
         * Takes in an array and find the sample deviation of that aray
         *
         * @param Vector<T> - &myArr
         * @return T - myStdDev
         */

        T StdDev(Vector<T> &myArr);

    private:
            /// average of type T
        T myAverage;
            /// standard deviation of type T
        T myStdDev;

};

template <class T>
Calculations<T>::Calculations()
{
    myAverage = 0;
    myStdDev = 0;
}

template <class T>
T Calculations<T>::average(Vector<T> &myArr)
{
    if(myAverage == 0 && myArr.getLength() != 0){
        for(int i = 0; i <myArr.getLength(); i++){
            myAverage += myArr[i];
        }
        myAverage = myAverage/myArr.getLength();
        return myAverage;
    }
    else
        return myAverage;
}

template <class T>
T Calculations<T>::StdDev(Vector<T> &myArr)
{
    if(myAverage == 0){
        average(myArr);
    }

    for(int i = 0; i < myArr.getLength(); i++){
        myStdDev +=  (myArr[i]-myAverage)*(myArr[i]-myAverage);
    }
    return sqrt(myStdDev/(myArr.getLength()-1));
}
#endif // Valculations_H
