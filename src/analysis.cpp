#include "analysis.h"
#include "grid.h"

bool station_average(const double* temps, int rows, int cols, int station, double& average) {
    if (temps == nullptr || cols <= 0  || !in_bounds(station, 0, rows, cols)) {
        return false;
    }

    double sum = 0.0;
    for (int col = 0; col < cols; ++col){
        int i = grid_index(station, col, cols);
        sum += temps[i];
    }
    
    average = sum / cols;
    return true;

}

bool day_average(const double* temps, int rows, int cols, int day, double& average) {
    if(temps == nullptr || rows <= 0 || !in_bounds(0, day, rows, cols)){
        return false;
     }

    double sum = 0.0;
    for (int row = 0; row < rows; ++row) {
        int i = grid_index(row, day, cols);
        sum += temps[i];
    }

    average = sum / rows;
    return true;

}

bool find_hottest(const double* temps, int rows, int cols, int& hot_row, int& hot_col) {
 if (temps == nullptr || rows <=0 || cols <= 0) {
    return false;
 }

int max_r = 0;
    int max_c = 0;
    double max_temp = temps[grid_index(0, 0, cols)];

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            int i = grid_index(r, c, cols);
            if (temps[i] > max_temp) {
                max_temp = temps[i];
                max_r = r;
                max_c = c;
            }
        }
    }

    hot_row = max_r;
    hot_col = max_c;
    return true;

}

int count_above(const double* temps, int rows, int cols, double threshold){
    if (temps == nullptr || rows <= 0 || cols <= 0) {
        return 0;
    }

 int count = 0;
 for (int r = 0; r < rows; ++r){
    for (int c = 0; c < cols; ++c){
        int i = grid_index(r, c, cols);
        if (temps[i] > threshold) {
            count++;

       }
    }   
 }

return count;

}

