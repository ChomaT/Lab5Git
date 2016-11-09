// Lab9_vectors.cpp
// This program shows some simple vector examples, and asks for simple tasks.
// Reference: Lippman, section 3.3

// Author: Luis Rivera

// IMPORTANT NOTE: YOU MAY NEED TO COMPILE ADDING THE FOLLOWING FLAG: -std=c++11
// Example: g++ Lab9_vectors.cpp -o Lab9_vectors -std=c++11
// Some initialization methods and other things are not supported by the old standard.

#include <iostream>
#include <vector>

using namespace std;

// Main function. Shows a few examples. Complete the assignments stated in the comments.

int main() {
    vector<int> ivec1(5), ivec2;
    vector<double> dvec1{5.1}, dvec2(5, 1.5);
    vector<string> svec1 = {"hello", "world"};
    // vector<myClass> myCvec;	// you can have vectors of objects
    // in general: vector<Type> vec;	// vector is a template

    for (int i = 0; i < ivec1.size(); i++)
        cout << ivec1[i] << endl;
    cout << "\n------------------------------------------------------------------" << endl;

    for (auto i : ivec1) // This is equivalent to the above for loop
        cout << i << endl;
    cout << "\n------------------------------------------------------------------" << endl;

    for (auto i : dvec1)
        cout << i << endl;
    cout << "\n------------------------------------------------------------------" << endl;

    for (auto i : dvec2)
        cout << i << endl;
    cout << "\n------------------------------------------------------------------" << endl;

    for (auto i : svec1)
        cout << i << endl;
    cout << "\n------------------------------------------------------------------" << endl;

    cout << "Original size: " << ivec2.size() << endl;
    ivec2.push_back(50);
    cout << "New size: " << ivec2.size() << "\nAdded element: " << ivec2[0] << endl;
    cout << "\n------------------------------------------------------------------" << endl;

    // ***********************************************************************
    // Try all the ways to initialize a vector shown in Table 3.4. Use the
    // vectors above and/or declare new vectors.
    // Some of those operations have already been used, but write your
    // own examples.

    char test = 'y';
    vector<char>v1;
    vector<char>v2 = v1;
    vector<char>v3(10, 'x');
    vector<char>v4(test);
    vector<char>v5{'a','b','c'};
    vector<char>v6 = {'a', 'b', 'c'};

    // Do exercises 3.14 and 3.15 from Lippman (page 102)

    vector<int>vec1;
    for (auto &i : vec1){
    	cin >> i;
    }

    vector<string>vec2;
	for (auto &i : vec1){
		cin >> i;
	}
    // Try all the vector operations shown in table 3.5. Use the vectors above
    // or define new ones. Try different types.
    // ***********************************************************************

    if (v1.empty() == true)
    	cout<"True";
    else
    	cout<<"False"<<endl;
    cout<<"Size is: "<< v1.size()<<endl;
    v1.push_back('X');
    v1 = v2;
    cout<<"v1[1] == "<<v1[1]<<endl;
    v1 = {'a','b','c'};
    if (v1 == v2)
    	cout<<"True"<<endl;
    else
    	cout<<"False"<<endl;


    return 0;
}
