#include <iostream>
#include <string>
#define MAX_BOOKS 20
using namespace std;

class Book {
    public:
        string author;
        string title;
        string subject;
        int pages;
        int recordNumber;
        bool isAvailable;
        Book* Next;

        void bookDetails(Book* ah);
};


void Book::bookDetails(Book* ah)
{
    cout<<"Title:     "<<ah->title<<endl;
    cout<<"Author:    "<<ah->author<<endl;
    cout<<"Record #:  "<<ah->recordNumber<<endl;
    cout<<"Subject:   "<<ah->subject<<endl;
    cout<<"Pages:     "<<ah->pages<<endl;
    if (ah->isAvailable) {
        cout<<"Available: "<<"Yes"<<endl;
    } else {
        cout<<"Availble:  "<<"Currently Out"<<endl;
    }
    cout<<"Press Enter to continue"<<endl;
    cin;
}
int createBook(Book** head, int numBooks)
{
    Book* nb = new Book;
    Book *last = *head;
    numBooks++;
    cout<<"Title: ";
    getline(cin, nb->title, '\n');
    cout<<"Author: ";
    getline(cin, nb->author, '\n');
    cout<<"Subject: ";
    getline(cin, nb->subject, '\n');
    cout<<"Number of pages:";
    cin>>nb->pages;
    nb->isAvailable = true;
    nb->recordNumber = numBooks;
    nb->Next = NULL;
    if (*head == NULL)
    {
        *head = nb;
        return numBooks;
    }
    while (last->Next != NULL)
    {
        last = last->Next;
    }
    last->Next = nb;
    return numBooks;
}

void searchBooks(Book *curr,string criteria, char method)
{
    char decide;
    cout<<"searching for "<<criteria<<"...\n";
    while (curr != NULL)
    {
        switch (method)
        {
        case 'T':
            if (curr->title.compare(criteria) == 0)
            {
                cout<<"Found! Display Details(Y/n)?"<<endl;
                cin>>decide;
                cin.ignore();
                if (decide == 'Y')
                    curr->bookDetails(curr);
            }
        case 'A':
            if (curr->author.compare(criteria) == 0)
            {   
                cout<<"Found! Display Details(Y/n)?"<<endl;
                cin>>decide;
                cin.ignore();
                if (decide == 'Y')
                    curr->bookDetails(curr);
            }
        }
        curr = curr->Next;
    }
}

void reserveBook(string title)
{
    cout<<"You have reserved "<<title<<"\n";
}

int main(int argc, char *argv[])
{
    string title;
    string author;
    Book* head = NULL;
    int numBooks = 0;
    int toDo = 0;
    char srchMethod;
    while (toDo != 5)
    {
        cout<<"Welcome to Max's Library!\n";
        cout<<"Would you like to: \n";
        cout<<"1) add a book\n";
        cout<<"2) search for a book\n";
        cout<<"3) display book details\n";
        cout<<"4) reserve a book\n";
        cout<<"5) exit\n";
        cin>>toDo;
        cin.ignore();
        switch (toDo)
        {
            case 1:
                numBooks = createBook(&head, numBooks);
                break;
            case 2:
                cout<<"How Would you like to search?"<<endl;
                cout<<"(A)uthor, (T)ite, (R)ecord number: ";
                cin>>srchMethod;
                cin.ignore();
                switch (srchMethod)
                {
                    case 'T':
                        cout<<"Enter the Title you would like to search for: ";
                        getline(cin, title, '\n');
                        searchBooks(head, title, srchMethod);
                        break;
                    case 'A':
                        cout<<"Enter the author you would like to search for: ";
                        getline(cin, author, '\n');
                        searchBooks(head, author, srchMethod);
                        break;
                    default:
                        cout<<"Invalid request"<<endl;
                }                      
                break;
            case 3:
                cout<<"Title of book to display: ";
                break;
            case 4:
                cout<<"Title to Reserve: ";
                getline(cin, title, '\n');
                reserveBook(title);
                break;
            case 5:
                exit(0);
            default:
                cout<<"Invalid Entry\n";
        }
    }
    return 0; //all good soldiers.
}