// Created by Samvel Khalatyan on Dec 2, 2013
// Copyright (c) 2013 Samvel Khalatyan. All rights reserved
//
// Use of this source code is governed by a MIT-style license that can be
// found in the LICENSE file.
//
// (*1.5)   Define a table of the names of months of the year and the number
//          of days in each month. Write out that table. Do this twice; once
//          using an array of char for the names and an array for the number
//          of days and once using an array of structures, with each structure
//          holding the name of a month and the number of days in it.

#include <iomanip>
#include <iostream>
#include <type_traits>

using std::cout;
using std::endl;
using std::setw;

namespace solution1
    // two arrays: one array for months and one array for days per month
    //
    // this is a very low level month/day association. One could use a higher
    // level structure, say MonthDayInterator, that would combine the two
    // arrays and synchroniously traverse both, extract values, etc.
    //
    // It mainly lacks access control: programmer has to make sure that he
    // always access' two arrays with the same index.
    //
{
    void run()
    {
        cout << "-- tow arrays: one with names, another with days" << endl;

        const char *months[] {
            "January", "February",
            "March", "April", "May",
            "June", "July", "August",
            "September", "October", "November",
            "December"
        };

        const short days[] {
            31, 28,
            31, 30, 31,
            30, 31, 31,
            30, 31, 30,
            31
        };

        // print months in customizable range
        //
        int from {2};
        int till {10};

        cout << "print months in range ["
            << months[from] << ","
            << months[till] << ')' << endl;

        // print each month in range... let's rock and roll
        //
        for(int i {0}, index {from}; till > index; ++index, ++i)
        {
            cout << setw(2) << i <<
                "| " << days[index] <<
                ": " << months[index] << endl;
        }

        cout << endl;
    }
}

namespace solution2
    // an array of structures holding the name and number of days
    //
    // Month enumeration lists all months. Based on the value of the month
    // day(...) function creates Month/Days object.
{
    enum class Month : unsigned char
        // declare all month constants
    {
        jan, feb,
        mar, apr, may,
        jun, jul, aug,
        sep, oct, nov,
        dec
    };

    // extract Month underlying type for use in increment operator
    //
    using month_type = std::underlying_type<Month>::type;

    Month &operator +=(Month &m, const month_type i)
        // increase month value by N: no range check
    {
        // one could expand this function and check resulting month for
        // validity: we skip it here for simplicity
        //
        return m = static_cast<Month>(static_cast<month_type>(m) + i);
    }

    struct MonthDays
        // associate month name with days
    {
        const char *name;
        short days;
    };

    std::ostream &operator <<(std::ostream &os, const MonthDays &md)
        // nice print of the month name and days
    {
        return os << md.days << ": " << md.name;
    }

    MonthDays days(const Month &month)
        // convert Month enumeration to MonthDays
    {
        switch(month)
        {
            case Month::jan: return MonthDays{"January", 31};
            case Month::feb: return MonthDays{"Februray", 28};
            case Month::mar: return MonthDays{"March", 31};
            case Month::apr: return MonthDays{"April", 30};
            case Month::may: return MonthDays{"May", 31};
            case Month::jun: return MonthDays{"June", 30};
            case Month::jul: return MonthDays{"July", 31};
            case Month::aug: return MonthDays{"August", 31};
            case Month::sep: return MonthDays{"September", 30};
            case Month::oct: return MonthDays{"October", 31};
            case Month::nov: return MonthDays{"November", 30};
            case Month::dec: return MonthDays{"December", 31};

            // use default in case invalid month is constructed
            default: throw std::invalid_argument("unsupported month");
        }
    }

    class MonthGenerator
        // generate sequence of months for a range-based for
        //
        // generator can be configured to generate months in rage [from,to)
        //
    {
        public:
            class Iterator
            {
                public:
                    Month operator *() const { return _month; }

                    bool operator !=(const Iterator &iter) const
                    {
                        return iter._month != _month;
                    }

                    Iterator &operator++()
                    {
                        _month += 1;

                        return *this;
                    }

                private:
                    friend MonthGenerator;

                    Iterator(const Month &month):
                        _month{month}
                    {}

                    Month _month;
            };

            // note that months are generated in range [from,to)
            //
            MonthGenerator(const Month &from=Month{},
                           const Month &to=static_cast<Month>(
                               static_cast<month_type>(Month::dec) + 1)):
                _from{Iterator{from}},
                _to{Iterator{to}}
            {}

            Iterator begin() const { return _from; }
            Iterator end() const { return _to; }

        private:
            Iterator _from;
            Iterator _to;
    };

    void run()
    {
        cout << "-- an array of structures with month name and days" << endl;

        // customize generato boundaries
        //
        Month from_month {Month::mar};
        Month till_month {Month::nov};

        cout << "generate months in range ["
            << days(from_month).name << ","
            << days(till_month).name << ')' << endl;

        // prepare array
        //
        MonthDays months[static_cast<month_type>(till_month) -
                         static_cast<month_type>(from_month)];

        // let's generate months ... sugar
        //
        int i {0};
        for(const auto &m:MonthGenerator(from_month, till_month))
            months[i++] = days(m);

        // print generated month and confirm they make sense
        //
        i = 0;
        for(const auto &m:months)
            cout << setw(2) << i++ << "| " << m << endl;

        cout << endl;
    }
}

int main(int, char *[])
{
    solution1::run();
    solution2::run();
}
