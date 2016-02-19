////////////////////////////////////////////////////////
// ECE 3574, Homework 2, Bowei Zhao
//
// File name: film.cpp
// Description: film implementation file
// Date: 2/17/2016
//
// *-----------------------------------------------* //
#include "film.h"

// Constructor with Parameters
Film::Film(QString id, QString title, QString dir, quint32 len, QDate relDate)
{
	m_FilmID = id;
	m_Title = title;
	m_Director = dir;
	m_FilmLength = len;
	m_ReleaseDate = relDate;
	qDebug() << "	Debug: Film Constructor" << endl;
}

Film::Film(QStringList propList)
{
	quint32 len_convert = propList.at(3).toInt();
	QDate date_convert = QDate::fromString(propList.at(4), "yyyy-MM-dd");

	m_FilmID = propList.at(0);
	m_Title = propList.at(1);
	m_Director = propList.at(2);
	m_FilmLength = len_convert;
	m_ReleaseDate = date_convert;
	qDebug() << "	Debug: Film propList" << endl;

}

QString Film::toString(bool labeled, QString sepchar)
{

}