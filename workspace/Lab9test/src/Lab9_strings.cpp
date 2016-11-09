// Lab9_strings.cpp
// This program shows some simple string examples, and asks for simple tasks.
// Reference: Lippman, section 3.2

// Author: Luis Rivera

#include <iostream>
#include <string>

using namespace std;

// Main function. Shows a few examples. Complete the assignments stated in the comments.
int main()
{
        int i;
	string s1, s2("Hello"), s3 = "World";
	cout << "\nEnter a word:" << endl;
	cin >> s1;

	string s4(s1);

	cout << s1 << endl
		 << s2 << endl
		 << s3 << endl
		 << s4 << endl;

	s1 = s2 + s3;
	cout << s1 << endl;

// ***********************************************************************
// Try all the operations in Table 3.2 using the strings above and
// using new strings that you may declare.
// Some of those operations have already been used, but write your
// own examples.
// ***********************************************************************

        if(s1.empty() == true)
            cout<<"True"<<endl;
        else
            cout<<"False"<<endl;
        i = s2.size();
        cout<<"Size is: "<<i<<endl;
        cout<<"s1[1] is: "<<s1[1]<<endl;
        cout<<"s1 + s2: "<< s1 + s2 << endl;
        s1=s2;


// -----------------------------------------------------------------------
	string line;
	cout << "\nEnter some text, finish it with an &" << endl;
	getline(cin, line, '&');
	cout << line << endl;

// ***********************************************************************
// Use a "Range for" (Lippman, page 93) and operations in table 3.3 to:
// 1) change the case of the letters in your input line above (upper to
//    lowercase and vice-versa).
// 2) Replace any whitespace with a dot ('.').
// Print the converted text.
// ***********************************************************************
        for( const char x : line)
        {
            if(islower(x))
                cout<< toupper(x);
            else if(x == ' ')
                cout<<'.';
            else
                cout<< tolower(x);
        }
	return 0;
}
