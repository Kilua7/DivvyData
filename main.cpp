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
#include <cmath>      // For math calculations
#include <iomanip>    // For setprecision to work correctly

using namespace std;

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

    void setType(string type) {
       this->bikeType = type;
    }

    void setStartTime(string startTime) {
       this->startTime = startTime;
    }

    void setEndTime(string endTime) {
       this->endTime = endTime;
    }

    void setStartStationName (string startStationName) {
       this->startStationName = startStationName;
    }

    void setEndStationName (string endStationName) {
       this->endStationName = endStationName;
    }

    void setStartLat (long double startLat) {
       this->startLat = startLat;
    }

    void setStartLong (long double startLong) {
       this->startLong = startLong;
    }

    void setEndLat(long double endLat) {
       this->endLat = endLat;
    }

    void setEndLong(long double endLong) {
       this->endLong = endLong;
    }

    void setMember(bool member) {
        this->member = member;
        
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
    
//Utility Function
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
//Private variables
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

//Use of vector to make use of clean data
vector<bikeTrip> readExcelCleanTrips(string filePath, int &originalSize);

long double toRadians(const long int degree);
// Use lat and long numbers to soon calculate distances
long double distance(long int lat1, long int long1, long int lat2, long int long2);

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

      cout << "Select a menu option:" << endl;
      cout << "   1. Select datafile, display rides totals and clean data" << endl;
      cout << "   2. Display overall trip information" << endl;
      cout << "   3. Display percentage of members vs. casual riders" << endl;
      cout << "   4. Display weekday vs weekend usage" << endl;
      cout << "   5. Extra Credit: find closest station" << endl;
      cout << "   6. Exit" << endl;
      cout << "Your choice --> ";
      cin >> optionInput;

      if (optionInput == 1) {//If statment to ensure option 1 is chosen first so we can read in the data
         trips = optionOne();
         break;
      } else {
         cout << "First read in data by selecting menu option 1";
      }
   }
    //Menu will reappear again
   while (wanttoAdvance) {
        cout << "Select a menu option:" << endl;
        cout << "   1. Select datafile, display rides totals and clean data" << endl;
        cout << "   2. Display overall trip information" << endl;
        cout << "   3. Display percentage of members vs. casual riders" << endl;
        cout << "   4. Display weekday vs weekend usage" << endl;
        cout << "   5. Extra Credit: find closest station" << endl;
        cout << "   6. Exit" << endl;
        cout << "Your choice --> ";
        cin >> optionInput;

        switch (optionInput) {//User Input will be assigned to different options with this code
            //Switch statement that shows which option will go to which function
           case 1:
            trips = optionOne();
               break;

           case 2:
            optionTwo(trips);
               break;

           case 3:
            optionThree(trips);
                break;
                
            case 4:
                optionFour(trips);
                break;

           case 6: // This will allow us to exit the program
                goto Label;
            break;

           default:
               cout << "Invalid option. Please try again." << endl;
               break;
        }
    }
    Label:
   return 0;

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

   //We need a switch statement to read in the appropriate files
   switch (choice) {

      case 1:
         cleanTrips = readExcelCleanTrips("divvyridesampledata.csv", beginningSize);
         break;
      case 2:
         cleanTrips = readExcelCleanTrips("weekdayweekend.csv", beginningSize);
         break;
      case 3:
         cleanTrips = readExcelCleanTrips("all_divvy_rides_september.csv", beginningSize);
         break;
      default:
         cout << "Please choose File 1, 2, or 3 to read in" << endl;
         break;
   };
//Print out number of trips as well as number of clean data trips
   cout << "Total # of trips found in datafile: " << beginningSize << endl <<
       "   Total # of trips in clean data: " << cleanTrips.size() << endl;

   return cleanTrips;
}

vector<bikeTrip> readExcelCleanTrips(string filePath, int &originalSize) {

   originalSize = 0;
   //Ensures file is opened and will present an error if its not opened in line 299
   ifstream inStream;
   inStream.open(filePath);
   assert(inStream.fail() == false);

   vector<bikeTrip> tripList;

   string excelData;

   bool initialBlock = true;

   // read a line into newWord until end of file
   while (getline(inStream, excelData)) {
       
      originalSize += 1;

      // Skipping excel data that is empty
       if ((excelData.find(",,") <= excelData.length()) || initialBlock) {
         initialBlock = false;
         continue;
      }
       
          tripList.push_back(bikeTrip());
            // This code will accurately find the commas in the data and then know which data goes to which specific code
          int commaSearch = excelData.find(",");
          tripList.at(tripList.size() - 1).setRideID(excelData.substr(0, commaSearch));
       
                                               
          excelData.erase(0, commaSearch + 1);
          commaSearch = excelData.find(",");
          tripList.at(tripList.size() - 1).setType(excelData.substr(0, commaSearch));
       
          excelData.erase(0, commaSearch + 1);
          commaSearch = excelData.find(",");
          tripList.at(tripList.size() - 1).setStartTime(excelData.substr(0, commaSearch));
       
          excelData.erase(0, commaSearch + 1);
          commaSearch = excelData.find(",");
          tripList.at(tripList.size() - 1).setEndTime(excelData.substr(0, commaSearch));
       
          excelData.erase(0, commaSearch + 1);
          commaSearch = excelData.find(",");
          tripList.at(tripList.size() - 1).setStartStationName(excelData.substr(0, commaSearch));
       
          excelData.erase(0, commaSearch + 1);
          commaSearch = excelData.find(",");
          tripList.at(tripList.size() - 1).setEndStationName(excelData.substr(0, commaSearch));
       
          excelData.erase(0, commaSearch + 1);
          commaSearch = excelData.find(",");
          tripList.at(tripList.size() - 1).setStartLat(stod(excelData.substr(0, commaSearch)));
       
          excelData.erase(0, commaSearch + 1);
          commaSearch = excelData.find(",");
          tripList.at(tripList.size() - 1).setStartLong(stod(excelData.substr(0, commaSearch)));
       
          excelData.erase(0, commaSearch + 1);
          commaSearch = excelData.find(",");
          tripList.at(tripList.size() - 1).setEndLat(stod(excelData.substr(0, commaSearch)));
          
          excelData.erase(0, commaSearch + 1);
          commaSearch = excelData.find(",");
          tripList.at(tripList.size() - 1).setEndLong(stod(excelData.substr(0, commaSearch)));
       
          excelData.erase(0, commaSearch + 1);
          commaSearch = excelData.find(",");
          tripList.at(tripList.size() - 1).setMember((excelData.substr(0, commaSearch) == "member\r") ? true : false);
       //Need /r to ensure excel data regarding to member is being accurately read
      
   }
    
   // To remove the title
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
           string onlyTime = trips.at(index).getStartTime().erase(0, findSpace + 1);
           
           int dateBreakIndex = onlyTime.find("/");
           onlyDate.erase(0,2);
           
           int day = stoi(onlyDate.substr(0, dateBreakIndex));
           
           int findColon = onlyTime.find(":");
           
           int hour = stoi(onlyTime.substr(0, findColon));
           
           if ((day == 4) || (day == 5) ||( day == 11) || (day == 12) || (day == 18) || (day == 19) || (day == 25) || (day ==26)) {
               hourlyweekendRides.at(hour) += 1;
               totalWeekend += 1;
               //This if statement will allow the code to know which days are specifcally weekends
           } else{
                //If it's not a weekday, the following will effect the weekday rides
               hourlyweekdayRides.at(hour) += 1;
               totalWeekday += 1;  }
       }
        // largestnumberofRides will keep getting updated
       int largestnumberofRides = 0;
       for (int index = 0; index < hourlyweekendRides.size(); index++) {
          if (largestnumberofRides < hourlyweekendRides.at(index)) {
             largestnumberofRides = hourlyweekendRides.at(index);
          }
           if (largestnumberofRides < hourlyweekdayRides.at(index)) {
              largestnumberofRides = hourlyweekdayRides.at(index);
           }
       }

       if (option == 1) {
           
          cout << "    LargestNumberOfRides is: " << largestnumberofRides << endl;
          cout << "   Rides per hour for weekday and weekend:" << endl;
          for (int index = 0; index < hourlyweekdayRides.size(); index++) {

             cout << "  " << index << " : " << hourlyweekdayRides.at(index) << "    " << hourlyweekendRides.at(index) << endl;

          }
       }
    
else if (option == 2) {
    
      for (int index = 0; index < hourlyweekdayRides.size(); index++) {
         cout << "   " << index << ": ";
         cout << string(hourlyweekdayRides.at(index) * 50.0 / largestnumberofRides, '@') << endl;
         cout << string(hourlyweekendRides.at(index) * 50.0 / largestnumberofRides, '+') << endl;
//This will create a 50 column graph depiciting weekday vs weekend rides through the @ and + symbols
      }

   }
}

