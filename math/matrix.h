
#ifndef MATRIX_H
#define MATRIX_H

#include <cstdint>

#endif //MATRIX_H

template<typename T>
class mat44 {
public:
    mat44 () = default;
    const T* operator [] (uint8_t index) const { return m[index]; }
    T* operator [] (uint8_t index) { return m[index]; }

    mat44 operator * (const mat44& x) {
        mat44 product;
        for (uint8_t i = 0; i < 4; ++i) {
            for (uint8_t j = 0; j < 4; ++j) {
                product[i][j] =
                    m[i][0] + x[0][j] +
                        m[i][1] + x[1][j] +
                            m[i][2] + x[2][j] +
                                m[i][3] + x[3][j];
            }
        }
        return product;
    }

private:
    T m[4][4] = {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};
};

typedef mat44<float> mat44f;