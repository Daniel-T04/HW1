#include <iostream>
#include <string>
#include "station.h"
#include "report.h"
#include "analysis.h"

int main() {
    //grid dimensions for stations as rows and days as columns
    constexpr int station_count = 4;
    constexpr int day_count = 7;
        
        //Details about the Station array
    const Station stations[station_count] = {
        {"Denton", 642.0},
        {"Fort Worth", 653.0},
        {"Waco", 470.0},
        {"Amarillo", 3605.0},
    };
       //Array storing temparature data per station per day 
    const double temps[station_count * day_count] = {
        91.2, 93.5, 95.0, 97.8, 96.1, 92.4, 90.3,   // Denton
        92.0, 94.1, 96.4, 98.6, 97.2, 93.0, 91.5,   // Fort Worth
        93.4, 95.2, 97.9, 99.3, 98.1, 94.6, 92.8,   // Waco
        84.5, 86.0, 88.2, 90.7, 89.9, 85.3, 83.6,   // Amarillo
    };

       //Display summary table and hottest station details
    print_report(stations, temps, station_count, day_count);

    //Count and output temperature reading striclty above 95.0 degrees
    int above_95 = count_above(temps, station_count, day_count, 95.0);
    std::cout << "Readings above 95.0 F: " << above_95 << "";

    // Prompts user for interactive stations 
    std::cout << "Station to look up: ";
    std::string input_name;
    std::getline(std::cin, input_name);

    //Searches for station matching input string
    const Station* matched_station = find_station(stations, station_count, input_name);

    if (matched_station != nullptr) {
 
           //Compute the row index via pointer 
        int row_index = static_cast<int>(matched_station - stations);
        double avg = 0.0;
        
        //Calculate and print the average temperature for matched station
        if (station_average(temps, station_count, day_count, row_index, avg)) {
           std::cout << matched_station->name << " average: " << avg << " F";
        }
    } else {
        std::cout << "No station named \"" << input_name << "\".\n";
 }

    return 0;
}   
