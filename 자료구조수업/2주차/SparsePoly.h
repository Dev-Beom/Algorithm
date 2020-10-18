#include <stdio.h>
#define MAX_TERMS	80

struct Term {				// 하나의 항을 표현하는  클래스
	int		expon;			// 항의 지수
	float	coeff;			// 항의 계수
};

class SparsePoly {			// 희소 다항식 클래스
	int	nTerms;				// 계수가 0이 아닌 항의 개수
	Term term[MAX_TERMS];	// 계수가 0이 아닌 항의 배열

public:
	void read() {
		nTerms = 0;
		while (1) {
			printf("계수 차수 입력(종료:-1): ");
			scanf("%f%d", &(term[nTerms].coeff), &(term[nTerms].expon));
			if (term[nTerms].expon < 0) {
				display("입력 다항식:");
				return;
			}
			nTerms++;
		}
	}
	void add(SparsePoly a, SparsePoly b) {
		int i, j;

		nTerms = 0;
		for (i = j = 0; i<a.nTerms || j<b.nTerms;) {
			if (i == a.nTerms || a.term[i].expon < b.term[j].expon)
				term[nTerms++] = b.term[j++];
			else if (j == b.nTerms || a.term[i].expon > b.term[j].expon)
				term[nTerms++] = a.term[i++];
			else {
				term[nTerms] = a.term[i++];
				term[nTerms++].coeff += b.term[j++].coeff;
			}
		}
	}
	void display(char *str = "SPoly") {
		int i;
		printf("\t%s", str);
		for (i = 0; i < nTerms; i++) {
			printf("%5.1f", term[i].coeff);
			if (term[i].expon > 0)
				printf(" x^%d + ", term[i].expon);
		}
		printf("\n");
	}
} ;

