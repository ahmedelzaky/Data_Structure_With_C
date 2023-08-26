# Data Structures in C

This project provides simple implementations of stack and queue data structures in C. These data structures are fundamental in computer science and can be used in various applications.

## Table of Contents

- [Features](#features)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Building](#building)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Features

- **Stack**:

  - Push and pop elements onto/from the stack.
  - Check if the stack is empty.
  - Get the size of the stack.
  - Automatic resizing when the stack is full or nearly empty.

- **Queue**:
  - Enqueue and dequeue elements from the queue.
  - Check if the queue is empty.
  - Get the front and last elements of the queue.
  - Automatic resizing when the queue is full.

## Getting Started

### Prerequisites

Before you can build and use this project, make sure you have the following installed:

- A C compiler (e.g., GCC)
- Make (optional, for building)

### Building

1. Clone the repository:

   ```bash
   git clone https://github.com/ahmedelzaky/Data_Structer_With_C.git
   ```

## Usage

To use the stack and queue data structures in your C program, follow these steps:

- Include the Data_Structer.h header file in your program:

```c
#include "Data_Structer.h"
Create a stack or queue using the provided functions (createStack or createQueue).
```

- Don't forget to free the memory when you're done with the data structure using freeStack or freeQueue.

Here's an example of using the stack:

```c
#include "Data_Structer.h"

int main() {
Stack *stack = createStack();

    push(stack, 42);
    int data;
    pop(stack, &data);

    freeStack(stack);
    return 0;

}
```


## Contributing
Contributions to this project are welcome. If you find any issues or have suggestions for improvements, please open an issue or submit a pull request.

## License
This project is licensed under the MIT License - see the LICENSE file for details.
