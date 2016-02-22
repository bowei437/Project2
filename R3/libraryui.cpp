////////////////////////////////////////////////////////
// ECE 3574, Homework 2 R3, Bowei Zhao
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
	//  -------- Modification Changes from R2 -----------
	//    
	//	No changes made from R2.

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
	//  -------- Modification Changes from R2 -----------
	//
	//   
	//	 

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
	//  -------- Modification Changes from R2 -----------
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

// CHANGE THIS
void LibraryUI::enterData()
{
	//  -------- Modification Changes from R2 -----------
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

  BookUI bookitem;
  ReferenceBookUI refbookitem;
  TextBookUI texbookitem;
  DvdUI dvditem;
  FilmUI filmitem;
  DataBaseUI datbitem;

	switch (TYPES.indexOf(typestr)) {
	case BOOK: objdata = bookitem.prompt();
	     break;
	case REFERENCEBOOK: objdata = refbookitem.prompt();
	     break;
	//end
	case TEXTBOOK: objdata = texbookitem.prompt();
	     break;
	case DVD: objdata = dvditem.prompt();
	     break;
	case FILM: objdata = filmitem.prompt();
	     break;
	case DATADVD: objdata = datbitem.prompt();
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
	//  -------- Modification Changes from R2 -----------
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
	//  -------- Modification Changes from R2 -----------
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
	//  -------- Modification Changes from R2 -----------
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
	//  -------- Modification Changes from R2 -----------
	//    
	//	  Changed call of lib to a -> this
	// 	  to get the correct Classes toString  

    outS <<"\n" << m_Lib->toString() << endl;

}

void LibraryUI::prepareToQuit(bool saved)
{
	//  -------- Modification Changes from R2 -----------
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