/*
Description:The Econo-Airlines fleet consists of one plane with a seating
capacity of 12. It makes one flight daily.
The aircraft seating is arranged in 6 rows with 2 seats per row. The
program uses an array of 12 structures. Each structure holds a seat
identification number, a marker that indicates whether the seat is
assigned, the last name of the seat holder, and the first name of the seat
holder.
Programmer:Hung Dung, Le
Date:2022 April 3rd
Version:1.0
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SEATS 12 //using for structure that contains 12 structure, which are equivalent to 12 seats.
#define TRUE 1// Using for assigning the seat.
#define FALSE 0//Using for emptying the seat.


struct AirLineSeat
{
	int id; //the seat id of the customer.
	int marker;//marker to check that whether the seat is empty.
	char lastname[10];// last name of the customer.
	char firstname[10];//first name of the customer.
}; 

void explainPrg(void); //explain what is the program about .
void menuOptions(struct AirLineSeat seatArrange[SEATS]);// create a menu with 7 options.
void initializeSeat(struct AirLineSeat seatArrange[SEATS]);//set up the seat first.
void allSeat(struct AirLineSeat seatArrange[SEATS]);//option A function.
void emptySeat(struct AirLineSeat seatArrange[SEATS]);//option B function.
void assignedSeat(struct AirLineSeat seatArrange[SEATS]);//option C function.
void assignCustomer(struct AirLineSeat seatArrange[SEATS]);//option D function.
void deleteoneCustomer(struct AirLineSeat seatArrange[SEATS]);//option E function.
void deleteallCustomer(struct AirLineSeat seatArrange[SEATS]);//option F function.
void saveData(struct AirLineSeat seatArrange[SEATS]);//option Q function that will save the data into a file and quit the profram.
void readData(struct AirLineSeat seatArrange[SEATS]);//read that file, which has saved before, it contains all the information we have assigned.




int main(void)
{	
	struct AirLineSeat seatArrange[SEATS];

	explainPrg(); //call the explainPrg function.
	readData(seatArrange);//call the readData function.
	
	return 0;
}

void readData(struct AirLineSeat seatArrange[SEATS]) // readData function.
{
	FILE *fp;
	if ((fp = fopen("D:\\mycustomer", "rb")) == NULL) // check that if the file is exist or not.
	{
		printf("\n\n\n\t\t\tDoesn't have any information customers file exist, begin to initialize all the seats...\n\n\t\t\t");
		system("pause");
		system("cls");
		initializeSeat(seatArrange); // if the file is not exist, call the initializeSeat function that will set up all 12 seats
		menuOptions(seatArrange);// call the menuOption function.
	}
	else//if the file exist, it will read the file which had already saved before, and put the file data in each of structure data.
	{
		fread(seatArrange, sizeof(struct AirLineSeat), SEATS, fp);
		fclose(fp);
		menuOptions(seatArrange);
	}
	
	return;
}

void explainPrg(void)// the explainPrg function, explain what program will do. 
{
	printf("\n\n\n\t\t\tThe Econo-Airlines fleet consists of one plane with a seating");
	printf("\n\t\t\tcapacity of 12. It makes one flight daily.");
	printf("\n\t\t\tThe aircraft seating is arranged in 6 rows with 2 seats per row.The");
	printf("\n\t\t\tprogram uses an array of 12 structures.Each structure holds a seat");
	printf("\n\t\t\tidentification number, a marker that indicates whether the seat is");
	printf("\n\t\t\tassigned, the last name of the seat holder, and the first name of the seat");
	printf("\n\t\t\tholder.\n\n\t\t\t");
	system("pause");
	system("cls");
	return;
}

void menuOptions(struct AirLineSeat seatArrange[SEATS]) // the menuOptions function.
{
	char options; //create a choice for menu.

	do
	{	
		printf("\n\n\n\t\t\tEcono-Flight Airline Reservation\n");
		printf("\n\n\n\t\t\tA.Display all the assignments(including Empty)");
		printf("\n\t\t\tB.Show ONLY a list of empty seats and show total of empty seats");
		printf("\n\t\t\tC.Show ONLY the assign seats with the name of person and total assigned");
		printf("\n\t\t\tD.Assign the customer to an empty seat");
		printf("\n\t\t\tE.Delete ONE seat assignment");
		printf("\n\t\t\tF.Delete ALL seat assignment");
		printf("\n\t\t\tQ.Quit Program");
		printf("\n\n\t\t\tPlease select your options:");
		fflush(stdin);
		scanf("%c", &options); // let the customer choose what the options they want. 
		system("cls");


		switch (options)
		{
		case 'A':
			allSeat(seatArrange); //option A.		
			break;
		case 'B':
			emptySeat(seatArrange);//option B.
			break;
		case 'C':
			assignedSeat(seatArrange);//option C.
			break;
		case 'D':
			assignCustomer(seatArrange);//option D.
			break;
		case 'E':
			deleteoneCustomer(seatArrange);//option E.
			break;
		case 'F':
			deleteallCustomer(seatArrange);//option F.
			break;
		case 'Q':
			saveData(seatArrange);//option Q.
			break;
		default:
			printf("\n\n\n\t\t\tYour options is not available,please select again\n\t\t\t");// if the customer doesn't choose the available options, it will notice and make the customer choose again.
			system("pause");
			system("cls");
			break;
		}
	} while (options != 'Q');// option Q will make the while-loop false, and exit the loop.
}

void initializeSeat(struct AirLineSeat seatArrange[SEATS])// initializeSeat function that will set up the seat.
{
	int seats;

	for (seats = 0; seats < SEATS; seats++) // set up 12 structures(seats) using for-loop
	{
		seatArrange[seats].id = seats + 1; // set up id from 1 to 12 
		seatArrange[seats].marker = FALSE;// make 12 seats empty.
		strcpy(seatArrange[seats].firstname, " ");//all 12 seats don't have first name.
		strcpy(seatArrange[seats].lastname, " ");//all 12 seats don't have last name. 

	}
	return;
}

void allSeat(struct AirLineSeat seatArrange[SEATS]) // allSeat function, that will show all the assigned and empty seats.
{
	int seats;
	printf("\n\n\n\n\n\t\t\t\t\t\t\tSEATING ARRANGEMENT\n");
	printf("\n\t\t\tSEATID\t\t\tSEAT STATUS\t\tLAST NAME\t\tFIRST NAME");
	for (seats = 0; seats < SEATS; seats++)//using for loop to check for all 12 seats.
	{

		if (seatArrange[seats].marker == TRUE)// TRUE means that the seat is assigned, and print all the assigned seats. 
		{
			printf("\n\t\t\t%d\t\t\tAssigned\t\t%s\t\t\t%s", seatArrange[seats].id, seatArrange[seats].lastname, seatArrange[seats].firstname);
		}
		else// Otherwise,it means FALSE, equivalent to empty and print all the empty seat. 
		{
			printf("\n\t\t\t%d\t\t\tEmpty\t\t%s\t\t\t%s", seatArrange[seats].id, seatArrange[seats].lastname, seatArrange[seats].firstname);
		}

	}
	printf("\n\n\t\t\t");
	system("pause");
	system("cls");
	return;
}

void emptySeat(struct AirLineSeat seatArrange[SEATS])// emptySeat function, that will show only the empty seat and count how many empty seats that they have left.
{
	int seats;
	int listofEmpty = 0;//count for empty seats.

	printf("\n\n\n\n\n\t\t\t\t\t\t\tSEATING ARRANGEMENT\n");
	printf("\n\t\t\tSEATID\t\t\tSEAT STATUS\t\tLAST NAME\t\tFIRST NAME");
	for (seats = 0; seats < SEATS; seats++) //using for loop to check for all 12 seats.
	{

		if (seatArrange[seats].marker == FALSE) //it means FALSE, equivalent to empty and print all the empty seat.

		{
			printf("\n\t\t\t%d\t\t\tEmpty\t\t%s\t\t\t%s", seatArrange[seats].id, seatArrange[seats].lastname, seatArrange[seats].firstname);
			listofEmpty++;//count for empty seats that each for-loop will count as one time
		}

	}
	printf("\n\n\t\t\tWe have %d empty seats right now", listofEmpty);// print the empty seats. 
	printf("\n\t\t\t");
	system("pause");
	system("cls");
	return;
}

void assignedSeat(struct AirLineSeat seatArrange[SEATS])// assignedSeat function that will only all the assigned seat, and how many customer has assigned thier seat.
{
	int seats;
	int listofAssigned = 0;//count for assigned seats.

	printf("\n\n\n\n\n\t\t\t\t\t\t\tSEATING ARRANGEMENT\n");
	printf("\n\t\t\tSEATID\t\t\tSEAT STATUS\t\tLAST NAME\t\tFIRST NAME");

	for (seats = 0; seats < SEATS; seats++)//using for loop to check for all 12 seats.
	{

		if (seatArrange[seats].marker == TRUE)// TRUE means that the seat is assigned, and print all the assigned seats. 
		{
			printf("\n\t\t\t%d\t\t\tAssigned\t\t%s\t\t\t%s", seatArrange[seats].id, seatArrange[seats].lastname, seatArrange[seats].firstname);
			listofAssigned++;//count for assigned seats that each for-loop will count as one time
		}
	}

	printf("\n\n\t\t\tWe have %d customer who has assigned thier seat.", listofAssigned);//print how many customer assigned seat
	printf("\n\n\t\t\t");
	system("pause");
	system("cls");
	return;
}

void assignCustomer(struct AirLineSeat seatArrange[SEATS])// call assignCustomer function, to assign customer into thier seat.
{
	int seats;
	printf("\n\n\n\t\t\tPlease the seat you want to assign:");
	scanf("%d", &seats);// this will let you choose which seat you want to assign customer into.

	while (seats < 1 || seats > 12) //it will let you choose from seat 1 to seat 12, out of this range will make you choose again.
	{
		system("cls");
		printf("\n\n\n\t\t\tYour choice is not available, please assign the seat again:");
		scanf("%d", &seats);// choose again the seat. 
	}

	if (seatArrange[seats - 1].marker == FALSE)// check that if the seat is Empty, so that we can assign customer. 
	{
		fflush(stdin);
		seatArrange[seats - 1].marker = TRUE; // this will make the seat assigned.
		printf("\n\t\t\tPlease enter your last name: ");
		gets(seatArrange[seats-1].lastname);//Enter lastname, and save lastname into the seat that we have choose for the customer.
		printf("\n\t\t\tPlease enter your first name: ");
		gets(seatArrange[seats-1].firstname);//Enter firstname, and save firstname into the seat that we have choose for the customer.
		printf("\n\n\t\t\tThe seat of %d assigned.\n\n\t\t\t", seatArrange[seats - 1].id);//notice that this seat has succesfully assigned.
		system("pause");
		system("cls");
	}
	else//if you assign the same seat again, it will notice that this seat has assigned, and you have to choose another seat.
	{
		printf("\n\t\t\tThis seat has already assigned, please assign another seat.\n\n\t\t\t");
		system("pause");
		system("cls");
	}
	return;

	
}

void deleteoneCustomer(struct AirLineSeat seatArrange[SEATS])// deleteoneCustomer function, that will delete the seat that you want to.
{
	int seats;
	printf("\n\n\n\t\t\tPlease the seat you want to delete:");
	scanf("%d", &seats);// this will let you choose which seat you want to delete.

	while (seats < 1 || seats > 12)//it will let you choose from seat 1 to seat 12, out of this range will make you choose again.
	{
		system("cls");
		printf("\n\n\n\t\t\tYour choice is not available, please assign the seat again:");
		scanf("%d", &seats);// choose again the seat. 
	}

	if (seatArrange[seats - 1].marker == TRUE)//checking that if the seat is assigned, so the program will begin to delete the seat.
	{
		seatArrange[seats - 1].marker = FALSE;//make the seat empty.
		strcpy(seatArrange[seats -1].firstname, " ");//delete the last name of the seat you choose.
		strcpy(seatArrange[seats -1].lastname, " ");//delete the first name of the seat you choose.
		printf("\n\n\t\t\tThe seat of %d deleted.\n\n\t\t\t", seatArrange[seats - 1].id);//notice that this seat has succesfully deleted.
		system("pause");
		system("cls");
	}
	else //if you delete the same seat again, it will notice that this seat has deleted, and you have to choose another seat.
	{
		printf("\n\t\t\tThis seat has already empty, please assign a customer.\n\n\t\t\t");
		system("pause");
		system("cls");
	}
	return;
}

void deleteallCustomer(struct AirLineSeat seatArrange[SEATS]) //deleteallCustomer function that will deletete all the customer information in that seat.
{
	int seats;

	for (seats = 0; seats < SEATS; seats++) //using for loop to access 12 seats.
	{
		if (seatArrange[seats].marker == TRUE)// checking that if every seats is assigned, so the program will begin to delete the seat.
		{

			seatArrange[seats].marker = FALSE;//if some of seats is assigned, it will make that seat is empty.
			strcpy(seatArrange[seats].firstname, " ");//delete the last name of the seat you choose.
			strcpy(seatArrange[seats].lastname, " ");//delete the first name of the seat you choose.
			printf("\n\t\t\tThe seat of %d deleted.", seatArrange[seats].id);
		}
		else//if you delete the same seat again, it will notice that this seat has deleted.
		{
			printf("\n\t\t\tThis seat of %d has already empty, please assign a customer.", seatArrange[seats].id);
		}
		
	}
	printf("\n\n\t\t\t");
	system("pause");
	system("cls");
	return;
}

void saveData(struct AirLineSeat seatArrange[SEATS]) //saveData function that will save all the the customer data into a file, 
{
	FILE *fp;
	int seats;
	if ((fp = fopen("D:\\mycustomer", "wb+")) == NULL) //Checking that the file is exist or not, and then it will create and begin to write a binary file into a disk, which we assigned into.
	{
		printf("Couldn't open file to write"); 
		exit(1);
	};
	fwrite(seatArrange, sizeof(struct AirLineSeat), SEATS, fp);//Writing all the 12 structure, equivalent to 12 seat information into a binary file.
	fclose(fp);

	printf("\n\n\n\n\n\t\t\t\t\t\t\tSEATING ARRANGEMENT SAVING\n");
	printf("\n\t\t\tSEATID\t\t\tSEAT STATUS\t\tLAST NAME\t\tFIRST NAME");
	for (seats = 0; seats < SEATS; seats++) //This will show all the customer information, before saving into a file.
	{
		if (seatArrange[seats].marker == TRUE)
		{
			printf("\n\t\t\t%d\t\t\tAssigned\t\t%s\t\t\t%s", seatArrange[seats].id, seatArrange[seats].lastname, seatArrange[seats].firstname);
		}
		else
		{
			printf("\n\t\t\t%d\t\t\tEmpty\t\t%s\t\t\t%s", seatArrange[seats].id, seatArrange[seats].lastname, seatArrange[seats].firstname);
		}
	}
	printf("\n\n\t\t\t");
	system("pause");
	return;
}