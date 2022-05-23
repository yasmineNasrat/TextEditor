#include <string>
#include <stack>
#include <map>
#include <vector>
#include <QString>
#include <iostream>
#include <fstream>
struct undoCmd{
  int commandNumber;
  std::string oldLine;
  std::vector<int> lineNumbers;
  int lineNumber;
};
class texteditor2
{
        static std::map <int , std::string > m;
        static std::stack<undoCmd> undoStack;
        static std::string currentFileName;
        static int i;
public:
        texteditor2()
        {
            currentFileName = " ";
        }
          void addLine(std::string  newLine){
            //texteditor::i.empty();
            undoCmd lineAdded;
            lineAdded.commandNumber = 1;
            if(m.empty()){
                m.insert({1,newLine});
                lineAdded.lineNumber = 1;
            }
            else{
                auto ptr = m.rbegin();
               int index = ptr -> first;
               index++;

               m.insert({index,newLine});
               lineAdded.lineNumber = index;
               }
               undoStack.push(lineAdded);
            /*for(auto m:m){
                cout << m.first << "-" << m.second << endl;
              }*/
        }
        void insertLine( int lineNo , std::string line ){
            if(lineNo <= 0)
             std::cout << "Invalid lineNo" << std::endl;
            else{
                try{
                    m.at(lineNo);
                    std::cout << "there is a line with number " << lineNo << " do you want to replace it ?\n";
                    char c;
                    std::cin >> c;
                    if(c == 'y'){
                        undoCmd inserted;
                        inserted.commandNumber = 5 ;
                        inserted.lineNumber = lineNo;
                        inserted.oldLine = m[lineNo];
                        undoStack.push(inserted);
                        m[lineNo] = line;
                    }

                }
                catch(const std::out_of_range &e){
                    m[lineNo] = line;
                    undoCmd inserted;
                    inserted.commandNumber = 6 ;
                    inserted.lineNumber = lineNo;
                    undoStack.push(inserted);
                }

            }
            /*for(auto m:m){
                cout << m.first << "-" << m.second << endl;
              }*/
        }

            void updateLine (int lineNo , std::string updatedLine){
                auto it = m.rbegin();
                if(lineNo <= 0 || lineNo > it->first)
                    std::cout << "Invalid line number" << std::endl;
                else{
                    m[lineNo] = updatedLine;
                }
                /*for(auto m:m){
                    cout << m.first << "-" << m.second << endl;
                }*/
            }
            std::string getLine(int lineNo){
                if(lineNo <= 0)
                   {
                        return "Invalid Line Number..";
                   }
                else{
                    try{
                         m.at(lineNo);
                         return m[lineNo];
                    }
                    catch(const std::out_of_range &e){
                       return "Empty line";
                    }

                }
            }
            std::vector<int> findAll(std::string line){
               std::vector<int> v;
                for(auto it = m.begin();it!=m.end();++it){
                    if(it->second == line){
                        v.push_back(it->first);
                    }
                }
                return v;
            }
            void findAndReplaceAll(std::string oldLine , std::string newLine){
                undoCmd allReplaced;
                for(auto it=m.begin();it!=m.end();++it){
                    if(it->second == oldLine){
                        it->second = newLine;
                        allReplaced.lineNumbers.push_back(it->first);
                    }
                }
                allReplaced.commandNumber = 2;
                allReplaced.oldLine = oldLine;
                undoStack.push(allReplaced);
            }
            void deleteLine(int lineNo){
                if(lineNo <= 0)
                    std::cout << "Invalid line number.." <<std::endl;
                else{
                    try{
                        m.at(lineNo);
                        undoCmd deleted;
                        deleted.lineNumber=lineNo;
                        deleted.oldLine = m[lineNo];
                        deleted.commandNumber = 3 ;
                        undoStack.push(deleted);
                        m.erase(lineNo);
                    }
                    catch(const std::out_of_range &e){
                        std::cout << "Empty line " << std::endl;
                    }
                }
                /*for(auto m:m){
                    cout << m.first << "-" << m.second << endl;
                }*/
            }
            void show(){
                auto it = m.rbegin();
                for(int i = 1;i <= it->first;++i){
                    try{
                        m.at(i);
                        std::cout << i << ") " << m.at(i) << std::endl;
                    }
                    catch(const std::out_of_range &e){
                        std::cout << i <<") " << std::endl;
                    }
                }
            }
            void openFile(std::string fileName){
                fileName+=".txt";
                std::ifstream readFile(fileName);
                if(readFile.is_open()){
                    m.clear();
                std::string line;int lineNo = 1;
                while(getline(readFile,line)){
                    if(line != ""){
                        m.insert({lineNo,line});
                    }
                    lineNo++;
                }
                readFile.close();
                currentFileName = fileName;
                }
                else{
                    std::cout << "File with this name not found..Make sure the name is correct.." << std::endl;
                }

            }
            void save(){
                if(currentFileName == " "){
                    std::cout << "WARNING" << std::endl << "To save for the first time .. choose (save to a file) " << std::endl;
                }
                else{
                    std::ofstream writefile;
                    writefile.open(currentFileName , std::ofstream::out | std::ofstream::trunc);
                    if(m.empty()){
                        writefile.close();
                        return;
                    }
                    else{
                        auto it = m.rbegin();
                        for(int i = 1 ;i<=it->first;++i){
                            try{
                                m.at(i);
                                writefile << m[i] << std::endl;
                            }
                            catch(const std::out_of_range &e){
                                writefile << "" <<std::endl;
                            }
                        }
                        writefile.close();
                    }
                }
            }
            void saveToAFile(std::string fileName){
                fileName+=".txt";
                std::ofstream writefile(fileName);
                currentFileName = fileName;
                if(m.empty()){
                    writefile.close();
                    return;
                }
                else{
                    auto it = m.rbegin();
                    for(int i = 1 ;i<=it->first;++i){
                        try{
                            m.at(i);
                            writefile << m[i] <<std::endl;
                        }
                        catch(const std::out_of_range &e){
                            writefile << "" <<std::endl;
                        }
                    }
                    writefile.close();
                }
                undoCmd fileSaved;
                fileSaved.commandNumber = 4;
                fileSaved.oldLine =  fileName;
                undoStack.push(fileSaved);
            }
          /* int texteditor:: wordCount(std::string word){
                int counter = 0;
                for(auto it = m.begin();it !=m.end();++it){
                    std::stringstream myLine(it->second);
                    std::string s;
                    while(myLine >> s){
                        if(s == word)
                            counter++;
                    }
                }
                return counter;
            }
            int texteditor::CountWords(){
                int counter = 0;
                for(auto it = m.begin();it !=m.end();++it){
                    std::stringstream myLine(it->second);
                    std::string s;
                    while(myLine >> s){
                            counter++;
                    }
                }
                return counter;
            }*/
            void undo(){
                undoCmd mostRecentCmd = undoStack.top();
                if(mostRecentCmd.commandNumber == 2){
                    for(int i = 0 ;i<(int)mostRecentCmd.lineNumbers.size();++i){
                        m.at(mostRecentCmd.lineNumbers[i]) = mostRecentCmd.oldLine;
                    }
                }
                else if(mostRecentCmd.commandNumber == 3){
                    insertLine(mostRecentCmd.lineNumber,mostRecentCmd.oldLine);
                }
                else if(mostRecentCmd.commandNumber == 4){
                    //remove(mostRecentCmd.oldLine);
                }
                else if(mostRecentCmd.commandNumber == 1){
                    m.erase(mostRecentCmd.lineNumber);
                }
                else if(mostRecentCmd.commandNumber == 5){
                    m[mostRecentCmd.lineNumber] = mostRecentCmd.oldLine;
                }
                else if(mostRecentCmd.commandNumber == 6){
                    m.erase(mostRecentCmd.lineNumber);
                }
                 undoStack.pop();
            }

};
