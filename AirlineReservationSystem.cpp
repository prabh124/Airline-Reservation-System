//Libraries needed to complete the code
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

//Initialize functions that are used within the code
void displayMenu();
void fcBooker(int array[]);
void ecBooker(int array[]);
void reservationStatus(int array[]);


	int main()
	{
		//Seed random time slots to allow for true randomization later on in the program
		srand(time(NULL));

		//Initialize the array to values of 0
		int seatingPlan[10] = { };
		//Choice for when FC or EC are full
		int choice;
		//Counter for the while loop
		int bookings = 0;
		//Counter to check when both are full
		int fcCounter(0), ecCounter(0);
		//Boolean which is used to exit the switch/while loop
		bool finished = false;
		//String initialized to nothing which will be replaced with either reserved or unreserved in the function reservationStatus.
		string whenFull = "";

		cout << "				Prabhs Airline Reservation System				" << endl;
		cout << "			 ===============================================		" << endl;

		cout << "\nWelcome to Prabhs Airlines! Please follow the menu options for us to serve you better!" << endl;
	
		//While the booking counter is less than 9, run this loop
		while (bookings < 9)
		{
		
			displayMenu();
            cout << "\n";
			cin >> choice;

			//Number validation, must be a valid menu choice
			while ((choice < 1) || (choice > 3))
			{
				cout << "Please enter a value between 1 and 3! " << endl;
				cin >> choice;
			}

			//Switch statement for the options
			switch (choice)
			{

			case 1:
				
				//Run the FC booking function
				fcBooker(seatingPlan);
				//Add one if this option is chosen
				fcCounter++;
			
					//If FC is full, ask if EC is okay. If both are full then break out of the loop and switch.
					if (fcCounter == 5)
					{
						cout << "First Class is full, book economy? (Yes/No)(Case Sensitive) " << endl;
						cin >> whenFull;

						if ((whenFull == "Yes") && (ecCounter != 5))
							ecBooker(seatingPlan);
						//When EC and FC are full, exit program
						else
							finished = true;
					}
				//Add one to bookings
				bookings += 1;

					break;
			case 2:
				
				//Run the EC booking function
				ecBooker(seatingPlan);
				//Add one if this option is chosen
				ecCounter++;

					//If EC is full, ask if FC is okay. If both are full then break out of the loop and switch.
					if (ecCounter == 5)
					{
						cout << "Economy Class is full, book First Class? (Yes/No)(Case Sensitive) " << endl;
						cin >> whenFull;

						if ((whenFull == "Yes") && (fcCounter != 5))
							fcBooker(seatingPlan);
						//When EC and FC are full, exit program
						else
							finished = true;
					}
				//Add one to bookings
				bookings += 1;

				break;
		
			case 3:
				
				//Display reservation status
				reservationStatus(seatingPlan);
				break;
			}

			//If full, break out of the while loop
			if (finished)
			{
				break;
			}
		
		

		}

		//When bookings are at 9, then the plane is full, and output reservation status
		if (bookings == 9)
		{
			reservationStatus(seatingPlan);
			cout << "\nThe plane is full. ";
		}
		
		//This line is added onto the previous line if the plane is full. If it is not full, this line is displayed
		//when either FC or EC are full and the user does not want to use the other option
		cout << "Next flight leaves in 3 hours" << endl;

	}
		
	
		//Menu
		void displayMenu()
		{
			cout << "\n<1> First Class " << endl;
			cout << "<2> Economy Class " << endl;
			cout << "<3> Reservation Status " << endl;
		}


		//FC Booking function
		void fcBooker(int array[])
		{
			int seatNumber= 0; 

			//Keep running until the array from 1-5 is set to 1 (reserved)
			while (array[seatNumber - 1] != 0)
			{
				seatNumber = 1 + rand() % 5;
	
			}
			
			//Output and setting the array to 1 if it is booked
			array[seatNumber - 1] = 1;
			cout << "\nYour seat number is " << seatNumber << " In First Class." << endl;
	
		}

		//EC Booking Function
		void ecBooker(int array[])
		{
			int seatNumber = 0;
			//Keep running until the array from 1-5 is set to 1 (reserved)
				while (array[seatNumber - 1] != 0)
				{
					seatNumber = 6 + rand() % 5;

				}
			
			//Output and setting the array to 1 if it is booked
			array[seatNumber - 1] = 1;
			cout << "\nYour seat number is " << seatNumber << " In Economy Class."<< endl;

		}
	
		//Print the reservation status
		void reservationStatus(int array[])
		{
			string reservation;
			cout << "\n";
	
			for (int i = 0; i <= 9; i++)
			{
				//If array at i is 1, it is reserved. Else it is unreserved
				if (array[i] == 1)
				{
					reservation = "RESERVED";
				}
		
				else
				{
					reservation = "UNRESERVED";
				}
		
					//if i is less than 5, that means that it is First Class. Else it is Economy Class
					if (i < 5)
					{
						cout << "Seat " << (i + 1) << " First Class: " << reservation << endl;

					}
					else
					{
						cout << "Seat " << (i + 1) << " Economy Class: " << reservation << endl;
					}
			}
		}
