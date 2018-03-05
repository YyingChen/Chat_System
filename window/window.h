#ifndef _WINDOWS_H_
#define _WINDOWS_H_

#include<iostream>
#include<ncurses.h>

class window
{
  public:
      void createHeader();
      void createOutput();
      void createInput();
      void createFriendList();
      void refreshMyWindow(WINDOW* win);
      void putStringToWin(WINDOW* win,int start_y,int start_x,std::string &msg);

      void clrNumsLines(WINDOW *win,int begin,int nums);
      void getStringFromWin(WINDOW* win,std::string &outString);
      window();
      ~window();
  public:
      WINDOW *header;
      WINDOW *output;
      WINDOW *friend_list;
      WINDOW *input;
};
#endif
