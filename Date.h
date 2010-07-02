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
#include <typeinfo>

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
        	const char *months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        	if(rhs.valid())
        		return lhs << rhs.my_day << " " << months[(rhs.my_month -1)] << " " << rhs.my_year << "  -  " << days << " days since 1 Jan 1600" << std::endl;
        	else
        		return lhs << "This is not a valid date" << std::endl;

        }

    private:
        // ----
        // data
        // ----
        // <your data>
        static int days;
        static int my_month;
        static int my_day;
        static int my_year;

    private:
        // -----
        // valid
        // -----

        /**
         * <your documentation>
         */
        bool valid () const {
            if(my_month < 0 || my_month > 12 || my_day > 31 || my_day < 0 || my_year < 0)
            	return false;
            else if(my_day > 30 && (my_month == 4 || my_month == 6 || my_month == 9 || my_month == 11))
            	return false;
            else if(my_day > 29 && my_month == 2)
            	return false;
            else if(my_day > 28 && !leap_year())
            	return false;
            else if(my_year < 1600)
            	return false;
            return true;}

        // -----------
        // constructor
        // -----------

        /**
         * @param totaldays >= 0
         * Date(0) -> 1 Jan 1600
         * you can loop through an array of month days
         */
        Date (const T& totaldays)
        {
            assert(totaldays >= 0);
            days = (int) totaldays;
            int count = 0;
            int curmonth = 1;
            int curyear = 1600;
            int curday = 1;
            while(count < days)
            {
            	if(curday < 28)
            		++curday;
            	else if(curday == 28 && curmonth == 2 && (curyear % 4 != 0 || (curyear % 4 == 0 && curyear % 400 != 0)))//non-leap year end of february
            	{
            		curday = 1;
            		++curmonth;
            	}
            	else if(curday == 29 && curmonth == 2 && curyear % 4 == 0)
            	{//leap year end of february
            		curday = 1;
            		++curmonth;
            	}
            	else if(curday < 30)//only february needs to worry about 28/29 so can move on to day 30 in other 11 months
            		++curday;
            	else if(curday == 30 && (curmonth == 4 || curmonth == 6 || curmonth == 9 || curmonth == 11))
            	{//end of september, april, june, or november
            		curday = 1;
            		++ curmonth;
            	}
            	else if(curday == 30 && !(curmonth == 4 || curmonth == 6 || curmonth == 9 || curmonth == 11))
            		++curday;
            	else if(curday == 31 && curmonth == 12)
            	{//end of december and current year
            		curday = 1;
            		curmonth = 1;
            		++curyear;
            	}
            	else
            	{//end of the other 31 day months
            		curday = 1;
            		++curmonth;
            	}
            	++ count;
            }

            my_year = curyear;
            my_day = curday;
            my_month = curmonth;


            if (!valid())
                throw std::invalid_argument("Date::Date()");
        }

        // -------
        // to_days
        // -------

        /**
         * @return the number of days since 1 Jan 1600, >= 0
         * 1 Jan 1600 -> 0
         */
        T to_days () const {
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
            my_month = month;
            my_day = day;
            if (!valid())
            	throw std::invalid_argument("Date::Date()");
            int currentyear = 1600;
            int daysin_givenyear = 0;
            int month_in_givenyear = 1;
            int givenyear = year;
            while(month_in_givenyear < month)
            {
            	if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
            		daysin_givenyear += 31;
            	else if(month == 4 || month == 6 || month == 9 || month == 11)
            		daysin_givenyear += 30;
            	else //february
            	{
            		if( (year % 4 == 0 && year % 100 != 0) || (year %4 == 0 && year % 400 == 0) )
            			daysin_givenyear += 29;
            		else
            			daysin_givenyear += 28;
            	}
            	++month_in_givenyear;
            }
            daysin_givenyear += day;
            --givenyear;
            while(currentyear < year)
            {
            	if(currentyear % 4 != 0 || (currentyear % 4 == 0 && currentyear % 100 == 0 && currentyear %400 != 0))
            		days+= 365;
            	else if(currentyear %4 == 0 && currentyear % 400 == 0)
            		days += 366;
            	++currentyear;
            }
            days += daysin_givenyear;

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
            // current day = rhs.my_day
            // current month = rhs.my_month
            // current year = rhs.my_year

            if (my_day != rhs.my_day){
                return false;}
            if (my_month != rhs.my_month){
                return false;}
            if (my_year != rhs.my_year){
                return false;}

            return true;}

        // ----------
        // operator <
        // ----------

        /**
         * <your documentation>
         */
        bool operator < (const Date& rhs) const {
            // current day = rhs.my_day
            // current month = rhs.my_month
            // current year = rhs.my_year

            if (my_year < rhs.my_year){
                return true;}
            if (my_year > rhs.my_year){
                return false;}
            if (my_year == rhs.my_year){
                if (my_month > rhs.my_month){
                    return false;}
                if (my_month < rhs.my_month){
                    return true;}
                if (my_month == rhs.my_month){
                    if (my_day > rhs.my_day){
                        return false;}
                    if (my_day < rhs.my_day){
                        return true;}
                    if (my_day == rhs.my_day){
                        return false;}
                }
            }
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
         Date& operator += (const T& numberDays) {

             if (typeid(numberDays) == typeid(int)){
                 if (numberDays < 0){
                     *this -= -numberDays;
                 }
                 else{
                     int tempDays = days + numberDays;
                     Date<T> tempDate(tempDays);
                     *this = tempDate;
                 }
             }

             if (typeid(numberDays) == typeid(Date)){
                 if (Date<T>(numberDays).days < 0){
                     *this -= -Date<T>(numberDays).days;
                 }
                 else{
                     int tempDays = days + Date<T>(numberDays).days;
                     Date<T> tempDate(tempDays);
                     *this = tempDate;
                 }
             }

             if (!valid()){
                 throw std::invalid_argument("Date:: +=()");
             }

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
         Date& operator -= (const T& numberDays) {

             if (typeid(numberDays) == typeid(int)){
                 if (numberDays < 0){
                     *this += -numberDays;
                 }
                 else{
                     int tempDays = days - numberDays;
                     Date<T> tempDate(tempDays);
                     *this = tempDate;
                 }
             }

             if (typeid(numberDays) == typeid(Date)){
                 if (Date<T>(numberDays).days < 0){
                     *this += -Date<T>(numberDays).days;
                 }
                 else{
                     int tempDays = days - Date<T>(numberDays).days;
                     Date<T> tempDate(tempDays);
                     *this = tempDate;
                 }
             }

             if (!valid()){
                 throw std::invalid_argument("Date:: -=()");
             }

             return *this;}

         // ----------
         // operator -
         // ----------

         /**
          * <your documentation>
          * @return the number of days between the dates (lhs - rhs)
          */
         T operator - (const Date& rhs) const {
             int numDays = days - rhs.days;
             if (numDays < 0){
                 numDays = -numDays;
             }
             return numDays;}


        // ---------
        // leap_year
        // ---------

        /**
         * <your documentation>
         */
        bool leap_year () const {
        	if(my_year % 4 != 0)
        		return false;
        	else if(my_year %4 == 0 && my_year % 400 == 0)
        		return true;
        	return false;
        }
};

#endif // Date_h
