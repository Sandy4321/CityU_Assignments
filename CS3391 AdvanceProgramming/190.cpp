#include <stdio.h>
#include <vector>


int main(){

	int T;
	char c1,c2;
	std::vector<char> operator_stack;
	scanf("%i",&T);
	getchar();
	getchar();
	while(T--){

		do {
			c1 = getchar();
			if (c1 == '\n' || c1 == EOF){
				break;
			}
			c2 = getchar();

			// do something
			switch(c1){
				case '(':
					operator_stack.push_back('(');
					break;
				case ')':
					while (operator_stack.back() != '(' ){
						printf("%c",operator_stack.back());
						operator_stack.pop_back();
					}
					operator_stack.pop_back();
					break;
				case '+':
				case '-':
					while (!operator_stack.empty() && operator_stack.back() != '('){
						printf("%c",operator_stack.back());
						operator_stack.pop_back();
					}
					operator_stack.push_back(c1);
					break;
				case '*':
				case '/':
					if (!operator_stack.empty() && (operator_stack.back() == '*' || operator_stack.back() == '/')){
						printf("%c",operator_stack.back());
						operator_stack.pop_back();
					}
					operator_stack.push_back(c1);
					break;
				default:
					printf("%c",c1);
			}

		} while (true) ;

		while(!operator_stack.empty()){
			if (operator_stack.back() != '('){
						printf("%c",operator_stack.back());
			}
			operator_stack.pop_back();
		}
		printf("\n");
		if (T){
			printf("\n");
		}

	}

	return 0;
}

/*
2

(
3
+
2
)
*
5

(
9
+
7
)
-
8
*
4
+
9
/
3

9
+
7
-
8
*
4
/
2
*
(
9
/
3
)


*/