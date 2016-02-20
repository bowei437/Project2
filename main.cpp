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

    enum menuChoice {ADD_FILM=1, REMOVE_FILM=2, GET_ID=3, FIND_FILM=4, QUIT=5};
    menuChoice select;

    QTextStream outS(stdout);
    QTextStream inS(stdin);
    FilmList listfilm;

    int sel_choice;
    
    QString id, title, dir, subject;
    quint32 len;

    QDate relDate;
    QString lookforID;

    //Grade grade;
    //MPAARatings rtng;
    //FilmTypes type;

    while(1) {
        outS << ADD_FILM << " - Add a film.\n"
             << REMOVE_FILM << " - Remove a film.\n"
             << GET_ID << " - Get Film ID by searching Title.\n"
             << FIND_FILM << " - Get Film Title by searching ID.\n"
             << QUIT << " - Quit the program.\n"
             << "Your choice(#): " << flush;
        sel_choice = inS.readLine().toInt();
        select = static_cast<menuChoice>(sel_choice);

        switch(select) {
        case ADD_FILM: {
            outS << "Enter the Films ID:" << endl;
            id = inS.readLine();
            outS << "Enter the Films Title:" << endl;
            title = inS.readLine();
            outS << "Enter the Films Director:" << endl;
            dir = inS.readLine();
            outS << "Enter the Films Length(numbers > 0):" << endl;
            len = inS.readLine().toInt();
            while(len <= 0) {
                outS << "Please enter a number greater than 0..." << endl;
                inS >> len;
            }
            outS << "Enter the Films Date (yyyy-MM-dd):" << endl;
            relDate = QDate::fromString(inS.readLine(), "yyyy-MM-dd");
            while(!relDate.isValid()) {
                outS << "Please enter a valid date in yyyy-MM-dd format" << endl;
                relDate = QDate::fromString(inS.readLine(), "yyyy-MM-dd");
            }
            Film newFilm(id, title, dir, len, relDate);
            listfilm.addFilm(&newFilm);
        }
            break;
        case REMOVE_FILM: {

        }
            break;
        case GET_ID: {

        }
            break;
        case FIND_FILM: {
            outS << "Enter the Films ID to get details:" << endl;
            lookforID = inS.readLine();
            outS << listfilm.findFilm(lookforID)->toString(true,"\n");

        }
            break;
        case QUIT: {


        }
            break;
        default: {
            outS << "Bad menu input. Exiting." << endl;
            exit(0);
        }
        }
    }

    return a.exec();
}
