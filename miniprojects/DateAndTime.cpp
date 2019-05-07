#include <iostream>
#include <string>

using namespace std;

class Date{


public:

    struct mydate{
        int day;
        int month;
        int year;
    };

    mydate date = {0, 0, 0};

    void SetDateNums(){

        cout << "\nEnter day: ";
        cin >> date.day;

        cout <<"Enter month: ";
        cin >> date.month;

        cout << "Enter year: ";
        cin >> date.year;

        if (!valid(date)){
            cout << "Something incorrect, pls try again!";
            SetDateNums();
        } else
            cout << "_________________________________________\n";

    }


    void NextDate(){
        mydate next = next_date(date);
        PrintDate(next);
    }

    void PreviousDate(){
        mydate previous = previous_date(date);
        PrintDate(previous);
    }

    void DayWeek(){
        string day[7] = {
                "Wednesday",
                "Thursday",
                "Friday",
                "Saturday",
                "Sunday",
                "Monday",
                "Tuesday"
        };
        int dw = week_day(date);
        cout << day[dw%7] << endl;
    }

    void PlusDays(){
        int days = 0;
        cout << "Enter days to add";
        cin >> days;
        mydate plus_date = plus_days(date, days);
        PrintDate(plus_date);
    }

    void Difference(){
        mydate f = {11,2,2012};
        mydate s = {7,5,2019};
        cout << difference_in_dates(s,f);
    }


    void PrintDate(mydate &date){

        cout << "Day: " << date.day <<
             "\nMonth: " << date.month << "\nYear: " << date.year;
    }




private:

    bool valid(const mydate &date){

        // this func will check the given date is valid or not
        // if the date is not valid then it will return the value false

        if (date.year < 0) return false;
        if (date.month >12 || date.month <1) return false;
        if (date.day >31 || date.day <1) return false;
        if ((date.day ==31 &&
             ( date.month == 2 || date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11) ))
            return false;
        if ( date.day ==30 && date.month == 2) return false;

        if (!(((date.year % 4 == 0) && (date.year % 100 != 0)) || (date.year % 400 == 0))){
            if (date.day ==29 && date.month ==2) return false;
        };

        return true;
    }

    mydate next_date(const mydate &date){

        mydate nextdat = date;

        nextdat = { date.day + 1, date.month, date.year}; if (valid(nextdat)) return nextdat;

        nextdat = {1, date.month + 1, date.year}; if (valid(nextdat)) return nextdat;

        nextdat = {1, 1, date.year + 1};

        return nextdat;
    }

    mydate previous_date(const mydate &date){
        mydate prevdat = date;

        prevdat = {date.day - 1, date.month, date.year}; if (valid(prevdat)) return prevdat;

        for (int day_(31); day_>27; day_--){
            prevdat = {day_, date.month - 1, date.year};
            if (valid(prevdat)) return prevdat;
        }

        prevdat = {31,12,date.year - 1};
        return prevdat;

    }


    bool first_bigges(const mydate &date1, const mydate &date2){
        bool flag = false; // if first biggest flag will be true

        if ((date1.day == date2.day) && (date1.month == date2.month) && (date1.year == date2.year)){
            flag = false;
        } else{

            if (date1.year > date2.year){
                flag = true;
            }

            else if (date1.year == date2.year){
                if (date1.month > date2.month)
                    flag = true;

                else if (date1.month == date2.month){
                    if(date1.day > date2.day)
                        flag = true;
                }
            }
        }
        return flag;
    }

    int week_day(const mydate &date){
        int dw ;
        int month = date.month;
        int year = date.year;
        int day = date.day;


        month = (month + 9) % 12;
        year -= month / 10;
        dw = 365*year + year/4 - year/100 + year/400 + (month*306 + 5)/10 + (day - 1);
        return dw;
    }

    mydate plus_days(const mydate &date, int n){
        if (n < 0)
            n = -n;
        else if (n == 0)
            return date;

        mydate rez = next_date(date);
        int count_days = 1;


        while (count_days < n){
            rez = next_date(rez);
            count_days +=1;
        }

        return rez;
    };


    int difference_in_dates(mydate &date1, mydate &date2){
        int days = 0;

        if (!first_bigges(date1, date2)){
            mydate templdate = date1;
            date1 = date2;
            date2 = templdate;
        }

        while (first_bigges(date1, date2)) {
            date2 = next_date(date2);
            days += 1;
        }
        return days;
    }

    mydate addingdates(mydate &date1, mydate &date2){
        int days = difference_in_dates(date1, date2);
        if (!first_bigges(date1, date2))
            date1 = date2;
        mydate rez = plus_days(date1, days);
        return rez;
    }


};



class Time{

public:
    struct mytime{
        int days;
        int hours;
        int minutes;
        int seconds;
    };

    mytime time = {1, 1, 1, 1};

    void SetTimeNums(){

        cout << "\nEnter day: ";
        cin >> time.days;

        cout <<"Enter hours: ";
        cin >> time.hours;

        cout << "Enter minutes: ";
        cin >> time.minutes;

        cout << "Enter seconds: ";
        cin >> time.seconds;

        if (!valid(time)){
            cout << "Something incorrect, pls try again!";
            SetTimeNums();
        } else
            cout << "_________________________________________\n";

    }

    void PrintTime(mytime time){
        cout << time.days << "," << time.hours << "," << time.minutes << "," << time.seconds << endl;
    }

    void seconds(){
        cout << to_seconds(time);
    }

    void add(){
        mytime t1 {0,1,12, 30};
        mytime t2 {1, 1,1, 1};

    }


private:
    bool valid(const mytime &time_){
        if (time_.days < 0) return false;
        if ( (time_.hours < 0) || (time_.hours > 24) ) return false;
        if ( (time_.minutes < 0) || (time_.minutes > 60) ) return false;
        if ( (time_.seconds < .0) || (time_.seconds > 100.) ) return false;

        return true;
    }


    int days(const mytime &time_){
        return time_.days;
    }

    Date to_mydate(const mytime &time_){
        Date to_time{.date = {.day = time_.days}};
        return to_time;
    }


    int to_seconds(const mytime &time_){
        int all_seconds = 86400 * time_.days + 3600 * time_.hours + 60 * time_.minutes + time_.seconds;
        return all_seconds;
    }


    bool first_biggest(const mytime &time1_, const mytime &time2_){
        return to_seconds(time1_) > to_seconds(time2_);
    }


    mytime second_to_mytime(int total_sec){
        mytime rez{};
        int s = 0, m = 0, h = 0, d = 0;
        d = total_sec / 86400;
        total_sec -= 86400 * (total_sec / 86400);

        h = total_sec / 3600;
        total_sec -= 3600 * (total_sec / 3600);

        m = total_sec / 60;
        total_sec -= 60 * (total_sec / 60);
        s = total_sec;

        rez = {d, h, m, s};
        return rez;
    }

    mytime add_mytime(const mytime &time1_, const mytime &time2_){
        int sec = to_seconds(time1_) + to_seconds(time2_);
        return second_to_mytime(sec);
    }

    mytime multiply_mytime(const mytime &time_, int n){
        int sec = to_seconds(time_) * n;
        return second_to_mytime(sec);
    }

    mytime divide_mytime(const mytime &time_, int n){
        int sec = to_seconds(time_) / n;
        return second_to_mytime(sec);
    }

    Date add_timedate( Date &date_, const mytime &time_){
        Date rez{
                date_.date.day + time_.days
        };
        return rez;
    }

};

int main(){
    Time t{};

}


