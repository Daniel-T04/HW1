#include <gtest/gtest.h>
#include "grid.h"
#include "analysis.h"
#include "station.h"

TEST(GridTest, GridIndex) {
    EXPECT_EQ(grid_index(0, 0, 7), 0);
    EXPECT_EQ(grid_index(0, 6, 7), 6);
    EXPECT_EQ(grid_index(1, 0, 7), 7);
    EXPECT_EQ(grid_index(2, 3, 7), 17);
}

TEST(GridTest, InBounds) {
    
    EXPECT_TRUE(in_bounds(1, 2, 4, 7));

    
    EXPECT_TRUE(in_bounds(0, 0, 4, 7));
    EXPECT_FALSE(in_bounds(4, 2, 4, 7)); 
    EXPECT_FALSE(in_bounds(1, 7, 4, 7)); 

   
    EXPECT_FALSE(in_bounds(-1, 2, 4, 7));
    EXPECT_FALSE(in_bounds(1, -1, 4, 7));
}



TEST(AnalysisTest, StationAverage) {
    
    const double test_temps[6] = {
        90.0, 92.0, 94.0,  
        80.0, 85.0, 90.0  
    };

    double avg = -999.0;

    
    EXPECT_TRUE(station_average(test_temps, 2, 3, 0, avg));
    EXPECT_DOUBLE_EQ(avg, 92.0);

    
    avg = -999.0;
    EXPECT_FALSE(station_average(test_temps, 2, 3, 5, avg));
    EXPECT_DOUBLE_EQ(avg, -999.0);
}

TEST(AnalysisTest, DayAverage) {
    const double test_temps[6] = {
        90.0, 92.0, 94.0,
        80.0, 86.0, 90.0
    };

    double avg = -999.0;

    
    EXPECT_TRUE(day_average(test_temps, 2, 3, 1, avg));
    EXPECT_DOUBLE_EQ(avg, 89.0);

    
    avg = -999.0;
    EXPECT_FALSE(day_average(test_temps, 2, 3, -1, avg));
    EXPECT_DOUBLE_EQ(avg, -999.0);
}

TEST(AnalysisTest, FindHottest) {

    const double test_temps[6] = {
        90.0, 98.5, 94.0,  
        98.5, 85.0, 90.0   
    };

    int hot_row = -1;
    int hot_col = -1;

   
    EXPECT_TRUE(find_hottest(test_temps, 2, 3, hot_row, hot_col));
    EXPECT_EQ(hot_row, 0);
    EXPECT_EQ(hot_col, 1);

    
    hot_row = -1;
    hot_col = -1;
    EXPECT_FALSE(find_hottest(test_temps, 0, 3, hot_row, hot_col));
    EXPECT_EQ(hot_row, -1);
    EXPECT_EQ(hot_col, -1);
}

TEST(AnalysisTest, CountAbove) {
    const double test_temps[6] = {
        90.0, 95.0, 96.2,
        88.1, 95.0, 91.0
    };

    
    EXPECT_EQ(count_above(test_temps, 2, 3, 95.0), 1);

    
    EXPECT_EQ(count_above(nullptr, 2, 3, 90.0), 0);
}

TEST(StationTest, FindStationSuccessAndNotFound) {
    Station test_stations[3] = {
        {"Alpha", 1200.0},
        {"Beta", 850.5},
        {"Gamma", 2100.0}
    };

    
    const Station* match = find_station(test_stations, 3, "Beta");
    ASSERT_NE(match, nullptr);
    EXPECT_EQ(match->name, "Beta");
    EXPECT_DOUBLE_EQ(match->elevation_ft, 850.5);

    
    EXPECT_EQ(find_station(test_stations, 3, "beta"), nullptr);

    
    EXPECT_EQ(find_station(test_stations, 3, "Delta"), nullptr);
}

TEST(StationTest, FindStationInvalidInputs) {
    Station test_stations[1] = {{"Alpha", 1000.0}};

   
    EXPECT_EQ(find_station(nullptr, 1, "Alpha"), nullptr);
    EXPECT_EQ(find_station(test_stations, 0, "Alpha"), nullptr);
    EXPECT_EQ(find_station(test_stations, -1, "Alpha"), nullptr);
}
