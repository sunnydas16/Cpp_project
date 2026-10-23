#include <iostream>
#include <string>
using namespace std;

#define MAX_SIZE 5

// STACK TEMPLATE 
template <class Type>
class Stack
{
    Type stack[MAX_SIZE];
    int top;

public:

    Stack()
    {
        top = -1;
    }

    // PUSH
    void push(Type value)
    {
        if(top == MAX_SIZE - 1)
        {
            cout << "Stack Overflow." << endl;
        }
        else
        {
            top++;
            stack[top] = value;
            cout << "Element pushed successfully." << endl;
        }
    }

    // POP
    void pop()
    {
        if(top == -1)
        {
            cout << "Stack Underflow." << endl;
        }
        else
        {
            cout << "Deleted element: " << stack[top] << endl;
            top--;
        }
    }

    // DISPLAY
    void display()
    {
        if(top == -1)
        {
            cout << "Stack is Empty." << endl;
        }
        else
        {
            cout << "Stack elements (TOP to bottom):" << endl;
            for(int i = top; i >= 0; i--)
            {
                cout << stack[i] << endl;
            }
        }
    }
};


// MAIN 
int main()
{
    // Five Stack objects
    Stack<int> intStack;
    Stack<char> charStack;
    Stack<float> floatStack;
    Stack<double> doubleStack;
    Stack<string> stringStack;

    // To check whether stack was opened before
    bool intCreated = false;
    bool charCreated = false;
    bool floatCreated = false;
    bool doubleCreated = false;
    bool stringCreated = false;

    int choice;
    int invalidCount = 0;

    // MAIN MENU 

    while(1)
    {
        cout << "\n\n========== MAIN MENU ==========" << endl;
        cout << "1. Integer Stack" << endl;
        cout << "2. Character Stack" << endl;
        cout << "3. Float Stack" << endl;
        cout << "4. Double Stack" << endl;
        cout << "5. String Stack" << endl;
        cout << "6. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;


        //  EXIT 
        if(choice == 6)
        {
            cout << "Program terminated." << endl;
            break;
        }


        //  INVALID MAIN MENU 
        if(choice < 1 || choice > 6)
        {
            invalidCount++;

            cout << "Invalid choice. Please enter a valid option." << endl;

            if(invalidCount == 3)
            {
                cout << "Maximum invalid attempts reached." << endl;
                cout << "Program terminated." << endl;
                break;
            }

            continue;
        }

        // Valid choice -> reset counter
        invalidCount = 0;

       //                INTEGER STACK
     
        if(choice == 1)
        {
            // Old/New stack
            if(intCreated == true)
            {
                int oldChoice;

                cout << "\n1. Continue with old stack" << endl;
                cout << "2. Create new stack" << endl;
                cout << "Enter your choice: ";
                cin >> oldChoice;

                if(oldChoice == 2)
                {
                    intStack = Stack<int>();
                    cout << "New integer stack created." << endl;
                }
            }

            intCreated = true;

            int stackChoice;
            int value;
            int stackInvalid = 0;

            while(1)
            {
                cout << "\n===== INTEGER STACK =====" << endl;
                cout << "1. Push" << endl;
                cout << "2. Pop" << endl;
                cout << "3. Display Stack" << endl;
                cout << "4. Main Menu" << endl;

                cout << "Enter your choice: ";
                cin >> stackChoice;

                if(stackChoice == 1)
                {
                    cout << "Enter integer: ";
                    cin >> value;

                    intStack.push(value);
                    stackInvalid = 0;
                }
                else if(stackChoice == 2)
                {
                    intStack.pop();
                    stackInvalid = 0;
                }
                else if(stackChoice == 3)
                {
                    intStack.display();
                    stackInvalid = 0;
                }
                else if(stackChoice == 4)
                {
                    break;
                }
                else
                {
                    stackInvalid++;

                    cout << "Invalid choice. Please enter a valid option." << endl;

                    if(stackInvalid == 3)
                    {
                        cout << "Maximum invalid attempts reached." << endl;
                        cout << "Program terminated." << endl;
                        return 0;
                    }
                }
            }
        }


        //                CHARACTER STACK
                else if(choice == 2)
        {
            if(charCreated == true)
            {
                int oldChoice;

                cout << "\n1. Continue with old stack" << endl;
                cout << "2. Create new stack" << endl;
                cout << "Enter your choice: ";
                cin >> oldChoice;

                if(oldChoice == 2)
                {
                    charStack = Stack<char>();
                    cout << "New character stack created." << endl;
                }
            }

            charCreated = true;

            int stackChoice;
            char value;
            int stackInvalid = 0;

            while(1)
            {
                cout << "\n===== CHARACTER STACK =====" << endl;
                cout << "1. Push" << endl;
                cout << "2. Pop" << endl;
                cout << "3. Display Stack" << endl;
                cout << "4. Main Menu" << endl;

                cout << "Enter your choice: ";
                cin >> stackChoice;

                if(stackChoice == 1)
                {
                    cout << "Enter character: ";
                    cin >> value;

                    charStack.push(value);
                    stackInvalid = 0;
                }
                else if(stackChoice == 2)
                {
                    charStack.pop();
                    stackInvalid = 0;
                }
                else if(stackChoice == 3)
                {
                    charStack.display();
                    stackInvalid = 0;
                }
                else if(stackChoice == 4)
                {
                    break;
                }
                else
                {
                    stackInvalid++;

                    cout << "Invalid choice. Please enter a valid option." << endl;

                    if(stackInvalid == 3)
                    {
                        cout << "Maximum invalid attempts reached." << endl;
                        cout << "Program terminated." << endl;
                        return 0;
                    }
                }
            }
        }


        //                  FLOAT STACK
        
        else if(choice == 3)
        {
            if(floatCreated == true)
            {
                int oldChoice;

                cout << "\n1. Continue with old stack" << endl;
                cout << "2. Create new stack" << endl;
                cout << "Enter your choice: ";
                cin >> oldChoice;

                if(oldChoice == 2)
                {
                    floatStack = Stack<float>();
                    cout << "New float stack created." << endl;
                }
            }

            floatCreated = true;

            int stackChoice;
            float value;
            int stackInvalid = 0;

            while(1)
            {
                cout << "\n===== FLOAT STACK =====" << endl;
                cout << "1. Push" << endl;
                cout << "2. Pop" << endl;
                cout << "3. Display Stack" << endl;
                cout << "4. Main Menu" << endl;

                cout << "Enter your choice: ";
                cin >> stackChoice;

                if(stackChoice == 1)
                {
                    cout << "Enter float value: ";
                    cin >> value;

                    floatStack.push(value);
                    stackInvalid = 0;
                }
                else if(stackChoice == 2)
                {
                    floatStack.pop();
                    stackInvalid = 0;
                }
                else if(stackChoice == 3)
                {
                    floatStack.display();
                    stackInvalid = 0;
                }
                else if(stackChoice == 4)
                {
                    break;
                }
                else
                {
                    stackInvalid++;

                    cout << "Invalid choice. Please enter a valid option." << endl;

                    if(stackInvalid == 3)
                    {
                        cout << "Maximum invalid attempts reached." << endl;
                        cout << "Program terminated." << endl;
                        return 0;
                    }
                }
            }
        }


        //                  DOUBLE STACK
        
        else if(choice == 4)
        {
            if(doubleCreated == true)
            {
                int oldChoice;

                cout << "\n1. Continue with old stack" << endl;
                cout << "2. Create new stack" << endl;
                cout << "Enter your choice: ";
                cin >> oldChoice;

                if(oldChoice == 2)
                {
                    doubleStack = Stack<double>();
                    cout << "New double stack created." << endl;
                }
            }

            doubleCreated = true;

            int stackChoice;
            double value;
            int stackInvalid = 0;

            while(1)
            {
                cout << "\n===== DOUBLE STACK =====" << endl;
                cout << "1. Push" << endl;
                cout << "2. Pop" << endl;
                cout << "3. Display Stack" << endl;
                cout << "4. Main Menu" << endl;

                cout << "Enter your choice: ";
                cin >> stackChoice;

                if(stackChoice == 1)
                {
                    cout << "Enter double value: ";
                    cin >> value;

                    doubleStack.push(value);
                    stackInvalid = 0;
                }
                else if(stackChoice == 2)
                {
                    doubleStack.pop();
                    stackInvalid = 0;
                }
                else if(stackChoice == 3)
                {
                    doubleStack.display();
                    stackInvalid = 0;
                }
                else if(stackChoice == 4)
                {
                    break;
                }
                else
                {
                    stackInvalid++;

                    cout << "Invalid choice. Please enter a valid option." << endl;

                    if(stackInvalid == 3)
                    {
                        cout << "Maximum invalid attempts reached." << endl;
                        cout << "Program terminated." << endl;
                        return 0;
                    }
                }
            }
        }


        //                  STRING STACk

        else if(choice == 5)
        {
            if(stringCreated == true)
            {
                int oldChoice;

                cout << "\n1. Continue with old stack" << endl;
                cout << "2. Create new stack" << endl;
                cout << "Enter your choice: ";
                cin >> oldChoice;

                if(oldChoice == 2)
                {
                    stringStack = Stack<string>();
                    cout << "New string stack created." << endl;
                }
            }

            stringCreated = true;

            int stackChoice;
            string value;
            int stackInvalid = 0;

            while(1)
            {
                cout << "\n===== STRING STACK =====" << endl;
                cout << "1. Push" << endl;
                cout << "2. Pop" << endl;
                cout << "3. Display Stack" << endl;
                cout << "4. Main Menu" << endl;

                cout << "Enter your choice: ";
                cin >> stackChoice;

                if(stackChoice == 1)
                {
                    cout << "Enter string: ";
                    cin >> value;

                    stringStack.push(value);
                    stackInvalid = 0;
                }
                else if(stackChoice == 2)
                {
                    stringStack.pop();
                    stackInvalid = 0;
                }
                else if(stackChoice == 3)
                {
                    stringStack.display();
                    stackInvalid = 0;
                }
                else if(stackChoice == 4)
                {
                    break;
                }
                else
                {
                    stackInvalid++;

                    cout << "Invalid choice. Please enter a valid option." << endl;

                    if(stackInvalid == 3)
                    {
                        cout << "Maximum invalid attempts reached." << endl;
                        cout << "Program terminated." << endl;
                        return 0;
                    }
                }
            }
        }
    }

    return 0;
}