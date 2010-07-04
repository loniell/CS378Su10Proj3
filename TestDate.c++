// --------------------------
// projects/date/TestDate.c++
// Copyright (C) 2010
// Glenn P. Downing
// --------------------------

/*
To test the program:
    % g++ -ansi -pedantic -lcppunit -ldl -Wall TestDate.c++ -o TestDate.app
    % valgrind TestDate.app >& TestDate.out
*/

// --------
// includes
// --------

#include <cstring>   // strcmp
#include <sstream>   // ostringstream
#include <stdexcept> // invalid_argument
#include <string>    // ==

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TestSuite.h"               // TestSuite
#include "cppunit/TextTestRunner.h"          // TestRunner

#include "Date.h"

// --------
// TestDate
// --------

struct TestDate : CppUnit::TestFixture {
    // ----------------
    // test_constructor
    // ----------------

    void test_constructor_1 () {
        try {
            const Date<int> x(0, 1, 1600);
            CPPUNIT_ASSERT(false);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(std::strcmp(e.what(), "Date()") == 0);}}
	
    void test_constructor_2 () {
        try {
            const Date<int> x(3, 6, 1924);
            CPPUNIT_ASSERT(true);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(std::strcmp(e.what(), "Date()") == 0);}}


    // -------------
    // test_equal_to
    // -------------

    void test_equal_to_1 () {
        try {
            const Date<int> x(28, 2, 2000);
            const Date<int> y(28, 2, 2000);
            CPPUNIT_ASSERT(x == y);
            CPPUNIT_ASSERT(!(x != y));}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
	
    void test_equal_to_2 () {
        try {
            const Date<int> x(29, 2, 1836);
            const Date<int> y(29, 2, 1836);
            CPPUNIT_ASSERT(x == y);
            CPPUNIT_ASSERT(!(x != y));}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
	
    void test_equal_to_3 () {
        try {
            const Date<int> x(1, 1, 1600);
            const Date<int> y(1, 1, 1600);
            CPPUNIT_ASSERT(x == y);
            CPPUNIT_ASSERT(!(x != y));}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
	
    void test_equal_to_4 () {
        try {
            const Date<int> x(3, 11, 1824);
            const Date<int> y(3, 12, 1824);
            CPPUNIT_ASSERT(x != y);
            CPPUNIT_ASSERT(!(x == y));}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
	
    void test_equal_to_5 () {
        try {
            const Date<int> x(5, 12, 2004);
            const Date<int> y(3, 12, 2004);
            CPPUNIT_ASSERT(x != y);
            CPPUNIT_ASSERT(!(x == y));}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
	
    void test_equal_to_6 () {
        try {
            const Date<int> x(3, 12, 3025);
            const Date<int> y(3, 12, 3024);
            CPPUNIT_ASSERT(x != y);
            CPPUNIT_ASSERT(!(x == y));}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    void test_equal_to_7 () {
        try {
            const Date<int> x(3, 12, 3025);
            const Date<int> y(3, 12, 3024);
            CPPUNIT_ASSERT(x != y);
            CPPUNIT_ASSERT(!(x == y));}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
	
    // ---------
    // test_less
    // ---------

    void test_less_1 () {
        try {
            const Date<int> x(4, 12, 2000);
            const Date<int> y(28, 2, 2340);
            CPPUNIT_ASSERT(x <  y);
            CPPUNIT_ASSERT(x <= y);
            CPPUNIT_ASSERT(!(x >  y));
            CPPUNIT_ASSERT(!(x >= y));}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
	
	void test_less_2 () {
        try {
            const Date<int> x(4, 12, 1999);
            const Date<int> y(4, 11, 1999);
            CPPUNIT_ASSERT(x >  y);
            CPPUNIT_ASSERT(x >= y);
            CPPUNIT_ASSERT(!(x <  y));
            CPPUNIT_ASSERT(!(x <= y));}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
	
	void test_less_3 () {
        try {
            const Date<int> x(4, 12, 1609);
            const Date<int> y(3, 12, 1609);
            CPPUNIT_ASSERT(x >  y);
            CPPUNIT_ASSERT(x >= y);
            CPPUNIT_ASSERT(!(x <  y));
            CPPUNIT_ASSERT(!(x <= y));}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
	
	void test_less_4 () {
        try {
            const Date<int> x(4, 12, 2000);
            const Date<int> y(4, 12, 4003);
            CPPUNIT_ASSERT(x <  y);
            CPPUNIT_ASSERT(x <= y);
            CPPUNIT_ASSERT(!(x >  y));
            CPPUNIT_ASSERT(!(x >= y));}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    // ---------
    // test_plus
    // ---------

    void test_plus_1 () {
        try {
            const Date<int> x(1, 1, 2000);
            const Date<int> y(1, 1, 2001);
            CPPUNIT_ASSERT(x + 366 == y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
	
	void test_plus_2 () {
        try {
            const Date<int> x(1, 1, 2001);
            const Date<int> y(1, 1, 2000);
            CPPUNIT_ASSERT(x + (-366) == y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
	
	void test_plus_3 () {
        try {
            const Date<int> x(1, 1, 1600);
            const Date<int> y(1, 1, 2000);
            CPPUNIT_ASSERT(x + 146097 == y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
	
	void test_plus_4 () {
        try {
            const Date<int> x(1, 1, 2000);
            const Date<int> y(1, 1, 2002);
            CPPUNIT_ASSERT(x + 731 == y);}		
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
	
	void test_plus_5 () {
        try {
            const Date<int> x(1, 1, 1600);
            const Date<int> y(1, 1, 2002);
            CPPUNIT_ASSERT(x + (-731) == y);}		
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(std::strcmp(e.what(), "-=()") == 0);}}

    // ----------
    // test_minus
    // ----------

    void test_minus_1 () {
        try {
            const Date<int> x(1, 1, 2000);
            const Date<int> y(1, 1, 2001);
            CPPUNIT_ASSERT(x - (-366) == y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
	
	void test_minus_2 () {
        try {
            const Date<int> x(1, 1, 2000);
            const Date<int> y(1, 1, 2002);
            CPPUNIT_ASSERT(y - 731 == x);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
	
	void test_minus_3 () {
        try {
            const Date<int> x(1, 1, 2000);
            const Date<int> y(1, 1, 1600);
            CPPUNIT_ASSERT(x - 146097 == y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
	
	void test_minus_4 () {
        try {
            const Date<int> x(1, 1, 2000);
            const Date<int> y(1, 1, 2001);
            CPPUNIT_ASSERT(y - 366 == x);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
	
	void test_minus_5 () {
        try {
            const Date<int> x(1, 1, 1600);
            const Date<int> y(1, 1, 2001);
            CPPUNIT_ASSERT(x - 366 == y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(std::strcmp(e.what(), "-=()") == 0);}}

    // -----------
    // test_output
    // -----------

    void test_output_1 () {
        try {
            const Date<int> x(16, 6, 2008);
            std::ostringstream out;
            out << x;
            CPPUNIT_ASSERT(out.str() == "16 Jun 2008");}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
	
	void test_output_2 () {
        try {
            const Date<int> x(29, 2, 2008);
            std::ostringstream out;
            out << x;
            CPPUNIT_ASSERT(out.str() == "29 Feb 2008");}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
	
	void test_output_3 () {
        try {
            const Date<int> x(1, 1, 1600);
            std::ostringstream out;
            out << x;
            CPPUNIT_ASSERT(out.str() == "1 Jan 1600");}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    // --------------
    // test_leap_year
    // --------------

    void test_leap_year_1 () {
        try {
            CPPUNIT_ASSERT(Date<int>(1, 1, 2000).leap_year());}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

	void test_leap_year_2 () {
        try {
            CPPUNIT_ASSERT(Date<int>(1, 1, 1600).leap_year());}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
	
	void test_leap_year_3 () {
        try {
            CPPUNIT_ASSERT(!(Date<int>(1, 1, 2003).leap_year()));}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}
	
    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestDate);
    CPPUNIT_TEST(test_constructor_1);
	CPPUNIT_TEST(test_constructor_2);
    CPPUNIT_TEST(test_equal_to_1);
	CPPUNIT_TEST(test_equal_to_2);
	CPPUNIT_TEST(test_equal_to_3);
	CPPUNIT_TEST(test_equal_to_4);
	CPPUNIT_TEST(test_equal_to_5);
	CPPUNIT_TEST(test_equal_to_6);
	CPPUNIT_TEST(test_equal_to_7);
    CPPUNIT_TEST(test_less_1);
	CPPUNIT_TEST(test_less_2);
	CPPUNIT_TEST(test_less_3);
	CPPUNIT_TEST(test_less_4);
    CPPUNIT_TEST(test_plus_1);
	CPPUNIT_TEST(test_plus_2);
	CPPUNIT_TEST(test_plus_3);
	CPPUNIT_TEST(test_plus_4);
	CPPUNIT_TEST(test_plus_5);
    CPPUNIT_TEST(test_minus_1);
	CPPUNIT_TEST(test_minus_2);
	CPPUNIT_TEST(test_minus_3);
	CPPUNIT_TEST(test_minus_4);
	CPPUNIT_TEST(test_minus_5);
    CPPUNIT_TEST(test_output_1);
	CPPUNIT_TEST(test_output_2);
    CPPUNIT_TEST(test_output_3);	
    CPPUNIT_TEST(test_leap_year_1);
	CPPUNIT_TEST(test_leap_year_2);
	CPPUNIT_TEST(test_leap_year_3);
    CPPUNIT_TEST_SUITE_END();};

// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false);  // turn off synchronization with C I/O
    cout << "TestDate.c++" << endl;

    CppUnit::TextTestRunner tr;
    tr.addTest(TestDate::suite());
    tr.run();

    cout << "Done." << endl;
    return 0;}
