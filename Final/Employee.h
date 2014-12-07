/* 
 * File:   Employee.h
 * Author: Hamza Khan
 *
 * Created on December 7, 2014, 1:04 PM
 */

#ifndef EMPLOYEE_H
#define	EMPLOYEE_H

class Employee{
    public:
        Employee(char[],char[],float);  //Constructor
        float        CalculatePay(float,int); //Procedure
        float        getGrossPay(float,int);  //Procedure
        float        getNetPay(float);        //Procedure
        const char*  toString();              //Procedure
        int          setHoursWorked(int);     //Procedure
        float        setHourlyRate(float);    //Procedure
    private:
        float Tax(float);      //Utility Procedure
        char   MyName[20];      //Property
        char   JobTitle[20];    //Property
        float  HourlyRate;      //Property
        int    HoursWorked;     //Property
        float  GrossPay;        //Property
        float  NetPay;          //Property
};

#endif	/* EMPLOYEE_H */
