#pragma once
#include <iostream>

using namespace std;
int roll_dice(int N);
void makeAlternatingCase(string& str);
void generateFibonacciSequence();

class MagicNumber {
public:
    MagicNumber(int num) : m_num(num) {}

    int getInt() const {
        return m_num;
    }

    // Special plus one operator postfix ++
    MagicNumber operator++(int) {
        MagicNumber old(*this);
        m_num += 6;
        return old;
    }

    // Special plus one operator prefix ++
    MagicNumber& operator++() {
        m_num += 4;
        return *this;
    }

private:
    int m_num;
};