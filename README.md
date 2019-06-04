# project name
	Occupation Search System

# Developers
	GROUP 9
	21300013 YechanKang, 21300150 YoseopKim, 21500477 DoeunLee, 21700550 YuriLee
	Github : https://github.com/LEEYURI21700550/OSS_project

# Description
	This program provides basic information about programming related companies and Graduate schools, and provides information that matches to the user's input. 
	
	At first, the program parses json file and parses them into tokens. 
	The parsed datas are shown with each token's size, range and type. 
	
	Next, it prints the menu. User can select one of those menu to print out the result. 
	For example, user can search companies by their name, company size, annual income and job type. 
	
	Other than menus about searching, there are multiple options to enter user's information and get recommendation, or ask for get help from someone else, like professor. 
	Those menus provides information about the graduate schools or adviser's contact mail.
	The menu will be presented until user selects '9. Quit Program'. 
	
# Run
	1. Repeat below: 
		$ gcc -o OSS.exe *.c
		$ ./OSS.exe your_json.json
	2. Select one of the numbers in menu
	3. use the program
	4. quit the program by pressing 9 or Ctrl+C.
	
# When to use
	This program is perfect for those who are looking for programming related job. 
	If the user wants to search jobs by some criteria(ex, size of the company/ annual income/ location...) user can use this program as searching engine, and get useful information from it. 
	So user can manage one's information efficiently by updating json file and searching information using the program.
	


