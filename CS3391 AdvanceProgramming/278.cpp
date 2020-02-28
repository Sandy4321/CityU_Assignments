#include <stdio.h>

int main(){

	int T,N,S;
	int* stud;
	int passed;
	double A;

	scanf("%i",&T);

	while(T--){


		scanf("%i",&N);
		
		stud = new int[N];
		passed = 0;
		A = 0;


		for (int i = 0; i < N ; i++)
		{

			scanf("%i",&S);
			A += S;
			stud[i] = S;

		}


		A /= N;


		for ( int i = 0 ; i < N ; i ++ ){


			if ( stud[i] > A ) {
				passed ++;	
			}


		}

		printf("%0.3f%%\n",(double)passed/N*100);


	}

	return 0;
}

/*

*/
