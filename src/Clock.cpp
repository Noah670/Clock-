/*
* Clock.cpp
* @author Noah Pohl
* @date 5-20-2020
*/

#include <iostream>

// use to print leading zeroes to use setw()
#include <iomanip>

using namespace std;

// Function declarations at the top
int displayClock(int, int, int);
void displayMenu();

int main()
{
  // variable to increase the time by 1
  int increaseHour = 1;
  int increaseMinute = 1;
  int increaseSecond = 1;

  // start the default time to display as 01:00:00 AM for both of the clocks
  // default time at startup can be changed with displayClock(int,int,int) where the 3 ints represent hours, minutes, and seconds
  displayClock(1, 0, 0);

  // displays input options for the user
  displayMenu();

  // a userChoice variable that allows the user to interact with the menu by entering a number 1-4
  int userChoice = 0;

  // take user input
  cin >> userChoice;

  // while loop that allows the user to enter options 1-4
  while (userChoice != 4)
  {

    if (userChoice == 1)

    {
      // increases the time by 1 hour
      displayClock(increaseHour, 0, 0);
      cout << "One hour added successfully. " << endl;
    }
    else if (userChoice == 2)
    {
      // increases the time by 1 minute
      displayClock(0, increaseMinute, 0);
      cout << "One minute added successfully. " << endl;
    }
    else if (userChoice == 3)
    {
      // increaes the time by 1 second
      displayClock(0, 0, increaseSecond);
      cout << "One second added successfully. " << endl;
    }
    else
    {
      // If the user inputs a menu option not available
      cout << "Invalid option selected. ";
    }

    // display the menu options again to the user
    displayMenu();

    cin >> userChoice;
  }

  // print ending statement to the user
  cout << "Thank you for using our clock service, goodbye! " << endl;
  return 0;
}

// displayClock function takes in three
int displayClock(int addHour, int addMinute, int addSecond)
{

  // local variables for storing the 12 hour clock time

  //declare the variables as static to preserve their values after calling the function
  // local variables for the 12 hour Clock which is display first
  static int firstClockHours = 0;
  static int firstClockMinutes = 0;
  static int firstClockSeconds = 0;

  // "AM" and "PM" string variables used to output for the 12 hour clock
  string morning = "AM";
  string afternoon = "PM";

  // local variables for storing the 24 hour clock time being displayed
  static int otherClockHours = 0;
  static int otherClockMinutes = 0;
  static int otherClockSeconds = 0;

  // static string used to switch from A.M. or P.M.
  // set dayOrNight to A.M. by default assuming default start time is 1:00 AM
  static string dayOrNight = morning;

  // update the 12 hour clock displayed first increasing the values
  firstClockHours = firstClockHours + addHour;
  firstClockMinutes = firstClockMinutes + addMinute;
  firstClockSeconds = firstClockSeconds + addSecond;

  // upate the other 24 hour clock by increasing the values
  otherClockHours = otherClockHours + addHour;
  otherClockMinutes = otherClockMinutes + addMinute;
  otherClockSeconds = otherClockSeconds + addSecond;

  // If/ else block to switch from AM to PM
  // check if the hours in the first clock is past 12
  if (firstClockHours > 12)
  {

    // check if dayOrNight is already morning and then change it to afternoon to display as PM
    if (dayOrNight == morning)
      dayOrNight = afternoon;

    // when dayOrNight is already afternoon switch it back to morning to display AM
    else
      dayOrNight = morning;

    // set the time back to 1:00:00 for the 12 hour clock format
    firstClockHours = 1;
  }

  // if statement blocks for the 12 hour clock logic

  // check the minutes in the first clock is greater than 59 minutes
  if (firstClockMinutes > 59)
  {
    // set the Minute clock hand back to 0
    firstClockMinutes = 0;
    // update and increase the hour clock hand by 1
    firstClockHours++;
  }

  // check if the seconds in the fist clock is greater than 59 minutes
  if (firstClockSeconds > 59)
  {
    // set the seconds in the clock hand back to 0
    firstClockSeconds = 0;
    // increase the Minute clock hand by 1
    firstClockMinutes++;
  }

  // if statement blocks for 24 hour clock logic

  // check if the other 24 hour clock has passed 24 hours
  if (otherClockHours > 24)
  {
    // set the clock hours hand back to 1
    otherClockHours = 1;
  }

  // check if the minutes in the 24 hour clock is greater than 59
  if (otherClockMinutes > 59)
  {
    // set the minutes clock hand back to 0
    otherClockMinutes = 0;
    // update and increase the Hour clock hand by 1
    otherClockHours++;
  }

  // eheck if the seconds in the 24 hour clock is greater than 59
  if (otherClockSeconds > 59)
  {
    // set the seconds clock hand back to 0
    otherClockSeconds = 0;
    // update and increase the Minute clock hand by 1
    otherClockMinutes++;
  }

  // formatting for displaying the clock time
  cout << "The current time is: " << endl;

  cout << "**************************"
       << "     "
       << "************************** " << endl;
  cout << "* "
       << "   12-hour Clock       *"
       << "     "
       << "* "
       << "   24-hour Clock       *" << endl;
  // print with one leading zeroe in front for both of the clocks using cout.fill('0') and setw(2) to alway display as 00:00:00 format
  cout.fill('0');
  cout << "*     " << setw(2) << firstClockHours << ":" << setw(2) << firstClockMinutes << ":" << setw(2) << firstClockSeconds << " " << dayOrNight << "     "
       << "   *"
       << "     "
       << "*       " << setw(2) << otherClockHours << ":" << setw(2) << otherClockMinutes << ":" << setw(2) << otherClockSeconds << "         *" << endl;
  cout << "**************************"
       << "     "
       << "**************************" << endl;
  cout << endl;

  //set return
  return 0;
}

// a simple displayMenu function for the user to view
void displayMenu()
{
  cout << "**************************" << endl;
  cout << "*  1 - Add One Hour      *" << endl;
  cout << "*  2 - Add One Mintue    *" << endl;
  cout << "*  3 - Add One Second    *" << endl;
  cout << "*  4 - Exit Program      *" << endl;
  cout << "**************************" << endl;
}
