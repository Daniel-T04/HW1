#include <iostream>
#include <iomanip>
#include "report.h"
#include "analysis.h"
#include "grid.h"

void print_report(const Station* stations, const double* temps, int rows, int cols) {
    if (stations == nullptr || temps == nullptr || rows <= 0 || cols <= 0) {
        return;
    }

    std::cout << std::fixed << std::setprecision(1);

    
    std::cout << std::left << std::setw(15) << "Station"
              << std::setw(12) << "Elev(ft)";


        std::cout << "Day " << std::left << std::setw(6) << (c + 1);
    }
    std::cout << std::setw(10) << "Average" << "\n";

    
    for (int r = 0; r < rows; ++r) {
        std::cout << std::left << std::setw(15) << stations[r].name
                  << std::setw(12) << stations[r].elevation_ft;

        for (int c = 0; c < cols; ++c) {
            int idx = grid_index(r, c, cols);
            std::cout << std::setw(10) << temps[i];
        }

        double avg = 0.0;
        if (station_average(temps, rows, cols, r, avg)) {
            std::cout << std::setw(10) << avg;
        }
        std::cout << "\n";
    }


    int hot_row = -1;
    int hot_col = -1;
    if (find_hottest(temps, rows, cols, hot_row, hot_col)) {
        int i = grid_index(hot_row, hot_col, cols);
        std::cout << "\nHottest: " << stations[hot_row].name
                  << " on Day " << (hot_col + 1)
                  << " (" << temps[i] << " deg F)\n";
    }
}
