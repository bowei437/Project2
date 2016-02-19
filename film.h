////////////////////////////////////////////////////////
// ECE 3574, Homework 2, Bowei Zhao
//
// File name: film.h
// Description: film header file
// Date: 2/17/2016
//
// *-----------------------------------------------* //

#ifndef FILM_H
#define FILM_H

#include <QDate>
#include <QDateTime>
#include <QFile>
#include <QString>
#include <QStringList>
#include <QList>
#include <QTextStream>
#include <QDebug>
#include <QLocale>
#include <QtAlgorithms>
#include <QChar>

#include <iostream>
#include <fstream>
#include <algorithm> 
#include <string>
#include <vector>
#include <exception>
#include <stdio.h>

typedef quint32 Length;

class Film
{
	public:
		Film(QString id, QString dir, quint32 LengthF, QDate relDate);
		Film(QString propList);
		virtual QString toString(bool labeled, QString sepchar);
	private:
		QString m_FilmID;
		QString m_Title;
		QString m_Director;
		Length m_FilmLength;
		QDate m_ReleaseDate;
};


#endif // FILM_H