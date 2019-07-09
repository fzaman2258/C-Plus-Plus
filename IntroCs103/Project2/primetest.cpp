/*
 * CSc103 Project 2: prime numbers.
 * See readme.html for details.
 * Please list all references you made use of in order to complete the
 * assignment: your classmates, websites, etc.  Aside from the lecture notes
 * and the book, please list everything.  And remember- citing a source does
 * NOT mean it is okay to COPY THAT SOURCE.  What you submit here **MUST BE
 * YOUR OWN WORK**.
 * References:
 *www.tutorialspoint.com/cplusplus/cpp_break_statement.htm
 www.geeksforgeeks.org/bool-data-type-in-c/-in
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
 int input;
 bool printed=false;
 while (cin>>input)
 {
 if(input<2){
  cout<<"0 \n";
 }
 else if(input==2)
 {
  cout<<"1 \n";
 }
 else if (input>2 && input%2==0) {
 cout<<"0 \n";
}
else {
 printed=false;
for(int x=input-2; x>=2; x-=2 ){
if ( input%x==0){
 cout<<"0 \n";
 printed=true;
 break;
}
}
if (printed==false)
{
cout<<"1 \n";

}
}
}


	return 0;
}

















