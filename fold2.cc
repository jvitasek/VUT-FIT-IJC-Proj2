// fold2.cc
// Implementation of the IJC - HW2, ex. a), 29/04/2014
// Author: Jakub Vitásek, VUT FIT 1BIT
// gcc 4.8

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;


int main(int argc, char* argv[])
{
    int i;
    int c = 0; 
    unsigned int w = 80;
    string filename;    
    ifstream infile;
    
    for(i=1; i<argc; i++)
    {
        if (!strcmp(argv[i], "-c"))
            c = 1;
        else if (!strcmp(argv[i], "-w"))
        {
            if (i<argc-1)
            {
                i++;
                w = atoi(argv[i]);
            }
        } else {
            if (filename.size()==0)
                filename = argv[i];
        }
    }

    if (filename.size()>0)
    {
        infile.open(filename.c_str());
    }


    string word;
    ios_base::sync_with_stdio(false);

    bool eof = false;
    int printedLen = 0;
    int row = 0;

    while(!eof)
    {   
        if (filename.size()>0)
        {
            getline(infile, word);
            eof = infile.eof();
        }
        else
        {
            getline(cin, word);
            eof = cin.eof();
        }

        if (!eof)
        {
            if (word.size()>0)
            {
                stringstream ss(word);

                string word1;
                while(ss >> word1)
                {
                    if (printedLen+word1.size()>=w)  
                    {
                        if (row>0)
                        {
                            if (printedLen>0)
                                cout << endl;
                        }                        
                        printedLen = 0;
                    } else {
                        if (printedLen>0)
                        {
                            printedLen++;
                            cout << " ";
                        }
                    }
                    if (c && word1.size()>w)
                        word1.erase(w);

                    int sz = word1.size();
                    cout << word1;
                    printedLen += sz;
                    row++;
                }
            } else {
                if (printedLen>0)
                {
                    cout << endl;
                } else {                 
                }
                cout << endl;
                printedLen = 0;
            }
        }
    }
}
