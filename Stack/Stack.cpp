#include <iostream>
#define size 5
int stk[size];
class Stack {
	int top;
public:
	Stack() {
		top = -1;
	}

	void Push(int);

	int Pop();
	
	int Peek();
};

/// <summary>
/// Summart for Push Function
/// </summary>
/// <param name="data"></param>
void Stack::Push(int data){
	if (top == size) {
		std::cout << "The Stack is Full" << std::endl;
		return;
	}

	top = top + 1;
	stk[top] = data;
}

/// <summary>
/// Function for Pop Function
/// </summary>
/// <returns></returns>
int Stack::Pop() {
	if (top == -1) {
		std::cout << "Stack is Empty" << std::endl;
		return -1;
	}

	return stk[top--];
}

/// <summary>
/// Function for Peek function
/// </summary>
/// <returns></returns>
int Stack::Peek() {
	if (top == -1) {
		return -1;
	}
	return stk[top];
}

/// <summary>
/// Driver Code Starts from Here
/// </summary>
/// <returns></returns>
int main()
{
   
	int choice = 0;
	Stack stk;
	do
	{
		std::cout << "Enter the choice" << std::endl;
		std::cout << "1. Push" << std::endl;
		std::cout << "2. Pop" << std::endl;
		std::cout << "3. Peek" << std::endl;
		std::cout << "Enter the choice you want to perform" << std::endl;
		std::cin >> choice;
		int data;
		switch (choice)
		{
		case 1:
			std::cout << "Enter the data you want to enter in Stack" << std::endl;
			std::cin >> data;
			stk.Push(data);
			break;
		case 2:
			data = stk.Pop();
			std::cout << "The Data popped out is " << data << std::endl;
			break;
		case 3:
			std::cout << "The Peek data is " << stk.Peek() << std::endl;
			break;
		default:
			break;
		}

	} while (choice != 0);
}

