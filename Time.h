#ifndef TIME_H
#define TIME_H

	/**
	 * @class Time
	 * @brief Holds the hour, and minutes.
	 *
	 * Hold the time in this function ready to use get to retrieve the data
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

class Time
{
    public:

        /**
         * @brief  Default constructor of Time
         *
         * This function assigns the value of hours, minutes, to 0
         *
         * @return void
         */

        Time();

        /**
         * @brief Constructor of Date
         *
         * This function assigns the value of day, month, and year, to the values given
         *
         * @param unsigned - tHours, unsigned - tMinutes
         *
         * @return void
         */

        Time(const unsigned tHours, const unsigned tMinutes);

        /**
        * @brief Setter for hour
        *
        * Sets the hour to the one pased in
        *
        * @param const unsigned - tHour
        * @return void
        */

        void setHour(const unsigned tHour);

        /**
        * @brief Setter for minutes
        *
        * Sets the minutes to the one pased in
        *
        * @param const unsigned - tMinutes
        * @return void
        */

        void setMinutes(const unsigned tMinutes);

        /**
        * @brief Getter for hours
        *
        * Gets the hours
        *
        * @return unsigned - hours
        */


        unsigned getHour() const;

        /**
        * @brief Getter for minutes
        *
        * Gets the minutes
        *
        * @return unsigned - minutes
        */

        unsigned getMinutes() const;

        bool operator == (const Time &D) const;

        bool operator < (const Time & D) const;

        bool operator > (const Time & D) const;

    protected:


    private:
            /// hold the hours
        unsigned hours;
            /// hold the minutes
        unsigned minutes;
};

#endif // TIME_H
