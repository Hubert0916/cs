//title採用固定大小配置
#include <iostream>
#include <cstring>
using namespace std;
class CWin 
{
    private:
        char id,title[20];
    
    public:
        CWin(char i='D',const char *text="Default window"):id(i)
        {
            strcpy(title,text);
        }
        CWin operator=(CWin const& win)
        {
            id=win.id;
            strcpy(this->title,win.title);
            return *this;
        }
        void show(void)
        {
            cout << "Window " << id << ": " << title << endl;
        }
        CWin(const CWin &win)
        {
            id=win.id;
            strcpy(title,win.title);
        }
};

int main(void)
{
    CWin win1('A',"Main window");
    CWin win2('B',"Big window");
    CWin win3;

    win1.show();
    win2.show();
    win3.show();

    win1=win2=win3;//win1.operator=(win2.operator=(win3))

    cout << "after..." << endl;

    win1.show();
    win2.show();
    win3.show();

    return 0;
}