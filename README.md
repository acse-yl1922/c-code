# Advanced Programming Exam Answer CID：02261717, yl1922
In this code I implemented a1.cpp, a2.cpp,b2.cpp for the corresponding question.
"fibo.txt" is already included in the file. You can see it in ../Exam/Exam/fibo.txt

I also wrote Header.h to store the necessary code and answer for *b1* class function.

For quesdtion C, I include all the answers in Matrix.h to avoid linker erros. All declarations are properly included and the answer of c1 will be like this:

    // Copy constructor
    /*
    This copy constructor takes an input Matrix<T> object other as its parameter,
    {
    ...... code ......

    This ensures that any changes to the input matrix after the copy is made do not affect the new matrix.
    */
    } 

    ...... code ended for c1.

For C2 the code should be like this:

    // Perform matrix-vector multiplication assuming row major order
    template <class T>
    {
    ......code......
    }

    // Perform matrix-vector multiplication assuming column major order
    template <class T>
    void Matrix<T>::matVecMult_colmajor(double* input, double* output)
    {
    ......code......        
    }
    

I also give the implementation for the matrix*vector methods of 2 versions to validate my answers.

The following picture gives the outcome for all the questions.
<img src="output.png"/>



