#include <gtest/gtest.h>
#include "grid.h"

TEST(GridTest, GridIndex) {
    // 4 rows by 7 columns grid
    EXPECT_EQ(grid_index(0, 0, 7), 0);
    EXPECT_EQ(grid_index(0, 6, 7), 6);
    EXPECT_EQ(grid_index(1, 0, 7), 7);
    EXPECT_EQ(grid_index(2, 3, 7), 17);
}

TEST(GridTest, InBounds) {
    // Normal valid case
    EXPECT_TRUE(in_bounds(1, 2, 4, 7));

    // Boundary edge cases
    EXPECT_TRUE(in_bounds(0, 0, 4, 7));
    EXPECT_FALSE(in_bounds(4, 2, 4, 7)); // row == rows
    EXPECT_FALSE(in_bounds(1, 7, 4, 7)); // col == cols

    // Negative index edge cases
    EXPECT_FALSE(in_bounds(-1, 2, 4, 7));
    EXPECT_FALSE(in_bounds(1, -1, 4, 7));
}
