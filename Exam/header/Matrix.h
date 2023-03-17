#pragma once

template <class T>
class Matrix
{
public:

    // constructor where we want to preallocate ourselves
    Matrix(int rows, int cols, bool preallocate);
    // constructor where we already have allocated memory outside
    Matrix(int rows, int cols, T* values_ptr);

    Matrix(const Matrix<T>& other);

    // destructor
    virtual ~Matrix();

    // Print out the values in our matrix
    void printValues();
    virtual void printMatrix();

    // Perform some operations with our matrix
    void matMatMult(Matrix<T>& mat_left, Matrix<T>& output);

    //Ver1 matrix-vector product
    void matVecMult_rowmajor(double* input, double* output);
    //Ver2 matrix-vector product
    void matVecMult_colmajor(double* input, double* output);

    // Explicitly using the C++11 nullptr here
    T* values = nullptr;
    int rows = -1;
    int cols = -1;

    // We want our subclass to know about this
protected:
    bool preallocated = false;

    // Private variables - there is no need for other classes 
    // to know about these variables
private:

    int size_of_values = -1;
};


// Constructor - using an initialisation list here
template <class T>
Matrix<T>::Matrix(int rows, int cols, bool preallocate) : rows(rows), cols(cols), size_of_values(rows* cols), preallocated(preallocate)
{
    // If we want to handle memory ourselves
    if (this->preallocated)
    {
        // Must remember to delete this in the destructor
        this->values = new T[size_of_values];
    }
}

// Constructor - now just setting the value of our T pointer
template <class T>
Matrix<T>::Matrix(int rows, int cols, T* values_ptr) : rows(rows), cols(cols), size_of_values(rows* cols), values(values_ptr)
{}

// destructor
template <class T>
Matrix<T>::~Matrix()
{
    // Delete the values array
    if (this->preallocated) {
        delete[] this->values;
    }
}


// Copy constructor
/*
This copy constructor takes an input Matrix<T> object other as its parameter,
and creates a new instance of Matrix<T> with the same dimensions as other.
It then allocates memory for the values array,
and uses std::copy to copy the values from other.values to this->values.

*/
template <class T>
Matrix<T>::Matrix(const Matrix<T>& other) : rows(other.rows), cols(other.cols), size_of_values(rows* cols), preallocated(other.preallocated)
{
    // Allocate memory for values
    if (this->preallocated)
    {
        this->values = new T[size_of_values];
        // Copy values from input matrix to new matrix
        std::copy(other.values, other.values + size_of_values, this->values);
    }
    else
    {
        // Allocate new memory for values
        this->values = new T[size_of_values];
        // Copy values from input matrix to new matrix
        std::copy(other.values, other.values + size_of_values, this->values);
    }
    /*
    Note: To make a deep copy of the input matrix, we need to allocate new memory for the values array of the new matrix, 
    instead of just copying the pointer to the values array from the input matrix. 
    This ensures that any changes to the input matrix after the copy is made do not affect the new matrix.
    */
}


// Perform matrix-vector multiplication assuming row major order
template <class T>
void Matrix<T>::matVecMult_rowmajor(double* input, double* output)
{
    for (int i = 0; i < this->rows; i++)
    {
        output[i] = 0;
        for (int j = 0; j < this->cols; j++)
        {
            output[i] += this->values[i * this->cols + j] * input[j];
        }
    }
}

// Perform matrix-vector multiplication assuming column major order
template <class T>
void Matrix<T>::matVecMult_colmajor(double* input, double* output)
{
    for (int j = 0; j < this->cols; j++)
    {
        for (int i = 0; i < this->rows; i++)
        {
            output[i] += this->values[j * this->rows + i] * input[j];
        }
    }
}



// Just print out the values in our values array
template <class T>
void Matrix<T>::printValues()
{
    std::cout << "Printing values" << std::endl;
    for (int i = 0; i < this->size_of_values; i++)
    {
        std::cout << this->values[i] << " ";
    }
    std::cout << std::endl;
}

// Explicitly print out the values in values array as if they are a matrix
template <class T>
void Matrix<T>::printMatrix()
{
    std::cout << "Printing matrix" << std::endl;
    for (int j = 0; j < this->rows; j++)
    {
        std::cout << std::endl;
        for (int i = 0; i < this->cols; i++)
        {
            // There is an explicit major ordering assumption here
            std::cout << this->values[i + j * this->cols] << " ";
        }
    }
    std::cout << std::endl;
}

// Do matrix matrix multiplication
// There is an explicit major ordering assumption in this function
// output = mat_left * this
template <class T>
void Matrix<T>::matMatMult(Matrix& mat_left, Matrix& output)
{

    // Check our dimensions match
    if (this->cols != output.cols)
    {
        std::cerr << "Input dimensions for matrices don't match" << std::endl;
        return;
    }

    // Check if our output matrix has had space allocated to it
    if (output.values != nullptr)
    {
        // Check our dimensions match
        if (this->rows != mat_left.cols || mat_left.rows != output.rows)
        {
            std::cerr << "Input dimensions for matrices don't match" << std::endl;
            return;
        }
    }
    // The output hasn't been preallocated, so we are going to do that
    else
    {
        output.values = new T[this->rows * mat_left.cols];
        // Don't forget to set preallocate to true now it is protected
        output.preallocated = true;
    }

    // Set values to zero before hand
    for (int i = 0; i < output.size_of_values; i++)
    {
        output.values[i] = 0;
    }

    // Now we can do our matrix-matrix multiplication
    // CHANGE THIS FOR LOOP ORDERING AROUND
    // AND CHECK THE TIME SPENT
    // Does the ordering matter for performance. Why??
    for (int i = 0; i < this->rows; i++)
    {
        for (int k = 0; k < this->cols; k++)
        {
            for (int j = 0; j < mat_left.cols; j++)
            {
                output.values[i * output.cols + j] += this->values[i * this->cols + k] * mat_left.values[k * mat_left.cols + j];
            }
        }
    }
}

