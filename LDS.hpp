//
// Created by djalma cunha on 25/09/18.
//

#ifndef HOTEL_LDS_HPP
#define HOTEL_LDS_HPP

class LDS {
    int n;
    int max;
    int *v;

    LDS(int max = 10) : n(0), max(max),
                        v(new int[max]) {

    }

    /*
     * serve como um free para devolver a memoria
     */
    virtual ~LDS() {
        delete[] v;
    }
};


#endif //HOTEL_LDS_HPP
