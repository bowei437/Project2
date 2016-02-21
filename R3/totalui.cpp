////////////////////////////////////////////////////////
// ECE 3574, Homework 2 R3, Bowei Zhao
//
// File name: totalui.cpp
// Description: total ui implementation file
// Date: 2/17/2016
//
// *-----------------------------------------------* //

#include "totalui.h"

QTextStream outT(stdout);
QTextStream inT(stdin);



QStringList RefItemUI::prompt()
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
       outT << "ISBN ("<< ISBNLEN << " digits): " << flush;
       str = inT.readLine();
       if(str.length() == ISBNLEN) {
          retval << str;
          break;
       }
    }
    outT << "Title: " << flush;
    retval << inT.readLine();
    while(1) {
       outT << "Number of copies: " << flush;
       copies = inT.readLine().toInt();
       if(copies > 0 and copies <= MAXCOPIES) {
          str.setNum(copies);
          break;
       }
    }
    retval << str;
    return retval;	

}

RefItemUI::~RefItemUI()
{
	// do nothing
}

QStringList BookUI::prompt()
{
	//  -------- Modification Changes -----------
	//    
	//	  No changes from original Client besides
	//	  formatting of output

    static const int MINYEAR(1900),
                     MAXYEAR(QDate::currentDate().year());

	RefItemUI newRefitem; // made a new item of RefItemUI class

    int year;
    QStringList retval(newRefitem.prompt());
    QString str;
    outT << "Author: " << flush;
    retval << inT.readLine();
    outT << "Publisher: " << flush;
    retval << inT.readLine();
    while(1) {
       outT << "Copyright year: " << flush;
       year = inT.readLine().toInt();
       if(year >= MINYEAR and year <= MAXYEAR) {
       	  outT << "\n" << flush;
          str.setNum(year);
          break;
       }
    }
    retval << str;
    return retval;	

}

QStringList ReferenceBookUI::prompt()
{
	//  -------- Modification Changes -----------
	//    
	//	  No changes from original Client
	
    int idx(0);
    bool ok;
    BookUI newBookitem; // made a new item of BookUI class
    QString str;
    QStringList retval(newBookitem.prompt());
    QStringList cats(ReferenceBook::getRefCategories());
    while(1) {
       outT << "Enter the index of the correct Reference Category: ";
       for(int i = 0; i < cats.size(); ++i)
          outT << "\n\t(" << i << ") " << cats.at(i);
       outT << "\n\t(-1)None of these\t:::" << flush;
       idx = inT.readLine().toInt(&ok);
       if(ok) {
          retval << str.setNum(idx);
          break;
       }
    }
    return retval;		

}

QStringList TextBookUI::prompt()
{
	//  -------- Modification Changes -----------
	//    
	//	  No changes from original Client

	BookUI newBookitem2; // made another new item of BookUI Class
	QStringList retval(newBookitem2.prompt());
	outT << "Course: " << flush;
	retval << inT.readLine();
	return retval; 	
}

QStringList DvdUI::prompt()
{
	//  -------- Modification Changes -----------
	//    
	//	  No changes from original Client

	RefItemUI newRefitem2; // made another new item of Refitemui class
	bool ok;
	QString str, ans;
	int dnum;
	const int MAXDISKS(10);
	QStringList retval(newRefitem2.prompt());
	while(1) {
	  outT << "Number of disks (no more than " << MAXDISKS 
	       << " please): " << flush;
	  dnum = inT.readLine().toInt(&ok);
	  if(ok and dnum > 0 and dnum <= MAXDISKS)
	     break;
	}
	str.setNum(dnum);
	retval << str;
	outT << "Two-sided disks (Y/N)? " << flush;
	ans = inT.readLine().toUpper();
	if(ans.startsWith("Y"))
	  str.setNum(1);
	else
	  str.setNum(0);
	retval << str;
	return retval;	
}

QStringList FilmUI::prompt()
{
	//  -------- Modification Changes -----------
	//    
	//	  No changes from original Client

	DvdUI newDVDitem; // made a new item of DVDUI class
	int min;
	const int MAXTIME(1000);
	bool ok;
	QString str, ans;
	QStringList retval(newDVDitem.prompt());
	outT << "Star of film: " << flush;
	retval << inT.readLine();
	outT << "Director of film: " << flush;
	retval << inT.readLine();
	while(1) {
	  outT << "Length of film (minutes): " << flush;
	  min = inT.readLine().toInt(&ok);
	  if(ok and min > 0 and min <= MAXTIME)
	     break;
	}
	str.setNum(min);
	retval << str;
	outT << "BlueRay (Y/N)? " << flush;
	ans = inT.readLine().toUpper();
	if(ans.startsWith("Y"))
	  str.setNum(1);
	else
	  str.setNum(0);
	retval << str;
	return retval;
}

QStringList DataBaseUI::prompt()
{
	//  -------- Modification Changes -----------
	//    
	//	  No changes from original Client
	DvdUI newDVDitem2; // made another new item of DVDUI class
   QStringList retval(newDVDitem2.prompt());
   outT << "Database protocol: " << flush;
   retval << inT.readLine();
   return retval;
}











/*

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
       outT << "ISBN ("<< ISBNLEN << " digits): " << flush;
       str = inT.readLine();
       if(str.length() == ISBNLEN) {
          retval << str;
          break;
       }
    }
    outT << "Title: " << flush;
    retval << inT.readLine();
    while(1) {
       outT << "Number of copies: " << flush;
       copies = inT.readLine().toInt();
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
    outT << "Author: " << flush;
    retval << inT.readLine();
    outT << "Publisher: " << flush;
    retval << inT.readLine();
    while(1) {
       outT << "Copyright year: " << flush;
       year = inT.readLine().toInt();
       if(year >= MINYEAR and year <= MAXYEAR) {
       	  outT << "\n" << flush;
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
       outT << "Enter the index of the correct Reference Category: ";
       for(int i = 0; i < cats.size(); ++i)
          outT << "\n\t(" << i << ") " << cats.at(i);
       outT << "\n\t(-1)None of these\t:::" << flush;
       idx = inT.readLine().toInt(&ok);
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
   outT << "Course: " << flush;
   retval << inT.readLine();
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
      outT << "Number of disks (no more than " << MAXDISKS 
           << " please): " << flush;
      dnum = inT.readLine().toInt(&ok);
      if(ok and dnum > 0 and dnum <= MAXDISKS)
         break;
   }
   str.setNum(dnum);
   retval << str;
   outT << "Two-sided disks (Y/N)? " << flush;
   ans = inT.readLine().toUpper();
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
   outT << "Star of film: " << flush;
   retval << inT.readLine();
   outT << "Director of film: " << flush;
   retval << inT.readLine();
   while(1) {
      outT << "Length of film (minutes): " << flush;
      min = inT.readLine().toInt(&ok);
      if(ok and min > 0 and min <= MAXTIME)
         break;
   }
   str.setNum(min);
   retval << str;
   outT << "BlueRay (Y/N)? " << flush;
   ans = inT.readLine().toUpper();
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
   outT << "Database protocol: " << flush;
   retval << inT.readLine();
   return retval;
}
*/