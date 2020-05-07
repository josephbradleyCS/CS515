/* These are test for the queue inerface methods using Google Test */
#include "queue.h"
#include <gtest/gtest.h>
#include <iostream>
using namespace std;

TEST(queueTest, constructorCreatesEmptyQueue)
{
    queue testQ;
    EXPECT_EQ(0, testQ.size());
    EXPECT_TRUE(testQ.empty());
}

/* Helper function for tests that follow */
void enqueueValues(queue &testQ, int startValue, int howMany)
{
   for (int i = 0; i < howMany; i++)
   {
       testQ.enqueue(startValue);
       startValue += 2;
   }
}

TEST(queueTest, enqueueSixItemsHasRightSize)
{
    queue testQ;
    enqueueValues(testQ, 2, 6);
    EXPECT_EQ(6, testQ.size());
    EXPECT_FALSE(testQ.empty());
    //cout << "Hi" << endl;
    //testQ.dump(cout);



}

TEST(queueTest, dequeueItemsHasRightValuesAndSize)
{
    queue testQ;
    int result;
    enqueueValues(testQ, 2, 6);

    //testQ.dump(cout); cout << endl;

    result = testQ.dequeue();
    EXPECT_EQ(2, result);
    //cout << "1" << endl;
    EXPECT_EQ(5, testQ.size());
    //cout << "2" << endl;
    EXPECT_FALSE(testQ.empty());
    //cout << "3" << endl;
    result = testQ.dequeue();
    //cout << "4" << endl;

    //testQ.dump(cout);
    EXPECT_EQ(4, result);
    //cout << "5" << endl;
    EXPECT_EQ(4, testQ.size());
    EXPECT_FALSE(testQ.empty());
}

TEST(queueTest, dequeueAfterMultipleEnqueueDequeue)
{
    queue testQ;
    //cout << "1" << endl;
    enqueueValues(testQ, 2, 6);
    //cout << "2" << endl;
    testQ.dequeue();
    //cout << "3" << endl;
    testQ.dequeue();
    //cout << "4" << endl;
    enqueueValues(testQ, 14, 6);

    //cout << "Looks like we made it" << endl;
    //testQ.dump(cout); cout << endl;
    EXPECT_EQ(6, testQ.dequeue());
    //cout << "6" << endl;
    EXPECT_EQ(8, testQ.dequeue());
    //cout << "7" << endl;
    EXPECT_EQ(8, testQ.size());
    //cout << "8" << endl;

}

TEST(queueTest, dumpAfterMultipleEnqueueDequeue)
{
    queue testQ;
    enqueueValues(testQ, 2, 6);
    testQ.dequeue();
    testQ.dequeue();
    enqueueValues(testQ, 14, 6);
    testQ.dequeue();
    testQ.dequeue();
    //testQ.dump(cout);
}

TEST(queueTest, enqueueDequeuePatternDumpsCorrectly)
{
    queue testQ;
    enqueueValues(testQ, 2, 6);
    for (int i = 0; i < 10000; i++)
    {
       testQ.dequeue();
       testQ.enqueue(i);
    }
    EXPECT_EQ(6, testQ.size());
    // testQ.dump(cout);
}

TEST(queueTest, dequeueAllLeavesEmpty)
{
    queue testQ;
    enqueueValues(testQ, 2, 6);
    testQ.dequeue();
    testQ.dequeue();
    enqueueValues(testQ, 14, 6);
    //cout << "testQ values prior to emptying: ";
    for (int i = 0; i < 10; i++) {
        testQ.dequeue();
    }
    //cout << endl;
    EXPECT_EQ(0, testQ.size());
    EXPECT_TRUE(testQ.empty());
    EXPECT_THROW(testQ.dequeue(), EmptyQueueException);
}

TEST(queueTest, enqueueAfterDequeueToEmptyWorks)
{
    queue testQ;
    enqueueValues(testQ, 2, 6);
    testQ.dequeue();
    testQ.dequeue();
    enqueueValues(testQ, 14, 6);
    for (int i = 0; i < 10; i++)
       testQ.dequeue();
    testQ.enqueue(20);
    EXPECT_EQ(1, testQ.size());
}

TEST(queueTest, copyConstructorMakesCorrectSize)
{
    queue q1;
    enqueueValues(q1, 2, 6);

    queue q2(q1);
    EXPECT_EQ(6, q2.size());
}

TEST(queueTest, copyConstructorMakesSeparateCopy)
{
    queue q1;
    enqueueValues(q1, 2, 6);

    queue q2(q1);
    q1.dequeue();
    q2.enqueue(15);
    EXPECT_EQ(5, q1.size());
    EXPECT_EQ(7, q2.size());
}

TEST(queueTest, assignmentOperatorMakesCorrectSize)
{
    queue q1;
    cout << "1" << endl;
    enqueueValues(q1, 2, 6);
    cout << "2" << endl;
    queue q2(q1);
    cout << "3" << endl;
    q1.dequeue();
    cout << "4" << endl;
    q2.enqueue(15);
    cout << "5" << endl;
    q1 = q2;
    cout << "6" << endl;
    EXPECT_EQ(7, q1.size());
    cout << "7" << endl;
}

TEST(queueTest, assignmentWithManyItemsHasCorrectValues)
{
    int i;
    queue q1;
    const int bigValue = 1050;
    for (i = 0; i < bigValue; i++)
        q1.enqueue(i);
    EXPECT_EQ(bigValue, q1.size());

    queue q2;
    q2 = q1;
    EXPECT_EQ(bigValue, q2.size());
    for (i = 0; i < bigValue - 1; i++)
        EXPECT_EQ(i, q2.dequeue());
    EXPECT_EQ(1, q2.size());
    EXPECT_EQ(bigValue, q1.size());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}
