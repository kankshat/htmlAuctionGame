/*
	Advait Shukla
	Processing Program
	
	All block comments below define function objective
	All single line comments define line by line or block by block
 
    Compile as executable with the following command:
    
    g++ Processing.cpp -o /usr/lib/cgi-bin/Processing.cgi
*/

#include <iostream>
#include <fstream>
#include <sstream>

//Bid structure holding a name and a bidprice
struct bid
{
	std::string name;
	double bidprice;
};

int main()
{
	//Necessary cout to write html pages
	std::cout << "Content-type: text/html\n\n";
	
	//Pull query string from website, everything after the question mark.
	std::string data = getenv("QUERY_STRING");
	
	/*
		The commented string below is a sample query string. 
	*/
		//std::string data = "name1=asas&bid1=26&name2=asdf&bid2=44&name3=bar&bid3=45&name4=yuh&bid4=98&submit=";

	//array of bid object. Holds name and bid in one element.
	bid query[4];

	
	/*Fill name and bid arrays with variables from query string*/
	for(int i = 0; i < 4; i++)
	{
		//parses a substring of the query string from the start until a '&' is found. 
		//parse will not contain the '&' character in it.
		std::string parse = data.substr(0, data.find('&'));
		
		//stores a substring of the parsed substring from element 6 to the end of the substring
		//elements 0 to 5 contain 'name1=' or 'name2=', so they must be thrown away
		query[i].name = parse.substr(6, std::string::npos);
		
		//erases the processed part of the query string, including the '&'
		data.erase(0, data.find('&') + 1);
		
		//parse is now overwritten with a new substring from 0 to '&'
		parse = data.substr(0, data.find('&'));
		
		//converts parse to an int before storing it in bidprice
		//elements 0 to 4 contain 'bid1=' or 'bid2=' and must be thrown away
		query[i].bidprice = stoi(parse.substr(5, std::string::npos));
		
		//erases the newly processsed part of the query string, including the '&'.
		data.erase(0, data.find('&') + 1);
	}
	
	/***************
	From this point forward, the comments represent c++ snippets that must be plugged in
	All variables used have been tweaked to cater to your writing style.
	Plug and Play. If it does not work, message me.
	***************/
	
	
	/*Build min_heap for both items from file*/
	
	/*build min_heap for bids*/
	
	/*Match roots*/
	
	/*Pop root*/
	
	/*cout sales, with name of successful bidders and 
	
	/*Re heap*/
	
	/* filestream out both leftover heaps*/
	
	//memory is erased after each time the 'Bid!' button is pressed on the website,
	//leftover inventory must be updated each time in order to ensure successful operation

	
	
	//More HTML header stuff. not important to explain. Check 'Bidding.html' again
	std::cout << "<!DOCTYPE html>\n<html>\n<head>\n<link rel=\"stylesheet\" href=\"/AOSBid/_css/AOSStyles.css\">\n<meta name=\"Ace of Spades: Online Bidding\">\n<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n<title>AOSBid</title>\n</head>\n<body>\n<h1>Welcome to Ace of Spades</h1>\n<div class=\"main\">\n<p class=\"bodyp\">Let's Begin!</p><br>\n";
	/*
		For loop below is for debugging only, testing whether query string parses properly
	*/
	/*for(int i = 0; i < 4; i++)
	{
		std::cout << "<p>Name " << i + 1 << ": " << query[i].name << " Bid " << i + 1 << ": " << query[i].bidprice << "</p>\n";
	}*/
	
	//std::cout << "</div>\n</body>\n</html>";
	
	//outputs new form to take in more bids. Notice it links to itself, meaning memory
	//will be cleared. Clicking 'Bid!' button will reload this page with updated parameters
	std::cout << "<form class=\"bidform\" action=\"http://localhost:8080/cgi-bin/Processing.cgi\">\nName:<input type=\"text\" name=\"name1\"></input>&nbsp;\nBid:<input  type=\"text\" name=\"bid1\"></input><br><br>\nName:<input type=\"text\" name=\"name2\"></input>&nbsp;\nBid:<input type=\"text\" name=\"bid2\"></input><br><br>\nName:<input type=\"text\" name=\"name3\"></input>&nbsp;\nBid:<input type=\"text\" name=\"bid3\"></input><br><br>\nName:<input type=\"text\" name=\"name4\"></input>&nbsp;\nBid:<input type=\"text\" name=\"bid4\"></input><br><br>\n<button type=\"submit\" name=\"submit\">Bid!</button>\n</form>\n</div>\n<div class=\"footer\">\n<p>Ace of Spades, All Rights Reserved</p>\n<p>Contact Us</p>\n<p>2019 Group Lab, Advait S, Kankshat P, Nishant P. <em>The Dream Team</em></p>\n</div>\n</body>\n<script src=\"_js/script.js\"></script>\n</html>";
	
}
