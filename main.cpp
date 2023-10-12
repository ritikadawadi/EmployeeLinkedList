#include <iostream>
#include "LinkedList.h"

int main()
{
   LinkedList<int> EmployeeId; // for employee id number
   LinkedList <int> employeeHours; // for number of hours worked
   LinkedList<double> payRate; // pay rate for each employee
   LinkedList<double> Wages; // list to store the gross wages of each employee;

   int i =1;
   int EmployeeID;
   int EmployeeHours;
   double PayRate;

   while(true)
   {
       std::cout<<"Enter the Employee ID of employee " << i <<std::endl;
       std::cin >> EmployeeID;
       EmployeeId.appendNode(EmployeeID);
       std::cout <<"Enter the number of hours of employee " <<i <<std::endl;
       std::cin >> EmployeeHours;
       while(true)
       {
           if (EmployeeHours <0)
           {
               std::cout<<"You entered a negative number. Please enter a positive number: ";
               cin >> EmployeeHours;
           }
           else
               break;
       }
       employeeHours.appendNode(EmployeeHours);
       std::cout<<"Enter the pay rate of the employee " << i <<std::endl;
       std:: cout <<"$";
       std::cin >>PayRate;
       while(true)
       {
           if (PayRate<15.00)
           {
               std::cout<<"You entered a number below 15.00. Please enter again. $";
               std::cin >> PayRate;
           }
           else
               break;
       }
       payRate.appendNode(PayRate);

       char check;
       std::cout <<"Do you wish to add another employee's information?" <<std::endl;
       std::cout <<"Enter (Y or y) if you wish to continue" <<std::endl;
       std::cin >> check;
       if (toupper(check) !='Y')
           break;
       else
       {
           i++;
           std::cout <<"------------------------------------------------" <<std::endl;
       }
   }
   int count = EmployeeId.getCount();
   int p =0;
   while (count !=0 )
   {
       double value = employeeHours.getElementAt(p) * payRate.getElementAt(p);
       Wages.appendNode(value);
       count--;
       p++;
   }
   int Count = Wages.getCount();
   int q=0;
   std::cout<<"-------------------------------------------------------" <<std::endl;
   std::cout <<"Here is the information about all the employees: " <<std::endl;
   std::cout <<"Employee \t\tWages" <<std::endl;
   while(Count !=0)
   {
       int ID = EmployeeId.getElementAt(q);
       double wage = Wages.getElementAt(q);

       std::cout << ID << "\t\t\t\t" <<wage << std::endl;
       q++;
       Count--;
   }
return 0;
}
