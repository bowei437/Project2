////////////////////////////////////////////////////////
// ECE 3574, Homework 2, Bowei Zhao
//// ID: 905789193
// email: bowei@vt.edu
// File name: filmlist.h
// Description: filmlist header file
// Date: 2/17/2016
//
// *-----------------------------------------------* //

#ifndef FILMLIST_H
#define FILMLIST_H

#include "film.h"

class FilmList : public QList<Film*>
{
	public:
		FilmList() {}
		QString toString();
		Film* findFilm(QString id);
		QStringList getID(QString title);
		void addFilm(Film* film);
		void removeFilm(QString filmID);
		int checkValid(QString c_id="", QString c_title="", QString c_dir="", QString c_len="", QString c_relDate="");
		int duplicate(QString d_title, QString d_dir, int d_len, QDate d_relDate);

	private:
		QList<Film*> q_list;


};





#endif // FILMLIST_H