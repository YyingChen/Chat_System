#include"window.h"

window::window()
{
    initscr();
}

window::~window()
{
    delwin(header);
    delwin(input);
    delwin(output);
    delwin(friend_list);
    endwin();
}

void window::createHeader()
{
   int _h=LINES/5;
   int _w=COLS;
   int _y=0;
   int _x=0;
   header=newwin(_h,_w,_y,_x);
   box(header,0,0);
}
void window::getStringFromWin(WINDOW* win,std::string &outString)
{
    char buf[1024];
    buf[0]=0;//清空字符串
    wgetnstr(win,buf,sizeof(buf));
    outString=buf;
}
void window::putStringToWin(WINDOW* win,int start_y,int start_x,std::string &msg)
{
    mvwaddstr(win,start_y,start_x,msg.c_str());
}
void window::clrNumsLines(WINDOW *win,int begin,int nums)
{
    while(nums-->0)
    {
       wmove(win,begin++,0);//begin y ,0 x
       wclrtoeol(win);

    }
}
void window::createOutput()
{
   int _h=LINES*3/5;
   int _w=COLS*3/4;
   int _y=LINES/5;
   int _x=0;
   output=newwin(_h,_w,_y,_x);
   box(output,0,0);

}
void window::createInput()
{
   int _h=LINES/5;
   int _w=COLS;
   int _y=LINES*4/5;
   int _x=0;
   input=newwin(_h,_w,_y,_x);
   box(input,0,0);

}
void window::createFriendList()
{
   int _h=LINES*3/5;
   int _w=COLS/4;
   int _y=LINES/5;
   int _x=COLS*3/4;
   friend_list=newwin(_h,_w,_y,_x);
   box(friend_list,0,0);

}
void window::refreshMyWindow(WINDOW* win)
{
    wrefresh(win);
}


/*int main()
{
    window win;//出口许可
    win.createHeader();
    win.refreshMyWindow(win.header);
    win.createOutput();
    win.refreshMyWindow(win.output);
    win.createFriendList();
    win.refreshMyWindow(win.friend_list);
    win.createInput();
    win.refreshMyWindow(win.input);
    std::string msg="welcome to chat system";
    int h=0;
    int w=0;
    int step=0;
    while(1)
    {
       win.createHeader();//重新描绘
       getmaxyx(win.header,h,w);
       win.putStringToWin(win.header,h/2,step++,msg);
       win.refreshMyWindow(win.header);
       win.clrNumsLines(win.header,h/2,1);
       step%=w;
       usleep(300000);

       std::string str;
       win.getStringFromWin(win.input,str);
       getmaxyx(win.output,h,w);
       win.putStringToWin(win.output,1,1,str);
       win.refreshMyWindow(win.output);

    }
    sleep(5);
    return 0;
}
*/
