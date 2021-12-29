//#include "DATE.h"
//#include "Time.h"

#include <iostream>
#include <fstream>
//#include "WindlogType.h"
#include "SortingWeatherData.h"
#include "Calculations.h"
#include "Vector.h"

using namespace std;

const string csvFilesList = "data/met_index.txt";
istream & operator >>(istream &input, SortingWeatherData &windlog);


void selection1(SortingWeatherData &Weather);
void selection2(SortingWeatherData &Weather);
void selection3(SortingWeatherData &Weather);
void selection4(SortingWeatherData &Weather, ofstream &outfile);

string convertMonth(unsigned monthInNum);
float round1Dec(float num);
float totalSR(Vector<WindLogType> &log);

//Main for testing
/*
int main()
{
    cout << convertMonth(2) <<endl;;
    cout <<round1Dec(231.3431f) <<endl;
    cout <<round1Dec(231.3531f) <<endl;
    Vector<WindLogType> aLog;
    WindLogType singleLog1;
    WindLogType singleLog2;
    WindLogType singleLog3;
    WindLogType singleLog4;

    singleLog1.SR = 400.40;
    singleLog2.SR = 331.34;
    singleLog3.SR = 31.34;
    singleLog4.SR = 331.34;

    aLog.insertValueAt(0, singleLog1);
    aLog.insertValueAt(1, singleLog2);
    aLog.insertValueAt(2, singleLog3);
    aLog.insertValueAt(3, singleLog4);

    cout<<"TOTAL SR IN kWh/m2: " <<totalSR(aLog) <<endl;

}
*/

int main()
{
    SortingWeatherData windlog;

    ifstream csvFilesInput(csvFilesList);

    cout << "Loading Data from data folder" <<endl;
    for(string line; getline(csvFilesInput, line);)
    {
        ifstream infile("data/"+line);
        if(!infile) return -1;

        infile >> windlog;

        infile.close();
    }

    int selection = 0;
    do{
        cout << "\n"<<endl;
        cout << "This program reads in historical weather data from files and sorts them into a map within a BST. This can then be used to extract data from the data as seen below" <<endl;
        cout << "Press 1 for The average windspeed and sample deviation given a month and year" <<endl;
        cout << "Press 2 for Average Amient air temp and sample deviation for each month of a year" <<endl;
        cout << "Press 3 for Total solar radiation for each month of a year in kWh/m2" << endl;
        cout << "Press 4 for Average and sample deviation of windspeed ambient air temp, and solar radiation in kWh/m2 for each month of year " <<endl;
        cout << "Press 5 for menu option 5(NOT DONE) " <<endl;
        cout << "Press 6 To exit " <<endl;

        cin >> selection;
        if(cin.fail()){
            selection = 6;
            cout<<"INVALID PLEASE ENTER A NUMBER FROM 1 TO 6"<<endl;
        }

        switch(selection){
        case 1:
            selection1(windlog);
            break;
        case 2:
            selection2(windlog);
            break;
        case 3:
            selection3(windlog);
            break;
        case 4:
            ofstream outfile( "data/WindTempSolar.csv" );
            selection4(windlog, outfile);
            outfile.close();
            break;
        }

    }while(selection != 6);

    return 0;
}

//Average wind speed and SD given a month and year
void selection1(SortingWeatherData &Weather){

    bool valid = true;
    string Tmonth;
    string Tyear;
    cout <<"Enter year: "<<endl;

    cin >> Tyear;

    cout <<"Enter month as number e.g January is 01: "<<endl;
    cin >> Tmonth;

    Vector<WindLogType> log;
    try{
        log = Weather.getMonthOfYear(stoi(Tmonth), stoi(Tyear));
    }catch(std::invalid_argument iaex)
    {
        valid = false;
    }

    if(valid == true && log.getLength() != 0){

        Vector<float> windSpeedCalc;

        for(int i = 0; i < log.getLength(); i++){ //Loads a vector reading for calulations
            windSpeedCalc.insertValueAt(i, log[i].S);
        }

        Calculations<float> myCalc;
        float windSpeedAvg = myCalc.average(windSpeedCalc);

        cout << Tyear << endl;
        if(windSpeedCalc.getLength() != 0){ //Checks if there is any windspeed data

            Tmonth.erase(0, Tmonth.find_first_not_of('0'));
            cout<< convertMonth(stoi(Tmonth)) << " " << Tyear << endl;

            float windSpeedSTDev = myCalc.StdDev(windSpeedCalc);

            cout << "Sample Dev: " << round1Dec(windSpeedSTDev) << endl;
            cout << "Average speed: " << round1Dec(windSpeedAvg) << endl;
        }
    }
    else
        cout <<Tyear <<" No Data Found"<<endl;
}

//Average Amient air temp and sample deviation for each month of a year
void selection2(SortingWeatherData &Weather){

    bool valid = true;
    string Tyear;
    cout << "Enter year(As a number e.g 2019): "<< endl;
    cin >> Tyear;

    cout << endl;
    cout << Tyear << endl;

    for(int i = 1; i < 13; i++){ //Loops though each month of year

            Vector<WindLogType> log;
        try{
            log = Weather.getMonthOfYear(i, stoi(Tyear));
        }catch(std::invalid_argument iaex)
        {
            cout << "Invalid Input" << endl;
            break;
        }
        //Vector<WindLogType> log = Weather.getMonthOfYear(i, stoi(Tyear)); //Find month at i index for the year

        Vector<float> airTempCalc; //Vector to pass in to get the standard deviation

        for(int j = 0; j < log.getLength(); j++){ // Loads a vector with air temp for calculations
           airTempCalc.insertValueAt(j, log[j].Te);
        }

        Calculations<float> myCalc;
        float airTempAvg = myCalc.average(airTempCalc);


        if(airTempCalc.getLength() != 0){ //Checks if no air temp data
            float aTempSTDev = myCalc.StdDev(airTempCalc);
            cout<< convertMonth(i) << ": average: "  << round1Dec(airTempAvg) << " degrees C, stdev: " << round1Dec(aTempSTDev) <<endl;

        }else
            cout << convertMonth(i) << ": No Data" << endl;
    }
}

//Total solar radiation for each month of a year in kWh/m2
void selection3(SortingWeatherData &Weather){

    string Tyear;
    cout <<"Enter year(As a number e.g 2019): "<<endl;

    cin >> Tyear;

    for(int j = 1; j < 13 ; j++){ //Loops for each month of year

        Vector<WindLogType> log;
        try{
            log = Weather.getMonthOfYear(j, stoi(Tyear));
        }catch(std::invalid_argument iaex)
        {
            cout << "Invalid Input" << endl;
            break;
        }

        float total = totalSR(log);

        if(total != 0){
            cout << convertMonth(j) << ":" << round1Dec(total) << "kWh/m^2" <<endl;
        }
        else
            cout << convertMonth(j) << ": No data" <<endl;
    }

}

//Average windspeed ambient air temp, and solar radiation in kWh/m2 for each month of year (PRINT TO FILE)
void selection4(SortingWeatherData &Weather, ofstream &outfile)
{
    bool valid = true;

    string Tyear;
    cout << "Enter year(As a number e.g 2019): "<< endl;
    cin >> Tyear;

    cout << endl;
    cout << Tyear << endl;

    Vector<WindLogType> Tlog;

    try{
        Tlog = Weather.getByYear(stoi(Tyear));
    }catch(std::invalid_argument iaex)
    {
        cout << "Invalid Input" << endl;
        valid = false;
    }

    //Vector<WindLogType> Tlog = Weather.getByYear(stoi(Tyear));

    if(valid = true){
        if(Tlog.getLength() == 0){ //Checks if no data exists
            outfile << Tyear <<endl
            << "No Data";
        }

        else{
            for(int i = 1; i < 13; i++){ //Loops though each month of year

                Vector<WindLogType> log = Weather.getMonthOfYear(i, stoi(Tyear)); //Find month at i index for the year

                Vector<float> airTempCalc; //Vector to pass in to get the standard deviations
                Vector<float> windSpeedCalc;
                Vector<float> srCalc;


                int acount = 0;
                for(int i = 0; i < log.getLength(); i++){ //Loops through loading a vector ready for calucations
                    airTempCalc.insertValueAt(i, log[i].Te);
                    windSpeedCalc.insertValueAt(i, log[i].S);

                    if(log[i].SR >= 100){
                        srCalc.insertValueAt(acount, log[i].SR);
                        acount++;
                    }
                }

                //Variables used for standard deviation averages and averages
                Calculations<float> airCalc;
                Calculations<float> speedCalc;
                float airTempAvg = airCalc.average(airTempCalc);
                float speedAvg = speedCalc.average(windSpeedCalc);
                float mySR = totalSR(log);

                //Checks for all empty data
                if(windSpeedCalc.getLength() == 0 && airTempCalc.getLength() == 0 && airTempCalc.getLength() == 0){ //If all data values are blank
                    outfile << convertMonth(i) << " had no data" <<endl;
                }else{

                    float aTempSTDev = airCalc.StdDev(airTempCalc);
                    float aSpeedSTDev = speedCalc.StdDev(windSpeedCalc);

                    outfile << convertMonth(i) << ",";
                    if(windSpeedCalc.getLength() == 0){ //Checks if no windspeed data
                        outfile << ",";
                    }else{
                        outfile << round1Dec(speedAvg) << "("<< round1Dec(aSpeedSTDev) << "),";
                    }
                    if(airTempCalc.getLength() == 0){ //Check if no air temp data
                        outfile << ",";
                    }else{
                        outfile  << round1Dec(airTempAvg) << "(" << round1Dec(aTempSTDev) << "),";
                    }
                    if(srCalc.getLength() == 0){ //Checks if no Sr data
                        outfile  <<endl;
                    }
                    else{
                        outfile << mySR <<endl;
                    }
                }
            }
        }
    }
    else{
        cout << "INVALID YEAR" << endl;
    }
}

float totalSR(Vector<WindLogType> &log) //Finds total sr and converts it
{
    float total = 0;
    float tempSR = 0;
    for(int i = 0; i < log.getLength(); i++){
        if(log[i].SR >= 100){
             tempSR = (log[i].SR*1/6);
             tempSR = tempSR/1000;
            total += tempSR;
        }
    }
    return total;
}

//Round to 1 deciman place
float round1Dec(float num)
{
    num = num*10;
    num += 0.5;
    int temp = (int)num;
    num = (float) temp;
    num = num/10;

    return num;
}

istream & operator >>(istream &infile, SortingWeatherData &windlog)
{
    WindLogType tempWindlog;
    Date tempDate;
    Time tempTime;
    string tempLine;
    string junkLine;
    getline(infile, junkLine);

    while(getline(infile, tempLine)){

        bool validData = true;
        string timeAndDate = tempLine.substr(0,tempLine.find(","));

        string tempDateString = timeAndDate.substr(0,timeAndDate.find(" "));

        string tempDayString = tempDateString.substr(0,tempDateString.find("/"));

        string tempMonthString = tempDateString.substr(tempDayString.size()+1,2);

        string tempYearString = tempDateString.substr( tempDayString.size()+4,4);


        try{
            tempDate.setDay(stoi(tempDayString));
        }catch (std::invalid_argument iaex){
            validData = false;//break;
        }

        try{
            tempDate.setMonth(stoi(tempMonthString));
        }catch (std::invalid_argument iaex){
            validData = false;//break;
        }

        try{
            tempDate.setYear(stoi(tempYearString));
        }catch (std::invalid_argument iaex){
            validData = false;//break;
        }


        string tempTimeString = timeAndDate.substr(timeAndDate.find(" "), timeAndDate.find(","));
            //cout<<"Time: "<<tempTimeString<<endl;
        string tempHourString = tempTimeString.substr(0,tempTimeString.find(":"));
            //cout<<"Hour: "<<tempHourString<<endl;
        string tempMinuteString = tempTimeString.substr(tempTimeString.find(":")+1,tempTimeString.size());
            //cout<<"Minute: "<<tempMinuteString<<endl;

        try{
            tempTime.setHour(stoi(tempHourString));
        }catch (std::invalid_argument iaex){
            validData = false;//break;
        }

        try{
            tempTime.setMinutes(stoi(tempMinuteString));
        }catch (std::invalid_argument iaex){
            validData = false;//break;
        }

        //Reading in the weather data (We only need S SR and T)
        string weatherReading;

        string myLine = tempLine.substr(tempLine.find(",")+1,tempLine.length());
        weatherReading = myLine.substr(0,myLine.find(",")); //DP
        myLine = myLine.substr(myLine.find(",")+1,myLine.length());

        weatherReading = myLine.substr(0,myLine.find(",")); //Dta
        myLine = myLine.substr(myLine.find(",")+1,myLine.length());

        weatherReading = myLine.substr(0,myLine.find(",")); //Dts
        myLine = myLine.substr(myLine.find(",")+1,myLine.length());

        weatherReading = myLine.substr(0,myLine.find(",")); //EV
        myLine = myLine.substr(myLine.find(",")+1,myLine.length());

        weatherReading = myLine.substr(0,myLine.find(",")); //QFE
        myLine = myLine.substr(myLine.find(",")+1,myLine.length());

        weatherReading = myLine.substr(0,myLine.find(",")); //QFF
        myLine = myLine.substr(myLine.find(",")+1,myLine.length());

        weatherReading = myLine.substr(0,myLine.find(",")); //QNH
        myLine = myLine.substr(myLine.find(",")+1,myLine.length());

        weatherReading = myLine.substr(0,myLine.find(",")); //RF
        myLine = myLine.substr(myLine.find(",")+1,myLine.length());

        weatherReading = myLine.substr(0,myLine.find(",")); //RH
        myLine = myLine.substr(myLine.find(",")+1,myLine.length());

        weatherReading = myLine.substr(0,myLine.find(",")); //S
        myLine = myLine.substr(myLine.find(",")+1,myLine.length());
            //cout << "Wind Speed: " << weatherReading <<endl;
        try{
            tempWindlog.S = stof(weatherReading);
        }catch (std::invalid_argument iaex){
            validData = false;//break;
        }

        weatherReading = myLine.substr(0,myLine.find(",")); //SR
        myLine = myLine.substr(myLine.find(",")+1,myLine.length());
            //cout << "Solar Radiation: " << weatherReading <<endl;
        try{
            tempWindlog.SR = stof(weatherReading);
        }catch (std::invalid_argument iaex){
            validData = false;//break;
        }

        weatherReading = myLine.substr(0,myLine.find(",")); //ST1
        myLine = myLine.substr(myLine.find(",")+1,myLine.length());

        weatherReading = myLine.substr(0,myLine.find(",")); //ST2
        myLine = myLine.substr(myLine.find(",")+1,myLine.length());

        weatherReading = myLine.substr(0,myLine.find(",")); //ST3
        myLine = myLine.substr(myLine.find(",")+1,myLine.length());

        weatherReading = myLine.substr(0,myLine.find(",")); //ST4
        myLine = myLine.substr(myLine.find(",")+1,myLine.length());

        weatherReading = myLine.substr(0,myLine.find(",")); //Sx
        myLine = myLine.substr(myLine.find(",")+1,myLine.length());

        weatherReading = myLine.substr(0,myLine.find(",")); //T
            //cout << "Temp: " << weatherReading <<endl;
        try{
            tempWindlog.Te = stof(weatherReading);
        }catch (std::invalid_argument iaex){
            validData = false;//break;
        }
        if(validData == true){
            tempWindlog.d.setDay(tempDate.getDay());
            tempWindlog.d.setMonth(tempDate.getMonth());
            tempWindlog.d.setYear(tempDate.getYear());
            tempWindlog.t.setHour(tempTime.getHour());
            tempWindlog.t.setMinutes(tempTime.getMinutes());
            //cout <<"ADDED"<<endl;
            windlog.addDataAt(tempWindlog);

        }
    }
    return infile;
}

string convertMonth(unsigned monthNumber) {

    string monthInString = "";

    switch(monthNumber) {
        case 1:
            monthInString = "January";
            break;
        case 2:
            monthInString = "February";
            break;
        case 3:
            monthInString = "March";
            break;
        case 4:
            monthInString = "April";
            break;
        case 5:
            monthInString = "May";
            break;
        case 6:
            monthInString = "June";
            break;
        case 7:
            monthInString = "July";
            break;
        case 8:
            monthInString = "August";
            break;
        case 9:
            monthInString = "September";
            break;
        case 10:
            monthInString = "October";
            break;
        case 11:
            monthInString = "November";
            break;
        case 12:
            monthInString = "December";
            break;
    }
    return monthInString;
}
