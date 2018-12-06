/* COSC 1410, Assignment 2
Tuesday, September 16, 2014
Write a program that simulates the user login.
Assume the user will always enter numbers
*/
#include <iostream>
using namespace std;
//Init the functions
bool is4digits(int pw);

int main(){
	//Init the variables
	const int USERID = 123456, PWID = 2014; //User login info
	int currUser, currPw;
	int nwPw;
	int counter = 3;

	do { /* I used a {do while} to make the program ask for the userID and PW at least once and to execute until the
		user fails to login after 3 attemps*/
		cout << "Please enter your 6-digit user id:";
		cin >> currUser;
		cout << "Please enter your 4-digit password:";
		cin >> currPw;

		if (currUser != USERID || currPw != PWID){//If the user enters an incorrect ID or PW decrease the attemps and let the user know
			counter--;//decrease counter
			cout << "Invalid userID/password. You can try " << counter << " more time/s.\n";
		}
		if (counter == 0) {//If the user runs out of attemps end the program
			cout << "Login has failed. Goodbye!" << endl;
			system("pause");
			return 0;
		}
	} while (currUser != USERID || currPw != PWID); //continue to loop until the correct userID and password

	if (currUser == USERID && currPw == PWID )//If the correct UserID and PW is inputted
	{
		cout << "-----------------------------------------------------\n";
		cout << "Logged in Successfully. You should change your password at the first login.\n"
			<< "The new password should be a 4-digit number and different from\n" <<
			"the current password.\n" << "Please enter your new 4-digit password:";
		cin >> nwPw;
		if (nwPw == currPw)//Error if the same password is inputted
		{
			cout << "Your password could not be changed. Please enter a different password!\n";
		}
		else if (is4digits(nwPw) != 1)//Error if the function is false (not true)
		{
			cout << "Your password could not be changed. Password is not 4-digits!\n";
		}
		else {//Password was changed
			cout << "Success! Your password has been changed!\n";
		}
	}

	system("pause");
	return 0;
}

bool is4digits(int pw) { //Bool Function to check if the PW is a 4-digit number (true or false)
	bool status = true; //status is true if it is a 4-digit number
	if (pw < 1000 || pw > 9999) { 
		status = false;//status changes to false if it is not a 4-digit number
	}
	return status; //return the status
}