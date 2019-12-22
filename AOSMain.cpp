//Make sure you compile as executable with the following command:
//g++ AOSMain.cpp -o /usr/lib/cgi-bin/AOSMain.cgi

#include <iostream>
#include <fstream>
#include <sstream>


int main()
{
	std::cout << "Content-type: text/html\n\n";
	
	//Pull query string from website
	std::string data = getenv("QUERY_STRING");
	
	//Change std::string data into an input stream of chars
	std::istringstream inputSS(data);
	
	//inputSS either equals "ans=y" or "ans=n"
	//temp is used to throw away first four characters of stream, "ans="
	//val holds action character, signaling yes or no
	char temp, val;
	
	//If statement operating on query string, throwing away stream characters, storing val.
	if(inputSS >> temp >> temp >> temp >> temp >> val)
	{
		//if user selects yes button, the html is outputted for next step.
		if(val == 'y')
		{
			//Check 'Bidding.html' for formatted version of this HTML. It may not be current.
			std::cout << "<!DOCTYPE html>\n<html>\n<head>\n<link rel=\"stylesheet\" href=\"/AOSBid/_css/AOSStyles.css\">\n<meta name=\"Ace of Spades: Online Bidding\">\n<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n<title>AOSBid</title>\n</head>\n<body>\n<h1>Welcome to Ace of Spades</h1>\n<div class=\"main\">\n<p class=\"bodyp\">Let's Begin!</p><br>\n";
			
			//Outputs form which takes in four names and four bids.
			//"Form action" links to new cpp file which will hold processing algorithm
			std::cout << "<form class=\"bidform\" action=\"http://localhost:8080/cgi-bin/Processing.cgi\">\nName:&nbsp;<input type=\"text\" name=\"name1\"></input>&nbsp;\nBid:&nbsp;<input  type=\"text\" name=\"bid1\"></input><br><br>\nName:&nbsp;<input type=\"text\" name=\"name2\"></input>&nbsp;\nBid:&nbsp;<input type=\"text\" name=\"bid2\"></input><br><br>\nName:&nbsp;<input type=\"text\" name=\"name3\"></input>&nbsp;\nBid:&nbsp;<input type=\"text\" name=\"bid3\"></input><br><br>\nName:&nbsp;<input type=\"text\" name=\"name4\"></input>&nbsp;\nBid:&nbsp;<input type=\"text\" name=\"bid4\"></input><br><br>\n<button type=\"submit\" name=\"submit\">Bid!</button>\n</form>\n</div>\n<div class=\"footer\">\n<p>Ace of Spades, All Rights Reserved</p>\n<p>Contact Us</p>\n<p>2019 Group Lab, Advait S, Kankshat P, Nishant P. <em>The Dream Team</em></p>\n</div>\n</body>\n<script src=\"_js/script.js\"></script>\n</html>";
		}
		
		//if user selects no, a goodbye page is outputted and the program is done running.
		else if(val == 'n')
		{
			//Check 'Goodbye.html' for formatted version of this html. It is current.
			std::cout << "<!DOCTYPE html>\n<html>\n<head>\n<link rel=\"stylesheet\" href=\"/AOSBid/_css/AOSStyles.css\"\n<meta name=\"Ace of Spades: Online Bidding\">\n<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n<title>AOSBid</title>\n</head>\n<body>\n<h1>Thank you for visiting Ace of Spades</h1>\n<div class=\"main\">\n<img class=\"byeimg\" src=\"/AOSBid/_images/AceOfSpades.png\">\n</div>\n<div class=\"footer\">\n<p>Ace of Spades, All Rights Reserved</p>\n<p>Contact Us</p>\n<p>2019 Group Lab, Advait S, Kankshat P, Nishant P. <em>The Dream Team</em></p>\n</div>\n</body>\n<script src=\"_js/script.js\"></script>\n</html>";
		}
	}
	
}
