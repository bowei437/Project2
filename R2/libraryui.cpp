////////////////////////////////////////////////////////
// ECE 3574, Homework 2 R2, Bowei Zhao
//
// File name: libraryui.cpp
// Description: library ui implementation file
// Date: 2/17/2016
//
// *-----------------------------------------------* //

#include "libraryui.h"

//start id=lclenums

QTextStream outS(stdout);
QTextStream inS(stdin);
//QTextStream errS(stderr); // error stream for standard error exception

enum Types {BOOK, REFERENCEBOOK, TEXTBOOK, DVD, FILM, DATADVD};
const QStringList TYPES = (QStringList() << "BOOK" << "REFERENCEBOOK"
   << "TEXTBOOK" << "DVD" << "FILM" << "DATADVD");


LibraryUI::Choices LibraryUI::nextTask()
{
	//  -------- Modification Changes -----------
	//    
	//	Changed output text and formatting

   int choice;
   QString response;
   do {
      outS <<"\n\n" << " -- Main Menu -- " << "\n"
      	   << READ << ". Read data from a file.\n"
           << ADD << ". Add items to the Library.\n"
           << FIND << ". Find and display an item.\n"
           << REMOVE << ". Remove an item from the Library.\n"
           << SAVE << ". Save the Library list to a file.\n"
           << LIST << ". Brief listing of Library items.\n"
           << QUIT << ". Exit from this program.\n\n"
           << "Your choice: " << flush;
     response = inS.readLine();
     choice = response.toInt();
   } while(choice < READ or choice > QUIT);
   return static_cast<Choices>(choice);

}


LibraryUI::LibraryUI(Library* lib)
	: m_Lib(lib)
{
	//qDebug() << "	Debug: LibraryUI Constructor" << endl;
}

void LibraryUI::add(QStringList objdata)
{
	//  -------- Modification Changes -----------
	//
	//    changed al references from lib.(function) to 
	//	  a pointer of this -> to that class's function	

	outS << objdata.join("[::]") << endl;
	QString type = objdata.first();
    RefItem* ref;
    switch(static_cast<Types>(TYPES.indexOf(type))) {
    case BOOK:
       ref = new Book(objdata);
       m_Lib->addRefItem(ref);
       break;
    case REFERENCEBOOK:
       ref = new ReferenceBook(objdata);
       m_Lib->addRefItem(ref);
          break;
 //end
    case TEXTBOOK:
       ref = new TextBook(objdata);
       m_Lib->addRefItem(ref);
       break;
    case DVD:
       ref = new Dvd(objdata);
       m_Lib->addRefItem(ref);
       break;
    case FILM:
       ref = new Film(objdata);
       m_Lib->addRefItem(ref);
          break;
    case DATADVD:
       ref = new DataDvd(objdata);
       m_Lib->addRefItem(ref);
       break;
 //start id=lclmenu
    default: qDebug() << "Bad type in add() function";
    }

}

void LibraryUI::read()
{
	//  -------- Modification Changes -----------
	//    
	//		Changed last else from add(lib, objdata)
	//	  	to just objdata 

    const QString sep("[::]");
    const int BADLIMIT(5); //max number of bad lines
    QString line, type;
    QStringList objdata;
    QFile inf("libfile");
    inf.open(QIODevice::ReadOnly);
    QTextStream instr(&inf);
    int badlines(0);
    while(not instr.atEnd()) {
       if(badlines >= BADLIMIT) {
          qDebug() << "Too many bad lines! Aborting.";
          return;
       }
       line = instr.readLine();
       objdata = line.split(sep);
       if(objdata.isEmpty()) {
          qDebug() << "Empty Line in file!";
          ++badlines;
       }
       else if(not TYPES.contains(objdata.first())) {
          qDebug() << "Bad type in line: " << objdata.join(";;;");
          ++badlines;
       }
       else
          add(objdata);
     }	

}

QStringList LibraryUI::promptRefItem()
{
	//  -------- Modification Changes -----------
	//    
	//	  No changes from original Client

    const int MAXCOPIES(10);
    const int ISBNLEN(13);
    int copies;
    QString str;
    QStringList retval;
    while(1) {
       outS << "ISBN ("<< ISBNLEN << " digits): " << flush;
       str = inS.readLine();
       if(str.length() == ISBNLEN) {
          retval << str;
          break;
       }
    }
    outS << "Title: " << flush;
    retval << inS.readLine();
    while(1) {
       outS << "Number of copies: " << flush;
       copies = inS.readLine().toInt();
       if(copies > 0 and copies <= MAXCOPIES) {
          str.setNum(copies);
          break;
       }
    }
    retval << str;
    return retval;	

}

QStringList LibraryUI::promptBook()
{
	//  -------- Modification Changes -----------
	//    
	//	  No changes from original Client besides
	//	  formatting of output

    static const int MINYEAR(1900),
                     MAXYEAR(QDate::currentDate().year());
    int year;
    QStringList retval(promptRefItem());
    QString str;
    outS << "Author: " << flush;
    retval << inS.readLine();
    outS << "Publisher: " << flush;
    retval << inS.readLine();
    while(1) {
       outS << "Copyright year: " << flush;
       year = inS.readLine().toInt();
       if(year >= MINYEAR and year <= MAXYEAR) {
       	  outS << "\n" << flush;
          str.setNum(year);
          break;
       }
    }
    retval << str;
    return retval;	

}
QStringList LibraryUI::promptReferenceBook()
{
	//  -------- Modification Changes -----------
	//    
	//	  No changes from original Client
	
    int idx(0);
    bool ok;
    QString str;
    QStringList retval(promptBook());
    QStringList cats(ReferenceBook::getRefCategories());
    while(1) {
       outS << "Enter the index of the correct Reference Category: ";
       for(int i = 0; i < cats.size(); ++i)
          outS << "\n\t(" << i << ") " << cats.at(i);
       outS << "\n\t(-1)None of these\t:::" << flush;
       idx = inS.readLine().toInt(&ok);
       if(ok) {
          retval << str.setNum(idx);
          break;
       }
    }
    return retval;	
}

QStringList LibraryUI::promptTextBook()
{
	//  -------- Modification Changes -----------
	//    
	//	  No changes from original Client

   QStringList retval(promptBook());
   outS << "Course: " << flush;
   retval << inS.readLine();
   return retval; 	
}

QStringList LibraryUI::promptDVD()
{
	//  -------- Modification Changes -----------
	//    
	//	  No changes from original Client

   bool ok;
   QString str, ans;
   int dnum;
   const int MAXDISKS(10);
   QStringList retval(promptRefItem());
   while(1) {
      outS << "Number of disks (no more than " << MAXDISKS 
           << " please): " << flush;
      dnum = inS.readLine().toInt(&ok);
      if(ok and dnum > 0 and dnum <= MAXDISKS)
         break;
   }
   str.setNum(dnum);
   retval << str;
   outS << "Two-sided disks (Y/N)? " << flush;
   ans = inS.readLine().toUpper();
   if(ans.startsWith("Y"))
      str.setNum(1);
   else
      str.setNum(0);
   retval << str;
   return retval;	
}

QStringList LibraryUI::promptFilm()
{
	//  -------- Modification Changes -----------
	//    
	//	  No changes from original Client

   int min;
   const int MAXTIME(1000);
   bool ok;
   QString str, ans;
   QStringList retval(promptDVD());
   outS << "Star of film: " << flush;
   retval << inS.readLine();
   outS << "Director of film: " << flush;
   retval << inS.readLine();
   while(1) {
      outS << "Length of film (minutes): " << flush;
      min = inS.readLine().toInt(&ok);
      if(ok and min > 0 and min <= MAXTIME)
         break;
   }
   str.setNum(min);
   retval << str;
   outS << "BlueRay (Y/N)? " << flush;
   ans = inS.readLine().toUpper();
   if(ans.startsWith("Y"))
      str.setNum(1);
   else
      str.setNum(0);
   retval << str;
   return retval;
}

QStringList LibraryUI::promptDataBase()
{
	//  -------- Modification Changes -----------
	//    
	//	  No changes from original Client

   QStringList retval(promptDVD());
   outS << "Database protocol: " << flush;
   retval << inS.readLine();
   return retval;
}

void LibraryUI::enterData()
{
	//  -------- Modification Changes -----------
	//    
	//	  Changed initial Question ask prompt
	//
	// 	  Changed Error invalid output
	//
	// 	  changed add(lib, objdata) to just a reference
	// 	  to add objdata instead

	     outS << "\n" << "Please enter one of the following types:\n"
	          << TYPES.join(" , ") << endl;
	QString typestr;
	while(1) {

		outS << "\n" <<"Library item type: " << flush;
		typestr = inS.readLine();
	  if(not TYPES.contains(typestr)) {
	  	outS << "\n" <<" --	ERROR: Input of " << typestr << " is invalid.\n"
	  		<< " -- Try Again with capital letters  -- " << flush;
	     outS << "\n \n" <<"Please enter one of the following types:\n"
	          << TYPES.join(" , ") << endl;
	     continue;
	  }
	  break;
	}
	QStringList objdata;
	switch (TYPES.indexOf(typestr)) {
	case BOOK: objdata = promptBook();
	     break;
	case REFERENCEBOOK: objdata = promptReferenceBook();
	     break;
	//end
	case TEXTBOOK: objdata = promptTextBook();
	     break;
	case DVD: objdata = promptDVD();
	     break;
	case FILM: objdata = promptFilm();
	     break;
	case DATADVD: objdata = promptDataBase();
	     break;
	//start id=lclprompt
	default:
	     qDebug() << "Bad type in enterData()";
	}
	objdata.prepend(typestr);
	add(objdata);


}


QString LibraryUI::find()
{
	//  -------- Modification Changes -----------
	//    
	//	 Changed call of lib to a -> this
	// 	 to get the correct Classes Item String 

    QString isbn, item;
    outS << "Search ISBN: " << flush;
    isbn = inS.readLine();
    item = m_Lib->getItemString(isbn);
    if(item == QString()) {
       outS << isbn << " not found." << endl;
       return item;
    }
    else {
       outS << item << endl;
       return isbn;
    }

}
void LibraryUI::remove()
{
	//  -------- Modification Changes -----------
	//    
	//	  Removed find(lib) as find() already 
	//	  A part of the function class
	//
	//	  Changed call of lib to a -> this
	// 	  to get the correct Classes removeRefItem

   QString isbn(find()), ans;
   if(isbn == QString()) {
      outS << isbn << " not found." << endl;
      return;
   }
   outS << "Remove this item (Y/N)? " << flush;
   ans = inS.readLine().toUpper();
   if(ans.startsWith("N"))
      return;
   int numCopiesLeft = m_Lib->removeRefItem(isbn);
   outS << "There are now  " << numCopiesLeft 
        << " copies left in the library." << endl;

}
void LibraryUI::save()
{
	//  -------- Modification Changes -----------
	//    
	//	  Changed call of lib to a -> this
	// 	  to get the correct Classes toString

   QFile outf("libfile");
   outf.open(QIODevice::WriteOnly);
   QTextStream outstr(&outf);
   outstr << m_Lib->toString();
   outf.close();

}

void LibraryUI::list()
{
	//  -------- Modification Changes -----------
	//    
	//	  Changed call of lib to a -> this
	// 	  to get the correct Classes toString  

    outS <<"\n" << m_Lib->toString() << endl;

}

void LibraryUI::prepareToQuit(bool saved)
{
	//  -------- Modification Changes -----------
	//    
	//	 Removed save(lib) as save()
	//	 is already a function within class

   QString ans;
   if(not saved) {
      outS << "Save data first (Y/N)? " << flush;
      ans = inS.readLine().toUpper();
      if(ans.startsWith("Y")) {
         save();
         exit(0);
      }
   }
   exit(1);
}