////////////////////////////////////////////////////////
// ECE 3574, Homework 2 R3, Bowei Zhao
//
// File name: totalui.h
// Description: total ui header file
// Date: 2/17/2016
//
// *-----------------------------------------------* //


#ifndef TOTALUI_H
#define TOTALUI_H


#include "library.h"
#include "libraryui.h"

class RefItemUI {

    public:
    	~RefItemUI();
        QStringList prompt();
};

class BookUI : public RefItemUI{

    public:
        QStringList prompt();
};

class ReferenceBookUI : public BookUI {

    public:
        QStringList prompt();
};

class TextBookUI : public BookUI{

    public:
        QStringList prompt();
};

class DvdUI : public RefItemUI{

    public:
        QStringList prompt();
};

class FilmUI : public DvdUI{

    public:
        QStringList prompt();
};

class DataBaseUI : public DvdUI{

    public:
        QStringList prompt();
};


#endif // TOTALUI_H