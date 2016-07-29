#include <gtest/gtest.h>
#include "../src/Matrix.hpp"


TEST(ConstructorTest, Dimensions) {
	Matrix* m = new Matrix(2, 2);
	ASSERT_EQ(2, m->getDimensions().rows);
	ASSERT_EQ(2, m->getDimensions().columns);
}

TEST(ConstructorTest, Zeroes) {
	Matrix* m = new Matrix(4, 4);
	EXPECT_EQ(0, m->getEntry(1, 1)) << "Failed on 1,1";		
	EXPECT_EQ(0, m->getEntry(1, 2)) << "Failed on 1,2";		
	EXPECT_EQ(0, m->getEntry(1, 3)) << "Failed on 1,3";		
	EXPECT_EQ(0, m->getEntry(1, 4)) << "Failed on 1,4";		
	EXPECT_EQ(0, m->getEntry(2, 1)) << "Failed on 2,1";		
	EXPECT_EQ(0, m->getEntry(2, 2)) << "Failed on 2,2";		
	EXPECT_EQ(0, m->getEntry(2, 3)) << "Failed on 2,3";		
	EXPECT_EQ(0, m->getEntry(2, 4)) << "Failed on 2,4";		
	EXPECT_EQ(0, m->getEntry(3, 1)) << "Failed on 3,1";		
	EXPECT_EQ(0, m->getEntry(3, 2)) << "Failed on 3,2";		
	EXPECT_EQ(0, m->getEntry(3, 3)) << "Failed on 3,3";		
	EXPECT_EQ(0, m->getEntry(3, 4)) << "Failed on 3,4";		
	EXPECT_EQ(0, m->getEntry(4, 1)) << "Failed on 4,1";		
	EXPECT_EQ(0, m->getEntry(4, 2)) << "Failed on 4,2";		
	EXPECT_EQ(0, m->getEntry(4, 3)) << "Failed on 4,3";		
	EXPECT_EQ(0, m->getEntry(4, 4)) << "Failed on 4,4";		
}
