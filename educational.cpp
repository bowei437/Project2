////////////////////////////////////////////////////////
// ECE 3574, Homework 2, Bowei Zhao
//
// File name: educational.cpp
// Description: educational implementation file
// Date: 2/17/2016
//
// *-----------------------------------------------* //

#include "educational.h"

/*
Educational::Educational(QString id, QString title, QString dir, quint32 len, QDate relDate, QString subject, Grade grade)
	:Film(id, title, dir, len, relDate)
{
	qDebug() << "	Debug: Educational Constructor" << endl;
	m_Subject = subject;
	m_GradeLevel = grade;
	qDebug() << "Output of Educational Constructor is: " << m_Subject << m_GradeLevel << endl;
}
*/

Educational::Educational(QString id, QString title, QString dir, quint32 len, QDate relDate, QString subject, Grade grade) :
    Film::Film(id,title,dir,len,relDate),
    m_Subject(subject),
    m_GradeLevel(grade)
{}

Educational::Educational(QStringList propList)
	:Film(propList.at(0), propList.at(1), propList.at(2), propList.at(3).toInt(), QDate::fromString(propList.at(4), "yyyy-MM-dd"))
{
	qDebug() << "	Debug: Educational propList" << endl;
	m_Subject = propList.at(5);
	int conv_cast = propList.at(6).toInt();
	Grade m_GradeLevel = (Grade)conv_cast;


	
	qDebug() << "Output of Educational propList is: " << m_Subject << m_GradeLevel << endl;

}

QString Educational::toString(bool labeled, QString sepchar)
{
	qDebug() << "	Debug: Educational toString" << endl;
	

	if (labeled == true)
	 {
        return
        QString("%1%2%3%4%5%6%7%8").arg("Education").arg(sepchar).arg(Film::toString(labeled, sepchar))
                                   .arg(sepchar).arg(m_Subject).arg(sepchar).arg(m_GradeLevel)
                                   .arg(sepchar);
    }

    else
     {
        return
        QString("%1%2%3%4%5%6").arg(Film::toString(labeled, sepchar)).arg(sepchar).arg(m_Subject)
                               .arg(sepchar).arg(m_GradeLevel).arg(sepchar);
    }
    
	/*
	QString retvalStr;
	// QString top/bottom used to concatante string outputs

	//QString top; 
	QString bottom;
	if (labeled == true) // sees that output is to be labeled
	{		
		//top = this->toString(true, sepchar);
		bottom = "Subject: " + m_Subject + sepchar
				 + "Grade: " + m_GradeLevel + sepchar; // adds strings together

	}
	else if (labeled == false) // if it doesn't want labeled output
	{
		//top = this->toString(false, sepchar);
		bottom = "Subject: " + m_Subject
				 + "Grade: " + m_GradeLevel; // adds strings together
	}

	retvalStr = bottom; // final QString concatanation to combine
	return retvalStr; // returns the final string for printing
	*/
	
	/*
	QString retString;
    if(labeled) {
        retString = this->toString(true, sepchar)
                + "Subject: " + m_Subject + sepchar
                + "Grade Level: " + m_GradeLevel + sepchar;
    }
    else {
        retString = this->toString(true, sepchar)
                + m_Subject + sepchar
                + m_GradeLevel + sepchar;
    }

    return retString;
	*/

}