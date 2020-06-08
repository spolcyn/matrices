#include <gtest/gtest.h>
#include "../src/Matrix.hpp"
#include "../src/MatrixOperations.hpp"
#include <cstdlib>
#include <chrono>

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

TEST(ConstructorTest, CopyConstructor)
{
	Matrix* original = new Matrix(3, 3);
	Matrix* copy = new Matrix(*original);

	EXPECT_NE(&(original->getDimensions()), &(copy->getDimensions()));

}

TEST(OperationsTest, RREF)
{
    //Matrix* expected = new Matrix(2, 2);
    Matrix* rref = new Matrix(2, 2);

    rref->editEntry(1, 1, 2);
    rref->editEntry(1, 2, 7);
    rref->editEntry(2, 1, 9);
    rref->editEntry(2, 2, 16);

    /*rref = &MatrixOperations::rref(rref);

    expected->editEntry(1, 1, 1);
    expected->editEntry(1, 2, 0);
    expected->editEntry(2, 1, 0);
    expected->editEntry(2, 2, 1);
    

    EXPECT_EQ(rref, expected);
    */
}

TEST(ThroughputTest, Add)
{
    int MATRIX_ROW = 5;
    int MATRIX_COL = 5;

    Matrix* m = new Matrix(MATRIX_ROW, MATRIX_COL);
    
    for(int i = 1; i <= MATRIX_ROW; i++) {
        for(int j = 1; j <= MATRIX_COL; j++) {
            m->editEntry(i, j, rand());
        }
    }

    auto start = std::chrono::steady_clock::now();

    // this throughput test is probably semi non-realistic given that it'll 
    // likely always cache hit
    int MAX_TRIALS = 1000000;
    for(int i = 0; i < MAX_TRIALS; i++) {
        MatrixOperations::add(*m, *m);
    }

    auto end = std::chrono::steady_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

    EXPECT_LT(elapsed, 1);
}


    



