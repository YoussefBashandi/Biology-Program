#include "Menu.h"
#include <bits/stdc++.h>
#include"RNA.h"
#include"Sequence.h"
#include"DNA.h"
#include"Protien.h"
#include"CodonsTable.h"
#include<conio.h>
#include<vector>
using namespace std;

Menu::Menu()
{
    vector<DNA> DNAV(10);
    vector<RNA> RNAV(10);
    vector<Protien> ProteinV(10);
    int DNANo = 0;
    int RNANo = 0;
    int PNo = 0;

start:
    cout << "welcome to the BETA version of our Biomolecular converter app. \nplease choose what you want to do:\n\n1- Enter or load sequence\n\n2- View existing sequences\n\n3- Save sequence to a file\n\n4- Convert sequences\n\n5- Align two different sequences of the same type(RNA,DNA or protein)\n" << endl;
    char Choice;
    cin >> Choice;
    switch (Choice)
    {
    case '1':
        cout << "Choose a sequence:\n 1- DNA\n 2- RNA\n 3- Protein" << endl;
        char Choice1;
        cin >> Choice1;
        switch (Choice1)
        {
        case '1':
        {
            char Choice2;
            cout << "what do you want to do:\n 1- Enter a DNA sequence\n 2- Load from file\n" << endl;
            cin >> Choice2;
            if (Choice2 == '1')
            {
                DNA newDNA;
                cin >> newDNA;
                DNAV[DNANo] = newDNA;
                DNANo++;
            }
            else if (Choice2 == '2')
            {
                DNA newDNA;
                newDNA.LoadFromFile();
                DNAV[DNANo] = newDNA;
                DNANo++;
            }
            else
            {
                cout << "wrong choice." << endl;
            }
            break;
        }
        case '2':
        {
            char Choice3;
            cout << "what do you want to do:\n 1- Enter an RNA sequence\n 2- Load from a file\n" << endl;
            cin >> Choice3;
            if (Choice3 == '1')
            {
                RNA newRNA;
                cin >> newRNA;
                RNAV[RNANo] = newRNA;
                RNANo++;
            }
            else if (Choice3 == '2')
            {
                RNA newRNA;
                newRNA.LoadFromFile();
                RNAV[RNANo] = newRNA;
                RNANo++;
            }
            else
            {
                cout << "wrong choice." << endl;
            }
            break;
        }
        case '3':
        {
            char Choice4;
            cout << "what do you want to do:\n 1- Enter a protein sequence\n 2-load from a file" << endl;
            cin >> Choice4;
            if (Choice4 == '1')
            {
                Protien newProtein;
                cin >> newProtein;
                ProteinV[PNo] = newProtein;
                PNo++;
            }
            else if (Choice4 == '2')
            {
                Protien newProtein;
                newProtein.LoadFromFile();
                ProteinV[PNo] = newProtein;
                PNo++;
            }
            else
            {
                cout << "wrong choice." << endl;
            }
            break;
        }
        default:
            cout << "wrong choice" << endl;
            break;
        }
        break;
    case '2':
        cout << "DNA Sequences:" << endl;
        for (int i = 0; i<DNANo; i++)
        {
            cout << i << ')' << endl << DNAV[i] << endl;
        }
        cout << endl << "RNA Sequences:" << endl;
        for (int i = 0; i<RNANo; i++)
        {
            cout << i << ')' << endl << RNAV[i] << endl;
        }
        cout << endl << "Protein Sequences:" << endl;
        for (int i = 0; i<PNo; i++)
        {
            cout << i << ')' << endl << ProteinV[i] << endl;
        }
        break;
    case '3':
        cout << "Choose a sequence:\n 1- DNA\n 2- RNA\n 3- Protein" << endl;
        char Choice5;
        cin >> Choice5;
        cout << "Choose from existing sequences" << endl;
        switch (Choice5)
        {
        case '1':
        {
            cout << "DNA Sequences:" << endl;
            for (int i = 0; i<DNANo; i++)
            {
                cout << i << ')' << endl << DNAV[i] << endl;
            }
            int index;
            cin >> index;
            if (index < 0 || index >= DNANo)
            {
                cout << "invalid operation. choose an available index" << endl;
            }
            else
            {
                DNAV[index].saveToFile();
            }
            break;
        }
        case '2':
        {
            cout << "RNA Sequences:" << endl;
            for (int i = 0; i<RNANo; i++)
            {
                cout << i << ')' << endl << RNAV[i] << endl;
            }
            int index;
            cin >> index;
            if (index < 0 || index >= RNANo)
            {
                cout << "invalid operation.choose an available index" << endl;
            }
            else
            {
                RNAV[index].saveToFile();
            }
            break;
        }
        case '3':
        {
            cout << "Protein Sequences:" << endl;
            for (int i = 0; i<PNo; i++)
            {
                cout << i << ')' << endl << ProteinV[i] << endl;
            }
            int index;
            cin >> index;
            if (index < 0 || index >= PNo)
            {
                cout << "invalid operation. choose an available index" << endl;
            }
            else
            {
                ProteinV[index].saveToFile();
            }
            break;
        }
        default:
            cout << "wrong choice" << endl;
            break;
        }
        break;
    case '4':
        cout << "Choose a sequence:\n 1- DNA\n 2- RNA" << endl;
        char Choice6;
        cin >> Choice6;
        cout << "Choose from existing sequences" << endl;
        switch (Choice6)
        {
        case '1':
        {
            cout << "DNA Sequences:" << endl;
            for (int i = 0; i<DNANo; i++)
            {
                cout << i << ')' << endl << DNAV[i] << endl;
            }
            int index;
            cin >> index;
            if (index < 0 || index >= DNANo)
            {
                cout << "invalid operation. choose an available index" << endl;
            }
            else
            {
                cout << "To:\n 1- RNA\n 2- Protein" << endl;
                int conversionchoice;
                cin >> conversionchoice;
                if (conversionchoice == 1)
                {
                    DNA tempDNA = DNAV[index];
                    RNA &&newRNA = tempDNA.ConvertToRNA();
                    RNAV[RNANo] = newRNA;
                    RNANo++;
                }
                else if (conversionchoice == 2)
                {
                    DNA tempDNA = DNAV[index];
                    RNA &&newRNA = tempDNA.ConvertToRNA();
                    Protien &&newProtein = newRNA.ConvertToProtein();
                    ProteinV[PNo] = newProtein;
                    PNo++;
                }
                else
                {
                    cout << "wrong choice." << endl;
                }
            }
            break;
        }
        case '2':
        {
            cout << "RNA Sequences:" << endl;
            for (int i = 0; i<RNANo; i++)
            {
                cout << i << ')' << endl << RNAV[i] << endl;
            }
            int index;
            cin >> index;
            if (index < 0 || index >= RNANo)
            {
                cout << "invalid operation. choose an available index" << endl;
            }
            else
            {
                cout << "To:\n 1- Protein\n 2- DNA" << endl;
                int conversionchoice;
                cin >> conversionchoice;
                if (conversionchoice == 2)
                {
                    DNA &&newDNA = RNAV[index].ConvertToDNA();
                    DNAV[DNANo] = newDNA;
                    DNANo++;
                }
                else if (conversionchoice == 1)
                {
                    Protien &&newProtein = RNAV[index].ConvertToProtein();
                    ProteinV[PNo] = newProtein;
                    PNo++;
                }
                else
                {
                    cout << "wrong choice." << endl;
                }
            }
            break;
        }
        }
        break;
    case '5':
        cout << "Choose a sequence:\n 1- DNA\n 2- RNA\n 3- Protein" << endl;
        char Choice7;
        cin >> Choice7;
        cout << "Choose from existing sequences, choose sequence 1 and 2 in relation to each other" << endl;
        switch (Choice7)
        {
        case '1':
        {
            cout << "DNA Sequences:" << endl;
            for (int i = 0; i<DNANo; i++)
            {
                cout << i << ')' << endl << DNAV[i] << endl;
            }
            int index1, index2;
            cin >> index1 >> index2;
            if ((index1 < 0 || index1 >= DNANo) || (index2 < 0 || index2 >= DNANo))
            {
                cout << "invalid operation.choose an available index" << endl;
            }
            else
            {
                int L1 = 0, L2 = 0;
                while (DNAV[index1].getElement(L1) != '\0')
                {
                    L1++;
                }
                while (DNAV[index2].getElement(L2) != '\0')
                {
                    L2++;
                }
                Sequence* s1 = &DNAV[index1];
                Sequence* s2 = &DNAV[index2];
                Align(s1, s2, L1, L2);
            }
            break;
        }
        case '2':
        {
            cout << "RNA Sequences:" << endl;
            for (int i = 0; i<RNANo; i++)
            {
                cout << i << ')' << endl << RNAV[i] << endl;
            }
            int index1, index2;
            cin >> index1 >> index2;
            if ((index1 < 0 || index1 >= RNANo) || (index2 < 0 || index2 >= RNANo))
            {
                cout << "invalid operation.choose an available index" << endl;
            }
            else
            {
                int L1 = 0, L2 = 0;
                while (RNAV[index1].getElement(L1) != '\0')
                {
                    L1++;
                }
                while (RNAV[index2].getElement(L2) != '\0')
                {
                    L2++;
                }
                Sequence* s1 = &RNAV[index1];
                Sequence* s2 = &RNAV[index2];
                Align(s1, s2, L1, L2);
            }
            break;
        }
        case '3':
        {
            cout << "Protein Sequences:" << endl;
            for (int i = 0; i<PNo; i++)
            {
                cout << i << ')' << endl << ProteinV[i] << endl;
            }
            int index1, index2;
            cin >> index1 >> index2;
            if ((index1 < 0 || index1 >= PNo) || (index2 < 0 || index2 >= PNo))
            {
                cout << "invalid operation. choose an available index" << endl;
            }
            else
            {
                int L1 = 0, L2 = 0;
                while (ProteinV[index1].getElement(L1) != '\0')
                {
                    L1++;
                }
                while (ProteinV[index2].getElement(L2) != '\0')
                {
                    L2++;
                }
                Sequence* s1 = &ProteinV[index1];
                Sequence* s2 = &ProteinV[index2];
                Align(s1, s2, L1, L2);
            }
            break;
        }
        default:
            cout << "wrong choice" << endl;
            break;
        }
        break;
    default:
        cout << "wrong choice" << endl;
    }
    goto start;
}

//ctor
