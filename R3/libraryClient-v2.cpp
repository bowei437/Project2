////////////////////////////////////////////////////////
// ECE 3574, Homework 2 R3, Bowei Zhao
//
// File name: libraryClient-v2.cpp
// Description: library client v2 implementation file
// Date: 2/17/2016
//
// *-----------------------------------------------* //

#include "libraryui.h"
#include "library.h"

bool saved(false);


int main() {
   Library lib;
   LibraryUI libui(&lib);
   while(1) {
      switch(libui.nextTask()) {
      case LibraryUI::READ: libui.read();
         saved = false;
         break;
      case LibraryUI::ADD: libui.enterData();
         saved = false;
         break;
      case LibraryUI::FIND: libui.find();
         break;
      case LibraryUI::REMOVE: libui.remove();
         saved = false;
         break;
      case LibraryUI::SAVE: libui.save();
         saved = true;
         break;
      case LibraryUI::LIST: libui.list();
         break;
      case LibraryUI::QUIT: libui.prepareToQuit(saved);
         break;
      default:
         break;
      }
   }
}

