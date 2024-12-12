#include <iostream>
#include "include/text_editor.h"

int main()
{
    TextEditor editor;
    int choice;

    do
    {
        std::cout << "\n1. Add Text\n2. Delete Text\n3. Undo\n4. Redo\n5. Display Text\n6. Save to File\n0.Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        if (choice == 1)
        {
            std::cin.ignore();
            std::string newText;
            std::cout << "Enter text to add: ";
            std::getline(std::cin, newText);
            editor.addText(newText);
        }
        else if (choice == 2)
        {
            size_t count;
            std::cout << "Enter number of characters to delete: ";
            std::cin >> count;
            editor.deleteText(count);
        }
        else if (choice == 3)
        {
            editor.undo();
        }
        else if (choice == 4)
        {
            editor.redo();
        }
        else if (choice == 5)
        {
            editor.display();
        }
        else if (choice == 6)
        {
            std::string filename;
            std::cout << "Enter filename to save: ";
            std::cin >> filename;
            editor.saveTofile(filename);
        }
        else if (choice != 0)
        {
            std::cout << "Invalid choice!" << std::endl;
        }
    } while (choice != 0);

    return 0;
}
