#include <muduo/base/Date.h>
#include <iostream>
using namespace muduo;

int main()
{
	Date date(2015,7,27);
	int julianDayNum=date.julianDayNumber();
	std::cout<<"Julian Day Num is"<<julianDayNum<<std::endl;
	Date date2(julianDayNum);
	struct Date::YearMonthDay yearMonthDay=date2.yearMonthDay();
	std::cout<<yearMonthDay.year<<"--"<<yearMonthDay.month<<"--"<<yearMonthDay.day<<std::endl;

	return 0;
}
