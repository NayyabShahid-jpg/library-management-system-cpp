# Library Management System in C++

```cpp
#include <iostream>
#include <string>
using namespace std;

// Structure for storing book information
struct Book
{
    int bookID;
    string title;
    string author;
    bool issued;
};

int main()
{
    Book books[100];
    int totalBooks = 0;
    int choice;

    do
    {
        cout << "\n====================================\n";
        cout << "        LIBRARY MANAGEMENT SYSTEM\n";
        cout << "====================================\n";
        cout << "1. Add Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Search Book\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "6. Exit\n";
        cout << "====================================\n";

        cout << "Enter your choice: ";
        cin >> choice;

        // Add Book
        if (choice == 1)
        {
            if (totalBooks >= 100)
            {
                cout << "\nLibrary is full. Cannot add more books.\n";
            }
            else
            {
                cout << "\n----- Add New Book -----\n";

                cout << "Enter Book ID: ";
                cin >> books[totalBooks].bookID;

                cin.ignore();

                cout << "Enter Book Title: ";
                getline(cin, books[totalBooks].title);

                cout << "Enter Author Name: ";
                getline(cin, books[totalBooks].author);

                books[totalBooks].issued = false;

                totalBooks++;

                cout << "\nBook added successfully!\n";
            }
        }

        // Display All Books
        else if (choice == 2)
        {
            if (totalBooks == 0)
            {
                cout << "\nNo books available in the library.\n";
            }
            else
            {
                cout << "\n========== ALL BOOKS ==========\n";

                for (int i = 0; i < totalBooks; i++)
                {
                    cout << "\nBook " << i + 1 << endl;
                    cout << "Book ID: " << books[i].bookID << endl;
                    cout << "Title: " << books[i].title << endl;
                    cout << "Author: " << books[i].author << endl;

                    if (books[i].issued == true)
                    {
                        cout << "Status: Issued" << endl;
                    }
                    else
                    {
                        cout << "Status: Available" << endl;
                    }
                }
            }
        }

        // Search Book
        else if (choice == 3)
        {
            int id;
            bool found = false;

            cout << "\nEnter Book ID to Search: ";
            cin >> id;

            for (int i = 0; i < totalBooks; i++)
            {
                if (books[i].bookID == id)
                {
                    cout << "\n----- Book Found -----\n";
                    cout << "Book ID: " << books[i].bookID << endl;
                    cout << "Title: " << books[i].title << endl;
                    cout << "Author: " << books[i].author << endl;

                    if (books[i].issued == true)
                    {
                        cout << "Status: Issued" << endl;
                    }
                    else
                    {
                        cout << "Status: Available" << endl;
                    }

                    found = true;
                    break;
                }
            }

            if (found == false)
            {
                cout << "\nBook not found!\n";
            }
        }

        // Issue Book
        else if (choice == 4)
        {
            int id;
            bool found = false;

            cout << "\nEnter Book ID to Issue: ";
            cin >> id;

            for (int i = 0; i < totalBooks; i++)
            {
                if (books[i].bookID == id)
                {
                    found = true;

                    if (books[i].issued == true)
                    {
                        cout << "\nThis book is already issued.\n";
                    }
                    else
                    {
                        books[i].issued = true;
                        cout << "\nBook issued successfully!\n";
                    }

                    break;
                }
            }

            if (found == false)
            {
                cout << "\nBook not found!\n";
            }
        }

        // Return Book
        else if (choice == 5)
        {
            int id;
            bool found = false;

            cout << "\nEnter Book ID to Return: ";
            cin >> id;

            for (int i = 0; i < totalBooks; i++)
            {
                if (books[i].bookID == id)
                {
                    found = true;

                    if (books[i].issued == false)
                    {
                        cout << "\nThis book was not issued.\n";
                    }
                    else
                    {
                        books[i].issued = false;
                        cout << "\nBook returned successfully!\n";
                    }

                    break;
                }
            }

            if (found == false)
            {
                cout << "\nBook not found!\n";
            }
        }

        // Exit
        else if (choice == 6)
        {
            cout << "\nThank you for using Library Management System!\n";
        }

        else
        {
            cout << "\nInvalid choice! Please enter 1 to 6.\n";
        }

    } while (choice != 6);

    return 0;
}
```

## How the Program Works

When you run the program, you get this menu:

```text
====================================
        LIBRARY MANAGEMENT SYSTEM
====================================
1. Add Book
2. Display All Books
3. Search Book
4. Issue Book
5. Return Book
6. Exit
====================================
Enter your choice:
```

### 1. Add Book

You can add a book by entering:

```text
Book ID: 101
Book Title: Introduction to C++
Author Name: Robert Lafore
```

The book is stored in the array.

### 2. Display All Books

This option displays all books and their current status.

Example:

```text
Book ID: 101
Title: Introduction to C++
Author: Robert Lafore
Status: Available
```

### 3. Search Book

Enter the Book ID:

```text
Enter Book ID to Search: 101
```

The program searches for the book and displays its information.

### 4. Issue Book

When a book is issued, its status changes:

```text
Status: Available
```

to:

```text
Status: Issued
```

If someone tries to issue an already issued book, the program displays:

```text
This book is already issued.
```

### 5. Return Book

When a book is returned, its status changes back to:

```text
Status: Available
```

### 6. Exit

The program ends when the user selects **6**.

## C++ Concepts Used

| Concept              | Purpose                        |
| -------------------- | ------------------------------ |
| `struct`             | Stores book information        |
| Array                | Stores multiple books          |
| `string`             | Stores title and author        |
| `bool`               | Stores issued/available status |
| `if-else`            | Performs different operations  |
| `for` loop           | Searches and displays books    |
| `do-while` loop      | Repeats the menu               |
| `switch` alternative | Menu is handled with `if-else` |
