#include<iostream>
#include<string.h>
using namespace std;
class Bookshop
{
    public:
    int stockPosition;
    char author[20], title[20], publisher[20];
    float price;
    void getdata();
    void show(int copy);
};
void Bookshop::getdata()
{
    cin.ignore();
    cout<<"Enter author name: ";
    cin.getline(author,20);
    cout<<"Enter the title of book: ";
    cin.getline(title,20);
    cout<<"Enter publisher name: ";
    cin.getline(publisher,20);
    cout<<"Enter price: ";
    cin>>price;
    cout<<"Enter number of books available: ";
    cin>>stockPosition;
}
void Bookshop::show(int copy)
{
    cout<<"\nThis is your book details\n";
    cout<<endl<<"Title: "<<title;
    cout<<endl<<"Author: "<<author;
    cout<<endl<<"Publisher: "<<publisher;
    cout<<endl<<"Total Price: "<<price*(float)copy;
    cout<<endl<<"Updated Stock Position: "<<stockPosition;
}
int main()
{
    Bookshop b[10];
    char author1[20], title1[20];
    int n, copies;
    cout<<"Enter number of books in store: ";
    cin>>n;
    for(int i=0; i<n; i++){
        b[i].getdata();
    }
    cout<<"\nWelcome to my Bookshop\nEnter name of book you want: ";
    cin.ignore();
    cin.getline(title1,20);
    cout<<"Enter the author: ";
    cin.getline(author1,20);
    for(int i=0; i<n; i++){
        if(strcmp(author1, b[i].author ) == 0  && strcmp(title1, b[i].title) == 0){
            cout<<"\nThis book is available\nHow many copies you want?";
            cin>>copies;
            if(copies<=b[i].stockPosition){
                cout<<"\nTotal Price is: \n"<<b[i].price*(float)copies;
                b[i].stockPosition -= copies;
                b[i].show(copies);
            }else{
                cout<<"Out of stock! Try reducing copies";
                break;
            }
        }else{
            cout<<"\nPlease wait checking in my Bookshop....\n";
            if(i==n-1){
                cout<<"\nThis book is not available";
            }
        }
    }
    return 0;
}

