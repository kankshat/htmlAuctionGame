#include <iomanip>
#include <iostream>
#include <fstream>
#include <vector>
struct book
{
    double bookprice;
    std::string bookname;
    int numcopies;
};

struct bid
{
    std::string name;
    double bidprice;
    int itemnum;
};

/*
    Create a priirity queue for each book
 
 
 */

void getNumBooks(int&, int&, std::string&);
void getContents(book[], book[], std::string, int&, int&);
void printallbooks(book[], int, book[], int);
void insertbook(std::string, int, double, int&, book[]);
void reheapBid(std::vector<bid>&, double);
void reheapBook(book[], int);
void compare(book[], int, std::vector<bid>&, double, bool);
void printBids(std::vector<bid>, double);
void displayBookToBid(book[], int);
void fillBidArray(bid[]);

int main()
{
    char rep = 'y';
    while(rep == 'y'){
        
        std::cout << std::setprecision(2) << std::fixed;
        int b1=1, b2=1;
        std::string filename;
        getNumBooks(b1, b2, filename);
        book *booklist1 = new book[b1];
        book *booklist2 = new book[b2];
        std::cout << b1 << b2 << std::endl;
        int sizeArray1 = b1, sizeArray2 = b2;
        getContents(booklist1, booklist2, filename, sizeArray1, sizeArray2);
        printallbooks(booklist1, sizeArray1, booklist2, sizeArray2);
        //these next two lines as well as fillBidArray fn will not be needed
        bid query[4];
        fillBidArray(query);

        int count = 0;
        
        std::vector<bid> bidlist1;
        std::vector<bid> bidlist2;
        std::vector<bid> bidlist3;
        std::vector<bid> bidlist4;
        
        
        bidlist1.push_back(query[count]);
        bidlist2.push_back(query[count]);
        bidlist3.push_back(query[count]);
        bidlist4.push_back(query[count]);
        int bidcopy1=0, bidcopy2=0, bidcopy3=0, bidcopy4=0; //bid copy is the copy that the bidder wants, ie bidcopy 1 is whatever copy bidder number 1 is bidding on
        
        
        while(count < 4) //count+1 = which bidder is bidding, max of four bidders
        {
            if(count == 0)
                bidcopy1 = query[count].itemnum;
            else if(count ==1)
                bidcopy2 = query[count].itemnum;
            else if(count ==2)
                bidcopy3 = query[count].itemnum;
            else if(count ==3)
                bidcopy4 = query[count].itemnum;
            
            count++;
        }
        
        bidlist1.push_back(query[0]); //pushing query object into one vector
        
        if(bidcopy2 == bidcopy1)
            bidlist1.push_back(query[1]);
        else
            bidlist2.push_back(query[1]);
        
        if(bidcopy3 == bidcopy1)
            bidlist1.push_back(query[2]);
        else if(bidcopy3 == bidcopy2)
            bidlist2.push_back(query[2]);
        else
            bidlist3.push_back(query[2]);
        
        if(bidcopy4 == bidcopy1)
            bidlist1.push_back(query[3]);
        else if(bidcopy4 == bidcopy2)
            bidlist2.push_back(query[3]);
        else if(bidcopy4 == bidcopy3)
            bidlist3.push_back(query[3]);
        else
            bidlist4.push_back(query[3]);
        
        
        //heap all the bids so the highest bid is in the root
       
        reheapBid(bidlist1, bidlist1.size());
        reheapBid(bidlist2, bidlist2.size());
        reheapBid(bidlist3, bidlist3.size());
        reheapBid(bidlist4, bidlist4.size());
        
        std::cout << bidlist1.size() << bidlist2.size() << bidlist3.size()<< bidlist4.size() << std::endl;
        printBids(bidlist1, bidlist1.size());
        printBids(bidlist2, bidlist2.size());
        printBids(bidlist3, bidlist3.size());
        printBids(bidlist4, bidlist4.size());
        std::cout <<std::endl;
        //bid list 1
        bool comparingBookList1 = true;
        if(bidlist1.size() > 1)
        {
            if(bidlist1[1].itemnum <= sizeArray1 && sizeArray1 >=1) //want to buy from booklist2
            {
                compare(booklist1, b1, bidlist1, bidlist1.size(), comparingBookList1);
                sizeArray1--;
            }
            else if(sizeArray2 >= 1 && bidlist1[1].itemnum > sizeArray1) //bidders that w
            {
                comparingBookList1 = false;
                bidlist1[1].itemnum -=b1;
                compare(booklist2, b2, bidlist1, bidlist1.size(), comparingBookList1);
                sizeArray2--;
            }
        }
        comparingBookList1 = true;
        if(bidlist2.size() > 1)
        {
            if(bidlist2[1].itemnum <= sizeArray1 && sizeArray1 >=1) //want to buy from booklist2
            {
                compare(booklist1, b1, bidlist2, bidlist2.size(), comparingBookList1);
                sizeArray1--;
            }
            else if(sizeArray2 >= 1 && bidlist2[1].itemnum > sizeArray1)
            {
                comparingBookList1 = false;
                bidlist2[1].itemnum -=b1;
                compare(booklist2, b2, bidlist2, bidlist2.size(), comparingBookList1);
                sizeArray2--;
            }
        }
        comparingBookList1 = true;
        if(bidlist3.size() > 1)
        {
            if(bidlist3[1].itemnum <= sizeArray1 && sizeArray1 >=1) //want to buy from booklist2
            {
                compare(booklist1, b1, bidlist3, bidlist3.size(), comparingBookList1);
                sizeArray1--;
            }
            else if(sizeArray2 >= 1 && bidlist3[1].itemnum > sizeArray1)
            {
                comparingBookList1 = false;
                bidlist3[1].itemnum -=b1;
                compare(booklist2, b2, bidlist3, bidlist3.size(), comparingBookList1);
                sizeArray2--;
            }
        }
        comparingBookList1 = true;
        if(bidlist4.size() > 1)
        {
            if(bidlist4[1].itemnum <= sizeArray1 && sizeArray1 >=1) //want to buy from booklist2
            {
                compare(booklist1, b1, bidlist4, bidlist4.size(), comparingBookList1);
                sizeArray1--;
            }
            else if(sizeArray2 >= 1 && bidlist4[1].itemnum > sizeArray1)
            {
                comparingBookList1 = false;
                bidlist4[1].itemnum -=b1;
                compare(booklist2, b2, bidlist4, bidlist4.size(), comparingBookList1);
                sizeArray2--;
            }
        }
        std::ofstream outputfile("/Users/kankshatpatel/CLASSES/CS/cs124/LABS/lab5-cgi_priority_queue/booklist.txt");
        for (int i=1; i < b1 ;i++) {
            if(booklist1[i].bookprice != 1000)
            {
                outputfile << booklist1[i].bookname << " C" << booklist1[i].numcopies << " $" << booklist1[i].bookprice<<"\n";
                std::cout << booklist1[i].bookname << " C" << booklist1[i].numcopies << " $" << booklist1[i].bookprice<<std::endl;
            }
        }
        for (int i=1; i < b2 ;i++) {
            if(booklist2[i].bookprice != 1000)
            {
                outputfile << booklist2[i].bookname << " C" << booklist2[i].numcopies << " $" << booklist2[i].bookprice <<"\n";
                std::cout << booklist2[i].bookname << " C" << booklist2[i].numcopies << " $" << booklist2[i].bookprice<<std::endl;
            }
        }
        std::cout << "REP?";
        std::cin >> rep;
        
    }
}
void getNumBooks(int& b1, int& b2,std::string& filename)
{
        std::string bookname, book1, book2;
        double bookprice;
        int numcopies=0;
        char ignored_character;
        std::ifstream bookinfo("/Users/kankshatpatel/CLASSES/CS/cs124/LABS/lab5-cgi_priority_queue/booklist.txt");
        if(bookinfo.is_open())
        {
            bookinfo >> bookname >> ignored_character >> numcopies >> ignored_character >> bookprice;
            b1++;
            book1 = bookname;
            while(!(bookinfo.eof()))
            {
                bookinfo >> bookname >> ignored_character >> numcopies >> ignored_character >> bookprice;
                if(book1 == bookname)
                    b1++;
                else if(book2 == bookname)
                    b2++;
                else
                    book2= bookname;
            }
            bookinfo.close();
        }
        else
            std::cout << "unable to open file. Sorry!\n";
        
}

void getContents(book booklist1[], book booklist2[], std::string filename, int& sizeArray1, int& sizeArray2)
{
    std::string bookname, whichbook;
    double price;
    int copy=0, i=0, max = (sizeArray1 + sizeArray2) - 2;
    sizeArray1=1;
    sizeArray2=1;
    char ignored_character;
    std::ifstream bookinfo2("/Users/kankshatpatel/CLASSES/CS/cs124/LABS/lab5-cgi_priority_queue/booklist.txt");
       if(bookinfo2.is_open()){
           while(!(bookinfo2.eof()) && i < max)
           {
               bookinfo2 >> bookname >> ignored_character >> copy >> ignored_character >> price;
               if(booklist1[1].bookname == "" || booklist1[1].bookname == bookname)
                   insertbook(bookname, copy, price, sizeArray1, booklist1);
               else if(booklist2[1].bookname == "" || booklist2[1].bookname == bookname)
                   insertbook(bookname, copy, price, sizeArray2, booklist2);
               i++;
           }
           bookinfo2.close();
       }
       else
           std::cout << "unable to open file. Sorry!!\n";
       std::cout << std::endl;
}

void printallbooks(book list1[], int size1, book list2[], int size2)
{
    std::cout << std::left << std::setw(42) << "NAME"  << std::left << std::setw(10) << "COPY" << std::left << std::setw(6) << "PRICE" << std::endl;
    for(int i =1; i < size1; i++)
        std::cout << list1[i].bookname << "                    " << list1[i].numcopies << "    $" << list1[i].bookprice << std::endl;
    for(int i =1; i < size2; i++)
        std::cout << list2[i].bookname << "     " << list2[i].numcopies << "    $" << list2[i].bookprice << std::endl;
}

void printBids(std::vector<bid> bids, double size)
{
    for (int i =1; i < size; i++)
        std::cout << bids[i].name << " wants to bid on item " << bids[i].itemnum << "   for $"<< bids[i].bidprice << std::endl;
}

void insertbook(std::string name, int copy, double price, int& size, book list[])
{
    list[size].bookname = name;
    list[size].bookprice = price;
    list[size].numcopies = copy;
    int i = size; //index of most recent entry
    while (i != 1 && list[i].bookprice < list[i/2].bookprice)  //child is greater than the parent so we swap
    {
        //swap names and copies of all
        double temp1 = list[i].bookprice;
        list[i].bookprice = list[i/2].bookprice;
        list[i/2].bookprice = temp1;

        std::string temp = list[i].bookname;
        list[i].bookname = list[i/2].bookname;
        list[i/2].bookname = temp;

        int temp2 = list[i].numcopies;
        list[i].numcopies = list[i/2].numcopies;
        list[i/2].numcopies = temp2;
        i/=2;
    }
    size++;
}


void reheapBid(std::vector<bid>& bidvector, double size)
{
    for(int i =1; i < size; i++){
        int num = i;
        while(num!= 1 && bidvector[num].bidprice > bidvector[num/2].bidprice) //while child is greater than parent
        {
            //swap prices
            double temp = bidvector[num].bidprice;
            bidvector[num].bidprice = bidvector[num/2].bidprice;
            bidvector[num/2].bidprice = temp;
            
            //swap names
            std::string temp2 = bidvector[num].name;
            bidvector[num].name = bidvector[num/2].name;
            bidvector[num/2].name = temp2;
            
            //swap item numbers
            int temp3 = bidvector[i].itemnum;
            bidvector[i].itemnum = bidvector[i/2].itemnum;
            bidvector[i/2].itemnum = temp3;
            
            num/=2;
        } //end while
    }//end for
}



void compare(book booklist[], int b1, std::vector<bid>& bidlist, double size, bool comp)
{
    //bidlist[1] will always hold the highest bid for a certain book
    
    int indexOfBook = bidlist[1].itemnum;
    if(bidlist[1].bidprice >= booklist[indexOfBook].bookprice) //if the bidder is bidding more than asking price
    {
        std::cout << "SOLD TO " << bidlist[1].name << "     FOR $" <<  bidlist[1].bidprice;
        if(comp)
            std::cout << "     Item# " << bidlist[1].itemnum << std::endl;
        else
            std::cout << "     Item# " << bidlist[1].itemnum+b1 << std::endl;
        booklist[indexOfBook].bookprice = 1000;
        
    }
}

void displayBookToBid(book booklist[], int size)
{
    //we are bidding on
    std::cout << "WE ARE BIDDING ON " << booklist[1].bookname << ", COPY " << booklist[1].numcopies;
    std::cout << " WITH ASKING PRICE: $" << booklist[1].bookprice << std::endl;
}

void fillBidArray(bid bidarray[])
{
    bidarray[0].bidprice = 10.12;
    bidarray[1].bidprice = 10.90;
    bidarray[2].bidprice = 10.33;
    bidarray[3].bidprice = 10.33;
    bidarray[3].name = "KEVIN";
    bidarray[1].name = "BOB";
    bidarray[2].name = "DAVID";
    bidarray[0].name = "RAJESH";
    bidarray[1].itemnum = 1;
    bidarray[2].itemnum = 3;
    bidarray[3].itemnum = 10;
    bidarray[0].itemnum = 5;
}
