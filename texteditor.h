#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H
#include <string>
#include <stack>
#include <map>
#include <vector>
#include <QString>
using namespace std;

struct undoCmd{
  int commandNumber;
  string oldLine,newLine;
  vector<int> lineNumbers;
  int lineNumber;
};

class texteditor
{
public:
    static std::map <int , std::string > m;
    static std::stack<undoCmd> undoStack;
    static std::stack<undoCmd> redoStack;
    static string currentFileName;
    texteditor();

};


#endif // TEXTEDITOR_H


