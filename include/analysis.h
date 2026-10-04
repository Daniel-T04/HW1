#ifndef ANALYSIS_H
#define ANALYSIS_H


/**
* @brief Calculate the average temperature for station over all days.
* @param temps Pointer to the array containing temperature readings.
* @param rows of Total number of stations (rows).
* @param cols of Total number of days (columns).
* @param station Index of the station (row) to average.
* @param average Reference to stored the calculated average if 
* successfull.
* @return true if station is in bounds and that cols > 0; otherwise 
* false.
*/ 
bool station_average(const double* temps, int rows, int cols, 
int station, double& average);

/**
* @brief Calculate the average temperature across all stations for a 
* specific day.
* @param temps Pointer to the array containing temperature readings.
* @param rows Total number of stations (rows).
* @param cols  Total number of days (columns).
* @param day Index of the day (column) to average.
* @param average Reference to store the calculated average 
* if successful. 
* @return true if day is it in bounds and rows > 0; otherwise false.
*/
bool day_average(const double* temps, int rows, int cols, int day, 
double& average);

/**
* @brief Find the highest temperature reading in the grid and its 
* row/column indices.
* @param temps Pointer to the array containing temperature readings.
* @param rows of Total numbers of stations (rows).
* @param cols of Total numbers of days (columns).
* @param hot_row gets Reference to store the row index of the hottest 
* reading.
* @param hot_col gets Reference to store the column index of the highest* reading.
* @return true if grid dimensions are valid if (rows > 0 and cols > 0);
* otherwise false
*/
bool find_hottest(const double* temps, int rows, int cols, int& hot_row, int& hot_col);

/**
* @brief Count the number of temperature reading strictly greater than 
* the threshold
* @param temps Pointer to the array containing temperature readings.
* @param rows from Number of stations (rows). 
* @param cols from Number of days (columns).
* @param threshold Temperature threshold to check against.
* @return The total number of readings greater than threshold. Return 
* 0 if grid is empty or invalid.
*/

int count_above(const double* temps, int rows, int cols, 
double threshold);


#endif 
