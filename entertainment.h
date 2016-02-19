////////////////////////////////////////////////////////
// ECE 3574, Homework 2, Bowei Zhao
//
// File name: entertainment.h
// Description: entertainment header file
// Date: 2/17/2016
//
// *-----------------------------------------------* //

#ifndef ENTERTAINMENT_H
#define ENTERTAINMENT_H

#include "film.h"

enum FilmTypes {Action, Comedy, Scifi};
enum MPAARatings {G, PG, PG13, R};

class Entertainment : public Film
{
	public:
		// Constructor with Parameters
		Entertainment(QString id, QString title, QString dir, quint32 len, QDate relDate, FilmTypes type, MPAARatings rtng);
		Entertainment(QStringList propList);
		QString toString(bool labeled, QString sepchar);
	private:
		FilmTypes m_Type;
		MPAARatings m_Rating;
};



#endif // ENTERTAINMENT_H