#ifndef SORTINGWEATHERDATA_H
#define SORTINGWEATHERDATA_H
#include "BSTCallbacks.h"

	/**
	 * @class SortingWeatherData
	 * @brief Find the weather data given a month and year
	 *
	 * Insert, Hold, and searches through weather data to for a given year or year and month
	 *
	 *
	 * @author Timothy Smith
	 * @version 01
	 * @date 20/04/2020, Timothy Smith, Beginning creation
	 * @date 11/06/2020, Timothy Smith Finish modification to cater for BST
	 *
	 *
	 * @todo
	 *
	 * @bug No known bugs
	 */

class SortingWeatherData
{
    public:

        /**
         * @brief  Default constructor for sorting weather data
         *
         * Default constructor
         *
         */

        SortingWeatherData();

        /**
         * @brief  Adds data the the vector stored in here
         *
         * Pass in a windLogType and store in vector
         *
         * @param const int - i, WindLogType - log
         * @return void
         */

        void addDataAt(WindLogType log);

        /**
         * @brief  Searches the data and returns vector at the month and year given
         *
         * Searches the data
         *
         * @param const unsigned - aMonth, const unsigned - aYear
         * @return Vector<WindLogType> - tempVector
         */

        Vector<WindLogType> getMonthOfYear(const unsigned aMonth, const unsigned aYear);

        /**
         * @brief  Searches the data and returns vector at the year given
         *
         * Searches the data for information
         *
         * @param const unsigned - aYear
         * @return Vector<WindLogType> - tempVector
         */

        Vector<WindLogType> getByYear(const unsigned aYear);

    protected:

    private:
            ///Holds a vector of type WindLogType
        Vector<WindLogType> data;
            /// BST that hold a StoreYearData, this is sorted by year
        BST<StoreYearData> myBST;
            /// Object of StoreYearData, which is used to hold data for each Year.
        StoreYearData myMaps;
            /// Current year we are using
        int currentYear;
            /// CallBacks used to get and put data into the BST
        BSTCallbacks myCallBacks;
};

#endif // SORTINGWEATHERDATA_H
