#include "StoreYearData.h"

StoreYearData::StoreYearData()
{
    Year = NULL;
}

StoreYearData::StoreYearData(const int aYear)
{
    Year = aYear;
}

int StoreYearData::getYear() const
{
    return Year;
}

void StoreYearData::setYear(const int aYear)
{
    Year = aYear;
}

bool StoreYearData::Insert(const WindLogType myData)
{

    if(yearMap.find(myData.d.getYear()) != yearMap.end()){ //Checks if the year is inside of the map

        if(yearMap.at(myData.d.getYear()).find(myData.d.getMonth()) != yearMap.at(myData.d.getYear()).end()){ //Checks if the month is inside of the map

            if(yearMap.at(myData.d.getYear()).at(myData.d.getMonth()).find(myData.d.getDay()) != yearMap.at(myData.d.getYear()).at(myData.d.getMonth()).end()){ //Checks if the day is inside of the map
                auto key = std::make_pair(myData.d, myData.t);

                yearMap.at(myData.d.getYear()).at(myData.d.getMonth()).at(myData.d.getDay()).insert(std::make_pair(key,myData)); //Inserts my data into the map at the day
            }else{
                auto key = std::make_pair(myData.d, myData.t);

                timeMap aTimeMap;
                aTimeMap.insert(std::make_pair(key, myData));

                yearMap.at(myData.d.getYear()).at(myData.d.getMonth()).insert(std::make_pair(myData.d.getDay(), aTimeMap)); //Inserts data into the map at the month
            }
        }else{
            auto key = std::make_pair(myData.d, myData.t);

            timeMap aTimeMap;
            aTimeMap.insert(std::make_pair(key, myData));

            dayMap aDayMap;
            aDayMap.insert(std::make_pair(myData.d.getDay(), aTimeMap));

            yearMap.at(myData.d.getYear()).insert(std::make_pair(myData.d.getMonth(), aDayMap)); //Inserts data into the map at the year
        }
    }else{
        auto key = std::make_pair(myData.d, myData.t);
        timeMap aTimeMap;
        aTimeMap.insert(std::make_pair(key, myData));

        dayMap aDayMap;
        aDayMap.insert(std::make_pair(myData.d.getDay(), aTimeMap));

        monthMap aMonthMap;
        aMonthMap.insert(std::make_pair(myData.d.getMonth(), aDayMap));

        yearMap.insert(std::make_pair(myData.d.getYear(), aMonthMap)); //Inserts new data into the map
    }
}

void StoreYearData::Clear()
{
    yearMap.clear();
}

Vector<WindLogType> StoreYearData::getByYear(const int year)
{
    Vector<WindLogType> tempVector;

    if(yearMap.find(year) != yearMap.end()){ //Checks year exists
        yearIt yi = yearMap.find(year); //Sets the iterator to the year found
        for(monthIt mi = yi->second.begin(); mi != yi->second.end(); mi++){ //For each month
            for(dayIt di = mi->second.begin(); di != mi->second.end(); di++){ //For each day
                for(timeIt ti = di->second.begin(); ti != di->second.end(); ti++){ //For each WindLogType in day
                        tempVector.Insert(ti->second); //Inserts the WindLogType
                }
            }
        }
    }

    return tempVector;
}

Vector<WindLogType> StoreYearData::getByMonthOfYear(const int month, const int year)
{
    Vector<WindLogType> tempVector;

    if(yearMap.find(year) != yearMap.end()){ //Checks year exists
        if(yearMap.at(year).find(month) != yearMap.at(year).end()){ //Checks month exists
            monthIt mi = yearMap.at(year).find(month); //Iterator for each month of year
                for(dayIt di = mi->second.begin(); di != mi->second.end(); di++){ //For each day
                    for(timeIt ti = di->second.begin(); ti != di->second.end(); ti++){ //For each WindLogType in day
                        tempVector.Insert(ti->second); //Inserts the WindLogType
                    }
                }
        }
    }

    return tempVector;
}

bool StoreYearData::operator==(const StoreYearData& D) const
{
    if(Year == D.getYear()){
        return true;
    }
    else
        return false;
}

bool StoreYearData::operator<(const StoreYearData& D) const
{
    if(Year < D.getYear()){
        return true;
    }
    else if(Year > D.getYear()){
        return false;
    }
    else
        return false;

}

bool StoreYearData::operator>(const StoreYearData& D) const
{
    if(Year > D.getYear()){
        return true;
    }
    else if(Year < D.getYear()){
        return false;
    }
    else
        return false;
}
