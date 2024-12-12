#ifndef TEXT_EDITOR_H
#define TEXT_EDITOR_H

#include <string>
#include <stack>
#include <utility>

class TextEditor
{
private:
    std::string text; // saving text
    std::stack<std::pair<char, std::string>> undoStack;
    std::stack<std::pair<char, std::string>> redoStack;

public:
    void saveTofile(const std::string &filename) const;
    void addText(const std::string &newText);
    void deleteText(size_t count);
    void undo();
    void redo();
    std::string display() const;
};

#endif // TEXT_EDITOR_H