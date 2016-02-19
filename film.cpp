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
	QString retvalStr;
	// QString top/bottom used to concatante string outputs
	QString top; 
	QString bottom;

	QString convert_num;
	QString convert_date;

	// Qstring convert_num/convert/date used to convert private vars to QString 
	convert_num = QString::number(m_FilmLength); // converts filmlength to base10 string output	
	convert_date = m_ReleaseDate.toString("yyyy-MM-dd");

	if (labeled == true) // sees that output is to be labeled
	{	
		top = "ID: " + m_FilmID + sepchar + "Title: " + m_Title + sepchar + "Director: " + m_Director + sepchar + "Runtime: "; 
		bottom = convert_num + sepchar + "Released: " + convert_date + sepchar;

	}
	else if (labeled == false) // if it doesn't want labeled output
	{
		top = m_FilmID + sepchar + m_Title + sepchar + m_Director + sepchar; // overloads + QString operator

		bottom = convert_num + sepchar + convert_date + sepchar; // adds strings together

	}

	retvalStr = top + bottom; // final QString concatanation to combine
	return retvalStr; // returns the final string for printing

}