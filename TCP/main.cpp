#include"test.h"
#include<cstdlib>
void usage(char* command)
{
    cout << "Usage: " << command << " port";
}
int main(int argc,char *argv[])
{
      if(argc<2){
      usage(argv[1]);
            return 1;
      }

   TCP tcp(atoi(argv[1]));
     tcp.init();
    tcp.start();

     
}
