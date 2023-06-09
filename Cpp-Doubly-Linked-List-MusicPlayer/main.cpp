#include <iostream>
using namespace std;

struct Song
{
    //Data
    int ID;
    string Name;
    int IsFavorite = 0;
    string Time;
    //

    //Pointers
    Song* Next;
    Song* Previous;

};

int main()
{
    Song* Head = NULL;
    Song* Last = NULL;
    Song* CSong = NULL;
    int menu = 0;
    while (menu != -1)
    {
        cout << "1- Yeni bir sarki ekle "<<endl;
        cout << "2- Sarki Listemi goster "<<endl;
        cout << "3- Sonraki sarkiyi cal "<<endl;
        cout << "4- Onceki sarkiyi cal "<<endl;
        cout << "5- Cikis "<<endl;
        cout << endl;
        cout << "Seciminiz:";
        cin >> menu;

        switch(menu)
        {
            case 1:
            {
                Song* NewSong = new Song();

                cout << "Sarki ID" << endl;
                cin >> NewSong->ID;
                cout << "Sarki Adi"<<endl;
                cin >> NewSong->Name;
                cout << "Favori mi? (1 Favori 0 Degil)" << endl;
                cin >> NewSong->IsFavorite;
                cout << "Sarki suresi" << endl;
                cin >> NewSong->Time;

                if (Head == NULL)
                {
                    Head = NewSong;
                    Last = NewSong;
                } 
                else
                {
                    NewSong->Next = Head;
                    Head->Previous = NewSong;
                    Head = NewSong;
                }
                CSong = NewSong;
            }
            break;
            case 2:
            {
                Song* NewSong = Head;
                cout << "ID\t" << "Ad\t" << "Favori\t" << "S�re" << endl;
                while (NewSong != NULL)
                {
                    cout << NewSong->ID <<"\t" << NewSong->Name << "\t" << NewSong->IsFavorite << "\t" << NewSong->Time << endl;
                    NewSong = NewSong->Next;
                }
            }
            break;
            case 3:
            {
                //Son Sark�ya geldiysem listenin ba��na d�nmeliyim - Circular Link List
                if (CSong == Last)
                {
                    CSong = Head;
                }
                else
                {
                    CSong = CSong->Next;
                }
                cout << "Sarki degisiyor" << endl;
                cout << "Sarki caliniyor : " << CSong->Name << endl;
            }
            break;
            case 4:
            {
                //E�er �lkNode a geldiysem Son Node a d�nmeliyim.
                if (CSong == Head)
                {
                    CSong = Last;
                }
                else
                {
                    CSong = CSong->Previous;
                }
                cout << "Sarki degisiyor" << endl;
                cout << "Sarki caliniyor : " << CSong->Name << endl;
            }
            break;
            case 5:
            {
                menu = -1;
                cout << "Yazilimi kullandiginiz icin tesekkur ederiz" << endl;
            }
            break;
        }



    }



}

