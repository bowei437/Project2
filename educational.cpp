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
	int conv_cast = propList.at(6).toInt();
	Grade m_GradeLevel = (Grade)conv_cast;


	qDebug() << "	Debug: Educational propList" << endl;

}

QString Educational::toString(bool labeled, QString sepchar)
{
	QString retvalStr;
	// QString top/bottom used to concatante string outputs

	QString top; 
	QString bottom;
	if (labeled == true) // sees that output is to be labeled
	{		
		top = "Subject: " + m_Subject+ sepchar; // overloads + QString operator
		bottom = "Grade: " + m_GradeLevel + sepchar; // adds strings together

	}
	else if (labeled == false) // if it doesn't want labeled output
	{
		top = m_Subject + sepchar; // overloads + string without labels
		bottom = m_GradeLevel + sepchar;
	}

	retvalStr = top + bottom; // final QString concatanation to combine
	return retvalStr; // returns the final string for printing


}