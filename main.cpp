////////////////////////////////////////////////////////
// ECE 3574, Homework 2, Bowei Zhao
//
// File name: main.cpp
// Description: main implementation file
// Date: 2/17/2016
//
// *-----------------------------------------------* //
#include <QCoreApplication>
#include <QTextStream>
#include <film.h>
#include <entertainment.h>
#include <educational.h>
#include <filmlist.h>


// Global input and output. Used because example client does this. 
// enum choices used for menu option selection

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    enum menuChoice {ADD_FILM=1, REMOVE_FILM=2, GET_ID=3, FIND_FILM=4, LIST=5, QUIT=6};
    menuChoice select;

    QTextStream outS(stdout);
    QTextStream inS(stdin);
    QTextStream errS(stderr); // error stream for standard error exception
    
    int sel_choice;
    
    QString f_id, f_title, f_dir;
    quint32 f_len;

    QDate f_relDate;
    QString lookforID, lookfortitle;
    FilmList listfilm; // here
    


        // Initializes variables to store Educational Class objects
    QString ed_subject;
    Grade ed_grade;

    QString empty; // used soley as an empty QString
    QString tempCheck;
    empty.clear();

    // Initializes variables to store Entertainment Class objects
    FilmTypes en_type;

    MPAARatings en_rtng;

    while(1) {
        outS << ADD_FILM << " - Add a film.\n"
             << REMOVE_FILM << " - Remove a film.\n"
             << GET_ID << " - Get Film ID by searching Title.\n"
             << FIND_FILM << " - Get Film Title by searching ID.\n"
             << LIST << " - List all Films .\n"
              << QUIT << " - Quit Program .\n"
             << "Your choice(#): " << flush;
        sel_choice = inS.readLine().toInt();
        select = static_cast<menuChoice>(sel_choice);

        switch(select) {
        case ADD_FILM: {
            outS << "\n" << "Please input a unique ID# for this film: " << flush;
            tempCheck = inS.readLine();
            while ((listfilm.checkValid(tempCheck)) == 1 )
            {
                errS << "Invalid ID#, it is already in use. Try again" << flush;
                outS << "\n" << "Please input a unique ID# for this film: " << flush;
                tempCheck = inS.readLine();
            }
            f_id = tempCheck; // input is now valid so assign value and continue
            
            outS << "\n" << "Please input the film title: " << flush;
            f_title = inS.readLine();

            outS << "\n" << "Please input the film's director: " << flush;
            f_dir = inS.readLine();

            outS << "\n" << "Please input the film's length in minutes: " << flush;
            tempCheck = inS.readLine();
            while ((listfilm.checkValid(empty,empty,empty,tempCheck)) == 2 )
            {
                errS << "Invalid film length.Try again" << flush;
                outS << "\n" << "Please input the film's length in minutes as an integer: " << flush;
                tempCheck = inS.readLine();
                
            }
            f_len = tempCheck.toInt();// input now valid reads in film length as QString and converts to Int
            
            outS << "\n" << "Please input the film's original release date in yyyy-MM-dd: " << flush;
            tempCheck = inS.readLine();
            while ((listfilm.checkValid(empty,empty,empty,empty,tempCheck)) == 3 )
            {
                errS << "Invalid date format. Try again." << flush;
                outS << "\n" << "Please input the film's original release date in yyyy-MM-dd: " << flush;
                tempCheck = inS.readLine();
            }
            f_relDate = QDate::fromString(tempCheck, "yyyy-MM-dd"); // QDate now valid so assigning to value
            
            //qDebug() << "Output of add function is: " << f_id << f_title << f_dir << f_len << f_relDate << flush;
            int filmchoice;
            outS << "\n" << "Enter the # corresponding to the type of film this is: "<< endl;
            outS << " 1 -- General Film" << endl;
            outS << " 2 -- Educational Film" << endl;
            outS << " 3 -- Entertainment Film" << endl;

            outS << "Your choice(#): " << flush;
            filmchoice = inS.readLine().toInt();
            Film* newFilm;
            

            while ((filmchoice < 1) || (filmchoice > 3)) // if the choice from user is not valid, run code
            {
                errS << "Number choice not valid. Try again." << endl;
                outS << "Your choice(#): " << flush;
                filmchoice = inS.readLine().toInt();
            }

            if (filmchoice == 1)
            {
                newFilm = new Film(f_id, f_title, f_dir, f_len, f_relDate);
                
            }
            else if (filmchoice == 2)
            {
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

                newFilm = new Educational(f_id, f_title, f_dir, f_len, f_relDate, ed_subject, ed_grade);
                //listfilm.addFilm(newFilm);
               // qDebug() << "Output of add educational function is: " << f_id << f_title << f_dir << f_len << f_relDate << ed_subject <<ed_grade << flush;


            }
            else if (filmchoice == 3)
            {
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

                newFilm = new Entertainment(f_id, f_title, f_dir, f_len, f_relDate, en_type, en_rtng);
                //listfilm.addFilm(newFilm);
                //qDebug() << "Output of add entertainment function is: " << f_id << f_title << f_dir << f_len << f_relDate << en_type <<en_rtng << flush;

            }
            listfilm.addFilm(newFilm);
        }
            break;
        case REMOVE_FILM: {
            outS << "\n" <<"Please input the ID of the film you wish to remove: " << flush;
            QString trashfilm; // qstring to store ID to delete film.
            trashfilm = inS.readLine();
            listfilm.removeFilm(trashfilm); // call function to remove the film. 

        }
            break;
        case GET_ID: {
            outS << "\n" << "Enter the Films Title to get ID#:" << flush;
            QStringList searchList;
            lookfortitle = inS.readLine();

            searchList = listfilm.getID(lookfortitle);
            for (int i=0; i< searchList.size(); i++)
            {
                outS << "\n" << "The search " << lookfortitle << " has ID# of " <<
                searchList.at(i) << endl;
            }

        }
            break;
        case FIND_FILM: {
            outS << "\n" << "Enter the Films ID# to get Title Name:" << flush;

            lookforID = inS.readLine();
            outS << listfilm.findFilm(lookforID)->toString(true, "\n");
            //Film* newFilm = listfilm.findFilm(lookforID);
            //QString fin_out = newFilm->toString(true, "\n");
            //outS << fin_out <<endl;
            
        }
            break;
        case LIST: {
            outS << "Printing all films" << endl;
            outS << listfilm.toString() << endl;

        }
            break;
        case QUIT: {
            outS << "Exiting Program" << endl;
            exit(0);

        }    
            break;
        default: {
            outS << "System Error, Program Exiting" << endl;
            exit(0);
        }
        }
    }

    return a.exec();
}