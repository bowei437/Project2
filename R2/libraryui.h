////////////////////////////////////////////////////////
// ECE 3574, Homework 2 R2, Bowei Zhao
//// ID: 905789193
// email: bowei@vt.edu
// File name: libraryui.h
// Description: library ui header file
// Date: 2/17/2016
//
// *-----------------------------------------------* //

#ifndef LIBRARYUI_H
#define LIBRARYUI_H

#include "library.h"



class LibraryUI
{
	public:
	enum Choices {READ=1, ADD=2, FIND=3, REMOVE=4, SAVE=5, LIST=6, QUIT=7};
        Choices nextTask();
	LibraryUI(Library* lib);
	void add(QStringList objdata);
        void read();
        void enterData();
        QString find();
        void remove();
        void save();
        void list();
        QStringList promptRefItem();
        QStringList promptBook();
        QStringList promptReferenceBook();
        QStringList promptTextBook();
        QStringList promptDVD();
        QStringList promptFilm();
        QStringList promptDataBase();
        void prepareToQuit(bool saved);

	private:
		Library* m_Lib;


};



#endif // LIBRARYUI_H