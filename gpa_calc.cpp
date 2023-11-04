#include <iostream>

using namespace std;

struct Class
{
   string name, grade;
   int credits;
   Class *next;
};

void addClass(Class*& head, int i)
{
   Class *add = new Class;
   cout << "\nEnter name of class " << i << ": ";
   cin >> add->name;
   cout << "Enter grade of class " << i << ": ";
   cin >> add->grade;
   cout << "Enter number of credits for the class " << i << ": ";
   cin >> add->credits;
   add->next = nullptr;
   
   Class *cur = head;
   if(cur)
   {
      while(cur->next)
         cur = cur->next;
      cur->next = add;
   }
   else
      head = add;
}

double weighted(string grade)
{
   if(grade == "A+" || grade == "A")
      return 4.00;
   else if(grade == "A-")
      return 3.67;
   else if(grade == "B+")
      return 3.33;
   else if(grade == "B")
      return 3.00;
   else if(grade == "B-")
      return 2.67;
   else if(grade == "C+")
      return 2.33;
   else if(grade == "C")
      return 2.00;
   else if(grade == "C-")
      return 1.67;
   else if(grade == "D+")
      return 1.33;
   else if(grade == "D")
      return 1.00;
   else if(grade == "D-")
      return 0.67;
   return 0.00;
}

void printClasses(Class *head)
{
   Class *cur = head;
   while (cur != nullptr)
   {
     cout << weighted(cur->grade) << " ";
     cur = cur->next;
   }
   cout << endl;
}

double calculateGPA(Class *head)
{
   double gpa;
   double total_credits;
   Class *cur = head;
   while (cur != nullptr)
   {
     gpa += weighted(cur->grade) * cur->credits;
     total_credits += (double)cur->credits;
     cur = cur->next;
   }
   //cout << "total weight: " << gpa << " total_credits: " << total_credits << endl;
   return gpa/total_credits;
}

int main()
{
   int classes;
   Class *head = nullptr;
   
   cout << "UTD GPA Calculator\n---------------------------------------------------------------------------------------------------------------------\n" << endl;
   cout << "Welcome Student" << endl;
   cout << "Enter your total number of classes: ";
   cin >> classes;
   
   for(int i = 0; i < classes; i++)
      addClass(head, i+1);
   //printClasses(head);
   cout << "\nGPA: " << calculateGPA(head) << endl << endl;
   
   return 0;
}





