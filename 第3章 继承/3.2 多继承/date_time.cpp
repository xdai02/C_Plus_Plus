#include "date_time.h"

using namespace std;

DateTime::DateTime(int year, int month, int day,
         int hour, int minute, int second)
  : Date(year, month, day),
	  Time(hour, minute, second) {}

string DateTime::getDateTime() {
    return getDate() + " " + getTime();
}