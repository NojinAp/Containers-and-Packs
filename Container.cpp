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
#include "Container.h"

using namespace std;

namespace sdds 
{

    Container::Container()
    {
        setEmpty();
    }

    void Container::setEmpty()
    {
        m_content[0] = 0;
        m_content_vol = 0;
        m_capacity = 0;
    }

    Container::Container(const char Content[51], int Capacity, int Content_vol)
    {
        setEmpty();

        if (Content != nullptr && Content_vol <= Capacity) 
        {
            m_capacity = Capacity;
            m_content_vol = Content_vol;
            strcpy(m_content, Content);
        }
    }

    Container::Container(const char Content[51], int Capacity) 
    {
        setEmpty();
        if (Content != nullptr)
        {
            m_capacity = Capacity;
            strcpy(m_content, Content);
        }
    }

    int Container::capacity() 
    {
        return m_capacity;
    }

    int Container::volume() 
    {
        return m_content_vol;
    }

    int Container::operator+=(int value)
    {
        if (m_content_vol + value <= m_capacity) 
        {
            m_content_vol += value;
        }
        else if (m_content_vol + value > m_capacity) 
        {
            value = m_capacity - m_content_vol;
            m_content_vol = m_capacity;
        }
        return value;
    }

    int Container::operator-=(int value) 
    {
        if (m_content_vol - value >= 0) 
        {
            m_content_vol -= value;
        }
        else if (m_content_vol - value < 0) 
        {
            value = m_content_vol;
            m_content_vol = 0;
        }
        return value;
    }

    bool Container::isValid() 
    {
        if (m_content[0] != 0 && m_content_vol <= m_capacity) 
        {
            return true;
        }
        return false;
    }

    Container::operator bool() const 
    {
        if (m_content[0] != 0 && m_content_vol <= m_capacity)
        {
            return true;
        }
        return false;
    }

    void Container::clear(int Capacity, const char Content[51])
    {
        if (Capacity > 0 && Content[0] != 0)
        {
            m_capacity = Capacity;
            strcpy(m_content, Content);
        }
    }

    ostream& Container::print(ostream& ostr) const
    {
        ostr << m_content << ": (" << m_content_vol << "cc/" << m_capacity << ")";
        return ostr;
    }

    istream& Container::read(istream& istr)
    {
        if (m_content[0] == 0 || m_content_vol > m_capacity)
        {
            cout << "Broken Container, adding aborted! Press <ENTER> to continue....";
            istr.ignore();
        }
        else 
        {
            cout << "Add to " << m_content << ": (" << m_content_vol << "cc/" << m_capacity << ")" << endl;
            cout << "> ";

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
                else if (value > 220000 || value < 1) 
                {
                    cout << "Value out of range [1<=val<=" << m_capacity - m_content_vol << "]: ";
                    cin.clear();
                }
                else 
                {
                    flag = 1;
                }
            } while (flag == 0);

            if (m_content_vol + value <= m_capacity) 
            {
                m_content_vol += value;
            }
            else if (m_content_vol + value > m_capacity) 
            { 
                if (value > m_capacity) 
                {
                    value = m_capacity;
                }
                else if (value < m_capacity) 
                {
                    value = m_capacity - m_content_vol;
                }

                m_content_vol = m_capacity;
            }
            cout << "Added " << value << " CCs" << endl;
        }
        return istr;
    }

    istream& operator>>(istream& istr, Container& C)
    {
        return C.read(istr);
    }

    ostream& operator<<(ostream& ostr, const Container& C)
    {
        if (C) 
        {
            C.print(ostr);
        }
        else 
        {
            ostr << "****: (**cc/***)";
        }

        return ostr;
    }
}