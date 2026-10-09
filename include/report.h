#ifndef REPORT_H
#define REPORT_H

#include "station.h"

/**
* @brief Print the complete summary report including station details, temperature grid,
*  station averages, and the hottest reading location.
* @param stations Array of Station structs containing name and elevation.
* @param temps Pointer to 1D Temperature array.
* @param rows Total number of stations (rows)
* @param cols Total number of days (columns).
*/

void print_report(const Station* stations, const double* temps, int rows, int cols);

#endif
