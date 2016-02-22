////////////////////////////////////////////////////////
// ECE 3574, Homework 2, Bowei Zhao
//// ID: 905789193
// email: bowei@vt.edu
// File name: entertainment.h
// Description: entertainment header file
// Date: 2/17/2016
//
// *-----------------------------------------------* //

#ifndef ENTERTAINMENT_H
#define ENTERTAINMENT_H

#include "film.h"

enum FilmTypes {Action=1, Comedy=2, Scifi=3, Horror=4};
enum MPAARatings {G=1, PG=2, PG13=3, R=4};

class Entertainment : public Film
{
	public:
		// Constructor with Parameters
		Entertainment(QString id, QString title, QString dir, quint32 len, QDate relDate, FilmTypes type, MPAARatings rtng);
		Entertainment(QStringList propList);
		QString toString(bool labeled, QString sepchar);
		int giveType();
		int giveRate();
	private:
		FilmTypes m_Type;
		MPAARatings m_Rating;
};



#endif // ENTERTAINMENT_H