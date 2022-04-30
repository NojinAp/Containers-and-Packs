/*
    ==================================================
    Containers and Packs
    ==================================================
*/

#ifndef SDDS_CONTAINER_H 
#define SDDS_CONTAINER_H

namespace sdds 
{
    class Container 
    {
        char m_content[51];
        int m_capacity;
        int m_content_vol;

    protected:
        void setEmpty();
        int capacity();
        int volume();

    public:
        Container();
        Container(const char Content[51], int Capacity, int Content_vol);
        Container(const char Content[51], int Capacity);
        int operator+=(int value);
        int operator-=(int value);
        bool isValid();
        operator bool() const;
        void clear(int Capacity, const char Content[51]);
        std::ostream& print(std::ostream& ostr) const;
        std::istream& read(std::istream& istr);

    };

    std::istream& operator>>(std::istream& istr, Container& C);
    std::ostream& operator<<(std::ostream& ostr, const Container& C);
}

#endif
