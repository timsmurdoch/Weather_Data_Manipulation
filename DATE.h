#ifndef Date_H
#define Date_H
#include <string>
#include <string.h>


	/**
	 * @class Date
	 * @brief Obtains the day, month, and year from a file
	 *
	 * Takes in the date from a file using isteams and set and gets, then outputs it using ostreams when needed
	 *
	 *
	 * @author Timothy Smith
	 * @version 01
	 * @date 20/03/2020, Timothy Smith, Started Modifying original
	 *
	 *
	 *
	 * @todo Wait for next lab
	 *
	 * @bug No known bugs
	 */
class Date
{
    public:

        /**
         * @brief  Default constructor of Date
         *
         * This function assigns the value of day, month, and year, to 0 or an empty string
         *
         * @return void
         */

        Date();

      /**
         * @brief Constructor of Date
         *
         * This function assigns the value of day, month, and year, to the values given
         *
         * @param unsigned - Sday, string - Smonth, unsigned - Syear
         *
         * @return void
         */

        Date(const unsigned Sday, const unsigned Smonth, const unsigned Syear);

        /**
         * @brief  Sets the day
         *
         * Sets the value of day to Sday
         *
         * @param unsigned - Sday
         * @return void
         */

        void setDay(const unsigned Sday);

        /**
         * @brief  Sets the month
         *
         * Sets the value of month to Smonth
         *
         * @param string - Smonth
         * @return void
         */

        void setMonth(const unsigned Smonth);

        /**
         * @brief  Sets the year
         *
         * Sets the value of year to Syear
         *
         * @param unsigned - Syear
         * @return void
         */

        void setYear(const unsigned Syear);

       /**
        * @brief  Returns the value of day
        *
        * Returns day value
        *
        * @return unsigned - day
        */

        unsigned getDay() const;

       /**
        * @brief  Returns the value of month
        *
        * Returns month value
        *
        * @return string - month
        */

        unsigned getMonth() const;

       /**
        * @brief  Returns the value of year
        *
        * Returns year value
        *
        * @return unsigned - year
        */

        unsigned getYear() const;

        bool operator == (const Date & D) const;

        bool operator < (const Date & D) const;

        bool operator > (const Date & D) const;


    protected:

    private:
            /// The day a mark was recorded
        unsigned day;
            /// The month a mark was recorded
        unsigned month;
            /// The year a mark was recorded
        unsigned year;

};
/*
//Not friends anymore
istream & operator >>( istream & input, Date & D );
//Not friends anymore
ostream & operator <<( ostream & os, const Date & D );
*/
#endif // Date_H
