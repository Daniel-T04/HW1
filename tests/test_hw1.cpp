#include <gtest/gtest.h>
#include "grid.h"
#include "analysis.h"
#include "station.h"

TEST(GridTest, GridIndex) {
    //Verify the row major formula: (row * cols + col) 
    EXPECT_EQ(grid_index(0, 0, 7), 0);
    EXPECT_EQ(grid_index(0, 6, 7), 6);
    EXPECT_EQ(grid_index(1, 0, 7), 7);
    EXPECT_EQ(grid_index(2, 3, 7), 17);
}

TEST(GridTest, InBounds) {
    // Vaild standard location
    EXPECT_TRUE(in_bounds(1, 2, 4, 7));

    // Vaild corner boundaries
    EXPECT_TRUE(in_bounds(0, 0, 4, 7));
    // Out of bounds: if row/col equal to or exceeding total dimensions
    EXPECT_FALSE(in_bounds(4, 2, 4, 7)); 
    EXPECT_FALSE(in_bounds(1, 7, 4, 7)); 
    // Out of bounds: negative indices
    EXPECT_FALSE(in_bounds(-1, 2, 4, 7));
    EXPECT_FALSE(in_bounds(1, -1, 4, 7));
}



TEST(AnalysisTest, StationAverage) {
    const double test_temps[6] = {
        90.0, 92.0, 94.0,  // Row 0 (Station 0)
        80.0, 85.0, 90.0  // Row 1 (Station 1)
    };

    double avg = -999.0;

    // Tests valid station average calculation
    EXPECT_TRUE(station_average(test_temps, 2, 3, 0, avg));
    EXPECT_DOUBLE_EQ(avg, 92.0);

    // Tests out of bounds station index failure
    avg = -999.0;
    EXPECT_FALSE(station_average(test_temps, 2, 3, 5, avg));
    EXPECT_DOUBLE_EQ(avg, -999.0);
}

TEST(AnalysisTest, DayAverage) {
    const double test_temps[6] = {
        90.0, 92.0, 94.0, // Station 0
        80.0, 86.0, 90.0 // Station 1
    };

    double avg = -999.0;

    // Test valid day average calculation (Column 1)
    EXPECT_TRUE(day_average(test_temps, 2, 3, 1, avg));
    EXPECT_DOUBLE_EQ(avg, 89.0);

    // Tests invaild negative day index failure
    avg = -999.0;
    EXPECT_FALSE(day_average(test_temps, 2, 3, -1, avg));
    EXPECT_DOUBLE_EQ(avg, -999.0);
}

TEST(AnalysisTest, FindHottest) {

     const double test_temps[6] = {
        90.0, 98.5, 94.0,  // Row 0
        98.5, 85.0, 90.0   // Row 1
    };

    
    int hot_row = -1;
    int hot_col = -1;

     // Verify first occurrence of max value is return 0 or 1
    EXPECT_TRUE(find_hottest(test_temps, 2, 3, hot_row, hot_col));
    EXPECT_EQ(hot_row, 0);
    EXPECT_EQ(hot_col, 1);

     // Verify handling of invaild grid dimensions (0 rows)
    hot_row = -1;
    hot_col = -1;
    EXPECT_FALSE(find_hottest(test_temps, 0, 3, hot_row, hot_col));
    EXPECT_EQ(hot_row, -1);
    EXPECT_EQ(hot_col, -1);
}

TEST(AnalysisTest, CountAbove) {
    const double test_temps[6] = {
        90.0, 95.0, 96.2, // strictly above 95.0
        88.1, 95.0, 91.0 // 95.0 is not  strictly above 95.0
    };

    // Verify structly greater than logic (count should be 1)
    EXPECT_EQ(count_above(test_temps, 2, 3, 95.0), 1);

    // Verify safety check for nullptr input
    EXPECT_EQ(count_above(nullptr, 2, 3, 90.0), 0);
}

TEST(StationTest, FindStationSuccessAndNotFound) {
    Station test_stations[3] = {
        {"Alpha", 1200.0},
        {"Beta", 850.5},
        {"Gamma", 2100.0}
    };

    // Valid lookup matching exact name
    const Station* match = find_station(test_stations, 3, "Beta");
    ASSERT_NE(match, nullptr);
    EXPECT_EQ(match->name, "Beta");
    EXPECT_DOUBLE_EQ(match->elevation_ft, 850.5);

    // Case senitivity test ("beta vs "Beta")
    EXPECT_EQ(find_station(test_stations, 3, "beta"), nullptr);

    // Non-existent station search
    EXPECT_EQ(find_station(test_stations, 3, "Delta"), nullptr);
}

TEST(StationTest, FindStationInvalidInputs) {
    Station test_stations[1] = {{"Alpha", 1000.0}};

    // Verify safety handling for nullptr, zero size, and negative side 
    EXPECT_EQ(find_station(nullptr, 1, "Alpha"), nullptr);
    EXPECT_EQ(find_station(test_stations, 0, "Alpha"), nullptr);
    EXPECT_EQ(find_station(test_stations, -1, "Alpha"), nullptr);
}
