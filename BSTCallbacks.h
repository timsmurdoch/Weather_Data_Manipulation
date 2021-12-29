#ifndef BSTCALLBACKS_H
#define BSTCALLBACKS_H
#include "BST.h"
#include "StoreYearData.h"

	/**
	 * @class BSTCallbacks
	 * @brief Function callbacks for the BST
	 *
	 * Takes advantage of the function pointers inside of the BST to get a Year from it, and insert into it
	 *
	 *
	 * @author Timothy Smith
	 * @version 01
	 * @date 03/06/2020, Timothy Smith, Started Modifying original
	 * @date 12/06/2020, Finishing adding the methods and variables
	 *
	 *
	 * @todo
	 *
	 * @bug No known bugs
	 */

class BSTCallbacks
{
    public:

        /**
        * @brief Used as a function pointer into the BST to find a Year
        *
        * Used as a function pointer into the BST to find a Year
        *
        * @param StoreYearData - &y
        * @return void
        */

        static void findYear(StoreYearData & y);

        /**
        * @brief Used as a function pointer into the BST to find add WindLogType
        *
        * Adds WindLogType into the BST at a year
        *
        * @param StoreYearData - &y
        * @return void
        */

        static void addData(StoreYearData &y);

        /**
        * @brief Finds a year inside of a BST
        *
        * Finds a year inside of a BST using inOrder and a function pointer with findYear()
        *
        * @param const BST<StoreYearData> - &aBST, const int - Year
        * @return StoreYearData - tempYearData
        */

        StoreYearData findYearData(const BST<StoreYearData> &aBST, const int Year);

        /**
        * @brief Puts data into the BST
        *
        * Puts data into the BST using inOrder and a function pointer with addData()
        *
        * @param const BST<StoreYearData> - &aBST, const int - Year, const WindLogType - dataToAdd
        * @return void
        */

        void addDataAt(const BST<StoreYearData> &aBST, const int year, const WindLogType dataToAdd);

    private:
            /// object of StoreYearData
        static StoreYearData tempYearData;
            /// Object of WindLogType
        static WindLogType data;
            /// Integer of the year to find
        static int yearToFind;

};



#endif // BSTCALLBACKS_H
