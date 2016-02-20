////////////////////////////////////////////////////////
// ECE 3574, Homework 2, Bowei Zhao
//
// File name: main.cpp
// Description: main implementation file
// Date: 2/17/2016
//
// *-----------------------------------------------* //
#include "film.h"
#include "entertainment.h"
#include "educational.h"
#include "filmlist.h"

// Global input and output. Used because example client does this. 
QTextStream outS(stdout); // output stream to standard output
QTextStream inS(stdin); // input stream to standard input
QTextStream errS(stderr); // error stream for standard error exception

// enum choices used for menu option selection
enum menuChoice {ADD_FILM=1, REMOVE_FILM=2, GET_ID=3, FIND_FILM=4, QUIT=5};
FilmList listfilm; // make new FilmList variable 

menuChoice taskPanel()
{
	//qDebug() << " 		MENU ITEM: taskPanel" << endl;
	int sel_choice; // stores choice of selection

    outS << ADD_FILM << " - Add a film.\n"
         << REMOVE_FILM << " - Remove a film.\n"
         << GET_ID << " - Get Film ID by searching Title.\n"
         << FIND_FILM << " - Get Film Title by searching ID.\n"
         << QUIT << " - Quit the program.\n"
         << "Your choice(#): " << flush;

    sel_choice = inS.readLine().toInt(); // gets input from keyboard
    if ((sel_choice < 1) || (sel_choice > 5)) // if the choice from user is not valid, run code
    {
    	// standard error output and function call.
    	errS << "\n \n" <<"Input is not valid!" << "\n"
    	<< "Please provide a number between " << ADD_FILM << " and " << QUIT << endl;
    	taskPanel(); // recursively call own function if given values are not correct
    }
    return static_cast<menuChoice>(sel_choice); // casting int to type enum so I can return menuChoice, like in example
}

// Function to add film. Generic base class first. Takes and returns nothing/void
void addfilm(void)
{
	//QTextStream outS(stdout);
	qDebug() << "\n" << "	Function: Add Film" << endl;

	// Initializes variables to store FILM Class objects
	QString f_id, f_title, f_dir;
	quint32 f_len;
	QDate f_relDate;

	QString empty; // used soley as an empty QString
	QString tempCheck;
	empty.clear();



	outS << "\n" << "Please input a unique ID# for this film: " << flush;
	f_id = inS.readLine();
	/*
	tempCheck = inS.readLine();
	if ((listfilm.checkValid(tempCheck)) == 1 )
	{
		errS << "Invalid ID#, it is already in use. Returning to main menu" << flush;
		return;
	}
	else // else, it is valid, we will assign inputted QString into actual variable
	{
		f_id = tempCheck;
	}
	*/
	outS << "\n" << "Please input the film title: " << flush;
	f_title = inS.readLine();

	outS << "\n" << "Please input the film's director: " << flush;
	f_dir = inS.readLine();

	outS << "\n" << "Please input the film's length in minutes: " << flush;
	f_len = inS.readLine().toInt();
	/*
	tempCheck = inS.readLine();
	if ((listfilm.checkValid(empty,empty,empty,tempCheck)) == 2 )
	{
		errS << "Invalid film length.Returning to main menu" << flush;
		return;
	}
	else // else, it is valid, we will assign inputted QString into actual variable
	{
		f_len = tempCheck.toInt();// reads in film length as QString and converts to Int
	}
	*/

	outS << "\n" << "Please input the film's original release date in yyyy-MM-dd: " << flush;
	f_relDate = QDate::fromString(inS.readLine(), "yyyy-MM-dd");
	/*
	tempCheck = inS.readLine();
	if ((listfilm.checkValid(empty,empty,empty,empty,tempCheck)) == 3 )
	{
		errS << "Invalid date format. Returning to main menu" << flush;
		return;
	}
	else // else, it is valid, we will assign inputted QString into actual variable
	{
		f_relDate = QDate::fromString(tempCheck, "yyyy-MM-dd");
	}
	*/
	//qDebug() << "Output of add function is: " << f_id << f_title << f_dir << f_len << f_relDate << flush;
	int filmchoice;

	outS << "\n" << "Enter the # corresponding to the type of film this is: "<< endl;
	outS << " 1 -- General Film" << endl;
	outS << " 2 -- Educational Film" << endl;
	outS << " 3 -- Entertainment Film" << endl;

	outS << "Your choice(#): " << flush;
	filmchoice = inS.readLine().toInt();

	while ((filmchoice < 1) || (filmchoice > 3)) // if the choice from user is not valid, run code
	{
		outS << "Your choice(#): " << flush;
		filmchoice = inS.readLine().toInt();
	}


	if (filmchoice == 1)
	{
		Film genfilm(f_id, f_title, f_dir, f_len, f_relDate);
		listfilm.addFilm(&genfilm);
		qDebug() << "Output of add general function is: " << f_id << f_title << f_dir << f_len << f_relDate << flush;
	}

	if (filmchoice == 2)
	{
		// Initializes variables to store Educational Class objects
		QString ed_subject;
		Grade ed_grade;
		int tempInt;// stores temporary integer for conversion

		outS << "\n" <<"Please input the film's subject: " << flush;
		ed_subject = inS.readLine();

		outS << "\n" <<"Please input the film's Grade Level intent (1, 2, 3, 4, 5): " << flush;
		tempInt = inS.readLine().toInt();
		while ((tempInt == 0) || (tempInt < 1) || (tempInt > 5))
		{
			errS << "Invalid entry! Please provide a number integer from 1 to 5 as input" << endl;
			outS << "\n" <<"Please input the film's Grade Level intent (1, 2, 3, 4, 5): " << flush;
			tempInt = inS.readLine().toInt();
		}

		ed_grade = static_cast<Grade>(tempInt);

		Educational newEdfilm(f_id, f_title, f_dir, f_len, f_relDate, ed_subject, ed_grade);
		listfilm.addFilm(&newEdfilm);

		qDebug() << "Output of add educational function is: " << f_id << f_title << f_dir << f_len << f_relDate << ed_subject <<ed_grade << flush;

	}

	if (filmchoice == 3)
	{
			
		//QString matchName; // used to match string input to enum input
		// Initializes variables to store Entertainment Class objects
		FilmTypes en_type;
		MPAARatings en_rtng;
		int tempInt2; // stores temporary integer for conversion

		outS << "\n" <<"Please input the film's FilmType by number in paranthesis( Action(1), Comedy(2), Scifi(3), Horror(4) ): " << flush;
		tempInt2 = inS.readLine().toInt();
		while ((tempInt2 == 0) || (tempInt2 < 1) || (tempInt2 > 4))
		{
			errS << "Invalid entry! Please provide a number integer from 1 to 4 as input" << endl;
			outS << "\n" <<"Please input the film's FilmType by number in paranthesis( Action(1), Comedy(2), Scifi(3), Horror(4) ): " << flush;
			tempInt2 = inS.readLine().toInt();
		}
		en_type = static_cast<FilmTypes>(tempInt2);

		outS << "\n" <<"Please input the film's MPAA Rating by number in paranthesis( G(1), PG(2), PG-13(3), R(4) ): " << flush;
		tempInt2 = inS.readLine().toInt();
		while ((tempInt2 == 0) || (tempInt2 < 1) || (tempInt2 > 4))
		{
			errS << "Invalid entry! Please provide a number integer from 1 to 4 as input" << endl;
			outS << "\n" <<"Please input the film's MPAA Rating by number in paranthesis( G(1), PG(2), PG-13(3), R(4) ): " << flush;
			tempInt2 = inS.readLine().toInt();
		}
		en_rtng = static_cast<MPAARatings>(tempInt2);

		Entertainment newEnfilm(f_id, f_title, f_dir, f_len, f_relDate, en_type, en_rtng);
		listfilm.addFilm(&newEnfilm);

		qDebug() << "Output of add entertainment function is: " << f_id << f_title << f_dir << f_len << f_relDate << en_type <<en_rtng << flush;

	}
	return;


}

void locfindfilm()
{
	
	qDebug() << "\n" << "	Function: locfindfilm" << endl;
	QString locID;

	outS << "Please input the ID of the film you want to find: " << flush;
	locID = inS.readLine();

	//Film *locfoundfilm;
	//listfilm.findFilm(locID);


	outS << "local found film is: " << listfilm.findFilm(locID)->toString(true,"\n") << endl;



}


int main (int argc, char* argv[])
{
	QCoreApplication f(argc, argv); // starts default handler application

	int Global_Error = 0; // used for error handling specific statements

	while(1) // constant running loop
	{
		try // try catch error exception handling
		{
			switch (taskPanel()) // Calls function to select choice and also switches between the options produced
			{
				case ADD_FILM:
					qDebug() << "\n" << "	TASK CHOICE: Add Film" << endl;
					addfilm();
					break;

				case REMOVE_FILM:
					qDebug() << "\n" << "	TASK CHOICE: Remove Film" << endl;
					break;

				case GET_ID:
					qDebug() << "\n" <<  "	TASK CHOICE: Get ID" << endl;
					break;

				case FIND_FILM:
					qDebug() << "\n" <<  "	TASK CHOICE: Find Film" << endl;
					locfindfilm();
					break;

				case QUIT:
					qDebug() << "\n" << "	TASK CHOICE: QUIT" << endl;
					break;

				default:
					break;

			}


		}
		catch (std::exception& e) // EXCEPTION HANDLING 
		{
			std::cerr << e.what(); // I output the default ERROR PHRASE

			// Tthe following errors below are self explanatory. They describe different patterns for bad input
			if (Global_Error == 1)
			{

			}


		}

	}


	return f.exec();
}













// used to store my exception and do a const output
class defErrception: public exception
{
  virtual const char* what() const throw()
  {
    return "   ERROR      ";
  }
} defErr;