////////////////////////////////////////////////////////
// ECE 3574, Homework 2, Bowei Zhao
//
// File name: educational.h
// Description: educational header file
// Date: 2/17/2016
//
// *-----------------------------------------------* //

#ifndef EDUCATIONAL_H
#define EDUCATIONAL_H

#include "film.h"

enum Grade {First=1, Second=2, Third=3, Fourth=4, Fifth=5};

class Educational : public Film
{
	public:
		Educational(QString id, QString title, QString dir, quint32 len, QDate relDate, QString subject, Grade grade);
		Educational(QStringList propList);
		QString toString(bool labeled, QString sepchar);

	private:
		QString m_Subject;
		Grade m_GradeLevel;

};


#endif // EDUCATIONAL_H
