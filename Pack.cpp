/*
    ==================================================
    Containers and Packs
    ==================================================
    Name   : Nozhin Azarpanah
    Date   : March 17, 2022
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include "cstring"
#include "Pack.h"

using namespace std;

namespace sdds
{

    Pack::Pack() 
    {
        m_unitSize = 330;
        m_numOfUnits = 0;
    }

    Pack::Pack(const char content[51], int size, int unitSize, int numOfUnits):Container(content, size * unitSize, numOfUnits * unitSize) 
    {
        if (unitSize > 0) 
        {
            m_size = size;
            m_unitSize = unitSize;
            m_numOfUnits = numOfUnits;
        }
        else
        {
            setEmpty();
        }
    }

    int Pack::operator+=(int value) 
    {
        int res = Container::operator+=((value * m_unitSize)); 
        m_numOfUnits += res / m_unitSize;
        return ((res / m_unitSize));
    }

    int Pack::operator-=(int value) 
    {
        int res = Container::operator-=((value * m_unitSize));
        m_numOfUnits -= res / m_unitSize;
        return ((res / m_unitSize));
    }

    int Pack::unit() 
    {
        return m_unitSize;
    }

    int Pack::noOfUnits()
    {
        int contvol = volume();
        int res = contvol / m_unitSize;
        return res;
    }

    int Pack::size() 
    {
        int cap = capacity();
        int res = cap / m_unitSize;
        return res;
    }

    void Pack::clear(int size, int unitSize, const char content[51])
    {
        if (unitSize > 0) 
        {
            Container::clear(size * unitSize , content);
            m_numOfUnits = Container::volume() / unitSize;
            m_unitSize = unitSize;
            m_size = size;
        }
    }

    ostream& Pack::print(ostream& ostr) const
    {
        Container::print(ostr);
        ostr << ", " << m_numOfUnits << " in a pack of " << m_size;
        return ostr;
    }

    istream& Pack::read(istream& istr) 
    {
        if (!isValid()) 
        {
            cout << "Broken Container, adding aborted! Press <ENTER> to continue....";
            istr.ignore();
        }
        else 
        {
            if (m_numOfUnits < m_size) 
            {
                if (m_unitSize > 0)
                {
                    cout << "Add to ";
                    print(cout);
                    cout << endl << "> ";
                    int value;
                    int flag = 0;
                    do
                    {
                        istr >> value;
                        if (cin.get() != '\n') 
                        {
                            cout << "Invalid Integer, retry: ";
                            cin.clear();
                            while (cin.get() != '\n');
                        }
                        else if (value > m_size - m_numOfUnits || value < 1) 
                        {
                            cout << "Value out of range [1<=val<=" << m_size - m_numOfUnits << "]: ";
                            cin.clear();
                        }
                        else 
                        {
                            flag = 1;
                        }
                    } while (flag == 0);

                    operator+=(value);
                    cout << "Added " << value << endl;       
                }
            }
            else 
            {
                cout << "Pack is full!, press <ENTER> to continue...";
                cin.ignore();
            }
        }
        return istr;
    }

    istream& operator>>(istream& istr, Pack& P)
    {
        return P.read(istr);
    }

    ostream& operator<<(ostream& ostr, const Pack& P)
    {
        P.print(ostr);
        return ostr;
    }
}