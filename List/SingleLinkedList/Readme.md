# Singly Linked List Implementation in C

This repository contains a basic implementation of a singly linked list in C, along with various operations for manipulating the list.

## Table of Contents

- [Features](#features)
- [Usage](#usage)
- [Functions](#functions)
- [Error Handling](#error-handling)
- [Contributing](#contributing)
- [License](#license)

## Features

- Creation of a singly linked list.
- Appending nodes to the end of the list.
- Getting and setting data at a specific index in the list.
- Deleting nodes from the list.
- Inserting nodes at a specific index in the list.
- Determining the size of the list.
- Displaying the list elements.
- Memory management to free the list when done.

## Usage

To use this singly linked list implementation in your C project, follow these steps:

1. Include the `singleLinkedList.h` header in your C file:

   ```c
   #include "singleLinkedList.h"
   ```

2. Create a list:

   ```c
   struct slList *myList = NULL;
   ```

3. Perform various operations on the list using the provided functions. For example:

   ```c
   // Append a node to the list
   appendNode(myList, 42);

   // Get the size of the list
   size_t size = getListSize(myList);

   // Display the list elements
   displayList(myList);

   // Free the memory when done
   freeList(myList);
   ```

4. Make sure to handle error cases as appropriate by checking the return values of the functions.

## Functions

- `appendNode`: Appends a node with the specified data to the end of the list.

- `pushNode`: Pushs a node with the specified data to the start of the list.

- `getNodeData`: Gets the data at a specific index in the list.

- `setNodeData`: Sets the data at a specific index in the list.

- `deleteNode`: Deletes a node at a specific index in the list.

- `insertNode`: Inserts a node with the specified data at a specific index in the list.

- `getListSize`: Returns the size of the list.

- `sortList`: Sort the list in ascending .

- `displayList`: Displays the elements of the list.

- `searchInList`: Returns the index of the first occurrence of value , If the value is not found or if the list is empty, it returns -1.

- `freeList`: Frees the memory allocated for the list.

## Error Handling

This implementation includes error handling for various scenarios, such as memory allocation failures and out-of-bounds index access. Functions return a `Statue` enum value indicating the status of the operation, allowing you to handle errors gracefully in your code.

## Contributing

Contributions to this implementation are welcome! If you find issues or have suggestions for improvements, please open an issue or submit a pull request.

## License

This implementation is provided under the [MIT License](LICENSE). Feel free to use, modify, and distribute it as needed.

---
