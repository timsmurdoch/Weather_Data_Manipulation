#include "SortingWeatherData.h"

SortingWeatherData::SortingWeatherData()
{

}

void SortingWeatherData::addDataAt(WindLogType log)
{

    if(log.d.getYear() != currentYear){     //Checks for current year we are inserting, if it is the current year,
                                            //we just add to the map unless it already exist inside of the BST, if this is the case then we
                                            // insert into our BST through Function pointers inside of BSTCallbacks

        currentYear = log.d.getYear();      //Set Current Year we must look for
        StoreYearData searchingYearData;    //Temp version of myMaps, only used for comparing years of StoreYearData
        searchingYearData.setYear(currentYear);

        if(!myBST.Search(searchingYearData))
        { //Current year is not in the BST so we must make a new year with myMaps

            myBST.Insert(myMaps); //Inserts the last map made(if this is the first will insert a map of year 0)
            myMaps.Clear(); //Clears the map ready to make new one

            myMaps.Insert(log);
            myMaps.setYear(currentYear);
            cout <<currentYear<<endl;
        }
        else
        {
            //This means the CurrentYear is inside of the BST so we will insert our previous years maps Into the BST then clear myMaps
            myBST.Insert(myMaps);
            myMaps.Clear();

            //Adding data into the current BST at currentYear
            myCallBacks.addDataAt(myBST, currentYear, log);
        }
    }
    else
    {
        //Sets the year we are searching for
        StoreYearData searchingYearData; //This is a temp version of myMaps, only used to compare years inside of the BST
        searchingYearData.setYear(log.d.getYear());

        if(!myBST.Search(searchingYearData))
        {
            //This means the data we are inserting is the currentYear and the year is not already inside of the BST, so we just add onto the maps until the currentYear changes.
            myMaps.Insert(log);
        }
        else
        {
            //This means the currentYear is inside of the BST, so we add the data diretly into the BST using function pointers inside of BSTCallbacks
            myCallBacks.addDataAt(myBST, currentYear, log);
        }

    }

}


Vector<WindLogType> SortingWeatherData::getMonthOfYear(const unsigned aMonth, const unsigned aYear)
{
    //Inserts the last file read into the BST
    myMaps.setYear(currentYear);
    myBST.Insert(myMaps);

    //Looks inside of the BST for a StoreYearData, at the year passed in. (BST stores 1 StoreYearData for each year)
    StoreYearData tempYearData = myCallBacks.findYearData(myBST, aYear);

    //Gets all of the data from the month of the year extracted from the BST, and puts it into a Vector to be processed by main
    Vector<WindLogType> tempVector = tempYearData.getByMonthOfYear(aMonth, aYear);

    return tempVector;
}

Vector<WindLogType> SortingWeatherData::getByYear(const unsigned aYear)
{
    //Inserts the last file read into the BST
    myMaps.setYear(currentYear);
    myBST.Insert(myMaps);

    //Looks inside of the BST for a StoreYearData, at the year passed in. (BST stores 1 StoreYearData for each year)
    StoreYearData tempYearData = myCallBacks.findYearData(myBST, aYear);

    //Gets all of the data from the year extracted from the BST, and puts it into a Vector to be processed by main
    Vector<WindLogType> tempVector = tempYearData.getByYear(aYear);

    return tempVector;
}


