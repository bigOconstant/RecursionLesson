# Recursion 101

A Lesson in practical recursion

## What is it?

Recursion is a function/method that calls itself to create a loop. Thats it. It's a loop created with a function calling itself and you must put in some condition to exit the loop or it will call itself forever. (**Infinite Loop**)

A recursive function usually starts with what is known as a **base case**. This is the condition where the function finishes. There is no law stating that it must start with the base case but for learning purposes it's good to always start your recursive function with the **base case**. It makes you start to think about how to exit. To compare it with a for loop, the **base case** is the condition **i** needs to exit the for loop.

## Example.

Take for example a loop to print out the values of a C++ vector.

```cpp

std::vector<int> testcase = {1,2,3,4,5}

for(int i = 0; i < testcase.size(); ++i){
    std::cout<<testcase[i]<<std::endl;
}
```

We can stick this into a function to generalize it.

```cpp
#include <iostream>
#include <vector>
void printVector(std::vector<int> input){
    for(int i = 0; i < input.size(); ++ i) {
        std::cout<<input[i]<<std::endl;
    }
}

int main(){
    std::vector<int> testcase = {1,2,3,4,5};
    printVector(testcase);

    return 0;
}


```

Output will be,

```
1
2
3
4
4
```

We can also loop through the vector with a recursive function.

```cpp

#include <iostream>
#include <vector>

void printVector(std::vector<int> input) {
    // Create a base case
    if(input.size() < 1){ // If vector is empty exit function
        return;
    }else{
        std::cout<<input.back()<<std::endl;// Print last element of vector
        input.pop_back();// Remove last element from vector. pop_back removes last element of vector
        /*The recursive call is next */
        printVector(input);// Call the function within itself and pass it a vector with one less element
    }

}

int main(){
    std::vector<int> testcase = {1,2,3,4,5};
    printVector(testcase);

    return 0;
}
```

output will be

```
5
4
3
2
1
```

It's backwards but that is ok for this example.

## Why?

You might be thinking, wtf why would I not just use a for loop? This seems overly complicated to make a loop.

And the reason is, some things end up much easier with recursion. A common example is sorting algorithms. But that is a complicated topic. Lets talk about how we can use it with what you are studying now. **Linked List**

```cpp

struct Node {
    int value;
    Node *next;
}

```

We can use recursion to build and print linked list really really easy.


```cpp
#include <iostream>

struct Node {
    std::string value;
    Node *next;

    //Add a function to the object
    Node(std::string key){
        this->value = key;
        next = NULL;
    }
    /*
    Recursive function insert:
        insert checks to see if the next point is NULL, if so it inserts the value into next.
        If it is not null then it calles the next insert function passing the value down the chain.

        This way , it loops all the way to the end of the list placing the value at the end with a new node.
    */
    void insert(std::string key){
        if(this->next == NULL) {
            this->next = new Node(key);
            return; // Exit
        }else{
            this->next->insert(key);// Push the value down the list
        }
    }
};

int main(){
    Node *root = new Node("first");

    root->insert("second");
    root->insert("third");


    // Print out each value
    std::cout<<root->value<<std::endl;
    std::cout<<root->next->value<<std::endl;
    std::cout<<root->next->next->value<<std::endl;

    return 0;
}

```

## Practice

Write a recursive function to print out the three values starting with the root function.

Hint: the base case should be `if (node == NULL)` and the recursive call should be `functionname(node->next)`
