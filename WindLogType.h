#ifndef WINDLOGTYPE_H_INCLUDED
#define WINDLOGTYPE_H_INCLUDED
#include "DATE.h"
#include "Time.h"

	/**
	 * @brief Struct for holding all of the data
	 *
	 * The data held includes Date, Time, Speed, Temperature, SolarRediation
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

 struct WindLogType{
    Date d;
    Time t;
    float S;
    float Te;
    float SR;

    bool operator == (const WindLogType & W) //Overloads operator == to check if date and time is same
    {
        if(W.d == d && W.t == t){
            return true;
        }
        return false;
    }

    bool operator < (const WindLogType & W) //Check which is smaller, priority is date, then time
    {
        if(d < W.d){
            return true;
        }
        else if(d > W.d){
            return false;
        }
        else if(t < W.t){
            return true;
        }
        else if(t > W.t){
            return false;
        }
        return false;

    }

    bool operator > (const WindLogType & W) //Check which is bigger, priority is date, then time
    {
        if(d > W.d){
            return true;
        }
        else if(d < W.d){
            return false;
        }
        else if(t > W.t){
            return true;
        }
        else if(t < W.t){
            return false;
        }
        return false;
    }
};


#endif // WINDLOGTYPE_H_INCLUDED
