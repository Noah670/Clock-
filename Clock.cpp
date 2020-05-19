/*
* @author Noah Pohl
* @date 5-18-2020
*
*/

#include <iostream>

// use to print leading zeroes
#include <iomanip>

using namespace std;

// Function declarations
int displayClock(int, int, int);
void displayMenu();

int main()
{
  // variable to increase the time by 1
  int increaseHour = 1;
  int increaseMinute = 1;
  int increaseSecond = 1;

  // start the default time to display as 10:00:00 AM
  displayClock(1, 0, 0);

  displayMenu();

  int userChoice = 0;

  cin >> userChoice;

  while (userChoice != 4)
  {

    if (userChoice == 1)

    {
      // run add hour function()
      displayClock(increaseHour, 0, 0);
      cout << "One hour added successfully. " << endl;
    }
    else if (userChoice == 2)
    {
      displayClock(0, increaseMinute, 0);
      cout << "One minute added successfully. " << endl;
    }
    else if (userChoice == 3)
    {
      displayClock(0, 0, increaseSecond);
      cout << "One second added successfully. " << endl;
    }
    else
    {
      cout << "Invalid option selected. ";
    }

    // displayClock(increaseHour);
    displayMenu();

    cin >> userChoice;
  }

  cout << "Thank you for using our clock service! " << endl;
  return 0;
}

int displayClock(int addHour, int addMinute, int addSecond)
{

  // local variables for storing the 12 hour clock time

  //declare the variables as static to preserve their values after calling the function
  // local variables for the 12 hour Clock which is display first
  static int FirstClockHours = 0;
  static int FirstClockMinutes = 0;
  static int FirstClockSeconds = 0;
  // "AM" and "PM" string variables used to output for the 12 hour clock
  string morning = "AM";
  string afternoon = "PM";

  // local variables for storing the 24 hour clock time being displayed
  static int OtherClockHours = 0;
  static int OtherClockMinutes = 0;
  static int OtherClockSeconds = 0;

  // used to switch from A.M. or P.M.
  // set dayOrNight to A.M. by default
  static string dayOrNight = morning;

  // update the 12 hour clock displayed first
  FirstClockHours = FirstClockHours + addHour;
  FirstClockMinutes = FirstClockMinutes + addMinute;
  FirstClockSeconds = FirstClockSeconds + addSecond;

  // upate the other 24 hour clock
  OtherClockHours = OtherClockHours + addHour;
  OtherClockMinutes = OtherClockMinutes + addMinute;
  OtherClockSeconds = OtherClockSeconds + addSecond;

  // switch the am to pm time

  // check if the hours in the first clock is past 12
  if (FirstClockHours > 12)
  {
    // set the time back to 1:00 and change from AM to PM
    dayOrNight = afternoon;
    FirstClockHours = 1;
  }

  // check the minutes in the first clock is greater than 59 minutes

  if (FirstClockMinutes > 59)
  {
    // set the Minute clock hand back to 0
    FirstClockMinutes = 0;
    // update and increase the hour clock hand by 1
    FirstClockHours++;
  }

  // check if the seconds in the fist clock is greater than 59 minutes
  if (FirstClockSeconds > 59)
  {
    // set the seconds in the clock hand back to 0
    FirstClockSeconds = 0;
    // increase the Minute clock hand by 1
    FirstClockMinutes++;
  }

  //switch the PM
  // use a for loop

  // check if the other 24 hour clock has passed 24 hours
  if (OtherClockHours > 24)
  {
    // set the clock hours hand back to 1
    OtherClockHours = 1;
  }

  // check if the minutes in the 24 hour clock is greater than 59
  if (OtherClockMinutes > 59)
  {
    // set the minutes clock hand back to 0
    OtherClockMinutes = 0;
    // update and increase the Hour clock hand by 1
    OtherClockHours++;
  }

  // eheck if the seconds in the 24 hour clock is greater than 59
  if (OtherClockSeconds > 59)
  {
    // set the seconds clock hand back to 0
    OtherClockSeconds = 0;
    // update and increase the Minute clock hand by 1
    OtherClockMinutes++;
  }

  cout << "The current time is: " << endl;

  cout << "**************************"
       << "     "
       << "************************** " << endl;
  cout << "* "
       << "   12-hour Clock       *"
       << "     "
       << "* "
       << "   24-hour Clock       *" << endl;
  // print with one leading zeroe in front for both of the clocks
  cout.fill('0');
  cout << "*     " << setw(2) << FirstClockHours << ":" << setw(2) << FirstClockMinutes << ":" << setw(2) << FirstClockSeconds << " " << dayOrNight << "     "
       << "   *"
       << "     "
       << "*       " << setw(2) << OtherClockHours << ":" << setw(2) << OtherClockMinutes << ":" << setw(2) << OtherClockSeconds << "         *" << endl;
  cout << "**************************"
       << "     "
       << "**************************" << endl;
  cout << endl;

  //set return
  return 0;
}

void displayMenu()
{
  cout << "**************************" << endl;
  cout << "*  1 - Add One Hour      *" << endl;
  cout << "*  2 - Add One Mintue    *" << endl;
  cout << "*  3 - Add One Second    *" << endl;
  cout << "*  4 - Exit Program      *" << endl;
  cout << "**************************" << endl;
}
