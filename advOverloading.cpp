#include <iostream>
using namespace std;
class CWin 
{
    private:
        char id,*title;
    
    public:
        CWin(char i='D',const char *text="Default window"):id(i)
        {
            title=new char[50];
            strcpy(title,text);
        }
        void set_data(char i,const char *text)
        {
            id=i;
            strcpy(title,text);
        }
        CWin operator=(const CWin &win)
        {
            id=win.id;
            strcpy(this->title,win.title);
            return *this;
        }
        void show(void)
        {
            cout << "Window " << id << ": " << title << endl;
        }
        ~CWin()
        {
            delete [] title;
        }
        CWin(const CWin &win)
        {
            cout << "拷貝";
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

    win1.operator=(win2.operator=(win3));
    cout << endl << "設定完之後..." << endl;
    win1.show();
    win2.show();
    win3.show();

    return 0;
}