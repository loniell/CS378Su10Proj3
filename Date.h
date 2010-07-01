// ------------------------
// projects/c++/date/Date.h
// Copyright (C) 2010
// Glenn P. Downing
// ------------------------

#ifndef Date_h
#define Date_h

// --------
// includes
// --------

#include <cassert>   // assert
#include <iostream>  // ostream
#include <stdexcept> // invalid_argument
#include <utility>   // !=, <=, >, >=

/*
namespace std     {
namespace rel_ops {

template <typename T>
inline bool operator != (const T& lhs, const T& rhs) {
    return !(lhs == rhs);}

template <typename T>
inline bool operator <= (const T& lhs, const T& rhs) {
    return !(rhs < lhs);}

template <typename T>
inline bool operator > (const T& lhs, const T& rhs) {
    return (rhs < lhs);}

template <typename T>
inline bool operator >= (const T& lhs, const T& rhs) {
    return !(lhs < rhs);}

} // rel_ops
} // std;
*/

// -----
// using
// -----

using namespace std::rel_ops;

// ----
// Date
// ----

template <typename T>
class Date {
    public:
        // ----------
        // operator +
        // ----------

        /**
         * <your documentation>
         * @throws invalid_argument if the resulting date precedes 1 Jan 1600
         */
        friend Date operator + (Date lhs, const T& rhs) {
            return lhs += rhs;}

        // ----------
        // operator -
        // ----------

        /**
         * <your documentation>
         * @throws invalid_argument if the resulting date precedes 1 Jan 1600
         */
        friend Date operator - (Date lhs, const T& rhs) {
            return lhs -= rhs;}

        // -----------
        // operator <<
        // -----------

        /**
         * @param  lhs an ostream
         * @param  rhs a date
         * @return the ostream
         * output a string representation of the date (e.g. "3 Feb 2008")
         * you can loop through an array of month names
         */
        friend std::ostream& operator << (std::ostream& lhs, const Date& rhs) {
            // <your code>
            return lhs << "1 Jan 2008";}

    private:
        // ----
        // data
        // ----
        // <your data>
        int days;
        int my_year;

    private:
        // -----
        // valid
        // -----

        /**
         * <your documentation>
         */
        bool valid () const {
            // <your code>
            return true;}

        // -----------
        // constructor
        // -----------

        /**
         * @param days >= 0
         * Date(0) -> 1 Jan 1600
         * you can loop through an array of month days
         */
        Date (const T& days) {
            assert(days >= 0);
            // <your code>
            if (!valid())
                throw std::invalid_argument("Date::Date()");}

        // -------
        // to_days
        // -------

        /**
         * @return the number of days since 1 Jan 1600, >= 0
         * 1 Jan 1600 -> 0
         */
        T to_days () const {
            T days = 0;
            // <your code>
            assert(days >= 0);
            return days;}

    public:
        // -----------
        // constructor
        // -----------

        /**
         * @param  day   >= 1 && <= 31
         * @param  month >= 1 && <= 12
         * @param  year  >= 1600
         * @throws invalid_argument if the resulting date is invalid
         */
        Date (const T& day, const T& month, const T& year) {
            my_year = (int) year;
            days = 0;
            int currentyear = 1600;
            int currentmonth = 1;
            int daysin_givenyear = 0;
            int month_in_givenyear = 1;
            while(month_in_givenyear < month)
            {
            	if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
            		daysin_givenyear += 31;
            	else if(month == 4 || month == 6 || month == 9 || month == 11)
            		daysin_givenyear += 30;
            	else //february
            	{
            		if((year % 4 == 0 && year % 100 != 0) ||(year %4 == 0 year % 400 == 0))
            			daysin_givenyear += 29;
            		else
            			daysin_givenyear += 28;
            	}
            	++month_in_givenyear;
            }
            daysin_givenyear += day;
            --year;
            while(currentyear < year)
            {
            	if(currentyear % 4 != 0 || (currentyear % 4 == 0 && currentyear % 100 == 0 && currentyear %400 != 0)))
            		days+= 365;
            	else if(currentyear %4 == 0 && currentyear % 400 == 0)
            		days += 366;
            	++currentyear;
            }
            days += daysin_givenyear;
            if (!valid())
                throw std::invalid_argument("Date::Date()");

        }

        // Default copy, destructor, and copy assignment.
        // Date (const Date&);
        // ~Date ();
        // Date& operator = (const Date&);

        // -----------
        // operator ==
        // -----------

        /**
         * <your documentation>
         */
        bool operator == (const Date& rhs) const {
            // <your code>
            return false;}

        // ----------
        // operator <
        // ----------

        /**
         * <your documentation>
         */
        bool operator < (const Date& rhs) const {
            // <your code>
            return false;}

        // -----------
        // operator +=
        // -----------

        /**
         * <your documentation>
         * @param  days the number of days to add (may be negative!)
         * @return the date resulting from adding days
         * @throws invalid_argument if the resulting date precedes 1 Jan 1600
         */
        Date& operator += (const T& days) {
            // <your code>
            return *this;}

        // -----------
        // operator -=
        // -----------

        /**
         * <your documentation>
         * @param  days the number of days to subtract (may be negative!)
         * @return the date resulting from subtracting days
         * @throws invalid_argument if the resulting date precedes 1 Jan 1600
         */
        Date& operator -= (const T& days) {
            // <your code>
            return *this;}

        // ----------
        // operator -
        // ----------

        /**
         * <your documentation>
         * @return the number of days between the dates (lhs - rhs)
         */
        T operator - (const Date& rhs) const {
            // <your code>
            return 0;}

        // ---------
        // leap_year
        // ---------

        /**
         * <your documentation>
         */
        bool leap_year () const {
            // <your code>
            return false;}};

#endif // Date_h
