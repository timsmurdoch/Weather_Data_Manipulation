#ifndef StoreYearData_H
#define StoreYearData_H
#include <map>
#include "WindLogType.h"
#include "Vector.h"

	/**
	 * @class StoreYearData
	 * @brief Holds a map, this map is for a year
	 *
	 * Allows a map to be inserted into with WindLogType data and then extracted from at a certain year and month
	 *
	 *
	 * @author Timothy Smith
	 * @version 01
	 * @date 3/06/2020, Timothy Smith, Begin class
	 * @date 12/06/2020, Finish class
	 *
	 * @todo
	 *
	 * @bug No known bugs
	 */

class StoreYearData
{
    public:
        /**
        * @brief Default constuctor for StoreYearData
        *
        * Sets the Year to null
        *
        */

        StoreYearData();

        /**
        * @brief Constuctor for StoreYearData
        *
        * Sets the Year to passed in year
        * @param const int - aYear
        */

        StoreYearData(const int aYear);

        /**
        * @brief Gets the year
        *
        * Gets the year from this class
        *
        * @return const int - Year
        */

        int getYear() const;

        /**
        * @brief Sets the year
        *
        * Sets the year of this class
        *
        * @param const int - aYear
        * @return void
        */

        void setYear(const int aYear);

        /**
        * @brief Insert data into the yearMap
        *
        * Allows the user to insert data of type WindLogType into the yearMap
        *
        * @param const WindLogType - myData
        * @return bool
        */

        bool Insert(const WindLogType myData);

        /**
        * @brief Clears the map
        *
        * Clears the yearMap
        *
        * @return void
        */

        void Clear();

        /**
        * @brief Gets the map values by year
        *
        * Searches through the map and gets all values in the year into a vector then returns that vector
        *
        * @param const int - year
        * @return Vector<WindLogType> - tempVector
        */

        Vector<WindLogType> getByYear(const int year);

        /**
        * @brief Gets the map values by year and month
        *
        * Searches through the map and gets all values in the year into a vector then returns that vector
        *
        * @param const int - year, const int - month
        * @return Vector<WindLogType> - tempVector
        */

        Vector<WindLogType> getByMonthOfYear(const int month, const int year);

        /**
        * @brief Overloads the == operator
        *
        * Checks for two equal years
        *
        * @param const StoreYearData - &D
        * @return bool
        */

        bool operator == (const StoreYearData &D) const;

        /**
        * @brief Overloads the < operator
        *
        * Checks for which year is smaller
        *
        * @param const StoreYearData - &D
        * @return bool
        */

        bool operator < (const StoreYearData & D) const;

        /**
        * @brief Overloads the > operator
        *
        * Checks for which year is bigger
        *
        * @param const StoreYearData - &D
        * @return bool
        */

        bool operator > (const StoreYearData & D) const;

    private:
            /// Pair which hold a Date and Time
        typedef std::pair<Date,Time> timePair;
            /// Time Map which hold a timePair as key and a WindLogType as value
        typedef std::map<timePair, WindLogType> timeMap;
            /// Day Map which hold a int as key and a timeMap as value
        typedef std::map<int, timeMap> dayMap;
            /// Month Map which hold a int as key and a dayMap as value
        typedef std::map<int, dayMap> monthMap;
            /// Year Map which hold a int as key and a monthMap as value
        std::map<int, monthMap> yearMap;

            ///Iterator for timeMap
        typedef timeMap::iterator timeIt;
            ///Iterator for dayMap
        typedef dayMap::iterator dayIt;
            ///Iterator for monthMap
        typedef monthMap::iterator monthIt;
            ///Iterator for yearMap
        typedef std::map<int, monthMap>::iterator yearIt;

            /// Year of the data being inserted
        int Year;
};

#endif //StoreYearData_H
