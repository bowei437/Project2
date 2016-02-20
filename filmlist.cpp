////////////////////////////////////////////////////////
// ECE 3574, Homework 2, Bowei Zhao
//
// File name: filmlist.cpp
// Description: filmlist implementation file
// Date: 2/17/2016
//
// *-----------------------------------------------* //
#include "filmlist.h"

QString FilmList::toString()
{
	qDebug() << "	Debug: FilmList toString" << endl;
	QString retvalStr;

	QString newline = "\n";
	QString brackchar = "[::]";

	for (int i = 0; i < q_list.size(); i++)
	{
		retvalStr += q_list.at(i)->toString(false, brackchar) + newline; // calls each Film's toString method
		// uses QString += overloaded operator to add strings together. Uses 'this -> to point to the pointers
		// actual toString method giving it false for sepchar with a bracket character.
	}

	return retvalStr;
}



int FilmList::checkValid(QString c_id, QString c_title, QString c_dir, QString c_len, QString c_relDate)
{
	qDebug() << "\n" <<"	Debug: FilmList checkValid";
	//qDebug() << "Passed in: " << c_id << c_title << c_dir << c_len << c_relDate << endl;

	if(!(c_id.isEmpty()))
	{
		//qDebug() << "Running ID Check" << flush;
		for (int i = 0; i < q_list.size(); i++)
		{
			if(q_list.at(i)->getID() == c_id)
			{
				//qDebug() << "ID already exists" << flush;
				return 1;
			}
		}
	}

	if(!(c_len.isEmpty()))
	{
		//qDebug() << "Running length Check" << flush;
		if ((c_len.toInt()) == 0) // if conversion fails, meaning not an integer
		{
			return 2;
		}

	}

	if(!(c_relDate.isEmpty()))
	{
		//qDebug() << "Running date Check" << flush;
		QDate tempDate;

		tempDate = QDate::fromString(c_relDate, "yyyy-MM-dd");
		if (!(tempDate.isValid()))
		{
			return 3;
		}

	}


	return 0; // else return 0 for normal operation
}

QStringList FilmList::getID(QString title)
{
	qDebug() << "	Debug: FilmList getID" << endl;
	QStringList retIDVal; // variable to finally return

	// temporary holding variables to store
	QString t_title; // stores temporary title
	QString t_ID; // stores temporary ID

	for (int i = 0; i < q_list.size(); i++)
	{
		//t_title = q_list.at(i)->giveTitle();
		//t_ID = q_list.at(i)->getID();
		if(t_title == title)
		{
			retIDVal.append(t_ID); // add temporary ID number to be stored
		}
	}
	return retIDVal;



}

Film* FilmList::findFilm(QString id)
{
	qDebug() << "	Debug: FilmList findFilm" << endl;
	Film* retFilmVal; // variable to return of type class Film

	//QString t_title; // stores temporary title
	//QString t_ID; // stores temporary ID
	for (int i = 0; i < q_list.size(); i++)
	{
		//t_title = q_list.at(i)->giveTitle();
		//t_ID = q_list.at(i)->getID();
		if(q_list.at(i)->getID() == id)
		{
			//qDebug() << "Before assignment found" << endl;
			retFilmVal = q_list.at(i); // gives QList<Film> holding type Film to return value
			//qDebug() << "Successfully found" << endl;
		}

	}

	return retFilmVal;
}

void FilmList::addFilm(Film* film)
{
	/*
	qDebug() << "	Debug: FilmList addFilm" << endl;
	
	if (q_list.contains(film))
	{
		qDebug() << film << "already in q_list" << endl;

	}
	else
	{
		q_list.append(film); // add film to list 
		qDebug() << film << "is now added" << endl;
	}
	*/

	qDebug() << "   DEBUG: FilmList addFilm" << endl;
    if(!q_list.contains(film))
        q_list.append(film);
    qDebug() << film << "is now added" << endl;

}

void FilmList::removeFilm(QString filmID)
{
	qDebug() << "	Debug: FilmList removeFilm" << endl;
	QString tempID;
	for (int i = 0; i < q_list.size(); i++)
	{
		tempID = q_list.at(i)->getID();

		if (tempID == filmID)
		{
			q_list.removeAt(i);
			qDebug() << "Removed ID " << tempID;
		}

	}


}