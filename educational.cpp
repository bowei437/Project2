////////////////////////////////////////////////////////
// ECE 3574, Homework 2, Bowei Zhao
//
// File name: educational.cpp
// Description: educational implementation file
// Date: 2/17/2016
//
// *-----------------------------------------------* //

#include "educational.h"


Educational::Educational(QString id, QString title, QString dir, quint32 len, QDate relDate, QString subject, Grade grade)
	:Film(id, title, dir, len, relDate)
{
	m_Subject = subject;
	m_GradeLevel = grade;


	qDebug() << "	Debug: Educational Constructor" << endl;
}

Educational::Educational(QStringList propList)
	:Film(propList.at(0), propList.at(1), propList.at(2), propList.at(3).toInt(), QDate::fromString(propList.at(4), "yyyy-MM-dd"))
{
	m_Subject = propList.at(5);
	m_GradeLevel = propList.at(6).toInt();

	qDebug() << "	Debug: Educational propList" << endl;

}

QString Educational::toString(bool labeled, QString sepchar)
{
	

}