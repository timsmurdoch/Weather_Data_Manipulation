#include "BSTCallbacks.h"

StoreYearData BSTCallbacks::tempYearData;
int BSTCallbacks::yearToFind;
WindLogType BSTCallbacks::data;


void BSTCallbacks::findYear(StoreYearData& y)
{
    if(yearToFind == y.getYear())
    {
        tempYearData = y;
    }
}

void BSTCallbacks::addData(StoreYearData& y)
{
    if(yearToFind == y.getYear())
    {
        y.Insert(data);
    }
}

void BSTCallbacks::addDataAt(const BST<StoreYearData> &aBST, const int year, const WindLogType dataToAdd)
{
    yearToFind = year;
    data = dataToAdd;
    aBST.inOrder(BSTCallbacks::addData);
}

StoreYearData BSTCallbacks::findYearData(const BST<StoreYearData> &aBST, const int Year)
{
    yearToFind = Year;
    aBST.inOrder(BSTCallbacks::findYear);
    return tempYearData;
}
