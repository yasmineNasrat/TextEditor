#include "texteditor.h"
//#include <bits/stdc++.h>
#include <sstream>
#include <cstdio>
#include <QMessageBox>
#include <iostream>
#include <fstream>
using namespace std;

map <int , string > texteditor:: m ={{0,""}};
stack<undoCmd> texteditor::undoStack;
stack<undoCmd> texteditor::redoStack;
string texteditor:: currentFileName = "";

texteditor::texteditor()
{
}
