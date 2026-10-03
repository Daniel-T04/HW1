#ifndef STATION_H
#define STATION_H

#include <string>

/**
* @brief Represents a weather with a name and elevation.
*/

struct Station {

    std::string name;
    double elevation_ft;
};


/**
* @brief Find the station whose name exactly matches the given string.
* @param stations Pointer to hte array of Station sturcts.
* @param count the Total number of stations in the array.
* @param name Exact case sensitive station name to search for.
* @return Pointer to the matching Station struct, or nullptr if not found or count <= 0.
*/
const Station* find_station(const Station* stations, int count, const std::string& name);

#endif
