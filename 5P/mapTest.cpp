/* These are test for map inerface methods using Google Test */
#include "map.h"
#include <gtest/gtest.h>
#include <iostream>
//#include
using namespace std;

//The constructor should create a map with zero size
TEST(MapTest, constructorCreatesZeroSizeMap) {

  Map m; // cout << "Map m declared\n";
  EXPECT_EQ(m.size(), 0);

  // delete m;
}

//Inserting into an empty map should return true and result in a size of one
TEST(MapTest, insertWhileEmptyReturnsTrueAndMapSizeIsOne) {
  Map m; // cout << "Map m declared\n";

  EXPECT_EQ(true, m.insert("a", "a"));
  EXPECT_EQ(m.size(), 1);
  // delete m;
}

//Inserting a key that already exists should fail and not change the map size
TEST(MapTest, insertOfSameKeyReturnsFalseAndMapSizeRemainsSame) {
  Map m; // cout << "Map m declared\n";
  EXPECT_EQ(m.size(), 0);

  m.insert("a", "a");
  EXPECT_EQ(m.size(), 1);

  EXPECT_FALSE(m.insert("a", "b"));

  EXPECT_EQ(m.size(), 1);
  // delete m;
}

//Accessing an existing item using [] should return correct value and not
//change the map size
TEST(MapTest, indexOperatorOfExistingKeyReturnsProperValueAndSizeIsSame) {
  Map m; // cout << "Map m declared\n";
  EXPECT_EQ(true, m.insert("a", "a"));
  EXPECT_EQ(m["a"], "a");
  EXPECT_EQ(m.size(), 1);
  // delete m;
}

//Using [] to set an item in an empty map should add the item with an
//appropriate value and increase the map size to one
TEST(MapTest, indexOperatorOnEmptyMapProperlySetsValueAndSizeIsOne) {
  Map m; // cout << "Map m declared\n";
  EXPECT_EQ(m.size(), 0);
  m["a"] = "b"; // FIXME
  EXPECT_EQ(m["a"], "b");

  EXPECT_EQ(m.size(), 1);


  // delete m;
}

//Using [] to set an item in a map that already contains other items
//inserts and updates the size appropriately
TEST(MapTest, indexOperatorOnMissingKeyProperlySetsValueAndIncrementsSize) {
  Map m; // cout << "Map m declared\n";

  EXPECT_TRUE(m.insert("a", "a"));
  EXPECT_TRUE(m.insert("b", "b"));

  EXPECT_EQ(m.size(), 2);

  m["c"] = "c"; // FIXME

  EXPECT_EQ(m.size(), 3);
  EXPECT_EQ(m["c"], "c");

  // delete m;
}

//Erasing a key that exists in the map succeeds and decrements the map size
TEST(MapTest, eraseOfExistingKeyReturnsTrueAndDecrementsSize) {

  Map m; // cout << "Map m declared\n";

  m.insert("a", "a");
  EXPECT_EQ(m.size(), 1);

  EXPECT_EQ(true, m.erase("a"));
  EXPECT_EQ(m.size(), 0);

  // delete m;
 m.erase("a");m.erase("b");
  //Map m; // cout << "Map m declared\n";

  m.insert("a", "a");
  m.insert("b", "b");

  EXPECT_EQ(m.size(), 2);

  m.erase("a");
  EXPECT_EQ(1, m.size());
  // delete m;

  //Map m; // cout << "Map m declared\n";
  m.erase("b");

  m.insert("a", "a");
  m.insert("b", "b");

  EXPECT_EQ(m.size(), 2);

  EXPECT_EQ(true, m.erase("b"));
  EXPECT_EQ(1, m.size());
  // delete m;
}

//Erase on an empty map fails and keeps the map size at zero
TEST(MapTest, eraseOnEmptyMapReturnsFalseAndSizeRemainsZero) {
  Map m; // cout << "Map m declared\n";
  EXPECT_EQ(false, m.erase("a"));
  EXPECT_EQ(0, m.size());
  // delete m;
}

//Erase of a non-existant key fails and does not change the map size
TEST(MapTest, eraseOfMissingKeyReturnsFalseAndSizeRemainsSame) {
  Map m; // cout << "Map m declared\n";

  m.insert("a", "a");
  m.insert("b", "b");

  EXPECT_EQ(false, m.erase("c"));
  EXPECT_EQ(2, m.size());

  // delete m;
}

//Using the copy constructor results in two maps of the same, correct size
TEST(MapTest, copyConstructorMakesCorrectSize) {
  Map m; // cout << "Map m declared\n";
  //Map n; // cout << "Map n declared\n";

  m.insert("a", "b");
  m.insert("b", "a");

  Map n(m);

  EXPECT_EQ(m.size(), n.size());
  EXPECT_EQ(2, n.size());

  // delete n;
  // delete m;
}

//Using the copy constructor with an existing   Map makes its own
//copy, such that if the value associated with a key is changed
//in the copy it does not change the associated value in the
//original, and inserts/erases on either won't affect the other.
TEST(MapTest, copyConstructorMakesSeparateCopy) {
  Map m; // cout << "Map m declared\n";
  EXPECT_EQ(m.size(), 0);
  m.insert("a", "b");
  m.insert("b", "a");
  EXPECT_EQ(m.size(), 2);

  Map n(m);
  EXPECT_EQ(n.size(), 2);

  n["a"] = "b";
  EXPECT_EQ(n["a"], "b");
  EXPECT_EQ(m["a"], "b");

  m.insert("v", "v");


  EXPECT_EQ(m.size(), 3);
  EXPECT_EQ(n.size(), 2);

  EXPECT_EQ(m["a"], "b");

  m.erase("a");

  EXPECT_EQ(m.size(), 2);
  EXPECT_EQ(n.size(), 2);

  EXPECT_EQ(n["a"], "b");
  n.erase("a");

  EXPECT_EQ(m.size(), 2);
  EXPECT_EQ(n.size(), 1);
}

//Using the assignment operator results in two maps of the same, correct size
TEST(MapTest, assignmentOperatorMakesCorrectSize) {


  Map m ; // cout << "Map m declared\n";
  m.insert("a", "a");

  Map n = m;
  // EXPECT_EQ(m.size(), n.size());
  // EXPECT_EQ(m.size(), 1);
  //
  // m.insert("b", "b");
  // m.insert("c", "c");
  // m.insert("d", "d");
  // m.insert("e", "e");


  //n = m;

  EXPECT_EQ(m.size(), n.size());
  EXPECT_EQ(m.size(), 1);




}

//Using the assignment operator with an existing   Map makes its own
//copy, such that if the value associated with a key is changed
//in the copy it does not change the associated value in the
//original, and inserts/erases on either won't affect the other.
TEST(MapTest, assignmentMakesSeparateCopy) {
  Map m ; // cout << "Map m declared\n";
  m.insert("a", "a");

  Map n = m;

  EXPECT_EQ(m.size(), n.size());

  n["a"] = "b";

  EXPECT_EQ("b", n["a"]);
  EXPECT_EQ("a", m["a"]);

  m.insert("c", "c");
  EXPECT_EQ(1, n.size());
  EXPECT_EQ(2, m.size());

  m.insert("d", "d");
  EXPECT_EQ(1, n.size());
  EXPECT_EQ(3, m.size());

  m.erase("c");
  m.erase("a");

  EXPECT_EQ(m.size(), n.size());
  EXPECT_EQ(m.size(), 1);
}

//Using the assignment operator with an existing map with over 1000 items
//makes a copy that has correct keys/values at a couple of places deep within
//the map (values that aren't at either end of the range of keys used).
TEST(MapTest, assignmentWithManyItemsHasCorrectValues) {
  Map m; // cout << "Map m declared\n";

  for (int i = 0; i < 1001; i++) {
    m.insert(to_string(i), to_string(i + 1));
  }

  Map n = m;

  EXPECT_EQ(n.size(), m.size());
  EXPECT_EQ(n.size(), 1001);



  EXPECT_EQ(n["50"], "51");
  EXPECT_EQ(n["105"], "106");
  EXPECT_EQ(n["500"], "501");
  EXPECT_EQ(n["755"], "756");
  EXPECT_EQ(n["831"], "832");
  EXPECT_EQ(n["900"], "901");

  EXPECT_EQ(m["50"], "51");
  EXPECT_EQ(m["105"], "106");
  EXPECT_EQ(m["500"], "501");
  EXPECT_EQ(m["750"], "751");
  EXPECT_EQ(m["800"], "801");
  EXPECT_EQ(m["900"], "901");

}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}
