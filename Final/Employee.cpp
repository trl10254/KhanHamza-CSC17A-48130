#include "Employee.h"
#include <sstream>
#include <string>
#include <iostream>
#include <iomanip>


Employee::Employee(char name[],char title[], float pay)
{
  //Set known variables letting the wonderful string do my conversions
    //std::string sName(name,20);
    for(int i=0;i<20;i++)
        MyName[i] = name[i];
    //std::string sTitle(title,20);
    for(int i=0;i<20;i++)
        JobTitle[i] = title[i];
    
    if(pay > 200 || pay < 0)
    {
        HourlyRate = 0;
        std::cout<<std::endl<<"VALUE OF PAY ("<<pay<<") INVALID, INITIALIZING TO ZERO"<<std::endl;
    }
    else
    {
        HourlyRate = pay;
    }
  //Initialize other variables to zero
    HoursWorked = 0;
    GrossPay = static_cast<float>(0);
    NetPay = static_cast<float>(0);
}
float  Employee::CalculatePay(float payrate,int hours)
{
    return getNetPay(getGrossPay(setHourlyRate(payrate)
		,setHoursWorked(hours)));
}
float  Employee::getGrossPay(float pay,int hours)
{
    float total = 0;
  //Calculate tax for income in 3rd bracket
    if(hours > 50)
    {
        int tempHours = hours - 50;
        total += pay * 2.0 * tempHours;
        hours -= tempHours;
    }
  //Calculate tax for income in 2nd bracket
    if(hours > 40)
    {
        int tempHours = hours - 40;
        total += pay * 1.5 * tempHours;
        hours -= tempHours;
    }
   //Calculate remaining tax
    total += pay * 1.0 * hours;
    
    //std::cout<<"||  Gross Pay = "<<tax<<std::endl;
  //Set gross pay variable
    GrossPay = total;
  //Return Gross Pay
    return total;
}
float  Employee::getNetPay(float grossPay)
{
    NetPay = grossPay - Tax(grossPay);
    return NetPay;
}
const char* Employee::toString()
{
  //Create string stream and push values to create a giant string
    std::stringstream data;
    data<<"||  "<<std::left<<std::setw(56)<<std::string(MyName)<<"  ||"<<std::endl
        <<"||============================================================||"<<std::endl
        <<"||  Job Title:      "<<std::string(JobTitle)<<std::endl
        <<"||  Pay Rate:       $"<<std::setprecision(4)<<HourlyRate<<"/hr"<<std::endl
        <<"||  Hours Worked:   "<<HoursWorked<<std::endl
        <<"||  Gross Pay:      $"<<std::setprecision(4)<<GrossPay<<std::endl
        <<"||  Net Pay:        $"<<std::setprecision(4)<<NetPay<<std::endl
        <<"||============================================================||"<<std::endl;   
    
   //data.str() returns a string and data.str().c_str() returns a character array)
    return data.str().c_str();
}
int    Employee::setHoursWorked(int hours)
{
    if(hours > 84 || hours < 0)
    {
        HoursWorked = 0;
        std::cout<<std::endl<<"VALUE OF HOURS WORKED ("<<hours
                 <<") INVALID, INITIALIZING TO ZERO"<<std::endl<<std::endl;
    }
    else
    {
        HoursWorked = hours;
    }
    return HoursWorked;
}
float  Employee::setHourlyRate(float pay)
{
    HourlyRate = pay;
    return HourlyRate;
}
float Employee::Tax(float grossPay)
{
    float tax = 0;
  //Calculate tax for income in 3rd bracket
    while(grossPay>1000.0)
    {
        float tempTax = grossPay - 1000.0;
        tax += tempTax * 0.3;
        grossPay -= tempTax;
    }
  //Calculate tax for income in 2nd bracket
    if(grossPay>500.0)
    {
        float tempTax = grossPay - 500.0;
        tax += tempTax * 0.2;
        grossPay -= tempTax;
    }
   //Calculate remaining tax
    tax += grossPay * 0.1;
    
    //std::cout<<"||  Tax Owed = "<<tax<<std::endl;
    return tax;
    
}
