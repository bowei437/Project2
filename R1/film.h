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

#include <QCoreApplication>
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
#include <QVector>

#include <iostream>
#include <fstream>
#include <algorithm> 
#include <string>
#include <vector>
#include <exception>
#include <stdio.h>
#include <typeinfo>


using namespace std;


typedef quint32 Length;

// Film is the base class of the entire branch of children. 
class Film
{
	public:
		// Functions that are used to modify and give access to the private held variables
		Film(QString id, QString title, QString dir, quint32 len, QDate relDate);
		Film(QStringList propList);
		QString giveTitle();
		QString giveDir();
		quint32 giveLen();
		QDate giveDate();
		QString getID();
		QStringList giveAll() const;
		virtual QString toString(bool labeled, QString sepchar);
	private:
		QString m_FilmID;
		QString m_Title;
		QString m_Director;
		Length m_FilmLength;
		QDate m_ReleaseDate;
};



#endif // FILM_H