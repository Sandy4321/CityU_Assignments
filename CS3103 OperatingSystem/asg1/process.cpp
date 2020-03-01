#include <iostream>
class Process{
	public:
		Process(){
			if (!pidKeeper){
				pidKeeper = 0;
			}
			pid = pidKeeper++;
		}
		~Process(){

		}
	private:
		static int pidKeeper;
		int pid;
};
int main(){
	return 0;
}