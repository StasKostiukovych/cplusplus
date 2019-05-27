/* Time
 * Realization of Time headers
 * Done by Kostiukovych Stanislav, Statistics
 * Date 28.05.2019
 */

#ifndef DATETIME_KOSTIUKOVYCH_TIME_H
#define DATETIME_KOSTIUKOVYCH_TIME_H
#include "Date.h"

class Time
{
public:

    struct myTime
    {
        int days;
        int hours;
        int minutes;
        int seconds;
    };


    void InputTime(myTime &time);
    void GetSeconds();
    void TimeToScreen(myTime time);
    void GetBiggerTime();
    void AddTimes();
    void SubtractTimes();
    void MultiplyTime();
    void DivideTime();
    void GetDays();
    void AddTimeToDate();
    void ConvertToTime();
    void SubtractTimeFromDate();


private:

    bool IsValidTime(const myTime &localTime);
    int GetSecondsLogic(const myTime &localTime);
    myTime GetBiggerTimeLogic(const myTime &time1, const myTime &time2);
    int GetDays(const myTime &localTime);
    Date GetDate( Date &date, const myTime &localTime);
    myTime GetConvertedSecondsToTime(int totalSeconds);
    Date ConvertToDate(const myTime &localTime);
    myTime GetAddedTimes(const myTime &time1, const myTime &time2);
    myTime GetMultipledTime(const myTime &localTime, int n);
    myTime GetDividedTime(const myTime &localTime, int n);

};
#endif //DATETIME_KOSTIUKOVYCH_TIME_H
