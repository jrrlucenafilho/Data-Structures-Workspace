#pragma once

class Node
{
    public:
    Node();
    virtual ~Node();

    int getContent();
    int getPrevious();
    int getNext();

    void setContent(int newContent);
    void setPrevious(int newPrevious);
    void setNext(int newNext);

    private:
    int content, previous, next;
};