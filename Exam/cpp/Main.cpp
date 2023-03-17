#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Header.h"
#include "Matrix.h"

using namespace std;

int main() {
    // Roll dice 1000 times
    while (true)
    // The while loop continue asks user to play with the programme 
    // until user enter "n" to end the programme.
    {
        //create a user interface
        cout << "Ready to roll dice?(y/n):" << endl;
        char c;
        cin >> c;
        if (c == 'y')
        {
            cout << "Start Rolling!" << endl;
        }
        if (c == 'n') {
            cout << "Programme End!" << endl;
            break;
        }

        int count = roll_dice(1000);

        // Print number of times 6 appears
        cout << "Number of times 6 appears: " << count << endl;
    }
 
    cout << "Continue to question a2------------------------------------------------------------------------------" 
    << endl;

    /*a2 part*/

    // Initialize vector of strings
    vector<string> strings = { "Evelyn Quan", "Waymond Wang", "Deirdre", "Jobu Tupaki", "Gong Gong", "Becky Sregor" };
    // Apply function to each string
    for (string& str : strings) {
        makeAlternatingCase(str);
    }

    // Print modified strings to screen
    for (const string& str : strings) {
        cout << str << endl;
    }

    cout << "Continue to question b1--------------------------------------------------------------------------------" 
    << endl;

    /*b1 part*/
    cout << "I write the class declaration in Header.h" << endl;
    MagicNumber magic1(1);

    //Call the special plus one operator
    magic1++;
    cout << "\nMy magic number: " << magic1.getInt();//printss 7

    //Call the second special plus one operator
    ++magic1;
    cout << "\nMy magic number now: " << magic1.getInt();//printss 11

    cout<<endl;

    cout << "Continue to question b2--------------------------------------------------------------------------------"
        << endl;

    // Generate the first 100 Fibonacci numbers and write them to a file
    generateFibonacciSequence();

    cout << "fibo.txt successfully generated"<< endl;

    cout << "Continue to question c--------------------------------------------------------------------------------"
        << endl;

    //This part is for validation

    // Create a matrix with row major order
    double values[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    Matrix<double> mat(3, 3, values);
    mat.printMatrix();

    // Create input and output vectors
    double input[] = { 1, 2, 3 };
    double output_rowmajor[2] = { 0 };
    double output_colmajor[2] = { 0 };

    cout << "vector is :{ ";
    for (auto &i : input)
    {
        cout << i <<" ";
    
    }
    cout << "}" << endl;

    // Compute matrix-vector product assuming row major order
    mat.matVecMult_rowmajor(input, output_rowmajor);
    cout << "Row-major product: ";
    for (int i = 0; i < 2; i++)
    {
       cout << output_rowmajor[i] << " ";
    }
    cout << endl;

    // Compute matrix-vector product assuming column major order
    mat.matVecMult_colmajor(input, output_colmajor);
    cout << "Column-major product:";
    for (int i = 0; i < 2; i++)
    {
        cout << output_colmajor[i] << " ";
    }
    cout << endl;

    return 0;
}





