#include "../include/text_editor.h"
#include <cassert>
#include <fstream>
#include <iostream>

void testAddText()
{
    TextEditor editor;
    editor.addText("Hello");
    editor.addText(" World");
    assert(editor.display() == "Hello World");
    std::cout << "textAddText passed!" << std::endl;
}

void testDeleteText()
{
    TextEditor editor;
    editor.addText("Hello World");
    editor.deleteText(5);
    assert(editor.display() == "Hello ");
    std::cout << "testDeleteText passed!" << std::endl;
}

void testUndoRedo()
{
    TextEditor editor;
    editor.addText("Hello");
    editor.deleteText(3);
    editor.undo();
    assert(editor.display() == "Hello");
    editor.redo();
    assert(editor.display() == "He");
    std::cout << "testUndoRedo passed!" << std::endl;
}

void testSaveToFile()
{
    TextEditor editor;
    editor.addText("Save this text");
    editor.saveTofile("test_output.txt");

    std::ifstream inFile("test_output.txt");
    std::string fileContent;
    std::getline(inFile, fileContent);
    assert(fileContent == "Save this text");
    inFile.close();
    std::cout << "testSaveToFile passed!" << std::endl;
}

void testEdgeCases()
{
    TextEditor editor;

    // Undo and redo on empty text
    editor.undo(); // Should not crash
    editor.redo(); // Should not crash

    // Delete on empty text
    editor.deleteText(5); // Should not crash
    assert(editor.display() == "");

    // Add, undo, and redo with edge cases
    editor.addText("A");
    editor.undo();
    assert(editor.display() == "");
    editor.redo();
    assert(editor.display() == "A");

    std::cout << "testEdgeCases passed!" << std::endl;
}


int main()
{
    testAddText();
    testDeleteText();
    testUndoRedo();
    testSaveToFile();
    testEdgeCases();
    std::cout << "All test passed!" << std::endl;

    return 0;
}