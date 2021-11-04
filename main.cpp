/*
    Divvy Bike Data Analysis program.
    Author: Angad Gakhal
    Date: 10/7/2021
    Class: CS 141, Fall 2021, UIC
    System: Mac XCode
    Menu Option 5 Extra Credit URL: https://www.google.com/maps/d/u/0/edit?mid=1kEBEpX9wK7_L-cxFBnXy6ZYR_u0mVIs6&usp=sharing
    Coordinates for Home I would like to live in:  41.8645  -87.6292
*/

#include <iostream>   // For Input and Output
#include <fstream>    // For file input and output
#include <cassert>    // For the assert statement
#include <cctype>     // access to tolower() or toupper() function
#include <vector>     // For vectors
#include <string>     // String operations
#include <algorithm>  // use of vector algorithms
#include <cmath>
#include <iomanip>

using namespace std;
/*
// filepaths for Macbook testing
const string sampleRidesFile = "/Users/angadgakhal/Downloads/Datatype/Prog4test/Prog4test/../../../divvyridesampledata.csv";
const string weekendRidesFile = "/Users/angadgakhal/Downloads/Datatype/Prog4test/Prog4test/../../../weekdayweekend.csv";
const string septRidesFile = "/Users/angadgakhal/Downloads/Datatype/Prog4test/Prog4test/../../../all_divvy_rides_september.csv";
*/

//filepaths for zybooks testing
const string sampleRidesFile = "divvyridesampledata.csv";
const string weekendRidesFile = "weekdayweekend.csv";
const string septRidesFile = "all_divvy_rides_september.csv";

class bikeTrip {

public:

   bikeTrip() { // This will be our default contructor with default paramters declared
      this->rideID = -1;
      this->bikeType = "default";
      this->startTime = "Default";
      this->endTime = "Default";
      this->startStationName = "default";
      this->endStationName = "default";
      this->startLat = 0;
      this->startLong = 0;
      this->endLat = 0;
      this->endLong = 0;
      this->member = true;
      
   }

    //Setters
    void setRideID(string rideID) {
       this->rideID = rideID;
    }

    void setType(bool member) {
       this->member = member;
    }

    void setStartTime(string startTime) {
       this->startTime = startTime;
    }

    void setEndTime(string endTime) {
       this->endTime = endTime;
    }

    void setStartStationName (long double startLat) {
       this->startLat = startLat;
    }

    void setEndStationName (long double startLong) {
       this->startLong = startLong;
    }

    void setStartLat (long double endLat) {
       this->endLat = endLat;
    }

    void setStartLng (long double endLong) {
       this->endLong = endLong;
    }

    void setEndLat(string type) {
       this->bikeType = type;
    }

    void setEndLng(string startStationName) {
       this->startStationName = startStationName;
    }

    void setMember(string endStationName) {
       this->endStationName = endStationName;
    }

   //Getters
   string getRideID() {
      return this->rideID;
   }

   string getType() {
      return this->bikeType;
   }

   string getStartTime() {
      return this->startTime;
   }

   string getEndTime() {
      return this->endTime;
   }

   string getStartStationName() {
      return this->startStationName;
   }

   string getEndStationName() {
      return this->endStationName;
   }

   long double getStartLat() {
      return this->startLat;
   }

   long double getStartLng() {
      return this->startLong;
   }

   long double getEndLat() {
      return this->endLat;
   }

   long double getEndLng() {
      return this->endLong;
   }

   bool getMember() {
      return this->member;
   }
    
    
    bikeTrip(string excelData) { // This will allow us to extract data from excel and place data type in appropriate spot based on where code finds commas

         int commaSearch = excelData.find(",");
         this->rideID = excelData.substr(0, commaSearch);

         excelData.replace(0, commaSearch + 1, "");
         commaSearch = excelData.find(",");
         this->bikeType = excelData.substr(0, commaSearch);

         excelData.replace(0, commaSearch + 1, "");
         commaSearch = excelData.find(",");
         this->startTime = excelData.substr(0, commaSearch);

         excelData.replace(0, commaSearch + 1, "");
         commaSearch = excelData.find(",");
         this->endTime = excelData.substr(0, commaSearch);

         excelData.replace(0, commaSearch + 1, "");
         commaSearch = excelData.find(",");
         this->startStationName = excelData.substr(0, commaSearch);

         excelData.replace(0, commaSearch + 1, "");
         commaSearch = excelData.find(",");
         this->endStationName = excelData.substr(0, commaSearch);

         excelData.replace(0, commaSearch + 1, "");
         commaSearch = excelData.find(",");
         this->startLat = stod((excelData.substr(0, commaSearch)));

         excelData.replace(0, commaSearch + 1, "");
         commaSearch = excelData.find(",");
         this->startLong = stod(excelData.substr(0, commaSearch));

         excelData.replace(0, commaSearch + 1, "");
         commaSearch = excelData.find(",");
         this->endLat = stod((excelData.substr(0, commaSearch)));

         excelData.replace(0, commaSearch + 1, "");
         commaSearch = excelData.find(",");
         this->endLong = stod((excelData.substr(0, commaSearch)));

         excelData.replace(0, commaSearch + 1, "");
         commaSearch = excelData.find(",");
         string checkMember = excelData.substr(0, commaSearch);
            
          //Check if bike user is a Member or not
         if (checkMember == "member\r") {//Need \r to ensure the data gets read properly. (Thanks Grace)
            this->member = true;
         } else {
            this->member = false;
         }

      }

   void displayTrip() {
      cout <<
          this->rideID << "," <<
          this->bikeType << "," <<
          this->startTime << "," <<
          this->endTime << "," <<
          this->startStationName << "," <<
          this->endStationName << "," <<
          this->startLat << "," <<
          this->startLong << "," <<
          this->endLat << "," <<
          this->endLong << "," <<
          this->member << endl;
   }

private:

   string rideID;
   string bikeType;
   string startTime;
   string endTime;
   string startStationName;
   string endStationName;
   long double startLat;
   long double startLong;
   long double endLat;
   long double endLong;
   bool member;

};

// Have to clean Data
vector<bikeTrip> readExcelCleanTrips(string filePath, int &originalSize);

long double toRadians(const long int degree);
//These two long doubles will convert our Lats and Longs from ints to our desired data type.
long double distance(long int lat1, long int long1, long int lat2, long int long2);

bool isWeekend(string date) {
   int dateBreakIndex = date.find("/");
    int month = stoi(date.substr(0, dateBreakIndex));

   date = date.erase(0,dateBreakIndex + 1);

   dateBreakIndex = date.find("/");
   int day = stoi(date.substr(0, dateBreakIndex));
   day %= 7;

   if (day == 4 || day == 5) {
        return true;
   }
   else {
        return false;
    }

}

vector<bikeTrip> optionOne();
// Menu options via Function declarations
void optionTwo(vector<bikeTrip> trips);

void optionThree(vector<bikeTrip> trips);

void optionFour(vector<bikeTrip> trips);

void displayMenu();



int main() {

   bool wanttoAdvance = true;//This will allow the user to advance through the different options if they want to go through more than one
   int optionInput;

   vector<bikeTrip> trips;
   cout << "Analyze Divvy bike ride information using September trip data." << endl;
   cout << "First select option 1 to read and clean the data." << endl << endl;

   while(true) {

      displayMenu();
      cin >> optionInput;

      if (optionInput == 1) {//If statment to ensure option 1 is chosen first so we can read in the data
         trips = optionOne();
         break;
      } else {
         cout << "First read in data by selecting menu option 1";
      }
   }

   while (wanttoAdvance) {
        displayMenu();
        cin >> optionInput;

        switch (optionInput) {//User Input will be assigned to different options with this code

           case 1:
            trips = optionOne();
               break;

           case 2:
            optionTwo(trips);
               break;

           case 3:
            optionThree(trips);
                break;

           case 6: // This will allow us to exit the program
            wanttoAdvance = false;
            break;

           default:
               cout << "Invalid option. Please try again." << endl;
               break;
        }
    }

   return 0;

}

//This function will allow us to display to menu to the user
void displayMenu() {

   cout << "Select a menu option:" << endl;
   cout << "   1. Select datafile, display rides totals and clean data" << endl;
   cout << "   2. Display overall trip information" << endl;
   cout << "   3. Display percentage of members vs. casual riders" << endl;
   cout << "   4. Display weekday vs weekend usage" << endl;
   cout << "   5. Extra Credit: find closest station" << endl;
   cout << "   6. Exit" << endl;
   cout << "Your choice --> ";
}

//Option 1
vector<bikeTrip> optionOne() {

   int beginningSize = 0;

   vector<bikeTrip> cleanTrips;//We need to use trips that derive from the clean data

   cout << "Select datafile:" << endl;
   cout << "1. Small subset of data with 14 rides to help create your program" << endl;
   cout << "2. Week day vs weekend rides" << endl;
   cout << "3. All September 2021 data (not tested in Zybooks)" << endl;
   cout << "Your selection--> " << endl;

   int choice;
   cin >> choice;

   //We need a switch statement to declare cleanTrips to be the clean data into each excel file
   switch (choice) {

      case 1:
         cleanTrips = readExcelCleanTrips(sampleRidesFile, beginningSize);
         break;
      case 2:
         cleanTrips = readExcelCleanTrips(weekendRidesFile, beginningSize);
         break;
      case 3:
         cleanTrips = readExcelCleanTrips(septRidesFile, beginningSize);
         break;
      default:
         cout << "Please choose File 1, 2, or 3 to read in" << endl;
         break;
   };

   cout << "Total # of trips found in datafile: " << beginningSize << endl <<
       "   Total # of trips in clean data: " << cleanTrips.size() << endl;

   return cleanTrips;
}

vector<bikeTrip> readExcelCleanTrips(string filePath, int &originalSize) {

   originalSize = 0;
   //Next lines of code will ensure file is opened and will present error if its not opened
   ifstream inStream;
   inStream.open(filePath);
   assert(inStream.fail() == false);

   vector<bikeTrip> tripList;

   string newWord;

   // blocks the first read from while to skip title
   bool initialBlock = true;

   // read a line into newWord until end of file
   while (getline(inStream, newWord)) {

      // count original size regardless of it is cleaned or not
      originalSize += 1;

      // if newWord has empty data or is the title just skip it
      if ((newWord.find(",,") != string::npos) || initialBlock) {
         initialBlock = false;
         continue;
      }

      //New trip will be put into the list
      tripList.push_back(bikeTrip(newWord));
   }

   // removes one from original size to remove title
   originalSize -= 1;

   inStream.close();

   return tripList;

}

// Utility functions getting distant between two map points
// Attribution: https://www.geeksforgeeks.org/program-distance-two-points-earth/
// converting degrees to radians
long double toRadians(const long double degree) {
   // cmath library in C++
   // defines the constant
   // M_PI as the value of
   // pi accurate to 1e-30
   long double one_deg = (3.14159265358979323846) / 180;
   return (one_deg * degree);
}

long double distance(long double lat1, long double long1,
                long double lat2, long double long2) {
   // Convert the latitudes
   // and longitudes
   // from degree to radians.
   lat1 = toRadians(lat1);
   long1 = toRadians(long1);
   lat2 = toRadians(lat2);
   long2 = toRadians(long2);

   // Haversine Formula
   long double distanceLong = long2 - long1;
   long double distanceLat = lat2 - lat1;

   long double ans = pow(sin(distanceLat / 2), 2) +
                 cos(lat1) * cos(lat2) *
                 pow(sin(distanceLong / 2), 2);

   ans = 2 * asin(sqrt(ans));

   // Radius of Earth in
   // Kilometers, R = 6371
   // Use R = 3956 for miles
   long double R = 3956;

   // Calculate the result
   ans = ans * R;

   return ans;
}

long double roundNumber(long double x) {
   return floor(x * 10 + 0.5) / 10;
}

void optionTwo(vector<bikeTrip> trips) {

   /**
    *    Total # of miles traveled: 13
   Average length of trips in miles:  1.3

   Longest trip information below:
   -------------------------------
   Trip ID: B465E78B601DB5A8
   Trip start location: Broadway & Belmont Ave
   Trip end location: Broadway & Thorndale Ave
   Trip distance in miles: 3.5
**/

   long double distanceSum = 0;
   long double tripDist = 0;

   bikeTrip tripMax = trips.at(0);
   long double maxtripDist = 0;

   for (int index = 0; index < trips.size(); index++) {
      tripDist = distance(trips.at(index).getStartLat(), trips.at(index).getStartLng(),
                  trips.at(index).getEndLat(), trips.at(index).getEndLng());//For loop that will allow to dsiplay appropriate latitude and longtitude
      
       if (maxtripDist < tripDist) {
         maxtripDist = roundNumber(tripDist);
         tripMax = trips.at(index);//ensures the biggest trip is stored into maxtripDist variable
      }

      distanceSum += tripDist;
    
   }

   distanceSum = round(distanceSum);

   long double avgDist = roundNumber(distanceSum / trips.size());

   cout << "   Total # of miles traveled: " << distanceSum << endl;
   cout << "   Average length of trips in miles:  "<< avgDist << endl << endl;
   cout <<      "   Longest trip information below: " << endl;
   cout <<      "   -------------------------------" << endl;
   cout <<      "   Trip ID: " << tripMax.getRideID() << endl;
   cout <<      "   Trip start location: " << tripMax.getStartStationName() << endl;
   cout <<      "   Trip end location: " << tripMax.getEndStationName() << endl;
   cout <<      "   Trip distance in miles: "<< maxtripDist << endl;
}

void optionThree(vector<bikeTrip> trips) {

   double totalMembers = 0;

   for (int index = 0; index < trips.size(); index++) {

      if (trips.at(index).getMember()) {
         totalMembers += 1;
      }
    };
    
   long double totalCasual = trips.size() - totalMembers;
   long double percentMembers = roundNumber( totalMembers / (long double)trips.size() * 100.0);
   long double percentCasual = roundNumber((double) totalCasual /(long double)trips.size() * 100.0);

   cout << "Casual Rider Percentage: " << setprecision(1) << fixed << percentCasual << "% " << endl;//Need setprecision and fixed to display the percentage correctly
   cout << "Member Rider Percentage: " << percentMembers << "% " << endl;

}

void optionFour(vector<bikeTrip> trips){
    
    
    cout << "Select type of display: " << "\n";
    cout << "    1. Counts of rides per hour in the day " << endl;
    cout << "    2. Proportional 50 column graph with @ for weekday and + for weekend " << endl;
    cout << "Your selection--> " << endl;
    
   
       int option = 0;
       cin >> option;
    
        double totalWeekend = 0;
        double totalWeekday = 0;

       vector<double> hourlyweekendRides(24,0);
       vector<double> hourlyweekdayRides(24,0);

       for (int index = 0; index < trips.size(); index++) {

          int findSpace = trips.at(index).getStartTime().find(" ");

          string onlyDate = trips.at(index).getStartTime().substr(0, findSpace);
          bool weekend = isWeekend(onlyDate);

          string onlyTime = trips.at(index).getStartTime().erase(0, findSpace + 1);

          int findColon = onlyTime.find(":");

          int hour = stoi(onlyTime.substr(0, findColon));

          if (weekend) {
             hourlyweekendRides.at(hour) += 1;
             totalWeekend += 1;
          }
          else {
             hourlyweekdayRides.at(hour) += 1;
             totalWeekday += 1;
          }
       }

       int largestnumberofRides = 0;
       for (int index = 0; index < hourlyweekendRides.size(); index++) {
          if (largestnumberofRides < hourlyweekendRides.at(index)) {
             largestnumberofRides = hourlyweekendRides.at(index);
          }
       }
       for (int index = 0; index < hourlyweekdayRides.size(); index ++) {
          if (largestnumberofRides < hourlyweekdayRides.at(index)) {
             largestnumberofRides = hourlyweekdayRides.at(index);
          }
       }

       if (option == 1) {
           
          cout << "    LargestNumberOfRides is: " << largestnumberofRides << endl;
          cout << "   Rides per hour for weekday and weekend" << endl;
          for (int index = 0; index < hourlyweekdayRides.size(); index++) {

             cout << "  " << index << " : " << hourlyweekdayRides.at(index) << "    " << hourlyweekendRides.at(index) << endl;

          }
       }
else if (option == 2) {
    
      for (int index = 0; index < hourlyweekdayRides.size(); index++) {
         cout << "   " << index << ": ";
         cout << string(hourlyweekdayRides.at(index) * 50.0 / largestnumberofRides, '@') << endl;
         cout << string(hourlyweekendRides.at(index) * 50.0 / largestnumberofRides, '+') << endl;

      }

   }
}
