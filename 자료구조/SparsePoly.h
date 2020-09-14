#include <stdio.h>
#include "algorithm"

struct Term
{
    int expon;
    float coeff;
};

class SparsePoly
{

private:
    int max_terms;
    int nTerms;
    Term *term;

public:
    SparsePoly(){};

    void read()
    {
        printf("몇개 ?");
        scanf("%d", &nTerms);

        term = new Term[nTerms];

        for (int i = 0; i < nTerms; i++)
        {
            printf("coeff[%d]: ", i);
            scanf("%f", &term[i].coeff);
        }
        for (int i = 0; i < nTerms; i++)
        {
            printf("coeff[%d]: ", i);
            scanf("%d", &term[i].expon);
        }
    }

    void display()
    {
        for (int i = 0; i < nTerms; i++)
        {
            if (term[i].coeff != 0 && term[i].expon != 0)
            {
                printf("%5.1f x^%d + ", term[i].coeff, term[i].expon);
            }
            else if (term[i].expon == 0 && term[i].coeff != 0)
            {
                printf("%4.1f\n", term[i].coeff);
            }
        }
    }

    void add(SparsePoly a, SparsePoly b)
    {

        nTerms = a.nTerms + b.nTerms;
        int cIndex = 0;
        term = new Term[nTerms];
        Term *tmpTerm = new Term[nTerms];
        //Sub
        for (int i = 0; i < a.nTerms; i++)
        {
            term[cIndex] = a.term[i];
            cIndex++;
        }
        for (int i = 0; i < b.nTerms; i++)
        {
            term[cIndex] = b.term[i];
            cIndex++;
        }

        //Sort
        for (int i = 0; i < nTerms; i++)
        {
            for (int j = i + 1; j < nTerms; j++)
            {
                if (term[i].expon < term[j].expon)
                {
                    tmpTerm[i] = term[j];
                    term[j] = term[i];
                    term[i] = tmpTerm[i];
                }
            }
        }

        //Merge
        for (int i = 0; i < nTerms; i++)
        {
            for (int j = i + 1; j < nTerms; j++)
            {
                if (term[i].expon == term[j].expon)
                {
                    term[i].coeff += term[j].coeff;
                    term[j].coeff = term[j].expon = 0;
                }
            }
        }
        
        //Sort
        for (int i = 0; i < nTerms; i++)
        {
            for (int j = i + 1; j < nTerms; j++)
            {
                if (term[i].expon < term[j].expon)
                {
                    tmpTerm[i] = term[j];
                    term[j] = term[i];
                    term[i] = tmpTerm[i];
                }
            }
        }
    }

    void print()
    {
        printf("\n");
        printf("coeff ");
        for (int j = 0; j < nTerms; j++)
        {
            term[j].coeff == 0 ? printf("[_____]") : printf("[%5.1f]", term[j].coeff);
        }
        printf("\n");
        printf("expon ");
        for (int j = 0; j < nTerms; j++)
        {
            term[j].expon == 0 ? printf("[_____]") : printf("[%5d]", term[j].expon);
        }
        printf("\n");
    }

    bool isZero(float num)
    {
        if (num == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};