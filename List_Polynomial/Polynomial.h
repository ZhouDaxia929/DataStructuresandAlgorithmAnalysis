//
// Created by ggggg on 2017/3/10.
//

#ifndef C_TEST_POLYNOMIAL_H
#define C_TEST_POLYNOMIAL_H
#define MaxDegree 100

typedef struct {
    int CoeffArray[MaxDegree + 1];
    int HighPower;
} *Polynomial;

void ZeroPolynomial(Polynomial Poly);
void AddPolynomial(const Polynomial Poly1, const Polynomial Poly2, Polynomial PolySum);
void MultPolynomial(const Polynomial Poly1, const Polynomial Poly2, Polynomial PolyProd);
int Max(int a, int b);

#endif //C_TEST_POLYNOMIAL_H
