#include<iostream>
#include<limits>

using namespace std;

class MyException
{
    public:
    MyException(const char* errorMsg, const char* fileName, 
    const char* funcName, int lineNum) 
    : error(errorMsg), file_name(fileName), func_name(funcName), line(lineNum)
    {}
    ~MyException(){}

    void displayException()
    {
        std::cout<<"Invalid <"<<error<<">\nError in "<<file_name<<"'s "
                 <<func_name<<"() function on line "<<line<<"."<<std::endl;
    }

    protected:
    //Member variables for displaying error
    const char* error;      
    const char* file_name;  
    const char* func_name;
    int line;
};

//Function Prototype
int factorial(int);

int main()
{
    std::cout<<"\t\t+--------------------+\n"
             <<"\t\t|Factorial Calculator|\n"
             <<"\t\t+--------------------+\n"<<std::endl;

    int num;
    while (true) {
        std::cout << "Enter a number: ";
        std::cin >> num;

        if (std::cin.fail()) {
            // Clear the fail bit and discard the invalid input
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter an integer.\n";
        }
        else {
            break;
        }
    }

    try
    {
        std::cout<<"Factorial of "<< num <<" is "<< factorial(num);
    }
    catch(MyException& error){
        error.displayException();
    }
    catch(...){
        std::cout<<"Error."<<std::endl;
    }

    return 0;
}

//Function Declaration
int factorial(int n){
    if (n < 0){
        // Throws error if argument is negative
        throw MyException("Factorial argument cannot be negative",__FILE__,
                          __func__,__LINE__);
    }
    else if (n > 12){
        // Throws error if argument exceeds int data type range
        throw MyException("Input value too large for calculation. (Try 1-12)"
                        ,__FILE__, __func__, __LINE__);
    }

    int ans = 1;
    while (n > 0){
        ans *= n;
        n--;
    }
    return ans;
}