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
    // int max_terms;

    int length;
    Term *term;

public:
    SparsePoly(){};

    void read()
    {
        printf("몇개 ?");
        scanf("%d", &length);

        term = new Term[length];

        for (int i = 0; i < length; i++)
        {
            printf("coeff[%d]: ", i);
            scanf("%f", &term[i].coeff);
        }
        for (int i = 0; i < length; i++)
        {
            printf("coeff[%d]: ", i);
            scanf("%d", &term[i].expon);
        }
    }

    void display()
    {
        for (int i = 0; i < length; i++)
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

        length = a.length + b.length;

        int index = 0; // index

        term = new Term[length];
        Term *tmpTerm = new Term[length];   //Tmp 구조

        //Sub
        for (int i = 0; i < a.length; i++)
        {
            term[index] = a.term[i];
            index++;
        }
        for (int i = 0; i < b.length; i++)
        {
            term[index] = b.term[i];
            index++;
        }

        //Sort
        for (int i = 0; i < length; i++)
        {
            for (int j = i + 1; j < length; j++)
            {
                if (term[i].expon < term[j].expon)
                {
                    tmpTerm[i] = term[j];
                    term[j] = term[i];
                    term[i] = tmpTerm[i];
                }
            }
        }

        print();
        //Merge
        for (int i = 0; i < length; i++)
        {
            for (int j = i + 1; j < length; j++)
            {
                if (term[i].expon == term[j].expon)
                {
                    term[i].coeff += term[j].coeff;
                    term[j].coeff = term[j].expon = 0;
                }
            }
        }
        print();
        //Sort
        for (int i = 0; i < length; i++)
        {
            for (int j = i + 1; j < length; j++)
            {
                if (term[i].expon < term[j].expon)
                {
                    tmpTerm[i] = term[j];
                    term[j] = term[i];
                    term[i] = tmpTerm[i];
                }
            }
        }
        delete tmpTerm;
    }

    void print()
    {
        printf("\n");
        printf("coeff ");
        for (int j = 0; j < length; j++)
        {
            term[j].coeff == 0 ? printf("[_____]") : printf("[%5.1f]", term[j].coeff);
        }
        printf("\n");
        printf("expon ");
        for (int j = 0; j < length; j++)
        {
            term[j].expon == 0 ? printf("[_____]") : printf("[%5d]", term[j].expon);
        }
        printf("\n");
    }
};