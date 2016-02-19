////////////////////////////////////////////////////////
// ECE 3574, Homework 2, Bowei Zhao
//
// File name: entertainment.cpp
// Description: entertainment implementation file
// Date: 2/17/2016
//
// *-----------------------------------------------* //

#include "entertainment.h"

//Constructor with Parameters
Entertainment::Entertainment(QString id, QString title, QString dir, quint32 len, QDate relDate, FilmTypes type, MPAARatings rtng)
	:Film(id, title, dir, len, relDate) // using initialization list
{
	m_Type = type;
	m_Rating = rtng;

	qDebug() << "	Debug: Entertainment Constructor" << endl;

}

Entertainment::Entertainment(QStringList propList)
	:Film(propList.at(0), propList.at(1), propList.at(2), propList.at(3).toInt(), QDate::fromString(propList.at(4), "yyyy-MM-dd"))
{

	m_Type = propList.at(5).toInt();
	m_Rating = propList.at(6).toInt();

	qDebug() << "	Debug: Entertainment propList" << endl;

}

QString Entertainment::toString(bool labeled, QString sepchar)
{
	QString retvalStr;
	if (labeled == true)
	{
		

	}
	else if (labeled == false)
	{

	}


}