#include <iomanip>
#include "report.h"
#include "analysis.h"
#include "grid.h"

void print_report(const Station* stations, const double* temps, int rows, int cols) {
     std::cout <<  "=== Weather Station Report ===\n";
    
        int row = 0; 
    for (int row = 0; row < rows; ++row){
        double avg = 0.0;
        if(station_average(temps, rows, cols, row, avg)) {
           std::cout << std::left << std::setw(15) << stations[row].name
                     << std::right << std::setw(6) << static_cast<int>(stations[row].elevation_ft) << " ft"
                     << "   avg " << std::fixed << std::setprecision(2) << std::setw(6) << avg << " F\n";    

        }
    }
  
    int hot_row = 0;
    int hot_col = 0;
    if (find_hottest(temps, rows, cols, hot_row, hot_col)) {
        int i = grid_index(hot_row, hot_col, cols);
        std::cout << "Hottest reading: " << std::fixed << std::setprecision(1) << 
        temps[i]  << " F at " << stations[hot_row].name
                  << " (day " << (hot_col + 1) << ")\n";
    }
}
