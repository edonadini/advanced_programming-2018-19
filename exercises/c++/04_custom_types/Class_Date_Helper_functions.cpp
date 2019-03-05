//
//  Class_Date_Helper_functions.cpp
//  
#include <iostream>
#include <string>

enum class month_enum { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };

class Date{
    unsigned short _day;
    month_enum _month;
    unsigned int _year;
    void add_one_day();
    const bool is_leap() const;
    
public:
    Date(const unsigned short& d, const month_enum& m, const unsigned int& y);//constructur
    ~Date() {}; //destructor
    
    const unsigned int day() const {return _day;}
    const month_enum month() const {return _month;} //const because do not modify the attribute
    const unsigned int year() const {return _year;}
    void add_days(const unsigned int& n);
    friend const bool operator==(const Date& d1, const Date& d2);
    friend const bool operator!=(const Date& d1, const Date& d2);
    friend std::ostream& operator<<(std::ostream& os, const Date& dat);
};

void Date::add_days(const unsigned int& n){
    for(auto i = 1u; i <=n; ++i)
    {
        add_one_day();
    }
}

void Date::add_one_day(){
    switch(this->_month){
        case month_enum::jan: case month_enum::mar: case month_enum::may: case month_enum::jul: case month_enum::aug: case month_enum::oct:
            if(_day==31){
                int new_month = (int) this->_month + 1;
                this->_month = (month_enum) new_month;
                _day=1;
            }
            else{
                _day=_day+1;
            }
            break;
        case month_enum::dec:
            if(_day==31){
                int new_month = (int) this->_month-11;
                this->_month = (month_enum) new_month;
                _day=1;
                _year=_year+1;
            }
            else{
                _day=_day+1;
            }
            break;
        case month_enum::apr: case month_enum::jun: case month_enum::sep: case month_enum::nov:
            if(_day==30){
                int new_month = (int) this->_month + 1;
                this->_month = (month_enum) new_month;
                _day=1;
            }
            else{
                _day=_day+1;
            }
            break;
        case month_enum::feb:
            if (is_leap()==true){
                if(_day==29){
                    int new_month = (int) this->_month + 1;
                    this->_month = (month_enum) new_month;
                    _day=1;
                }
                else{
                    _day=_day+1;
                }
            }
            else{
                if(_day==28){
                    int new_month = (int) this->_month + 1;
                    this->_month = (month_enum) new_month;
                    _day=1;
                }
                else{
                    _day=_day+1;
                    break;
                }
            }
    }
}

const bool Date::is_leap() const
{
    return _year % 4 == 0 && _year % 400 != 0;
}

const bool operator==(const Date& d0, const Date& d1){
    if ((d0._year == d1._year) && (d0._month == d1._month) && (d0._day == d1._day) )
        return 1;
    return 0;
}

const bool operator!=(const Date& d0, const Date& d1){
    if ((d0._year != d1._year) || (d0._month != d1._month) || (d0._day != d1._day) )
        return 1;
    return 0;
}


Date::Date(const unsigned short& d, const month_enum& m, const unsigned int& y):
_day{d},
_month{m},
_year{y}
{
    std::cout<<"Timing time\n";
    }
    
    std::ostream& operator<<(std::ostream& os, const Date& dat) {
        os << dat.day()<<" "<<static_cast<int>(dat.month())<<" "<<dat.year()<< std::endl;
        return os;
    }
    
    int main(){
        Date D{28,month_enum::feb,2016};
        std::cout<<"Date "<< D <<std::endl;
        D.add_days(2);
        std::cout<<D<<std::endl;
        return 0;
    }
