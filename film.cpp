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
    : m_FilmID(id), m_Title(title), m_Director(dir), m_FilmLength(len), m_ReleaseDate(relDate) {
	qDebug() << "	Debug: Film Constructor" << endl;

	qDebug() << "Output of Film Constructor is: " << m_FilmID << m_Title << m_Director << m_FilmLength << m_ReleaseDate << endl;
	}
/*
Film::Film(QString id, QString title, QString dir, quint32 len, QDate relDate)
{
	qDebug() << "	Debug: Film Constructor" << endl;
	// default constructor operations
	m_FilmID = id;
	m_Title = title;
	m_Director = dir;
	m_FilmLength = len;
	m_ReleaseDate = relDate;

	qDebug() << "Output of Film Constructor is: " << m_FilmID << m_Title << m_Director << m_FilmLength << m_ReleaseDate << endl;

	
}
*/

QStringList Film::giveAll() const
{
	qDebug() << "	Debug: Film giveAll" << endl;

	// uses a temporary stringlist to store all private variables into locations on list
	// locations are always set following same pattern
	// used to return a stringlist with everything in it 
	const QStringList tempList;
	QString convert_num;
	QString convert_date;

	// Qstring convert_num/convert/date used to convert private vars to QString 
	convert_num = QString::number(m_FilmLength); // converts filmlength to base10 string output	
	convert_date = m_ReleaseDate.toString("yyyy-MM-dd");
	/*
	tempList.at(0) = m_FilmID;
	tempList.at(1) = m_Title;
	tempList.at(2) = m_Director;
	tempList.at(3) = convert_num;
	tempList.at(4) = convert_date;
	*/
	
	/*
	tempList.at(0)->m_FilmID;
	tempList.at(1)->m_Title;
	tempList.at(2)->m_Director;
	tempList.at(3)->convert_num;
	tempList.at(4)->convert_date;
	*/
	
	
	return tempList;
}

Film::Film(QStringList propList) 
{
	qDebug() << "	Debug: Film propList constructor" << endl;

	
	QDate date_convert = QDate::fromString(propList.at(4), "yyyy-MM-dd");

	m_FilmID = propList.at(0);
	m_Title = propList.at(1);
	m_Director = propList.at(2);
	quint32 len_convert = propList.at(3).toInt();
	m_FilmLength = len_convert;
	m_ReleaseDate = date_convert;
	

	qDebug() << "Output of Film propList is: " << m_FilmID << m_Title << m_Director << m_FilmLength << m_ReleaseDate << endl;

}

QString Film::toString(bool labeled, QString sepchar)
{
	qDebug() << "	Debug: Film toString" << endl;
	/*

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
	*/
	QString retString;
    if(labeled) {
        retString = "ID: " + m_FilmID + sepchar
                + "Title: " + m_Title + sepchar
                + "Director: " + m_Director + sepchar
                + "Length (min): " + QString::number(m_FilmLength) + sepchar
                + "Release Date: " + m_ReleaseDate.toString("yyyy-MM-dd") + sepchar;
    }
    else {
        retString = m_FilmID + sepchar
                + m_Title + sepchar
                + m_Director + sepchar
                + m_FilmLength + sepchar
                + m_ReleaseDate.toString("yyyy-MM-dd") + sepchar;
    }

    return retString;

}

QString Film::giveTitle()
{
	qDebug() << "	Debug: Film giveTitle" << endl;

	return m_Title;
}

QString Film::getID() {
     qDebug() << "  DEBUG: Film getID" << endl;
    return m_FilmID;
}

/*
QString Film::getID()
{
	qDebug() << "	Debug: Film getID" << endl;

	return m_FilmID;
}
*/