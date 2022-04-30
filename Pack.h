/*
    ==================================================
    Containers and Packs
    ==================================================
*/

#ifndef SDDS_PACK_H 
#define SDDS_PACK_H

#include "Container.h"

namespace sdds 
{
    class Pack : public Container 
    {
        int m_size;
        int m_unitSize;
        int m_numOfUnits;

    public:
        Pack();
        Pack(const char content[51], int size, int unitSize = 330, int numOfUnits = 0);
        int operator+=(int value);
        int operator-=(int value);
        int unit();
        int noOfUnits();
        int size();
        void clear(int size, int unitSize, const char content[51]);
        std::ostream& print(std::ostream& ostr) const;
        std::istream& read(std::istream& istr);
    };

    std::istream& operator>>(std::istream& istr, Pack& P);
    std::ostream& operator<<(std::ostream& ostr, const Pack& P);

}

#endif
