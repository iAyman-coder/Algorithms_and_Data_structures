# Introduction
Hello, World!

This is a project that I built in order to improve my programming skills with C language and to better understand how these algorithms and data structures actually works under the hood.

My interest in these topics have started when I first learned about them in the CS50x course. Learning them in theory was not enough to fulfill my curiosity.

Since I am a person who loves to understand how things work internally and to understand how they are actually built, I decided that there is no better way to understand algorithms and data structures than building them myself from scratch.

In this README file, I will document the things I learned while programming them.

# Linear Search Algorithm
This algorithm was obviously the easiest to implement among all the topics I worked on. There was not anything new that I learned from it.

# Binary Search Algorithm
With this algorithm I learned two things:

1. How to properly calculate the index of the middle element via the formula:

    `int middle_index = low + (high - low) / 2;`

2. If the middle element in the current iteration was not the target I am looking for, I should not included it in the next iteration. Either I make `high = middle + 1` or `low = middle - 1`. Before I learned this, I had the problem of getting into an infinite loop if target was on either edge of the array.

# Selection Sort & Bubble Sort Algorithms
Here, I learned why these algorithms take `O(n^2)` on average to sort the array. It is because they utilize nested loops to go through the array again and again until the array is sorted.

I know that bubble sort can be optimized, but usually it will take `O(n^2)` to sort the array.

Also, I learned the difference between these two algorithms:

1. Selection sort: it sorts the array from left to right, sorting the elements from smallest to largest.
2. Bubble sort: it sorts the array from right to left, sorting the elements from largest to smallest.

# Merge Sort Algorithm
When implementing this algorithm in first, I tried to divide the original array into statically declared new arrays in order to make the process simpler and to not deal with manual memory management. However, these statically declared arrays kept showing unexpected result and bringing garbage values from memory.

I tried different solutions but none of them worked. So, I decided to use dynamically declared arrays. They were like magic! They worked as expected and were not actually hard to manage.

The only additional thing that I needed to add is to free these dynamically allocated arrays after merging them together into the original array. Which was surprisingly simple.

More importantly, I improved my understanding of how recursion works and how to use it.

Even though it took a lot of time to implement and debug, it was the most rewarding, and it is my favorite algorithm.

# Interpolation Search Algorithm
This algorithm is an improved version of binary search, so there was not much to learn with it.

However, I learned why it might be better than binary search. It is because of its nature that mimics human behavior by guessing the place of the target, similar to when humans look for a word in a dictionary. You don't always go the middle of the dictionary when looking for a word. instead you go immediately to the section that the word might be inside.

# Quick Sort Algorithm
At first I thought that this algorithm is 90% similar to the merge sort algorithm. I was completely wrong. These algorithms are only similar in theory, but on practice, they are really different.

Also, I learned how to find the pivot and how to put it in its initial correct place.

The differences between quick sort and merge sort that I learned from implementing the quick sort algorithm are the following:

| Aspect             | Quick Sort                                                                                                 | Merge Sort                                                                                                                                                             |
|:--------------------:|:------------------------------------------------------------------------------------------------------------:|:------------------------------------------------------------------------------------------------------------------------------------------------------------------------:|
| Pivot              | You need to find a pivot and put it in the middle                                                          | No pivot are needed.                                                                                                                                                   |
| Dividing the array | Division in place (no new arrays are created)                                                              | Division into new arrays.                                                                                                                                              |
| Sorting            | The sorting happens on every iteration. Smaller elements on  the left of the pivot and larger on the right | The sorting starts only the moment arrays start merging back.                                                                                                          |
| Space complexity   | `O(log n)` because it only uses recursion and does not create new arrays                                   | `O(n)` because it uses recursion alongside creating new arrays.                                                                                                        |
| Base case          | It is common to recursively pass an empty array to the quick sort function.                                | It is very rare to pass an empty array to the recursive call, because of the merge sort nature where there is almost always at least  one element in the passed array. |

# Insertion Sort Algorithm
Implementing this algorithm was fairly easy. The only thing that I needed to understand before implementing it is how to shift elements to the right.

It turned out that I only needed to store the element that I will insert in a temporary variable, then shift all elements that are greater than it into the right with a while loop.

Also, I learned that in this sorting algorithm, I should start from the second element considering that the first is already sorted.

# Singly Linked List
This is the first data structure that I implemented. It was easy to program and understand, at least for me. It was my first deep interactions with structs, pointer, and dynamic memory.

Unlike what many people say, dealing with these topics was not as scary as they mention. In fact, I enjoyed using them.

Implementing this data structure first, later helped me implement stack and queue data structures more easily.

# Doubly Linked List
This part was the hardest to implement. It took me 5 days to implement it in a robust and safe way. However, as always, it was the most rewarding.

1. I learned how to traverse a data structure both forward and backward.
2. I learned how to add safety checking for parameters, and how to exit the program if there is anything wrong.
3. I relearned the importance of separating different functionality into separate functions for simplicity.
4. Unlike singly linked list, I needed to deal with four pointers at a time when I want to insert or remove a node.
5. I learned how to make an array of pointers.
6. I felt again the satisfaction of solving a problem that took to long to find a solution for. And I felt again the joy of programming.

Although implementing this data structure was difficult, but I enjoyed every moment of it.

# Stack & Queue
Implementing these data structures was easy because they are just a slight modification of singly linked lists.

The major difference between these data structures and singly linked lists is the nature of the processes you perform on them.

For example, in a singly linked list, you can insert and remove a node from anywhere from the list. However, in stacks you can only insert and remove to the top of the structure. And in queues you can only insert to the end and remove from the front of the structure.

Also, I learned few terminologies related to the these data structures:

| Referring to | Linked lists | Stacks | Queues  |
|--------------|--------------|--------|---------|
| First node   | Head         | Top    | Front   |
| Last node    | Tail         | Bottom | Rear    |
| Insertion    | Insert       | Push   | Enqueue |
| Removal      | Remove       | Pop    | Dequeue |

# Hash Table
Taking inspiration from the "Dictionary" problem set from the CS50x course. I decided to make a hash table for storing the information about users.

It was easier to implement than I initially expected. The knowledge I harvested from making singly linked lists and learning how to make an array of pointers while making the doubly linked list made the process of implementing the hash table extremely smooth.

In the previous data structures, I only used them to store single characters. However, in the hash table, I decided to use strings and to use the string.h library more. Therefore, I looked for a good hashing function that I can use with strings. I found the DJB2 hashing function, and it was the ideal function for the purpose I wanted it for.

# Other Things I Learned During The Process
While coding these algorithms and data structures gave me a good grasp of how they work under the hood, and help me improve my fluency with C language, this project has also enabled me to cultivate some skills as side effects:

1. I learned how to make a header file and document my functions.
2. I learned to do unit testing and test my code.
3. I learned how to make and use Makefiles.
4. I got the opportunity to experiment with git branches during the process.
5. I improved my Vim motion skills, and learned more tricks.

# Conclusion
It was an outstanding journey where I used my enthusiasm in programming to learn something new and to better understand topics that I learned before. I am certain that there things that I learned in doing this project that will be sustainable for my entire life time.

Thanks for spending some time reading through this README file. I appreciate you.

Have a nice day 👋!