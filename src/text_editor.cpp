#include "text_editor.h"
#include <iostream>
#include <fstream>

void TextEditor::saveTofile(const std::string &filename) const
{
    std::ofstream outFile(filename);
    if (!outFile)
    {
        std::cerr << "Error: Could not open file " << filename << " for writing." << std::endl;
        return;
    }

    outFile << text;
    outFile.close();
    std::cout << "Text saved to " << filename << std::endl;
}

void TextEditor::addText(const std::string &newText)
{
    undoStack.push({'A', newText});

    while (!redoStack.empty())
        redoStack.pop();
    text += newText;
}

void TextEditor::deleteText(size_t count)
{
    if (count > text.size())
        count = text.size();

    if (!text.empty() && count > 0)
    {
        std::string deletedText = text.substr(text.size() - count);
        undoStack.push({'D', deletedText});

        while (!redoStack.empty())
            redoStack.pop();
        text.erase(text.size() - count);
    }
}

void TextEditor::undo()
{
    if (undoStack.empty())
    {
        std::cout << "Nothing to undo!" << std::endl;
        return;
    }

    auto [op, value] = undoStack.top();
    undoStack.pop();

    if (op == 'A' && text.size() >= value.size())
    {
        text.erase(text.size() - value.size());
        redoStack.push({'A', value});
    }
    else if (op == 'D')
    {
        text += value;
        redoStack.push({'D', value});
    }
}

void TextEditor::redo()
{
    if (redoStack.empty())
    {
        std::cout << "Nothing to redo!" << std::endl;
        return;
    }

    auto [op, value] = redoStack.top();
    redoStack.pop();

    if (op == 'A')
    {
        text += value;
        undoStack.push({'A', value});
    }
    else if (op == 'D' && text.size() >= value.size())
    {
        text.erase(text.size() - value.size());
        undoStack.push({'D', value});
    }
}

std::string TextEditor::display() const
{
    std::cout << "Current text: " << text << std::endl;
    return text;
}